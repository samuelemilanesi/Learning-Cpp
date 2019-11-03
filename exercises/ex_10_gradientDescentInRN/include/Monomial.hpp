#pragma once
#include "Rn_point.hpp"
class Monomial {
private:
    real coeff;
    vector<real> powers;
    

public:
    Monomial();
    ~Monomial();
};