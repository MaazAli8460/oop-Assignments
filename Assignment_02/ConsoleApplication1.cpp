#include"Header.h"
//#include"BinaryStore.cpp"
#include<iostream>

using namespace std;

int main()
{

	BinaryStore x(2);
	char c[] = "0010";
	char b[] = "1010100";
	x.add_Address(c);
	x.set_Byte(c, b);
	cout << endl << "0010   " << x.Get(c);

	char d[] = "0000";
	char e[] = "0101010";
	x.add_Address(d);
	x.set_Byte(d, e);
	cout << endl << "0000   " << x.Get(d) << " end";

	return 0;
}


