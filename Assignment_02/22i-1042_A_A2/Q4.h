#include<iostream>

using namespace std;

struct file
{
    string name;
    string address;
    int age;
    float cgpa;
};

class Record
{
private :
// add required data members if required
char* fileName;
public :
Record (char* str)  //constructor will create the file with the given file name.
{
    fileName = str;
    file f;
    f.name = "";
    f.address = "";
    f.age = 0;
    f.cgpa = 0;   
}
int record_Input(); /// input function will get the multiple data (name ,address,age and CGPA )from the user and adds to the file,
void record_Display() ;// the function will display the all the data store in file.
int delete_Record();/// function will delete the complete record that is data(name ,address ,age and CGPA ) of person with given name.
int record_Count();//function will count the total records stored in the file.
int record_Search(); // Allows to search the file with a particular name
int record_Insert();//it will allow the user to insert the data (name ,address,age and CGPA ) after some name in the file
void record_Replace();//it will allow the user to replace the data (name ,address,age and CGPA ) of given name in the file
~Record();
} ;