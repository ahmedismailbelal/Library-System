#include<cstring>
#include<iostream>
#include <User.h>
#include<Book.h>
#include <string>
#ifndef BOOKLIST_H
#define BOOKLIST_H


class BookList
{
    private:
        Book* books;
        int capacity;
        int booksCount=0;
    public:
        int arr_cnt =0;
        BookList();
        BookList(int capacity);
        void addBook(Book book);
        BookList(const BookList& anotherList);
        Book& searchBook(string name);
        Book& searchBook(int id);
        void deleteBook(int id);
        Book getTheHighestRatedBook();
        void getBooksForUser(User user);
        Book & operator [ ] (int position);
        int get_booksCount();
        void set_book_author(User user);
        void set_book_name(string s);
        void set_book_category(string c);
        void set_book_rate(int r);
        friend ostream &operator<<( ostream &output, BookList &booklist );
        ~BookList();
};

#endif // BOOKLIST_H
