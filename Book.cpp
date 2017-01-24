#include "Book.h"

Book::Book(int ID, string name, double price, string author, string publisher, int page):Product(ID,name,price){
  this->author=author;
  this->publisher=publisher;
  this->page=page;
}
string Book::getAuthor()const{
  return author;
}
string Book::getPublisher()const{
  return publisher;
}
int Book::getPage()const{
  return page;
}
void Book::setAuthor(string & author){
  this->author=author;
}
void Book::setPublisher(string & publisher){
  this->publisher=publisher;
}
void Book::setPage(int & page){
  this->page=page;
}
void Book::printProperties(){
  cout<<"\tID        : "<<getID()<<endl;
  cout<<"\tName      : "<<getName()<<endl;
  cout<<"\tPrice     : "<<"$"<<getPrice()<<endl;
  cout<<"\tAuthor    : "<<author<<endl;
  cout<<"\tPublisher : "<<publisher<<endl;
  cout<<"\tPage      : "<<page<<endl<<endl;
}
