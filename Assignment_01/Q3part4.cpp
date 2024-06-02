#include<iostream>
using namespace std;

	void space(int str, int e) //This is the recursive Function to Print the Pattern
	{
		if (str==e)
		return;
		cout<<" ";
		space(++str,e);
	}	
	
	void PrintPattern3(int start, int end) //This is the Recursive Function to Print the "X" Pattern
	{
		if (start==(start+end)/2) //To Take the middle staric we have used This Operation
		{
			cout<<'*'<<endl;
			return;
		}
		
		space(start, end);
		cout<<"*";
		cout<<endl;
		
		PrintPattern3(start+1, end-1);

		space(start, end);
		cout<<"*";
		cout<<endl;
	}
	
int main()
{
cout<<"This is the Pattern to print the X" <<endl;
PrintPattern3(5,25);
}