# ASCII-ART
Autor: Adam Majtán

ASCII art

Váš program:
1.	z jednoho až n obrázků běžného formátu (BMP/SVG/RAW/TGA, ...) načte data a ty validně zobrazí v ASCII (odstíny šedi)
2. ze souboru načte definovaný ASCII přechod
3. umožňuje alespoň tři jednoduché operace (zesvětlení/ztmavení obrázku, vymazání, konvoluce, negativ, ...)
4. umožnuje "spuštění" animace v případě více načtených obrázků a triviální editaci animace na úrovní framů (např. mazání framů, seřazení za sebou, ...)
Program bude umět pracovat s minimálně jedním obrázkovým formátem.

Program bude mít jednoduché možnosti přehrávání animace (zastavit, spustit, zobrazit konkrétní frame, ...).

Kde lze využít polymorfismus? (doporučené)

- Nástroje pro manipulaci a jejich efekty, sady znaků, ...
- Formáty vstupu: BMP, SVG, RAW, ...
- Různé styly ASCII vykreslení
- Přehrávač: obrázek (jen zobrazí), sekvence (přehraje více obrázků)
- Uživatelské rozhraní: konzole, ncurses, SDL, OpenGL (různé varianty), ...

#Spracovanie zadania
Môj ASCII-ART program bude podporovať načítanie obrázku z formátu PNG. Program začne načítaním ascii prechodu v metóde **initializeAsciiTransition**. Po načítaní obrázku v
metódach **ReadInput** a **readPNG** v triede **CFileReader** bude obrázok prevedený na grayscale za pomoci
metódy **toGrayscale** z triedy **CTool**, a vráti maticovú reprezentáciu. Následne obrázok v
prekonvertuje na ascii reprezantáciu metódou **convertToAscii** , ktorú uloží do triedy **CImage** dokopy s grayscale maticou a menom obrázku. 
Ktoré budú uložené v triede **CImageLibrary**. V triede **CEffect** bude mať uživateľ na výber zo štyroch efektov, ktoré môže použiť: Zosvetlenie ,stmavenie, konvolúcia a negatív. 
Budeme upravovať grayscale maticu obrázku. Kde potom metódou updateImage uložíme upravený obrázok a jeho adekvátnu ascii maticu. Uživateľ bude mať na výber v základnom menu 5 operácií: 
pridanie obrázku, zobrazenie obrázku, použitie efektu, vymazanie obrázku a ukončenie programu.
Animáciu môžeme spustiť za pomoci triedy **CAnimation**, ktorú bude potom mocť zastaviť, spustiť,
odstrániť nejaký z obrázkov a spustiť ju len pre ostatné. Na zobrazovanie outputu budem používať obyčajný terminál. Celý program bude riadený z **CManager**

#Kde používam polymorfizmus?
A tiež polymorfizmus využívam pri triede **CEffect**,ktorá je parent class pre jednotlivé efekty:
**CEffectDarken**, **CEffectLighten**, **CEffectNegative** . Tieto triedy budu dediť spoločnú metódu **ApplyEffect**, ktorá bude mať na vstupe a výstupe **CImage**.
