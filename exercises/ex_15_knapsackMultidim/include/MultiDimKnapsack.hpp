#ifndef MULTIDIMKNAPSACK_H_
#define MULTIDIMKNAPSACK_H_

#include <set>
#include <vector>
#include "Item.hpp"

class MultiDimKnapsack
{
protected:
    double w;
    double s;
    std::vector<Item> items;
    // returns a vector of sorted item indices
    virtual std::vector<unsigned> sort(void) const = 0;

public:
    // generate n_items random items and set knapsack capacities
    MultiDimKnapsack(int n_items, double max_weight,
                     double max_size);
    // returns the set of items included in the solution
    std::set<unsigned> solve(void) const;
    //prints all possible items 
    void print(void) const;
    //prints solution
    void print_solution(void) const;

};

#endif /* MULTIDIMKNAPSACK_H_ */