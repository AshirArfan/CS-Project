#include<iostream>
#include<string>
#include"admindata.h"
using namespace std;

// Function prototypes
void new_member_req(Member* memberreq,int& user_req,Member* members,int& num_members);
int existing_member_check(Member* members,int& num_members);
void get_items();
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
