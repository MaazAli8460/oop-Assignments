#pragma once
#include<iostream>
using namespace std;

    // add suitable member attributes
private:
    char* addres;
    char* byte;
class BinaryStore
{
public:
    BinaryStore *link;

    BinaryStore(int len); // constructor which creates the store of length len.
    void add_Address(char* s) // add a new address in the list of Binary store.
    {
        if(link==NULL)
        {
            addres=new char[5];
            byte=NULL;
            int i=0;
            while(s[i]!='\0')
            {
                addres[i]=s[i];
                i++
            }
            addres[i]='\0';
            link=new BinaryStore;
        }
        else
        {
            BinaryStore temp=link;
            temp->link=new BinaryStore;
            temp->link->link = NULL;
            temp->addres=new char[5];
            int i=0;
            while(s[i]!='\0')
            {
                temp->addres[i]=s[i];
                i++
            }
            temp->addres[i]='\0';
            temp->byte=NULL;
            
            
        }
    }
bool isEqual(char *p,char*q)const //returns true if two strings are equal
{
    bool flag=false;
    int i=0;
    int index=0;
    while(p[index]!='\0' && q[index]!='\0')
    {
    	if(p[index]==q[index])
        {
            index++;
            i++;
            flag=true;
            continue;
        }
        else
        {
            flag=false;
            break;
        }
    }
    
    return flag;
}
    void set_Byte(char* address, char* value) // add the byte at newly added address
        // here the first parameter is address and second is byte// Similarly the
        //following code adds byte address and later byte // if address not found add
        //address and byte both // function also overrides the data given at particular byte
        //address.
        //BinaryStore::set_Byte(char* address, char* value) // add the byte at newly added address
        // here the first parameter is address and second is byte// Similarly the
    {
        if(link==NULL)
        {
            byte=new char[9];
            int i=0;
            while(value[i]!='\0')
            {
                byte[i]=value[i];
                i++
            }
            value[i]='\0';
            
        }
        else
        {
            BinaryStore temp=link;
            bool flag=false;
            while(temp->link!=NULL)
            {
                flag=isEqual(temp->addres,address);
                if(flag)
                {
                    temp->byte=new char[9];
                    int i=0;
                    while(value[i]!='\0')
                    {
                        temp->byte[i]=value[i];
                        i++;
                    }
                    //value[i]='\0';
                    temp->byte[i]='\0';
                    break;
                }
                else
                {
                    temp=temp->link;
                }
            }
            if(flag==false)
            {
                temp->addres=new char[5];
                int i=0;
                while(s[i]!='\0')
                {
                 temp->addres[i]=s[i];
                 i++
                }
                temp->addres[i]='\0';
                temp->byte=new char[9];
                int i=0;
                while(value[i]!='\0')
                {
                    temp->byte[i]=value[i];
                    i++;
                }
                //value[i]='\0';
                temp->byte[i]='\0';
                temp->link->link = NULL;
            }
            
            
        }
    }

    char* Get(char* address) //Get function will retrieve the byte at a given address 
    {
        int flag=0;
        BinaryStore temp=link;
        while(temp!=NULL)
        {
            flag=isEqual(temp->addres,address)
            if(flag==true)
            {
                return temp->byte;
            }
            else
            {
                temp=temp->link;
            }
        }
    }

