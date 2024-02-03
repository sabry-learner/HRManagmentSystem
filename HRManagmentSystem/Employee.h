#include "Departement.h"
#include<iostream>
#include<string>
#include"Benefit.h"
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
private:
    Benefit** m_benefit_list;
protected:
    int m_employeeID;
    string m_name;
    string m_phone;
    string m_email;
    string m_jobTitle;
    Departement* depart_employee;
    int m_size_benefit ;
    int m_count_benefit;
public:
    Employee();
    Employee (int id,string n,string ph,string em,string job);
    virtual ~Employee();
    void set_ID(int);
    int get_ID();
    string get_name();
    string get_jobTitle();
    virtual void getSalary();
    virtual void displayDetails();
    virtual double calculatePay()=0;
    void set_depart(Departement*);
    Departement get_department()const;
};

#endif // EMPLOYEE_H
