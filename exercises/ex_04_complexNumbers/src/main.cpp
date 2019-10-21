#include <iostream>
#include "complx.hpp"
using std::cout; using std::endl;

int main() {

    complx x(0,0);
    complx y(5,-5);

    complx z=x;
    z.set_mod(1);
    z.set_phase(M_PI/6);
    cout<< "z= "<< z.real()<<"+ i*( "<<z.img()<<")"<<endl; ;
    cout<<"phase = "<< z.phase()<<endl;
    cout<<"mod =" << z.mod()<<endl;
   
}