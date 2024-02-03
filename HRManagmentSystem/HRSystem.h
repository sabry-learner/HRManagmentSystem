#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;
#ifndef HRSYSTEM_H
#define HRSYSTEM_H


class HRSystem
{
private:
    Employee** m_employee_list;
    int m_size_emp;
    int m_count_emp;
public:
    void calc_Total_Payroll();
    void add_Employee();
    void edit_Employee(int);
    void del_Employee(int);
    void Find_Employee(string);
    void show_All();
    bool assignDepartToEmployeeById(int , Departement*);
    int findById(int);
    HRSystem(int);
    virtual ~HRSystem();

};

#endif // HRSYSTEM_H
