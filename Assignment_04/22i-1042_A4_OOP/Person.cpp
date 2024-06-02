//Maaz ALi
//22i-1042
//Assignment4

#include "Person.h"

Person::Person()
{
    id=0;
    name="";
    phonenumber="";
    address="";
}
Person ::Person(int idx, string na, string ph, string ad)
{
    id=idx;
    name=na;
    phonenumber=ph;
    address=ad;
}
void Person::setId(int idx)
{
    id = idx;
}
void Person::setName(string str)
{
    name = str;
}
void Person::setPhoneNumber(string str)
{
    phonenumber=str;
}
void Person::setAddress(string str)
{
    address=str;
}
int Person::getId()
{
    return id;
}
string Person::getName()
{
    return name;
}
string Person::getPhoneNumber()
{
    return phonenumber;
}
string Person::getAddress()
{
    return address;
}
Person::~Person()
{

}