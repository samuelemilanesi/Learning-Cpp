#pragma once
#include "Polynomial.hpp"
#include <random>
typedef double real;
enum stop_criteria
{
    RESIDUAL,
    INCREMENT,
    BOTH
};

class Gradient_descent_R
{
private:
    const real step; //learning rate
    const real tol;
    const stop_criteria ST;
    const Polynomial &f; // function to minimize
    const real ub;       // domain upper bound
    const real lb;       // domain lower bound
    const unsigned int long max_iter;
    bool converged(const unsigned num_iter,const real residual, const real incr, const stop_criteria ST) const;
public:
    Gradient_descent_R(const Polynomial &f, const real ub, const real lb, const real step,
                       const stop_criteria ST, const real tol, const unsigned int long max_iter)
        : f(f), ub(ub), lb(lb), step(step), ST(ST), tol(tol), max_iter(max_iter){};

    real get_min(real x_old) const;
    real get_min_multistart(int num_starting_points) const;
    real get_min_dom_decomposition(int num_intervals) const;

};