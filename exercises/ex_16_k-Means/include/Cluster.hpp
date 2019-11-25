#pragma once
#include "Point_Rn.hpp"
#include <list>
using std::list;
class Cluster
{
private:
    Point_Rn centroid;

public:
    Cluster(Point_Rn &p)
        : centroid(p){};

    list<Point_Rn> clustered_points;
    // getters
    Point_Rn &get_centroid() { return centroid; };

    //utility
    bool recenter(); // TRUE if the centroid changed position
    void print() const; 
};