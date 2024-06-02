#ifndef PAGE_H
#define PAGE_H

#pragma once
#include "Line.h"

#include<iostream>
using namespace std;

class Page
{
private:
    const int max_line=20;
    int page_num;
    Page* link;
    char **page1;
    int line_num;
    int line_size;
    Line ltemp,ltemp2;
    
public:
    static int page_count;
    Page();
    Page(const Page&);
    ~Page();
    bool pageisfull();
    Page operator+=(string str);
    char** &operator+=(Page &temp);
    Page operator+=(Line & l1);

    Page operator=(string str);
    char** getpage();
    int getlinenum();
    int getlinesize();
    //friend Book operator+=(Page p1);




};

#endif