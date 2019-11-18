#ifndef LINEAR_INTERPOLATION_HH
#define LINEAR_INTERPOLATION_HH

#include <vector>
#include "Interpolation.hpp"

class LinearInterpolation : public Interpolation
{

public:
  explicit LinearInterpolation(const std::vector<Point> &p)
      : Interpolation(p){};

  double interpolate(const double x) const override;
};

#endif // LINEAR_INTERPOLATION_HH
