# 🎬 Kino Rodzinne

Prosta, statyczna aplikacja do rodzinnego głosowania na film wieczoru (Tata, Mama, Ula, Antek).

## Jak uruchomić

Wystarczy otworzyć `index.html` w przeglądarce. Nie trzeba niczego instalować ani budować.
Można też wrzucić pliki na dowolny hosting statyczny, np. GitHub Pages.

## Jak działa

1. **Start**: ustawiasz, ile filmów może wybrać jedna osoba (domyślnie 3), i klikasz „Rozpocznij głosowanie”.
2. **Kto teraz głosuje?**: każdy wybiera swój bilet. Osoby, które już zagłosowały, mają pieczątkę
   „Głos oddany”. Ponowne wejście pozwala zmienić głosy.
3. **Wybór filmów**: dotknij plakatu, aby zaznaczyć film; przycisk „▶ Zwiastun” otwiera zwiastun.
   Na koniec kliknij „Zatwierdzam ✓”.
4. **Pokaż wyniki**: podium (3., 2., 1. miejsce) oraz pełna lista. Każdy wybrany film to 1 punkt.
   Filmy z tą samą liczbą głosów dzielą miejsce.
5. **Resetowanie** (z listy osób albo z ekranu wyników): przycisk „↺ Resetuj głosowanie” pozwala
   - „Wyczyść głosy”: usunąć wszystkie głosy i głosować od nowa z tym samym limitem,
   - „Zmień limit filmów”: zacząć zupełnie od nowa od ekranu startowego.

   Pojedyncza osoba może też usunąć tylko swój głos przyciskiem „🗑 Usuń mój głos” na ekranie wyboru filmów.

Głosy są zapisywane w `localStorage` przeglądarki, więc całe głosowanie odbywa się na jednym urządzeniu
(np. wspólnym tablecie). Wyniki zostają po odświeżeniu strony.

## Pliki

| Plik         | Zawartość                                                           |
|--------------|---------------------------------------------------------------------|
| `index.html` | szkielet strony                                                     |
| `styles.css` | wygląd: kurtyny, neonowy szyld, bilety, podium                      |
| `app.js`     | logika: ekrany, głosowanie, liczenie wyników                        |
| `movies.js`  | **lista filmów i osób**: tutaj zmienia się tytuły, plakaty, zwiastuny |

## Plakaty i zwiastuny

Plakaty są linkowane z TMDB (`image.tmdb.org`). Jeśli któryś się nie wczyta, aplikacja pokaże kolorowy
„plakat zastępczy” z tytułem. Aby podmienić plakat, zmień pole `poster` w `movies.js` na dowolny adres
obrazka (np. skopiowany z Filmwebu lub IMDb). Pole `trailer` to link do zwiastuna. Domyślnie prowadzi do
wyszukiwania polskiego zwiastuna na YouTube, ale można tam wkleić bezpośredni link do filmu.
