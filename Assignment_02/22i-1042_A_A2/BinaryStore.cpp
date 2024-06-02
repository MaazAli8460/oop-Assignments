#include"BinaryStore.h"

using namespace std;

BinaryStore:: BinaryStore(int len)
{
    addres= new char*[len];
    byte=new char*[len];
    for(int i=0;i<len;i++)
    {
        addres[i]=new char[4];
        byte[i]=new char[8];
    }
    address_count=0;
    byte_count=0;
};

void BinaryStore::add_Address(char*s)
{
    for(int i=0;i<4;i++)
    {
        addres[address_count][i]=*(s+i);
    }
    address_count++;
}

void BinaryStore::set_Byte(char* address, char* value) // add the byte at newly added address
// here the first parameter is address and second is byte// Similarly the
{
    int index;
    bool flag=false;
    for(int i=0;i<address_count;i++)
    {
        for (int  j= 0; j < 4; j++)
        {
            if(addres[i][j]==*(address+j))
            {
                flag=true;
                continue;
            }
            else
            {
                flag=false;
                break;
            }
            /* code */
        }
        if(flag==true)
        {
            index=i;
            break;
        }
        
    }
    for(int i=0;i<8;i++)
    {
        byte[index][i]=*(value+i);
    }
    byte_count++;
}
char* BinaryStore::Get(char* address)//Get function will retrieve the byte at a givenaddress ,
{
    char* s=new char[8];
    int index;
    bool flag=false;
    for(int i=0;i<address_count;i++)
    {
        for (int  j= 0; j < 4; j++)
        {
            if(addres[i][j]==*(address+j))
            {
                flag=true;
                continue;
            }
            else
            {
                flag=false;
                break;
            }
        /* code */
        }
        if(flag==true)
        {
            index=i;
            break;
        }
    }
    if(flag==true)
    {
    for(int i=0;i<8;i++)
    {
        s[i]=byte[index][i];
    }
    }
    else{
        s=NULL;
    }

    return s;
}