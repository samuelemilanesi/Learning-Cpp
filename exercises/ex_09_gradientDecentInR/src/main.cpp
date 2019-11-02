#include <iostream>
#include "Polynomial.hpp"
#include "Gradient_descent_R.hpp"

int main() {
    const vector<real> coeff={-1,2,3};
    const Polynomial f(coeff);
    Gradient_descent_R gdr(f,3,-3,0.0001,BOTH,1e-8,1e5);
    real x_min= gdr.get_min(2);
    cout << "Minimum at x= "<< x_min <<"; minimum value= "<< f.eval(x_min)<<endl;
    return 0;
}