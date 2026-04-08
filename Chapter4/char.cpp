#include <iostream>
using namespace std;

int main(){
    int i=0;

    while(i < 26){
        char c = 'a' + i;
        cout << c << '\t' << int(c) << '\n';
        ++i;
    }
}