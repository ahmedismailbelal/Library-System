#include "User.h"
#include <string>
#include<iostream>
using namespace std;
int User::Count =1;
User::User() //the default constrictor
{
    ID = Count;
}
User::User(string u_name, int u_age, string u_email, string u_password) // the constrictor that takes initial values
{
    name = u_name;
    age = u_age;
    email=u_email;
    password = u_password;
    Count ++;


}
User::User(const User&user) // the copy constrictor
{
    name=user.name;
    age=user.age;
    email = user.email;
    password = user.password;
    ID = user.ID;
}
bool User::operator == (const User& obj) // the function that compare between the objects to make sure that there is no identical values
{
    bool status;
    if(name == obj.name && age == obj.age && ID==obj.ID && email == obj.email)
        status = 1;
    else
        status =0;
}
void User::setName(string s) //funs to set and get the private members
{
    name =s;
}
string User::getName() const
{
    return name;
}
void User::setPassword(string pass)
{
    password = pass;
}
string User::getPassword()
{
    return password;
}
void User::setEmail(string Email)
{
    email = Email;
}
string User::getEmail()
{
    return email;
}
void User::setAge(int Age)
{
    age = Age;
}
int User::getAge()
{
    return age;
}
void User::setId(int user_id)
{
    ID=user_id;
}
int User::getId()
{
    return ID;
}

ostream &operator<<(ostream &output, const User &user ) // a overloading operator to get the output
{
    output<< "=======User "  << user.ID<<  " Info========" << endl;
    output << "Name: " << user.name << endl;
    output << "Age: " << user.age << endl;
    output << "ID: " << user.ID << endl;
    output <<  "Email: " << user.email << endl;
     cout << "====================================\n" << endl;
    return output;
}
istream &operator>>( istream &input, User &user ) // a overloading operator to get the input
{
    user.ID = user.Count;
    input >> user.name >> user.age >> user.email >> user.password;
    return input;
}
User::~User() // a deconstructor
{

}
