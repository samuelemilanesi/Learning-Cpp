#ifndef BOX_hpp
#define BOX_hpp
#include <iostream>
using std::cout;
using std::endl;
class Box
{
public:
    Box(double l, double b, double h) : length(l), breadth(b), height(h)
    {
        
        cout << "Constructing a box" << endl;
        cout << "box number: " <<++n_boxes<<endl;
        id=n_boxes;
    }
    Box(const Box& b) : length(b.length), breadth(b.breadth), height(b.height)
    {
        cout << "Constructing a box" << endl;
        cout << "box number: " <<++n_boxes<<endl;
        id=n_boxes;

    }
    Box& operator=(Box& b);
    ~Box()
    {
        cout << "Destructing a box" << endl;
        cout << "number of boxes: " <<--n_boxes<<endl;
    }

    double Volume() const;
    static unsigned get_n_boxes(){return n_boxes;};

private:
    static unsigned n_boxes; // number of boxes 
    double length;  // Length of a box
    double breadth; // Breadth of a box
    double height;  // Height of a box
    unsigned id;
};
#endif