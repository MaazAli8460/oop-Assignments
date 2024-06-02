//Maaz ALi
//22i-1042
//Assignment4



#include "Item.h"

Item::Item()
{
    name="";
    item_type="";
    price=0;
}


void Item::setname(string s)
{
    name=s;
}
void Item::setitem_type(string s)
{
    item_type=s;
}
void Item::setprice(double p)
{
    price=p;
}
string Item::getname()
{
    return name;
}
string Item::gettype()
{
    return item_type;
}
double Item::getprice()
{
    return price;
}
Item::~Item()
{

}