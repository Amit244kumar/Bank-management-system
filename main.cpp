#include <iostream>
#include "admin.h"
#include "customer.h"
using namespace std;

int main()
{
    int choice;
    while(true)
    {
        cout<<"1.Enter as admin"<<endl;
        cout<<"2.Enter as customer"<<endl;
        cout<<"3.exit"<<endl;
        cin>>choice;
        if(choice==1)
        {
           admin();
        }
        else if(choice == 2)
        {
              customer();
        }
        else if(choice == 3)
        {
            exit(0);
        }
        system("cls");
    }
    return 0;
}
