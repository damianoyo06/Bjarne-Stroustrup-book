#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

void print(string& label, const vector<int>& v){
    cout << label << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
}

void fibonacci(int x, int y, vector<int>& v, int n){
    if(n < 1) error("the sequnce requires at least 1 digit");
    v.push_back(x);
    if(n == 1) return;
    v.push_back(y);
    if(n == 2) return;
    for(int i=2; i<n; i++){
        v.push_back(v[i-1] + v[i-2]);
    }
}

int main()
{
    vector<int> v;
    int x;
    int y;
    int n;
    string s = "Your Fibonacci sequence:";

    cout << "Enter your first number in the sequence:" << '\n';
    cin >> x;
    cout << "Enter your second number in the sequence:" << '\n';
    cin >> y;
    cout << "Enter your length of the sequence:" << '\n';
    cin >> n;

    fibonacci(x, y, v, n);
    print(s, v);
    
    

    
    
}