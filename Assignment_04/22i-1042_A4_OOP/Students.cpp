//Maaz ALi
//22i-1042
//Assignment4


#include "Students.h"

Students::Students()
{
    regester = false;
    Issued=NULL;
}
Students::Students(int idx, string na, string ph, string ad)
{
    setId(idx);
    regester = true;
    setName(na);
    setPhoneNumber(ph);
    setAddress(ad);
}
void Students::addBook(Books  b1)
{
    if(Issued==NULL && b1.getId()==-1 && regester==true)
    {
        Issued=new Books[1];
        size++;
        Issued[size]=b1;
    }
    else if(b1.getId()!=-1 && size<max_books_Students)
    {
        Books *Temp=new Books[size+1];
        for (int  i = 0; i < size; i++)
        {
            Temp[i]=Issued[i];
        }
        Temp[size]=b1;
        size++;
        Issued=Temp;
        Temp=NULL;   
    }
    else if(size==max_books_Students)
    {
        cout<<"\nYou have issued mximum books allowed.";
    }
    else
    {
        cout<<"\nBook not issued by Admin.";
    }
}
void Students::remBook(Books  b1)
{
    if(Issued==NULL )
    {
        cout<<"\nNo Books were issued in your name.";
    }
    else if(b1.getId()!=-1 && size<max_books_Students)
    {
        Books *Temp=new Books[size-1];
        for (int  i = 0; i < size; i++)
        {
            if(Issued[i].getId()!=b1.getId())
            {
            Temp[i]=Issued[i];
            }
            else
            {
                cout<<"\nBook Returned.";
            }

        }
        size--;
        Issued=Temp;
        Temp=NULL;   
    }
    else
    {
        cout<<"\nBook not issued by Admin.";
    }
}
void Students::wantIssue(string ty, int id1,int date_issu)
{
    book_id = id1;
    book_type = ty;
}
void Students::wantReturn(string ty, int id1,int date_ret)
{
    book_id = id1;
    book_type = ty;
}
void Students::print()
{
    int i = 0;
    while (i < size)
    {
        Issued[i].BookDisplay();
        i++;
    }
}
void Students::set_id(int bookid)
{
    book_id = bookid;
}
void Students::set_type(string ty)
{
    book_type = ty;
}
void Students::Regester(bool fl)
{
    regester = fl;
}
Students Students::operator=(Students f1)
{
    if (size != 0 && Issued != NULL && f1.size>0)
    {
        size = f1.size;
        Issued = new Books[size];
        for (int i = 0; i < size; i++)
        {
            Issued[i] = f1.Issued[i];
        }
        setId(f1.getId());
        setName(f1.getName());
        regester = f1.regester;
        setAddress(f1.getAddress());
        setPhoneNumber(f1.getPhoneNumber());
        return *this;
    }
    else
    {
        setId(f1.getId());
        setName(f1.getName());
        regester = f1.regester;
        setAddress(f1.getAddress());
        setPhoneNumber(f1.getPhoneNumber());
        return *this;
    }
}

void Students::setna(string na)
{
    setName(na);
}
void Students::setidx(int idz)
{
    setId(idz);
}
void Students::setph(string ph)
{
    setPhoneNumber(ph);
}
void Students::setad(string ad)
{
    setAddress(ad);
}

string Students::getna()
{
    return getName();
}
string Students::getph()
{
    return getPhoneNumber();
}
string Students::getad()
{
    return getAddress();
}
int Students::getidx()
{
    return getId();
}

Students::~Students()
{

}