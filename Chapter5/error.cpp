#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

class Bad_area{};

int area(int length, int width){
    if(length<=0 || width <=0) throw Bad_area{};
    return length * width;
}

int framed_area(int x, int y){
    return area(x-2, y-2);
}
// int f(int x, int y, int z){
//     int area1 = area(x,y);
//     if(area1<=0) error("non-positive area");
//     int area2 = framed_area(1,z);
//     int area3 = framed_area(y,z);
//     double ratio = double(area1)/area3;

//     return area1;
// }
int main()
try{
    int x = -1;
    int y = 2;
    int z = 4;

    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;

    cout << "Area 1: " << area1 << "\n Area 2: " << area2 << "\n Area 3: " << "\n ratio: " << ratio;
}

catch(Bad_area){
    cout << "Oops! Bad arguments to area()\n";
}