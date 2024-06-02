//Maaz ALi
//22i-1042
//Assignment4



#include "Manager.h"

Manager::Manager(string s)
{
    string stemp = s;
    name = stemp;
}

Manager Manager::setmanager(const Manager &s)
{
    string temp = s.name;
    name = temp;
    return *this;
}
string Manager::getmanager()
{
    return name;
}
void Manager::setname(string s)
{
    this->name = s;
}

Manager::~Manager()
{
    // cout<<"\nManager Destructor called.";
}