#include "Line.h"

#include"string.h"

#include<iostream>
using namespace std;

//Line::line_count=0;
Line::Line()
{
    line_size=0;
    line=new char*[20];
    for (int i = 0; i < 20; i++)
    {
        line[i] = new char[max_char];
        /* code */
    }
    line_count=0;

}
Line::Line(string str)
{
    line_size=0;
    line=new char*[20];
    for (int i = 0; i < 20; i++)
    {
        line[i] = new char[max_char];
    /* code */
    }
    line_count=0;
    int i=0;
    while(str[i]!='\0')
    {
        int temp=i;
        while(str[temp]!=' ' && str[temp]!='.')
        {
            temp++;
        }
        int len=temp-i;
        len+=1;
        char* word=new char[len+1];
        int x=0;
        while(len!=0)
        {
            word[x]=str[i];
            x++;
            i++;
            len--;

        }
        //i++;
        //word[x]='\0';
        addword(word,x);

    }
        
}

Line :: Line(const Line& l)
{
    line_size=l.line_size;
    line=new char*[20];
    for (int i = 0; i < 20; i++)
    {
        line[i] = new char[max_char];
        /* code */
    }
    for (int i = 0; i < 20; i++)
    {
        strcpy(line[i],l.line[i]);//recheck
    }
    line_count++;
    
}
Line::~Line()
{

}
Line  Line ::operator+=(string str)
{
    int i=0;
    while(str[i]!='\0')
    {
        int temp=i;
        while(str[temp]!=' ' && str[temp]!='.')
        {
            temp++;
        }
        int len=temp-i;
        len+=1;
        char* word=new char[len+1];
        int x=0;
        while(len!=0)
        {
            word[x]=str[i];
            x++;
            i++;
            len--;

        }
        //i++;
        //word[x]='\0';
        addword(word,x);

    }
    

}
Line Line ::operator=(string str)
{
    // for (int i=0;i<=line_count;i++)
    // {
    //     delete []line[i];
    // }
    // delete[] line;
    line_size=0;
    line=new char*[20];
    for (int i = 0; i < 20; i++)
    {
        line[i] = new char[max_char];
        /* code */
    }
    line_count=0;

    *this += str;
}

void Line::addword(char *p,int s)
{
    bool fl=lineisfull();
    int cc=s+line_size;
    if(fl==false && cc<40)
    {
        int i=0;
        while(i<s)
        {
            line[line_count][line_size]=p[i];
            line_size++;
            i++;
        }    
    }
    else
    {

        int i=0;
        line_count++;
        line_size=i;
        while(i<s)
        {
            line[line_count][line_size]=p[i];
            line_size++;
            i++;
        }    
    }
}
char** Line::getline()
{
    return line;
}
int Line::getlinecount()
{
    return line_count;
}
int Line::getlinesize()
{
    return line_size;
}
bool Line:: lineisfull()
{
    if(line_size==max_char)
    {
        return true;

    }
    else
    {
        return false;
    }
}