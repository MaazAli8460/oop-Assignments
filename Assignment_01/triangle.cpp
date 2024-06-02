#include<iostream>
using namespace std;

	void space(int str, int e) //This is the recursive Function to Print the Pattern
	{
		if (str==e)
		return;
		cout<<" ";
		space(++str,e);
	}	
	
	void PrintPattern3(int start, int end) 
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

PrintPattern3(1,10);
}
