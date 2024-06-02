//Maaz ALi
//22i-1042
//Assignment4


#include "Faculty.h"

Faculty::Faculty()
{
    regester = false;
    size = 0;
    Issued = NULL;
}
Faculty::Faculty(int idx, string na, string ph, string ad)
{
    setId(idx);
    regester = true;
    setName(na);
    setPhoneNumber(ph);
    setAddress(ad);
}
void Faculty::addBook(Books b1)
{
    if (Issued == NULL && b1.getId() == -1 && regester == true)
    {
        Issued = new Books[1];
        size++;
        Issued[0] = b1;
        // Issued[size].setAuthor(b1.getAuthor());
        // Issued[size].setName(b1.getName());
        // Issued[size].setID(b1.getId());
        // Issued[size]. setNumber(b1.getnumber());
        // Issued[size]. setType(b1.getType());

        // Issued[size]. set_dateissued(b1.getdayissu(),b1.getmonthissu());
        // Issued[size]. setAvailable(b1.getAvailable());
    }
    else if (b1.getId() != -1 && size < max_books_faculty)
    {
        Books *Temp = new Books[size + 1];
        for (int i = 0; i < size; i++)
        {
            Temp[i] = Issued[i];
        }
        Temp[size] = b1;
        size++;
        Issued = Temp;
        Temp = NULL;
    }
    else if (size == max_books_faculty)
    {
        cout << "\nYou have issued mximum books allowed.";
    }
    else
    {
        cout << "\nBook not issued by Admin.";
    }
}
void Faculty::remBook(Books b1)
{
    if (Issued == NULL)
    {
        cout << "\nNo Books were issued in your name.";
    }
    else if (b1.getId() != -1 && size < max_books_faculty)
    {
        Books *Temp = new Books[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (Issued[i].getId() != b1.getId())
            {
                Temp[i] = Issued[i];
            }
            else
            {
                cout << "\nBook Returned.";
            }
        }
        size--;
        delete[] Issued;
        Issued = Temp;
        Temp = NULL;
    }
    else
    {
        cout << "\nBook not issued by Admin.";
    }
}
void Faculty::wantIssue(string ty, int id1)
{
    book_id = id1;
    book_type = ty;
}
void Faculty::wantReturn(string ty, int id1)
{
    book_id = id1;
    book_type = ty;
}
void Faculty::print()
{
    int i = 0;
    while (i < size)
    {
        Issued[i].BookDisplay();
        i++;
    }
}
void Faculty::set_id(int bookid)
{
    book_id = bookid;
}
void Faculty::set_type(string ty)
{
    book_type = ty;
}
void Faculty::Regester(bool fl)
{
    regester = fl;
}
Faculty Faculty::operator=(Faculty f1)
{
    if (size != 0 && Issued != NULL)
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

void Faculty::setna(string na)
{
    setName(na);
}
void Faculty::setidx(int idz)
{
    setId(idz);
}
void Faculty::setph(string ph)
{
    setPhoneNumber(ph);
}
void Faculty::setad(string ad)
{
    setAddress(ad);
}

string Faculty::getna()
{
    return getName();
}
string Faculty::getph()
{
    return getPhoneNumber();
}
string Faculty::getad()
{
    return getAddress();
}
int Faculty::getidx()
{
    return getId();
}
Faculty::~Faculty()
{
}