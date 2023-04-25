#include<iostream>
#include<conio.h>
using namespace std;

void customer()
{
    BST_tree t;
    t.load_server();
    BST_node *temp;
    long long acc;
    string password;

    //authentication of user
    cout<<"Enter account no : ";
    cin>>acc;
    //checking account no is correct or not
    if(t.check_account_no_is_unique(acc))
    {
        cout<<"Account no is not correct";
        getch();
        return;
    }
    cout<<"Enter password : ";
    cin>>password;
    temp=t.search(t.get_root(),acc);
    if(temp->password != password)
    {
        cout<<"The password is not correct";
        getch();
        return;
    }

    while(true)
    {
        system("cls");
        int choice;
        int amou;
        cout<<"#### Welcome "<<temp->name <<" ####"<<endl;
        cout<<"1.withdraw"<<endl;
        cout<<"2.deposit"<<endl;
        cout<<"3.transfer"<<endl;
        cout<<"4.Balance"<<endl;
        cout<<"5.check account details"<<endl;
        cout<<"6.change password"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        system("cls");

        if(choice == 1)
        {

          cout<<"Enter amount to withdraw : ";
          cin>>amou;
          if(!t.is_amount_less(acc,amou))
          {
              cout<<"Amount should be less than your current balance";
          }else{
              t.withdraw(acc,amou);
              cout<<"withdrawal is successfully : ";
          }
          //updating BST tree
          t.updating_root();
          t.load_server();
        }
        else if(choice == 2)
        {

              cout<<"Enter amount to deposit : ";
              cin>>amou;
              t.deposit(acc,amou);
              cout<<"deposit successfully";
              //updating BST tree
              t.updating_root();
              t.load_server();
        }
        else if(choice == 3){
           long long receiver_acc;
           cout<<"Enter receiver account no : ";
           cin>>receiver_acc;
           if(t.check_account_no_is_unique(receiver_acc))
           {
               cout<<"The receiver account no is not correct";
               getch();
               continue;
           }
           temp=t.search(t.get_root(),acc);
           cout<<"Enter amount to transfer : ";
           cin>>amou;
           if(temp->balance < amou)
           {
               cout<<"You cannot transfer money more than "<<temp->balance;
           }
           else{
               t.transfer_money(acc,receiver_acc,amou);
               cout<<"Money transfer successfully";
           }
           //updating BST tree
           t.updating_root();
           t.load_server();
        }
        else if(choice == 4)
        {
            temp=t.search(t.get_root(),acc);
            cout<<"your balance "<<temp->balance;
        }
        else if(choice == 5)
        {
            t.printInformation(acc);
        }
        else if(choice == 6)
        {
            string ps;
            cout<<"Enter new password : ";
            cin>>ps;
            t.change_password(acc,ps);
            cout<<"password successfully chnaged";

           //updating BST tree
           t.updating_root();
           t.load_server();
        }
        getch();
    }

}
