#pragma once
#include "Employee.hpp"
class Secretary : public Employee
{
private:
public:
    Secretary(const string &n, const string &s, unsigned ID)
        : Employee(n, s, ID){};
    
    double compute_salary() const override{return pay_rate*work_hours;};
    


};