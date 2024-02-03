#include "ManagerEmployee.h"


ManagerEmployee::~ManagerEmployee()
{
    //dtor
}
ManagerEmployee::ManagerEmployee():m_bonus(0.0),m_more_bonus(0.0){

}
ManagerEmployee::ManagerEmployee(int id,string n,string ph,string em,string job,double sa,double bo,double more_b):SalariedEmployee(id,n,ph,em,job,sa)
{
  m_bonus = bo;
  m_more_bonus=more_b;
}
void ManagerEmployee::getSalary(){
  char ch;
  SalariedEmployee::getSalary();
  cout<<"Enter Manager Employee Bonus : ";
  cin>>m_bonus;
  cout<<"Did you achieve an extra bonus?(y/n): ";
  cin>>ch;
  if(ch=='y'||ch=='Y'){
     cout<<"Enter more bonus : ";
     cin>>m_more_bonus;
  }
}
double ManagerEmployee::calculatePay(){
  return m_salary + m_bonus;
}
void ManagerEmployee::displayDetails(){
  SalariedEmployee::displayDetails();
  cout<<"Manager Employee bonus = "<<calculatePay()<<endl;
  if(m_more_bonus>0){
     addBonus(m_more_bonus);
  cout<<"Total bonus after adding extra bonus = "<<m_bonus<<endl;
  }
}
void ManagerEmployee::addBonus(double moreBonus){
  m_bonus+=moreBonus;

}
