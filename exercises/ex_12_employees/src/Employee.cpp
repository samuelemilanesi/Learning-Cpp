#include "Employee.hpp"

string Employee::get_name() const
{
    return name;
};

string Employee::get_surname() const
{
    return surname;
}

unsigned int Employee::get_employeeID() const
{
    return employee_ID;
}

double Employee::get_work_hours() const
{
    return work_hours;
}