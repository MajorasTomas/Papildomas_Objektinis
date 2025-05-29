# Teksto Apdorojimo Programa

---

Programa skirta išrinkti daugiausiai pasikartojančius žodžius lietuviškame straipsnyje ir išvesti į atskirą failą pasikartojimų kiekį bei eilutes,
kuriuose galima rasti tuos žodžius. Taip pat programa gali surasti tekste paminėtas nuoruodas ir jas išvesti į atskirą failą.

---

PROGRAMOS PALEIDIMO INSTRUKCIJA:

1. Atsiųsti Visual Studio C++ kompiliatorių
2. Atsisiųsti programą 
3. Atsisiųsti visual studio programą
4. Įsikelti programos aplanką į visual studio programą
5. Paleisti programą

---

Kompiuterio specifickacijos:

|Komponentas|	Specifikacija|
|-------------|-----------|
|CPU|	AMD Ryzen 7740HS|
|RAM|	32 GB DDR5|
|HDD|SSD (NVMe)|

---

Rūšiavimas ir analizė atliekama naudojant std::map asociatyvų konteinerį, taip pat darbui su lietuviškomis raidėmis naudota <cctype> biblioteka. Norint, kad programa veiktų ne tik su
lietuvišku straipsniu, reikia pakeisti std::locale.
