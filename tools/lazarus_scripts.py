"""The game's hard-coded quest/dialogue handlers, lifted from the decompilation into data.

LAZARUS.EXE has three handler tables: script on_trigger (indexed by script id, run when an object with
`target = id` fires), item use (Enter with an item selected and nothing to interact with) and
missing-item replies (an object needs an item the hero has not selected).  Every non-empty handler of
the three tables is transcribed below, op by op, from reference/lazarus.c (function names in `fn`).
extract_assets.py validates this module against the EXE tables and writes
assets/gamedata/script_logic.json; docs 04-game-content.md 4.9 describes the op set.

Ops are lists `[name, args...]`:

  dialogue    ["say", m]          show message m, wait for Ctrl/Enter/Space, clear
              ["say_keep", m]     show and wait, keep the text (the next one is drawn over it)
              ["print", m]        show without waiting (header before a menu or a number)
              ["say_indexed", m, var]   say message m + state[var]
              ["print_number", var]     draw state[var] after the printed text
              ["wait"], ["clear"]
              ["menu", [opt...]]  choose one option; result in "choice".  An option is a message id
                                  or {"msg": m, "if": cond}; hidden options keep their index, so
                                  "choice" is the index in the full list.
  control     ["if", cond, [then ops], [else ops]]
              ["switch", var, {"value": [ops], ..., "default": [ops]}]
              ["call", script_id]
  inventory   ["give", item]      add to the first free pocket and select it
              ["take", item]      remove the item (if present)
              ["take_selected"]   remove the selected pocket
  state       ["set", var, value] (value may be a condition, stored as 0/1), ["add", var, n],
              ["set_flag", n] (g_gameFlags[n] = 1)
              ["money", n]        add n (negative = pay; the caller checks the balance first)
              ["energy", "full"|"+third"], ["fuel", "full"|"+third"|0],
              ["ammo", "+third"|"all_full"]  (+third: current weapon)
              ["weapon", n]       own + select weapon n, ammo +3/3
              ["activate_object", index]   force-activate room object (the hub force field)
              ["random", var, n]  state[var] = random 0..n-1
  presentation ["teleport", col, row, x, y], ["picture", frame], ["picture_var", var],
              ["fade", from_palette, to_palette, steps] (the target becomes the current palette),
              ["show_pcx", file] (full-screen picture, wait for a key), ["sound", id],
              ["bomb_sound", "start"|"stop"], ["delay", ticks], ["delay_ms", ms], ["explode"],
              ["end_game", "death"|"joke_ending"|"win"]  (sets the end state; the handler still runs
                                  to its end, then the game loop exits)

Conditions (a compared value may also be {"var": name}):
            ["money_lt", n], ["money_eq", n], ["has_item", i], ["eq", var, n], ["ne", var, n],
["lt", var, n], ["in_room", col, row], ["energy_full"], ["ammo_full"], ["sock_here"],
["and", c...], ["or", c...], ["not", c].
"""

