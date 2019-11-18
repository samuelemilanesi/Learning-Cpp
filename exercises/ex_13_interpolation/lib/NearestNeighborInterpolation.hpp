#ifndef NEAREST_NEIGHBOR_INTERPOLATION_HH
#define NEAREST_NEIGHBOR_INTERPOLATION_HH

#include <vector>
#include "Interpolation.hpp"

class NearestNeighborInterpolation: public Interpolation
{
public:
  explicit NearestNeighborInterpolation (const std::vector<Point> &p)
    :Interpolation(p){};

  double interpolate(double x) const override;
};

#endif // NEAREST_NEIGHBOR_INTERPOLATION_HH
