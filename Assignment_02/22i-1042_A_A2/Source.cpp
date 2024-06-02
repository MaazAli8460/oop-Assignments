#include <iostream>

#include "Record.h"

using namespace std;



int main()

{

    string c;
    cout << "\nEnter the name of file:";
    cin >> c;

    char* fname;
    int i=0;
    while(c[i]!='\0')
    {
        i++;
    }
    int x=i+5;//4 for .txt
    string c1=".txt";
    fname = new char[x];
    i=0;
    while(c[i]!='\0')
    {
        fname[i]=c[i];
        i++;        
    }
    int z=0;
    while(c1[z]!='\0')
    {
        fname[i]=c1[z];
        i++;
        z++;
    }
    fname[x-1]='\0';
    cout<<"\nFile Name:"<<fname<<" created sucessfully.";

    //char fname[]="maaz.txt";
    Record r(fname);
    char choice='c',choice2;
    int ch1=0;
    string sp;
    char* sp1;
    while(choice=='c' || choice=='C')
    {
        cout<<"\n _____________________________________________________________________";
        cout<<"\n|                        RECORD HANDLING                              |  ";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n _____________________________________________________________________ ";
        cout<<"\n|You can select operations to perform on the file from the table below|";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 1 to Input data into the table                               |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 2 to Delete data from file                                   |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 3 to Search data from Record                                 |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 4 to Display file                                            |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 5 to Insert data in file                                     |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 6 to Replace data from Record                                |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|->Press 7 to Count total data in file                                |";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\nEnter your choice:";
        cin>>ch1;
        switch (ch1)
        {
        case 1:
            while(choice2!='s')
            {
            r.record_Input();
            cout<<"\nEnter s if you want to stop inserting data in file else press any key:";
            cin>>choice2;
            }
            choice2='\0';
            break;
        case 2:
            cout<<"\nEnter the name you want to delete from record:";
            getline(cin>>ws,sp);
            cin.ignore();
            i=0;
            while(sp[i]!='\0')
            {
            i++;
            }
            sp1=new char[i+1];
            i=0;
            while(sp[i]!='\0')
            {
            sp1[i]=sp[i];
            i++;        
            }
            sp1[i]='\0';
            r.delete_Record(sp1);
            sp="";
            delete[]sp1;
            sp1=NULL;
            break;

        case 3:
            cout<<"\nEnter the name you want to search from record:";
            getline(cin>>ws,sp);
            cin.ignore();
            i=0;
            while(sp[i]!='\0')
            {
            i++;
            }
            sp1=new char[i+1];
            i=0;
            while(sp[i]!='\0')
            {
            sp1[i]=sp[i];
            i++;        
            }
            sp1[i]='\0';
            r.record_Search(sp1);
            sp="";
            delete[]sp1;
            sp1=NULL;
            break;

        case 4:
            r.record_Display();
            break;
        case 5:
            cout<<"\nEnter the name after which you want to insert in record:";
            getline(cin>>ws,sp);
            cin.ignore();
            i=0;
            while(sp[i]!='\0')
            {
            i++;
            }
            sp1=new char[i+1];
            i=0;
            while(sp[i]!='\0')
            {
            sp1[i]=sp[i];
            i++;        
            }
            sp1[i]='\0';
            r.record_Insert(sp1);
            sp="";
            delete[]sp1;
            sp1=NULL;
            break;
        
        case 6:
            cout<<"\nEnter the name which you want to replace in record:";
            getline(cin>>ws,sp);
            cin.ignore();
            i=0;
            while(sp[i]!='\0')
            {
            i++;
            }
            sp1=new char[i+1];
            i=0;
            while(sp[i]!='\0')
            {
            sp1[i]=sp[i];
            i++;        
            }
            sp1[i]='\0';
            r.record_Replace(sp1);
            sp="";
            delete[]sp1;
            sp1=NULL;
            break;

        case 7:
            cout<<"\nTotal count of records in file:"<<r.record_Count();
            break;

        default:
            cout<<"\nWrong choice.";
            break;
        }
        cout<<"\n _____________________________________________________________________";
        cout<<"\n|                   PRESS 'c' TO CONTINUE                             |  ";
        cout<<"\n|_____________________________________________________________________|";
        cout<<"\n|                   PRESS 'x' TO EXIT                                 |  ";
        cout<<"\n|_____________________________________________________________________|\n:";
        cin>>choice;
    }



}


