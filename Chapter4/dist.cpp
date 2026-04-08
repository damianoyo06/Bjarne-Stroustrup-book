#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    vector<double> distance;
    
    double dist;
    cout << "Enter distances between cities \n";
    while(cin>>dist){
        distance.push_back(dist);
    }

    sort(distance);

    double sum = 0;
    
    for(int i=0; i<distance.size(); i++){
        sum += distance[i];
      
        cout << distance[i] << "\n";
    }

      cout << " The sum of the distances is " << sum 
        << ".\n The greatest distance is " << distance[distance.size()-1]
        << ".\n The smallest distnace is " << distance[0]
        << ".\n The mean distance is " << distance[distance.size()/2];
      

}