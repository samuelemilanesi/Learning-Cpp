#include "Bisection.hpp"

Bisection::Bisection(const Function& f, real x0, real tol, unsigned max_iter):
     f(f),tol(tol),max_iter(max_iter), M(BOTH){

         a=f.get_a();
         b=f.get_b();
         if(f.get_fx(f.get_a())*f.get_fx(f.get_b())>0)
            cout<<"ERROR: change the domain in order to have f(a) and f(b) of opposite sign"<<endl;
        
    
     };

Bisection::Bisection(const Function& f, real x0, real tol):
     f(f),tol(tol),max_iter(0), M(TOL){
         a=f.get_a();
         b=f.get_b();
          if(f.get_fx(f.get_a())*f.get_fx(f.get_b())>0)
            cout<<"ERROR: change the domain in order to have f(a) and f(b) of opposite sign"<<endl;
        
     };

Bisection::Bisection( unsigned max_iter,const Function& f, real x0):
    f(f),tol(1e6), max_iter(max_iter), M(MAXIT){ if(f.get_fx(f.get_a())*f.get_fx(f.get_b())>0)
        a=f.get_a();
         b=f.get_b();
        cout<<"ERROR: change the domain in order to have f(a) and f(b) of opposite sign"<<endl;
    };

bool Bisection::converged(real tol, unsigned max_iter, mtd& M) const{

    switch (M) // M is the stopping criteria
    {
    case TOL:
        return abs(f.get_fx(x))<tol;
        break;
    
    case MAXIT:
        return num_iter>max_iter;
        break;

    case BOTH:
        return abs(f.get_fx(x))<tol && num_iter>max_iter;
        break;
    }

}


real Bisection::get_zero(){
    
    while(!converged(tol,max_iter,M)){

        if(f.get_fx(a)*f.get_fx(x)>0)
            a=x;
            
        else
            b=x;
        x=(a+b)/2;
        num_iter++;
        
    }

return x;
}