#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
class Item
{
    double weight;
    double size;
    double value;

public:
    Item(double w, double s, double v)
        : weight(w), size(s), value(v) {}

// getters
    double get_size(void) const;
    double get_weight(void) const;
    double get_value(void) const;

// setters
    void set_size(double size);
    void set_weight(double weight);
    void set_value(double value);

// printer 
    void print(void) const;
};

#endif /* ITEM_H_ */