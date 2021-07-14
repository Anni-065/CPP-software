// AST for exp


#ifndef __AST__
#define __AST__

#include <iostream>
#include <string>
#include <memory>
#include "vm.h"

using namespace std;

enum class Exp_t {
    IntExp_t,
    PlusExp_t,
    MultExp_t
};

class Exp {
public:
    virtual int eval() = 0;
    virtual string pretty() = 0;
    virtual vector<Code> cleverPretty() = 0;
    Exp_t expType;
};

class IntExp : public Exp {
    int val;
public:
    IntExp(int _val) {
        val = _val;
        expType = Exp_t::IntExp_t;
    }
    int eval();
    string pretty();
    vector<Code> cleverPretty();
};

class PlusExp : public Exp {
    std::shared_ptr<Exp> e1;
    std::shared_ptr<Exp> e2;
public:
    PlusExp(std::shared_ptr<Exp> _e1, std::shared_ptr<Exp> _e2) {
        e1 = _e1;
        e2 = _e2;
        expType = Exp_t::PlusExp_t;
    }
    int eval();
    string pretty();
    vector<Code> cleverPretty();
};


class MultExp : public Exp {
    std::shared_ptr<Exp> e1;
    std::shared_ptr<Exp> e2;
    void printExp(string* s, std::shared_ptr<Exp> e);
public:
    MultExp(std::shared_ptr <Exp> _e1, std::shared_ptr<Exp> _e2) {
        e1 = _e1;
        e2 = _e2;
        expType = Exp_t::MultExp_t;
    }
    int eval();
    string pretty();
    vector<Code> cleverPretty();
};

// Short-hands

typedef std::shared_ptr<Exp> EXP;

EXP newInt(int i);

EXP newPlus(EXP l, EXP r);

EXP newMult(EXP l, EXP r);


#endif // __AST__
