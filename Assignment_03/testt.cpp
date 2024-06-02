// #include <iostream>
// #include <string>
// using namespace std;

// class Example6 {
//     string* ptr;
//   public:
//     Example6 (const string& str) : ptr(new string(str)) {}
//     ~Example6 () {delete ptr;}
//     // move constructor
//     Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}
//     // move assignment
//     Example6& operator= (Example6&& x) {
//       delete ptr; 
//       ptr = x.ptr;
//       x.ptr=nullptr;
//       return *this;
//     }
//     // access content:
//     const string& content() const {return *ptr;}
//     // addition:
//     Example6 operator+(const Example6& rhs) {
//       return Example6(content()+rhs.content());
//     }
// };


// int main () {
//   Example6 foo ("Exam");
//   Example6 bar = Example6("ple");   // move-construction
  
//   foo = foo + bar;                  // move-assignment

//   cout << "foo's content: " << foo.content() << '\n';
//   return 0;
// }
///////////////////////////
////////////////DOWNCASTING
///////////////////////////

#include <iostream>
using namespace std;

class Person
{
	//content of Person
};


class Employee:public Person
{
public:
	Employee(string fName, string lName, double sal)
	{
		FirstName = fName;
		LastName = lName;
		salary = sal;
	}
	string FirstName;
	string LastName;
	double salary;
	void show()
	{
		cout << "First Name: " << FirstName << " Last Name: " << LastName << " Salary: " << salary<< endl;
	}
	void addBonus(double bonus)
	{
		salary += bonus;
	}
};

class Manager :public Employee
{
public:
	Manager(string fName, string lName, double sal, double comm) :Employee(fName, lName, sal)
	{
		Commision = comm;
	}
	double Commision;
	double getComm()
	{
		return Commision;
	}
};

class Clerk :public Employee
{
public:
	Clerk(string fName, string lName, double sal, Manager* man) :Employee(fName, lName, sal)
	{
		manager = man;
	}
	Manager* manager;
	Manager* getManager()
	{
		return manager;
	}
};

void congratulate(Employee* emp)
{
	cout << "Happy Birthday!!!" << endl;
	emp->addBonus(200);
	emp->show();
};

int main()
{
    //pointer to base class object
    Employee* emp;
    //object of derived class
    Manager m1("Steve", "Kent", 3000, 0.2);
    //implicit upcasting
    emp = &m1;
    //explicit downcasting from Employee to Manager
    Manager* m2 = (Manager*)(emp);
    m2->show();

    Employee e1("Peter", "Green", 1400);
    //try to cast an employee to Manager
    Manager* m3 = (Manager*)(&e1);
    m3->show();
    cout << m3->getComm() << endl;
    int c = 9;
    int &s = c;
    int nigger=8;
    s=nigger;
    cout<<endl<<s;
    return 0;
}