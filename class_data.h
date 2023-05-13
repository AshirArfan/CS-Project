#include<iostream>
#include<string>
using namespace std;

class User;
class Member;
class Items;
struct Requests;

class User
{
    protected:
        string full_name;
        int age;
    
};

class Member : public User
{
    public:
        string username,password,req;
    
};

class Items
{
    public:
        string itemname;
        int quantity;

        void item_info()
        {
            cout<<"----------------------------\n";
            cout<<"Item Name: "<<itemname<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            cout<<"----------------------------\n";
        }
};

struct Requests
{
    string username;
    string request;
};