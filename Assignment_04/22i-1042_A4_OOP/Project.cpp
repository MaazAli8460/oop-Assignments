#include "Project.h"

Project::Project()
{
    title = "";
    m = nullptr;
}
string Project ::getTitle()
{
    return title;
}
void Project ::setTitle(string t)
{
    title = t;
}
Manager *Project ::getManager()
{
    return m;
}

void Project::setManager(Manager *m1)
{
    if (m == nullptr)
    {
        m = new Manager();
    }
    string s1 = m1->getmanager();
    m->setname(s1);
}
Project::~Project()
{
    // cout<<"\nProject Destructor called.";
    delete m;
}