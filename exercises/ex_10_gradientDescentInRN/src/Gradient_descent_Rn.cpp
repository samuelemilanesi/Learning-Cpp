#include "Gradient_descent_Rn.hpp"
 
Rn_point Gradient_descent_Rn::compute_gradient(const Rn_point &p) const{
    vector<real> res_cood; 
    for(size_t k=0;k<p.get_dimension(); ++k)
    {
        res_cood.push_back(f.diff_eval(k,p));
    }
    return Rn_point(res_cood);
}

Rn_point     Gradient_descent_Rn::solve(const Rn_point& x_start) const
{   
    Rn_point x_old(x_start);
    Rn_point x_new;

    while(!converged(x_old)) // bisogna ancora implementare converged()
    {   
        x_new= x_old - step*compute_gradient(x_old);
    }

}