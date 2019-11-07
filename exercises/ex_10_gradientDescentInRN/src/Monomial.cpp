#include "Monomial.hpp"

Monomial::Monomial(real c, vector<real> &pows)
    : coeff(c), powers(pows){};

real Monomial::eval(const Rn_point &p) const
{
    real res = 1.0;
    //check
    if (p.get_dimension() != powers.size())
    {
        cerr << "The monomial cannot be evaluated in that point: dimensions must agree" << endl;
        return 1.0;
    }
    for (size_t k = 0; k < powers.size(); ++k)
    {
        res *= pow(p.get_coord_k(k), powers[k]);
    }

    return res * coeff;
}

real Monomial::diff_eval(size_t j, const Rn_point &p) const
{
    real res=1.0;
    if (p.get_dimension() != powers.size())
    {
        cerr << "The monomial derivative cannot be evaluated in that point: dimensions must agree" << endl;
        return 1.0;
    }
    for (size_t k = 0; k < powers.size(); ++k)
    {
        if(k!=j){
            res*=pow(p.get_coord_k(k) ,powers[k]);
        }else{
            powers[k]>0 ? pow(p.get_coord_k(j) ,powers[j]-1) : res=0;
        } 
    }
    return res*coeff*(powers[j]-1);

}
