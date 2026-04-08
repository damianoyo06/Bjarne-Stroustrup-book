#include <iostream>
#include "std_lib_facilities.h"
#include <algorithm>
using namespace std;

int main()
{

    vector<int> number;
    vector<int> guess;

    bool guessed = false;

    while (!guessed)
    {
        number.clear();
        guess.clear();
        cout << "Enter a digit followed by enter repeatadly four times: \n";

        while (guess.size() < 4)
        {
            int random = randint(9);
            if (find(guess.begin(), guess.end(), random) == guess.end())
            {
                guess.push_back(random);
            }
        }

        // debuggin printing the guess numbers
        // for(int n:guess){
        //     cout << n << "\n";
        // }
        while (number.size() < 4)
        {
            int n;
            cin >> n;

            if (find(number.begin(), number.end(), n) == number.end())
            {
                number.push_back(n);
            }
            else
            {
                cout << n << " already entered \n";
            }
        }

        int bull = 0;
        int cow = 0;
        for (int i = 0; i < number.size(); i++)
        {

            if (number[i] == guess[i])
            {
                bull++;
            }
            else if (find(guess.begin(), guess.end(), number[i]) != guess.end())
            {
                cow++;
            }
        }

        cout << bull << " bulls and " << cow << " cows \n";

        if (bull == 4)
        {
            guessed = true;
            cout << "Correct, you have guessed the number \n";
            cout << "do you want to play again? \n";
            char again;
            cin >> again;
            if (again == 'y')
            {
                bull = 0;
                cow = 0;
                number.clear();
                guess.clear();
                guessed = false;
            }
        }
        else
        {
            number.clear();
            cout << "Try again \n";
        }
    }
}