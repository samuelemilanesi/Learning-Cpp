#include "Taxi.hpp"

Taxi Taxi::operator=(const Taxi &t)
{
    if(this != &t )
    {   

        Driver* tmp = new Driver(*(t.driv));
        this->driv = tmp;
        delete tmp;
        receipts = t.receipts;

    }
    return *this;
   
}
