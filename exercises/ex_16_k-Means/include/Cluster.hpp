#pragma once
#include "Point_Rn.hpp"
#include <set>
using std::set;
class Cluster
{
private:
    Point_Rn centroid;

public:
    Cluster(Point_Rn &p)
        : centroid(p){};

    set<Point_Rn> clustered_points={};
    // getters
    Point_Rn &get_centroid() { return centroid; };

    //utility
    bool recenter(); // TRUE if the centroid changed position
    void print() const; 
};