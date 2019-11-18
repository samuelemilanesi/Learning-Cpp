#include "StepwiseInterpolation.hpp"

double StepwiseInterpolation::interpolate (double x) const
{
    if(check_domain(x))
    {
        std::vector<Point>::const_iterator it=place_x(x);
        return (it-1)->get_y() ;
    }
    return std::nan("");
}
