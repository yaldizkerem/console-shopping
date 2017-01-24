#include "CreditCard.h"

CreditCard::CreditCard(double amount):Payment(amount){

}
long CreditCard::getNumber()const{
  return number;
}
string CreditCard::getType()const{
  return type;
}
string CreditCard::getExpDate()const{
  return expDate;
}
void CreditCard::setNumber(long & number){
  this->number=number;
}
void CreditCard::setType(string & type){
  this->type=type;
}
void CreditCard::setExpDate(string & expDate){
  this->expDate=expDate;
}
void CreditCard::performPayment(){
  long number;
  string type;
  string expDate;
  cout<<"\tNumber> ";
  cin>>number;
  cin.ignore();
  cout<<"\tType> ";
  getline(cin,type);
  cout<<"\texpDate> ";
  getline(cin,expDate);
  cout<<"\t$"<<getAmount()<<" has been paid"<<endl;
}
