#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<string>
using namespace std;

class Customer{
private:
  long customerID;
  string name;
  string adress;
  string phone;
  double bonus;
  string email;
  string username;
  string password;
public:
  Customer(long, string, string, string, double, string, string, string);
  long getCustomerID()const;
  string getName()const;
  string getAdress()const;
  string getPhone()const;
  double getBonus()const;
  string getEmail()const;
  string getUsername()const;
  string getPassword()const;
  void setCustomerID(long &);
  void setName(string &);
  void setAdress(string &);
  void setPhone(string &);
  void setBonus(double);
  void setEmail(string &);
  void setUsername(string &);
  void setPassword(string &);
  bool checkAccount(string &, string &)const;
  void addBonus(double &);
};
#endif
