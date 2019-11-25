#include "Clustered_set.hpp"

Clustered_set::Clustered_set(vector<Cluster> &clusts, vector<Point_Rn> pts)
    : clusters(clusts), points(pts)
{
    for (size_t k = 0; k < points.size(); ++k)
    {
        assigned_cluster.push_back(0);
        clusters[0].clustered_points.insert(clusters[0].clustered_points.begin(), points[k]);
    }
};

void Clustered_set::clusterize()
{
    bool converged(false);
    while (!converged)
    {
        for (size_t j = 0; j < points.size(); ++j)
        {
            for (size_t k = 0; k < clusters.size(); ++k)
            {
                Point_Rn PROVA= points[j];
                if (points[j].compute_distance(clusters[k].get_centroid()) <= points[j].compute_distance(clusters[assigned_cluster[j]].get_centroid()))
                {
                    // removes from old cluster
                    clusters[assigned_cluster[j]].clustered_points.remove(points[j]);
                    // sets new cluster
                    assigned_cluster[j] = k;
                    // inserts in new the cluster
                    clusters[k].clustered_points.insert(clusters[k].clustered_points.begin(), points[j]);
                }
            }
        }
        for (auto it = clusters.begin(); it != clusters.end(); ++it)
        {
            converged=true;
            converged *= !(it->recenter());

            // at the end of the cycle converged is TRUE iff no centroid has changed position
        }
    }
}



void Clustered_set::print() const
{
    for(int k=0; k<clusters.size(); ++k){
        std::cout<<"\n\nCLUSTER "<< k<<std::endl;
        clusters[k].print();

    }

}