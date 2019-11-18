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

  double x = 2.2;
  
  LinearInterpolation lin_int(points);
  double res= lin_int.interpolate(x);
  std::cout<< "Interpolation value y= " << res << std::endl;

  return 0;
}
