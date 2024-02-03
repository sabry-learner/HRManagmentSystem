#include "Benefit.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H


class DentalBenefit : public Benefit{
public:
   string m_info;
   DentalBenefit();
   ~DentalBenefit();
   double calculateBenefit();
   void readBenefit();
   void displayBenefit();

};
#endif // DENTALBENEFIT_H
