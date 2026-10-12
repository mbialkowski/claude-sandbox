"""Mazovia (Polish DOS code page, CP437-based) text codec.

All in-game Polish text (dialogues, item names, menus) and CZYTAJ.TO are
stored in Mazovia. Python has no built-in codec for it, so we map the 18
Polish letters explicitly and fall back to CP437 for everything else.
"""

MAZOVIA_OVERRIDES = {
    0x86: "ą", 0x8D: "ć", 0x8F: "Ą", 0x90: "Ę", 0x91: "ę", 0x92: "ł",
    0x95: "Ć", 0x98: "Ś", 0x9C: "Ł", 0x9E: "ś", 0xA0: "Ź", 0xA1: "Ż",
    0xA2: "ó", 0xA3: "Ó", 0xA4: "ń", 0xA5: "Ń", 0xA6: "ź", 0xA7: "ż",
}

_TABLE = []
for _b in range(256):
    if _b in MAZOVIA_OVERRIDES:
        _TABLE.append(MAZOVIA_OVERRIDES[_b])
    elif _b < 0x80:
        _TABLE.append(chr(_b))
    else:
        _TABLE.append(bytes([_b]).decode("cp437"))

_REVERSE = {ch: i for i, ch in enumerate(_TABLE)}


def decode(data: bytes) -> str:
    return "".join(_TABLE[b] for b in data)


def encode(text: str) -> bytes:
    return bytes(_REVERSE[ch] for ch in text)


if __name__ == "__main__":
    import sys
    sys.stdout.write(decode(open(sys.argv[1], "rb").read()).replace("\r\n", "\n"))
