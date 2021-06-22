#include "String.h"

ostream& operator<< (ostream& out, String& s) {
    for (int i = 0; i < s.size; i++) {
        out << s.str[i];
    }

    return out;
}


int main() {
    String s("Eins");
    String s2("Zwei");

    cout << s << endl;
    s += s2;
    cout << s << endl;
}
