#include<iostream>
#include "BST_tree.h"
using namespace std;
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<string>
#include<stdio.h>
#include<conio.h>

//these method related to admin
string generate_password()
{
    const string charset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    string password="";

    srand(time(0));

    for(int i=0;i<5;i++)
    {
        password+=charset[rand()%charset.length()];
    }
    return password;
}

long long  generate_account_no()
{
    while(true)
    {
        srand(time(NULL));
        stringstream ss;
        string random_number;
        long long acc;
        for (int i = 0; i < 8; i++) {
            ss << rand() % 10;
        }
        ss >> random_number;
        acc=stoi(random_number);
        return acc;
    }
}

void admin()
{
     system("cls");
     int choice;
     long long acc,ph;
     int bal;
     string a,ad,pass,admin_pass;
     BST_tree t;

     //Admin authentication
     cout<<"Enter password : ";
     cin>>admin_pass;
     if(admin_pass != "admin123")
     {
         cout<<"admin password is wrong ";
         getch();
         return ;
     }

     while(true)
     {
        system("cls");
        cout<<"1.add account"<<endl;
        cout<<"2.edit account"<<endl;
        cout<<"3.delete account"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;
        t.load_server();
        if(choice == 1)
        {
            cout<<"Enter name : ";
            cin.ignore();
            getline(cin,a);
            cout<<"Enter address : ";

            getline(cin,ad);
            cout<<"Enter phone no : ";
            cin>>ph;
            cout<<"Enter balance : ";
            cin>>bal;
            while(true)
            {
                //checking account no is unique
                acc=generate_account_no();
                if(t.check_account_no_is_unique(acc))
                {

                   break;
                }
            }
            pass=generate_password();
            t.add_account(a,ad,pass,ph,acc,bal);
            cout<<"Account added successfuly";
            //updating BST tree
           t.updating_root();
           t.load_server();
        }
        else if(choice  == 2)
        {
              system("cls");
              cout<<"Enter account no";
              cin>>acc;
              //checking account no exit in database or not
              if(t.check_account_no_is_unique(acc))
              {
                 cout<<"account doest not exits";
                 getch();
                 continue;
              }
              cout<<"what you want to change "<<endl;
              cout<<"1.change name"<<endl;
              cout<<"2.change address"<<endl;
              cout<<"3.change phone no"<<endl;
              cout<<"Enter your choice : ";
              cin>>choice;
              if(choice ==1 )
              {
                  cout<<"Enter name : ";
                  cin.ignore();
                  getline(cin,a);
                  t.edit_account(acc,a,"",0);
                  cout<<"You have successfully change name ";
              }
              else if(choice == 2)
              {
                  cout<<"Enter address : ";
                  cin.ignore();
                  getline(cin,ad);
                  t.edit_account(acc,"",ad,0);
                  cout<<"You have successfully change address ";
              }
              else{
                  cout<<"Enter phone no : ";
                  cin>>ph;
                  t.edit_account(acc,"","",ph);
                  cout<<"You have successfully change phone no ";
              }
              getch();
              //updating BST tree
              t.updating_root();
              t.load_server();
        }
        else if(choice == 3)
        {
              system("cls");
              cout<<"Enter account no";
              cin>>acc;
              //checking account no exit in database or not
              if(t.check_account_no_is_unique(acc))
              {
                 cout<<"account doest not exits";
                 getch();
                 continue;
              }
              t.delete_account(acc);
              cout<<"Account deleted successfully";
              getch();
              //updating BST tree
              t.updating_root();
              t.load_server();
        }
        else{
            return;
        }

     }
}
