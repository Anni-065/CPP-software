/*
 * Aufgabe 2.c
 *
 *  Created on: 11.05.2021
 *      Author: Athanasia Leontarakis
 */
#include <stdio.h>
#include <stdlib.h>
 // es sind keine Weiter Bibliotheken erlaubt

 /*
 Funktion : length

 Beschreibung :
	 Bestimmt die (netto) Länge der übergebenen Zeichenkette.
	 Korrekte Funktion wird nur für 7 Bit ASCII Zeichen garantiert. UTF kodierte Zeichen führen zu fehlerhaften Längenangaben.

 Parameter:
	 s - Zeichenkette dessen Länge bestimmt werden soll

 Rückgabe:
	 Nettolänge der Zeichenkette (ohne den Terminator)
 */
int length(char* s) {
	int n = 0;
	while (*s != '\0') {
		n++;
		s++;
	}

	return n;
}





// Annahme: n ist > 0
void copy(char* s, int n, char* t) {
	int i = 0;
	while (i < n) {
		t[i] = s[i];
		i++;
	}
}



/*
Funktion : reverse

Beschreibung :
	Dreht die übergebene Zeichenkette zeichenweise um.
	Der für die neue Zeichenkette benötigter Speicherplatz wird auf dem Heap reserviert.
	Korrekte Funktion wird nur für 7 Bit ASCII Zeichen garantiert. UTF kodierte Zeichen führen zu fehlerhaften Kodierung

	Beispiele:
	"abg" -> "gba"
	"Hallo" -> "ollaH"

Parameter:
	s - Zeichenkette die umgedreht werden soll


Rückgabe:
	Zeiger auf die neue umgedrehte Zeichenkette
*/

char* reverse(char* s)
{
	// Hier sollte Ihre eigene Implementierung von reverse weilen
}



/*
Funktion : putBack
Beschreibung :
	Fügt am Ende der übergebenen Zeichenkette (s) ein Zeichen (c) ein.
	Der für die neue Zeichenkette benötigter Speicherplatz wird auf dem Heap reserviert.


Parameter:
	s - Zeichenkette die ein neues Zeichen aufnehmen soll
	c - Zeichen das am anfang der Zeichenkette (s) eingefügt werden soll


Rückgabe:
	neue, um das übergebene Zeichen erweiterte Zeichenkette.
*/
char* putBack(char* s, char c) {
	const int n = length(s);
	char* r = malloc(sizeof(char) * (n + 2));
	copy(s, n, r);
	r[n] = c;
	r[n + 1] = '\0';
	return r;
}

/*
Funktion : reverseRec
Beschreibung :
	Dreht die übergebene Zeichenkette zeichenweise um. Funktion ruft sich selbst rekursiv auf bis keine Zeichen mehr in der Übergebenen Zeichenkette vorhanden sind.
	Diese Funktion verwendet die Funktion putBack() um neue (gedrehte) Zeichenketten zu erstellen.
	Alte, nicht mehr benötigte Zeichenkette der folgender Rekursionsstuffe wird mit free() freigegeben.
	Korrekte Funktion wird nur für 7 Bit ASCII Zeichen garantiert. UTF kodierte Zeichen führen zu fehlerhaften Kodierung.

	Beispiele:
	"abg" -> "gba"
	"Hallo" -> "ollaH"

Parameter:
	s - Zeichenkette die umgedreht werden soll

Rückgabe:
	Zeiger auf die neue umgedrehte Zeichenkette
*/
char* reverseRec(char* s)
{
	// Hier sollte Ihre eigene Implementierung von reverseRec weilen
	if (*s == '\0')
	{
		// Rekursionsabbruch
	}


}

int main()
{
	printf("Hallo Aufgabe 2!");

	// Hier sind keine Automatischen Tests notwendig. Es reicht einfach nur ein paar umgedrehte Zeichenketten auf der Konsole auszugeben. 


	return 0;
}