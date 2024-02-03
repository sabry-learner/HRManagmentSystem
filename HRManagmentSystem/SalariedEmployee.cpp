#include "SalariedEmployee.h"


SalariedEmployee::~SalariedEmployee()
{
    //dtor
}
SalariedEmployee::SalariedEmployee():m_salary(0.0)
{

}
SalariedEmployee::SalariedEmployee(int id,string n,string ph,string em,string job,double sa):Employee(id,n,ph,em,job)
{
    m_salary=sa;
}
void SalariedEmployee::getSalary()
{
    Employee::getSalary();
    cout<<"Enter Employee Salary : ";
    cin>>m_salary;
}
double SalariedEmployee::calculatePay()
{
    return m_salary;
}
void SalariedEmployee::displayDetails()
{
    Employee::displayDetails();
    cout<<"Employee Salary = "<<m_salary<<endl;
}
