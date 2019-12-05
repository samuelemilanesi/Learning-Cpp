#pragma once
#include "Driver.hpp"
#include "Receipt.hpp"
#include <vector>
class Taxi
{
private:
    std::vector<Receipt> receipts;
    Driver *driv;

public:
    Taxi(const Driver &d, const std::vector<Receipt> &r)
        : driv(new Driver(d)), receipts(r){};
    Taxi(const Taxi &t)
        : driv(new Driver(*(t.driv))), receipts(t.receipts){};

    Taxi operator=(const Taxi &t);

    ~Taxi()
    {
        delete driv;
    };
};