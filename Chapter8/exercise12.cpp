#include <iostream>
#include <algorithm>
#include "../std_lib_facilities.h"
using namespace std;

string shortAlphaSort(const vector<string>& v);
string longAlphaSort(const vector<string>& v);


void shortestAndLongest(vector<int> num, vector<string> v){
    int shortest = INT_MAX;
    int longest = 0;
    int shortIndex = 0;
    int longIndex = 0;

    for(int i=0; i<num.size(); i++){
        int current = num[i];
        if(current < shortest){
            shortest = current;
            shortIndex = i;
        }
        if(current > longest){
            longest = current;
            longIndex = i;
        }
    }

    cout << "The shortest word is " << v[shortIndex];
    cout << " with " << shortest << " letters" << '\n';
    cout << "The longest word is " << v[longIndex];
    cout << " with " << longest << " letters";

}

void print(vector<string>& v){
    vector<int> num;

    for(int i=0; i<v.size(); i++){
        num.push_back(v[i].size());
        cout << "The length of " << v[i] << " is " << num[i] << " letters" << '\n';
    }

    shortestAndLongest(num, v);
    
    cout << "Alphabetically first: "
         << shortAlphaSort(v) << '\n';

    cout << "Alphabetically last: "
         << longAlphaSort(v) << '\n';
}

string shortAlphaSort(const vector<string>& v){

    if(v.size() == 0) error("argument is empty vector");
    vector<string> v_cp = v;
    sort(v_cp.begin(), v_cp.end());
    return v_cp[0];
} 

string longAlphaSort(const vector<string>& v){

    if(v.size() == 0) error("argument is empty vector");
    int n = v.size()-1; 
    vector<string> v_cp = v;
    sort(v_cp.begin(), v_cp.end());
    return v_cp[n]; 
}

int main()
{
    vector<string> name;
    string s;

    cout << "Enter your words: \n";
    while(cin >> s && s != "done"){
        name.push_back(s);
    }

    print(name);
}