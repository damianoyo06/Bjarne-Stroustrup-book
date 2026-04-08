#include "std_lib_facilities.h"
#include <iostream>
using namespace std;

int permutation(int a, int b)
{
    // P(a,b) = a! / (a-b)!
    int sum = 0;

    // factorial for a
    int factorial = 1;
    for (int i = 1; i <= a; i++)
    {
        factorial *= i;
    }

    int bottom = a - b;
    // factorial for a-b;
    if (bottom == 0)
    {
        bottom = 1;
    }
    else
    {
        for (int i = bottom - 1; i > 0; i--)
        {
            bottom *= i;
        }
    }

    // sum of permutation
    sum = factorial / bottom;

    return sum;
}

int combination(int a, int b)
{
    int sum = permutation(a, b);

    // factorial for b
    if (b == 0)
    {
        b = 1;
    }
    else
    {
        int factorial = b;
        for (int i = b - 1; i > 0; i--)
        {
            factorial *= i;
        }
         sum = sum / factorial;
    }

    return sum;
}

int main()
try
{
    int a, b;
    cout << "Welcome to the calculator of permutation or combination. \n"
         << "Please enter two values for int a and int b, where a >= b and where b != 0. \n"
         << "int a = ";

    cin >> a;

    cout << "int b = ";

    cin >> b;

    if (b > a)
        error("b>a, calculation impossible");
    if (a < 0 || b < 0)
        error("integers have to be positive");
    cout << "Please choose if you want to calculate permutation (p), combination (c) or both (b) \n";
    char select;
    cin >> select;

    switch (select)
    {
    case 'p':
    {
        cout << "Permutation of (" << a << "," << b << ") = ";
        cout << permutation(a, b) << "\n";
        break;
    }
    case 'c':
    {
        cout << "Combination of (" << a << "," << b << ") = ";
        cout << combination(a, b);
        break;
    }
    case 'b':
    {
        cout << "Permutation of (" << a << "," << b << ") = ";
        cout << permutation(a, b) << "\n";
        cout << "Combination of (" << a << "," << b << ") = ";
        cout << combination(a, b);
    }
    default:
        break;
    }

    // cout << "permutation: \n";
    // cout << permutation(a, b) << "\n";
    // cout << "combination: \n";
    // cout << combination(a, b);

    return 0;
}
catch (exception &e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch (...)
{
    return 2;
}
