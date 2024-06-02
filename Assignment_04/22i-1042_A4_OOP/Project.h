//Maaz ALi
//22i-1042
//Assignment4


#ifndef PROJECT_H
#define PROJECT_H

#pragma once
#include <iostream>
#include "Manager.h"
using namespace std;
class Project
{
public:
    Project();
    string getTitle();
    void setTitle(string t);
    Manager *getManager();
    void setManager(Manager *m1);
    ~Project();

private:
    string title;
    Manager *m;
};

#endif