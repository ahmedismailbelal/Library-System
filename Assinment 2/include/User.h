#ifndef USER_H
#define USER_H
#include<string>
using namespace std;

class User
{
    private:
         string name;
         int age=0;
         int ID=0;
         string password;
         string email;

    public:
        friend class Book;
        void settest(int Id);
        int gettest();
        static int Count;
        User();
        ~User();
        User(string u_name, int u_age,  string u_email, string u_password);
        User(const User&user);
        bool operator == (const User& obj);
        void setName(string s);
       string getName() const;
       void setPassword(string pass);
        string getPassword();
        void setEmail(string Email);
        string getEmail();
        void setAge(int Age);
        int getAge();
        void setId(int user_id);
        int getId();
        friend ostream &operator<<(ostream &output, const User &user );
        friend istream &operator>>( istream &input, User &user );


};

#endif // USER_H
