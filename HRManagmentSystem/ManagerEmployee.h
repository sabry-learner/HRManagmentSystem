#include "SalariedEmployee.h"
#include"Employee.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H


class ManagerEmployee:public SalariedEmployee
{
private:
   double m_bonus;
   double m_more_bonus;
public:
   ManagerEmployee();
   ~ManagerEmployee();
   ManagerEmployee(int id,string n,string ph,string em,string job,double sa,double bo,double more_b);
   void getSalary();
   double calculatePay();
   void displayDetails();
   void addBonus(double moreBonus);
};

#endif // MANAGEREMPLOYEE_H
