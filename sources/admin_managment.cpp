#include<admin_managment.h>

AdminManagment::AdminManagment(){}

void AdminManagment::logIn()
{
    bool ok=currentAdmin.logIn();
    if(!ok)
    return;
    int currentAdminId=currentAdmin.getUserId();
    string path="admin_file.text";
    vector<string>v;
    readFromFile(path,v);
    int aidId=0;
    for(int i=0;i<v.size();i++)
    {
        int tempId;
        string tempBookName;
        int tempSessionNumber;
        int tempPagesNumberInSession;
        int tempBookId;
        istringstream iss(v[i]);
        iss>>tempId>>tempBookName>>tempBookId>>tempSessionNumber>>tempPagesNumberInSession;
        aidId=max(aidId,tempBookId);
        if(tempId==currentAdminId)
        {
            int number=currentAdmin.getNumberOfBooks();
            currentAdmin.setNumberOfBooks(++number);
            Book tempBook;
            tempBook=returnBook(tempBookName,tempBookId,tempSessionNumber,tempPagesNumberInSession);
            currentAdmin.pushBook(tempBook);
        }
    }
    currentAdmin.setLastBookId(aidId);
    menuOfAdmin();
}

void AdminManagment::signUp()
{
    bool ok=currentAdmin.signUp();
    if(!ok)
    return;
    string path="user_file.text";
    addToFile(path,currentAdmin.adminInformation());
}

void AdminManagment::menuOfAdmin()
{
    int number=currentAdmin.adminMenu();
    if(number==1)
    currentAdmin.viewMyProfile();
    else if(number==2)
    currentAdmin.addNewBook();
    else if(number==3)
    currentAdmin.viewMyBooks();
    else
    return;
    menuOfAdmin();
}

void AdminManagment::viewMyBooks()
{
    currentAdmin.viewMyBooks();
}
