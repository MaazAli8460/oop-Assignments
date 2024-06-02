//Maaz ALi
//22i-1042
//Assignment#03


#include <iostream>
#include "BigInt.h"
using namespace std;

BigInt::BigInt(int val)
{
    if (val == 0)
    {
        num = new int[1];
        num[0] = 0;
        size = 0;
        carry = 0;
        x = 1;
    }
    else
    {
        if (val > 0)
        {
            x = 1;
        }
        else
        {
            x = -1;
            val*=-1;
        }
        
        int temp = val;
        int count = 0;
        for (int j = 0; temp != 0; j++)
        {
            if (temp == 0)
                break;
            temp = temp / 10;
            count++;
        }
        size = count;

        num = new int[count];
        temp = val;
        for (int i = size - 1; i >= 0; i--)
        {
            num[i] = temp % 10;
            temp = temp / 10;
        }
        carry = 0;
    }
};
BigInt ::BigInt(const string &text)
{
    int count = 0;
    bool flag = false;
    if (text[0] == '-')
    {
        x = -1;
        //count=1;
        flag = true;
    }
    else
    {
        x = 1;
    }
    while (text[count] != '\0')
    {
        count++;
    }
    if (flag)
    {
        count--;
        size = count;
        num = new int[count];
        int counter = 0;
        int temp=0;
        for (int i = 1; i <=count; i++)
        {
            temp= text[i] - '0';
            num[counter]=temp;
            counter++;
        }
        
    }
    else
    {
        size = count;
        num = new int[count];
        for (int i = 0; i < count; i++)
        {
            num[i] = text[i] - '0';
        }
        
    }
};
BigInt::BigInt(const BigInt &copy)
{
    x = copy.x;
    size = copy.size;
    num = new int[size];
    for (int i = 0; i < size; i++)
    {
        num[i] = copy.num[i];
    }
};

