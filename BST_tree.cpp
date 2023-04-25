#include "BST_tree.h"

#include<iostream>
#include<fstream>
#include<iostream>
using namespace std;
BST_tree::BST_tree()
{
    Root=nullptr;
}
int BST_tree::get_last_id()
{
    int i=0;
    ifstream read;
    read.open("D:/my documents/bank_management/customer_account_id.txt",ios::in);
    while(!read.eof())
    {
        read>>i;
    }
    read.close();
    return ++i;
}
void BST_tree::add_account(string name,string address,string password,long long phoneNo,long long accountNo,int balance)
{
    ofstream write;

    write.open("D:/my documents/bank_management/customer_account_id.txt",ios::app | ios::out);
    int i=get_last_id();
    write<< i <<endl;
    write.close();


    write.open("D:/my documents/bank_management/customer_account.txt",ios::app|ios::out);
    write<< i << endl << accountNo<< endl << name << endl << address << endl << phoneNo << endl << password << endl << balance << endl;
    write.close();


}


void BST_tree::load_server()
{
    if(Root)return;
    int id=0;
    fstream read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::app|ios::in);
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {

        //reading data from file

        read>>account_no;
        read.ignore();
        getline(read,name);
        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;
       // cout<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance<<endl;

        if(account_no != 0 && name != "" && address != "" && phone_no != 0 && password != "")
        {

            BST_node *node = new BST_node(name,address,password,account_no,phone_no,balance);
            BST_node *current;
            if(Root == nullptr)
            {
                Root=node;
            }
            else{
                current=Root;
                while(true)
                {
                    if(current->account_no > account_no)
                    {

                        //got to left
                        if(current->left == nullptr)
                        {
                            current->left=node;
                            break;
                        }

                        current=current->left;
                    }
                    else{

                        //got to right
                        if(current->right == nullptr)
                        {
                            current->right=node;
                            break;
                        }

                        current=current->right;
                    }
                }
            }
        }
        read>>id;
    }
    read.close();

}


bool BST_tree::check_account_no_is_unique(long long account_no)
{
    BST_node *current;
    if(Root == nullptr)
    {
        return true;
    }
    else{
        current=Root;
        while(true)
        {
            if(current->account_no == account_no)
            {
                return false;
            }
            else if(current->account_no > account_no)
            {
                //go to left
                if(current->left == nullptr)
                {
                    return true;
                }
                current=current->left;
            }
            else{
                //go to right
                if(current->right ==nullptr)
                {
                    return true;
                }
                current=current->right;
            }
        }
    }
}

void BST_tree::print(BST_node *root)
{

    if(root)
    {
        print(root->left);
        cout<<root->account_no;
        print(root->right);
    }
}

void BST_tree::edit_account(long long acc,string n,string addr,long long ph)
{
    fstream write,read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {

        //reading data from file

        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(account_no == acc)
        {
            if(n != "")
            {
                 write<< id << endl << account_no<< endl << n << endl << address << endl << phone_no << endl << password << endl << balance << endl;
            }
            else if(addr != ""){
               write<< id << endl << account_no<< endl << name << endl << addr << endl << phone_no << endl << password << endl << balance << endl;
            }
            else if(ph){
                 write<< id << endl << account_no<< endl << name << endl << address << endl << ph << endl << password << endl << balance << endl;
            }

        }
        else{
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
    read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}


void BST_tree::delete_account(long long acc)
{
    fstream write,read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {

        //reading data from file

        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(account_no != acc)
        {
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
    read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}

//these methods related to customers
bool BST_tree::is_amount_less(long long account_no,int amount)
{
    BST_node *current;
    current=Root;
    while(true)
    {
        if(current->account_no == account_no)
        {
            return current->balance>=amount?true:false;

        }
        else if(current->account_no > account_no)
        {
            //go to left
            current=current->left;
        }
        else{
            //go to right
            current=current->right;
        }
    }
}

void BST_tree::withdraw(long long acc,int amount)
{
    fstream write,read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {

        //reading data from file

        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(account_no == acc)
        {
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance-amount << endl;
        }
        else{
             write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
       read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}
void BST_tree::deposit(long long account,int amount)
{
    fstream write,read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {

        //reading data from file

        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(account_no == account)
        {
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance+amount << endl;
        }
        else{
             write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
       read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}

void BST_tree::transfer_money(long long sender_account,long long receiver_account,int amount)
{
//    updating_transaction(sender_account,receiver_account,amount);
    fstream write,read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {
        //reading data from file
        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(sender_account == account_no)
        {
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance-amount << endl;
        }
        else if(receiver_account == account_no){
             write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance+amount << endl;
        }
        else{
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
       read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}
/*
void updating_transaction(long long sa,long ra,int am)
{
    fstream write,read;
    read.open("D:/my documents/bank_management/transaction_history.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {
        //reading data from file
        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(sender_account == account_no)
        {
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance-amount << endl;
        }
        else if(receiver_account == account_no){
             write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance+amount << endl;
        }
        else{
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
       read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}
*/
BST_node* BST_tree::search(BST_node *root,long long account)
{
    if(root != nullptr)
    {
        if(root->account_no == account)
        {
            return root;
        }
        else if(root->account_no > account)
        {
            return search(root->left,account);
        }
        else{
            return search(root->right,account);
        }
    }
    return nullptr;
}
//Returning root of tree
BST_node* BST_tree::get_root(){return Root;}

//Assigning nullptr to root
void BST_tree::updating_root(){Root=nullptr;}

void BST_tree::printInformation(long long acc)
{
    BST_node *temp;
    temp=search(get_root(),acc);
    cout<<"name : "<<temp->name<<endl;
    cout<<"balance : "<<temp->balance<<endl;
    cout<<"account no : "<<temp->account_no<<endl;
    cout<<"address : "<<temp->address<<endl;
    cout<<"phone no : "<<temp->phone_no<<endl;
    cout<<"password : "<<temp->password<<endl;
}



void BST_tree::change_password(long long acc,string new_password)
{
    fstream write,read;
    read.open("D:/my documents/bank_management/customer_account.txt",ios::in);
    write.open("D:/my documents/bank_management/temp.txt",ios::out);
    int id;
    string name="";
    string address="";
    string password="";
    long long account_no=0;
    long long phone_no=0;
    int balance;
    read>>id;
    while(!read.eof())
    {
        //reading data from file
        read>>account_no;
        read.ignore();
        getline(read,name);

        getline(read,address);
        read>>phone_no;
        read>>password;
        read>>balance;

        if(account_no == acc)
        {
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << new_password << endl << balance << endl;
        }
        else{
            write<< id << endl << account_no<< endl << name << endl << address << endl << phone_no << endl << password << endl << balance << endl;
        }
       read>>id;
    }
    read.close();
    write.close();
    remove("D:/my documents/bank_management/customer_account.txt");
    rename("D:/my documents/bank_management/temp.txt","D:/my documents/bank_management/customer_account.txt");
}

