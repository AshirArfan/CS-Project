#include<iostream>
#include<string>
using namespace std;

class User;
class Member;
class Items;
class PhysicalItems;
class SoftwareItems;
class Requests;

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

        Member()
        {
            num_items_taken=0;
        }

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
            cout<<"\n----------------------------\n";
            cout<<"Item Name: "<<itemname<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            if (quantity<=10)
                cout<<"Quantity running low!\n";
            cout<<"----------------------------\n\n";
        }
};

class SoftwareItems : public Items
{
    public:
        void item_info()
        {
            cout<<"\n----------------------------\n";
            cout<<"Item Name: "<<itemname<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            if (quantity<=20)
                cout<<"Quantity running low!\n";
            cout<<"----------------------------\n\n";
        }
};

class Requests
{
    public:
    string username;
    string item_name;
    int num_items;

    friend ostream& operator<<(ostream& out,const Requests obj)
    {
        out<<"\nUsername: "<<obj.username<<endl;
        out<<"Item: "<<obj.item_name<<endl;
        out<<"Quantity: "<<obj.num_items<<endl;
    }
};