BigInt::operator string() // conversts integer array to string//+48
{
    char *str;
    int p = 0;
    while (num[p] == 0)
    {
        p++;
    }
    if(p>=size)
    {

    	str=new char[2];
    	str[0]='0';
    	str[1]='\0';

    	return str;
    }
    str = new char[size + 1];
    if (x == -1)
    {
        str[0] = '-';

        int counter = 1;

        for (int i = p; i < size; i++)
        {
            str[counter] = num[i] + 48;
            counter++;
        }
        str[counter] = '\0';
    }
    else
    {
        int counter = 0;
        for (int i = p; i < size; i++)
        {
            str[counter] = num[i] + 48;
            counter++;
        }
        str[counter] = '\0';
    }

    return str;
}
BigInt BigInt::operator+(const BigInt &val) const // program to reverse array?
{
    BigInt temp;
    int smaller;
    int temp1;
    if((x==-1 && val.x==1) || (x==1 && val.x==-1))
    {
        temp=*this-val;
        return temp;
    }
    else if(x==-1 && val.x==-1)
    {
        temp.x=-1;
    }
    else if(x==1 && val.x==1)
    {
        temp.x=1;
    }
    if (size >= val.size)
    {
        temp1 = size;
        smaller = val.size;
        temp.x = x;
    }
    else
    {
        temp1 = val.size;
        temp.x = val.x;
        smaller = size;
    }
    temp.size = temp1 + 1;
    temp.num = new int[temp.size];
    temp.carry = 0;
    bool flag = true;

    // reverse the array num.
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // reverse the array val.num.
    for (int i = 0; i < val.size / 2; i++)
    {
        int t2 = val.num[i];
        val.num[i] = val.num[val.size - 1 - i];
        val.num[val.size - 1 - i] = t2;
    }

    int s = 0;

    for (int i = 0; i < temp1; i++)
    {

        if (i < smaller)
        {
            s = num[i] + val.num[i] + temp.carry;
            temp.carry = 0;
        }
        else if (smaller == size)
        {
            s = val.num[i] + temp.carry;
            temp.carry = 0;
        }
        else if (smaller == val.size)
        {
            s = num[i] + temp.carry;
            temp.carry = 0;
        }

        if (s < 10)
        {
            temp.num[i] = s;
        }
        else
        {
            temp.carry = 1;
            temp.num[i] = s % 10;
        }
    }
    temp.num[temp1] = temp.carry;
    for (int i = 0; i < temp.size / 2; i++)
    {
        int t2 = temp.num[i];
        temp.num[i] = temp.num[temp.size - 1 - i];
        temp.num[temp.size - 1 - i] = t2;
    }

    if (temp.num[0] == 0)
    {
        int *ptr = temp.num;
        int ptrsize = temp.size;
        temp.size -= 1;
        temp.num = new int[temp.size];

        int index = 0;
        for (int i = 1; i < ptrsize; i++)
        {
            temp.num[index] = ptr[i];
            index++;
        }
        delete[] ptr;
        ptr = NULL;
    }

    // reverse the array num.
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // reverse the array val.num.
    for (int i = 0; i < val.size / 2; i++)
    {
        int t2 = val.num[i];
        val.num[i] = val.num[val.size - 1 - i];
        val.num[val.size - 1 - i] = t2;
    }
    return temp;
}
BigInt BigInt::operator+(int val) const
{
    BigInt temp2;
    int *ptr;
    int ptrsize;
    int ptrsign;
    if (val == 0)
    {
        ptr = new int[1];
        ptrsize = 1;
    }
    else
    {
        if (val > 0)
        {
            ptrsign = 1;
        }
        else
        {
            ptrsign = -1;
        }
        
        int temp = val;
        int count = 0;
        for (int j = 0; temp != 0; j++)
        {
            if (temp == 0)
                break;
            temp = temp / 10;
            count++;
        }
        ptrsize = count;

        ptr = new int[count];
        temp = val;
        for (int i = ptrsize - 1; i >= 0; i--)
        {
            ptr[i] = temp % 10;
            temp = temp / 10;
        }
    }
    int smaller;
    int temp1;
    if((x==-1 && ptrsign==1) || (x==1 && ptrsign==-1))
    {
        temp2.x=-1;
        temp2=*this-val;
        return temp2;
    }
    else if(x==-1 && ptrsign==-1)
    {
        temp2.x=-1;
    }
    else if(x==1 && ptrsign==1)
    {   
        temp2.x=1;
    }
    if (size >= ptrsize)
    {
        temp1 = size;
        smaller = ptrsize;
        temp2.x = x;
    }
    else
    {
        temp1 = ptrsize;
        temp2.x = ptrsign;
        smaller = size;
    }
    temp2.size = temp1 + 1;
    temp2.num = new int[temp2.size];
    temp2.carry = 0;
    bool flag = true;

    // reverse the array num.
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // reverse the array val.num.
    for (int i = 0; i < ptrsize / 2; i++)
    {
        int t2 = ptr[i];
        ptr[i] = ptr[ptrsize - 1 - i];
        ptr[ptrsize - 1 - i] = t2;
    }

    int s = 0;
    for (int i = 0; i < temp1; i++)
    {
        if (i < smaller)
        {
            s = num[i] + ptr[i] + temp2.carry;
            temp2.carry = 0;
        }
        else if (smaller == size)
        {
            s = ptr[i] + temp2.carry;
            temp2.carry = 0;
        }
        else if (smaller == ptrsize)
        {
            s = num[i] + temp2.carry;
            temp2.carry = 0;
        }

        if (s < 10)
        {
            temp2.num[i] = s;
        }
        else
        {
            temp2.carry = 1;
            temp2.num[i] = s % 10;
        }
    }
    temp2.num[temp1] = temp2.carry;
    for (int i = 0; i < temp2.size / 2; i++)
    {
        int t2 = temp2.num[i];
        temp2.num[i] = temp2.num[temp2.size - 1 - i];
        temp2.num[temp2.size - 1 - i] = t2;
    }

    cout << endl;
    if (temp2.num[0] == 0)
    {
        int *ptr1 = temp2.num;
        temp2.num = new int[temp2.size - 1];
        temp2.size -= 1;
        int index = 0;
        for (int i = 1; i < temp2.size; i++)
        {
            temp2.num[index] = ptr1[i];
            index++;
        }
        delete[] ptr1;
        ptr1 = NULL;
    }

    // reverse the array num.
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // Delete ptr
    delete[] ptr;
    ptr = NULL;
    return temp2;
}
BigInt BigInt::operator+=(const BigInt &rhs)
{
    BigInt temp;
    temp.carry = carry;
    temp.size = size;
    temp.num = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp.num[i] = num[i];
    }
    temp.x = x;
    if(x==-1 && rhs.x==1) 
    {
        if(size>rhs.size)
        {
        BigInt tempf(*this);
        tempf.x=1;
        temp=*this-tempf;
        temp.x=-1;
        *this=temp;
        }
        else
        {
            BigInt tempf(*this);
            tempf.x=1;
            temp=*this-tempf; 
            *this=temp;
        }
        return temp;
    }
    else if(x==1 && rhs.x==-1)
    {
        if(size>rhs.size)
        {
            BigInt tempf(rhs);
            tempf.x=1;
            temp=*this-tempf;
            *this=temp;
        }
        else
        {
            BigInt tempf(rhs);
            tempf.x=1;
            temp=*this-tempf;

            *this=temp;
        }
        return temp;
    }
    else if(x==-1 && rhs.x==-1)
    {
        temp.x=-1;
    }
    else if(x==1 && rhs.x==1)
    {   
        temp.x=1;
    }
    temp = temp + rhs;
    delete[] num;
    num = temp.num;
    size = temp.size;
    x = temp.x;
    return temp;
}
BigInt BigInt::operator-(const BigInt &val) const
{
    BigInt temp;
    int smaller;
    int temp1;
    if(x==-1 && val.x==1) 
    {
        BigInt tempf(val);
        tempf.x=-1;
        temp=*this+tempf;
        return temp;
    }
    else if (x==1 && val.x==-1)
    {
        BigInt tempf(val);
        tempf.x=1;
        temp=*this+tempf;
        return temp;   
    }
    else if(x==-1 && val.x==-1)
    {
        temp.x=-1;
    }
    else if(x==1 && val.x==1)
    {   
        temp.x=1;
    }
    if (size >= val.size)
    {
        temp1 = size;
        smaller = val.size;
        temp.x = x;
    }
    else
    {
        temp1 = val.size;
        temp.x = val.x;
        smaller = size;
    }
    delete[] temp.num;
    temp.num = new int[temp1];
    temp.size = temp1;
    temp.carry = 0;

    bool flag = true;

    // reverse the array num.
    for (int i = 0; i < size/2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }
   
    // reverse the array val.num.
    for (int i = 0; i < val.size / 2; i++)
    {
        int t2 = val.num[i];
        val.num[i] = val.num[val.size - 1 - i];
        val.num[val.size - 1 - i] = t2;
    }
    if(val.size==size)
    {
    for (int i = 0; i < temp.size; i++)
    {
        if (i < smaller)
        {
            if (val.num[i] > num[i])
            {
            	
        		num[i]+=10;
                	num[i+1]-=1;
        	
            }
            temp.num[i] = num[i] - val.num[i];
        }
        else
        {
            temp.num[i] = num[i]-val.num[i];
        }
    }
    }

    else
    {
    for (int i = 0; i < temp.size; i++)
    {
        if(i<smaller)
        {
            if(val.num[i]>num[i])
            {

                int tt=i;
                while((num[tt]==0 ||num[tt]<val.num[i]) && tt+1!=size)
                {
                    num[tt]+=10;
                    num[tt+1]-=1;
                    tt++;
                }
                //num[tt]-=1;
            }
            temp.num[i] = num[i] - val.num[i];
        }
        else
        {
            temp.num[i]=num[i];
        }
    }
    }
    for (int i = 0; i < temp.size / 2; i++)
    {
        int t2 = temp.num[i];
        temp.num[i] = temp.num[temp.size - 1 - i];
        temp.num[temp.size - 1 - i] = t2;
    }
    if (temp.num[0] == 0)
    {
        int *ptr = temp.num;
        int ptrsize = temp.size;
        temp.size -= 1;
        temp.num = new int[temp.size];

        int index = 0;
        for (int i = 1; i < ptrsize; i++)
        {
            temp.num[index] = ptr[i];
            index++;
        }
        delete[] ptr;
        ptr = NULL;
    }
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // reverse the array val.num.
    for (int i = 0; i < val.size / 2; i++)
    {
        int t2 = val.num[i];
        val.num[i] = val.num[val.size - 1 - i];
        val.num[val.size - 1 - i] = t2;
    }

    return temp;
}
BigInt BigInt::operator-(int val) const
{
    BigInt temp = *this;

    BigInt vtemp(val);
	
    temp = temp - vtemp;

    return temp;
}
BigInt BigInt::operator-=(const BigInt &rhs)
{
    *this = *this - rhs;

    return *this;
}
BigInt BigInt::operator*(const BigInt &val) const
{
    BigInt temp;
    temp.carry = 0;
    int count = size + 1 + val.size;
    int **mul = new int *[val.size];
    for (int i = 0; i < val.size; i++)
    {
        mul[i] = new int[size + 1+val.size];
    }
    for (int i = 0; i < val.size; i++)
    {
        for (int j = 0; j < count; j++)
        {
            mul[i][j] = 0;
        }
        
    }


    // reverse the array num.
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // reverse the array val.num.
    for (int i = 0; i < val.size / 2; i++)
    {
        int t2 = val.num[i];
        val.num[i] = val.num[val.size - 1 - i];
        val.num[val.size - 1 - i] = t2;
    }

    for (int i = 0; i < val.size; i++)
    {
        int s = 0;
        temp.carry=0;

        for (int j = 0; j < size; j++)
        {
            s = 0;
            s = val.num[i] * num[j] + temp.carry;

            temp.carry = 0;
            if (s >= 10)
            {
                mul[i][j + i] = s % 10;
                temp.carry = s / 10;

            }
            else
            {
                temp.carry = 0;
                mul[i][j+i]=s;

                continue;
            }
        }
        mul[i][size+i]=temp.carry;

    }

    temp.num = new int[count+1];
    temp.size = count+1;
    for (int i = 0; i < temp.size; i++)
    {
        temp.num[i] = 0;
    }
    int s=0;


    for (int i = 0; i < val.size; i++)
    {
        temp.carry=0;
        for(int j=0;j<count;j++)
        {
            s = mul[i][j] +temp.num[j]+ temp.carry;
            temp.carry = 0;
            if (s < 10)
            {
                temp.num[j] = s;
            }
            else
            {
                temp.carry = 1;
                temp.num[j] = s % 10;
            }
        }
        
        temp.num[count] += temp.carry;
    }

    for (int i = 0; i < temp.size / 2; i++)
    {
        int t2 = temp.num[i];
        temp.num[i] = temp.num[temp.size - 1 - i];
        temp.num[temp.size - 1 - i] = t2;
    }
    if (x == -1 && val.x == -1)
    {
        temp.x = 1;
    }
    else if (x == 1 && val.x == -1)
    {
        temp.x = -1;
    }
    else if (x == -1 && val.x == 1)
    {
        temp.x = -1;
    }
    else if (x == 1 && val.x == 1)
    {
        temp.x = 1;
    }
    //reverse array num
    for (int i = 0; i < size / 2; i++)
    {
        int t2 = num[i];
        num[i] = num[size - 1 - i];
        num[size - 1 - i] = t2;
    }

    // reverse the array val.num.
    for (int i = 0; i < val.size / 2; i++)
    {
        int t2 = val.num[i];
        val.num[i] = val.num[val.size - 1 - i];
        val.num[val.size - 1 - i] = t2;
    }
    for (int i = 0; i < val.size; i++)
    {
    	delete[] mul[i];
    }
	delete[] mul;
    return temp;
}
BigInt BigInt::operator*=(const BigInt &rhs)
{
    BigInt temp = *this;
    temp = temp * rhs;
    *this=temp;
    return temp;
}
bool BigInt::operator==(const BigInt &val) const
{
    bool flag = false;
    if (size != val.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (num[i] == val.num[i])
        {
            flag = true;
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (x != val.x)
    {
        flag = false;
    }

    return flag;
}
bool BigInt::operator==(const char *val) const
{
    bool flag = false;
    BigInt temp(val);
    if (size != temp.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (num[i] == temp.num[i])
        {
            flag = true;
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (x != temp.x)
    {
        flag = false;
    }

    return flag;
}
bool BigInt::operator!=(const BigInt &val) const
{
    bool flag = false;
    if (size != val.size)
    {
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (num[i] == val.num[i])
        {
            flag = false;
            continue;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (x != val.x)
    {
        flag = true;
    }

    return flag;
}
bool BigInt::operator<(const BigInt &val) const
{
    bool flag = false;
    if (size < val.size && val.x == 1)
    {
        flag = true;
        return flag;
    }
    else if (size >= val.size && val.x == 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (num[i] > val.num[i])
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
                continue;
            }
        }
    }

    if (x == -1 && val.x == 1)
    {
        flag = true;
    }
    else if (x == 1 && val.x == -1)
    {
        flag = false;
    }
    return flag;
}
bool BigInt::operator>(const BigInt &val) const
{
    BigInt big = *this;
    bool flag = big < val;
    if (flag)
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
    return flag;
}
bool BigInt::operator<=(const BigInt &val) const
{
    BigInt big = *this;
    bool flag1 = (big < val);
    bool flag2 = (big == val);
    bool f = false;
    if (flag1 == true || flag2 == true)
    {
        f = true;
    }
    else
    {
        f = false;
    }
    return f;
}
bool BigInt::operator>=(const BigInt &val) const
{
    BigInt big = *this;
    bool flag1 = (big > val);
    bool flag2 = (big == val);
    bool f = false;
    if (flag1 == true || flag2 == true)
    {
        f = true;
    }
    else
    {
        f = false;
    }
    return f;
}
BigInt ::operator int()
{
    return size;
}
BigInt &BigInt::operator++() // Pre-increment Operator
{
    *this+=1;
    return *this;
}
BigInt BigInt::operator++(int) // Post-increment Operator
{
    BigInt temp;
    temp=*this + 1;
    *this=temp;
    return *this;
}
BigInt &BigInt::operator--() // Pre-decrement Operator
{
    BigInt temp;
    temp=*this - 1;
    *this=temp;
    return *this;
}
BigInt BigInt::operator--(int) // Post-decrement Operator
{
    BigInt temp;
    temp=*this + 1;
    *this=temp;
    return *this;
}
// BigInt BigInt:: operator=(BigInt & b)
// {
//     size = b.size;
//     delete []num;
//     num = new int[size];
//     for (int i = 0; i < size; i++)
//     {
//         num[i] = b.num[i];
//     }
//     return *this;
// }

ostream& operator<<(ostream& output, const BigInt& val)
{
    for (int i = 0; i < val.size; i++)
    {
        output<<val.num[i];
    }    
    return output;
}
istream& operator>>(istream& input, BigInt& val)
{
    string s1;
    input>>s1;
    BigInt btest(s1);
    delete []val.num;
    val.size = btest.size;
    val.num = new int[btest.size];
    for (int i = 0; i < btest.size; i++)
    {
        val.num[i] = btest.num[i];
        
    }
    return input;
}
BigInt::~BigInt(){

};
