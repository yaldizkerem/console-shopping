#include "Menu.h"
void Menu::Samples(){
  m_loggedIn=false;
  Customer *customer=new Customer(0,"Kerem Yaldız","Eskişehir","+90 *** ** **",50,"keremyaldiz@gmail.com","yaldizkerem","1");
  m_customerList.push_back(customer);
  Book *book=new Book(10,"Sefiller",15.99,"Victor HUGO","CAN",533);
  m_bookList.push_back(book);
  Magazine *magazine=new Magazine(11,"Cosmopolitan",23.30,1932,"Fashion");
  m_magazineList.push_back(magazine);
  MusicCD *musiccd=new MusicCD(12,"Dream On",19.99,"Aerosmith","Rock");
  m_musicCDList.push_back(musiccd);
}
void Menu::MainMenu(){
  Samples();
  int condition;
  do {
    cout<<"\t-----------------------"<<endl;
    cout<<"\t|     1. Customer     |"<<endl;
    cout<<"\t|     2. Item         |"<<endl;
    cout<<"\t|     3. Shopping     |"<<endl;
    cout<<"\t|     4. Exit         |"<<endl;
    cout<<"\t-----------------------"<<endl;
    cout<<"\tChoose one : ";
    cin>>condition;
    switch (condition) {
      case 1:
        CustomerMenu();
      break;
      case 2:
        ItemMenu();
      break;
      case 3:
        ShoppingMenu();
      break;
      case 4:
        exit(0);
      break;
      default:
        cout<<"\tInvalid option!"<<endl;
      break;
    }
  } while(condition!=4);
}

