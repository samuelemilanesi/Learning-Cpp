#include "Rn_point.hpp"

real Rn_point::distance(Rn_point &x) const
{
    real res = 0;
    if (x.coord.size() != get_dimension())
        cerr << "Point dimensions must agree" << endl;

    for (size_t k = 0; k < x.coord.size(); ++k)
    {
        res += (x.coord[k] - coord[k]) * (x.coord[k] - coord[k]);
    }
    return sqrt(res);
}

real Rn_point::norm_2() const
{
    coordinates orig_coords(coord.size(), 0.);

    Rn_point origin(orig_coords);

    return distance(origin);
}

real Rn_point::norm_inf() const
{
    real res = fabs(coord[0]);

    for (size_t k = 1; k < coord.size(); ++k)
    {
        if (res < fabs(coord[k]))
            res = fabs(coord[k]);
    }

    return res;
}

// getters
real Rn_point::get_coord_k(size_t k) const
{
    return coord[k];
}

size_t Rn_point::get_dimension() const
{
    return coord.size();
}

// setters
void Rn_point::set_coord_k(size_t k, real val)
{
    coord[k] = val;
}

// printer
void Rn_point::print() const
{
    cout << "Point = [";
    for (auto el : coord)
    {
        cout << el << "; ";
    }
    cout << "\b\b]" << endl;
}

Rn_point operator*(real c, const Rn_point &p)
{

    coordinates res_c(p.coord);
    for (size_t k = 0; k < p.coord.size(); ++k)
    {
        res_c[k] *= c;
    };
    return res_c;
}
Rn_point Rn_point::operator-(const Rn_point &q)
{

    coordinates coord_q(q.coord);
    for (size_t k = 0; k < q.coord.size(); ++k)
    {
        coord_q[k]= this->coord[k]- coord_q[k];
    };
    return coord_q;
}