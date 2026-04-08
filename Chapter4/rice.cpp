#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    int grain = 1;
    int square = 1;

    bool printed_1t = false;
    bool printed_1m = false;
    bool printed_1b = false;
    
    while(square <= 64){
       

        if(!printed_1t && grain >= 1000){
            cout << "You need " << square << " squares for 1,000 grains \n";
            printed_1t = true;

        }
        if(!printed_1m && grain >= 1000000){
            cout << "You need " << square << " squares for 1,000,000 grains \n";
            printed_1m = true;
        }
        if(!printed_1b && grain >= 1000000000){
            cout << "You need " << square << " squares for 1,000,000,000 grains \n";
            printed_1b = true;
        }

         square++;
        grain *= 2;
    }
}