void Menu::CustomerMenu(){
  int condition;
  do {
    cout<<"\t---------------------------------------------------"<<endl;
    cout<<"\t|     1. Add a new customer to system             |"<<endl;
    cout<<"\t|     2. Show the customers in the system         |"<<endl;
    cout<<"\t|     3. Back                                     |"<<endl;
    cout<<"\t---------------------------------------------------"<<endl;
    cout<<"\tChoose one : ";
    cin>>condition;
    switch (condition) {
      case 1:
        AddCustomer();
      break;
      case 2:
        ShowCustomers();
      break;
      case 3:
      break;
      default:
        cout<<"\tInvalid option!"<<endl;
      break;
    }
  } while(condition!=3);
}
void Menu::ItemMenu(){
  int condition;
  do {
    cout<<"\t-----------------------------------------------"<<endl;
    cout<<"\t|     1. Add a new item to system             |"<<endl;
    cout<<"\t|     2. Show the items in the system         |"<<endl;
    cout<<"\t|     3. Back                                 |"<<endl;
    cout<<"\t-----------------------------------------------"<<endl;
    cout<<"\tChoose one : ";
    cin>>condition;
    switch (condition) {
      case 1:
        AddItem();
      break;
      case 2:
        ShowItems();
      break;
      case 3:
      break;
      default:
        cout<<"\tInvalid option!"<<endl;
      break;
    }
  } while(condition!=3);
}
void Menu::ShoppingMenu(){
  int condition;
  do {
    cout<<"\t----------------------------------"<<endl;
    if(!m_loggedIn){
      cout<<"\t|     1.  Login                  |"<<endl;
    }
    else{
      cout<<"\t|     1.  Logged In              |"<<endl;
    }
    cout<<"\t|     2.  Add Product            |"<<endl;
    cout<<"\t|     3.  Remove Product         |"<<endl;
    cout<<"\t|     4.  List All Products      |"<<endl;
    cout<<"\t|     5.  List Shopping Cart     |"<<endl;
    cout<<"\t|     6.  Show Bonus             |"<<endl;
    cout<<"\t|     7.  Use Bonus              |"<<endl;
    cout<<"\t|     8.  Place Order            |"<<endl;
    cout<<"\t|     9.  Cancel order           |"<<endl;
    cout<<"\t|     10. Show invoice           |"<<endl;
    cout<<"\t|     11. Back                   |"<<endl;
    cout<<"\t----------------------------------"<<endl;
    cout<<"\tChoose one : ";
    cin>>condition;
    switch (condition) {
      case 1:
        Login();
      break;
      case 2:
        AddProduct();
      break;
      case 3:
        RemoveProduct();
      break;
      case 4:
        ShowItems();
      break;
      case 5:
        if(m_loggedIn){
          m_shoppingCart->printProducts();
        }
        else{
          cout<<"\tYou should login first!"<<endl;
        }
      break;
      case 6:
        if(m_loggedIn){
          cout<<"\tBonus : "<<m_shoppingCart->getCustomer()->getBonus()<<endl;
        }
        else{
          cout<<"\tYou should login first!"<<endl;
        }
      break;
      case 7:
        if(m_loggedIn){
          m_shoppingCart->setBonusUsed();
        }
        else{
          cout<<"\tYou should login first!"<<endl;
        }
      break;
      case 8:
        if(m_loggedIn){
          m_shoppingCart->placeOrder();
        }
        else{
          cout<<"\tYou should login first!"<<endl;
        }
      break;
      case 9:
        if(m_loggedIn){
          m_shoppingCart->cancelOrder();
          cout<<"\tOrder has been succesfully canceled!"<<endl;
        }
        else{
          cout<<"\tYou should login first!"<<endl;
        }
      break;
      case 10:
        if(m_loggedIn){
          m_shoppingCart->showInVoice();
        }
        else{
          cout<<"\tYou should login first!"<<endl;
        }
      break;
      case 11:
        m_loggedIn=false;
      break;
      default:
        cout<<"\tInvalid option!"<<endl;
      break;
    }
  } while(condition!=11);
}
void Menu::AddCustomer(){
  string name;
  string adress;
  string phone;
  string email;
  string username;
  string password;
  cin.ignore();
  cout<<"Customer name> ";
  getline(cin,name);
  cout<<"Customer adress> ";
  getline(cin,adress);
  cout<<"Customer phone number> ";
  getline(cin,phone);
  cout<<"Customer email> ";
  getline(cin,email);
  cout<<"Customer username> ";
  getline(cin,username);
  cout<<"Customer password> ";
  getline(cin,password);

  Customer *customer=new Customer(m_customerList.size(),name,adress,phone,0,email,username,password);
  m_customerList.push_back(customer);
}
void Menu::ShowCustomers(){
  if(m_customerList.empty()){
    cout<<"\tCustomer list is empty!"<<endl;
  }
  else{
    cout<<"\t-------------------------"<<endl;
    cout<<"\t|     CUSTOMER LIST     |"<<endl;
    cout<<"\t-------------------------"<<endl<<endl;
    for(int i=0;i<m_customerList.size();i++){
      cout<<"\tName   : "<<m_customerList[i]->getName()<<endl;
      cout<<"\tAdress : "<<m_customerList[i]->getAdress()<<endl;
      cout<<"\tPhone  : "<<m_customerList[i]->getPhone()<<endl;
      cout<<"\tEmail  : "<<m_customerList[i]->getEmail()<<endl<<endl;
    }
  }
}
void Menu::AddItem(){
  int condition;
  do {
    cout<<"\t-----------------------"<<endl;
    cout<<"\t|     1. Book         |"<<endl;
    cout<<"\t|     2. Magazine     |"<<endl;
    cout<<"\t|     3. MusicCD      |"<<endl;
    cout<<"\t|     4. Back         |"<<endl;
    cout<<"\t-----------------------"<<endl;
    cout<<"\tChoose one : ";
    cin>>condition;
    switch (condition) {
      case 1:
        AddBook();
      break;
      case 2:
        AddMagazine();
      break;
      case 3:
        AddMusicCD();
      break;
      case 4:
      break;
      default:
        cout<<"\tInvalid option!"<<endl;
      break;
    }
  } while(condition!=4);
}
void Menu::ShowItems(){
  if(!m_bookList.empty()){
    cout<<"\t---------------------"<<endl;
    cout<<"\t|     BOOK LIST     |"<<endl;
    cout<<"\t---------------------"<<endl<<endl;
    for(int i=0;i<m_bookList.size();i++){
      m_bookList[i]->printProperties();
    }
  }
  if(!m_magazineList.empty()){
    cout<<"\t------------------------"<<endl;
    cout<<"\t|     MAGAZINE LIST     |"<<endl;
    cout<<"\t------------------------"<<endl<<endl;
    for(int i=0;i<m_magazineList.size();i++){
      m_magazineList[i]->printProperties();
    }
  }
  if(!m_musicCDList.empty()){
    cout<<"\t-----------------------"<<endl;
    cout<<"\t|     MUSICCD LIST     |"<<endl;
    cout<<"\t-----------------------"<<endl<<endl;
    for(int i=0;i<m_musicCDList.size();i++){
      m_musicCDList[i]->printProperties();
    }
  }
  if(m_bookList.empty()&m_magazineList.empty()&m_musicCDList.empty()){
    cout<<"\tItem list is empty!"<<endl;
  }
}
void Menu::AddBook(){
  string name;
  double price;
  string author;
  string publisher;
  int page;
  cin.ignore();
  cout<<"Book name> ";
  getline(cin,name);
  cout<<"Book price> ";
  cin>>price;
  cin.ignore();
  cout<<"Book author> ";
  getline(cin,author);
  cout<<"Book publisher> ";
  getline(cin,publisher);
  cout<<"Book page> ";
  cin>>page;
  Book *book=new Book(m_bookList.size()*10+10,name,price,author,publisher,page);
  m_bookList.push_back(book);
}
void Menu::AddMagazine(){
  string name;
  double price;
  int issue;
  string type;
  cin.ignore();
  cout<<"Magazine name> ";
  getline(cin,name);
  cout<<"Magazine price> ";
  cin>>price;
  cin.ignore();
  cout<<"Magazine issue> ";
  cin>>issue;
  cin.ignore();
  cout<<"Magazine type> ";
  getline(cin,type);
  Magazine *magazine=new Magazine(m_magazineList.size()*10+11,name,price,issue,type);
  m_magazineList.push_back(magazine);
}
void Menu::AddMusicCD(){
  string name;
  double price;
  string singer;
  string type;
  cin.ignore();
  cout<<"MusicCD name> ";
  getline(cin,name);
  cout<<"MusicCD price> ";
  cin>>price;
  cin.ignore();
  cout<<"MusicCD singer> ";
  getline(cin,singer);
  cout<<"MusicCD type> ";
  getline(cin,type);
  MusicCD *musiccd=new MusicCD(m_musicCDList.size()*10+12,name,price,singer,type);
  m_musicCDList.push_back(musiccd);
}
void Menu::Login(){
  if(m_loggedIn){
    cout<<"\tYou are already logged in!"<<endl;
  }
  else{
    string username;
    string password;
    cin.ignore();
    cout<<"\tUsername> ";
    getline(cin,username);
    cout<<"\tPassword> ",
    getline(cin,password);
    for(int i=0;i<m_customerList.size();i++){
      if(m_customerList[i]->checkAccount(username, password)){
        m_loggedIn=true;
        m_shoppingCart=new ShoppingCart(m_customerList[i]);
        cout<<"\tSuccessfully logged in!"<<endl;
        return;
      }
    }
    cout<<"\tThere was an error while trying to login!"<<endl;
  }
}
void Menu::AddProduct(){
  if(m_loggedIn){
    ShowItems();
    long ID;
    cout<<"\tID> ";
    cin>>ID;
    int quantity;
    cout<<"\tQuantity> ";
    cin>>quantity;
    if(ID%10==0){
      for(int i=0;i<m_bookList.size();i++){
        if(ID==m_bookList[i]->getID()){
          m_shoppingCart->addProduct(m_bookList[i], quantity);
          return;
        }
      }
    }
    if(ID%10==1){
      for(int i=0;i<m_magazineList.size();i++){
        if(ID==m_magazineList[i]->getID()){
          m_shoppingCart->addProduct(m_magazineList[i], quantity);
          return;
        }
      }
    }
    if(ID%10==2){
      for(int i=0;i<m_musicCDList.size();i++){
        if(ID==m_musicCDList[i]->getID()){
          m_shoppingCart->addProduct(m_musicCDList[i], quantity);
          return;
        }
      }
    }
    cout<<"\tThere is no such product!"<<endl;
  }
  else{
    cout<<"\tYou should login first!"<<endl;
  }
}
void Menu::RemoveProduct(){
  if(m_loggedIn){
    ShowItems();
    long ID;
    cout<<"\tID> ";
    cin>>ID;
    int quantity;
    cout<<"\tQuantity> ";
    cin>>quantity;
    if(ID%10==0){
      for(int i=0;i<m_bookList.size();i++){
        if(ID==m_bookList[i]->getID()){
          m_shoppingCart->removeProduct(m_bookList[i], quantity);
          return;
        }
      }
    }
    if(ID%10==1){
      for(int i=0;i<m_magazineList.size();i++){
        if(ID==m_magazineList[i]->getID()){
          m_shoppingCart->removeProduct(m_magazineList[i], quantity);
          return;
        }
      }
    }
    if(ID%10==2){
      for(int i=0;i<m_musicCDList.size();i++){
        if(ID==m_musicCDList[i]->getID()){
          m_shoppingCart->removeProduct(m_musicCDList[i], quantity);
          return;
        }
      }
    }
    cout<<"\tThere is no such product!"<<endl;
  }
  else{
    cout<<"\tYou should login first!"<<endl;
  }
}
