#include<iostream>
#include<string>
#include"class_data.h"

using namespace std;

// Funtion Prototype

void check_new_member_req();
void check_all_members(Member* members,int& num_members);
void remove_member(Member* members,int& num_members);
void check_inventory(Items* item[],int num_item);
void restock_inventory(Items* item[],int num_item);
void check_item_req(Requests* item_reqs,int& num_item_reqs);
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

void check_item_req(Requests* item_reqs,int& num_item_reqs)
{
    for (int i = 0; i < num_item_reqs; i++)
    {
        cout<<"Username: "<<item_reqs[i].username<<endl;
        cout<<"Request: "<<item_reqs[i].request<<endl;
    }
    
}