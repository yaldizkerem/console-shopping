#ifndef PRODUCTTOPURCHASE_H
#define PRODUCTTOPURCHASE_H

#include "Book.h"
#include "Magazine.h"
#include "MusicCD.h"

class ProductToPurchase{
private:
  Product * product;
  int quantity;
public:
  ProductToPurchase(Product *, int);
  Product * getProduct()const;
  int getQuantity()const;
  void setProduct(Product *);
  void setQuantity(int);
};
#endif
