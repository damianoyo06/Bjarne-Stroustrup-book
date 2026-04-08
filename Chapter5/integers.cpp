#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main()
try
{
    vector<double> v;
    vector<double> diff;
    int number = 0;
    double sum = 0;

    cout << "Please enter the number of values you want to sum:\n";
    cin >> number;
    if(number < 0) error("The number has to be a positive integer");
    int value;
    cout << "Please enter integers (press '|' to stop): \n";

    while(cin >> value){
        v.push_back(value);
    }

    if(number > v.size()) error("Number out of bounds");
    for(int i=0; i<number; i++){
       sum += v[i];
    }
    for(int i=1; i<number; i++){
        diff.push_back(v[i] - v[i-1]);
    }

    if(sum > INT_MAX || sum < INT_MIN) error("the number cannot be written as an int");
    cout << "The sum is: " << sum <<"\n";
    cout << "The differneces are: \n";
    for(int i=0; i<number-1; i++){
        cout << diff[i] << "\n";
    }
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}