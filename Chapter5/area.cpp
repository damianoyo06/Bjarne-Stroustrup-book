#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int area(int length, int width)
//calcualte the area of a rectangle
//precondition: length and width need to be positive
//postcondition: area needs to be positive
{
    if(length<=0 || width <=0) error("area() pre-condition");
    int a = length * width;
    if(a<=0) error("area() post-condition");
    return a;
}

int main(){
    int a = 0;
    int b = 0;

    cout << "Enter values for a and b: \n";
    cin >> a >> b;


    cout<< "The area of " << a << " * " << b << " is " << area(a,b) << "\n";
}

