#ifndef CUSTOMERMANAGMENT
#define CUSTOMERMANAGMENT
#include<bits/stdc++.h>
#include<customer.h>

class Customer_Managment : public Customer
{
private:
    Customer currentCustomer;
public:
    Customer_Managment();
    void logIn();
    void signUp();
    void menuOfCustomer();

};

#endif