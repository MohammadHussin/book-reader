#include<customer_managment.h>

Customer_Managment::Customer_Managment(){}

void Customer_Managment::logIn()
{
    bool ok=currentCustomer.logIn();
    if(!ok)
    return;
    int currentCustomerId=currentCustomer.getUserId();
    string path="books_file.text";
    vector<string>allBooks;
    vector<string>myBooks;
    readFromFile(path,allBooks);
    path="customer_file.text";
    readFromFile(path,myBooks);
    for(int i=0;i<allBooks.size();i++)
    {
        string tempName;
        int tempSession;
        int tempBookId;
        int tempPages;
        istringstream iss(allBooks[i]);
        iss>>tempName>>tempBookId>>tempSession>>tempPages;
        Book tempBook;
        bool ok=true;
        for(int j=0;j<myBooks.size();j++)
        {
            int tempId;
            string tempName1;
            int tempSession1;
            int tempBookId1;
            int tempPages1;
            istringstream iss1(myBooks[j]);
            iss1>>tempId>>tempName1>>tempBookId1>>tempSession1>>tempPages1;
            if(tempId==currentCustomerId && tempBookId==tempBookId1)
            {
                tempBook=returnBook(tempName,tempBookId,tempSession,tempPages);
                currentCustomer.pushBook(tempBook,1);
                ok=false;
                break;
            }
        }
        if(!ok)
        continue;
        tempBook=returnBook(tempName,tempBookId,tempSession,tempPages);
        currentCustomer.pushBook(tempBook);
    }
    menuOfCustomer();
}

void Customer_Managment::signUp()
{
    bool ok=currentCustomer.signUp();
    if(!ok)
    return;
    string path="user_file.text";
    addToFile(path,currentCustomer.customerInformation());
}

void Customer_Managment::menuOfCustomer()
{
    int choice=currentCustomer.customerMenu();
    if(choice==1)
    currentCustomer.viewMyProfile();
    else if(choice==2)
    currentCustomer.buyBook();
    else if(choice==3)
    currentCustomer.viewMyBooks();
    else if(choice==4)
    currentCustomer.viewSystemBooks();
    else if(choice==5)
    currentCustomer.readBook();
    else
    return;
    menuOfCustomer();
}
