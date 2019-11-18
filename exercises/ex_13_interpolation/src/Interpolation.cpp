#include "Interpolation.hpp"

bool Interpolation::check_domain(const double &x) const
{
    bool flag=points[0].get_x() <= x & (points.end()-1)->get_x() >= x;
    return points[0].get_x() <= x & (points.end()-1)->get_x() >= x;
}


/* sort of binary search implementation in order to place x*/ 
std::vector<Point>::const_iterator Interpolation::place_x(const double &x) const
{
    std::vector<Point>::const_iterator beg_it(points.begin());
    std::vector<Point>::const_iterator end_it(points.end());
    std::vector<Point>::const_iterator mid_it(beg_it + (end_it - beg_it) / 2);

    while (beg_it != mid_it && mid_it != end_it)
    {
        if (x <= mid_it->get_x())
        {
            if (x == mid_it->get_x())
                return mid_it;
            if (x >= (mid_it - 1)->get_x())
                return (mid_it - 1)->get_x() == x ? mid_it - 1 : mid_it;
            end_it=mid_it;
        }
        else
        {
            if (x <= (mid_it + 1)->get_x())
                return mid_it + 1;
            beg_it=mid_it;
        }
        mid_it= beg_it+ (end_it-beg_it)/2;
    }
}