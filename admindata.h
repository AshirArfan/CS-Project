#include<iostream>
#include<string>
#include"class_data.h"

using namespace std;

// Funtion Prototype

void check_new_member_req(Member* memberreq,int& user_req,Member* members,int& num_members);
void check_all_members(Member* members,int& num_members);
void remove_member(Member* members,int& num_members);
void check_inventory(Items* item[],int num_item);
void restock_inventory(Items* item[],int num_item);
void check_item_req(Requests* item_reqs,int& num_item_reqs,Member* members,int& num_members);
void change_password(string& pass);

// Functions

void check_inventory(Items* item[],int num_item)
{
    for (int i = 0; i < num_item; i++)
    {
        item[i]->item_info();
    }
    
}

void restock_inventory(Items* item[],int num_item)
{
    check_inventory(item,5);
    cout<<"\nEnter Item Name: ";
    string name;
    cin>>name;

    for (int i = 0; i < 5; i++)
    {
        if(name==item[i]->itemname)
        {
            cout<<"Quantity: "<<item[i]->quantity<<endl;
            cout<<"Enter Quantity you want to add: ";
            int num;
            cin>>num;
            item[i]->quantity+=num;
            cout<<"Quantity Updated Successfully.\n";
            return;
        }
    }
    cout<<"Item not found.\n";
    
}

void change_password(string& pass)
{
    cout<<"Enter new pass: ";
    cin>>pass;
}

void remove_member(Member* members,int& num_members)
{
    check_all_members(members,num_members);
    cout<<"\nEnter username: ";
    string name;
    cin>>name;

    for (int i = 0; i < num_members; i++)
    {
        if(members[i].username==name)
        {
            for (int j = 0; j < num_members-1; j++)
            {
                members[j]=members[j+1];
                num_members--;
                cout<<"Member removed successfully.\n";
                return;
            }
            
        }
    }
    cout<<"Username not found.\n";
    
}

void check_all_members(Member* members,int& num_members)
{
    for (int i = 0; i < num_members; i++)
    {
        members[i].show_info();
    }
    
}

void check_item_req(Requests* item_reqs,int& num_item_reqs,Member* members,int& num_members)
{
    if (item_reqs==0)
    {
        cout<<"No item requests.\n";
        return;
    }
    for (int i = 0; i < num_item_reqs; i++)
    {
        cout<<item_reqs[i];
    }
    if (num_item_reqs==0)
    {
        cout<<"No requests.\n";
        return;
    }
    

    cout<<"Enter Item name: ";
    string name;
    cin>>name;

    for (int i = 0; i < num_item_reqs; i++)
    {
        if(name==item_reqs[i].item_name)
        {
            cout<<"Do you want to approve or reject this Request(A/R): ";
            char option;
            cin>>option;
            if (option=='R'){}
            else
            {
                for (int j = 0; j < num_members; j++)
                {
                    if (item_reqs[i].username==members[j].username)
                    {
                        members[j].itmtkn[members[j].num_items_taken].name_of_item=item_reqs[i].item_name;
                        members[j].itmtkn[members[j].num_items_taken].num_items=item_reqs[i].num_items;
                        members[j].num_items_taken++;
                        for (int k = i; k < num_item_reqs-1; k++)
                        {
                            item_reqs[j]=item_reqs[j+1];
                        }
                        num_item_reqs--;
                        cout<<"Request Approved.\n";
                        return;
                    }
                    
                }
                
                
            }
            
        }
    }
    cout<<"Item not found.\n";
}

void check_new_member_req(Member* memberreq,int& user_req,Member* members,int& num_members)
{
    if(user_req==0)
    {
        cout<<"No requests.\n";
    }
    for (int i = 0; i < user_req; i++)
    {
        memberreq[i].show_info();
    }

    cout<<"Enter Username: ";
    string username;
    cin>>username;

    for (int i = 0; i < user_req; i++)
    {
        if(username==memberreq[i].username)
        {
            cout<<"Do you want to approve or reject this member(A/R): ";
            char option;
            cin>>option;
            if (option=='R'){}
            else
            {
                members[num_members]=memberreq[i];
                num_members++;
                
            }
            for (int j = i; j < user_req-1; j++)
                {
                    memberreq[j]=memberreq[j+1];
                }
                user_req--;
                return;
        }
    }
    
    
}