# 🍿 Kino Rodzinne

Prosta, statyczna aplikacja do rodzinnego głosowania na film wieczoru (Tata, Mama, Ula, Antek).
Wygląd wzorowany na [Popcorn Vote](https://github.com/Stadicus/popcorn-vote): jasne, ciepłe karty, siatka
plakatów, licznik 🍿 i dolne zakładki. Działa też w trybie ciemnym (według ustawień systemu).

## Jak uruchomić

Aplikacja jest publikowana na GitHub Pages: <https://mbialkowski.github.io/claude-sandbox/>.
Każdy push do `main` publikuje ją od nowa (`.github/workflows/pages.yml`). Jednorazowo w ustawieniach
repozytorium: Settings → Pages → Build and deployment → Source: „GitHub Actions”.

**Na ekran początkowy (iPhone/iPad):** otwórz stronę w Safari → Udostępnij → „Do ekranu początkowego”.
Aplikacja dostaje ikonę 🍿 i otwiera się na pełnym ekranie, bez pasków Safari. Uwaga: aplikacja z ekranu
początkowego ma własne głosy, osobne od Safari, więc głosujcie zawsze z tego samego miejsca.

Lokalnie wystarczy otworzyć `index.html` w przeglądarce. Nie trzeba niczego instalować ani budować.

## Jak działa

1. **Start**: ustawiasz, ile filmów może wybrać jedna osoba (domyślnie 3), i klikasz „Rozpocznij głosowanie”.
2. **Głosowanie** (zakładka 🎞️): lista osób. Kto już zagłosował, ma zielony znaczek i liczbę
   wybranych filmów (bez zdradzania, jakich). Ponowne wejście pozwala zmienić głosy.
3. **Wybór filmów**: dotknij plakatu albo przycisku „🍿 Wybieram”. W nagłówku widać, ile 🍿 zostało do
   rozdania. Na dole: „Anuluj” albo „Zatwierdź głos”.
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
| `movies.js`  | **lista filmów i osób**: tytuły, plakaty, kolory osób                 |
| `manifest.webmanifest`, `icons/` | nazwa i ikony aplikacji na ekranie początkowym    |

## Plakaty

Plakaty są oryginalne, z Filmwebu: pole `poster` w `movies.js` wskazuje plik na `fwcdn.pl`
(np. `filmweb("88/78/698878/7740691_1")` → `https://fwcdn.pl/fpo/88/78/698878/7740691_1.10.webp`;
środkowa liczba to numer filmu na Filmwebie, ostatnia to numer plakatu, `.10` to duży rozmiar).

Gdy plakat z Filmwebu się nie wczyta, aplikacja pyta angielską Wikipedię o grafikę z ramki artykułu filmu
(pole `wiki`) i zapamiętuje jej adres w przeglądarce. Bez internetu zostaje kolorowy „plakat zastępczy” z tytułem.
