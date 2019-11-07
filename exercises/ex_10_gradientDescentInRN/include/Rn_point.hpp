#pragma once
#include <vector>
#include <iostream>
#include <cmath>
using std::size_t;
using std::vector;
using std::cerr; using std::endl; using std::cout;
typedef double real;
typedef vector<real> coordinates;
class Rn_point
{
private:
    coordinates coord;
public:
    friend Rn_point operator*(real,const Rn_point&);
    Rn_point operator-(const Rn_point&);
    Rn_point(coordinates& coord)
            : coord(coord){};
    Rn_point()
            : coord({}){};

    real norm_2() const;
    real norm_inf() const;
    real distance(Rn_point &x) const;
    void print() const;

    // getters
    real get_coord_k(size_t k) const; //return the k-th coordinate of the point
    size_t get_dimension() const;

    // setters
    void set_coord_k(size_t k, real val);
};
Rn_point operator*(real,const Rn_point&);