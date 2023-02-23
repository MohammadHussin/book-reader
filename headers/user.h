#ifndef USER
#define USER
#include<bits/stdc++.h>
#include<file_functions.h>
#include<helper_functions.h>
using namespace std;

class User
{
private:
    string name; 
    string userName;
    string email;
    string password;
    int userId;
    int lastId;
public:
    User();
    bool logIn(string path);
    bool signUp(string path);
    void viewMyProfile();
    int getUserId() const;
    string userInformation();
};

#endif
