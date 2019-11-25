#include "Cluster.hpp"

bool Cluster::recenter()
{
    bool res(false);
    double old_coord;
    if (clustered_points.size() > 0)
    {
        for (size_t k = 0; k < centroid.get_dim(); ++k)
        {
            old_coord = centroid.get_coord_k(k);
            centroid.set_coord_k(k, 0);
            for (auto it = clustered_points.begin(); it != clustered_points.end(); ++it)
            {
                centroid.set_coord_k(k, centroid.get_coord_k(k) + it->get_coord_k(k));
            }
            centroid.set_coord_k(k, centroid.get_coord_k(k) / clustered_points.size());
            if (old_coord != centroid.get_coord_k(k))
            {
                res = true;
            }
        }
    }

    return res;
}


void Cluster::print() const
{
    std::cout<< "Centroid: ";
    centroid.print();
    std::cout<<std::endl; 
    std::cout<< "Points: ";

    for(auto it=clustered_points.begin(); it!=clustered_points.end(); ++it)
    {
        std::cout<<"\n\t";
        it->print();
    }
}