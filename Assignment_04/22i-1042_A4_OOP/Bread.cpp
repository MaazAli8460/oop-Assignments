//Maaz ALi
//22i-1042
//Assignment4



#include "Bread.h"

Bread::Bread(int u, double p, bool s, bool g)
{
    units=u;
    setprice(p);
    setname("Bread");
    setitem_type("Food");
    sale=s;
    gift=g;

}
void Bread::setsale(bool t)
{
    sale = t;
}
void Bread::setgift(bool t)
{
    gift = t;
}
void Bread::setunits(int p)
{
    units = p;
}
bool Bread::getsale()
{
    return sale;
}
bool Bread::getgift()
{
    return gift;
}
int Bread::getunits()
{
    return units;
}
double Bread::price()
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
bool Bread::operator==(Bread &b1)
{
    string str1=gettype();
    string str2=b1.gettype();
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
    string str4=b1.getname();
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
    if(sale==b1.sale && fl1==true && getprice()==b1.getprice() && fl2==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ostream& operator<<(ostream& os,Bread& bread)
{
    //<Name> <Unit Price> <No of Units> <on Sale> <Complementary Gift card>, Price: <Price> Rs.
           os<<"Name\tPrice\tUnits\tSale\tGift Card\tPrice"<<endl;
    return os<<bread.getname()<<"\t"<<bread.getprice()<<"\t"<<bread.getunits()<<"\t"<<bread.getsale()<<"\t"<<bread.getgift()<<"\t\t"<<bread.price()<<".Rs"<<endl;
}

Bread::~Bread()
{

}