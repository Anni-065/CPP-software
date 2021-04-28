/*
 * Aufgabe 1.c
 *
 *  Created on: 25.04.2021
 *      Author: Athanasia Leontarakis
 */

#include <stdio.h>

#define TEST_CASES_COUNT   16		// Anzahl der Tests

//Teststruktur eines Testpaares. Enthält Zeiger die zu testende Zeichenkette sowie auf dem erwarteten Suffix
typedef struct {
    char* input;	// Zeiger auf die ursprüngliche Zeichenkette
    char* expected;	//Zeiger auf dem erwarteten Ergebnis
} TestCase;

/*
Funktion : extract
Beschreibung :
    Sucht den Suffix in einer Zeichenkette und liefert diesen zurück.
    Der Suffix ist definiert als alle Zeichen nach den Letzten zwei nacheinander folgenden Doppelpunkten die als Trennzeichen dienen.

    Zeichenkette<::>Sufix
    Zeichenkette:<::>Sufix
    Zeichenkette:::Zeichenkette<::>Sufix

Parameter:
    input - Zeiger auf die Zeichenkette in der nach dem Suffix gesucht werden sollte.

Rückgabe:
    Zeiger auf das erste Zeichen der übergebenen Zeichenkette die nach den Letzten zwei hintereinander folgenden Doppelpunkten liegt
*/
char* extract(char* input) {
    char* r = input;
    int counter = 0;

    while(*input != '\0') {
        if (*input == ':') {
            input++;
            if (*input == ':') {
                while (*input == ':') {
                    input++;
                }
                counter++;
                r = input;
            }
        }
        if (*input != '\0') {
           input++;
        }
    }

    if (counter == 0) {
        r = input;
    }
    
    return r;
}

/*
Funktion : extract2
Beschreibung :
    Sucht den Suffix in einer Zeichenkette und liefert diesem zurück.
    Der Suffix ist definiert als alle Zeichen nach den Letzten zwei nacheinander folgenden Doppelpunkten die als Trennzeichen dienen.

    Zeichenkette<::>Sufix
    Zeichenkette:<::>Sufix
    Zeichenkette:::Zeichenkette<::>Sufix

Parameter:
    input - Zeiger auf die Zeichenkette in der nach dem Suffix gesucht werden sollte.
    output - Zeiger auf das erste Zeichen der übergebenen Zeichenkette die nach den Letzten zwei hintereinander Folgenden Doppelpunkten liegt (Call by reference)

Rückgabe:
    Keine
*/
void extract2(char* input, char** output) {
    *output = extract(input);
}

typedef enum {
    OK,		// Test war OK
    FAIL	// Test ist fehlgeschlagen
} Test;

/*
Funktion: testExpected

Beschreibung:
    Extrahiert den Suffix der Übergebenen Zeichenkette. Prüft ob der extrahierte Suffix den erwarteten entspricht.

Parameter:
        input -    Zeiger auf die Zeichenkette, in der nach dem Suffix gesucht werden sollte
        expected - Zeiger auf die Zeichenkette mit dem erweiterten Ergebnis

Rückgabe:
        OK oder Fail je nach dem ob die extrahierte Zeichenkette der Übergebenen entsprochen hat (OK), oder nicht (FALSE)
*/
Test testExpected(char* input, char* output) {
    Test t;
    int flag = 0;
    char* result = extract(input);

    while (*result != '\0' || *output != '\0') {
        if (*result == *output) {
            result++;
            output++;
        } else if ((*result == '\0' && *output != '\0') || (*result != '\0' && *output == '\0') || *result != *output) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        t = OK;
    }
    else {
        t = FAIL;
    }
    return t;
}

Test testExpected2(char* input, char* expected) {
    Test t;
    char* ergebnis;    // Zeiger reservieren
    extract2(input, &ergebnis);    // Adresse des Zeigers "Ergebnis" übergeben
}

/*
Funktion: runTests

Beschreibung:
    Führt automatische Tests und prüft ob die aus dem Eingaben extrahierte Suffixe den erwarteten entsprechen.
    Die Ausgabe der Testergebnisse erfolgt auf der Konsole.

Parameter:
        no 	  - Anzahl der Tests die durchgeführt werden sollten
        test - Struktur die zu Prüfende Paare enthält

Rückgabe:
        keine
*/
void runTests(int no, TestCase test[]) {
    Test t;
    int i;

    for (i = 0; i < no; i++) {
        printf("Test %d: ", i);
        t = testExpected(test[i].input, test[i].expected);
        if (OK == t)
            printf("OK - Input: %s, Expected: %s, Output: %s \n", test[i].input, test[i].expected, extract(test[i].input)); // das ist hier zu wenig. Bitte um sinnvolle Angaben erweitern so das der Kunde bei der Präsentation ohne den Debugger erkennen kann was hier passiert!
        if (FAIL == t)
            printf("FAIL - Input: %s, Expected: %s, Output: %s \n", test[i].input, test[i].expected, extract(test[i].input)); // das ist hier zu wenig. Bitte um sinnvolle Angaben erweitern so das der Kunde bei der Präsentation ohne den Debugger erkennen kann was hier passiert!
        printf("\n");
    }
}

int main() {
    printf("Hallo Aufgabe 1! \n\n");

    TestCase tests[TEST_CASES_COUNT] = {
         {"", ""},	// Sonderfall
         {"Hel::lo", "lo"},
         {"Hell::o", "o"},
         {"Hello", ""},
         {"::Hello", "Hello"},
         {"Hel::lo", "lo"},
         {"Hello::", ""},
         {"Hel:::lo", "lo"},
         {"H::ell::o", "o"},
         {"H::ell:::o", "o"},
         {":Hell:::o", "o"},
         {"::", ""},
         {":::", ""},
         // es folgen Tests die die Funktionsfähigkeit der Testfunktion überprüfen. Der Kunde will sehen dass die Testfunktion Fehler erkennen kann.
         {"H::allo", ""},
         {"H:allo", "allo"},
         {"Hal:::lo", ":lo"}
    };

    runTests(TEST_CASES_COUNT, tests); // Tests der Funktion extract ausführen

                                      // Tests der Funktion extract2 ausführen
}
