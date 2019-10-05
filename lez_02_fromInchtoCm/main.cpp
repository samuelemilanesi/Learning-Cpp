#include <iostream>
using namespace std;
const float inch_cm_ratio=2.54;
int main() {
    float xInch; //measure in inch
    cout <<"Insert a length in inch: "<< endl;
    cin >> xInch;

    cout<<"The length converted in cm is equal to: " << inch_cm_ratio*xInch<<endl;

    return 0;
}