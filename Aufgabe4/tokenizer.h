// Tokenizer for exp


#ifndef __TOKENIZER__
#define __TOKENIZER__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class seccase {
    EOS,           // End of string
    ZERO,
    ONE,
    TWO,
    OPEN,
    CLOSE,
    PLUS,
    MULT
};

string showTok(seccase t);

// Elementary tokenize(r) class
class Tokenize {
    string s;
    int pos;
public:
    Tokenize(string s) {
        this->s = s;
        pos = 0;
    }

    // Scan throuh string, letter (symbol) by letter.
    seccase next();
    vector<seccase> scan();
    string show();

};


// Wrapper class, provide the (current) token.
class Tokenizer : Tokenize {
public:
    seccase token;
    Tokenizer(string s) : Tokenize(s) { token = next(); }
    void nextToken() {
        token = next();
    }
};

#endif // __TOKENIZER__