#include <iostream>
#include "std_lib_facilities.h"
#include <algorithm>
using namespace std;

int main()
{
    vector<char> letter;
    vector<char> guess;

    bool guessed = false;

    // Repeat until guessed correctly
    while (!guessed)
    {
        while (guess.size() < 4)
        {
            int i = randint(26);
            char c = 'a' + i;
            if (find(guess.begin(), guess.end(), c) == guess.end())
            {
                guess.push_back(c);
            }
        }

        // Printing out computer's guess
        cout << "Generated sequence: ";
        for (int i = 0; i < guess.size(); i++)
        {
            cout << guess[i];
        }
        letter.clear();

        cout << "\n Please enter 4 letters: \n";

        while (letter.size() < 4)
        {
            char c;
            cin >> c;

            if (find(letter.begin(), letter.end(), c) == letter.end())
            {
                letter.push_back(c);
            }
        }

        // Printing out user input
        cout << "User's letters: ";
        for (int i = 0; i < letter.size(); i++)
        {
            cout << letter[i];
        }

        int bull = 0;
        int cow = 0;

        // Check for bull & cow
        for (int i = 0; i < guess.size(); i++)
        {
            if (letter[i] == guess[i])
            {
                bull++;
            }
            else if (find(guess.begin(), guess.end(), letter[i]) != guess.end())
            {
                cow++;
            }
        }

        // Print out the cows and bulls
        cout << "\n"
             << bull << " bulls and " << cow << " cows." << "\n";

        if (bull == 4)
        {
            guessed = true;
            cout << "Correct, you have guessed 4 letters. \n";
            cout << "Do you want to play again? y (yes) n (no)\n";
            char again;
            cin >> again;
            if (again == 'y')
            {
                bull = 0;
                cow = 0;
                guessed = false;
                letter.clear();
                guess.clear();
            }
        }
        else
        {
            letter.clear();
            cout << "try again";
        }
    }
}
