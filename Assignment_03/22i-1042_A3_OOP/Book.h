#ifndef BOOK_H
#define BOOK_H

#include "Line.h"

#include "Page.h"
#include <iostream>

class Book {
private:
    int size;
    int pagecount;
    static int tt;
    bool flag;
    char ***book;
public:
    Book();
    Book(int l);
    void operator+=(Page& p1);
    char** &operator[](int x);
    char*** operator+ (Book& b);
    Book operator=(char*** p);
    friend ostream operator<<(ostream &o, Book &b);
    void print();


    ~Book();
};

#endif
