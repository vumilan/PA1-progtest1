# PA1-progtest01

Úkolem je vytvořit program, který bude počítat umístění bodů v rovině tak, aby vznikly rovnoběžníky.

V rovině jsou zadané 3 body: A, B a C. Každý z bodů je zadaný pomocí svých souřadnic (dvojice desetinných čísel). Program tyto souřadnice přečte ze svého vstupu a určí souřadnice čtvrtého bodu tak, aby vznikl rovnoběžník (případně nějaká ze speciálních variant rovnoběžníku: kosočtverec, obdélník nebo čtverec). Souřadnici čtvrtého bodu program zobrazí na svém výstupu, dále zobrazí informaci o případném speciálním tvaru vznikajícího obrazce (čtverec/obdélník/ kosočtverec/rovnoběžník). Obecně existují 3 možnosti umístění bodu (rovnoběžníky ABA'C, ABCB' a AC'BC), viz ukázka běhu programu níže.

Může se stát že vstupní body leží na přímce, pak zadání nemá žádné řešení. Program tuto situaci musí detekovat a odpovídajícím způsobem zareagovat (viz ukázka běhu programu níže).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:
* nečíselné zadání souřadnic (neplatné desetinné číslo),
* chybějící souřadnice,
* chybějící nebo přebývající oddělovače (souřadnice musí být zadaná v hranatých závorkách, hodnoty x a y musí být oddělené čárkou).
