#include"Header.h"
//#include"BinaryStore.cpp"
#include<iostream>

using namespace std;

int main()
{
	BinaryStore x(3);
	
	x.add_Address("0000");
	x.add_Address("0001");
	x.add_Address("0010");
	x.set_Byte("0000", "01010101");
	x.set_Byte("0010", "01010100");
	cout<<x.Get("0000");
	cout<<x.Get("0010");
	cout<<x.Get("0001");
    // BinaryStore x;
    // char byt5[] = "11111110";
	// char byt6[] = "10001010";
	// cout<<endl<<x.comp_AND(byt5, byt6);
   // BinaryStore x(3);
	// x.add_Address("0000");
	// x.add_Address("0001");
	// x.add_Address("0010");

	// x.set_Byte("0000", "01010101");
	// x.set_Byte("0010", "01010100");
    // cout<<endl<<x.Get("0000");
    // cout<<endl<<x.Get("0001");
    // cout<<endl<<x.Get("0010");
    //BinaryStore x(2);
	// x.add_Address("0000");
	// x.add_Address("0001");

	// x.set_Byte("0000", "01010101");
	// x.set_Byte("0010", "01010100");
    // cout<<endl<<"0000   "<<x.Get("0000");
	// cout<<endl<<"0010   "<<x.Get("0010");
    //char byt[] =  "00001110";
	//char byt2[] = "01010110";
	//cout<<x.Add(byt, byt2);
    // char byt[] = "10001110";
	// char byt2[] = "10001110";
    // cout<<endl<<"flag=";
	// cout<<(x.comp_EQUAL(byt, byt2));
    // cout<<endl;
    // char byt3[]= "10101110";
	// char byt4[]= "10001110";
    // cout<<endl<<"flag=";
	// cout<<(x.comp_EQUAL(byt3, byt4));
    // cout<<endl;
    // char byt5[] = "11111110";
	// char byt6[] = "10001010";
	// cout<<endl<<x.comp_AND(byt5, byt6);

    return 0;
}


