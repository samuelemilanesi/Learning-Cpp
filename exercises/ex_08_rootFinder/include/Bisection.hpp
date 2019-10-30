#pragma once
#include "Root_Finder.hpp"

class Bisection: public Root_Finder {

public:
    Bisection(const Polynomial& ,real tol, unsigned long max_iter,
     real lb, real ub,  mtd M);


// compute zero
    real get_zero() override;

};