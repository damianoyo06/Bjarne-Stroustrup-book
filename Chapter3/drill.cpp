#include <iostream>
using namespace std;

int main(){

    string first_name;
    string friend_name;
    char friend_sex = 0;
    int age;
    cout << "Enter your first name \n";
    cin >> first_name;
    cout << "What is your age? \n";
    cin >> age;
    cout << "What is your friend's name \n";
    cin >> friend_name;
    cout << "Enter m for male, f for female \n";
    cin >> friend_sex;

    cout << "Dear, " << first_name
        << "\n How are you?";
        if(friend_sex == 'm'){
            cout << "\n If you see " << friend_name << " please ask him to call me \n";
        } else {
            cout << "\n If you see " << friend_name << " please ask her to call me \n";
        }

   if(age < 0 || age > 110){
    cout << "You're kidding \n";
   } else if (age == 12){
    cout << "Next year you will be " << age+1 << "\n";
    } else if (age == 17){
    cout << "Next year you will be able to vote \n";
   } else if (age == 70){
    cout << "Enjoy your retirement \n";
    } else {
         cout << "I hear you just had a birthday and you are " << age << " years old \n";
    }

    cout << "Yours sincerely \n"
        << "\n"
        << "\n"
        << first_name;
   }