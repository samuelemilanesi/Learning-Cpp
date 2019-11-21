#include "LargestFirstMDK.hpp"
#include <algorithm>
#include <iostream>
LargestFirstMDK::LargestFirstMDK(int n_items, double max_weight, double max_size)
    : MultiDimKnapsack(n_items, max_weight, max_size){};



std::vector<unsigned> LargestFirstMDK::sort(void) const
{
    std::vector<unsigned> res;
    for (unsigned k = 0; k < items.size(); ++k)
    {
        res.push_back(k);
    };

    for (std::size_t i = 0; i < items.size() - 1; ++i)
    {
        for (std::size_t j = i + 1; j < items.size(); ++j)
        {
            if (items[res[i]].get_size() < items[res[j]].get_size())
            {
                using std::swap;
                swap(res[i], res[j]);
            }
        }
    }
    
    return res;
};
