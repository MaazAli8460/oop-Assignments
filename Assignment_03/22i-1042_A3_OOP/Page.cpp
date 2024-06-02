//Maaz ALi
//22i-1042
//Assignment#03

#include "Page.h"
#include "Line.h"
#include <iostream>
using namespace std;

int Page::page_count=0;
Page::Page()
{
    page_count++;
    page_num = 0;
    line_num = 0;
    link = NULL;
    if (pageisfull())
    {
        link = new Page();
    }
}

Page::~Page()
{
}
bool Page::pageisfull()
{
    if (line_num == max_line)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Page::Page(const Page &ptr)
{
    link = new Page();
    link->page_num = ptr.page_num;
    link->line_num = ptr.line_num;
}
Page Page::operator+=(string str)
{

    int tempsize = 0;
    int tt = 0;
    while (str[tempsize] != '\0')
    {
        tempsize++;
    }
    tt = 20 * 40;
    if (tempsize >= tt)
    {
        string s1, s2;
        int cp = 0;
        --tt;
        while (tt != 0)
        {
            s1[cp] = str[cp];
            cp++;
            tt--;
        }
        while(s1[cp]!=' ')
        {
            cp--;
        }
        while (str[cp] = '\0')
        {
            s2[tt] = str[cp];
            cp++;
            tt++;
        }
        ltemp += s1;
        page1 = ltemp.getline();
        line_num = ltemp.getlinecount();
        line_size = ltemp.getlinesize();
        link=new Page();
        link->link=NULL;
        ltemp2+=s2;
        link->page1 = ltemp2.getline();
        link->line_num = ltemp2.getlinecount();
        link->line_size = ltemp2.getlinesize();

    }
    else
    {
        ltemp += str;
        page1 = ltemp.getline();
        line_num = ltemp.getlinecount();
        line_size = ltemp.getlinesize();

    }
}

Page Page ::operator+=(Line & l1)
{
    line_num++;
    line_size=0;
    char** cp=l1.getline();
    for(int i=0;i<=l1.getlinecount();i++)
    {
        for(int j=0;j<40;j++)
        {
            page1[line_num][j]=cp[i][j];
        }
        line_num++;
    }



}

Page Page ::operator=(string str)
{
    page_num = 0;
    line_num = 0;
    link = NULL;
    //delete []page1;
    *this += str;


}
char** Page::getpage()
{
    return page1;
}
int Page::getlinenum()
{
    return line_num;
}
int Page::getlinesize()
{
    return line_size;
}

