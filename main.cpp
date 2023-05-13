#include<iostream>
#include"admindata.h"
using namespace std;

string AdminPass="abc12345";

int main()
{
    Member memberreq[20];
    Member members[50];
    Requests item_reqs[10];

    int num_members=0;
    int user_reqs=0;
    int num_item_req=0;

    Items* item[5];
    for (int i = 0; i < 2; i++)
    {
        item[i]=new PhysicalItems;
        item[i]->quantity=30;
    }
    
    for (int i = 2; i < 5; i++)
    {
        item[i]=new SoftwareItems;
        item[i]->quantity=50;
    }

    item[0]->itemname="Laptop";
    item[1]->itemname="Printer";
    item[2]->itemname="Anydesk License";
    item[3]->itemname="Microsoft 365 License";
    item[4]->itemname="Windows 11 License";

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
                cout<<"2. Check All members.\n";
                cout<<"3. Remove a member.\n";
                cout<<"4. Check Inventory.\n";
                cout<<"5. Restock Inventory.\n";
                cout<<"6. Check Item Requests.\n";
                cout<<"7. Change Admin Password.\n";
                cout<<"8. Exit.\n";
                cout<<"Enter: ";
                
                int admin_options;
                cin>>admin_options;

                switch (admin_options)
                {
                case 1:
                    /* code */
                    break;
                
                case 2:
                    check_all_members(members,num_members);
                    break;
                
                case 3:
                    remove_member(members,num_members);
                    break;
                
                case 4:
                    check_inventory(item,5);
                    break;
                
                case 5:
                    restock_inventory(item,5);
                    break;
                
                case 6:
                    /* code */
                    break;
                
                case 7:
                    change_password(AdminPass);
                    break;
                
                case 8:
                    /* code */
                    break;
                
                default:
                    break;
                } 
            }
        }
        break;

        case 2:
        
    
    default:
        break;
    }
}