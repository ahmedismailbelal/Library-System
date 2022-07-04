#include "Book.h"
#include <string>
#include<iostream>
using namespace std;
#include "BookList.h"

BookList::BookList() // a default constructor
{

}
BookList::BookList(int cap) // a paramitriza constructer
{
    capacity = cap;
    books = new Book[capacity];
}

void BookList::addBook(Book book) // a fun to add a book
{
   books[booksCount] = book;
    booksCount ++;
    Book::Count++;
    arr_cnt++;
}
BookList::BookList(const BookList& anotherList) // a copy constructor
{
    capacity = anotherList.capacity;
    for(int i=0; i<booksCount;i++)
    {
        books[i] = anotherList.books[i];
    }
    arr_cnt = anotherList.arr_cnt;
}
void BookList::set_book_author(User user) // some funs to get the author info
{
    books[booksCount].setAuthor(user);
}
void BookList::set_book_name(string s)
{
    books[booksCount].setTitle(s);
}
void BookList::set_book_category(string c)
{
    books[booksCount].setCategory(c);
}
void BookList::set_book_rate(int r)
{
    books[booksCount].rateBook(r);
}


Book& BookList::searchBook(string name) // to search about the author by the name
{
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].getTitle() == name)
        {
            return books[i];
        }
    }
}
Book& BookList::searchBook(int id) // to search about the author by the id
{
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].getId() == id)
        {
            return books[i];
        }
    }
}
void BookList::deleteBook(int id) // to delete a book from the book list
{
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getId() == id)
        {   arr_cnt--;
            for(int j=i; j<booksCount-1; j++)
            {
                delete (books+j);
                books[j] = books[j+1];
            }
        }

    }
}

Book BookList::getTheHighestRatedBook() // to the highest avg from the user
{
    int max_rate=0;+
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].get_rate() > max_rate)
            max_rate = books[i].get_rate();
    }
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].get_rate() == max_rate)
            return books[i];
    }

}

void BookList::getBooksForUser(User user) // to get a book by the id
{
    for(int i=0; i < booksCount; i++)
    {
        if(books[i].getAuthor() == user)
            cout <<  books[i];
    }
}

Book & BookList::operator [ ] (int position) // an operating overloading to get an element from the array
{
    for(int i=0; i < booksCount; i++)
    {
        return books[position];
    }
}
ostream &operator<<( ostream &output, BookList &booklist ) // an operating overloading to get the output
 {

     for(int i=0; i< booklist.arr_cnt; i++)
     {
         output << booklist.books[i];
     }
      return output;
 }
 int BookList::get_booksCount() // fun to get the count of the books
{
    return booksCount;
}
BookList::~BookList() // a deconstractor to delete the dynamic array
{
    delete [] books;
}
