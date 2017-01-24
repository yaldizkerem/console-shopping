#include "Product.h"

Product::Product(int ID, string name, double price){
  this->ID=ID;
  this->name=name;
  this->price=price;
}
int Product::getID()const{
  return ID;
}
string Product::getName()const{
  return name;
}
double Product::getPrice()const{
  return price;
}
void Product::setID(int & ID){
  this->ID=ID;
}
void Product::setName(string & name){
  this->name=name;
}
void Product::setPrice(double & price){
  this->price=price;
}
