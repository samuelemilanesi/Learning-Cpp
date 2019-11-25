#include "Point_Rn.hpp"

// getters
double Point_Rn::get_coord_k(size_t k) const
{
    return coordinates[k];
};

size_t Point_Rn::get_dim() const
{
    return dimensions;
};

// setters
void Point_Rn::set_coord_k(size_t k, double val)
{
    coordinates[k] = val;
};

// utility

double Point_Rn::compute_distance(const Point_Rn &p) const
{
    if (dimensions != p.get_dim())
    {
        std::cerr << "Error: points dimensions must agree" << std::endl;
        return -1;
    }
    double res = 0;

    for (size_t i = 0; i < dimensions; ++i)
    {
        res += (coordinates[i] - p.coordinates[i]) * (coordinates[i] - p.coordinates[i]);
    }

    return sqrt(res);
}

bool Point_Rn::operator==(const Point_Rn &rhs)
{   
  
    for(size_t k=0; k<dimensions;++k)
    {
        if(coordinates[k]!=rhs.get_coord_k(k))
            return false;
    }
    return true;
}


void Point_Rn::print() const
{
    std::cout<<"(";
    for(auto it=coordinates.begin(); it!=coordinates.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout<<"\b\b)";
}
