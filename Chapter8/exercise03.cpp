#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

void reverseNum(vector<int>& v){
    int l = 0;
    int r = v.size()-1;

    while(l < r){
        swap(v[l], v[r]);
        l++;
        r--;
    }
}

void reverseString(vector<string>& s){
    int l=0;
    int r=s.size()-1;
    while(l<r){
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

template<typename T>
void print(const vector<T>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
}

int main()
{
    vector<int> nums = {1,3,5,7,9, 10};
    vector<string> s = {"Damian", "Angela", "Barhomelev", "Victor", "Nancy"};
    cout << "Pre-reverse: " << '\n';
    print(nums);
    print(s);
    reverseNum(nums);
    reverseString(s);
    cout << "Post-reverse: " << '\n';
    print(nums);
    print(s);
}