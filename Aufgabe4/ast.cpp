#include <iostream>
#include <string>

using namespace std;

#include "ast.h"

int IntExp::eval() { 
    return val;
}

/*
Methode: pretty
Klasse: IntExp
Beschreibung :
    Bearbeitet den aktuellen Knoten eines Ganzzahl Ausdrucks und gibt diesen als ein Stringobjekt zurück.

Parameter:
    keine

Rückgabe:
    ein Stringobjekt mit der Textrepresentation dieses Knotens.
*/
string IntExp::pretty() {
    return to_string(val);
}

vector<Code> IntExp::cleverPretty() {
    return vector<Code>{
        newPush(val)
    };
}

int PlusExp::eval() {
    return e1 -> eval() + e2 -> eval(); 
}

/*
Methode: pretty
Klasse: PlusExp
Beschreibung :
    Bearbeitet den aktuellen Knoten eines Additionsausdrucks und gibt diesen als ein Stringobjekt zurück.
    Das erstellte Objekt beinhaltet neben dem eigentlichen Knoten auch alle diesem Knoten zugeordneten Tochterknoten.
    Der gesammte Ausdruck wird in dem erstellten Stringobjekt automatisch mit eine Anfangs- sowie Endklammer versehen.

Parameter:
    keine

Rückgabe:
    Ein Stringobjekt mit der Textrepresäntation dieses Knotens, sowie allen diesem Knoten zugewisenen Tochterknoten.
*/
string PlusExp::pretty() {
    string s("");
    s.append(e1 -> pretty())
      .append("+")
      .append(e2 -> pretty());
    return s;
}
 
vector<Code> PlusExp::cleverPretty() {
    vector<Code> e1_cPretty = e1 -> cleverPretty();
    vector<Code> e2_cPretty = e2 -> cleverPretty();
    e1_cPretty.insert(e1_cPretty.end(), e2_cPretty.begin(), e2_cPretty.end());
    e1_cPretty.push_back(newPlus());
    return e1_cPretty;
}

int MultExp::eval() { return e1 -> eval() * e2 -> eval(); }

void MultExp::printExp(string* s, std::shared_ptr<Exp> e) {
    if (e -> expType == Exp_t::PlusExp_t) {
        s -> append("(").append(e -> pretty()).append(")");
    }
    else {
        s -> append(e -> pretty());
    }
}

/*
Methode: pretty
Klasse: PlusExp
Beschreibung :
    Bearbeitet den aktuellen Knoten eines Multiplikationsausdrucks und gibt diesen als ein Stringobjekt zurück.
    Das erstellte Objekt beinhaltet neben dem eigentlichen Knoten auch alle diesem Knoten zugeordneten Tochterknoten.
    Der gesammte Ausdruck wird in dem erstellten Stringobjekt automatisch mit eine Anfangs- sowie Endklammer versehen.

Parameter:
    keine

Rückgabe:
    Ein Stringobjekt mit der Textrepräsentation dieses Knotens sowie aller diesem Knoten zugewiesenen Tochterknoten
*/
string MultExp::pretty() {
    string s("");
    printExp(&s, e1);
    s.append("*");
    printExp(&s, e2);
    return s;
}

vector<Code> MultExp::cleverPretty() {
    vector<Code> e1_cPretty = e1 -> cleverPretty();
    vector<Code> e2_cPretty = e2 -> cleverPretty();
    e1_cPretty.insert(e1_cPretty.end(), e2_cPretty.begin(), e2_cPretty.end());
    e1_cPretty.push_back(newMult());
    return e1_cPretty;
}
/*
Methode  : newInt
Klasse : IntExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ IntExp.
    Der neu erstellter Knoten ist immer ein Endknoten und bestzt selbst keine Äste.

Parameter:
    i - Wert des Knotens

Rückgabe:
    Ein Objekt vom Typ IntExp
*/
EXP newInt(int i) {
    return std::make_shared<IntExp>(i);
}

/*
Methode: newPlus
Klasse: PlusExp
Beschreibung :
    Erstellt einen neuen Ausdruck/Objekt vom Typ PlusExp.
    Der Objekt PlusExp ist ein Knoten der immer zwei Äste besitz.
    Dem Knoten werden die beiden als Parameter angegebenen Ausdrücke als linker und rechter Ast zugewiesen.

Parameter:
    l - linker Ausdruck
    r - rechter Ausdruck

Rückgabe:
        Ein Objekt vom Typ PlusExp
*/
EXP newPlus(EXP l, EXP r) {
    return std::make_shared<PlusExp>(l, r);
}

/*
Methode: newMult
Klasse: MultExp
Beschreibung :
    Erstellt einen neuen Ausdruck/Objekt vom Typ MultExp.
    Der Objekt MultExp ist ein Knoten der immer zwei Äste besitz.
    Dem Knoten werden die beiden als Parameter angegebenen Ausdrücke als linker und rechter Ast zugewiesen.

Parameter:
    l - linker Ausdruck
    r - rechter Ausdruck

Rückgabe:
        Ein Objekt vom Typ PlusExp
*/ 
EXP newMult(EXP l, EXP r) {
    return std::make_shared<MultExp>(l, r);
}