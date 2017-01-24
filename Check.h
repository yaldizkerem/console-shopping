#ifndef CHECK_H
#define CHECK_H

#include "Payment.h"
#include<string>
using namespace std;

class Check : public Payment{
private:
  string name;
  string bankID;
public:
  Check(double);
  string getName()const;
  string getBankID()const;
  void setName(string &);
  void setBankID(string &);
  void performPayment();
};
#endif
