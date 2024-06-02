
//Maaz ALi
//22i-1042
//Assignment4


#include <iostream>
#include "Project.h"
#include "Project.cpp"
#include "Manager.h"
#include "Manager.cpp"
#include "Employee.h"
#include "Employee.cpp"

using namespace std;

int main()
{
    Manager *m1 = new Manager("Michael");
    Manager *m2 = new Manager("Dwight");
    Manager *m3 = new Manager("Jim");
    Manager *m4 = new Manager("Andy");

    string s1 = "Project: 1";
    string s2 = "Project: 2";
    string s3 = "Project: 3";
    string s4 = "Project: 4";

    Project p1, p2, p3, p4;
    p1.setTitle(s1);
    p2.setTitle(s2);
    p3.setTitle(s3);
    p4.setTitle(s4);

    {
        Employee EMP[15];

        EMP[0].setName("Adam");
        EMP[0].setProject(s1);
        EMP[0].allocateManager(m1);
        EMP[1].setName("Bob");
        EMP[1].setProject(s1);
        EMP[1].allocateManager(m1);
        EMP[2].setName("Carl");
        EMP[2].setProject(s2);
        EMP[2].allocateManager(m2);
        EMP[6].setName("Dave");
        EMP[6].setProject(s2);
        EMP[6].allocateManager(m2);
        EMP[3].setName("Eve");
        EMP[3].setProject(s3);
        EMP[3].allocateManager(m3);
        EMP[4].setName("Fred");
        EMP[4].setProject(s3);
        EMP[4].allocateManager(m3);
        EMP[5].setName("Gail");
        EMP[5].setProject(s3);
        EMP[5].allocateManager(m3);
        EMP[7].setName("Hazel");
        EMP[7].setProject(s3);
        EMP[7].allocateManager(m3);
        EMP[8].setName("Ida");
        EMP[8].setProject(s3);
        EMP[8].allocateManager(m3);
        EMP[9].setName("Jem");
        EMP[10].setName("Ada");
        EMP[11].setName("Shelby");
        EMP[12].setName("Ford");
        EMP[13].setName("Arthur");
        EMP[13].setProject(s4);
        EMP[13].allocateManager(m4);
        EMP[14].setName("Arnold");
        EMP[14].setProject(s4);
        EMP[14].allocateManager(m4);

        cout << "\n";
        for (int i = 0; i < 15; i++)
        {
            cout << i + 1 << ".";
            EMP[i].print();
        }
    }
    cout << "\nEmployee is deleted so now project is destroyed because without any employee there is no project. Because Employee is composition.\n";

    // EMP[0].print();

    cout << "\nBut Manager are still present because manager is agrigated. E.g::::\n";
    cout << m1->getmanager();
    cout << "\n";
    cout << m2->getmanager();
    cout << "\n";
    cout << m3->getmanager();
    cout << "\n";
    cout << m4->getmanager();
    cout << "\n";
    delete m1;
    delete m2;
    delete m3;
    delete m4;

    return 0;
}