#include<cstring>
#include<iostream>
#include <User.h>
#include<Book.h>
#include <string>
#include <UserList.h>
#include <BookList.h>
using namespace std;
 bool ch=0;
int main()
{
    UserList u; //to save all the changes that happen to the coming objects
    BookList b; //to save all the changes that happen to the coming objects

    while (1)
    {
            cout << "Select one of the following choices: " << endl ;
            cout << "1- Books Menu" << endl << "2- Users Menu" << endl ;
            cout << "3- Exit" << endl;
            int choice ;
            cin >> choice;
            if(choice == 1)  // to access the first option in the menu which is the (book list)
            {
                 cout << "How many books will you add ?" << endl;
                 int num_of_books;
                 cin >> num_of_books;
                 BookList book_obj(num_of_books);
                 b = book_obj;
                 while(1)  // the book menu
                 {
                     cout << "Books Menu" << endl;
                     cout << "1- Create a book and add it to the list" << endl;
                     cout << "2- Search for a book" << endl;
                     cout << "3- Display all books (with book rating)" << endl;
                     cout << "4- Get the highest rating book" << endl;
                     cout << "5- Get all books of a user" << endl;
                     cout << "6- Copy the current book list to a new book list and switch to it" << endl;
                     cout << "7- Back to the main menu" << endl;
                     cin >> choice;
                     if(choice == 1) // addbook
                     {
                         cout << "Enter the book information in this order" << endl;
                         cout << "Title       ISBN         Category (space separated)" << endl;
                         Book b1;
                         cin >> b1;
                         while(1) // options in addbook
                         {
                             cout << "1- Assign Author" << endl << "2- Continue" << endl;
                             cin >> choice;
                             if(choice == 1)  //to assign an author
                             {
                                cout << "Enter Author (user) id" << endl;
                                int author_id ;
                                cin >> author_id;
                                User author = u.searchUser(author_id);
                                b1.setAuthor(author);
                                book_obj.addBook(b1);
                                break;
                            }
                            else // to continue the process
                            {
                                 book_obj.addBook(b1);
                                 break;
                            }

                     }
                     }
                     else if(choice == 2) //to search for book
                     {
                      while(1) //options in search feature
                        {
                         cout << "Search for a book" << endl;
                         cout << "1-Search by name" << endl;
                         cout << "2-Search by id" << endl;
                         cout << "3-return to book menu" << endl;
                         cin >> choice;
                         if(choice == 3) //return in the main manu
                         {
                             break;
                         }
                         else if(choice == 1) // to search for a book by his name
                         {
                             string name;
                             cout << "Enter name" << endl;
                             cin >> name;
                             cout << book_obj.searchBook(name);
                         }
                         else if(choice == 2) // to search for a number by his id
                         {
                             int id;
                             cout << "Enter id" << endl;
                             cin >> id;
                             cout << book_obj.searchBook(id);
                         }
                        while(1) // others features for the book
                         {
                             cout << "1- Update Author" << endl << "2- Update name" << endl;
                             cout << "3- Update Category" << endl << "4- Delete book" << endl;
                             cout << "5-Rate book" << endl << "6-Get back to books menu" << endl;
                             cin >> choice;
                             if(choice == 1) // to update the author of the book
                             {
                                    cout << "Enter Author (user) id" << endl;
                                    int author_id ;
                                    cin >> author_id;
                                    User author = u.searchUser(author_id);

                                    if(UserList::ch==1)
                                    {
                                        book_obj.set_book_author(u.searchUser(author_id));
                                        break;
                                    }
                                    else
                                    {
                                        cout << "No Author found with id " << author_id << endl;
                                    }
                                }
                                else if(choice == 2) // to update the name of the book
                                {
                                    cout << "Enter the new name" << endl;
                                    string name;
                                    cin >> name;
                                    book_obj.set_book_name(name);
                                }
                                else if(choice == 3) //to update the category
                                {
                                    cout << "Enter the new category " << endl;
                                    string cat;
                                    cin >> cat;
                                    book_obj.set_book_category(cat);
                                }
                                else if(choice == 4) // to delete the book from the list
                                {
                                    cout << "Enter book id " << endl;
                                    int book_id;
                                    cin >> book_id;
                                    book_obj.deleteBook(book_id);
                                }
                                else if(choice == 5) //to change the highest avg of all the books
                                {
                                    cout << "Enter rate" << endl;
                                    int rate;
                                    cin >>  rate;
                                    book_obj.set_book_rate(rate);

                                }
                                else if(choice == 6)//to get back to the main menu
                                {
                                    break;
                                }
                            }

                        }

                        }
                        else if(choice == 3)  // an option in the menu books to display all the books in the list
                        {
                            cout << book_obj;
                        }
                        else if(choice == 4)  // an option in the book menu to get the highest rating book
                        {
                            cout << book_obj.getTheHighestRatedBook();
                        }
                        else if(choice == 5)   // an option to get books for one user
                        {       User wanted;
                                cout << "Enter ID" << endl;
                                int user_id;
                                cin >> user_id;
                                wanted = u.searchUser(user_id);
                                book_obj.getBooksForUser(wanted);
                        }
                        else if (choice == 6) // to copy the list of books in another list
                        {
                            b= book_obj;
                            cout << "copied current List (2 books) to a New List and switched it";
                        }
                        else if(choice ==7) //get back to the main menu
                        {
                            break;
                        }

                    b= book_obj;
                 }

            }
            else if(choice == 2)  // to access the first option in the menu which is the (uers list)
            {
                cout << "How many users will be added ?" << endl;
                int num_of_users;
                cin >> num_of_users;
                UserList obj(num_of_users);
                u = obj;

                while(1)  // get in the user menu
                {
                    cout << "USERS MENU" << endl;
                    cout << "1-Create a user and add it to the list" << endl;
                    cout << "2-Search for a user" << endl;
                    cout << "3-Display all users" << endl;
                    cout << "4-Back to the main menu" << endl;
                    cin >> choice;
                    if(choice == 1)  // an option to adduser
                    {
                        cout << "Enter the user information in this order" << endl;
                        cout << "Name  Age  Email  Password (space separated)"<< endl;
                        User u1;
                        cin >> u1;
                        obj.addUser(u1);
                    }

                    else if(choice == 2)  // an option to search for a user
                    {
                        while(1) // more feature in the add part
                        {
                            cout << "1- search by name " << endl;
                            cout << "2- search by id " << endl;
                            cout << "3- Return to users menu" << endl;
                            cin >> choice;
                            User wanted;
                            if(choice == 1) // for the searching by the name
                            {
                                cout << "Enter name" << endl;
                                string user_name;
                                cin >> user_name;
                                wanted = obj.searchUser(user_name);
                                cout << wanted;
                            }
                            else if(choice == 2) // for the searching by the id
                            {
                                cout << "Enter ID" << endl;
                                int user_id;
                                cin >> user_id;
                                wanted = obj.searchUser(user_id);
                                cout << wanted;
                            }
                            else if(choice == 3) // for returning to the user menu
                            {
                                break;
                            }
                            cout << "1- Delete user" << endl;
                            cout << "2- Return to users menu" << endl;
                            cin >> choice;
                            if(choice == 1) // for deleting the founded user
                            {
                                obj.deleteUser(wanted.getId());
                            }
                            else if(choice == 2) // for returning to the user menu
                            {
                                break;
                            }
                        }

                    }

                    else if(choice == 3)  // an option to display all users
                    {
                        cout << obj;
                    }
                    else if(choice == 4)  // an option to back to the main menu
                    {
                        break;
                    }

                }
                u=obj;

            }

            else if(choice == 3) // an option to Exit
            {
                return 0;
            }

    }
    return 0;
}
