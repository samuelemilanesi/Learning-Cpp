#include "Polynomial_Rn.hpp"

void Polynomial_Rn::add_monomial(const Monomial &m)
{
    monoms.push_back(m);
};

real Polynomial_Rn::eval(const Rn_point &p) const
{
    real res = 0;
    for (size_t k = 0; k < monoms.size(); ++k)
    {
        res += monoms[k].eval(p);
    }
    return res;
}

real Polynomial_Rn::diff_eval(size_t k, Rn_point &p) const
{
    real res = 0;
    for (size_t k = 0; k < monoms.size(); ++k)
    {
        res += monoms[k].diff_eval(k,p);
    }
    return res;
}

