//Maaz ALi
//22i-1042
//Assignment4


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once
#include <iostream>
#include "Project.h"
using namespace std;
class Employee
{
public:
    Employee();
    void setName(string n);
    void setProject(string t);
    void allocateManager(Manager *m);
    void print();
    ~Employee();

private:
    Project p;
    string name;
};

#endif