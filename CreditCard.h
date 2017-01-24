#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Payment.h"
#include<iostream>
using namespace std;

class CreditCard : public Payment{
private:
  long number;
  string type;
  string expDate;
public:
  CreditCard(double);
  long getNumber()const;
  string getType()const;
  string getExpDate()const;
  void setNumber(long &);
  void setType(string &);
  void setExpDate(string &);
  void performPayment();
};
#endif
