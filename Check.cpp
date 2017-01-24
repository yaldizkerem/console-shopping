#include "Check.h"

Check::Check(double amount):Payment(amount){

}
string Check::getName()const{
  return name;
}
string Check::getBankID()const{
  return bankID;
}
void Check::setName(string & name){
  this->name=name;
}
void Check::setBankID(string & bankID){
  this->bankID=bankID;
}
void Check::performPayment(){
  string name;
  string bankID;
  cin.ignore();
  cout<<"\tName> ";
  getline(cin,name);
  cout<<"\tbankID> ";
  getline(cin,bankID);
  cout<<"\t$"<<getAmount()<<" has been paid"<<endl;
}
