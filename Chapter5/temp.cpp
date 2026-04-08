#include <iostream>
#include "std_lib_facilities.h"
#include <limits>
using namespace std;

int main(){
    double min_temp = numeric_limits<double>::max();
    double high_temp = numeric_limits<double>::lowest();
    double sum = 0;
    int totalTemp = 0;

    for(double temp; cin>>temp; ){
        totalTemp++;
        if(temp > high_temp) high_temp = temp;
        if(temp < min_temp) min_temp = temp;
        sum += temp;
    }

    cout << "Highest temperature is; " << high_temp << "\n";
    cout << "Lowest temperature is: " << min_temp << "\n";
    cout << "Average temperature is: " << sum/totalTemp << "\n";
}