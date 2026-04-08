#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main()
{
    vector<string> names;
    vector<int> scores;

    string name = " ";
    int score = 0;

    cout << "Enter name and score: \n";
    while (cin >> name >> score)
    {

        if (name == "NoName")
        {
            break;
        }

        bool found = false;
        for (int i = 0; i < names.size(); i++)
        {
            if (name == names[i])
            {
                cout << name << " " << scores[i];
                found = true;
                break;
            }
        }

        if (!found)
        {
            names.push_back(name);
            scores.push_back(score);
        }
    }

    cout << "The following names and scores are: \n";
    for (int i = 0; i < names.size(); i++)
    {
        cout << "(" << names[i] << "\t" << scores[i] << ")" << "\n";
    }
}