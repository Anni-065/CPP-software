// String.cpp
#include <iostream>
using namespace std;

#include "String.h"

/*
Konstruktor : Standard Konstruktor
Beschreibung :
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Erstellt einem Leere Zeichenkette als Inhalt des Objekts

Parameter:
	keine

Rückgabe:
	keine
*/
String::String() {
	size = 0;
	str = new char[1];
	str[0] = '\0';
}


/*
Konstruktor : Zeichen
Beschreibung :
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Das übergebene Zeichen wird als String des Objekts gespeichert

Parameter:
	c - Zeichen

Rückgabe:
	keine
*/
String::String(char c) {
	size = 1;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
}


/*
Konstruktor : Zeichenkette
Beschreibung :
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Die übergeben Zeichenkette wird als String des Objekts gespeichert

Parameter:
	s - Zeichenkette

Rückgabe:
	keine
*/

String::String(const char* s) {
	// TODO
}

/*
Konstruktor : Kopierkonstruktor
Beschreibung :
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Kopiert die Zeichenkette des als Parameter Übergebenen String Objekts

Parameter:
	s - Objekt aus dem die Zeichenkette kopiert wird

Rückgabe:
	keine
*/

String::String(const String& s) {
	// TODO
}


/*
Konstruktor : Verschiebekonstruktor
Beschreibung :
	Konstruktor einer Stringobjekt.
	Initialisiert die aktuelle Instanz.
	Übernimmt die Zeichenkette der Übergebenen Instanz


Parameter:
	s - Objekt aus dem die Zeichenkette Übernommen wird

Rückgabe:
	keine
*/

String::String(String&& s) {
	// TODO
}

String::~String() { delete[] str; }


/*
Operator : []
Beschreibung :
	Liefert das an der  übergebenen Position vorhanden Zeichen zurück.

Parameter:
	index - Position des Zeichen in der Zeichenkette

Rückgabe:
	Zeichen an der Stelle index
*/

char& String::operator[](int index) {
	// TODO
}


/*
Operator : =
Beschreibung :
	Kopiert den Inhalt des Übergebenen String Objektes in das aktuelle Objekt.


Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt Kopiert wird

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/

String& String::operator=(const String& s) {
	// TODO
}


/*
Operator : = (move)
Beschreibung :
	verschiebt den Inhalt des Übergebenen String Objektes in das aktuelle Objekt.


Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt verschoben wird

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/

String& String::operator=(String&& s) {
	// TODO
}



/*
Operator : +
Beschreibung :
	hängt den Inhalt des Übergebenen String Objektes an das aktuelle Objekt na.


Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt angehängt wird

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/

String& String::operator+=(String& s) {
	// TODO
}