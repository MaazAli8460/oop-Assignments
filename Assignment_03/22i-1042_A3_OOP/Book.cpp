//Maaz ALi
//22i-1042
//Assignment#03

#include "Book.h"
#include "Line.h"
#include "Page.h"

#include <iostream>

using namespace std;
int Book:: tt=0;
Book::Book() {
    size = 0;
    pagecount = 0;
    flag=false;
    book = new char **[1];
    book=NULL;
}

Book::Book(int l) {
    pagecount = 0;
    size = l;
    flag=false;
    book = new char **[l];
    for (int i = 0; i < l; i++) {
        book[i] = new char *[20];
        for (int j = 0; j < 20; j++) {
            book[i][j] = new char[40];
        }
    }
}

void Book::operator+=(Page& p1) {
    if(flag==false)
    {
    int temp = p1.getlinenum();
    char **t3 = p1.getpage();
    if (pagecount < size) {
        for (int i = 0; i <= temp; i++) {
            for (int j = 0; j < 40; j++) {
                book[pagecount][i][j] = t3[i][j];
            }
        }
        
        pagecount++;
    }
    }
    else if(flag==true)
    {

    }
    //return *this;
}
char*** Book:: operator+ (Book& b)
{
    Book temp(size+b.size);
    for (int i = 0; i < size; i++) 
    {    
        for (int j = 0; j < 20; j++) 
        {
            for (int k = 0; k < 40; k++) 
            {
                temp.book[i][j][k] = book[i][j][k];
            }
            }
    }
    for (int i = 0; i < b.size; i++) 
    {
        for (int j = 0; j < 20; j++) 
        {
            for (int k = 0; k < 40; k++) 
            {
                temp.book[i+size][j][k] = b.book[i][j][k];
            }
        }
    }
    tt=size+b.size;
    char *** ttpp= new char**[size+b.size];
    for (int i = 0; i < size+b.size; i++)
    {
        ttpp[i] = new char*[20];
        for (int j = 0; j < 20; j++)
        {
            ttpp[i][j] = new char[40];
        }
    }
    for (int i = 0; i < size+b.size; i++)
    {
        
        for (int j = 0; j < 20; j++)
        {
            for (int k = 0; k < 40; k++)
            {
                ttpp[i][j][k] = temp.book[i][j][k];
            }    
        }
    }
    return ttpp;

}

Book Book:: operator=(char*** p)
{
    size=tt;
    delete []book;
    book=p;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < 20; j++)
    //     {
    //         for (int k = 0; k < 40; k++)
    //         {
    //             book[i][j][k] = p[i][j][k];
    //         }
    //     }
    // }
    //cout<<*this;
    return *this;            
}


char** &Book::operator[](int x)
{
    flag=true;
    return book[x];
}

Book::~Book() {
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < 20; j++) {
    //         delete[] book[i][j];
    //     }
    //     delete[] book[i];
    // }
    // delete[] book;
}
ostream operator<<(ostream &o, Book &b)
{
    //b.print(b);
    int i=1;
    for(int j=0;j<b.size;j++)
    {
        o<<"-----------Page-"<<i<<"------------\n";
        i++;
        for(int k=0;k<20;k++)
        {
            for(int l=0;l<40;l++)
            {
                o<<b.book[j][k][l];
            }
            o<<endl;
        }       
    }
    //return o;
}
void Book::print()
{
    int i=1;
    for(int j=0;j<size;j++)
    {
        cout<<"-----------Page-"<<i<<"------------\n";
        i++;
        for(int k=0;k<20;k++)
        {
            for(int l=0;l<40;l++)
            {
                cout<<book[j][k][l];
            }
            cout<<endl;
        }       
    }
}

