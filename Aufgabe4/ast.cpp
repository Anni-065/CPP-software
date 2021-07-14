#include <iostream>
#include <string>

using namespace std;

#include "ast.h"

int IntExp::eval() { return val; }

/*
Methode  : pretty
Klasse : IntExp
Beschreibung :
    Bearbeitet den aktuellen Knoten einer Ganzzahl Ausdrucks und gibt diesem als ein Stringobjekt zurück.
.

Parameter:
    keine

Rückgabe:
    ein Stringobjekt mit der Textrepresentation dieses Knotens.
*/


string IntExp::pretty() {
    return to_string(val);
}

vector<Code> IntExp::superpretty() {
    return vector<Code>{newPush(val)};
}

int PlusExp::eval() { return e1->eval() + e2->eval(); }

/*
Methode  : pretty
Klasse : PlusExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten einer Additionsausdrucks und gibt diesem als ein Stringobjekt zurück.
    Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
    Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt automatisch mit eine Anfangs sowie endklammer versehen.

Parameter:
    keine

Rückgabe:
    ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/

string PlusExp::pretty() {
    string s("");
    s.append(e1->pretty())
        .append("+")
        .append(e2->pretty());
    return s;
}
/*
 * Original Methode Pretty
string PlusExp::pretty() {
    string s("(");				// "klammer öffnen" anhängen
    s.append(e1->pretty());		// linken Knotten ausführen und das Ergebnis anhängen
    s.append("+");				// Pluszeichen anhängen
    s.append(e2->pretty());		// rechten Knotten ausführen und das Ergebnis anhängen
    s.append(")");    			// "klammer zu" anhängen
    return s;
}*/

vector<Code> PlusExp::superpretty() {
    vector<Code> e1_spretty = e1->superpretty();
    vector<Code> e2_spretty = e2->superpretty();
    e1_spretty.insert(e1_spretty.end(), e2_spretty.begin(), e2_spretty.end());
    e1_spretty.push_back(newPlus());
    return e1_spretty;
}

int MultExp::eval() { return e1->eval() * e2->eval(); }

void MultExp::printExp(string* s, std::shared_ptr<Exp> e) {
    if (e->expType == Exp_t::PlusExp_t) {
        s->append("(").append(e->pretty()).append(")");
    }
    else {
        s->append(e->pretty());
    }
}
/*
Methode  : pretty
Klasse : PlusExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten eines Multiplikationsausdrucks und gibt diesem als ein Stringobjekt zurück.
    Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
    Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt automatisch mit eine Anfangs- sowie Endklammer versehen.

Parameter:
    keine

Rückgabe:
    ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/

string MultExp::pretty() {
    string s("");
    printExp(&s, e1);
    s.append("*");
    printExp(&s, e2);
    return s;
}

vector<Code> MultExp::superpretty() {
    vector<Code> e1_spretty = e1->superpretty();
    vector<Code> e2_spretty = e2->superpretty();
    e1_spretty.insert(e1_spretty.end(), e2_spretty.begin(), e2_spretty.end());
    e1_spretty.push_back(newMult());
    return e1_spretty;
}
/*
Methode  : newInt
Klasse : IntExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ IntExp.
    Der neu erstellter Knoten ist immer ein Endknoten und bestzt selbst keine Äste.

Parameter:
    i - wert des Knotens.

Rückgabe:
    ein Objekt vom TYP IntExp
*/

EXP newInt(int i) {
    return std::make_shared<IntExp>(i);
}
/*
Methode  : newPlus
Klasse : PlusExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ PlusExp.
    Der Objekt PlusExp ist ein Knoten der immer zwei Äste besitz.
    Dem knoten werden die beiden als Parameter angegebenen Expresionen ala linker und rechter Ast zugewiesen.

    Beispiele:

    2 + 4

      +
     / \
    2   4

Eine der zugewisenen Ausdruck kann wiederum wieitere Äaste anthalten: (ohne Gewähr da nur vermutung, nicht getestet)

   2 + 4 * 5

      +
     / \
    2   *
       / \
      4   5


Parameter:
    l - linker Ausdruck
    r - rechter Ausdruck

Rückgabe:
        ein Objekt vom TYP PlusExp
*/

EXP newPlus(EXP l, EXP r) {
    return std::make_shared<PlusExp>(l, r);
}
/*
Methode  : newMult
Klasse : MultExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ MultExp.
    Der Objekt MultExp ist ein Knoten der immer zwei Äste besitz.
    Dem Knoten werden die beiden als Parameter angegebenen Expresionen ala linker und rechter Ast zugewiesen.

Parameter:
    l - linker Ausdruck
    r - rechter Ausdruck

Rückgabe:
        ein Objekt vom TYP PlusExp
*/


EXP newMult(EXP l, EXP r) {
    return std::make_shared<MultExp>(l, r);
}