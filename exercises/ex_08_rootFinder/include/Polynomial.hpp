#pragma once
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
using std::vector; using std::cout;
using std::endl;
typedef double real;


class Polynomial {
    
private:
    const vector<real> coeff;

public:
  
    Polynomial(vector<real>& coeff);

// getters
    real eval(real x) const;
    const vector<real>& get_coeff() const;

// other methods
    Polynomial diff() const;
    void print() const;
    
};