# ---------------------------------------------------------------------------
# state the handlers use (besides money/energy/fuel/ammo/pockets and g_gameFlags[256])
# ---------------------------------------------------------------------------
STATE = {
    "choice": {"addr": None, "init": None, "note": "result of the last menu"},
    "bomb_wire": {"addr": "89348", "init": ["random", 3], "note": "wire that defuses the bomb: 0 red, 1 green, 2 blue"},
    "secret_door": {"addr": "89368", "init": ["random", 3],
                    "note": "which secret door of (8,7) hides magic key 5; also sets g_gameFlags[76 + n]"},
    "sock_chest": {"addr": "89350", "init": ["random", 11], "note": "index into the 11 sock spots (EXE 0x5442C)"},
    "sock_found": {"addr": "89354", "init": 0, "note": ""},
    "riddle": {"addr": "89314", "init": ["random", 3], "note": "riddle asked by the riddle man (answers 14/19/97)"},
    "shop_map": {"addr": "8947c", "init": ["random_of", [1079, 1078]], "note": "picture shown by the shop map (item 37)"},
    "magazines": {"addr": "89310", "init": 0, "note": "stack count of item 36"},
    "cauldron_flowers": {"addr": "89360", "init": 0, "note": "magic flowers dropped into the cauldron"},
    "key_slots": {"addr": "8938c", "init": 0, "note": "magic keys inserted in the hub"},
    "bomb_active": {"addr": "8934c", "init": 0, "note": "countdown g_bombTimer = 3000 ticks runs while set"},
    "infinite_ammo_fuel": {"addr": "89390", "init": 0, "note": "also the IDSIAR cheat"},
    "pw_temple": {"addr": "89330", "init": 1, "note": "teleport passwords, in hub-menu order"},
    "pw_netherworld": {"addr": "89334", "init": 0, "note": ""},
    "pw_abyss": {"addr": "89338", "init": 0, "note": ""},
    "pw_valley": {"addr": "8933c", "init": 0, "note": ""},
    "pw_terror": {"addr": "89340", "init": 0, "note": ""},
    "pw_training": {"addr": "89344", "init": 1, "note": ""},
    "stock_energy": {"addr": "8936c", "init": 1, "note": "vending machine stock (energy: recomputed = not full)"},
    "stock_clip": {"addr": "89370", "init": 1, "note": ""},
    "stock_uzi": {"addr": "89374", "init": 1, "note": ""},
    "stock_ticket": {"addr": "89378", "init": 1, "note": ""},
    "stock_map": {"addr": "8937c", "init": 1, "note": ""},
    "stock_leave": {"addr": "89380", "init": 1, "note": "'Może innym razem.' - always listed"},
    "witch_death": {"addr": "89388", "init": 0, "note": "written, never read"},
    "unused_8935c": {"addr": "8935c", "init": None, "note": "cleared by the witch death, never read"},
}

PALETTES = {"game": "DATA25", "alarm": "DATA16", "black": "all black", "current": "the palette in use"}


# ---------------------------------------------------------------------------
# helpers to keep the transcription close to the C
# ---------------------------------------------------------------------------
def says(first, last=None):
    """Dlg_SayRange(first..last) / Dlg_Say(first)."""
    return [["say", m] for m in range(first, (last if last is not None else first) + 1)]


def buy(price, effect, poor=43):
    return [["if", ["money_lt", price], [["say", poor]], [["money", -price]] + effect]]


def brewing(final_msg):
    """The witch's 'Świetnie! ... Chwileczkę! ... Momencik! ... I oto jest!' routine."""
    return [["say", 99], ["say_keep", 100], ["wait"], ["say_keep", 101], ["wait"], ["say", 102],
            ["say", final_msg]]


def picture_by_riddle(frames):
    return [["switch", "riddle", {"0": [["picture", frames[0]]], "1": [["picture", frames[1]]],
                                  "default": [["picture", frames[2]]]}]]


