#pragma once
#include "Rn_point.hpp"
class Monomial {
private:
    real coeff;
    vector<real> powers;
    

public:
    Monomial(real c, vector<real>& pows);
    real eval(const Rn_point& p) const;
    real diff_eval(size_t j, const Rn_point& p) const;

};