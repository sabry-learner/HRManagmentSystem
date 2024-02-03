#include "CommissionEmployee.h"


CommissionEmployee::~CommissionEmployee()
{
    //dtor
}
CommissionEmployee::CommissionEmployee():m_target(0.0),m_rate(0.0){

}
CommissionEmployee::CommissionEmployee(int id,string n,string ph,string em,string job,double tar,double rat):Employee(id,n,ph,em,job){
  m_target= tar;
  m_rate=rat;
}
void CommissionEmployee::getSalary(){
  Employee::getSalary();
  cout<<"Enter Employee target : ";
  cin>>m_target;
  cout<<"Enter Employee rate : ";
  cin>>m_rate;
}
double CommissionEmployee::calculatePay(){
  return m_target* m_rate;
}
void CommissionEmployee::displayDetails(){
  Employee::displayDetails();
  cout<<"Employee target = "<<m_target<<endl;
  cout<<"Employee rate = "<<m_rate<<endl;
  cout<<"Employee Pay = "<<calculatePay()<<endl;
}
