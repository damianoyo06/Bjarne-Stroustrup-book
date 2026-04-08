#include <iostream>
using namespace std;

int main(){

    const double yen_to_dollar = 0.0064;
    const double kroner_to_dollar = 0.099;
    const double pound_to_dollar = 1.33;
    
    double value;
    char currency = ' ';

    cout << "Please enter value followed by currency, y for Yen, k for Kroner, and p for Pouds \n";
    cin >> value >> currency;

    cout << value << currency;
    if(currency == 'y'){
        cout<< " is $" << value * yen_to_dollar;
    } else if (currency == 'k'){
        cout<< " is $" << value * kroner_to_dollar;
    } else if (currency == 'p'){
        cout<< " is $" << value * pound_to_dollar;
    } else {
        cout << " is invalid";
    }
}