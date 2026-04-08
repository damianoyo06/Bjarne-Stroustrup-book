
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------
//constants:
const char number = '8'; //t.kind==number means that t is a number Token
const char quit = 'q'; //t.kind==quit means that t is a quit Token
const char print = ';'; //t.kind == print means that t is a print Token
const string prompt = "> "; //used to indicate what follows is a prompt
const string result = "= "; //used to indicate what follows is a result

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
private:
    bool full {false};        // is there a Token in the buffer?
    Token buffer = {'0'};     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------
void Token_stream::ignore(char c) // c represtes the kind of Token
{
    if(full && c == buffer.kind){
        full = false;
        return;
    }
    full = false;
    
    //now search for input
    char ch = 0;
    while(cin>>ch){
        if(ch==c) return;
    }
}
//------------------------------------------------------------------------------

Token Token_stream::get()
    //read all characters from cin and compose a Token
{
    if (full) {       // check if we already have a Token ready
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:    
    case quit:   
    case '(': 
    case ')': 
    case '{': 
    case '}': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '!': 
    case '%':
        return Token{ch};        // let each character represent itself
    case '.':                   //a floating point-literal
    case '0': case '1': case '2': case '3': case '4': //numerical literal
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token{number, val};   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

class Variable{
public:
    string name;
    double value;
};

vector<Variable> var_table;
//------------------------------------------------------------------------------
double get_value(string s) //return a value of a variable names s
{
    for(const Variable& v : var_table){
        if(v.name == s) return v.value;
    }
    error("get: undefined varaible", s);
}
//------------------------------------------------------------------------------
void set_value(string s, double d) // set variable names s to d
{
    for(Variable& v : var_table){
        if(v.name==s){
            v.value = d;
            return;
        }
    }
    error("set: undefined varaible", s);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
bool is_declared(string var)
{
    for(const Variable&v : var_table){
        if(var.name == var) return true;
    }
    return false;
}
//------------------------------------------------------------------------------

//=====Add {var, val} to the var_table=====
double define_name(string var, double val)
{
    if(is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable{var, val});
    return val;
}
//------------------------------------------------------------------------------


double term();

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double factorial(double d)
{
    int p = d;
    if(double(p) != d){
        error("factorial not defined for doubles");
    } else if (d == 0){
        return 1;
    } else if (d < 0){
        error("Factorial valid for positive numbers only");
    } else if (d > 31){
        error("number too large");
    } else {
        int res = 1;
        for(int i = d; i > 0; i--){
            res *= i;
        }
        return res;
    }
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    double d;

    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case '{': // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if(t.kind != '}') error("'}' exprected");
            return d;
    }
    case number:            
        d = t.value;    //return the number's value
        break;
    case '-':
        d = -primary();
        break;
    case '+':
        d = primary();
        break;
    default:
        error("primary expected");
    }

    t = ts.get();
    if(t.kind == '!'){
        return factorial(d);
    }
    if(t.kind != '!'){
        ts.putback(t);
        return d;
    }


}
        

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if(d==0)error("%: divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }  
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}
//------------------------------------------------------------------------------

//====assume we have seen let, handle: name = expression, declare a vraible called "name" with the initial value "expression"
double decleration()
{
    Token t = ts.get();
    if(t.kind != name) error("name expected in decleration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error(" = missing in delcartion of ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}


//------------------------------------------------------------------------------
double statement()
{
    Token t = ts.get();
    switch(t.kind){
    case let:
        return decleration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------
void clean_up_mess()
{
    ts.ignore(print);
}
//------------------------------------------------------------------------------

void calculate()
{
     while(cin) 
     try{
        cout << prompt; 
        Token t = ts.get();

        while(t.kind==print) t=ts.get();
        if(t.kind == quit){
           return;
        }
        ts.putback(t);
        cout<< result <<statement() << '\n';
    }
    catch(exception& e){
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}
//------------------------------------------------------------------------------



int main()
try
{
    cout << "Welcome to our simple calculator. \n"
        << "Please enter expressions using floating-point numbers. \n'"
        << "This calculator supports +, -, *, /, %, and (). \n"
        << "Please add "<< print << " at the end of the expression to calculate \n"
        << "To exit pres " << quit << " \n";
    calculate();
    return 0;

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

//------------------------------------------------------------------------------