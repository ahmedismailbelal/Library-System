#include "Book.h"
#include <string>
#include<iostream>
using namespace std;
int Book::Count =1;
Book::Book()
{
     id = Count;
}
Book::Book(string tit, string is, string cat) // a paramertriz constructor
{
    title =tit;
    isbn = is;
    category = cat;
    Count++;

}
Book::Book(const Book& book) // a copy constructor
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    id= book.id;
    author = book.author;
}
void Book::setTitle(string tit)//funs to set and get the date from the user
{
    title =tit;
}
string Book::getTitle()
{
    return title;
}
void Book::setISBN(string is)
{
    isbn = is;
}
string Book::getISBN()
{
    return isbn;
}
void Book::setId(int Id)
{
    id=Id;
}
int Book::getId()
{
    return id;
}
void Book::setCategory(string cat)
{
      category = cat;
}
string Book::getCategory()
{
    return category;
}
void Book::setAuthor(User user)
{
    author = user;
   /* author.setAge(user.getAge()) ;
    author.setName(user.getName());
    author.setPassword(user.getPassword());
    author.setEmail(user.getEmail());
    author.setId(user.getId());*/
}
User Book::getAuthor() // to get the info about the auther
{
   cout << "=======Book Author Info=======" << endl;
   cout << "Name: " << author.name << " ";
   cout << "Age: " << author.age << " ";
   cout << "ID: " << author.ID << " ";
   cout <<  "Email: " << author.email << endl;
   cout << "==========================\n" << endl;
}
void Book::rateBook(int rating) //fun to get the avg of the book
{  rating_ave =0;
    arr[arr_cntr] = rating;
    for(int i=0; i<=arr_cntr; i++)
    {
        rating_ave += arr[i];
    }
    rating_ave /= (arr_cntr+1);
    averageRating = rating_ave;
    arr_cntr++;

}
bool Book::operator==(const Book& book) // fun to know if the user set the same auther of the book
{
     bool status;
     if(title==book.title&& isbn == book.isbn && category == book.category && id==book.id&& author == book.author)
     {
         status = 1;
     }
     else
        status =0;
     return status;
}
ostream &operator<<(ostream &output, const Book &book ) // an operator overloading to output the book info
{
     output<< "=========Book "  << book.id<<  " Info========" << endl;
    output << "Title: " << book.title << endl;
    output << "ISBN: " << book.isbn << endl;
    output << "ID: " << book.id << endl;
    output << "Cat: " << book.category <<endl;
    output <<  "Rating: " << book.rating_ave << endl;
    cout << "=======================================\n" << endl;

    return output;
}
istream &operator>>( istream &input, Book &book ) // an operator overloading to input the book info
{
    book.id = book.Count;
    input >> book.title >> book.isbn >> book.category;
}
double Book::get_rate()// fun to get the avg of the boo;
{
    return averageRating;
}
Book::~Book() // a deconstructor to delete the dynamic array
{
   delete [] arr;
}
