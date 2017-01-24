#include "Cash.h"

Cash::Cash(double amount):Payment(amount){

}
void Cash::performPayment(){
  cout<<"\t$"<<getAmount()<<" has been paid"<<endl;
}
