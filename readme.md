"Implementacija sustava za praćenje osobnih financija"
1. STRUKTURA PODATAKA (Dinamička biblioteka .so):
- Stog implementiran kao polje fiksne veličine (100 elemenata) s operacijama:
* Inicijalizacija stoga (postavljanje top pokazivača)
* Push (dodavanje elementa)
* Pop (uklanjanje elementa)
* Peek (pregled vrha stoga)
* IsEmpty/IsFull provjere
* Ispis sadržaja stoga
2. STRUKTURA STOGA:
- Polje struktura transakcija (veličine 100)
- Pokazivač na vrh stoga (top)
- Maksimalna veličina stoga kao konstanta
3. STRUKTURA TRANSAKCIJE:
- Iznos (float)
- Kategorija (enum: 1-Hrana, 2-Režije, 3-Zabava, 4-Ostalo)
- Dan (1-31)
- Mjesec (1-12)
- Opis (max 50 znakova)
4. GLAVNA APLIKACIJA (koristi implementirani stog za pohranu):
Osnovne funkcionalnosti:
- Unos nove transakcije (push na stog)
- Poništavanje zadnje transakcije (pop sa stoga)
- Pregled zadnje transakcije (peek)
- Ispis svih transakcija (ispis stoga)
- Pregled ukupnog stanja
- Izlaz iz programa
Dodatne funkcionalnosti (ako ostane vremena):
- Pregled po kategorijama
- Mjesečni izvještaj
- Pretraživanje transakcija
5. OBAVEZNI ZAHTJEVI:
- Validacija unosa podataka
- Provjera stanja stoga prije operacija
- Osnovno error handling
- Komentari za funkcije
6. ORGANIZACIJA PROJEKTA:
- finance_tracker/ (glavni direktorij)
* src/ (source datoteke)
* include/ (header datoteke)
* lib/ (dinamička biblioteka .so)
* obj/ (objektne datoteke)
* bin/ (izvršna datoteka)