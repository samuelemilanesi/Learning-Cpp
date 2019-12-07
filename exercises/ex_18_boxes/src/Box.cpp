#include "Box.hpp"

unsigned Box::n_boxes=0;


Box& Box::operator=(Box& b)
{
    height=b.height;
    breadth=b.breadth;
    length=b.length;

}

double Box::Volume() const
{
    return length * breadth * height;
}
