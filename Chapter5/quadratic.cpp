#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    double a, b, c;

    cout << "Enter values, a, b, c : \n";
    cin >> a >> b >> c;

    cout << "Your values: " << a << " "<< b << " "<< c;

    //ax^2+bx + c = 0;
    if(a == 0 || b == 0) error("No real roots");
    double sum = pow(b, 2);
    sum -= 4 * a * c;
    if(sum < 0)error("negative number");
    sum = sqrt(sum);
    a = 2 * a;
    
    double x1 = 0;
    double x2 = 0;

    x1 = (-b + sum) / a;
    x2 = (-b - sum) / a;

    cout << "The result is " << x1 << " and " << x2;
}