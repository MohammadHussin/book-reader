#include<book.h>

Book::Book() : name(""),sessionNumber(0),pagesNumberInSession(0),id(0){}

string Book::getName() const 
{
    return name;
}

void Book::setName(string name)
{
    this->name=name;
}

int Book::getSessionNumber() const
{
    return sessionNumber;
}

void Book::setSessionNumber(int sessionNumber)
{
    this->sessionNumber=sessionNumber;
}

int Book::getPagesNumberInSession() const 
{
    return pagesNumberInSession;
}

void Book::setPagesNumberInSession(int pagesNumberInSession)
{
    this->pagesNumberInSession=pagesNumberInSession;
}

int Book::getId() const
{
    return id;
}

void Book::setId(int id)
{
    this->id = id;
}

string Book::information()
{
    string aid;
    aid+=name;
    aid+=' ';
    aid+=to_string(id);
    aid+=' ';
    aid+=to_string(sessionNumber);
    aid+=' ';
    aid+=to_string(pagesNumberInSession);
    return aid;
}

Book Book::returnBook(string tempName,int tempId,int tempSession, int tempPages)
{
    Book tempBook;
    tempBook.setName(tempName);
    tempBook.setId(tempId);
    tempBook.setPagesNumberInSession(tempPages);
    tempBook.setSessionNumber(tempSession);
    return tempBook;
}