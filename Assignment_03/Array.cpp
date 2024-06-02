#include<iostream>
#include"Array.h"
using namespace std;


Array::Array()
{
    s = 0;
    array = NULL;
};

Array::Array(int size)
{
    s = size;
    array = new int[s];
    for(int i=0;i<s;i++)
    {
    	array[i]=0;
    }

};

Array::Array(int *arr,int size)
{
    s = size;
    array = new int[s];
    for(int i=0;i<s;i++)
    {
        array[i] = arr[i];
    }

    
};

 Array::Array(const Array &arr)
 {
    s=arr.s;
    array = new int[s];
    for(int i=0;i<s;i++)
    {
        array[i] = arr.array[i];
    }
    
 };

 Array::~Array()
 {
    //delete [] array;
    //array=NULL;
 };
 int Array::size()
 {
     return s;
 }
 int& Array::operator[](int i)
 {
    int nu=-1;
    if(i<0 || i>=s)
    {
        cout<<"\nIndex out of range"<<endl;
        return nu;
    }
    return array[i];

 }
int& Array::operator[](int i) const
{
    int nu=-1;
    if(i<0 || i>=s)
    {
        cout<<"\nIndex out of range"<<endl;
        return nu;
    }
    return array[i];
}
const Array& Array:: operator=(const Array &arr)
{
    s=arr.s;
    delete [] array;
    array = new int[s];
    for(int i=0;i<s;i++)
    {
        array[i] = arr.array[i];
    }
    
}

Array Array:: operator+(const Array &arr)
{
 
    Array temp(s);
    if(s==arr.s)
    {
        

        for(int i=0;i<s;i++)
        {
            temp.array[i]=array[i]+arr.array[i];
        }
    }
    else
    {
        cout<<"\nArray size not equal."<<endl;
        
    }
    return temp;
}

Array Array :: operator-(const Array&arr) //subtracts two Array
{
    Array temp(s);
    if(s==arr.s)
    {
        for(int i=0;i<s;i++)
        {
            temp.array[i]=array[i]-arr.array[i];
        }
    }
    else
    {
        cout<<"\nArray size not equal."<<endl;
    }
    return temp;
}
Array Array::operator++()
{
    for(int i=0;i<s;i++)
    {
        array[i]=array[i]+1;
    }

}
Array Array::operator++(int)
{
    for(int i=0;i<s;i++)
    {
        array[i]=array[i]+1;
    }

}
Array& Array::operator--(int ) //subtracts one from each element of array
{
    for(int i=0;i<s;i++)
    {
        array[i]=array[i]-1;
    }

}
bool Array::operator==(const Array& arr)const //returns true if two arrays are same
{
    bool flag=false;
    if(s==arr.s)
    {
        for(int i=0;i<s;i++)
        {
            if(array[i]==arr.array[i])
            {
                flag=true;
                continue;
            }
            else
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        cout<<"\nSize not equal.\n";
    }
    return flag;
}
bool Array::operator!() // returns true if the Array is empty
{
    bool flag=false;
    if(s==0)
    {
        flag=true;
    }
    return flag;
}
void Array::operator+=(const Array&arr) //adds two Array?
{
    if(s==arr.s)
    {
        for(int i=0;i<s;i++)
        {
            array[i]+=arr.array[i];
        }
    }
    else
    {
        cout<<"\nSize not equal.\n";
    }
}
void Array::operator-=(const Array& arr) //subtracts two Array
{
    if(s==arr.s)
    {
        for(int i=0;i<s;i++)
        {
            array[i]-=arr.array[i];
        }
    }
    else
    {
        cout<<"\nSize not equal.\n";
    }
}
int Array::operator()(int idx, int val) // erases the value val at idx. Returns 1 for a successful 
//deletion and-1 if idx does not exists or is invalid. Shift the elements after idx to the //left.
{

    if(array[idx]==val)
    {
        array[idx]=0;
        for(int i=idx;i<s-1;i++)
        {
            array[i]=array[i+1];
            
        }
        //s--;
        return 1;
    }
    else
    {
        return -1;
    }
}
ostream& operator<<(ostream &input, const Array &rhs)
{
    for(int i=0;i<rhs.s;i++)
    {
        input<<rhs.array[i]<<" ";
    }
}
istream& operator>>(istream &output, Array &rhs)
{
    for(int i=0;i<rhs.s;i++)
    {
        output>>rhs.array[i];
    }
}