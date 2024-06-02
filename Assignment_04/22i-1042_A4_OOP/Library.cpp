//Maaz ALi
//22i-1042
//Assignment4



#include "Library.h"

Library::Library()
{
    current_size = 0;
    Catalogue = NULL;
}
bool Library::libsearch(int id)
{
    int i = 0;
    while (i < current_size)
    {
        if (Catalogue[i].getId() == id)
        {
            return true;
        }
        i++;
        /* code */
    }
    cout << "\nRecord not found!!!!";
    return false;
}
Books Library::temp(int id1, string ty)
{
    int i = 0;
    while (i < current_size)
    {
        if (Catalogue[i].getId() == id1)
        {
            break;
        }
        i++;
        /* code */
    }
    return Catalogue[i];
}

void Library::addBook(int id1, string na1, string ad1, int num1, string date1, bool flag, string ty)
{
    // cout<<"\n"<<current_size<<endl;
    if (current_size == 0)
    {
        Catalogue = new Books[1];
        Catalogue[current_size].setAuthor(ad1);
        Catalogue[current_size].setAvailable(flag);
        Catalogue[current_size].setName(na1);
        Catalogue[current_size].setNumber(num1);
        Catalogue[current_size].setID(id1);
        Catalogue[current_size].setType(ty);
        Catalogue[current_size].setDate(date1);
        current_size += 1;
    }
    else if (current_size < max_allowed && current_size > 0)
    {
        Books *b = new Books[current_size + 1];
        for (int i = 0; i < current_size; i++)
        {
            b[i] = Catalogue[i];
        }
        b[current_size].setAuthor(ad1);
        b[current_size].setAvailable(flag);
        b[current_size].setName(na1);
        b[current_size].setNumber(num1);
        b[current_size].setID(id1);
        b[current_size].setType(ty);
        b[current_size].setDate(date1);

        current_size += 1;
        delete[] Catalogue;
        Catalogue = b;
        b = NULL;
    }
    else
    {
        cout << "\nError Max allowed = 10.";
    }
}
void Library::issueBook(int id1, string ty)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else
    {
        for (int i = 0; i < current_size; i++)
        {
            string tempauthor, temptype, tempname;
            int tempid;
            temptype = Catalogue[i].getType();
            tempid = Catalogue[i].getId();
            bool impflag = Catalogue[i].getAvailable();
            if (tempid == id1 && temptype == ty && impflag == true)
            {
                Catalogue[i].setAvailable(false);
                cout << "\nEnter day:";
                int day, month, year;
                cin >> day;
                cout << "\nEnter month:";
                cin >> month;
                cout << "\nEnter year:";
                cin >> year;
                Catalogue[i].set_dateissued(day, month);
                break;
            }
            else if (tempid == id1 && temptype == ty && impflag == false)
            {
                cout << "\nBook is already Issued. ";
            }
        }
    }
}
void Library::getIssueDate(int id)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else if (libsearch(id))
    {
        for (int i = 0; i < current_size; i++)
        {
            if (Catalogue[i].getId() == id)
            {
                cout << "\nIssue Date : " << Catalogue[i].getdayissu() << endl;
                cout << "\nIssue Month: " << Catalogue[i].getmonthissu() << endl;
            }
        }
    }
}
void Library::getReturnDate(int id)
{

    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else if (libsearch(id))
    {
        for (int i = 0; i < current_size; i++)
        {
            if (Catalogue[i].getId() == id)
            {
                cout << "\nIssue Date : " << Catalogue[i].getdayretu() << endl;
                cout << "\nIssue Month: " << Catalogue[i].getmoretu() << endl;
            }
        }
    }
}
int Library::getIssuday(int id)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else if (libsearch(id))
    {
        for (int i = 0; i < current_size; i++)
        {
            if (Catalogue[i].getId() == id)
            {
                return Catalogue[i].getdayissu();
            }
        }
    }
}
int Library::getReturnday(int id)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else if (libsearch(id))
    {
        for (int i = 0; i < current_size; i++)
        {
            if (Catalogue[i].getId() == id)
            {
                return Catalogue[i].getmonthissu();
            }
        }
    }
}
int Library::getIssuemonth(int id)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else if (libsearch(id))
    {
        for (int i = 0; i < current_size; i++)
        {
            if (Catalogue[i].getId() == id)
            {
                return Catalogue[i].getdayretu();
            }
        }
    }
}
int Library::getReturnmonth(int id)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else if (libsearch(id))
    {
        for (int i = 0; i < current_size; i++)
        {
            if (Catalogue[i].getId() == id)
            {
                return Catalogue[i].getmoretu();
            }
        }
    }
}
void Library::returnBook(int id1, string ty)
{
    if (Catalogue == NULL)
    {
        cout << "\nError Library Empty.";
    }
    else
    {
        for (int i = 0; i < current_size; i++)
        {
            string tempauthor, temptype, tempname;
            int tempid;
            temptype = Catalogue[i].getType();
            tempid = Catalogue[i].getId();
            bool impflag = Catalogue[i].getAvailable();
            if (tempid == id1 && temptype == ty && impflag == false)
            {
                Catalogue[i].setAvailable(true);
                cout << "\nEnter day:";
                int day, month, year;
                cin >> day;
                cout << "\nEnter month:";
                cin >> month;
                cout << "\nEnter year:";
                cin >> year;
                Catalogue[i].set_dateret(day, month);
                cout << "\nBook was returned.";
                break;
            }
            else if (tempid == id1 && temptype == ty && impflag == true)
            {
                cout << "\nBook was never issued. ";
            }
        }
    }
}
void Library::DisplayLibrary()
{
    for (int i = 0; i < current_size; i++)
    {
        Catalogue[i].BookDisplay();
    }
}
Library::~Library()
{
}