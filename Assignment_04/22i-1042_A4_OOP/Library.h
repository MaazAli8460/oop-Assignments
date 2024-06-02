//Maaz ALi
//22i-1042
//Assignment4



#ifndef LIBRARY_H
#define LIBRARY_H
#include "Books.h"
#include <iostream>
using namespace std;
#pragma once

class Library
{
private:
    const int max_allowed = 10;
    int current_size;
    Books *Catalogue;

public:
    Library();
    void addBook(int id1, string na1, string ad1, int num1, string date1, bool flag, string ty);
    void issueBook( int id1, string ty);
    void returnBook(int id1,string ty);
    Books temp(int id1,string ty);
    bool libsearch(int id);
    void getIssueDate(int id);
    void getReturnDate(int id);
    int getIssuday(int id);
    int getReturnday(int id);
    int getIssuemonth(int id);
    int getReturnmonth(int id);
    void DisplayLibrary();
    ~Library();

};

#endif