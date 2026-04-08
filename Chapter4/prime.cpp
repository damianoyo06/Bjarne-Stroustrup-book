#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

vector<int> prime;

int isPrime(int n)
{
    for (int p = 0; p < prime.size(); p++)
        if (n % prime[p] == 0)
            return false;
    return true;
}

int main()
{

    cout << "Enter you value: \n";
    int max = 0;
    cin >> max;

    if (max > 2)
    {
        prime.push_back(2);
        for (int i = 3; i < max; i++)
        {
            if (isPrime(i))
            {
                prime.push_back(i);
            }
        }

        cout << "The prime numbers up to " << max << " are:";

        for (int i = 0; i < prime.size(); i++)
        {
            cout << "\n " << prime[i];
        }
      
    }   else
        {
            cout << "Ther are no prime numbers before " << max;
        }
}