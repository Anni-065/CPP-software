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
	const char* temp = s;

	while (*s != '\0') {
		size++;
		s++;
	}

	str = new char[size + 1];

	for (int i = 0; i < size; i++) {
		str[i] = temp[i];
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
	size = s.size;
	char* p = s.str;

	int i = 0;

	while (p[i] != '\0') {
		str[i] = p[i];
		i++;
	}
	str[size] = '\0';
}


/*
Konstruktor: Verschiebekonstruktor
Beschreibung:
	Konstruktor einer Stringobjekt.
	Initialisiert die aktuelle Instanz.
	Übernimmt die Zeichenkette der übergebenen Instanz.

Parameter:
	s - Objekt aus dem die Zeichenkette übernommen wird.

Rückgabe:
	keine
*/
String::String(String&& s) {
	this->size = s.size;
	this->str = s.str;

	s.size = 0;
	s = nullptr;
}
String::~String() { 
	delete[] str;
}


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
	char* retStr;
	retStr = str + index - 1;
	return *retStr;
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
	if (this != &s) {
		delete[] str;
		size = s.size;

		str = new char[s.size + 1];
		char* p = s.str;

		int i = 0;

		while (p[i] != '\0') {
			str[i] = p[i];
			i++;
		}
		str[size] = '\0';
	}
	return *this;
}


/*
Operator: = (move)
Beschreibung :
	Verschiebt den Inhalt des übergebenen String Objektes in das aktuelle Objekt.

Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt verschoben wird.

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/
String& String::operator=(String&& s) {
	if (this != &s) {
		delete[] str;

		str = s.str;
		size = s.size;

		s.size = 0;
		s.str = nullptr;
	}
	return *this;
}


/*
Operator: +=
Beschreibung :
	Hängt den Inhalt des übergebenen String Objektes an das aktuelle Objekt an.

Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt angehängt wird.

Rückgabe:
	Referenz auf das aktuelle Stringobjekt
*/
String& String::operator+=(String& s) {
	String temp = str;
	delete[] str;
	str = new char[size + s.size + 1];

	int i = 0;

	while (temp.str[i] != '\0') {
		str[i] = temp.str[i];
		i++;
	}
	i = 0;
	while (s.str[i] != '\0') {
		str[size + i] = s.str[i];
		i++;
	}
	size = size + s.size;
	str[size] = '\0';

	return *this;
}