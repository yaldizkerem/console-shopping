#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>
using namespace std;

class Product{
private:
  int ID;
  string name;
  double price;
public:
  Product(int, string, double);
  int getID()const;
  string getName()const;
  double getPrice()const;
  void setID(int &);
  void setName(string &);
  void setPrice(double &);
  virtual void printProperties()=0;
};
#endif
