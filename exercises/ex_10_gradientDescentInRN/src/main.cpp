#include <iostream>
#include "Rn_point.hpp"
int main() {
    coordinates y_co={0,0,0,0,0};
    coordinates z_co={1,2,2,2,3};
    Rn_point y(y_co);
    Rn_point z(z_co);

    cout<<"norm2= " << z.norm_2() << " norm_inf= "<< z.norm_inf() << " distance(y,z)= "<< z.distance(y)<<endl;


}