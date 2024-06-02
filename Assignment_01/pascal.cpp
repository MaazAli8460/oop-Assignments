#include <iostream>
using namespace std;

int pascal(int row, int col) 
{
    if (col == 0 || col == row || row == 0) 
	{
        return 1;
    }
    
    return pascal(row - 1, col) + pascal(row - 1, col - 1);
}


int main() 
{
    cout << pascal(10,5);
    return 0;
}

