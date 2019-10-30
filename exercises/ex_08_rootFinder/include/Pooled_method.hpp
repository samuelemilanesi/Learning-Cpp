#pragma once
#include "Root_Finder.hpp"
#include "Bisection.hpp"
#include "Newton.hpp"

class Pooled_method: public Root_Finder
{
private:
    real tol_bis;

public:
    Pooled_method(const Polynomial& ,real tol, real cfratio,
    unsigned long max_iter, real lb, real ub,  mtd M);

    real get_zero() override;
};