#include "Function.hpp"

Function::Function(vector<real>& coeff, real a,real b):
    coeff(coeff), a(a),b(b){};


// getters
real Function::get_a() const{
    return a;
}
real Function::get_b() const{
    return b;
}
const vector<real>& Function::get_coeff() const{
    return coeff;
}

// other methods
Function Function::diff() const{
    vector<real> derivative_coeff;
    int N=coeff.size();

    if(N<1)
        derivative_coeff.push_back(0.0);
        Function res(derivative_coeff,a,b);
        return res;
        
    for(unsigned k=0; k<coeff.size()-1; ++k){
        derivative_coeff.push_back(coeff[k+1]*(k+1));
    }

    Function ris(derivative_coeff,a,b);
    return ris;   
}

void Function::print() const{

    cout<< "\n\n--------------------------------------"<<endl;
    cout<<"f:["<<a<<", "<<b <<"]--> R,\tf(x)= ";

    for(unsigned k=0;k<coeff.size();++k){
        cout<<"+("<<coeff[k]<<")"<<"x^"<<k<<" ";
            }
    cout<<endl;
   cout<< "\n--------------------------------------"<<endl;

}

real Function::get_fx(real x) const{
    real res=0;
    for(unsigned k=0; k<coeff.size(); ++k){
        res+= pow(x,k)*coeff[k];
    }
    return res;
}
