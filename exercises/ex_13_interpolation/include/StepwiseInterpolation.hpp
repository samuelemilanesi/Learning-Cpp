#ifndef STEPWISE_INTERPOLATION_HH
#define STEPWISE_INTERPOLATION_HH

#include <vector>
#include "Interpolation.hpp"

class StepwiseInterpolation: public Interpolation
{
public:
  explicit StepwiseInterpolation (const std::vector<Point> &p)
    :Interpolation(p){};

  double interpolate(const double x) const override;
};

#endif // STEPWISE_INTERPOLATION_HH
