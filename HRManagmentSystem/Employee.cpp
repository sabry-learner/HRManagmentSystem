#include "Employee.h"
#include "HealthBenefit.h"
#include "DentalBenefit.h"
using namespace std;
Employee::Employee()
{
    depart_employee= NULL;
    m_size_benefit=10;
    m_count_benefit=0;
    m_benefit_list=new Benefit*[m_size_benefit];
}

Employee::~Employee()
{
    for(int i=0; i<m_count_benefit; i++)
    {
        delete m_benefit_list[i];
    }

    delete [] m_benefit_list;
}

Employee::Employee (int id,string n,string ph,string em,string job)
{
    m_employeeID=id;
    m_name=n;
    m_phone=ph;
    m_email=em;
    m_jobTitle=job;

}
void Employee::set_ID(int id)
{
    m_employeeID=id;
}
int Employee::get_ID()
{
    return m_employeeID;
}
string Employee::get_jobTitle()
{
    return m_jobTitle;
}
void Employee::getSalary()
{
    int n;
    cout<<"-----\tEnter Employee Information ,Please-----\n";
    cin.ignore();
    cout<<"Enter Employee Name : ";

    getline(cin,m_name);
    cout<<"Enter Employee ID : ";
    cin>>m_employeeID;
    cin.ignore();
    cout<<"Enter Employee Phone : ";
    getline(cin,m_phone);
    cout<<"Enter Employee Email : ";
    getline(cin,m_email);
    cout<<"Enter Employee Job Title : ";
    getline(cin,m_jobTitle);

    cout<<"Enter a number of Benefits: ";
    cin>>n;
    cin.ignore();

    if(n<=m_size_benefit)
    {
        for(int i=0; i<n; i++)
        {
            string type;
            cout<<"Enter type of benefit (Health,Dental) :";
            cin>>type;
            cin.ignore();
            if(type=="Health"||type=="health")
            {
                m_benefit_list[i]=new HealthBenefit();
                m_benefit_list[i]->readBenefit();
                m_count_benefit++;
            }
            else if(type=="Dental"||type=="dental")
            {
                m_benefit_list[i]=new DentalBenefit();
                m_benefit_list[i]->readBenefit();
                m_count_benefit++;
            }
            else
            {
                cout<<"Invalid choice, try again!\n";
            }

        }
    }
}
void Employee::set_depart(Departement* d)
{
    depart_employee=d;
}
Departement Employee::get_department()const
{
    return *depart_employee;
}
string Employee::get_name()
{
    return m_name;
}
void Employee::displayDetails()
{
    cout<<"--------------------------------------\n";
    cout<<"Employee Name : "<<m_name<<"\t"<<"Employee ID : "<<m_employeeID<<endl;
    cout<<"Employee Phone : "<<m_phone<<"\t"<<"Employee Email : "<<m_email<<endl;
    cout<<"Employee Job Title : "<<m_jobTitle<<endl;
    if(depart_employee!=NULL)
    {
        depart_employee->print();
    }

    for(int i=0; i<m_count_benefit; i++)
    {
        cout<<"Total Number of Benefits is "<<m_count_benefit<<":-"<<endl;
        m_benefit_list[i]->displayBenefit();
        m_benefit_list[i]->calculateBenefit();
    }
}
