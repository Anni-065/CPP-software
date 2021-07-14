#include "utility.h"
#include "ast.h"
#include "tokenizer.h"
#include "parser.h"


// E  ::= T E'
Optional<EXP> Parser::parseE() {

    Optional<EXP> t = parseT();
    if (t.isNothing())
        return t;

    return parseE2(t.fromJust());
}


// E' ::= + T E' |
Optional<EXP> Parser::parseE2(EXP left) {

    if (t.token == seccase::PLUS) {
        t.nextToken();

        Optional<EXP> right = parseT();
        if (right.isNothing())
            return right;

        return parseE2(newPlus(left, right.fromJust()));
    }

    return just<EXP>(left);
}


// T  ::= F T'
Optional<EXP> Parser::parseT() {

    Optional<EXP> f = parseF();
    if (f.isNothing())
        return f;

    return parseT2(f.fromJust());
}


// T' ::= * F T' |
Optional<EXP> Parser::parseT2(EXP left) {
    if (t.token == seccase::MULT) {
        t.nextToken();

        Optional<EXP> right = parseF();
        if (right.isNothing())
            return right;

        return parseT2(newMult(left, right.fromJust()));
    }

    return just<EXP>(left);
}


// F ::= N | (E)
Optional<EXP> Parser::parseF() {
    switch (t.token) {
    case seccase::ZERO:
        t.nextToken();
        return just<EXP>(newInt(0));
    case seccase::ONE:
        t.nextToken();
        return just<EXP>(newInt(1));
    case seccase::TWO:
        t.nextToken();
        return just<EXP>(newInt(2));
    case seccase::OPEN: { // introduce new scope
        t.nextToken();
        Optional<EXP> e = parseE();
        if (e.isNothing())
            return e;
        if (t.token != seccase::CLOSE)
            return nothing<EXP>();
        t.nextToken();
        return e; }
    default: return nothing<EXP>();
    }

}
