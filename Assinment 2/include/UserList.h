#include<cstring>
#include<iostream>
#include <User.h>
#include<Book.h>
#include <string>
#ifndef USERLIST_H
#define USERLIST_H


class UserList
{
    private:
        User* users;
        int capacity;
        int usersCount=0;


    public:
         static bool ch;
         int arr_cnt=0;
         UserList();
         UserList(int capacity);
         UserList(const UserList& anotherList);
         void addUser(User user);
         User& searchUser(string name);
         User& searchUser(int id);
         void deleteUser(int id);
         friend ostream &operator<<( ostream &output, UserList &userList );
         int get_usersCount();
          ~UserList();
};

#endif // USERLIST_H
