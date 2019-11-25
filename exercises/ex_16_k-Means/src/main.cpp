#include <iostream>
#include "Point_Rn.hpp"
#include "Clustered_set.hpp"
#include "Cluster.hpp"
int main()
{
    /* points to be clusterized*/ 
    vector<double> p0_coor({0,0,0,0,0,0});
    Point_Rn p0(p0_coor);

    vector<double> p1_coor({1,2,3,4,5,6});
    Point_Rn p1(p1_coor);

    vector<double> p2_coor({1,13,24,2,5,6});
    Point_Rn p2(p2_coor);

    vector<double> p3_coor({0,2,3,4,3,2});
    Point_Rn p3(p3_coor);

    vector<double> p4_coor({0, 0, 0, 0, 3,2});
    Point_Rn p4(p4_coor);

    vector<double> p5_coor({0,1,2,4,3,2});
    Point_Rn p5(p5_coor);

    vector<double> p6_coor({0,22,3,4,31,2});
    Point_Rn p6(p6_coor);



  
   
    // vector of points to be clusterized
    vector<Point_Rn> points({p0,p1,p2,p3,p4,p5,p6});


    /* clusters */
    vector<double> c1_coor({1,1,1,1,1,1});
    Point_Rn c1(c1_coor);
    Cluster cluster1(c1);

    vector<double> c2_coor({2,2,2,2,2,2});
    Point_Rn c2(c2_coor);
    Cluster cluster2(c2);

    vector<double> c3_coor({3,3,3,3,3,3});
    Point_Rn c3(c3_coor);
    Cluster cluster3(c3);

    // vector of clusters
    vector<Cluster> clusters({cluster1,cluster2,cluster3});


    /* set of clusters */

    Clustered_set cluset(clusters,points);

    cluset.clusterize();
    

    cluset.print();
 


    return 0;

}