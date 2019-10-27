#pragma once
#include <Function.hpp>

class Bisection {
private:
    real x;
    real a;
    real b;
    real tol;
    unsigned long num_iter=0;
    unsigned long max_iter;
    enum mtd {TOL, MAXIT, BOTH} M; 
    const Function& f;
// subroutines
    bool converged(real tol, unsigned max_iter, mtd& M) const;

public:
    Bisection(const Function& , real x0, real tol, unsigned max_iter);
    Bisection(const Function&, real x0, real tol);
    Bisection(unsigned max_iter, const Function&, real x0);

// getter 
    real get_zero();




    
};