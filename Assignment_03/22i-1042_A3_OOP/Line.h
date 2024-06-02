#ifndef LINE_H
#define LINE_H

#pragma once
#include<iostream>
using namespace std;
class Line
{
private:
    const int max_char=40;
    char **line;
    int line_count;
    int line_size;
public:
    Line();
    Line(string str);
    ~Line();
    bool lineisfull();
    Line(const Line& l);
    Line operator+=(string str);
    Line operator=(string str);

    void addword(char *p,int s);
    char** getline();
    int getlinecount();
    int getlinesize();





};

#endif