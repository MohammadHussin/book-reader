#ifndef ADMIN
#define ADMIN
#include<bits/stdc++.h>
#include<user.h>
#include<book.h>
using namespace std;

class Admin : public User , public Book
{
private:
    int numberOfBooks;
    vector<Book>books;
    int lastBookId;
public:
    Admin();
    bool logIn();
    bool signUp();
    int adminMenu();
    int getNumberOfBooks() const;
    void setNumberOfBooks(int numberOfBooks);
    void pushBook(Book &tempBook);
    int getUserId() const;
    int getLastBookId() const;
    void setLastBookId(int lastId);
    void viewMyProfile();
    string adminInformation();
    void addNewBook();
    void viewMyBooks();
};

#endif
