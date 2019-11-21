#include "MultiDimKnapsack.hpp"
#include <iostream>
#include <random>

MultiDimKnapsack::MultiDimKnapsack(int n_items, double max_weight,
                                   double max_size)
    : w(max_weight), s(max_size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> rand_weight(0.0, w);
    std::uniform_real_distribution<double> rand_size(0.0, s);
    std::uniform_real_distribution<double> rand_value(0.0, 1.0);

    for (int k = 0; k < n_items; ++k)
    {
        // the biggest item is at most 1/3 of the knapsack in both weight and size
        items.push_back(Item(rand_weight(gen)/3, rand_size(gen)/3, rand_value(gen)));
    }
};

std::set<unsigned> MultiDimKnapsack::solve(void) const
{
    std::set<unsigned> solution;
    std::vector<unsigned> indexes(sort());
    double current_size(0.0);
    double current_weight(0.0);
    for (auto it = indexes.begin(); it != indexes.cend(); ++it)
    {
        if (current_size + items[*it].get_size() <= s && current_weight + items[*it].get_weight() <= w)
        {
            current_size += items[*it].get_size();
            current_weight += items[*it].get_weight();
            solution.insert(*it);
        }
    }
    return solution;

};

void MultiDimKnapsack::print_solution(void) const
{
    std::set<unsigned> indexes(solve());
    
    std::cout << "[";
    for(auto it=indexes.cbegin(); it!=indexes.cend();++it)
    {
        std::cout << *it <<", ";
    }
    std::cout << "\b\b]";
};

void MultiDimKnapsack::print() const
{
    std::cout << "Knapsack: \n[\n";
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        it->print();
    }
    std::cout << "]" << std::endl;
};
