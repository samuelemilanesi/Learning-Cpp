#pragma once
#include <Polynomial.hpp>

enum mtd {INCREMENT, RESIDUAL, BOTH}; 

class Root_Finder {
    protected:
    real x;
    real lb;
    real ub;
    real incr=1e3;
    const real tol;
    const mtd M;
    unsigned long num_iter=0;
    const unsigned long max_iter;
    const Polynomial& f;
    // subroutines
    bool converged() const;

public:
    Root_Finder(const Polynomial& f,  real tol, unsigned long max_iter,
     real lb, real ub, mtd M);

    Root_Finder(const Polynomial& f,  real tol, unsigned long max_iter, mtd M);

    virtual real get_zero()=0;
    
};