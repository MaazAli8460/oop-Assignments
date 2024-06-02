#include<iostream>

using namespace std;

int findVowels(char* str);

int main()
{
    char* input = new char;
    input="osama/bin/laden";

    int x=findVowels(input);

    cout<<x<<endl;


    return 0;
}
int findVowels(char* str)
{
    static int x;

    if((*str)=='\0')
    {
        return x;
    }

    
    findVowels((str+1));
  if(*str == 'a'||*str == 'e'||*str == 'i'||*str == 'o'||*str == 'u')
    x=x+1;

    return x;
}