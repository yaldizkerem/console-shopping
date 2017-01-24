#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(Customer * customer){
  this->customer=customer;
  this->isBonusUsed=false;
}
Payment * ShoppingCart::getPaymentMethod()const{
  return paymentMethod;
}
Customer * ShoppingCart::getCustomer()const{
  return customer;
}
void ShoppingCart::setPaymentMethod(Payment * paymentMethod){
  this->paymentMethod=paymentMethod;
}
void ShoppingCart::setCustomer(Customer * customer){
  this->customer=customer;
}
void ShoppingCart::setBonusUsed(){
  isBonusUsed=true;
}
void ShoppingCart::addProduct(Product * product,int & quantity){
  list<ProductToPurchase*>::iterator iter;
  for(iter=productsToPurchase.begin();iter!=productsToPurchase.end();++iter){
    if((*iter)->getProduct()==product){
      (*iter)->setQuantity((*iter)->getQuantity()+quantity);
      return;
    }
  }
  ProductToPurchase *producttopurchase=new ProductToPurchase(product,quantity);
  productsToPurchase.push_back(producttopurchase);
}
void ShoppingCart::removeProduct(Product * product, int & quantity){
  list<ProductToPurchase*>::iterator iter;
  for(iter=productsToPurchase.begin();iter!=productsToPurchase.end();iter++){
    if((*iter)->getProduct()==product){
      if(quantity<(*iter)->getQuantity()){
        (*iter)->setQuantity((*iter)->getQuantity()-quantity);
        cout<<"\tProduct successfully removed!"<<endl;
        return;
      }
      else{
        iter=productsToPurchase.erase(iter);
        cout<<"\tProduct successfully removed!"<<endl;
        return;
      }
    }
  }
  cout<<"\tThere is no such product in Shopping Cart!"<<endl;
}
void ShoppingCart::placeOrder(){
  while(true) {
    cout<<"\t------------------------|"<<endl;
    cout<<"\t|     1. CreditCard     |"<<endl;
    cout<<"\t|     2. Cash           |"<<endl;
    cout<<"\t|     3. Check          |"<<endl;
    cout<<"\t|     4. Back           |"<<endl;
    cout<<"\t-------------------------"<<endl;
    cout<<"\tChoose one : ";
    int condition;
    cin>>condition;
    if(condition==4){
      break;
    }
    if(condition==1|condition==2|condition==3){
      double amount=0;
      for(list<ProductToPurchase*>::iterator iter=productsToPurchase.begin();iter!=productsToPurchase.end();iter++){
        amount+=(*iter)->getProduct()->getPrice()*(*iter)->getQuantity();
      }
      cout<<endl<<"\tTotal Price : "<<amount<<endl;
      if(isBonusUsed){
        cout<<"\tBonus       : "<<customer->getBonus()<<endl<<endl;
        if(customer->getBonus()>=amount){
          customer->setBonus(customer->getBonus()-amount);
          amount=0;
        }
        else{
          amount-=customer->getBonus();
          customer->setBonus(0);
        }
      }
      if(condition==1){
        paymentMethod=new CreditCard(amount);
      }
      else if(condition==2){
        paymentMethod=new Cash(amount);
      }
      else if(condition==3){
        paymentMethod=new Check(amount);
      }
      paymentMethod->performPayment();
      customer->addBonus(amount);
      cancelOrder();
      isBonusUsed=false;
      break;
    }
  }
}
void ShoppingCart::cancelOrder(){
  while(!productsToPurchase.empty()){
    productsToPurchase.pop_back();
  }
}
void ShoppingCart::printProducts(){
  if(productsToPurchase.empty()){
    cout<<"\tShopping Cart is empty!"<<endl;
  }
  else{
    cout<<"\t-------------------------"<<endl;
    cout<<"\t|     SHOPPING CART     |"<<endl;
    cout<<"\t-------------------------"<<endl<<endl;
    list<ProductToPurchase*>::iterator iter;
    for(iter=productsToPurchase.begin();iter!=productsToPurchase.end();iter++){
      cout<<"\tQuantity  : "<<(*iter)->getQuantity()<<endl;
      (*iter)->getProduct()->printProperties();
    }
  }
}
void ShoppingCart::showInVoice(){
  cout<<"\t-------------------"<<endl;
  cout<<"\t|     INVOICE     |"<<endl;
  cout<<"\t-------------------"<<endl<<endl;
  cout<<"\tName   : "<<customer->getName()<<endl;
  cout<<"\tAdress : "<<customer->getAdress()<<endl;
  cout<<"\tPhone  : "<<customer->getPhone()<<endl;
  cout<<"\tEmail  : "<<customer->getEmail()<<endl<<endl;
}
