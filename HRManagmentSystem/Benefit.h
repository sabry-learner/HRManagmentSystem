#include<iostream>
#include<string>
using namespace std;
#ifndef BENEFIT_H
#define BENEFIT_H


class Benefit {
protected:
   string m_planType;
   double m_amount;
public:
   Benefit();
   ~Benefit();
   void readBenefit();
   virtual double calculateBenefit()=0;
   virtual void displayBenefit();
};
#endif // BENEFIT_H
