//Maaz ALi
//22i-1042
//Assignment4



#ifndef MANAGER_H
#define MANAGER_H

#pragma once
#include <iostream>
using namespace std;
class Manager
{
public:
    Manager(string s = "");
    string getmanager();
    void setname(string s);
    Manager setmanager(const Manager &s);
    ~Manager();

private:
    string name;
};

#endif
