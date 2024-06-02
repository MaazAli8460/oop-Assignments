
//Maaz ALi
//22i-1042
//Assignment4


#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "Library.h"
#include "Faculty.h"
#include "Students.h"


using namespace std;
#pragma once

class Admin
{
private:
const int duefac=9;
const int duestu=2;

string name;
string password;
Library l1;
bool fine;
Faculty * f1;
int f_size,stu_size;
Students * s1;

public:
    Admin();
    Admin(string na, string pass);
    void searchRecord(int id1);
    Books ReturnRecord(int id1,string ty);

    void addRecord(int id1, string na1, string ad1, int num1, string date1, string ty);

    Books issueBookfac(int id, string type);
    Books issueBookstu(int id, string type);
    void viewRecord();
    bool generateChalanfac(int id, string types);
    bool generateChalanstu(int id, string types);
    bool isMember(Faculty ft);
    bool isMember(Students s1);

    int getIssuday1(int id);
    int getReturnday1(int id);
    int getIssuemonth1(int id);
    int getReturnmonth1(int id);

    void displayLibrary();
    void regesterMember(Faculty &ftemp);
    void regesterMember(Students &stemp);
    void removeBookstu(Books &b);
    void removeBookfac(Books &b);

    Books returnBookstu(int id, string type);
    Books returnBookfac(int id, string type);

    ~Admin();

private:

};

#endif