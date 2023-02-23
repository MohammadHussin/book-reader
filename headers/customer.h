#ifndef CUSTOMER
#define CUSTOMER
#include<bits/stdc++.h>
#include<book.h>
#include<user.h>
using namespace std;

class Customer : public User , public Book
{
private:
    vector<Book>myBooks;
    vector<Book>otherBooks;
public:
    Customer();
    bool logIn();
    bool signUp();
    void viewMyProfile();
    int customerMenu();
    void pushBook(Book &temp,bool ok=0);
    int getUserId();
    string customerInformation();
    void viewMyBooks();
    void viewSystemBooks();
    void buyBook();
    void reloadOtherBooks();
    void readBook();
    pair<int,int> viewHistory(int userId,int BookID);
    void read(int currentPage,int currentSession,int limitSession,int limitPage,pair<int,int>&v);
};

#endif