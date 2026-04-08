#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> digits;
    vector<string> unit;
    unit.push_back(" ones ");
    unit.push_back(" tens ");
    unit.push_back(" hundred ");
    unit.push_back(" thousands ");
    unit.push_back(" tens of thousands ");
    unit.push_back(" hundred of thausands ");

    cout << "Please enter a digit. To submit enter a semicolon followed by a new line\n";
    char d;
    
    //getting user's input
    while(cin>> d){
        if(d < '0' || d > '9') break; // break the inoput if the input is not a digit
        digits.push_back(d - '0');
    }

    //error handling
    if(digits.size() == 0)error("The size of digits is 0");
    if(digits.size() > unit.size())error("Can't handle that many digits");

    //print out the digits
    int n = digits.size() -1;
    for(int i=0; i<=n; i++){
         cout << digits[i] << unit[n-i];
    }
    
  
}