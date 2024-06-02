//Maaz ALi
//22i-1042
//Assignment4



#include "Admin.h"

Admin::Admin()
{
    name = "Maaz Ali";
    password = "I_LOVE_OOP";
    f1 = NULL;
    s1 = NULL;
}

Admin ::Admin(string na, string pass)
{
    name = na;
    f1 = NULL;
    s1 = NULL;
    password = pass;
}
void Admin::searchRecord(int id1)
{
    l1.libsearch(id1);
}

void Admin::addRecord(int id1, string na1, string ad1, int num1, string date1, string ty)
{
    l1.addBook(id1, na1, ad1, num1, date1, true, ty);
}

bool Admin::isMember(Faculty ft)
{
    if (ft.type == "Faculty\0")
    {
        if (ft.regester == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool Admin::isMember(Students st)
{
    if (st.type == "Students\0")
    {
        if (st.regester == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void Admin::displayLibrary()
{
    l1.DisplayLibrary();
}
Books Admin::issueBookfac(int id, string type) // check
{
    
    Books b;
    if ((l1.libsearch(id) == true))
    {
        if (f1 != NULL)
        {
            l1.issueBook(id, type);
            b = (l1.temp(id, type));
            int i=l1.getIssuday(id);
            int j=l1.getIssuemonth(id);
            b.set_dateissued(i,j);
            return b;
        }
        else
        {
            cout << "\nNOT REGESTERED.";
            b.setID(-1);
            return b;
        }
    }
    else
    {
        cout << "\nBook was not issued.";
        b.setID(-1);
        return b;
    }
}
Books Admin::issueBookstu(int id, string type)
{
    
    Books b;
    if (l1.libsearch(id) == true)
    {
        if (s1 != NULL )
        {
            l1.issueBook(id, type);
            b = (l1.temp(id, type));
            int i=l1.getIssuday(id);
            int j=l1.getIssuemonth(id);
            b.set_dateissued(i,j);
            return b;
        }
        else
        {
            cout << "\nNOT REGESTERED.";
            b.setID(-1);
            return b;
        }
    }
    else
    {
        cout << "\nBook was not issued.";
        b.setID(-1);
        return b;
    }
}
Books Admin::returnBookstu(int id, string type)
{
    l1.returnBook(id, type);
    
    bool flagtp = generateChalanstu(id, type);
    if (flagtp)
    {
        cout << "\nYou are returning late. you will be fined.";
        cout<<"\nDay Issue:"<<l1.getIssuday(id)<<"   Month Issue:"<<l1.getIssuemonth(id);
        cout<<"\nDay Returned:"<< l1.getReturnday(id)<<"  Month Returned:"<<l1.getReturnmonth(id);
        //temp
        cout<<"\n-----------\n";
        l1.getIssueDate(id);
        l1.getReturnDate(id);
    }
    else
    {
        cout << "\nYou have returned on time. You will not be fined.";
        cout<<"\nDay Issue:"<<l1.getIssuday(id)<<"   Month Issue:"<<l1.getIssuemonth(id);
        cout<<"\nDay Returned:"<< l1.getReturnday(id)<<"  Month Returned:"<<l1.getReturnmonth(id);
        cout<<"\n-----------\n";
        l1.getIssueDate(id);
        l1.getReturnDate(id);
    }
    Books b;
    if (l1.libsearch(id) == false)
    {
        b = (l1.temp(id, type));
        removeBookstu(b);
        return b;
    }
    else
    {
        cout << "\nBook was not issued.";
        b.setID(-1);
        return b;
    }
}
Books Admin::returnBookfac(int id, string type)
{
    Books b;
    l1.returnBook(id, type);

    bool flagtp = generateChalanfac(id, type);
    if (flagtp)
    {
        cout << "\nYou are returning late. you will be fined.";
        cout<<"\nDay Issue:"<<l1.getIssuday(id)<<"   Month Issue:"<<l1.getIssuemonth(id);
        cout<<"\nDay Returned:"<< l1.getReturnday(id)<<"  Month Returned:"<<l1.getReturnmonth(id);
        cout<<"\n-----------\n";
        l1.getIssueDate(id);
        l1.getReturnDate(id);
    }
    else
    {
        cout << "\nYou have returned on time. You will not be fined.";
        cout<<"\nDay Issue:"<<l1.getIssuday(id)<<"   Month Issue:"<<l1.getIssuemonth(id);
        cout<<"\nDay Returned:"<< l1.getReturnday(id)<<"  Month Returned:"<<l1.getReturnmonth(id);
        cout<<"\n-----------\n";
        l1.getIssueDate(id);
        l1.getReturnDate(id);
    }
    if (l1.libsearch(id) == true)
    {

        b = (l1.temp(id, type));
        removeBookfac(b);
        return b;
    }
    else
    {
        cout << "\nBook was not issued.";
        b.setID(-1);
        return b;
    }
}
bool Admin::generateChalanfac(int id, string types)
{

    Books btemp = l1.temp(id, types);
    int day, month, day2, month2;
    day = l1.getIssuday(id);
    month = l1.getIssuemonth(id);
    day2 = l1.getReturnday(id);
    month2 = l1.getReturnmonth(id);
    int tempcheck = 0;
    for (int i = month; i <= month2; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == month && j == 0)
            {
                j = day;
            }
            tempcheck++;
        }
    }
    tempcheck /= 7;
    if (tempcheck < duefac)
    {
        return false;
    }
    else
    {
        return true;
    }
    return false;
}
void Admin::removeBookstu(Books &b)
{
    s1->remBook(b);
}
Books Admin::ReturnRecord(int id1,string ty)
{
    Books b;
    b=l1.temp(id1,ty);
    return b;
}

void Admin::removeBookfac(Books &b)
{
    f1->remBook(b);
}
bool Admin::generateChalanstu(int id, string types)
{

    Books btemp = l1.temp(id, types);

    int day, month, day2, month2;
    day = l1.getIssuday(id);
    month = l1.getIssuemonth(id);
    day2 = l1.getReturnday(id);
    month2 = l1.getReturnmonth(id);
    int tempcheck = 0;
    for (int i = month; i <= month2; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == month && j == 0)
            {
                j = day;
            }
            tempcheck++;
        }
    }
    tempcheck /= 7;
    if (tempcheck < duestu)
    {
        return false;
    }
    else
    {
        return true;
    }
    return false;
}
void Admin::regesterMember(Faculty &ftemp)
{
    if (f1 == NULL && ftemp.regester==true)
    {
        f1 = new Faculty[1];
        f1[0] = ftemp;
        f_size++;
    }
    else if(ftemp.regester==true)
    {
        Faculty *tt = new Faculty[f_size + 1];
        for (int i = 0; i < f_size; i++)
        {
            tt[i] = f1[i];
        }
        tt[f_size] = ftemp;
        delete[] f1;
        f1 = tt;
        f_size++;
        tt = NULL;
    }
}
void Admin::regesterMember(Students &stemp)
{
    if (s1 == NULL && stemp.regester==true)
    {
        s1 = new Students[1];
        s1[0] = stemp;
        stu_size++;
    }
    else if(stemp.regester==true)
    {
        Students *tt = new Students[stu_size + 1];
        for (int i = 0; i < stu_size; i++)
        {
            tt[i] = s1[i];
        }
        tt[stu_size] = stemp;
        delete[] s1;
        s1 = tt;
        stu_size++;
        tt = NULL;
    }
}
int Admin::getIssuday1(int id)
{
    return this->l1.getIssuday(id);
}
int Admin::getReturnday1(int id)
{
    return this->l1.getReturnday(id);

}
int Admin::getIssuemonth1(int id)
{
    return this->l1.getIssuemonth(id);
}
int Admin::getReturnmonth1(int id)
{
    return this->l1.getReturnmonth(id);
}
void Admin::viewRecord()
{
    cout<<"\n---------------Faculty---------------";
    for (int i = 0; i < f_size; i++)
    {
        f1[i].print();
        /* code */
    }
    cout<<"\n--------------Students---------------";
    for (int i = 0; i < stu_size; i++)
    {
        s1[i].print();
        /* code */
    }
    cout<<"\n-------------------------------------";
    
    
}

Admin::~Admin()
{
}