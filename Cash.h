#ifndef CASH_H
#define CASH_H

#include "Payment.h"

class Cash : public Payment{
public:
  Cash(double);
  void performPayment();
};
#endif
