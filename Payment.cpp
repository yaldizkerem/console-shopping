#include "Payment.h"

Payment::Payment(double amount){
  this->amount=amount;
}
double Payment::getAmount()const{
  return amount;
}
void Payment::setAmount(double & amount){
  this->amount=amount;
}
