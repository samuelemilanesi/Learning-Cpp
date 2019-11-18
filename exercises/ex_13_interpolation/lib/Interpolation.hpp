#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>
#include <cmath>
#include "Point.hpp"

class Interpolation
{
protected:
  std::vector<Point> points; // sorted_vector
  bool check_domain(const double &x) const;
  
  /* returns the iterator to the first element in "points" greater or equal to x */ 
  std::vector<Point>::const_iterator place_x(const double& x) const;

public:
  Interpolation(const std::vector<Point> &p)
      : points(p){};

  virtual double interpolate(const double x) const = 0;
};

#endif // INTERPOLATION_HH
