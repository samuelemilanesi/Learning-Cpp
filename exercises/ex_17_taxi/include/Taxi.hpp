#pragma once
#include "Driver.hpp"
#include "Receipt.hpp"
#include <vector>
class Taxi {
private:
    std::vector<Receipt> receipts;
    Driver* driv;
public:
    Taxi();
    Taxi operator=(const Taxi&);
    ~Taxi();
};