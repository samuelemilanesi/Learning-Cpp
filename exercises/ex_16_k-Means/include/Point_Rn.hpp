#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

class Point_Rn {
protected: 
    double dimensions;
    vector<double> coordinates;

public:
    Point_Rn(vector<double>& coord)
        : coordinates(coord){dimensions=coordinates.size();};
// getters
    double get_coord_k(size_t k) const;
    size_t get_dim() const;

// setters 
    void set_coord_k(size_t k, double val);
// utility
    double compute_distance(const Point_Rn&) const; 
    void print() const;
 
bool operator==(const Point_Rn& rhs) const;
bool operator<(const Point_Rn& rhs) const;

};