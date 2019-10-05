#include <iostream>
using namespace std;

int main() {
    int x;
    cout<< "Insert integer value for x: "<<endl;
    cin >> x;

    char c = x;
    int y = c;

    if(x==y){
        cout<<"x=y"<<endl;

    } else{
        cout<<"x ="<< x << " != "<< y << "=y"<<endl;
    }

    /* the "if" is satisfied only for x in the range -128:127 because this
     * the size of the memory allocated for a CHAR variable!!!*/

    return 0;
}