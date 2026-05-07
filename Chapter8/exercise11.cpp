#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;


void print_until_s(vector<string>v, string quit){
    bool seen = false;
    for(string s:v){
        if(s == quit){
            if(seen == true){
                return;
            }
            seen = true;
        };
        cout << s << '\n';
    }
}



int main()
{
    vector<string> v;
    string s;
    string quit;

    cout << "Enter your list of words: \n";
    while(cin>>s && s!="done"){
        v.push_back(s);
    }

    cout << "Enter your until what word to print: \n";
    cin >> quit;

    print_until_s(v, quit);

}