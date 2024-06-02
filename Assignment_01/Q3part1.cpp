#include<iostream>

using namespace std;

bool isperfectNumber(int n);

int main()
{
    int num;
    cout<<"\nEnter the number:";
    cin>>num;
    
    
    bool flag=false;
    flag=isperfectNumber(num);
    cout<<flag<<endl;
    return 0;
}
bool isperfectNumber(int n)
{
    static int sum=1;
    static int temp=n;

    if (n==1)
    return 1;

    if(temp%n==0 && n!=temp)
    sum+=n;

    isperfectNumber(n-1);

    if(sum==temp)
    return true;
    else
    return false;
 }