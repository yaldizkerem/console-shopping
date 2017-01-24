#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Customer.h"
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"
#include "ProductToPurchase.h"
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

class ShoppingCart{
private:
  list<ProductToPurchase *> productsToPurchase;
  Payment * paymentMethod;
  Customer * customer;
  bool isBonusUsed;
public:
  ShoppingCart(Customer *);
  Payment * getPaymentMethod()const;
  Customer * getCustomer()const;
  void setPaymentMethod(Payment *);
  void setCustomer(Customer *);
  void setBonusUsed();
  void addProduct(Product *,int &);
  void removeProduct(Product *, int &);
  void placeOrder();
  void cancelOrder();
  void printProducts();
  void showInVoice();
};
#endif
