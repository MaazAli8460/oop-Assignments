#include"Q1.h"
#include<iostream>

using namespace std;

int main()
{
   ZooChain obj;
	char name1[6] = "LION";
	char name2[6] = "TIGER";
	char name3[7] = "MONKEY";
    cout<<"\nBefore deletion1";
	obj.add_Cage(name1, 12);
	obj.add_Cage(name2, 7);
	obj.add_Cage(name3, 20);
    cout<<"\nBefore deletion2";
    obj.print_Chain();
    cout<<"\nBefore deletion3";
    //obj.delete_Chain(7);
    cout<<"\nAfter deletion4";
    obj.Sort_Chain();
    obj.print_Chain();
    obj.update_name_at_cageNumber(7, "ZEBRA");
	obj.update_name_at_cageNumber(12, "ELEPHANT");
	obj.update_name_at_cageNumber(20, "WOLF");
    obj.print_Chain();
    cout<<"\nFuck";
    cout << obj.start->link->link->name;
    cout<<"\nYou";
    return 0;
   
}
