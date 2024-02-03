#include "Employee.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H


class CommissionEmployee :public Employee
{
public:
    double m_target;
    double m_rate;

    CommissionEmployee();
    ~CommissionEmployee();

    CommissionEmployee(int id,string n,string ph,string em,string job,double tar,double rat);
    void getSalary();
    double calculatePay();
    void displayDetails();
};

#endif // COMMISSIONEMPLOYEE_H
