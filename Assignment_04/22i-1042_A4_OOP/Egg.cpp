//Maaz ALi
//22i-1042
//Assignment4


#include "Egg.h"

Egg::Egg(int u, double p, bool s, bool g)
{
    units=u;
    setprice(p);
    setname("Egg");
    setitem_type("Food");
    sale=s;
    gift=g;

}
void Egg::setsale(bool t)
{
    sale = t;
}
void Egg::setgift(bool t)
{
    gift = t;
}
void Egg::setunits(int p)
{
    units = p;
}
bool Egg::getsale()
{
    return sale;
}
bool Egg::getgift()
{
    return gift;
}
int Egg::getunits()
{
    return units;
}
double Egg::price()
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
bool Egg::operator==(Egg &e1)
{
    string str1=gettype();
    string str2=e1.gettype();
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
    string str4=e1.getname();
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
    if(sale==e1.sale && fl1==true && getprice()==e1.getprice() && fl2==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Egg::~Egg()
{
}
ostream& operator<<(ostream& os,Egg& egg)
{
    //<Name> <Unit Price> <No of Units> <on Sale> <Complementary Gift card>, Price: <Price> Rs.
           os<<"Name\tPrice\tUnits\tSale\tGift Card\tPrice"<<endl;
    return os<<egg.getname()<<"\t"<<egg.getprice()<<"\t"<<egg.getunits()<<"\t"<<egg.getsale()<<"\t"<<egg.getgift()<<"\t\t"<<egg.price()<<"Rs"<<endl;
}