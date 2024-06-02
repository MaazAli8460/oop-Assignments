//Maaz ALi
//22i-1042
//Assignment4



#ifndef CART_H
#define CART_H

#pragma once
#include"Item.h"
#include"Pens.h"
#include"Socks.h"
#include"Egg.h"
#include"Bread.h"


#include<iostream>
class Cart
{
public:
    Cart();
    int getTotalItems();
    bool Discount() const;
    double price() const;
    string String() const;
    //oprator +=
    Cart operator+=(Bread &b);
    Cart operator+=(Egg &e);
    Cart operator+=(Pens &p);
    Cart operator+=(Socks &s);
    //oprator +

    Cart operator+(Bread &b);
    Cart operator+(Egg &e);
    Cart operator+(Pens &p);
    Cart operator+(Socks &s);
    //oprator -=

    Cart operator-=(Bread &b);
    Cart operator-=(Egg &e);
    Cart operator-=(Pens &p);
    Cart operator-=(Socks &s);
    //oprator -
    Cart operator-(Bread &b);
    Cart operator-(Egg &e);
    Cart operator-(Pens &p);
    Cart operator-(Socks &s);
    


    friend ostream& operator<<(ostream& os, Cart& c1);
    ~Cart();

private:
static int total_items;
Pens *pe;
int pe_count;
Socks *so;
int so_count;
Egg *eg;
int eg_count;
Bread *br;
int br_count;


};

#endif