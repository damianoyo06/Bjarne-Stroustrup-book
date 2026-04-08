#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    vector<string> game = {"Rock", "Paper", "Scissors"};
       srand(time(0));
        int userScore = 0;
        int cpuScore = 0;
        int draw = 0;

       while(userScore < 5 || cpuScore < 5){


        cout << "Enter rock, paper or sicssors \n r \n p \n s \n";
        char userInput;
        cin >> userInput;
        string userPlayed = " ";

        switch(userInput){
            case 'r':
                userPlayed = "Rock";
                break;
            case 'p':
                userPlayed = "Paper";
                break;
            case 's':
                userPlayed = "Scissors";
                break;
            default:
                cout << "Incorrect input";
                break;
        }


        int r = rand() %3;
        cout << "My choice is " << game[r] << "\n";

        if(userPlayed == game[r]){
            cout << "It's a draw \n";
            draw++;
        } else if (userPlayed == "Rock" && r == 2){
            cout << "You win \n";
            userScore++;
        } else if (userPlayed == "Paper" && r == 0){
            cout << "You win \n";
            userScore++;
        } else if (userPlayed == "Scissors" && r == 1){
            cout << "You win \n";
            userScore++;
        } else {
            cout << "You loose \n";
            cpuScore++;
        }

        cout << "The current score is: "
            << "\n You won " << userScore << " times"
            << "\n I won " << cpuScore << " times" 
            << "\n and we have drawn " << draw << " times. \n";


   }
}

