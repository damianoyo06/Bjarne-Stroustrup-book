#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main()
try
{
     vector<int> fib = {};

    int n = 1;
    int m = 2;
    while(n<m){
        cout << n << "\n";
        int x = n+m;
        n = m; // drop the lowest number
        m = x; // add a new high
    }

    //highest int
    cout << "The largest fibonacci int is: " << n << "\n";
   
    
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}