# ---------------------------------------------------------------------------
# item use handlers (item id -> ops); dialog = wrapped in Dlg_Begin/Dlg_End
# ---------------------------------------------------------------------------
ITEM_USE = {
    0: {"fn": "1ac50", "ops": []},
    1: {"fn": "1ac68", "dialog": True, "ops": says(256)},
    2: {"fn": "1acf8", "dialog": True, "ops": says(257)},
    3: {"fn": "1af04", "dialog": True, "ops": says(258)},
    4: {"fn": "1ac98", "dialog": True, "ops": says(259)},
    5: {"fn": "1acc8", "ops": [["fuel", "full"], ["take_selected"]]},
    6: {"fn": "1acf8", "dialog": True, "ops": says(257)},
    7: {"fn": "1ad28", "dialog": True, "ops": says(276)},
    8: {"fn": "1ad58", "dialog": True, "ops": says(260)},
    9: {"fn": "1ad88", "dialog": True, "ops": says(261)},
    10: {"fn": "1adb8", "dialog": True, "ops": says(262)},
    11: {"fn": "1ade8", "dialog": True, "note": "the magic whistle becomes the golden key in room (1,5) (TARAPATY)",
         "ops": [["if", ["in_room", 1, 5], [["say", 160], ["take", 11], ["give", 23]], [["say", 159]]]]},
    12: {"fn": "1ae54", "dialog": True, "ops": says(263)},
    13: {"fn": "1ae84", "dialog": True, "ops": says(264)},
    14: {"fn": "1aeb4", "dialog": True, "ops": says(265)},
    15: {"fn": "1aee4", "ops": [["picture", 1077]]},
    16: {"fn": "1af04", "dialog": True, "ops": says(258)},
    17: {"fn": "1af34", "dialog": True, "ops": says(266)},
    **{k: {"fn": "1af64", "dialog": True, "ops": says(267)} for k in range(18, 23)},
    23: {"fn": "1af94", "dialog": True, "ops": says(268)},
    24: {"fn": "1afc4", "dialog": True,
         "ops": [["if", ["money_eq", 0], [["say", 253]],
                  [["print", 252], ["print_number", "money"], ["wait"], ["clear"]]]]},
    25: {"fn": "1b024", "dialog": True, "ops": says(269)},
    26: {"fn": "1b054", "dialog": True, "ops": says(270)},
    27: {"fn": "1b084", "ops": [["picture", 1080]]},
    28: {"fn": "1b0a4", "note": "BUG in the original: riddle 2 shows riddle 1's picture (1082 instead of 1083)",
         "ops": picture_by_riddle([1081, 1082, 1082])},
    29: {"fn": "1b0f8", "dialog": True, "ops": says(271)},
    **{k: {"fn": "1b128", "dialog": True, "ops": says(272)} for k in (30, 31, 32)},
    33: {"fn": "1b158", "dialog": True, "ops": says(273)},
    34: {"fn": "1b188", "dialog": True, "ops": says(274)},
    35: {"fn": "1b1b8", "dialog": True, "ops": says(275)},
    36: {"fn": "1b1e8", "dialog": True, "note": "magazine: +1/3 ammo for the current weapon",
         "ops": [["if", ["ammo_full"], [["say", 278]],
                  [["ammo", "+third"], ["sound", 38], ["add", "magazines", -1],
                   ["if", ["eq", "magazines", 0], [["take", 36]],
                    [["print", 277], ["print_number", "magazines"], ["wait"], ["clear"]]]]]]},
    37: {"fn": "1b290", "ops": [["picture_var", "shop_map"]]},
}

# missing-item replies (item id -> ops)
MISSING_ITEM = {
    1: {"fn": "1b2c8", "ops": says(3)},
    2: {"fn": "1b2f8", "ops": says(8)},
    3: {"fn": "1b328", "ops": says(1)},
    4: {"fn": "1b358", "ops": says(5)},
    6: {"fn": "1b388", "ops": says(34)},
    7: {"fn": "1b3b8", "ops": [["say_keep", 23], ["say_keep", 24]]},
    8: {"fn": "1b3f8", "ops": [["say_keep", 29]]},
    9: {"fn": "1b428", "ops": says(64)},
    10: {"fn": "1b454", "ops": says(72)},
    12: {"fn": "1b484", "ops": says(76)},
    13: {"fn": "1b4b4", "ops": says(77)},
    14: {"fn": "1b4e4", "ops": says(105)},
    16: {"fn": "1b328", "ops": says(1)},
    17: {"fn": "1b514", "ops": says(156)},
    **{k: {"fn": "1b544", "ops": says(230)} for k in range(18, 23)},
    23: {"fn": "1b574", "ops": says(158)},
    25: {"fn": "1b5a4", "ops": says(140)},
    26: {"fn": "1b5d4", "ops": says(161) + says(162) + says(161) + says(163)},
    29: {"fn": "1b630", "ops": says(202)},
    33: {"fn": "1b7b4", "ops": says(86, 87)},
    34: {"fn": "1b814", "ops": [["if", ["has_item", 34], [["say", 255]], [["say", 254]]]]},
    35: {"fn": "1b8b4", "ops": says(229)},
}
for _h in MISSING_ITEM.values():
    _h["dialog"] = True

