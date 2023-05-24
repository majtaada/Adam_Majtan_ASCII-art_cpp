# ASCII-ART
Autor: Adam Majtán

ASCII art

Vaším cílem je napsat nástroj, který na vstupu získá obrázek nebo sadu několika obrázků a překonvertuje je do ASCII art vizualizace. Pomocí parametrů při spuštění a/nebo konfiguračních souborů parametrizujte generování souborů.

Implementujte následující funkcionality:

1. Nástroj načítá obrázky v alespoň jednom běžném souborovém formátu. (př. BMP, PNG, JPEG, SVG, …)

2. Implementujte alespoň 5 druhů různých operací (př. změna jasu, negativ, konvoluce, změna velikosti obrázku, …)

3. Výstupem nástroje je ASCII art (textové odstíny šedi) vytvořený z obrázků, který umí zobrazit a uložit do souboru.

4. Nástroj musí být konfigurovatelný ze souboru:

 a) definice ASCII přechodů (př. název, znaky seřazené dle hustoty, …)

 b) definice aplikovaných filtrů (jeden filtr může být aplikován víckrát s různými parametry)

5. V případě více předaných obrázků:

 a) Nástroj spustí prezentaci jednotlivých snímků, kterou lze ovládat (alespoň změna snímku, 	zastavení prezentace, spuštění prezentace).

 b) Lze definovat filtry pro jednotlivé obrázky i pro celou množinu.

Kde lze využít polymorfismus? (doporučené)

filtry: změna jasu, negativ, konvoluce, změna velikosti obrázku, …

různé styly ASCII vykreslení

formáty vstupu: BMP, SVG, RAW, …

druh výstupu: zobrazení, soubor, prezentace, …

uživatelské rozhraní: konzole, ncurses, SDL, OpenGL (různé varianty)

#Spracovanie zadania
Môj ASCII-ART program bude podporovať načítanie obrázku z formátu PNG. Program začne načítaním ascii prechodu v metóde **initializeAsciiTransition**. Po načítaní obrázku v
metódach **ReadInput** a **readPNG** v triede **CFileReader** bude obrázok prevedený na grayscale za pomoci
metódy **toGrayscale** z triedy **CTool**, a vráti maticovú reprezentáciu. Následne obrázok v
prekonvertuje na ascii reprezantáciu metódou **convertToAscii** , ktorú uloží do triedy **CImage** dokopy s grayscale maticou a menom obrázku. 
Ktoré budú uložené v triede **CImageLibrary**. V triede **CEffect** bude mať uživateľ na výber z piatich efektov, ktoré môže použiť: Zosvetlenie ,stmavenie, negatív, konvolúcia a zmenšenie. 
Budeme upravovať grayscale maticu obrázku. Kde potom metódou updateImage uložíme upravený obrázok a jeho adekvátnu ascii maticu. Uživateľ bude mať na výber v základnom menu 6 operácií: 
pridanie obrázku, zobrazenie obrázku, použitie efektu, vymazanie obrázku, uloženie obrázku a ukončenie programu.
Animáciu môžeme spustiť za pomoci triedy **CAnimation**, ktorú bude potom mocť zastaviť, spustiť,
odstrániť nejaký z obrázkov a spustiť ju len pre ostatné. Na zobrazovanie outputu budem používať linuxový terminál. Celý program bude riadený z **CManager**

#Kde používam polymorfizmus?
Polymorfizmus využívam pri triede **CEffect**,ktorá je parent class pre jednotlivé efekty:
**CEffectDarken**, **CEffectLighten**, **CEffectNegative** . Tieto triedy budu dediť spoločnú metódu **ApplyEffect**, ktorá bude mať na vstupe a výstupe **CImage**.
