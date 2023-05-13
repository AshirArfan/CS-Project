#include<iostream>
#include"class_data.h"
using namespace std;

string AdminPass="abc12345";

int main()
{
    Member memberreq[20];
    Member members[50];
    Items item[50];
    Requests item_reqs[10];

    int num_members=0;
    int num_items=0;
    int user_reqs=0;


    cout << "\t\tWelcome to ABC's Inventory\n";
    cout<<"\n\nLogin as: ";
    cout <<"\n1. Admin.\n2. Member\n3. Exit";
    cout<<"Enter: ";
    
    int option;
    cin>>option;

    switch (option)
    {
    case 1:
        {
            cout<<"Enter Pasword: ";
            string pass;
            cin>>pass;

            if (pass==AdminPass)
            {
                cout<<"Welcome to Admin Pannel\n";
                cout<<"\n1. Check new members requests.\n";
                cout<<"2. Remove a member.\n";
                cout<<"3. Check Inventory.\n";
                cout<<"4. Restock Inventory.\n";
                cout<<"5. Check Requests.\n";
                cout<<"6. Change Admin Password.\n";
                cout<<"7. Exit.\n";
                cout<<"Enter: ";
                
                int admin_options;
                cin>>admin_options;

                switch (admin_options)
                {
                case 1:
                    /* code */
                    break;
                
                case 2:
                    /* code */
                    break;
                
                case 3:
                    /* code */
                    break;
                
                case 4:
                    /* code */
                    break;
                
                case 5:
                    /* code */
                    break;
                
                case 6:
                    /* code */
                    break;
                
                case 7:
                    /* code */
                    break;
                
                default:
                    break;
                } 
            }
        }
        break;
    
    default:
        break;
    }
}