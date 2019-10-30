#include "Newton.hpp"

Newton::Newton(const Polynomial& f,real tol, unsigned long max_iter,real x0, mtd M):
        Root_Finder(f,tol,max_iter,M){
            x=x0;
        }


real Newton::get_zero(){
    
    Polynomial df=f.diff();
    while(!converged()){
        if(!df.eval(x)){
            cout<<"Error dividing by 0: stationary point"<<endl;
            return 0;
        }
        x_new=x - f.eval(x)/df.eval(x);
        incr=f.eval(x_new)-f.eval(x);
        x=x_new;
        num_iter++;
    }

    cout<<"Newton number of iterations= "<< num_iter<<endl;
    return x;
}
