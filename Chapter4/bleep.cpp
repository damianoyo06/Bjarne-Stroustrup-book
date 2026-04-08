#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

int main(){
    vector<string> disliked = {"mean", "I", "You"};
    vector<string> words;

    for(string temp; cin>>temp; ){

             words.push_back(temp);
      
    }

   for(int i=0; i<words.size(); i++){
    for(string d : disliked){
        if(words[i] == d){
            words[i] = "Bleep";
        }
    }
    cout<< words[i] << "\n";
   }

}
