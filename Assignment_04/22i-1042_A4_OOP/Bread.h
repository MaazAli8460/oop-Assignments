//Maaz ALi
//22i-1042
//Assignment4




#ifndef BREAD_H
#define BREAD_H

#pragma once
#include"Item.h"
#include<iostream>
using namespace std;
class Bread: public Item
{
public:
    Bread(int u=0, double p=0, bool s=false, bool g=false);
    void setsale(bool t);
    void setgift(bool t);
    void setunits(int p);
    bool getsale();
    bool getgift();
    int getunits();
    double price();
    bool operator==(Bread &b1);
    friend ostream& operator<<(ostream& os, Bread& bread);
    ~Bread();

private:
bool sale;
bool gift;
int units;

};

#endif