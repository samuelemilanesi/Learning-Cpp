#include "complx.hpp"

complx::complx(float real_part, float img_part):
    real_part(real_part),img_part(img_part){};


//getters
float complx::real() const{
    return real_part;
}

float complx::img() const{
    return img_part;
}

float complx::mod() const{
    return sqrt( real_part*real_part + img_part*img_part );
}


complx complx::conj() const{
    complx res(real_part, -img_part);
    return res;
}

float complx::phase() const{
    float res;
    if(real_part>0){
        res=atan(img_part/real_part);
    }else{
        if(real_part!=0){
            if(img_part<0){
                res=atan(img_part/real_part)-M_PI;
            }else{
                res=atan(img_part/real_part)+M_PI;
            }
        }else{
            res= img_part<0? -M_PI: M_PI;
            if(img_part==0){
                res=0;}
            }
    }
    return res;
}


//setters

void complx::set_img(float im){
    img_part=im;
}
void complx::set_real(float re){
    real_part=re;
}

void complx::set_phase(float ph){
    float m=mod();
    img_part= sin(ph)*m;
    real_part= cos(ph)*m;
}

void complx::set_mod(float A){
    float ph=phase();
    real_part= cos( ph )*A;
    img_part= sin( ph )*A;
}


//operators 
complx operator+(const complx& x, const complx& y){
    complx res(x.real_part+y.real_part,x.img_part+y.img_part);
    return res;
}


complx operator-(const complx& x, const complx& y){
    complx res(x.real_part-y.real_part,x.img_part-y.img_part);
    return res;
}

complx operator*(const complx& x,const complx& y){
     complx res(x.real_part*y.real_part-x.img_part*y.img_part,
        x.img_part*y.real_part+x.real_part*y.img_part);
     return res;
}

complx operator/(const complx& x,const complx& y){
     complx z = x * y.conj();
     complx res(z.real_part / (y.real_part*y.real_part + y.img_part*y.img_part),
        z.img_part/(y.real_part*y.real_part + y.img_part*y.img_part)
     );
     return res;
}


