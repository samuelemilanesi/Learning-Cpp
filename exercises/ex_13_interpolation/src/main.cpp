#include <iostream>
#include <memory>

#include "Point.hpp"
#include "Interpolation.hpp"
#include "LinearInterpolation.hpp"
#include "StepwiseInterpolation.hpp"
#include "NearestNeighborInterpolation.hpp"

int
main (void)
{
  std::vector<Point> points {
    Point (1.0, 0.0),
      Point (2.0, 3.0),
      Point (3.0, 1.0),
      Point (4.0, 2.0),
      Point (5.0, 4.0)
      };

  double x = 5;
  
  LinearInterpolation lin_int(points);
  StepwiseInterpolation step_int(points);
  NearestNeighborInterpolation near_int(points);

  double lin_res= lin_int.interpolate(x);
  double step_res= step_int.interpolate(x);
  double near_res=near_int.interpolate(x);

  std::cout<< "Linear interp y= " << lin_res << std::endl;
  std::cout<< "Stepwise interp y= " << step_res << std::endl;
  std::cout<< "Nearest neighbor interp y= " << near_res << std::endl;


  return 0;
}
