#include <iostream>
#include "BigInt.h"
#include "BigInt.cpp"

using namespace std;

int main()
{
    BigInt I1("12345678912345"),I2("747392933828293939");
    BigInt I3;//
    I3=I1*I2;//9227073182399630473820475776955
    cout<<I3; 
    return 0;
}