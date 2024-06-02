
//Maaz ALi
//22i-1042
//Assignment4



#include "Item.h"
#include "Item.cpp"
#include "Egg.h"
#include "Egg.cpp"
#include "Bread.h"
#include "Bread.cpp"
#include "Socks.h"
#include "Socks.cpp"
#include "Pens.h"
#include "Pens.cpp"
#include "Cart.h"
#include "Cart.cpp"


#include <iostream>
using namespace std;
int main()
{

    // example of non sale item.
     
    // Bread b1(10,1,true);
    // Bread b2(10,2,true,true);
    // Bread b3(10,3,true,true);


    // Pens p1(6,5);
    
    // Socks s1(12,100,true,true);

    // cout<<e1;

    // //cout<<b1;

    // cout<<p1;

    // cout<<s1;

    // cout<<b1;

    // cout<<b2;

    // cout<<b3;

    // Cart c1;

    // c1=c1+b1;

    // c1+=b2;

    // c1+=b3;

    // c1=c1+e1;

    // c1+=p1;

    // c1+=s1;
    
    // cout<<c1;
    Bread p1(12, 3);
    cout << p1 << endl;
    // example of sale item
    Egg p2(15, 1, true);

    Egg e1(15,1,true);

    // example of sale item with gift card

    bool flag=false;

    flag=p2==e1;

    if(flag)
    {
        cout<<endl<<"ARE EQUAL.\n";

    }
    else
    {
        cout<<endl<<"NOT EQUAL.\n";
    }
    Socks p3(20, 2.0, true, true);
    Cart c1;
    c1 += p1; // add bread to cart
    c1 += p1;
    c1 += p2; // add eggs to cart
    c1 += p3; // add socks to cart
    cout << c1 << endl;
    int i=c1.getTotalItems(); // displays number of all items in all carts.
    cout<<"\nTotal Items in Cart 1="<<i<<endl;
    //cout<<"\nTotal Items="<<i<<endl;
    c1 = c1 - p1; // Delete all the unit of type bread
    cout << c1 << endl;
    i=c1.getTotalItems(); // displays number of all items in all carts.
    cout<<"\nTotal Items in Cart 1="<<i<<endl;
    //cout<<"\nTotal Items="<<i<<endl;
    Cart c2;
    c2 = c1 + p2; // Add item of type eggs

    cout << c2 << endl;
    i=c2.getTotalItems(); // displays number of all items in all carts.
    cout<<"\nTotal Items in Cart 2="<<i<<endl;
    //cout<<"\nTotal Items="<<i<<endl;
    // Delete all the units of eggs type food from the cart.
    c2 -= p2;
    cout << c2;
    i=c2.getTotalItems(); // displays number of all items in all carts.
    cout<<"\nTotal Items in Cart 2="<<i<<endl;
    //cout<<"\nTotal Items="<<i<<endl;
    
    
    return 0;
}