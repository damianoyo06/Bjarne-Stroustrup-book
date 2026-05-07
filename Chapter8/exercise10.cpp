#include <iostream>
#include <algorithm>
#include "../std_lib_facilities.h"
using namespace std;


void maxNumber(vector<int>& v){
    sort(v.begin(), v.end());
    int n = v.size();

    cout << "The largest number is: " << v[n-1] << '\n';
    cout << "The smallest number is: " <<v[0] << '\n';

    double median = 0;
    double mean = 0;

    for(int i=0; i<n; i++){
        mean += v[i];
    }
    mean /= n;

    if(n % 2 == 1){
        median = v[n/2];
    } else {
        median = (v[n/2 -1] + v[n/2]) / 2.0;
    }
   

     cout << "The mean is: " << mean << '\n';
     cout << "The median is: " << median << '\n';
}


int main()
{
    vector<int> nums;
    int x;

    cout << "Enter values, write 99 when finished: " << '\n';
    while(cin>>x){
        nums.push_back(x);
    }

    maxNumber(nums);
}