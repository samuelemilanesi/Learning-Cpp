#include <iostream>
#include "Polynomial.hpp"
#include "Bisection.hpp"
#include "Newton.hpp"
#include "Pooled_method.hpp"
int main() {
    vector<real> c={-0.5,0,1,5,-3,2};
    const Polynomial f(c);
    f.print();
    f.diff().print();
    
    Bisection b(f,1e-08,1e6,0.,1.,BOTH);
    Newton n(f,1e-08,50,2,BOTH);

    real zero_b=b.get_zero();
    real zero_n=n.get_zero();
    cout<<"---Perform the pooled computation---"<<endl;
    Pooled_method p(f,1e-08,1e03,1e5,0.0,1.0,BOTH);
    real zero_pooled=p.get_zero();

    cout<< "\nroot bisection: " <<  zero_b << " f(zero) =" <<f.eval(zero_b);
    cout<< "\nroot Newton: " <<  zero_n << " f(zero) =" <<f.eval(zero_n);
    cout<< "\nroot Pooled: " <<  zero_pooled << " f(zero) =" <<f.eval(zero_pooled);

    return 0;
}   