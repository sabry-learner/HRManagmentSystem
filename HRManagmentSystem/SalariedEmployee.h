#include "Employee.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H


class SalariedEmployee:public Employee
{
public:
    double m_salary;
    SalariedEmployee();
    virtual~SalariedEmployee();
    SalariedEmployee(int id,string n,string ph,string em,string job,double sa);
    void getSalary();
    double calculatePay();
    void displayDetails();
};
#endif // SALARIEDEMPLOYEE_H
