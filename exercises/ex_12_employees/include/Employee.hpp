#pragma once
#include <string>
using std::string;

class Employee {
protected:
    string name;
    string surname;
    unsigned int employee_ID;
    const double pay_rate=7.5;
    double work_hours;
public:
    Employee(const string& n, const string& s, unsigned ID)
        :name(n),surname(s),employee_ID(ID){};

//getters 
    string get_name() const;
    string get_surname() const;
    unsigned int get_employeeID() const;
    double get_pay_rate() const;
    double get_work_hours() const;

// pure virtual functions
    virtual double compute_salary() const = 0;

//setters 
    void set_work_hours(double);

};