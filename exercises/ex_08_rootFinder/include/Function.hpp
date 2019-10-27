#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <vector>
using std::vector; using std::cout;
using std::endl;
typedef double real;
class Function {
private:
    const real a; //left bound of the domain interval
    const real b; //right bound of the domain interval
    const vector<real> coeff;

public:
    Function(vector<real>& coeff, real a ,  real b);

// getters
    real get_a() const;
    real get_b() const;
    real get_fx(real x) const;
    const vector<real>& get_coeff() const;

// other methods
    Function diff() const;
    void print() const;
    
};