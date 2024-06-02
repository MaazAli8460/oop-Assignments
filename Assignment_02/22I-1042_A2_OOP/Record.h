#ifndef RECORD_H

#define RECORD_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Record
{

private:
    char* fileName;

    int age;

    char* name;

    char* address;

    float cgpa;

public:
    Record()

    {

        age = 0;

        cgpa = 0.0;

        name = NULL;

        address = NULL;
    };

    Record(char* str)
    {

        fileName = str;
    };

    int record_Input()//function will input record
    {
        string na, ad;
        fstream file;

        file.open(fileName, ios::out | ios::app);

        int count = 0;

        cout << "File Name is : " << fileName << endl;

        cout << " Enter name of the student : " << endl;
        getline(cin >> ws, na);
        cin.ignore();

        cout << " Enter address of the student : " << endl;
        getline(cin >> ws, ad);
        cin.ignore();

        cout << " Enter age of the student : " << endl;
        cin >> age;
        while (age < 0 || age > 110)
        {
            cout << " Enter age of the student : " << endl;
            cin >> age;
        }

        cout << " Enter CGPA of the student : " << endl;
        cin >> cgpa;

        while (cgpa < 0.0f || cgpa > 4.0f)
        {
            cout << " Enter CGPA of the student : " << endl;
            cin >> cgpa;
        }

        if (file.good())
        {

            file << na << "\t\t\t" << ad << "\t\t\t" << age << "\t" << cgpa << "\n";
            count = 1;
        }

        else
        {
            cout << "File not found" << endl;
            count = 0;
        }

        file.close();

        return count;
    };

    void record_Display()//functions displays record
    {
        fstream wrdata(fileName, ios::in);
        int position, count = 0;
        string userdata = "", temp1, temp2;
        while (getline(wrdata, temp1))
        {
            position = temp1.find("\t");
            temp2 = temp1.substr(0, position);
            userdata += temp1 + "\n";


            count++;           
        }
        wrdata.close();

        string name1, add, age1, gpa;

        for (int i = 0; i < count; i++)
        {
            position = userdata.find("\t\t\t");
            name1 = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);

            position = userdata.find("\t\t\t");
            add = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);


            position = userdata.find("\t");
            age1 = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);

            position = userdata.find("\n");
            gpa = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);

            cout << name1 << "\t\t\t" << add << "\t\t\t" << age1 << "\t" << gpa  << endl;

        } 
    }



    int record_Search(char* name)//searches the record whose name is given

    {
        fstream wrdata(fileName, ios::in);
        int position, count = 0;
        string userdata = "", temp1, temp2;
        while (getline(wrdata, temp1))
        {
            position = temp1.find("\t");
            temp2 = temp1.substr(0, position);
            if (name == temp2)
            {
                userdata += temp1 + "\n";
                count++;
            }
        }
        wrdata.close();

        string name1, add, age1, gpa;
        if (count == 0)
        {
            cout << " NO RECORD FOUND!!!" << endl;
            return count;
        }
        for (int i = 0; i < count; i++)
        {
            position = userdata.find("\t\t\t");
            name1 = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);

            position = userdata.find("\t\t\t");
            add = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);


            position = userdata.find("\t");
            age1 = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);

            position = userdata.find("\n");
            gpa = userdata.substr(0, position);
            userdata = userdata.substr(position + 1);

        }

        cout << name1 << "\t\t\t" << add << "\t\t\t" << age1 << "\t" << gpa  << endl;
        return count;
    };

    int record_Count()//keeps count of total records

    {
        fstream wrdata(fileName, ios::in);
        int position, count = -1;
        string userdata = "", temp1, temp2;
        while (getline(wrdata, temp1))
        {
            position = temp1.find("\t");
            temp2 = temp1.substr(0, position);
            count++;
        }
        wrdata.close();
        return count+1;
    };


    int delete_Record(char* check_name)//deletes the record whose name is given

    {
        int count1=0;

        ofstream of;
        of.open("temp.txt");

        fstream wrdata(fileName, ios::in);
        int position, age1=0, count=0;
        float gpa;
        string userdata,temp1, temp2, name1, add;
        while (getline(wrdata, temp1))
        {
            position = temp1.find("\t");
            temp2 = temp1.substr(0, position);
            userdata += temp1 + "\n";
            count++;

            if (check_name == temp2)
            {
                cout << "\nRecord Deleted" << endl;
                count1++;
            }

            else
            {
                of << temp1 << "\n";

            }
        }
        wrdata.close();
        of.close();

        remove(fileName);
        rename("temp.txt", fileName);
        if(count1==0)
        {
            cout<<"\nRECORD NOT FOUND !!!!!";
            return 0;
        }

        return count;
    }


    int record_Insert(char* check_name)//insersts a new record after the name given
    {
        int age1,count1 = 0;
        float cgpa1;
        int position, count = 0;
        string na, ad1;
        ofstream of;
        of.open("temp.txt");
        fstream wrdata(fileName, ios::in);
        
        string userdata, temp1, temp2;

        cout << " Enter name of the student : " << endl;
        getline(cin >> ws, na);
        cin.ignore();

        cout << " Enter address of the student : " << endl;
        getline(cin >> ws, ad1);
        cin.ignore();
  

        cout << " Enter age of the student : " << endl;
        cin >> age1;
        while (age1 < 0 || age1 > 110)

        {
            cout << " Enter age of the student : " << endl;
            cin >> age1;
        }

        cout << " Enter CGPA of the student : " << endl;
        cin >> cgpa1;

        while (cgpa1 < 0.0f || cgpa1 > 4.0f)
        {
            cout << " Enter CGPA of the student : " << endl;
            cin >> cgpa1;
        }

 
        while (getline(wrdata, temp1))
        {
            position = temp1.find("\t");
            temp2 = temp1.substr(0, position);
            userdata += temp1 + "\n";
            count++;

            if (check_name == temp2)
            {
                count1++;
                of << temp1 << "\n";
                of << na << "\t\t\t" << ad1 << "\t\t\t" << age1 << "\t" << cgpa1 << endl;

            }

            else
            {
                of << temp1<<endl;

            }
        }
        wrdata.close();
        of.close();

        remove(fileName);
        rename("temp.txt", fileName);

        if(count1==0)
        {
            cout<<"\nRECORD NOT FOUND !!!!!";
            return 0;
        }

        return count;
    }

    void record_Replace(char* check_name)//replaces the record with new record

    {
        int age1,count1=0;
        float cgpa1;
        int position, count = 0;
        string na, ad1;
        ofstream of;
        of.open("temp.txt");
        fstream wrdata(fileName, ios::in);

        string userdata, temp1, temp2;

        cout << " Enter name of the student : " << endl;
        getline(cin >> ws, na);
        cin.ignore();

        cout << " Enter address of the student : " << endl;
        getline(cin >> ws, ad1);
        cin.ignore();


        cout << " Enter age of the student : " << endl;
        cin >> age1;
        while (age1 < 0 || age1 > 110)

        {
            cout << " Enter age of the student : " << endl;
            cin >> age1;
        }

        cout << " Enter CGPA of the student : " << endl;
        cin >> cgpa1;

        while (cgpa1 < 0.0f || cgpa1 > 4.0f)
        {
            cout << " Enter CGPA of the student : " << endl;
            cin >> cgpa1;
        }


        while (getline(wrdata, temp1))
        {
            position = temp1.find("\t");
            temp2 = temp1.substr(0, position);
            userdata += temp1 + "\n";
            count++;

            if (check_name == temp2)
            {
                count1++;
                of << na << "\t\t\t" << ad1 << "\t\t\t" << age1 << "\t" << cgpa1 << endl;
            }

            else
            { 
                of << temp1 << "\n";

            }
        }
        wrdata.close();
        of.close();

        remove(fileName);
        rename("temp.txt", fileName);

        if(count1==0)
        {
            cout<<"\nRECORD NOT FOUND !!!!!";
            return ;
        }
      
    }

    ~Record()

    {

        cout << " \n Destructor called" << endl;
    };
};

#endif
