#pragma once
#include "Developer.hpp"
class Manager : public Developer
{
private:
    double wsh_rate = 8.5;
    double m_rate = 9;
    double m_hours = 0;

public:
    Manager(const string &n, const string &s, unsigned ID)
        : Developer(n, s, ID){};

    double compute_salary() const override
    {
        return ((work_hours - wsh_hours - m_hours) * pay_rate +
                wsh_hours * wsh_rate +
                m_hours * m_rate);
    };

    //setter
    void set_m_hours(double h) { m_hours = h; };
};
