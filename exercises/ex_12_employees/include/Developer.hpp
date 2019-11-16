#pragma once
#include "Employee.hpp"
class Developer : public Employee
{
protected:
    double wsh_hours = 0;
    const double wsh_rate = 8;

public:
    Developer(const string &n, const string &s, unsigned int ID)
        : Employee(n, s, ID){};

    // setters
    void set_wsh_hours(double h) { wsh_hours = h; };

    double compute_salary() const override { return ((work_hours - wsh_hours) * pay_rate + wsh_hours * wsh_rate); };

};