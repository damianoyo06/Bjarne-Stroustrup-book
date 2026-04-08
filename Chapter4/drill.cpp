#include <iostream>
#include "std_lib_facilities.h"
using namespace std;


int main(){
    double a = 0.0;
    double b = 0.0;
    cout << "Enter two values \n";
    while(cin>> a >> b){

        if(a < b){
            cout << "The smaller value is " << a << " and the larger value is " << b << "\n";
           
        } else if ( a > b){
             cout << "The smaller value is " << b << " and the larger value is " << a << "\n";
        } else if (a == b){
            cout << "The value " << a << " is equal to " << b << "\n";
        }

         if(abs(a-b) < 0.01){
                cout << a << " is almost equal to " << b << "\n";
            }
    }
}