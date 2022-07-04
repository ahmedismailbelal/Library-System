#include "UserList.h"
#include<cstring>
#include<iostream>
#include <User.h>
#include<Book.h>
#include <string>
bool UserList::ch=0;

UserList::UserList() // a default construtor
{

}
UserList::UserList(int cap) // a parametriz constructor
{
    capacity = cap;
    users = new User[capacity];
}

UserList::UserList(const UserList& anotherList) // a copy constroctor
{
    capacity = anotherList.capacity;
    for(int i=0; i<usersCount; i++)
    {
        users[i]=anotherList.users[i];
    }
    arr_cnt = anotherList.arr_cnt;
}

void UserList:: addUser(User user) // a fun to add a user to the user list
{
    users[usersCount] = user;
    usersCount ++;
    User::Count++;
    arr_cnt++;
}

User& UserList::searchUser(string name) // to find a user by the name
{
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getName() == name)
        {
            return users[i];
        }
    }
}

User& UserList::searchUser(int id) // to find a user by the id
{
    ch=0;
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId() == id)
        {
            ch =1;
            return users[i];
        }
    }

}

void UserList::deleteUser(int id) // to delete a user
{
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId() == id)
        {
             arr_cnt--;
            for(int j=i; j<arr_cnt; j++)
            {
                delete (users+j);
                users[j] = users[j+1];
            }
        }

    }
}
int UserList::get_usersCount() //to return the users numbers from the list
{
    return usersCount;
}
ostream & operator<<( ostream &output, UserList &userList ) // an operator overloading to get the output
{
    for(int i=0; i< userList.arr_cnt; i++)
    {
        output << userList.users[i];
    }
    return output;
}

UserList::~UserList() // a deconstructor to delete a dynamic array
{
    delete [] users;
}
