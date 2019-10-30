#pragma once
#include "Root_Finder.hpp"
class Newton: public Root_Finder {
private:
    real x_new;


public:
    Newton(const Polynomial& ,real tol, unsigned long max_iter, real x0, mtd M);
    
//compute zero
    real get_zero() override;
};