#include "MusicCD.h"

MusicCD::MusicCD(int ID, string name, double price, string singer, string type):Product(ID,name,price){
  this->singer=singer;
  this->type=type;
}
string MusicCD::getSinger()const{
  return singer;
}
string MusicCD::getType()const{
  return type;
}
void MusicCD::setSinger(string & singer){
  this->singer=singer;
}
void MusicCD::setType(string & type){
  this->type=type;
}
void MusicCD::printProperties(){
  cout<<"\tID        : "<<getID()<<endl;
  cout<<"\tName      : "<<getName()<<endl;
  cout<<"\tPrice     : "<<"$"<<getPrice()<<endl;
  cout<<"\tSinger    : "<<singer<<endl;
  cout<<"\tType      : "<<type<<endl<<endl;
}
