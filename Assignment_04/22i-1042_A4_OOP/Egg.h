//Maaz ALi
//22i-1042
//Assignment4

#ifndef EGG_H
#define EGG_H
#include"Item.h"
#include<iostream>
using namespace std;
#pragma once

class Egg:public Item
{
public:
    Egg(int u=0, double p=0, bool s=false, bool g=false);
    void setsale(bool t);
    void setgift(bool t);
    void setunits(int p);
    bool getsale();
    bool getgift();
    int getunits();
    double price();
    bool operator==(Egg &e1);

    friend ostream& operator<<(ostream& os, Egg& egg);
    ~Egg();

private:
bool sale;
bool gift;
int units;
};

#endif