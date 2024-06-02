
//Maaz ALi
//22i-1042
//Assignment4

#include "Books.h"

Books::Books()
{
}
Books ::Books(int id1, string na1, string ad1, int num1, string date1, bool flag, string ty)
{
    id = id1;
    name = na1;
    author = ad1;
    number = num1;
    purchased_date = date1;
    avail = flag;
    type = ty;
}
void Books::setID(int x)
{
    id = x;
}
void Books::setNumber(int x)
{
    number = x;
}
void Books::setName(string n)
{
    name = n;
}
void Books::setAuthor(string a)
{
    author = a;
}
void Books::setDate(string date)
{
    purchased_date = date;
}
void Books::setType(string n)
{
    type = n;
}
void Books::setAvailable(bool flag)
{
    avail = flag;
}
int Books::getId()
{
    return id;
}
int Books::getnumber()
{
    return number;
}
string Books::getName()
{
    return name;
}
string Books::getType()
{
    return type;
}
string Books::getAuthor()
{
    return author;
}
string Books::getDate()
{
    return purchased_date;
}
bool Books::getAvailable()
{
    return avail;
}
Books Books::operator=(Books b)
{
    if(b.id!=-1)
    {
    id = b.id;
    name = b.name;
    author = b.author;
    number = b.number;
    purchased_date = b.purchased_date;
    avail = b.avail;
    type = b.type;
    dayiss=b.dayiss;
    dayre=b.dayre;
    moiss=b.moiss;
    more=b.more;
    return *this;
    }
    else
    {
        id=-1;
        name="";
        author="";
        number=-1;
        purchased_date="";
        avail=false;
        type="";
        return *this;
    }
}
void Books::BookDisplay()
{
    cout << "\nType          :" << type;
    cout << "\nName          :" << name;
    cout << "\nAuthor        :" << author;
    cout << "\nID            :" << id;
    cout << "\nEdition Number:" << number;
    cout << "\nPurchased Date:" << purchased_date;
    cout << "\nAvailable     :" << avail;
    cout << "\nIssue date    :"<<dayiss<<" - "<<moiss;
    cout << "\nReturn date   :"<<dayre<<"  - "<<more;

}
void Books::set_dateissued(int da,int mo)
{
    dayiss=da;
    moiss=mo;
}
void Books::set_dateret(int da,int mo)
{
    dayre=da;
    more=mo;
}
int  Books::getdayissu()
{
    return dayiss;
}
int  Books::getmonthissu()
{
    return moiss;
}

int Books::getdayretu()
{
    return dayre;
}
int Books::getmoretu()
{
    return more;
}
Books::~Books()
{

}