#include "std_lib_facilities.h"
#include <iostream>
using namespace std;

//--------------------------------------------------

class String_stream
{
    public:
        String_stream();
        string get();
        void putback(string s);
    private:
        bool full;
        string buffer;
};

//--------------------------------------------------

String_stream::String_stream()
    :full(false), buffer("") { }

//--------------------------------------------------

void String_stream::putback(string s)
{
    if(full)error("putback() into a full buffer");
    buffer = s;
    full = true;
}

//--------------------------------------------------

string String_stream::get()
{
    if(full){
        full = false;
        return buffer;
    }

    string s = " ";
    cin >> s;
    return s;
}

//--------------------------------------------------

String_stream sstr;

//--------------------------------------------------

//check if next string is conjuction
bool conjunction()
{
    string s = sstr.get();
    if(s == "and" || s == "or" || s == "but"){
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------

//check if next string is a noun
bool noun()
{
    string s = sstr.get();
    if(s == "birds" || s == "fish" || s == "C++"){
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------

//check if next string is a verb
bool verb()
{
    string s = sstr.get();
    if(s == "rules" || s == "fly" || s == "swim"){
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------

//handles subject
bool subject()
{
    string s = sstr.get();
    if(s == "the"){          //article before noun
        return noun();
    } else {                //no article, put string back and check if noun
        sstr.putback(s);
        return noun();
    }
}

bool sentence()
{
    return(subject() && verb());
}

int main()
try{

    cout<< "Enter an English sentence \n";
    bool is_ok = false;

    while(true){
        is_ok = sentence();
        if(!is_ok){
            cout << "Not OK \n";
            return 0;
        } 
        string s = sstr.get();

        if(s == "."){
            cout << "OK\n";
            return 0;
        } else {
            sstr.putback(s);
            is_ok = conjunction();
            if(!is_ok){
                cout << "Not OK\n";
                return 0;
            }
        }
    }

}
catch(exception& e)
{
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr<< "Oops: unknown exception!\n";
    return 2;
}


