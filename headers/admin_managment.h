#ifndef ADMIN_MANAGMENT
#define ADMIN_MANAGMENT
#include<bits/stdc++.h>
#include<admin.h>
using namespace std;

class AdminManagment : public Admin
{
private:
    Admin currentAdmin;
public:
    AdminManagment();
    void logIn();
    void signUp();
    void menuOfAdmin();
    void viewMyBooks();
};

#endif
