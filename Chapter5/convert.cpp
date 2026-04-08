#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

pair< double, string> ctok(double c) // converts Celsius to Kelvin
{
    //celsius to fahrenheit

    double f = c * 9/5 + 32;
    //fahrenheit to kelvin
    double k = (f - 32) * 5/9 + 273.15;

    if(k < 0.0) error("Value is below absolute 0"); // post-conditional check
    return {k, "Kelvin" };
}

pair <double, string> ktoc(double k) // convert Kelvin to Celsius
{
    if(k < 0.0) error("Value is below absolute zero");
    double c = k - 273.15;
    return {c, "Celsius" };
}

int main(){
    double value = 0; // decalre input varaible 
    char d; // declare degree 

    cout << "Provide degrees followed by c for celsius, k for kelvin\n"; //input for user
    cin >> value >> d; // retrieve temperature to input value

    pair<double, string> result;


    if(d == 'c'){
        result = ctok(value);
    } else if (d == 'k'){
        result = ktoc(value);
    } else {
        error("Unknown temperature unit");
    }
    cout << value << " " << d << " is converted to " << result.first << " " << result.second << "\n"; // print out temperature
}
