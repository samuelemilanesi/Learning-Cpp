#pragma once
#include "MultiDimKnapsack.hpp"

class LargestFirstMDK : public MultiDimKnapsack
{
private:


public:
  //  bool smallerThan(unsigned lhs, unsigned rhs ) const;
    LargestFirstMDK(int n_items, double max_weight, double max_size);
    
    std::vector<unsigned> sort(void) const override;
};