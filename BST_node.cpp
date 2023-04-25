#include "BST_node.h"
#include<string>
#include<iostream>
using namespace std;
BST_node::BST_node()
{
     right=left=nullptr;
     name="";
     address="";
     phone_no=0;
     account_no=0;
     balance=0;
     password="";
}
BST_node::BST_node(string name,string address,string password, long long accountNo,long long phoneNo,int balance)
{
    left=nullptr;
    right=nullptr;
    this->name=name;
    this->address=address;
    this->account_no=accountNo;
    this->phone_no=phoneNo;
    this->balance=balance;
    this->password=password;
}
