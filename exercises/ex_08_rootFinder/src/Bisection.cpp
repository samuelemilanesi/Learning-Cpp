#include "Bisection.hpp"

Bisection::Bisection(const Polynomial& f,  real tol, unsigned long max_iter,
real lb, real ub, mtd M):
     Root_Finder(f,tol,max_iter,lb,ub,M){
         if( f.eval(lb)*f.eval(ub) > 0 )
            cout<<"ERROR: change the domain in order to have f(a) and f(b) of opposite sign"<<endl;
     };

real Bisection::get_zero(){
    x= (lb+ub)/2;
  
    while(!converged()){

        if(f.eval(lb)*f.eval(x)>0){
            lb=x;
            }
        else{
            ub=x;
            }

        incr = f.eval(x)-f.eval( (lb+ub)/2 ) ; //incr = old x - new x 
        x= (lb+ub)/2; // new x 
        num_iter++; 
        
    }
    cout<<"Bisection number of iterations= "<< num_iter<<endl;
return x;
}