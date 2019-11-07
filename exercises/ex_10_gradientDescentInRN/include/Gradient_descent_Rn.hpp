#pragma once
#include "Polynomial_Rn.hpp";

class Gradient_descent_Rn
{
private:
    Polynomial_Rn f;
    real tol;
    real step;
    size_t max_iter;
    vector<real> sup_bnd;
    vector<real> inf_bnd;
    Rn_point compute_gradient(const Rn_point &p) const;
    bool converged(const Rn_point& x) const;


public:
    Gradient_descent_Rn(const Polynomial_Rn &fun, real t, real s, size_t maxit,
                        const vector<real> &sbnd, const vector<real> ibnd)
    : f(fun),tol(t),step(s),max_iter(maxit),sup_bnd(sbnd),inf_bnd(ibnd){};

    Rn_point solve(const Rn_point& x0) const;
};