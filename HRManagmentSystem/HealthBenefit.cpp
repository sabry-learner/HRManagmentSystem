#include "HealthBenefit.h"

HealthBenefit::HealthBenefit()
{
    //ctor
}

HealthBenefit::~HealthBenefit()
{
    //dtor
}
double HealthBenefit::calculateBenefit(){
  return (0.2 * m_amount);
}
void HealthBenefit::readBenefit(){
  Benefit::readBenefit();
  cout<<"Enter Health Benefit information : ";
  getline(cin,m_info);
  cout<<"Enter Health Benefit coverage : ";
  getline(cin,m_coverage);
}
void HealthBenefit::displayBenefit(){
  Benefit::displayBenefit();
  cout<<"Total Health Benefit = "<<calculateBenefit()<<endl;
}
