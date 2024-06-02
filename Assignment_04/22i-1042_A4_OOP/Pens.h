//Maaz ALi
//22i-1042
//Assignment4


#ifndef PENS_H
#define PENS_H

#pragma once
#include"Item.h"
#include<iostream>
using namespace std;
class Pens: public Item
{
public:
    Pens(int u=0, double p=0, bool s=false, bool g=false);
    void setsale(bool t);
    void setgift(bool t);
    void setunits(int p);
    bool getsale();
    bool getgift();
    int getunits();
    double price();
    bool operator==(Pens &p1);

    friend ostream& operator<<(ostream& os, Pens& pen);
    ~Pens();

private:
bool sale;
bool gift;
int units;

};

#endif