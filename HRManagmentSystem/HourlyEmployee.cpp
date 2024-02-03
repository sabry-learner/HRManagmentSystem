#include "HourlyEmployee.h"

HourlyEmployee::~HourlyEmployee()
{
    //dtor
}
HourlyEmployee::HourlyEmployee():m_hoursWorked(0.0),m_rate(0.0),m_more_hours(0)
{

}
HourlyEmployee::HourlyEmployee(int more,double h,double r,int id,string n,string ph,string em,string job):Employee(id,n,ph,em,job)
{
    m_hoursWorked=h;
    m_rate=r;
    m_more_hours=more;
}
double HourlyEmployee::calculatePay()
{
    return m_hoursWorked*m_rate;
}
void HourlyEmployee::getSalary()
{
    Employee::getSalary();
    char choose;
    cout<<"Enter your hours worked : ";
    cin>>m_hoursWorked;
    cout<<"Enter your rate : ";
    cin>>m_rate;
    cout<<"You Worked more hours ?(y/n): ";
    cin>>choose;
    if(choose=='y'||choose=='Y')
    {
        cout<<"Enter more hours worked : ";
        cin>>m_more_hours;
    }
}
void HourlyEmployee::addHours(int moreHours)
{
    m_hoursWorked+= moreHours;
}

void HourlyEmployee::displayDetails()
{
    Employee::displayDetails();
    cout<<"Employee hours worked = "<<m_hoursWorked<<"\t"<<"Employee rate = "<<m_rate<<endl;
    cout<<"Employee Basic Salary = "<<calculatePay()<<endl;
    if(m_more_hours>0)
    {
        addHours(m_more_hours);
        cout<<"The Total Salary = "<<m_hoursWorked*m_rate<<endl;
    }

}
