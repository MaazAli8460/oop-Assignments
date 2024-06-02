#include <iostream>
using namespace std;


void space(int sp)
{
    if (sp == 0)
    {
        return;
    }
    else
    cout<<"  ";

    space(sp - 1);
}

void print(int num2)
{
    if (num2 == 0)
    {
        return;
    }
    else
    cout << "* ";
    print(num2 - 1);
}  


void lowerdiamond(int n, int num)
{

    if (n == 0)
    {
        return;
    }

    print(num - n + 1);
    
    space(2 * n - 2);
    
    print(num - n + 1);
    
    cout <<'\n';
  

    lowerdiamond(n - 1, num);

}

void upperdiamond(int n, int num)
{

    if (n == 0)
    {
        return;
    }
    print(n);
    
    space(2 * (num - n));
    
    print(n);
    
    cout << '\n';
  
    
    upperdiamond(n - 1, num);
}
  

void printHollowDiamond(int n){
    int num=n;

    upperdiamond(n, num);
    
    lowerdiamond(n - 1, num);
}
  
int main()
{
    
    printHollowDiamond(27);
    return 0;
}
