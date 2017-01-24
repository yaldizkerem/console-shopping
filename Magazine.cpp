#include "Magazine.h"

Magazine::Magazine(int ID, string name, double price, int issue, string type):Product(ID,name,price){
  this->issue=issue;
  this->type=type;
}
int Magazine::getIssue()const{
  return issue;
}
string Magazine::getType()const{
  return type;
}
void Magazine::setIssue(int & issue){
  this->issue=issue;
}
void Magazine::setType(string & type){
  this->type=type;
}
void Magazine::printProperties(){
  cout<<"\tID        : "<<getID()<<endl;
  cout<<"\tName      : "<<getName()<<endl;
  cout<<"\tPrice     : "<<"$"<<getPrice()<<endl;
  cout<<"\tIssue     : "<<issue<<endl;
  cout<<"\tType      : "<<type<<endl<<endl;
}
