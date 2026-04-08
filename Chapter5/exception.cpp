#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main()
try{
   
    int x1 = narrow_cast<int>(2.9); //throws
    int x2 = narrow_cast<int>(2.0); // OK
    char c1 = narrow_cast<char>(1066); // throws
    char c2 = narrow_cast<char>(85); // OK
    int a = 2;
    int b = 1;
    if(b==0){
        throw runtime_error("Division by zero");
    }

    int sum = a/b;
    cout << sum;
    return 0;
}
catch(runtime_error& e){
    cerr<<"Error: " << e.what() << "\n";
    return 1;
}