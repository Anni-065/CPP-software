#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "tokenizer.h"


string showTok(seccase t) {
    switch (t) {
    case seccase::EOS:   return "EOS";
    case seccase::ZERO:  return "ZERO";
    case seccase::ONE:   return "ONE";
    case seccase::TWO:   return "TWO";
    case seccase::OPEN:  return "OPEN";
    case seccase::CLOSE: return "CLOSE";
    case seccase::PLUS:  return "PLUS";
    case seccase::MULT:  return "MULT";
    }
    // NOTE: The (clang) compiler is able to figure out that
    // along all control-flow paths, a return statement will be reached.
}

seccase Tokenize::next() {
    if (s.length() <= pos)
        return seccase::EOS;

    while (1) {

        if (s.length() <= pos)
            return seccase::EOS;

        switch (s[pos]) {
        case '0': pos++;
            return seccase::ZERO;
        case '1': pos++;
            return seccase::ONE;
        case '2': pos++;
            return seccase::TWO;
        case '(': pos++;
            return seccase::OPEN;
        case ')': pos++;
            return seccase::CLOSE;
        case '+': pos++;
            return seccase::PLUS;
        case '*': pos++;
            return seccase::MULT;
        default:  // we simply skip all other symbols !
            pos++;
            break;
        }
    }
} // next


vector<seccase> Tokenize::scan() {
    vector<seccase> v;
    seccase t;

    do {
        t = next();
        v.push_back(t);
    } while (t != seccase::EOS);

    return v;
} // scan


string Tokenize::show() {
    vector<seccase> v = this->scan();
    string s;

    for (int i = 0; i < v.size(); i++) {
        s += showTok(v[i]);
        if (i + 1 < v.size())
            s += ";";         // Add delimiter
    }
    return s;
} // show
