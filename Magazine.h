#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Product.h"
#include<iostream>
using namespace std;

class Magazine : public Product{
private:
  int issue;
  string type;
public:
  Magazine(int, string, double, int, string);
  int getIssue()const;
  string getType()const;
  void setIssue(int &);
  void setType(string &);
  void printProperties();
};
#endif
