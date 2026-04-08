#include "std_lib_facilities.h"
#include <iostream>
using namespace std;

class Token
{
public:
    char kind;
    double value;
    Token(char ch):
        :kind(ch), value(0) {}
    Token(char ch, double val)
        :kind(ch), value(val) {}
}

double expression()
{
    double left = term();
 
    while(true){
        Token t = ts.get();
        if(t.kind == '+'){
            left += term();
        } else {
            ts.putback(t);
            return left;
        }
    }
}

double term()
{
    double left = primary();

    while(true){
        Token t = ts.get();
        if(t.kind == '*'){
            left *= primary();
        } else {
            ts.putback(t);
            return left;
        }
    }
  
}

double primary()
{
    Token t = ts.get();

    switch(t.kind){
    case '(':
    {

        double d = expression();
        t= ts.get();
        if(t.kind != ')')error("Expected ')'");
        return d;
    }
    case '8':
        return t.value;
    default:
        error("Primary expected");
    }
   
}