#include<file_functions.h>

void writeOnFile(string path,vector<string>&v)
{
    path="../others/"+path;
    ofstream f(path.c_str());
    if(f.fail())
    {
        cout<<"ERROR can't open this file"<<endl;
        return;
    }
    for(int i=0;i<v.size();i++)
    f<<v[i]<<endl;
    f.close();
}

void readFromFile(string path,vector<string>&v)
{
    path="../others/"+path;
    ifstream f(path.c_str());
    if(f.fail())
    {
        cout<<"ERROR can't open this file"<<endl;
        return;
    }
    string info;
    while(getline(f,info))
    v.push_back(info);
    f.close();
}

void addToFile(string path,string info)
{
    path="../others/"+path;
    ofstream f(path.c_str(),ios::app | ios::out);
    if(f.fail())
    {
        cout<<"ERROR can't open this file"<<endl;
        return;
    }
    f<<info<<endl;
    f.close();
}

void eraseFromFile(string path,string s)
{
    path="../others/"+path;
    ifstream f(path.c_str());
    if(f.fail())
    {
        cout<<"ERROR can't open this file"<<endl;
        return;
    }
    vector<string>v;
    string info;
    while(getline(f,info))
    {
        if(info!=s)
        v.push_back(info);
    }
    f.close();
    writeOnFile(path,v);
}