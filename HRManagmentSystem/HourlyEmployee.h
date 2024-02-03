#include "Employee.h"

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

class HourlyEmployee :public Employee
{
private:
    double m_hoursWorked;
    double m_rate;
    int m_more_hours;

public:
    HourlyEmployee();
    ~HourlyEmployee();
    HourlyEmployee(int more,double h,double r,int id,string n,string ph,string em,string job);
    double calculatePay();
    void getSalary();
    void addHours(int moreHours);
    void displayDetails();
};
#endif // HOURLYEMPLOYEE_H
