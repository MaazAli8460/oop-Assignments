//Maaz ALi
//22i-1042
//Assignment4

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
#pragma once

class Person
{
private:
    int id;
    string name;
    string phonenumber;
    string address;

public:
    Person();
    Person(int idx, string na, string ph, string ad);
    void setId(int idx);
    void setName(string str);
    void setPhoneNumber(string str);
    void setAddress(string str);
    int getId();
    string getName();
    string getPhoneNumber();
    string getAddress();
    ~Person();

private:

};

#endif