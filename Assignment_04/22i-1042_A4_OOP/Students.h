//Maaz ALi
//22i-1042
//Assignment4



#ifndef STUDENTS_H
#define STUDENTS_H

#pragma once

#include "Books.h"
#include "Person.h"
#include <iostream>
using namespace std;


class Students: public Person
{
private:
 const int max_books_Students=5;

 
 int book_id;
 string book_type;
 Books *Issued;
 int size;
 

public:
bool regester;
const string type="Students\0";
    Students();
    Students(int idx, string na, string ph, string ad);
    void setna(string na);
    void setidx(int idz);
    void setph(string ph);
    void setad(string ad);
    void addBook(Books  b1);
    void remBook(Books  b1);

    string getna();
    string getph();
    string getad();
    int getidx();

    void wantIssue(string ty, int id1,int date_issu);
    void wantReturn(string ty, int id1,int date_ret);
    void print();
    void set_id(int bookid);
    void set_type(string ty);
    void Regester(bool fl);
    Students operator=(Students f1);
    ~Students();

};

#endif