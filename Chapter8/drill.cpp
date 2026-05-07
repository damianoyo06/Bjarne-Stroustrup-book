#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

namespace X
{
    int var;
    void print()
    {
        cout << "X value: " << var << '\n';
    }
}

namespace Y
{
    int var;
    void print()
    {
        cout << "Y value: " << var << '\n';
    }
}

namespace Z
{
    int var;
    void print()
    {
        cout << "Z value: " << var << '\n';
    }
}

int main()
{
    X::var = 7;
    X::print(); // print X var
    using namespace Y;
    var = 9;
    print(); // print Y var

    {
        using Z::print;
        using Z::var;
        var = 11;
        print(); // print Z var;
    }
    print();    // Print Y var
    X::print(); // print X
}