//Maaz ALi
//22i-1042
//Assignment4


#include "Socks.h"

Socks::Socks(int u, double p, bool s, bool g)
{
    units=u;
    setprice(p);
    setname("Socks");
    setitem_type("Clothes");
    sale=s;
    gift=g;

}
void Socks::setsale(bool t)
{
    sale = t;
}
void Socks::setgift(bool t)
{
    gift = t;
}
void Socks::setunits(int p)
{
    units = p;
}
bool Socks::getsale()
{
    return sale;
}
bool Socks::getgift()
{
    return gift;
}
int Socks::getunits()
{
    return units;
}
double Socks::price()
{
    if(sale)
    {
        double price;
        price=(getprice()*((100.0-25.0)/100.0))*units;
        return price;
    }
    else
    {
        return getprice()*units;
    }
}
bool Socks::operator==(Socks &s1)
{
    string str1=gettype();
    string str2=s1.gettype();
    bool fl1=false;
    int i=0;
    while(str1[i]!='\0'&&str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
            fl1=false;
            break;
        }
        else
        {
            fl1=true;
        }
        i++;
    }
    string str3=getname();
    string str4=s1.getname();
    bool fl2=false;
    i=0;
    while(str3[i]!='\0'&&str4[i]!='\0')
    {
        if(str3[i]!=str4[i])
        {
            fl2=false;
            break;
        }
        else
        {
            fl2=true;
        }
        i++;
    }
    if(sale==s1.sale && fl1==true && getprice()==s1.getprice() && fl2==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& os,Socks& sock)
{
    //<Name> <Unit Price> <No of Units> <on Sale> <Complementary Gift card>, Price: <Price> Rs.
           os<<"Name\tPrice\tUnits\tSale\tGift Card\tPrice"<<endl;
    return os<<sock.getname()<<"\t"<<sock.getprice()<<"\t"<<sock.getunits()<<"\t"<<sock.getsale()<<"\t"<<sock.getgift()<<"\t\t"<<sock.price()<<".Rs"<<endl;
}

Socks::~Socks()
{

}