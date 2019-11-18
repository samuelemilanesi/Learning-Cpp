#include "NearestNeighborInterpolation.hpp"

double NearestNeighborInterpolation::interpolate (double x) const
{
    if(check_domain(x))
    {
        std::vector<Point>::const_iterator it=place_x(x);

        return it->get_x()-x <= x-(it-1)->get_x()? it->get_y(): (it-1)->get_y() ;
    }
    return std::nan("");
}
