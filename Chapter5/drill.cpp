#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main()
try {
    
    string s = "ape";
    bool c = "fool" > s;
    if(c){
        cout << "Success\n";
    }

    keep_window_open();
    return 0;
}
catch(exception& e){
    cerr << "error: " << e.what() << "\n";
    keep_window_open();
    return 1;
}
catch(...){
    cerr << "Unknown exception!\n";
    keep_window_open();
    return 2;
}