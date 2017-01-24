#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<vector>
#include"Customer.h"
#include"Book.h"
#include "Magazine.h"
#include "MusicCD.h"
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"
#include "ShoppingCart.h"
using namespace std;

class Menu{
private:
  static Customer *m_customer;
  static ShoppingCart *m_shoppingCart;
  static vector<Customer*> m_customerList;
  static vector<Book*> m_bookList;
  static vector<Magazine*> m_magazineList;
  static vector<MusicCD*> m_musicCDList;
  static bool m_loggedIn;
public:
  virtual ~Menu()=0;
  static void Samples();
  static void MainMenu();
  static void CustomerMenu();
  static void ItemMenu();
  static void ShoppingMenu();
  static void AddCustomer();
  static void ShowCustomers();
  static void AddItem();
  static void ShowItems();
  static void AddBook();
  static void AddMagazine();
  static void AddMusicCD();
  static void Login();
  static void AddProduct();
  static void RemoveProduct();
};
#endif
