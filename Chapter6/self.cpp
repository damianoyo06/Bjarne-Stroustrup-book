
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//strutucture:

class Token
{
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0) { }
    Token(char ch, double val)
        :kind(ch), value(val) { }
};

class Token_stream
{
    public:
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full {false};
        Token buffer = {'0'};
};

Token_stream::Token_stream()
    :full(false), buffer(0)
{    
}

void Token_stream::putback(Token t)
{
    if(full)error("putback() into a full buffer");
    buffer = t;
    full = true;
}


Token Token_stream::get(){

    if(full){
        full = false;
        return buffer;
    }
    
    char ch;
    cin >> ch;
    switch(ch){
        case '=':
        case 'x':
        case '(': case ')': case '{': case '}': case '*': case '/': case '+': case '-': case '!':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('8', val);
        }
    }
}

Token_stream ts;

double expression();

double factorial(double d)
{
    int p = d;
    if(double(p) != d) error("factorial not defined for doubles");
    else if (d < 0) error("facotrial only valid for positive numbers");
    else if ( d == 0) return 1;
    else {
        int res = 1;
        for(int i= d; i> 0; i--){
            res *= i;
        }
        return res;
    }
}

double primary()
{
    Token t = ts.get();
    double d;

    switch(t.kind){
    case '(':
    {
        double d = expression();
        t = ts.get();
        if(t.kind != ')')error("')' expected");
            return d;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if(t.kind != '}')error("'}' expected");
        return d;
    }
    case '8':
        d = t.value;
        break;
    default:
        error("Primary expected");
    }

    t = ts.get();
    if(t.kind == '!')
    {
        return factorial(d);
    } else {
        ts.putback(t);
        return d;
    }
   
}

double term()
{
    double left = primary();
    Token t = ts.get();
    
    while(true){
        switch(t.kind){
        case '*':
        {
            left *= primary();
            t = ts.get();
            break;   
        }
        case '/':
        {
            double d = primary();
            if( d== 0)error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '+':
         {   left += term();
            t = ts.get();
            break;
        }
        case '-':
        {    left -= term();
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

int main()
try
{
    cout << "Enter you vals \n";

    double val = 0;

    while(cin){
        Token t = ts.get();

        if(t.kind == 'x') break;
        if(t.kind == '='){
            cout << "=" << val << '\n';
        } else {
            ts.putback(t);
        }
        val = expression();
    }
} 
catch (exception& e){
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...){
    cerr << "Ooos: unknown exception!\n";
    return 2;
}
