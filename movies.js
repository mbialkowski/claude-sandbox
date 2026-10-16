// Lista filmów do głosowania.
// poster  – adres plakatu (TMDB); jeśli się nie wczyta, aplikacja pokaże własny „plakat zastępczy".
// trailer – link do zwiastuna; tutaj wyszukiwanie polskiego zwiastuna na YouTube.
// Aby podmienić plakat lub zwiastun, wystarczy zmienić adres poniżej.

const TMDB = "https://image.tmdb.org/t/p/w500";
const yt = (q) => "https://www.youtube.com/results?search_query=" + encodeURIComponent(q + " zwiastun PL");

window.MOVIES = [
  {
    id: "epoka-lodowcowa-5",
    title: "Epoka lodowcowa: Mocne uderzenie",
    year: 2016,
    blurb: "Scrat znów goni żołędzia – tym razem w kosmosie, a na Ziemię leci meteoryt.",
    poster: TMDB + "/o29BFNqgXOUT1yHNYusnITsH7P9.jpg",
    trailer: yt("Epoka lodowcowa Mocne uderzenie"),
    colors: ["#5bc0eb", "#1d3557"],
    emoji: "🦣",
  },
  {
    id: "iniemamocni",
    title: "Iniemamocni",
    year: 2004,
    blurb: "Rodzina superbohaterów musi wrócić do akcji i uratować świat.",
    poster: TMDB + "/2LqaLgk4Z226KkgPJuiOQ58wvrm.jpg",
    trailer: yt("Iniemamocni 2004"),
    colors: ["#e63946", "#1b1b1b"],
    emoji: "🦸",
  },
  {
    id: "spider-man-daleko-od-domu",
    title: "Spider-Man: Daleko od domu",
    year: 2019,
    blurb: "Peter Parker jedzie na szkolną wycieczkę do Europy, ale wakacje szybko się kończą.",
    poster: TMDB + "/4q2NNj4S5dG2RLF9CpXsej7yXl.jpg",
    trailer: yt("Spider-Man Daleko od domu"),
    colors: ["#d62828", "#003049"],
    emoji: "🕷️",
  },
  {
    id: "spider-man-uniwersum",
    title: "Spider-Man Uniwersum",
    year: 2018,
    blurb: "Miles Morales poznaje Spider-Manów z innych wymiarów.",
    poster: TMDB + "/iiZZdoQBEYBv6id8su7ImL0oCbD.jpg",
    trailer: yt("Spider-Man Uniwersum 2018"),
    colors: ["#ff006e", "#3a0ca3"],
    emoji: "🕸️",
  },
  {
    id: "minionki-i-potwory",
    title: "Minionki i potwory",
    year: 2026,
    blurb: "Minionki trafiają do Hollywood i niechcący wypuszczają na świat potwory.",
    poster: "", // film z 2026 r. – wklej tu adres plakatu, gdy będzie pod ręką

    trailer: yt("Minionki i potwory"),
    colors: ["#ffd60a", "#0077b6"],
    emoji: "🍌",
  },
  {
    id: "potwory-i-spolka",
    title: "Potwory i spółka",
    year: 2001,
    blurb: "Sulley i Mike straszą dzieci zawodowo – do czasu, aż poznają Boo.",
    poster: TMDB + "/sgheSKxZkttIe8ONsf2sWXPgip3.jpg",
    trailer: yt("Potwory i spółka 2001"),
    colors: ["#2ec4b6", "#6a0dad"],
    emoji: "👾",
  },
  {
    id: "herkules",
    title: "Herkules",
    year: 1997,
    blurb: "Syn Zeusa musi zostać prawdziwym bohaterem, by wrócić na Olimp.",
    poster: TMDB + "/dK9rNoC97tgX3xXg5zdxFisdfcp.jpg",
    trailer: yt("Herkules Disney 1997"),
    colors: ["#f4a261", "#6d2e46"],
    emoji: "🏛️",
  },
  {
    id: "evan-wszechmogacy",
    title: "Evan Wszechmogący",
    year: 2007,
    blurb: "Bóg prosi Evana o zbudowanie arki, a zwierzęta już ustawiają się w kolejce.",
    poster: TMDB + "/qK7j3t3KZXvkCRhFtL5XdyAizeO.jpg",
    trailer: yt("Evan Wszechmogący"),
    colors: ["#90be6d", "#264653"],
    emoji: "🛶",
  },
  {
    id: "kosmiczny-mecz-2",
    title: "Kosmiczny mecz: Nowa era",
    year: 2021,
    blurb: "LeBron James i Zwariowane Melodie grają mecz o wszystko w cyfrowym świecie.",
    poster: TMDB + "/5bFK5d3mVTAvBCXi5NPWH0tYjKl.jpg",
    trailer: yt("Kosmiczny mecz Nowa era"),
    colors: ["#f77f00", "#03045e"],
    emoji: "🏀",
  },
  {
    id: "buzz-astral",
    title: "Buzz Astral",
    year: 2022,
    blurb: "Prawdziwa historia kosmicznego strażnika, który zainspirował zabawkę z „Toy Story\".",
    poster: TMDB + "/ox4goZd956BxqJH6iLwhWPL9ct4.jpg",
    trailer: yt("Buzz Astral 2022"),
    colors: ["#7b2cbf", "#80ed99"],
    emoji: "🚀",
  },
];

window.USERS = [
  { id: "tata", name: "Tata", emoji: "🧔", female: false, color: "#2563eb" },
  { id: "mama", name: "Mama", emoji: "👩", female: true, color: "#db2777" },
  { id: "ula", name: "Ula", emoji: "👧", female: true, color: "#9333ea" },
  { id: "antek", name: "Antek", emoji: "👦", female: false, color: "#16a34a" },
];
