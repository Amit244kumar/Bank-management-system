#include "BST_node.h"

class BST_tree
{
  private:
    BST_node *Root=nullptr;
  protected:
    int get_last_id();
  public:
  BST_tree();

  //These methods can be use by admin
  void add_account(string,string,string,long long,long long,int);
  void edit_account(long long,string,string,long long);
  void delete_account(long long);

  //These methods can be use by customers;
  void withdraw(long long,int);
  void deposit(long long,int);
  void transaction_history();
  void transfer_money(long long,long long,int);
  void printInformation(long long);
  void change_password(long long,string);

  //this method can be use by system
  void load_server();
  bool check_account_no_is_unique(long long);
  void print(BST_node*);
  bool is_amount_less(long long,int);
  BST_node* search(BST_node*,long long );
  BST_node* get_root();
  void updating_root();

};



