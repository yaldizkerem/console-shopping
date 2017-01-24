#ifndef MUSICCD_H
#define MUSICCD_H

#include "Product.h"
#include<iostream>
using namespace std;

class MusicCD : public Product{
private:
  string singer;
  string type;
public:
  MusicCD(int, string, double, string, string);
  string getSinger()const;
  string getType()const;
  void setSinger(string &);
  void setType(string &);
  void printProperties();
};
#endif
