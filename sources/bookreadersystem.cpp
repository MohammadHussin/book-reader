#include<bookreadersystem.h>

void bookReaderSystem::run()
{
    AdminManagment newAdmin;
    Customer_Managment newCustomer;
    int num=logOrSignMenu();
    if(num==1)
    {
        int choice=logOrSign();
        if(choice==1)
        newCustomer.logIn();
        else
        newAdmin.logIn();
    }
    else if(num==2)
    {
        int choice=logOrSign();
        if(choice==1)
        newCustomer.signUp();
        else
        newAdmin.signUp();
    }
    else
    return;
    run();
}