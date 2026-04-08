#include "std_lib_facilities.h"
#include <iostream>
using namespace std;

class Name_value
{
    public:
        Name_value(string n, int s): name(n), score(s) { }
        string name;
        int score;
};

int main()
try
{
    vector<Name_value> pairs;
    string n;
    int v;

    while(cin >> n >> v && n != "NoName"){
        for(int i=0; i<pairs.size(); i++){
            if(n == pairs[i].name) error("Duplicate: ", n);
        } 
        pairs.push_back(Name_value(n,v));
    }

    for (int i=0; i<pairs.size(); i++){
        cout << pairs[i].name << " " << pairs[i].score << "\n";
    }
}
catch(exception& e)
{
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...)
{
    return 2;
}


