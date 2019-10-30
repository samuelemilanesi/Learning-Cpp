#include "Root_Finder.hpp"

Root_Finder::Root_Finder(const Polynomial& f,  real tol,  unsigned long max_iter,
 real lb, real ub, mtd M):
     f(f),tol(tol),max_iter(max_iter),lb(lb), ub(ub), M(M){};


Root_Finder::Root_Finder(const Polynomial& f,  real tol, unsigned long max_iter, mtd M):
     f(f),tol(tol),max_iter(max_iter), M(M){};
    


bool Root_Finder::converged() const{
    if(max_iter<num_iter){
        return true;}

    switch (M) // M is the stopping criteria
    {
    case RESIDUAL:
        return fabs(f.eval(x))<tol;
        break;
    
    case INCREMENT:
        return fabs(incr)<tol;
        break;

    case BOTH:
        return fabs(f.eval(x))<tol && fabs(incr)<tol;
        
        break;
    }
}