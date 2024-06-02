//Maaz ALi
//22i-1042
//Assignment4


#include "Employee.h"

Employee::Employee()
{
    name = "";
    string Er = "Error";
    p.setTitle(Er);
    Manager mtemp(Er);
}
void Employee::setName(string n)
{
    name = n;
}
void Employee::setProject(string t)
{
    p.setTitle(t);
}
void Employee::allocateManager(Manager *m)
{
    p.setManager(m);
}
void Employee::print()
{
    cout << "\tName: " << name << "\t";
    string comp;
    comp = p.getTitle();

    bool flag = false;
    int i = 0;
    string Er = "Error";
    while (comp[i] != '\0')
    {
        if (comp[i] == Er[i])
        {
            flag = true;
            i++;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag == false)
    {
        Manager *m1 = p.getManager();
        string cps = m1->getmanager();
        cout << "Project: " << p.getTitle() << "\t";
        cout << "Manager: " << cps << endl;
    }
    else
    {

        cout << "Project: "
             << "Not Alocated\t";
        cout << "Manager: "
             << "Not Alocated" << endl;
    }
}
Employee::~Employee()
{
    cout << "\nEmployee Destructor called.";
}