#pragma once
#include "Point_Rn.hpp"
#include "Cluster.hpp"
#include<set>
using std::set;

class Clustered_set {
private: 
    vector<Point_Rn> points;
    vector<unsigned> assigned_cluster; 
    vector<Cluster> clusters;
    size_t n_clusts;
public:
    Clustered_set(vector<Cluster>& clusts, vector<Point_Rn> pts);

    
    void clusterize();

    void print() const;




};