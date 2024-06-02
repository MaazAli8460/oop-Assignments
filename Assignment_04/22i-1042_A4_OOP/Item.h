//Maaz ALi
//22i-1042
//Assignment4


#ifndef ITEM_H
#define ITEM_H

#pragma once
#include<iostream>
using namespace std;
class Item
{
private:
string name;
string item_type;
double price;
public:
    Item();
    void setname(string s);
    void setitem_type(string s);
    void setprice(double p);
    string getname();
    string gettype();
    double getprice();
    ~Item();


};

#endif