#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    vector<string> numbers =
        {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "Please enter a digit or spell out a digit \n";

    string input = " ";

    cin >> input;

    bool isDigit = false;
    if(input.size() < 2){
        isDigit = true;
    }
    if(isDigit){
        int index = stoi(input);
        cout << "Your number is " << numbers[index];
    } else {
        bool found = false;
        for(int i=0; i<numbers.size(); i++){
            if(input == numbers[i]){
                cout << "Your number is " << i;
                found = true;
                break;
            }
        }
    }
}