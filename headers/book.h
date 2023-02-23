#ifndef BOOK
#define BOOK
#include<bits/stdc++.h>
using namespace std;

class Book
{
private:
    string name;
    int sessionNumber;
    int pagesNumberInSession;
    int id;
public:
    Book();
    string getName() const;
    void setName(string name);
    int getSessionNumber() const;
    void setSessionNumber(int sessionNumber);
    int getPagesNumberInSession() const;
    void setPagesNumberInSession(int pagesNumberInSession);
    int getId() const;
    void setId(int id);
    string information();
    Book returnBook(string tempName,int tempId,int tempSession,int tempPages);
};

#endif