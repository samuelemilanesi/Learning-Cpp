#include "Item.hpp"

// getters
double Item::get_size(void) const
{
    return size;
};
double Item::get_weight(void) const
{
    return weight;
};
double Item::get_value(void) const
{
    return value;
};

// setters
void Item::set_size(double size)
{
    this->size=size;
};
void Item::set_weight(double weight)
{
    this->weight=weight;
};
void Item::set_value(double value)
{
    this->value=value;
};

void Item::print() const
{
    std::cout << "(w: " << get_weight() << ", s: " << get_size() << ", v: " << get_value() << (")\n");
}