#include <iostream>

using namespace std;

int countVowels(char* str, int x);
int findVowels(char* str);


int main()
{
    char* input = new char;
    input = "Osama/bin/laden";

    int x = findVowels(input);

    cout << x << endl;


    return 0;
}
int findVowels(char* str)
{
    return countVowels(str, 0);
}

int countVowels(char* str, int x)
{
    if (*str == '\0')
    {
        return x;
    }

    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
    {
        x = x + 1;
    }

    return countVowels(str + 1, x);
}