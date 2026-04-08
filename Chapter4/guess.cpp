#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    cout << "Think of a number between 1 and 100 \n";

    int low = 1;
    int high = 100;
   
    for(int i=0; i<7; i++){
        int mid = (low + high) / 2;
        cout << "Is your number greater than " << mid << "?";
        char answer = ' ';
        cin >> answer;
        if(answer == 'y'){
            low = mid + 1;
        } else {
            high = mid;
        }

        if(low == high){
            cout<< "your number is " << low << "\n";
            return 0;
        }

       
    }

      cout<< "your number is " << low << "\n";
   
    
    
}