#pragma once
#include "Monomial.hpp"


class Polynomial_Rn
{
private:
    vector<Monomial> monoms;

public:
    void add_monomial(const Monomial& m);
    real eval(const Rn_point& p) const;
    real diff_eval(size_t k, const Rn_point& p) const;
};