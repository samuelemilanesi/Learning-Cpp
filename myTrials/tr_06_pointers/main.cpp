#include <iostream>
using namespace std;

int main(){
    int a[2][4]={3,9,12,15,18,21,24};
    char* arr[]={"C","C++","Java","VBA"};
    char* (*ptr)[4]=&arr;
    
    cout<<++(*ptr)[3]<<endl;
    cout<<*(a[1]+3)<<*(*(a+1)+3)<<++(*ptr)[3]<<endl;

    return 0;
}
