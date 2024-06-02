//Maaz ALi
//22i-1042
//Assignment4

#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
using namespace std;

#pragma once

class Books
{
private:
    // ID,name, author, edition number purchase date and marked available or issued in the system
    string type;
    int id;
    string name;
    string author;
    int number;
    string purchased_date;
    int dayiss;
    int moiss;
    int dayre;
    int more;
    bool avail;

public:
    Books();
    Books(int id1, string na1, string ad1, int num1, string date1, bool flag, string ty);
    void setID(int x);
    void setNumber(int x);
    void setName(string n);
    void setType(string n);
    void setAuthor(string a);
    void setDate(string date);
    void setAvailable(bool flag);
    void set_dateissued(int da,int mo);
    void set_dateret(int da,int mo);

    int getId();
    int getnumber();
    string getName();
    string getAuthor();
    string getType();
    string getDate();
    Books operator=(Books b);
    void BookDisplay();
    bool getAvailable();
    int  getdayissu();
    int  getmonthissu();

    int getdayretu();
    int getmoretu();

    ~Books();

private:
};

#endif