# ---------------------------------------------------------------------------
# script on_trigger handlers (script id -> ops)
# ---------------------------------------------------------------------------
SCRIPTS = {
    32: {"fn": "1b660", "dialog": True, "name": "merchant 1 (8,1)",
         "note": "buying the wire cutters does not set flag 36, so the second merchant only appears after "
                 "the other choices",
         "ops": [["print", 37], ["menu", [38, 39, 40, 41]],
                 ["if", ["eq", "choice", 3], [["set_flag", 36], ["say", 44]],
                  [["if", ["money_lt", 10], [["say", 43], ["set_flag", 36]],
                    [["switch", "choice", {"0": [["set_flag", 36], ["set", "pw_abyss", 1], ["say", 53]],
                                           "1": [["set_flag", 36], ["give", 6]],
                                           "default": [["give", 7]]}],
                     ["say", 42], ["money", -10]]]]]]},
    33: {"fn": "1b794", "ops": [["give", 6]], "name": "lift card pickup"},
    34: {"fn": "1b7e8", "dialog": True, "ops": says(9), "name": "hanging man asks for help"},
    35: {"fn": "1b864", "dialog": True, "name": "hanging man rescued",
         "ops": [["print", 10], ["say_indexed", 11, "bomb_wire"], ["say", 22]]},
    37: {"fn": "1b8e4", "dialog": True, "name": "merchant 2 (9,3)",
         "ops": [["print", 45], ["menu", [46, 47, 48, 49]],
                 ["if", ["eq", "choice", 3], [["say", 51]],
                  [["if", ["money_lt", 14], [["say", 43]],
                    [["say", 50], ["money", -14],
                     ["if", ["eq", "choice", 1], [["give", 7]], [["wait"], ["clear"], ["say", 52]]]]]]]]},
    38: {"fn": "1b9d8", "dialog": True, "name": "deaf prisoner arms the bomb",
         "ops": says(14, 17) + [["bomb_sound", "start"], ["fade", "game", "alarm", 7]] + says(18, 21)
         + [["set", "bomb_active", 1]]},
    39: {"fn": "1ba4c", "dialog": True, "name": "bomb: cut a wire",
         "ops": [["print", 25], ["menu", [26, 27, 28]],
                 ["if", ["eq", "choice", {"var": "bomb_wire"}],
                  [["bomb_sound", "stop"], ["fade", "alarm", "game", 7], ["set", "bomb_active", 0],
                   ["take", 7], ["say", 35]],
                  [["print", 36], ["delay", 100], ["clear"], ["explode"]]]]},
    41: {"fn": "1bb38", "ops": [["give", 8]], "name": "cage key pickup"},
    42: {"fn": "1bb58", "dialog": True, "name": "prisoner freed",
         "ops": says(30, 33) + [["set", "pw_netherworld", 1]]},
    43: {"fn": "1bb98", "ops": [["give", 19]], "name": "magic key 2"},
    44: {"fn": "1bbb8", "ops": [["give", 32]], "name": "magic flower 3"},
    45: {"fn": "1bbd8", "ops": [["teleport", 4, 5, 14, 83]], "name": "booth (8,6) -> (4,5)"},
    64: {"fn": "1bc08", "dialog": True, "name": "the witch",
         "ops": says(88, 91) + [["take", 33], ["print", 92], ["menu", [93, 94, 95]],
                                ["if", ["eq", "choice", 1], says(96, 97) + [["give", 34]],
                                 brewing(103) + [
                                     ["switch", "choice", {
                                         "0": [["set", "witch_death", 1], ["set", "unused_8935c", 0], ["delay", 100],
                                               ["end_game", "death"], ["say", 122]],
                                         "default": [["fade", "game", "black", 6], ["show_pcx", "DATA21.RES"],
                                                     ["end_game", "joke_ending"]]}]]]]},
    65: {"fn": "1bd98", "name": "cauldron",
         "note": "silent unless the hero has the shears; the dialogue opens after the flowers are counted",
         "ops": [["if", ["and", ["has_item", 34], ["ne", "cauldron_flowers", 3]],
                  [["if", ["has_item", f], [["take", f], ["add", "cauldron_flowers", 1]], []] for f in (30, 31, 32)]
                  + [["if", ["eq", "cauldron_flowers", 3],
                      brewing(104) + [["take", 34], ["give", 14]],
                      [["say", 98]]]],
                  []]]},
    66: {"fn": "1bea8", "ops": [["give", 9]], "name": "empty bucket"},
    67: {"fn": "1bec8", "dialog": True, "name": "tap fills the bucket",
         "ops": [["take_selected"], ["give", 10], ["say_keep", 65], ["wait"], ["say", 66]]},
    68: {"fn": "1bf20", "dialog": True, "name": "burning-hat man extinguished",
         "ops": [["take_selected"], ["give", 11]] + says(73, 75) + says(83, 85) + [["set", "pw_abyss", 1]]},
    69: {"fn": "1bf88", "dialog": True, "ops": says(67, 71), "name": "burning-hat man talks"},
    70: {"fn": "1bfbc", "ops": [["give", 13]], "name": "grey card"},
    71: {"fn": "1bfdc", "dialog": True, "ops": says(78), "name": "grave: Long John Silver"},
    72: {"fn": "1c00c", "dialog": True, "ops": [["say_keep", 79], ["say", 80]], "name": "grave: a hand"},
    73: {"fn": "1c04c", "dialog": True, "ops": says(81), "name": "grave: Gereon Świniopas"},
    74: {"fn": "1c07c", "dialog": True, "ops": says(82), "name": "grave: Jaksra Tokwili"},
    75: {"fn": "1c0ac", "dialog": True, "name": "undertaker (7,6)",
         "ops": [["say", 54], ["print", 55], ["menu", [56, 57, 58, 59]],
                 ["if", ["eq", "choice", 3], [["say", 63]],
                  buy(10, [["switch", "choice", {"0": [["set", "pw_abyss", 1], ["say", 60]],
                                                 "1": [["say", 61]],
                                                 "default": [["give", 15]]}],
                           ["say", 62]])]]},
    79: {"fn": "1c1d8", "ops": [["give", 22]], "name": "magic key 5"},
    80: {"fn": "1c1f8", "dialog": True, "ops": says(106, 120) + [["give", 35]], "name": "Jouler de Generat"},
    81: {"fn": "1c238", "dialog": True, "ops": says(121), "name": "Jouler buried again"},
    97: {"fn": "1c268", "ops": [["give", 16]], "name": "purple card 2"},
    98: {"fn": "1c288", "dialog": True, "ops": [["teleport", 4, 2, 100, 121], ["set", "pw_valley", 1]],
         "name": "trigger (2,9) -> Hidden Valley"},
    99: {"fn": "1c2cc", "ops": [["give", 20]], "name": "magic key 3"},
    100: {"fn": "1c2ec", "dialog": True, "ops": says(123), "name": "man attacked by a monster"},
    101: {"fn": "1c318", "dialog": True, "name": "rescued man: secret-door hint",
          "ops": [["say", 124], ["say", 125], ["print", 126], ["say_indexed", 127, "secret_door"], ["say", 130]]},
    102: {"fn": "1c388", "dialog": True, "ops": says(145, 155) + [["set", "pw_terror", 1]],
          "name": "the Devil's daughter"},
    103: {"fn": "1c3c8", "dialog": True, "ops": says(133, 139), "name": "man missing a sock"},
    104: {"fn": "1c3fc", "dialog": True, "ops": says(141, 144) + [["take", 25], ["give", 26]],
          "name": "sock -> decoder"},
    105: {"fn": "1c448", "dialog": True, "name": "chest",
          "ops": [["if", ["and", ["sock_here"], ["eq", "sock_found", 0]],
                   [["say", 132], ["give", 25], ["set", "sock_found", 1]], [["say", 131]]]]},
    106: {"fn": "1c4e0", "dialog": True, "ops": says(131), "name": "empty chest"},
    107: {"fn": "1c510", "dialog": True, "ops": [["take", 17], ["say", 157]], "name": "ferryman"},
    108: {"fn": "1c550", "ops": [["fuel", 0]], "name": "no-fly zone over the river"},
    128: {"fn": "1c578", "dialog": True, "ops": [["say", 0], ["give", 5]], "name": "fuel can (with remark)"},
    129: {"fn": "1c5b0", "ops": [["give", 3]], "name": "purple card"},
    130: {"fn": "1c5d0", "ops": [["give", 1]], "name": "first-aid kit"},
    131: {"fn": "1c5f0", "ops": [["give", 4]], "name": "fuse"},
    132: {"fn": "1c610", "dialog": True, "ops": [["say", 6], ["take", 4], ["call", 241]], "name": "fuse fitted"},
    134: {"fn": "1c654", "ops": [["fuel", "+third"]], "name": "fuel pick-up"},
    136: {"fn": "1c690", "ops": [["energy", "+third"]], "name": "energy potion (unused id)"},
    137: {"fn": "1c690", "ops": [["energy", "+third"]], "name": "energy potion"},
    138: {"fn": "1c6cc", "dialog": True, "ops": says(7), "name": "'too far to jump'"},
    139: {"fn": "1c6fc", "dialog": True, "ops": says(2), "name": "bleeding man"},
    140: {"fn": "1c72c", "dialog": True, "ops": [["take_selected"], ["give", 2], ["say", 4]],
          "name": "bleeding man healed"},
    141: {"fn": "1c770", "ops": [["give", 21]], "name": "magic key 4"},
    142: {"fn": "1c790", "ops": [["give", 30]], "name": "magic flower 1"},
    160: {"fn": "1c7b0", "dialog": True, "name": "vending machine (0,0)",
          "note": "the energy refill is +1/3 and is only listed when energy is not full",
          "ops": [["set", "stock_energy", ["not", ["energy_full"]]], ["print", 232],
                  ["menu", [{"msg": 233 + i, "if": ["ne", v, 0]} for i, v in enumerate(
                      ["stock_energy", "stock_clip", "stock_uzi", "stock_ticket", "stock_map", "stock_leave"])]],
                  ["switch", "choice", {
                      "0": buy(5, [["energy", "+third"], ["say", 240]], poor=239),
                      "1": buy(2, [["if", ["has_item", 36], [], [["give", 36]]], ["add", "magazines", 1],
                                   ["say", 240]], poor=239),
                      "2": buy(20, [["weapon", 3], ["set", "stock_uzi", 0], ["say", 240]], poor=239),
                      "3": buy(95, [["give", 17], ["set", "stock_ticket", 0], ["say", 240]], poor=239),
                      "4": buy(30, [["give", 37], ["set", "stock_map", 0], ["say", 240]], poor=239),
                      "default": []}]]},
    161: {"fn": "1cab8", "name": "magic key slot (hub)",
          "ops": [["if", ["ne", "key_slots", 5],
                   [["add", "key_slots", 1], ["take_selected"],
                    ["if", ["eq", "key_slots", 5], [["activate_object", 12]], []]], []]]},
    162: {"fn": "1cb30", "dialog": True, "ops": [["take", 35], ["say", 231]], "name": "Time Key delivered"},
    163: {"fn": "1cb70", "dialog": True, "name": "Time Guardian",
          "ops": says(208, 228) + says(241, 242) + [["set", "infinite_ammo_fuel", 1], ["ammo", "all_full"],
                                                    ["give", 33]]},
    164: {"fn": "1cc00", "dialog": True, "ops": says(207), "name": "'Zaufaj mocy, Lucek!'"},
    165: {"fn": "1cc2c", "ops": [["fade", "game", "black", 6], ["end_game", "win"]], "name": "door of time: WIN"},
    192: {"fn": "1cc70", "ops": [["give", 18]], "name": "magic key 1"},
    193: {"fn": "1cc90", "ops": [["give", 12]], "name": "shaped key piece"},
    194: {"fn": "1ccb0", "dialog": True, "name": "gum-chewer trade",
          "ops": says(161) + says(164, 166) + [["print", 167], ["menu", [168, 169, 170, 171]],
                                               ["if", ["eq", "choice", 3], [["say", 172]],
                                                [["take", 26], ["switch", "choice", {
                                                    "2": [["say", 174], ["fade", "current", "black", 7],
                                                          ["delay_ms", 5000], ["fade", "black", "current", 7],
                                                          ["say", 175], ["say", 173]],
                                                    "1": [["give", 27], ["say", 173]],
                                                    "default": [["money", 30], ["say", 173]]}]]]]},
    195: {"fn": "1ce20", "dialog": True, "name": "riddle man gives the riddle",
          "ops": says(176, 181) + picture_by_riddle([1081, 1082, 1083]) + [["say", 182], ["give", 28]]},
    196: {"fn": "1ceac", "dialog": True, "name": "riddle answer",
          "note": "options are messages 185+3r..187+3r; correct = option 1 for riddles 0-1, option 2 for riddle 2",
          "ops": [["print", 184],
                  ["menu", [{"msg": 185, "per_riddle_offset": 3}, {"msg": 186, "per_riddle_offset": 3},
                            {"msg": 187, "per_riddle_offset": 3}]],
                  ["if", ["or", ["and", ["eq", "choice", 1], ["lt", "riddle", 2]],
                          ["and", ["eq", "choice", 2], ["eq", "riddle", 2]]],
                   [["say", 194], ["set_flag", 197]], [["say", 195]]],
                  ["take", 28]]},
    198: {"fn": "1cfb8", "dialog": True, "ops": says(196, 201), "name": "crying girl"},
    199: {"fn": "1cfec", "dialog": True, "ops": says(204, 205) + [["take", 29], ["money", 100]],
          "name": "teddy returned"},
    200: {"fn": "1d038", "dialog": True, "ops": says(203), "name": "girl insists"},
    201: {"fn": "1d068", "ops": [["give", 29]], "name": "teddy bear"},
    202: {"fn": "1d088", "ops": [["give", 31]], "name": "magic flower 2"},
    203: {"fn": "1d0a8", "name": "damaged teleport (4,5)",
          "ops": [["random", "r", 3],
                  ["if", ["eq", "r", 0], [["teleport", 9, 6, 186, 178]], [["teleport", 8, 8, 108, 125]]]]},
    204: {"fn": "1d100", "dialog": True, "ops": says(206), "name": "damaged teleport warning"},
    224: {"fn": "1d130", "ops": [["money", 1]], "name": "coin"},
    225: {"fn": "1d150", "ops": [["weapon", 1]], "name": "rocket launcher"},
    226: {"fn": "1d190", "ops": [["weapon", 3]], "name": "Uzi"},
    227: {"fn": "1d1b0", "ops": [["weapon", 4]], "name": "flame-thrower"},
    228: {"fn": "1d170", "ops": [["weapon", 2]], "name": "heavy rocket launcher"},
    229: {"fn": "1d1d0", "ops": [["weapon", 5]], "name": "plasma gun"},
    230: {"fn": "1d1f0", "ops": [["money", 10]], "name": "big coin"},
    231: {"fn": "1d210", "ops": [["ammo", "+third"]], "name": "ammo pick-up"},
    232: {"fn": "1d270", "ops": [["give", 5]], "name": "fuel can"},
    233: {"fn": "1d290", "ops": [["energy", "full"]], "name": "full energy"},
    240: {"fn": "1d2b8", "dialog": True, "name": "hub teleport terminal",
          "ops": [["if", ["and"] + [["eq", v, 0] for v in
                                     ["pw_temple", "pw_netherworld", "pw_abyss", "pw_valley", "pw_terror",
                                      "pw_training"]],
                   [["say", 250]],
                   [["print", 249],
                    ["menu", [{"msg": 243 + i, "if": ["ne", v, 0]} for i, v in enumerate(
                        ["pw_temple", "pw_netherworld", "pw_abyss", "pw_valley", "pw_terror", "pw_training"])]],
                    ["clear"],
                    ["switch", "choice", {"0": [["teleport", 7, 0, 22, 83]], "1": [["teleport", 7, 8, 38, 178]],
                                          "2": [["teleport", 1, 6, 27, 64]], "3": [["teleport", 4, 2, 100, 121]],
                                          "4": [["teleport", 1, 1, 94, 26]], "5": [["teleport", 5, 5, 124, 26]]}]]]]},
    241: {"fn": "1d4b8", "ops": [["teleport", 0, 0, 53, 178]], "name": "teleport booth -> hub"},
    255: {"fn": "1d4e0", "ops": [["take_selected"]], "name": "consume the selected item (locks)"},
}

