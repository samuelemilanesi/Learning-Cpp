#pragma once
#include <cmath>
using std::sqrt;




class complx {

friend complx operator+(const complx& x,const complx& y);
friend complx operator-(const complx& x,const complx& y);
friend complx operator*(const complx& x,const complx& y);
friend complx operator/(const complx& x,const complx& y);

private:
    float real_part;
    float img_part;
    


public:
    complx();
    complx(float real_part, float img_part);//constructor

// getter
    float real() const;
    float img() const;
    float mod() const;
    float phase() const;
    complx conj() const;

// setter 
    void set_img(float);
    void set_real(float);
    void set_phase(float);
    void set_mod(float);

};
complx operator+(const complx& ,const complx& );
complx operator-(const complx& ,const complx& );
complx operator*(const complx& ,const complx& );
complx operator/(const complx& ,const complx& );
