// String.h
#include <iostream>
using namespace std;

class String {
private:
    // 'String' is represented internally as a plain C-style string.
    int size;
    char* str;
public:
    String();
    String(char c);
    String(const char*);
    String(const String&);
    String(String&&);
    ~String();

    char& operator[](int index);
    String& operator=(const String&);
    String& operator=(String&&);
    String& operator+=(String&);

    // make friend, so we can access private members
    friend ostream& operator<< (ostream& out, String& s);

};
