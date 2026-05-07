#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

vector<string> names;
vector<int> ages;


void enterValues()
{
    string name;
    cout << "Enter list of names, when complete write 'done' \n";
    while (cin >> name && name != "done")
    {
        for (int i = 0; i < names.size(); i++)
        {
            if (name == names[i])
            {
                error("Duplicate Name");
            }
        }
        names.push_back(name);
    }

    for (int i = 0; i < names.size(); i++)
    {
        double age;
        cout << names[i] << " age of: " << '\n';
        cin >> age;
        ages.push_back(age);
    }
}

void printInfo(vector<string> name, vector<int> age){

    for(int i=0; i<age.size(); i++){
        cout << "Name: " << name[i] << ", aged: " << age[i] << '\n';
    }
}

int find_index(const vector<string>& name, string s){
    for(int i=0; i<name.size(); i++){
        if(name[i] == s){
            return i;
        }
        
    }
    error("not found");
}

void sortedNames(vector<string>& name, vector<int> age){
    vector<int> org_age = ages;
    vector<string> org_name = names;
    sort(name.begin(), name.end());

    for(int i=0; i<ages.size(); i++){
        ages[i] = org_age[find_index(org_name, name[i])];
    }

}
int main()
{
    enterValues();
    cout << "Names with ages before sorting \n";
    printInfo(names, ages);
    cout << "Names with ages after sorting \n";
    sortedNames(names,ages);
    printInfo(names, ages);

}