    char* ToString(); //return the BinaryStore as character dynamic array.
    char* Add(char* a, char* b)
    {
        char* s = new char[8];
        char* s1 = new char[8];
        char* s2 = new char[8];
        for (int i = 0; i < 8; i++)
        {
            s1[i] = *(a + i);
            s2[i] = *(b + i);
        }
        for (int i = 7; i >= 0; i--)
        {
            int carry = 0;
            if (s1[i] == '0' && s2[i] == '0')
            {
                s[i] = '0';
            }
            else if (s1[i] == '1' && s2[i] == '0')
            {
                s[i] = '1';

            }
            else if (s1[i] == '0' && s2[i] == '1')
            {
                s[i] = '1';
            }
            else if (s1[i] == '1' && s2[i] == '1')
            {
                carry = 1;

                s[i] = '0';
                if (s1[i - 1] == '1')
                {
                    s1[i - 1] = 0;

                }
            }


            /* code */
        }

        std::cout << "\nin add\n";
        return s;

    }
    //ADD function will take two strings as input parameters and given the binary
    //equivalent in form of string.
    // comp_EQUAL, comp_AND, and comp_OR function will take two strings as input
    //parameters and given the binary equivalent in form of string.
    bool    comp_EQUAL(char* a, char* b)
    {
        char* s1 = new char[8];
        char* s2 = new char[8];
        bool flag = false;
        for (int i = 0; i < 8; i++)
        {
            s1[i] = *(a + i);
            s2[i] = *(b + i);
        }
        for (int i = 0; i < 8; i++)
        {
            /* code */
            if (s1[i] == s2[i])
            {
                flag = true;
                continue;
            }
            else
            {
                flag = false;
                std::cout << "\nNot Equal.";

                break;
            }
        }

        return flag;

    }
    char* comp_AND(char* a, char* b)
    {
        char* s = new char[8];
        char* s1 = new char[8];
        char* s2 = new char[8];
        for (int i = 0; i < 8; i++)
        {
            s1[i] = *(a + i);
            s2[i] = *(b + i);
        }
        for (int i = 7; i >= 0; i--)
        {
            int carry = 0;
            if (s1[i] == '0' && s2[i] == '0')
            {
                s[i] = '0';
            }
            else if (s1[i] == '1' && s2[i] == '0')
            {
                s[i] = '0';

            }
            else if (s1[i] == '0' && s2[i] == '1')
            {
                s[i] = '0';
            }
            else if (s1[i] == '1' && s2[i] == '1')
            {

                s[i] = '1';

            }


            /* code */
        }

        //std::cout<<"\nin add\n";
        return s;

    }
    //ADD function will take two strings as input parameters and given the binary
    //equivalent in form of string.
    // comp_EQUAL, comp_AND, and comp_OR function will take two strings as input
    //parameters and given the binary equivalent in form of string.
    // comp_NOT function will take one string as input parameter and given the binary
    //equivalent in form of string.

    char* comp_OR(char* a, char* b)//this function will take binary OR
    {
        char* s = new char[8];
        char* s1 = new char[8];
        char* s2 = new char[8];
        for (int i = 0; i < 8; i++)
        {
            s1[i] = *(a + i);
            s2[i] = *(b + i);
        }
        for (int i = 7; i >= 0; i--)
        {
            int carry = 0;
            if (s1[i] == '0' && s2[i] == '0')
            {
                s[i] = '0';

            }
            else if (s1[i] == '1' && s2[i] == '0')
            {
                s[i] = '1';

            }
            else if (s1[i] == '0' && s2[i] == '1')
            {
                s[i] = '1';
            }
            else if (s1[i] == '1' && s2[i] == '1')
            {

                s[i] = '1';

            }


        }
        return s;
    }
    char *  comp_NOT(char * a)
{
    char* s1=new char[8];
    char* s=new char[8];
    for(int i=0;i<8;i++)
    {
        s1[i]=*(a+i);
    }
    for(int i=0;i<8;i++)
    {
        if(s1[i]=='1')
        {
            s[i]='0';
        }
        else
        {
            s[i]='1';
        }
    }
    return s;
}




    ~BinaryStore()
    {};
};
BinaryStore::BinaryStore(int len=0)
{
    addres = new char* [len];
    byte = new char* [len];
    for (int i = 0; i < len; i++)
    {
        addres[i] = new char[4];
        byte[i] = new char[8];
    }
    address_count = 0;
    byte_count = 0;
};

//BinaryStore ::

