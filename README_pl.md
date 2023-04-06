# Grep

Zadaniem programu jest znalezienie danej frazy wśród plików z bieżącego folderu i folderów,
które się w nim znajdują, i utworzenie pliku z wynikami poszukiwań oraz pliku z logami
działających wątków. Za pomocą flag istnieje możliwość zmiany przeszukiwanej ścieżki, nazw
powstających plików oraz ilości działających wątków. Na koniec działania programu ma zostać
wyświetlony komunikat, przedstawiający informacje takie jak: ilość przeszukanych plików,
ilość plików zawierających poszukiwaną frazę, ilość znalezionych instancji, ścieżkę do pliku
z wynikami działania programu i z logami wątków, ilości działających wątków oraz czas działania
programu.

Zrobiłem również podstawowy plik CMakeLists.txt, jedyny sposób jaki znam na kompilację
z jego pomocą to utworzenie i wejście w folder build/ i wpisanie kolejno komend:
```
cmake ..
make
```
lub pobranie go z tego repozytorium, można wtedy pominąć pierwszą komendę.

Próbowałem również stworzyć pulę wątków i funkcję przeszukania ścieżki zmusić do działania
w wątkach, ale z racji, że to mój pierwszy kontakt z wielowątkowością, nie udało się. Moje
próby widoczne są na gałęzi threadpool.
