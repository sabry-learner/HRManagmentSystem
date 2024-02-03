#include "DentalBenefit.h"

DentalBenefit::DentalBenefit()
{
    //ctor
}

DentalBenefit::~DentalBenefit()
{
    //dtor
}
double DentalBenefit::calculateBenefit(){
  return (0.1 * m_amount);
}
void DentalBenefit::readBenefit(){
  Benefit::readBenefit();
  cout<<"Enter Dental Benefit information : ";
  getline(cin,m_info);
}
void DentalBenefit::displayBenefit(){
  Benefit::displayBenefit();
  cout<<"Total Dental Benefit = "<<calculateBenefit()<<endl;
}