# ---------------------------------------------------------------------------
# validation
# ---------------------------------------------------------------------------
OPS = {"say": 1, "say_keep": 1, "print": 1, "say_indexed": 2, "print_number": 1, "wait": 0, "clear": 0,
       "menu": 1, "if": 3, "switch": 2, "call": 1, "give": 1, "take": 1, "take_selected": 0, "set": 2,
       "add": 2, "set_flag": 1, "money": 1, "energy": 1, "fuel": 1, "ammo": 1, "weapon": 1,
       "activate_object": 1, "random": 2, "teleport": 4, "picture": 1, "picture_var": 1, "fade": 3,
       "show_pcx": 1, "sound": 1, "bomb_sound": 1, "delay": 1, "delay_ms": 1, "explode": 0, "end_game": 1}
CONDS = {"money_lt": 1, "money_eq": 1, "has_item": 1, "eq": 2, "ne": 2, "lt": 2, "in_room": 2,
         "energy_full": 0, "ammo_full": 0, "sock_here": 0, "and": None, "or": None, "not": 1}


def validate(n_messages=293, n_items=38):
    """Raise ValueError on unknown ops/conditions or out-of-range ids; return referenced message ids."""
    msgs = set()
    local_vars = {"r"}

    def var_ok(v):
        if v not in STATE and v not in local_vars and v not in ("money",):
            raise ValueError(f"unknown state variable {v!r}")

    def cond(c, where):
        name, args = c[0], c[1:]
        if name not in CONDS or (CONDS[name] is not None and len(args) != CONDS[name]):
            raise ValueError(f"{where}: bad condition {c!r}")
        if name in ("and", "or"):
            for a in args:
                cond(a, where)
        elif name == "not":
            cond(args[0], where)
        elif name in ("eq", "ne", "lt"):
            var_ok(args[0])
        elif name == "has_item" and not 0 <= args[0] < n_items:
            raise ValueError(f"{where}: item {args[0]}")

    def walk(ops, where):
        for op in ops:
            name, args = op[0], op[1:]
            if name not in OPS or len(args) != OPS[name]:
                raise ValueError(f"{where}: bad op {op!r}")
            if name in ("say", "say_keep", "print"):
                msgs.add(args[0])
            elif name == "say_indexed":
                var_ok(args[1])
                msgs.update(range(args[0], args[0] + 3))
            elif name == "menu":
                for o in args[0]:
                    if isinstance(o, dict):
                        msgs.add(o["msg"])
                        if "per_riddle_offset" in o:
                            msgs.update(o["msg"] + k * o["per_riddle_offset"] for k in range(3))
                        if "if" in o:
                            cond(o["if"], where)
                    else:
                        msgs.add(o)
            elif name == "if":
                cond(args[0], where)
                walk(args[1], where)
                walk(args[2], where)
            elif name == "switch":
                var_ok(args[0])
                for body in args[1].values():
                    walk(body, where)
            elif name in ("give", "take") and not 0 < args[0] < n_items:
                raise ValueError(f"{where}: item {args[0]}")
            elif name in ("set", "add", "print_number", "picture_var", "random"):
                var_ok(args[0])
    for table, hs in (("script", SCRIPTS), ("item_use", ITEM_USE), ("missing_item", MISSING_ITEM)):
        for k, h in hs.items():
            walk(h["ops"], f"{table} {k}")
    bad = [m for m in msgs if not 0 <= m < n_messages]
    if bad:
        raise ValueError(f"message ids out of range: {bad}")
    return msgs


