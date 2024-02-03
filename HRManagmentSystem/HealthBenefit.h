#include "Benefit.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H


class HealthBenefit : public Benefit{
private:
   string m_info;
   string m_coverage;
public:
   HealthBenefit();
   ~HealthBenefit();
   double calculateBenefit();
   void readBenefit();
   void displayBenefit();
};
#endif // HEALTHBENEFIT_H
