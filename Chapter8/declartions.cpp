#include "../std_lib_facilities.h"

int f(int x){
    return x;
};


int main(){

    int i = 7;
    int& r = i;
     r = 9;
     i = 10;
    cout << i << ' ' << r << "\n";



}