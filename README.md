# 🍿 Kino Rodzinne

Prosta, statyczna aplikacja do rodzinnego głosowania na film wieczoru (Tata, Mama, Ula, Antek).
Wygląd wzorowany na [Popcorn Vote](https://github.com/Stadicus/popcorn-vote): jasne, ciepłe karty, siatka
plakatów, licznik 🍿 i dolne zakładki. Działa też w trybie ciemnym (według ustawień systemu).

## Jak uruchomić

Wystarczy otworzyć `index.html` w przeglądarce. Nie trzeba niczego instalować ani budować.
Można też wrzucić pliki na dowolny hosting statyczny, np. GitHub Pages.

## Jak działa

1. **Start**: ustawiasz, ile filmów może wybrać jedna osoba (domyślnie 3), i klikasz „Rozpocznij głosowanie”.
2. **Głosowanie** (zakładka 🎞️): lista osób. Kto już zagłosował, ma zielony znaczek i miniatury swoich
   plakatów. Ponowne wejście pozwala zmienić głosy.
3. **Wybór filmów**: dotknij plakatu albo przycisku „🍿 Wybieram”. W nagłówku widać, ile 🍿 zostało do
   rozdania; „▶” otwiera zwiastun. Na dole: „Anuluj” albo „Zatwierdź głos”.
4. **Wyniki** (zakładka 🍿, także przycisk „🏆 Pokaż wyniki”): przycisk „Odsłoń podium” pokazuje 3., 2. i 1. miejsce
   z wybuchem popcornu, a pod nim aktualną tabelę i siatkę plakatów z liczbą głosów i tym, kto na co głosował.
   Każdy wybrany film to 1 punkt; filmy z tą samą liczbą głosów dzielą miejsce.
5. **Więcej** (zakładka ⋯):
   - „Wyczyść głosy”: usuwa wszystkie głosy, limit zostaje,
   - „Nowe głosowanie”: zaczyna od początku z nowym limitem.

   Pojedyncza osoba może usunąć tylko swój głos przyciskiem „🗑️ Usuń mój głos” pod listą filmów.

Głosy są zapisywane w `localStorage` przeglądarki, więc całe głosowanie odbywa się na jednym urządzeniu
(np. wspólnym tablecie). Wyniki zostają po odświeżeniu strony.

## Pliki

| Plik         | Zawartość                                                             |
|--------------|-----------------------------------------------------------------------|
| `index.html` | szkielet strony: nagłówek, zakładki                                   |
| `styles.css` | wygląd (jasny i ciemny motyw)                                         |
| `app.js`     | logika: ekrany, głosowanie, liczenie wyników                          |
| `movies.js`  | **lista filmów i osób**: tytuły, plakaty, zwiastuny, kolory osób      |

## Plakaty i zwiastuny

Plakaty są linkowane z TMDB (`image.tmdb.org`). Jeśli któryś się nie wczyta, aplikacja pokaże kolorowy
„plakat zastępczy” z tytułem. Aby podmienić plakat, zmień pole `poster` w `movies.js` na dowolny adres
obrazka (np. skopiowany z Filmwebu lub IMDb). Pole `trailer` to link do zwiastuna. Domyślnie prowadzi do
wyszukiwania polskiego zwiastuna na YouTube, ale można tam wkleić bezpośredni link do filmu.
