//Maaz ALi
//22i-1042
//Assignment4


#ifndef SOCKS_H
#define SOCKS_H

#pragma once
#include"Item.h"
#include<iostream>
using namespace std;
class Socks : public Item
{
public:
    Socks(int u=0, double p=0, bool s=false, bool g=false);
    void setsale(bool t);
    void setgift(bool t);
    void setunits(int p);
    bool getsale();
    bool getgift();
    int getunits();
    double price();
    bool operator==(Socks &s1);

    friend ostream& operator<<(ostream& os, Socks& sock);
    ~Socks();

private:
bool sale;
bool gift;
int units;

};

#endif