#include<iostream>
#include"userdata.h"
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
    system("pause");
    while (true)
    {
        system("cls");
        cout<<"\n\nLogin as: ";
        cout <<"\n1. Admin.\n2. Member\n3. Exit\n";
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
                    while(option!=-1)
                    {
                        system("cls");
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
                            check_new_member_req(memberreq,user_reqs,members,num_members);
                            system("pause");
                            break;
                        
                        case 2:
                            check_all_members(members,num_members);
                            system("pause");
                            break;
                        
                        case 3:
                            remove_member(members,num_members);
                            system("pause");
                            break;
                        
                        case 4:
                            check_inventory(item,5);
                            system("pause");
                            break;
                        
                        case 5:
                            restock_inventory(item,5);
                            system("pause");
                            break;
                        
                        case 6:
                            check_item_req(item_reqs,num_item_req,members,num_members);
                            system("pause");
                            break;
                        
                        case 7:
                            change_password(AdminPass);
                            system("pause");
                            break;
                        
                        case 8:
                            option=-1;
                            break;
                        
                        default:
                            cout<<"Invalid Option.\n";
                            system("pause");
                            break;
                    }} 
                }
                else
                {
                    cout<<"Wrong Password.\n";
                    system("pause");
                } 
            }
            break;

            case 2:

                while(option!=-1)
                {
            
                    system("cls");       
            
                    cout<<"1. Existing User?\n2. New User\n3. Exit\nEnter: ";
                    int memberoption;
                    cin>>memberoption;
            
                    switch (memberoption)
                    {
                    case 1:
            
                        if (existing_member_check(members,num_members))
                        {
            
                            while(option!=-1)
                            {
                                system("cls");
            
                                cout<<"Welcome to members Pannel.\n";
                                cout<<"1. Get items\n2. Exit\nEnter: ";
            
                                int member_option;
                                cin>>member_option;
            
                                switch (member_option)
                                {
                                case 1:
            
                                    get_items(item_reqs,num_item_req,item,5,members,num_members);
                                    system("pause");
                                    break;
                                
                                case 2:
                                    option=-1;
                                    break;
                                
                                default:
                                    cout<<"Invalid Option.\n";
                                    system("pause");
                                    break;
            
                            }}
                        }
                        break;
                    
                    case 2:
                        new_member_req(memberreq,user_reqs,members,num_members);
                        
                        system("pause");
                        option=-1;
                        
                        break;

                    case 3:
                        option=-1;
                        break;

                    default:
                        cout<<"Invalid Option.\n";
                        system("pause");
                        break;
                }}
            break;
        
            case 3:
                cout<<"Exiting...\n";
                return 0;
                break;
        default:
        
            cout<<"Invalid Option.\n";
            system("pause");
            break;
    }}
}