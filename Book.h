#ifndef BOOK_H
#define BOOK_H

#include "Product.h"
#include<iostream>
using namespace std;

class Book : public Product{
private:
  string author;
  string publisher;
  int page;
public:
  Book(int, string, double, string, string, int);
  string getAuthor()const;
  string getPublisher()const;
  int getPage()const;
  void setAuthor(string &);
  void setPublisher(string &);
  void setPage(int &);
  void printProperties();
};
#endif