def export(exe):
    """Check coverage against the EXE handler tables and return the JSON document."""
    noop = "1b2b0"
    msgs = validate(len(exe.messages()), len(exe.items()))
    problems = []
    for s in exe.scripts():
        if s["on_trigger_fn"] != noop and s["id"] not in SCRIPTS:
            problems.append(f"script {s['id']} handler {s['on_trigger_fn']} not transcribed")
        if s["id"] in SCRIPTS and SCRIPTS[s["id"]]["fn"] != s["on_trigger_fn"]:
            problems.append(f"script {s['id']}: fn {SCRIPTS[s['id']]['fn']} != EXE {s['on_trigger_fn']}")
        if s["on_missing_item_fn"] != noop and s["id"] not in MISSING_ITEM:
            problems.append(f"missing-item {s['id']} handler {s['on_missing_item_fn']} not transcribed")
        if s["id"] in MISSING_ITEM and MISSING_ITEM[s["id"]]["fn"] != s["on_missing_item_fn"]:
            problems.append(f"missing-item {s['id']}: fn mismatch")
    for it in exe.items():
        if it["id"] not in ITEM_USE or ITEM_USE[it["id"]]["fn"] != it["use_fn"]:
            problems.append(f"item {it['id']} use handler {it['use_fn']} not transcribed")
    if problems:
        raise ValueError("; ".join(problems))

    def table(hs):
        return [dict({"id": k}, **h) for k, h in sorted(hs.items())]

    return {"note": "Hard-coded handlers of LAZARUS.EXE as data. Op set: tools/lazarus_scripts.py docstring and "
                    "docs 04-game-content.md 4.9. Message ids index text/messages.json; item ids "
                    "gamedata/items.json. dialog = runs inside Dlg_Begin/Dlg_End (game frozen, sound "
                    "effects paused).",
            "state": STATE, "palettes": PALETTES,
            "scripts": table(SCRIPTS), "item_use": table(ITEM_USE), "missing_item": table(MISSING_ITEM),
            "messages_referenced": len(msgs)}
