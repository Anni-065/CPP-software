// String.cpp
#include <iostream>
using namespace std;

#include "String.h"

/*
Konstruktor: Standard Konstruktor
Beschreibung:
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Erstellt einem leere Zeichenkette als Inhalt des Objekts.

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
Konstruktor: Zeichen
Beschreibung:
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Das übergebene Zeichen wird als String des Objekts gespeichert.

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
Konstruktor: Zeichenkette
Beschreibung:
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Die übergeben Zeichenkette wird als String des Objekts gespeichert.

Parameter:
	s - Zeichenkette

Rückgabe:
	keine
*/
String::String(const char* s) {
	size = 0;

	while (*s != '\0') {
		size++;
		s++;
	}
	size++;

	str = new char[size];

	for (int i = 0; i < size; i++) {
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
}

/*
Konstruktor: Kopierkonstruktor
Beschreibung:
	Konstruktor eines Stringobjekts.
	Initialisiert die aktuelle Instanz.
	Kopiert die Zeichenkette des als Parameter übergebenen String Objekts.

Parameter:
	s - Objekt aus dem die Zeichenkette kopiert wird.

Rückgabe:
	keine
*/
String::String(const String& s) {
	str = new char[s.size + 1];
	char* p = s.str;

	int i = 0;

	while (*p != '\0') {
		str[i] = *p;
		i++;
	}

	str[size] = '\0';
}


/*
Konstruktor: Verschiebekonstruktor
Beschreibung:
	Konstruktor einer Stringobjekt.
	Initialisiert die aktuelle Instanz.
	Übernimmt die Zeichenkette der Übergebenen Instanz.

Parameter:
	s - Objekt aus dem die Zeichenkette übernommen wird.

Rückgabe:
	keine
*/
String::String(String&& s) {
	//TODO
}
String::~String() { delete[] str; }


/*
Operator: []
Beschreibung:
	Liefert das an der übergebenen Position vorhanden Zeichen zurück.

Parameter:
	index - Position des Zeichen in der Zeichenkette.

Rückgabe:
	Zeichen an der Stelle index.
*/
char& String::operator[](int index) {
	//TODO
}


/*
Operator: =
Beschreibung:
	Kopiert den Inhalt des übergebenen String Objektes in das aktuelle Objekt.

Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt kopiert wird.

Rückgabe:
	Referenz auf das aktuelle Stringobjekt.
*/
String& String::operator=(const String& s) {
	//TODO
}


/*
Operator: = (move)
Beschreibung :
	verschiebt den Inhalt des übergebenen String Objektes in das aktuelle Objekt.

Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt verschoben wird.

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/
String& String::operator=(String&& s) {
	//TODO
}


/*
Operator: +
Beschreibung :
	Hängt den Inhalt des übergebenen String Objektes an das aktuelle Objekt an.

Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt angehängt wird.

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/
String& String::operator+=(String& s) {
	//TODO
}