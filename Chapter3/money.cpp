#include <iostream>
using namespace std;

int main(){
    int penny;
    int nickel;
    int dime;
    int quater;
    int half;
    
    cout << "Enter the amout for penny \n";
    cin >> penny;
    cout << "Enter the amout for nickel \n";
    cin >> nickel;
    cout << "Enter the amout for dime \n";
    cin >> dime;
    cout << "Enter the amout for quarter \n";
    cin >> quater;
    cout << "Enter the amout for 50 cents \n";
    cin >> half;

    double sum = penny + (nickel * 5) + (dime * 10) + (quater * 25) + (half * 50);
    cout << "You have " 
        << "\n" << penny << " pennies"
        << "\n" << nickel << " nickels"
        << "\n" << dime << " dimes"
        << "\n" << quater << " quaters"
        << "\n" << half << " half dollars"
        << "\n" << "The values of all your coins is " 
        << sum
        << " cents, which is $" << sum/100;





}