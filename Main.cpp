#include "Menu.h"
Customer *Menu::m_customer;
ShoppingCart *Menu::m_shoppingCart;
vector<Customer*> Menu::m_customerList;
vector<Book*> Menu::m_bookList;
vector<Magazine*> Menu::m_magazineList;
vector<MusicCD*> Menu::m_musicCDList;
bool Menu::m_loggedIn;
int main(){
  Menu::MainMenu();
}
