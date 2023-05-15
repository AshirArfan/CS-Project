#include<iostream>
#include<string>
#include"admindata.h"
using namespace std;

// Function prototypes
void new_member_req(Member* memberreq,int& user_req,Member* members,int& num_members);
int existing_member_check(Member* members,int& num_members);
void get_items(Requests* item_reqs,int& num_item_req,Items* item[],int num_item,Member* members,int& num_members);

// Functions
void new_member_req(Member* memberreq,int& user_req,Member* members,int& num_members)
{
    if(user_req==20)
    {
        cout<<"Max request limit reached. Please try again later.\n";
        return;
    }
    memberreq[user_req].get_info();
    string username;
    while (true)
    {
        char username_check='Y';
        cout<<"Enter username: ";
        cin>>username;
        for (int i = 0; i < num_members; i++)
        {
            if(username==members[i].username)
            {
                cout<<"Username already taken.\n";
                username_check='N';
            }
        }
        if (username_check=='N')
            continue;
        cout<<"Enter password: ";
        cin>>memberreq[user_req].password;
        user_req++;
        cout<<"Request added successfully. Admin will review your request.\n";
        return;
    }
    
}

int existing_member_check(Member* members,int& num_members)
{
    cout<<"Enter username: ";
    string username;
    cin>>username;
    cout<<"Enter Password: ";
    string password;
    cin>>password;

    for (int i = 0; i < num_members; i++)
    {
        if(members[i].username==username && members[i].password==password)
        {
            cout<<"User Found.\n";
            return 1;
        }
    }
    cout<<"User not found.\n";
    return 0;
    
}

void get_items(Requests* item_reqs,int& num_item_req,Items* item[],int num_item,Member* members,int& num_members)
{
    check_inventory(item,5);

    cout<<"Enter item name: ";
    string name;
    cin>>name;
    char check='Y';

    for (int i = 0; i < num_item; i++)
    {
        if (name==item[i]->itemname)
        {
            cout<<"Enter quantity: ";
            int quantity;
            cin>>quantity;
            if (quantity>item[i]->quantity)
            {
                cout<<"Not enough items avalible.\n";
                cout<<"Do you want to put in a request for following items?(Y/N): ";
                char option;
                cin>>option;
                if (option=='N')
                {
                    return;
                }
                else
                {
                    cout<<"Enter your username: ";
                    string username;
                    cin>>username;
                    for (int j = 0; j < num_members; j++)
                    {
                        if (username==members[j].username)
                        {
                            item_reqs[num_item_req].username=username;
                            item_reqs[num_item_req].item_name=item[i]->itemname;
                            item_reqs[num_item_req].num_items=quantity;
                            num_item_req++;
                            cout<<"Request added successfully.\n";
                            return;
                        }
                        
                    }
                    cout<<"Username not found.\n";
                    return;
                }
                
            }
            else
            {
                cout<<"Enter your username: ";
                string username;
                cin>>username;
                for (int j = 0; j < num_members; j++)
                {
                    if(username==members[j].username)
                    {
                        members[j].itmtkn[members[j].num_items_taken].name_of_item=item[i]->itemname;
                        members[j].itmtkn[members[j].num_items_taken].num_items=item[i]->quantity;
                        members[j].num_items_taken++;
                        item[i]->quantity-=quantity;
                        cout<<"Item bought Successfully.\n";
                        return;

                    }
                }
                cout<<"Username not found.\n";
                return;
            }
            
        }
    }
    cout<<"Item not found.\n";
}