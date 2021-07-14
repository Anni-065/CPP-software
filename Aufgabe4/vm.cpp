#include "utility.h"
#include "vm.h"


Code newPush(int i) {
    return Code(OpCode_t::PUSH, i);
}

Code newPlus() {
    return Code(OpCode_t::PLUS);
}

Code newMult() {
    return Code(OpCode_t::MULT);
}

Optional<int> VM::run() {
    // always start with an empty stack
    stack<int> d;
    s.swap(d);

    for (int i = 0; i < code.size(); i++) {
        switch (code[i].kind) {
            case OpCode_t::PUSH:
                s.push(code[i].val);
                break;
            case OpCode_t::MULT: {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left * right);
                break;
            }
            case OpCode_t::PLUS: {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left + right);
                break;
            }
        }
    }

    if (s.empty())
        return nothing<int>();

    return just<int>(s.top());
} // run
