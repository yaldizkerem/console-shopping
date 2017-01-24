#ifndef PAYMENT_H
#define PAYMENT_H

#include<iostream>
using namespace std;

class Payment{
private:
  double amount;
public:
  Payment(double);
  double getAmount()const;
  void setAmount(double &);
  virtual void performPayment()=0;
};
#endif
