#include "Benefit.h"

Benefit::Benefit()
{
    //ctor
}

Benefit::~Benefit()
{
    //dtor
}

void Benefit::readBenefit(){
  cout<<"Enter Benefit plan type : ";
  getline(cin,m_planType);
  cout<<"Enter Benefit amount : ";
  cin>>m_amount;
}

void Benefit::displayBenefit(){
  cout<<"Benefit Plan Type : "<<m_planType<<"\t"<<"Benefit amount = "<<m_amount<<endl;
}
