#include "Pooled_method.hpp"

Pooled_method::Pooled_method(const Polynomial& f,  real tol, real cfratio,
unsigned long max_iter,real lb, real ub, mtd M):
     Root_Finder(f,tol,max_iter,lb,ub,M), tol_bis(tol*cfratio){
         if( f.eval(lb)*f.eval(ub) > 0 )
            cout<<"ERROR: change the domain in order to have f(a) and f(b) of opposite sign"<<endl;
     };

real Pooled_method::get_zero(){
    Bisection bisect_calc(f,tol_bis,max_iter,lb,ub,RESIDUAL);
    x=bisect_calc.get_zero();

    Newton newton_calc(f,tol,max_iter,x,M);

    return newton_calc.get_zero();

}