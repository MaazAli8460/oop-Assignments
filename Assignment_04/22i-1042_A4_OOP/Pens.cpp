//Maaz ALi
//22i-1042
//Assignment4


#include "Pens.h"

Pens::Pens(int u, double p, bool s, bool g)
{
    units=u;
    setprice(p);
    setname("Pens");
    setitem_type("Supplies");
    sale=s;
    gift=g;

}
void Pens::setsale(bool t)
{
    sale = t;
}
void Pens::setgift(bool t)
{
    gift = t;
}
void Pens::setunits(int p)
{
    units = p;
}
bool Pens::getsale()
{
    return sale;
}
bool Pens::getgift()
{
    return gift;
}
int Pens::getunits()
{
    return units;
}
double Pens::price()
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
bool Pens::operator==(Pens &p1)
{
    string str1=gettype();
    string str2=p1.gettype();
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
    string str4=p1.getname();
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
    if(sale==p1.sale && fl1==true && getprice()==p1.getprice() && fl2==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ostream& operator<<(ostream& os,Pens& pen)
{
    //<Name> <Unit Price> <No of Units> <on Sale> <Complementary Gift card>, Price: <Price> Rs.
           os<<"Name\tPrice\tUnits\tSale\tGift Card\tPrice"<<endl;
    return os<<pen.getname()<<"\t"<<pen.getprice()<<"\t"<<pen.getunits()<<"\t"<<pen.getsale()<<"\t"<<pen.getgift()<<"\t\t"<<pen.price()<<".Rs"<<endl;
}
Pens::~Pens()
{

}