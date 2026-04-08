#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    double v1 = 0.0;
    double v2 = 0.0;

    char op = ' ';

    cout << "Please enter an equation \n";
    cin >> v1 >> op >> v2;

    switch(op){
        case '+':
            cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2;
            break;
        case '-':
            cout << "The difference of " << v1 << " and " << v2 << " is " << v1 - v2;
            break;
        case '*':
            cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2;
            break;
        case '/':
            cout << "The quotient of " << v1 << " and " << v2 << " is " << v1 / v2;
            break;
        default:
            cout << "Your operator is unfamiliar to me";
    }

}