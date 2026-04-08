#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

vector<int> mon;
vector<int> tue;
vector<int> wed;
vector<int> thu;
vector<int> fri;
vector<int> sat;
vector<int> sun;
int rejected = 0;

int days_of_week(string d, int v){
    int cont = 0;
    if(d == "Monday" || d =="monday" || d == "Mon" || d == "mon"){
        mon.push_back(v);
    } else if(d == "Tuesday" || d =="tuesday" || d == "tue" || d == "Tue"){
        tue.push_back(v);
    } else if(d == "Wednesday" || d =="wednesday" || d == "wed" || d == "Wed"){
        wed.push_back(v);
    } else if(d == "Thursday" || d =="thursday" || d == "thu" || d == "Thu"){
        thu.push_back(v);
    } else if(d == "Firday" || d =="friday" || d == "Fri" || d == "fri"){
        fri.push_back(v);
    } else if(d == "Saturday" || d =="saturday" || d == "Sat" || d == "sat"){
        sat.push_back(v);
    } else if(d == "Sunday" || d =="sunday" || d == "Sun" || d == "sun"){
        sun.push_back(v);
    } else if (d == "q" && v == 0){
        cont = -1;
    } else {
        rejected++;
    }
    return cont;
}

int get_sum(vector<int> v){
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }
    return sum;
}

void print_day(string d, vector<int> v){
    cout << d << "(sum: " << get_sum(v) << ")" << "\n";
    cout << "Values:";
    for(int i=0; i<v.size(); i++){
        cout << " "<< v[i];
    } 
    cout << endl;
}

void print_results(){
   print_day("Monday", mon);
   print_day("Tuesday", tue);
   print_day("Wednesday", wed);
   print_day("Thursday", thu);
   print_day("Friday", fri);
   print_day("Saturday", sat);
   print_day("Sunday", sun);
   cout << rejected << " rejected values \n";
}



int main()
try{
    string day = " ";
    int value = 0;

    cout << "Enter a day of a week followed by a value: \n";
    while( cin >> day >> value){

        int cont = days_of_week(day, value);
        if(cont == -1){
            print_results();
            return 0;
        }
    }

}
catch (runtime_error& e){
    cout << e.what() << "\n";
}