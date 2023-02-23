#include<user.h>

User::User() : name(""),userName(""),password(""),email(""),userId(0),lastId(0){}

bool User::logIn(string path)
{
    bool ok=true;
    bool ok1=true;
    vector<string>users;
    readFromFile(path,users);
    while(ok && ok1)
    {
        string username;
        cout<<"please enter your username"<<endl;
        cin.ignore();
        getline(cin,username);
        string Password;
        stringWithComma(username);
        cout<<"please enter your password"<<endl;
        cin>>Password;
        for(int i=0;i<users.size();i++)
        {
            
            string tempName;
            string tempUserName;
            string tempPassword;
            string tempEmail;
            int tempId;
            istringstream iss(users[i]);
            iss>>tempId>>tempName>>tempUserName>>tempPassword>>tempEmail;
            if(username==tempUserName && tempPassword==Password)
            {
                ok=false;
                name=tempName;
                userName=tempUserName;
                password=tempPassword;
                email=tempEmail;
                userId=tempId;
            }
        }
        if(ok)
        cout<<"this username not exist enter 1 to try with another username or enter 2 to come back"<<endl;
        else
        break;
        int num=check(2);
        if(num==2)
        ok1=false;
    }
    return !ok;
}

bool User::signUp(string path)
{
    vector<string>users;
    readFromFile(path,users);
    bool ok=true;
    bool ok1=true;
    string tempusername;
    while(ok && ok1)
    {
        cout<<"please enter your username (without comma)"<<endl;
        cin.ignore();
        getline(cin,tempusername);
        stringWithComma(tempusername);
        bool ok=false;
        for(int i=0;i<users.size();i++)
        {
            string tempName;
            string tempUserName1;
            int tempId;
            istringstream iss(users[i]);
            iss>>tempId>>tempName>>tempUserName1;
            lastId=max(lastId,tempId);
            if(tempusername==userName)
            ok=true;
        }
        if(ok)
        cout<<"this username exist enter 1 to try with another username or enter 2 to come back"<<endl;
        else
        break;
        int num=check(2);
        if(num==2)
        ok1=false;
    }
    if(!ok)
    return ok;
    userId=++lastId;
    string temppassword;
    cout<<"please enter your password"<<endl;
    cin>>temppassword;
    string tempemail=checkEmail();
    string tempname;
    cout<<"please enter your name (without comma)"<<endl;
    cin.ignore();
    getline(cin,tempname);
    stringWithComma(tempname);
    name=tempname;
    password=temppassword;
    userName=tempusername;
    email=tempemail;
    string temppath="user_file.text";
    return true;
}

void User::viewMyProfile()
{
    cout<<endl;
    cout<<"1_ID : "<<userId<<endl;
    cout<<"2_Username : "<<stringWithoutComma(userName)<<endl;
    cout<<"3_Password : "<<password<<endl;
    cout<<"4_email : "<<email<<endl;
}

int User::getUserId() const
{
    return userId;
}

string User::userInformation()
{
    string temp;
    temp+=to_string(userId);
    temp+=' ';
    temp+=name;
    temp+=' ';
    temp+=userName;
    temp+=' ';
    temp+=password;
    temp+=' ';
    temp+=email;
    return temp;
}