
#include<string>
#include<iostream>
using namespace std;

class BST_node
{
  public:
      BST_node *left;
      BST_node *right;
      string  name;
      string address;
      string password;
      long long account_no;
      long long phone_no;
      int balance;
      BST_node();
      BST_node(string,string,string,long long,long long,int);
};

