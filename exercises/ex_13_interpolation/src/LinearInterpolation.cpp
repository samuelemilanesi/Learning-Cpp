#include "LinearInterpolation.hpp"

double LinearInterpolation::interpolate (const double x) const
{
    if(check_domain(x))
    {

        std::vector<Point>::const_iterator it=place_x(x);
        double x_0( (it-1)->get_x());
        double y_0( (it-1)->get_y());
        double x_1( it->get_x());
        double y_1( it->get_y());

        return (y_1-y_0)/(x_1-x_0) * (x - x_0) + y_0 ;
    }
    return std::nan("");
}
