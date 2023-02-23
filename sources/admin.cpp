#include<admin.h>

Admin::Admin() : numberOfBooks(0),lastBookId(0){}

bool Admin::logIn()
{
    string path="user_file.text";
    return User::logIn(path);
}

bool Admin::signUp()
{
    string path="user_file.text";
    return User::signUp(path);
}

int Admin::adminMenu()
{
    cout<<"1_view my profile"<<endl;
    cout<<"2_add new book"<<endl;
    cout<<"3_view my book"<<endl;
    cout<<"4_back"<<endl;
    return check(4);
}

int Admin::getNumberOfBooks() const
{
    return numberOfBooks;
}

void Admin::setNumberOfBooks(int numberOfBooks)
{
    this->numberOfBooks=numberOfBooks;
}

void Admin::pushBook(Book &tempBook)
{
    books.push_back(tempBook);
}

int Admin::getUserId() const
{
    return User::getUserId();
}

void Admin::viewMyProfile()
{
    User::viewMyProfile();
    cout<<"5_books number that added by you : "<<numberOfBooks<<endl;
    cout<<endl;
}

string Admin::adminInformation()
{
    return User::userInformation();
}

void Admin::addNewBook()
{
    cout<<"please enter the name of book"<<endl;
    cin.ignore();
    string name;
    getline(cin,name);
    stringWithComma(name);
    cout<<"please enter the number of sessions"<<endl;
    int sessions;
    cin>>sessions;
    cout<<"please enter the number of pages in every session"<<endl;
    int pages;
    cin>>pages;
    Book tempBook=returnBook(name,++lastBookId,sessions,pages);
    pushBook(tempBook);
    string path="books_file.text";
    addToFile(path,tempBook.information());
    path="admin_file.text";
    numberOfBooks++;
    string aid=to_string(getUserId())+' '+tempBook.information();
    addToFile(path,aid);
}

void Admin::viewMyBooks()
{
    cout<<endl;
    for(int i=0;i<books.size();i++)
    {
        cout<<i+1<<"_the name of the book : "<<stringWithoutComma(books[i].getName())<<endl
        <<" number of sessions : "<<books[i].getSessionNumber()<<endl
        <<" number of pages in session : "<<books[i].getPagesNumberInSession()<<endl;
    }
    if(!books.size())
    cout<<"you don't have any book :("<<endl;
    cout<<endl;
}

int Admin::getLastBookId() const
{
    return lastBookId;
}

void Admin::setLastBookId(int lastId)
{
    this->lastBookId=lastId;
}
