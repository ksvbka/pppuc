/*
Ex 6.7: Write a grammar for bitwise logical expressions. A bitwise logical
expression is much like an arithmetic expression except that the operators are !
(not), ~ (complement), & (and), | (or), and ^ (exclusive or). Each operator does
its operation to each bit of its integer operands (see §25.5). ! and ~ are
prefix unary operators. A ^ binds tighter than a | (just as * binds tighter than
+) so that x|y^z means x|(y^z) rather than (x|y)^z. The & operator binds tighter
than ^ so that x^y&z means x^(y&z).*/
/*

// | < ^ < & < ~!

Grammar:
    Expression:
        Term
        Expression | Term // Handle |
    Term:
        Primary
        Term ^ Primary
    Primary
        Unit
        Primary & Unit
    Unit
        Number(int form)
        ~Number
        !Number
        ( Expression )
        ~( Expression )
        !( Expression )

*/

#include "std_lib_facilities.h"
#include <cassert>

//------------------------------------------------------------------------------

class Token{
public:
    char kind;
    int value;
    Token(char ch)
        : kind(ch), value(0) {}
    Token(char ch, int val)
        : kind(ch), value(val) {}
};

//------------------------------------------------------------------------------

class Token_stream{
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream()
    : full(false), buffer(0)
{}

Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;
    switch(ch){
        case ';':
        case 'q':
        case '~': case '!': case '^': case '|': case '&': case '(' : case ')':
                return Token(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '9':
                return Token('8', ch - '0');
        default:
            error("Bad Token");
    }
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

int Unit();
int Primary();
int Term();
int Expression();


Token_stream ts;

int Expression(){
    int left = Term();
    Token t = ts.get();
    while(true){
        if(t.kind == '|'){
            left |= Expression();
            t = ts.get();
        }else{
            ts.putback(t);
            return left;
        }
    }
}

int Term(){
    int left = Primary();
    Token t = ts.get();
    while(true){
        if(t.kind == '^'){
            left ^= Expression();
            t = ts.get();
        }else{
            ts.putback(t);
            return left;
        }
    }
}

int Primary(){
    int left = Unit();
    Token t = ts.get();
    while(true){
        if(t.kind == '&'){
            left &= Expression();
            t = ts.get();
        }else{
            ts.putback(t);
            return left;
        }
    }
}

int Unit(){
    Token t = ts.get();
    switch(t.kind){
        case '8':
            return t.value;
        case '(':
        {
            int ret = Expression();
                ret = !ret;
                t = ts.get();
                if(t.kind != ')')
                    error("Nead )");
            return ret;
        }
        case '~':
        {
            t = ts.get();
            if(t.kind == '8')
                return ~(t.value);
            if(t.kind == '('){
                int ret = Expression();
                ret = ~ret;
                t = ts.get();
                if(t.kind != ')')
                    error("Nead )");
                return ret;
            }

        }
        case '!':
        {
            t = ts.get();
            if(t.kind == '8')
                return !(t.value);
            if(t.kind == '('){
                int ret = Expression();
                ret = !ret;
                t = ts.get();
                if(t.kind != ')')
                    error("Nead )");
                return ret;
            }

        }
    }
}

int main(){
    try{
        int val = 0;
        cout << "Please input the logical expression, end with ; " << endl;
        while(cin){
            Token t = ts.get();

            if(t.kind == 'q') break;
            if(t.kind == ';')
                cout << " = " << val << endl;
            else
                ts.putback(t);
            val = Expression();
        }
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}
