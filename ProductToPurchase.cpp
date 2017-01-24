#include "ProductToPurchase.h"

ProductToPurchase::ProductToPurchase(Product * product, int quantity){
  this->product=product;
  this->quantity=quantity;
}
Product * ProductToPurchase::getProduct()const{
  return product;
}
int ProductToPurchase::getQuantity()const{
  return quantity;
}
void ProductToPurchase::setProduct(Product * product){
  this->product=product;
}
void ProductToPurchase::setQuantity(int quantity){
  this->quantity=quantity;
}
