#include<iostream>
#include<string>
using namespace std;

class User;
class Member;
class Items;
class PhysicalItems;
class SoftwareItems;
struct Requests;

struct itemstaken
{
    string name_of_item;
    int num_items;
};

class User
{
    protected:
        string full_name;
        int age;
    
};

class Member : public User
{
    public:
        string username,password;
        itemstaken itmtkn[50];
        int num_items_taken;

        void get_info()
        {
            cout<<"Enter your name: ";
            cin>>full_name;
            cout<<"Enter age: ";
            cin>>age;
        }

        void show_info()
        {
            cout<<"\n------------------------\n";
            cout<<"Name: "<<full_name<<endl;
            cout<<"Username: "<<username<<endl;
            cout<<"------------------------\n";
        }
    
};

class Items
{
    public:
        string itemname;
        int quantity;
        virtual void item_info()=0;

};

class PhysicalItems : public Items
{
    public:
        void item_info()
        {
            cout<<"----------------------------\n";
            cout<<"Item Name: "<<itemname<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            if (quantity<=10)
                cout<<"Quantity running low!\n";
            cout<<"----------------------------\n";
        }
};

class SoftwareItems : public Items
{
    public:
        void item_info()
        {
            cout<<"----------------------------\n";
            cout<<"Item Name: "<<itemname<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            if (quantity<=20)
                cout<<"Quantity running low!\n";
            cout<<"----------------------------\n";
        }
};

struct Requests
{
    string username;
    string request;
};
