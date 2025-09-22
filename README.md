OSY PREP:

vycisteni makefajlu:
	• make clean

Creates the static library:
	• LIBFILE

	.o files:
	• Object files jsou tedy "poloprodukt" mezi zdrojovým kódem a finálním programem.

STATICKÁ knihovna: 
	• obsahuje všechen zkompilovaný kód (knihovna (.o soubory) i main) v jednom binárním souboru
	• pak už ho jen spustíme: ./vysledek
DYNAMICKÁ knihovna:
	• Main je zkompilovaný v binárním souboru
	• Knihovna je zkompilovaná odděleně v .so souboru
	• Binární soubor obsahuje jen "odkazy" na funkce v knihovně
	• muíme mu dát přesnou cestu k tomu .so (export LD_LIBRARY_PATH=.)
	• Propojení se děje až za běhu
	• pak už ho jen spustíme: ./vysledek
