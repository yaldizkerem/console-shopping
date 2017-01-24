#include "Customer.h"

Customer::Customer(long customerID, string name, string adress, string phone, double bonus, string email, string username, string password){
  this->customerID=customerID;
  this->name=name;
  this->adress=adress;
  this->phone=phone;
  this->bonus=bonus;
  this->email=email;
  this->username=username;
  this->password=password;
}
long Customer::getCustomerID()const{
  return customerID;
}
string Customer::getName()const{
  return name;
}
string Customer::getAdress()const{
  return adress;
}
string Customer::getPhone()const{
  return phone;
}
double Customer::getBonus()const{
  return bonus;
}
string Customer::getEmail()const{
  return email;
}
string Customer::getUsername()const{
  return username;
}
string Customer::getPassword()const{
  return password;
}
void Customer::setCustomerID(long & customerID){
  this->customerID=customerID;
}
void Customer::setName(string & name){
  this->name=name;
}
void Customer::setAdress(string & adress){
  this->adress=adress;
}
void Customer::setPhone(string & phone){
  this->phone=phone;
}
void Customer::setBonus(double bonus){
  this->bonus=bonus;
}
void Customer::setEmail(string & email){
  this->email=email;
}
void Customer::setUsername(string & username){
  this->username=username;
}
void Customer::setPassword(string & password){
  this->password=password;
}
bool Customer::checkAccount(string & username, string & password)const{
  if(this->username==username&this->password==password){
    return true;
  }
  return false;
}
void Customer::addBonus(double & bonus){
  this->bonus+=bonus/100;
}
