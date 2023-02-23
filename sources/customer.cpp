#include<customer.h>

Customer::Customer(){}

bool Customer::logIn()
{
    string path="user_file.text";
    return User::logIn(path);
}

bool Customer::signUp()
{
    string path="user_file.text";
    return User::signUp(path);
}

void Customer::viewMyProfile()
{
    cout<<endl;
    User::viewMyProfile();
    cout<<"5_number of books : "<<myBooks.size()<<endl;
    cout<<endl;
}

int Customer::customerMenu()
{
    cout<<endl;
    cout<<"1_view my profile"<<endl;
    cout<<"2_buy book"<<endl;
    cout<<"3_view my books"<<endl;
    cout<<"4_view system books"<<endl;
    cout<<"5_read book"<<endl;
    cout<<"6_back"<<endl;
    return check(6);
}

void Customer::pushBook(Book &temp,bool ok)
{
    if(ok)
    myBooks.push_back(temp);
    else
    otherBooks.push_back(temp);
}

int Customer::getUserId()
{
    return User::getUserId();
}

string Customer::customerInformation()
{
    return User::userInformation();
}

void Customer::viewMyBooks()
{
    cout<<endl;
    for(int i=0;i<myBooks.size();i++)
    {
        cout<<i+1<<"_book name : "<<stringWithoutComma(myBooks[i].getName())<<endl
        <<" session number : "<<myBooks[i].getSessionNumber()<<endl
        <<" pages number : "<<myBooks[i].getPagesNumberInSession()<<endl;
    }
    if(!myBooks.size())
    cout<<"you don't have any book :("<<endl;
    cout<<endl;
}

void Customer::viewSystemBooks()
{
    reloadOtherBooks();
    cout<<endl;
    for(int i=0;i<otherBooks.size();i++)
    {
        cout<<i+1<<"_book name : "<<stringWithoutComma(otherBooks[i].getName())<<endl
        <<" session number : "<<otherBooks[i].getSessionNumber()<<endl
        <<" pages number : "<<otherBooks[i].getPagesNumberInSession()<<endl;
    }
    if(!otherBooks.size())
    cout<<"there are no books:("<<endl;
    cout<<endl;
}

void Customer::buyBook()
{
    reloadOtherBooks();
    if(!otherBooks.size())
    {
        cout<<endl;
        cout<<"there are no books :("<<endl;
        return;
    }
    viewSystemBooks();
    int choice=check(otherBooks.size());
    cout<<"the purchase was completed successfully"<<endl;
    myBooks.push_back(otherBooks[choice-1]);
    otherBooks.erase(otherBooks.begin()+choice-1);
    string path="customer_file.text";
    addToFile(path,to_string(getUserId())+' '+myBooks.back().information());
}

void Customer::reloadOtherBooks()
{
    vector<string>books;
    string path="books_file.text";
    readFromFile(path,books);
    otherBooks.clear();
    for(int i=0;i<books.size();i++)
    {
        bool ok=true;
        for(int j=0;j<myBooks.size();j++)
        {
            if(myBooks[j].information()==books[i])
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            string tempName;
            int tempSession;
            int tempPages;
            int tempId;
            istringstream iss(books[i]);
            iss>>tempName>>tempId>>tempSession>>tempPages;
            Book tempBook=returnBook(tempName,tempId,tempSession,tempPages);
            otherBooks.push_back(tempBook);
        }
    }
}

void Customer::readBook()
{
    viewMyBooks();
    int choice=check(myBooks.size());
    choice--;
    pair<int,int>history=viewHistory(getUserId(),myBooks[choice].getId());
    pair<int,int> currentHistory;
    string path="history_file.text";
    if(history.first==-1)
    read(1,1,myBooks[choice].getSessionNumber(),myBooks[choice].getPagesNumberInSession(),currentHistory);
    else
    {
        string aid1=to_string(getUserId())+' '+to_string(myBooks[choice].getId())+' '+to_string(history.first)+' '+to_string(history.second);
        eraseFromFile(path,aid1);
        cout<<"you have an old history if you want to continue enter 1 or enter 2 to read from begining"<<endl;
        int choice1=check(2);
        if(choice1==2)
        read(1,1,myBooks[choice].getSessionNumber(),myBooks[choice].getPagesNumberInSession(),currentHistory);
        else
        read(history.first,history.second,myBooks[choice].getSessionNumber(),myBooks[choice].getPagesNumberInSession(),currentHistory);
    }
    string aid=to_string(getUserId())+' '+to_string(myBooks[choice].getId())+' '+to_string(currentHistory.first)+' '+to_string(currentHistory.second);
    addToFile(path,aid);

}

pair<int,int> Customer::viewHistory(int userId,int BookId)
{
    vector<string>history;
    string path="history_file.text";
    readFromFile(path,history);
    pair<int,int> p={-1,-1};
    for(int i=0;i<history.size();i++)
    {
        int tempUserId;
        int tempBookId;
        int tempSession;
        int tempPage;
        istringstream iss(history[i]);
        iss>>tempUserId>>tempBookId>>tempSession>>tempPage;
        if(tempUserId==userId && tempBookId==BookId)
        {
            p={tempSession,tempPage};
            break;
        }
    }
    return p;
}

void Customer::read(int currentSession,int currentPage,int limitSession,int limitPage,pair<int,int>&v)
{
    bool ok=true;
    while(ok)
    {
        int counter=1;
        cout<<endl<<endl<<endl;
        cout<<"           text            "<<endl;
        cout<<endl<<endl<<endl;
        if(currentPage<limitPage)
        cout<<counter++<<"_move to next page"<<endl;
        if(currentPage==limitPage && currentSession<limitSession)
        cout<<counter++<<"_move to next session"<<endl;
        if(currentPage>1)
        cout<<counter++<<"_move to previos page"<<endl;
        if(currentPage==1 && currentSession>1)
        cout<<counter++<<"_move to previos session"<<endl;
        cout<<counter<<"_stop reading"<<endl;
        int choice=check(counter);
        if(choice==1 && currentPage<limitPage)
        currentPage++;
        else if(choice==1 && currentPage==limitPage && currentSession<limitSession)
        {
            currentSession++;
            currentPage=1;
        }
        else if(choice==1)
        currentPage--;
        else if(choice==2 && currentPage>1)
        currentPage--;
        else if(choice==2 && currentPage==1 && currentSession>1)
        {
            currentSession--;
            currentPage=limitPage;
        }
        else
        ok=false;
    }
    v.first=currentSession;
    v.second=currentPage;
}