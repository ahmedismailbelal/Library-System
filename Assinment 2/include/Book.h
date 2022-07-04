#ifndef BOOK_H
#define BOOK_H
#include<string>
#include <user.h>
using namespace std;

class Book
{
    private:
        string title;
        string isbn;
        int id;
        string category;
        double averageRating;
        User author;
        int*arr = new int[10];
        int arr_cntr =0;
        double rating_ave=0;
    public:
        static int Count;
        Book();
        Book(string tit, string is, string cat);
        Book(const Book& book);
        void setTitle(string tit);
        string getTitle();
        void setISBN(string is);
        string getISBN();
        void setId(int Id);
        int getId();
        void setCategory(string cat);
        string getCategory();
        void setAuthor( User user);
        User getAuthor();
        void rateBook(int rating);
        bool operator==(const Book& book);
        friend ostream &operator<<(ostream &output, const Book &book );
        friend istream &operator>>( istream &input, Book &book );

        double get_rate();
      ~Book();

};

#endif // BOOK_H
