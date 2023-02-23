#include<helper_functions.h>

string stringWithComma(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        s[i]=',';
    }
    return s;
}

string stringWithoutComma(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',')
        s[i]=' ';
    }
    return s;
}

int check(int end,int start)
{
    int choice;
    bool ok=true;
    while(ok)
    {
        cout<<"please enter your choice:"<<endl;
        cin>>choice;
        if(choice>=start && choice<=end)
        ok=false;
        if(ok)
        cout<<"invalid input please try again"<<endl;
    }
    return choice;
}

int logOrSignMenu()
{
    cout<<"1_log in"<<endl;
    cout<<"2_sign up"<<endl;
    cout<<"3_log out"<<endl;
    int choice=check(3);
    if(choice<=3)
    return choice;
    return logOrSignMenu();
}

string checkEmail()
{
    string email;
    cout<<"please enter your email"<<endl;
    cin>>email;
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(regex_match(email, pattern))
    return email;
    cout<<"invalid input please try again"<<endl;
    return checkEmail();
}

int logOrSign()
{
    cout<<"1_Costumer"<<endl;
    cout<<"2_Admin"<<endl;
    int choice=check(2);
    return choice;
}