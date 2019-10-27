#include <iostream>
#include "Function.hpp"
#include "Bisection.hpp"
int main() {
    vector<real> c={1,-2,3,4};
    Function f(c,-3,3);
    f.print();

    cout<< f.get_fx(3)<< f.get_fx(-3)<<endl;
    Bisection b(f,0,0.0001,1000);
    
    cout<<b.get_zero();

    return 0;
}   