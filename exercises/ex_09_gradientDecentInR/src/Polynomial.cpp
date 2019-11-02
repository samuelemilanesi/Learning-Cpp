#include "Polynomial.hpp"

Polynomial::Polynomial(const vector<real>& coeff):
    coeff(coeff){};


// getters

const vector<real>& Polynomial::get_coeff() const{
    return coeff;
}

// other methods
Polynomial Polynomial::diff() const{
    vector<real> derivative_coeff;
    int N=coeff.size();
    if(N<=1){
        derivative_coeff.push_back(0.0);
        Polynomial res(derivative_coeff);
        return res;
        }
    for(unsigned k=0; k<coeff.size()-1; ++k){
        derivative_coeff.push_back(coeff[k+1]*(k+1));
    }
    Polynomial ris(derivative_coeff);
    return ris;   
}

void Polynomial::print() const{

    cout<< "\n\n--------------------------------------"<<endl;
    for(unsigned k=0;k<coeff.size();++k){
        cout<<"+("<<coeff[k]<<")"<<"x^"<<k<<" ";
            }
    cout<<endl;
   cout<< "\n--------------------------------------"<<endl;

}

real Polynomial::eval(const real x) const{
    real res=0;
    for(unsigned k=0; k<coeff.size(); ++k){
        res+= pow(x,k)*coeff[k];
    }
    return res;
}
