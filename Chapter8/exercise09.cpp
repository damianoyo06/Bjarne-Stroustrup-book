#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

vector<double> price;
vector<double> weight;

void print(const vector<double>& p, const vector<double>& w){
    if(p.size() != w.size()) error ("Price and weight and not equal in size");
    double total = 0;
    
    for(int i=0; i<p.size(); i++){
        double sum = p[i] * w[i];
        cout << "The sum of " << p[i] << " and " << w[i] << " is: " << sum << '\n';
        total += sum;
    }

    cout << "The total sum is: " << total << '\n';
}

int main()
{
    price = {2.0, 2.50, 4.99, 19.99};
    weight = {12.30, 41.20, 11.20, 5.45};
    
    print(price, weight);
    
}