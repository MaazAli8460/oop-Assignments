#pragma once
#include<iostream>
using namespace std;
class BinaryStore
{
    // add suitable member attributes
private:
    char** addres;//array to store address
    char** byte;//array to store byte
    int olen;
    int address_count;
    int byte_count;             
    char *** additional_address;//to entertain extra addresses
    int total_index;
    int current_index;
    bool flag_control;//only true when additional address is made so that it can be deleted in destructor

public:
    BinaryStore(int len); // constructor which creates the store of length len.
    void add_Address(char* s) // add a new address in the list of Binary store.
        //add_Address(char*s)
    {
        for (int i = 0; i < 4; i++)
        {
            addres[address_count][i] = *(s + i);
        }
        address_count++;
    }
    void set_Byte(char* address, char* value) // add the byte at newly added address
        // here the first parameter is address and second is byte// Similarly the
        //following code adds byte address and later byte // if address not found add
        //address and byte both // function also overrides the data given at particular byte
        //address.
        //BinaryStore::set_Byte(char* address, char* value) // add the byte at newly added address
        // here the first parameter is address and second is byte// Similarly the
    {
        int index;
        bool flag = false;
        for (int i = 0; i < address_count; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (addres[i][j] == address[j])
                {
                    flag = true;
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
                /* code */
            }
            if (flag == true)
            {
                index = i;
                break;
            }

        }
        
        if(flag==true)
        {
        
        for (int i = 0; i < 8; i++)
        {
            byte[index][i] = *(value + i);
        }
        byte_count++;
        }
        else
        {
            flag_control=true;
            total_index=10;
            additional_address[0]=new char*[total_index];
            additional_address[1]=new char*[total_index];
            int i=0;
            while(i<total_index)
            {
            additional_address[0][i]=new char[4];
            additional_address[1][i]=new char[8];
            i++;
            }
            
            current_index=0;
            for (int i = 0; i < 4; i++)
        	{
            		additional_address[0][current_index][i] = *(address + i);
            		
        	}
           for (int i = 0; i < 8; i++)
        	{
            		additional_address[1][current_index][i] = *(value + i);
            		
        	}
        	current_index++;
        	
        }
    }
    char* Get(char* address) //Get function will retrieve the byte at a givenaddress ,
        //BinaryStore::Get(char* address)//Get function will retrieve the byte at a givenaddress ,
    {
        char* s = new char[8];
        int index;
        bool flag = false;
	
        for (int i = 0; i < address_count; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (addres[i][j] == *(address + j))
                {
                    flag = true;
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
                /* code */
            }
            if (flag == true)
            {
                index = i;
                break;
            }
        }
        
        if (flag == true && byte[index][0]!='\0')
        {
        
        
            for (int i = 0; i < 8; i++)
            {
                s[i] = byte[index][i];

            }
            s[8] = '\0';
            return byte[index];
        }
        
        else if(flag==true && byte[index][0]=='\0')
        {
        
            delete[] s;
            s=nullptr;
            byte[index]=NULL;  
            return byte[index];
        }
        else
        {
            if(current_index<total_index && additional_address[0][0][0]!='\0' )
            {
            	for (int i = 0; i < current_index; i++)
        	{
            		for (int j = 0; j < 4; j++)
            		{
                		if (additional_address[0][i][j] == *(address + j))
                		{
                    			flag = true;
                    			continue;
                		}
                		else
                		{
                    			flag = false;
                    			break;
                		}
                		/* code */
            		}
            		if (flag == true)
            		{
                		index = i;
                		break;
            		}
        	}
        	
        	if (flag == true && additional_address[1][index][0]!='\0')
        	{
        		
        
           		for (int i = 0; i < 8; i++)
            		{
                		s[i] = additional_address[1][index][i];

            		}
            		s[8] = '\0';
            		return additional_address[1][index];
        	}
        
        	else if(flag==true && additional_address[1][index][0]=='\0')
        	{
        
            		delete[] s;
            		s=nullptr;
            		additional_address[1][index]=NULL;  
            		return additional_address[1][index];
        	}
            }
        
        }

        //return s;
    }
    char* ToString() //return the BinaryStore as character dynamic array.
    {
    	char* binstore;
    	int x=(byte_count*8)+(address_count*4)+1;//1='\0'
    	binstore=new char[x];
    	int c=0;
    	for (int i = 0; i < address_count; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                binstore[c]=addres[i][j];
                c++;
            }
            for (int j = 0; j < 8; j++)
            {
                binstore[c]=byte[i][j];
                c++;
            }
            
        }
        binstore[c]='\0';
       
        
        return binstore;
    	
    }
    char* Add(char* a, char* b)//checks the char array and adds them
    {
        char* s = new char[8];
        char* s1 = new char[8];
        char* s2 = new char[8];
        for (int i = 0; i < 8; i++)
        {
            s1[i] = *(a + i);
            s2[i] = *(b + i);
        }
        int carry = 0;
        for (int i = 7; i >= 0; i--)
        {
            
            if (s1[i] == '0' && s2[i] == '0' && carry==0)
            {
                s[i] = '0';
            }
            else if (s1[i] == '1' && s2[i] == '0' && carry==0)
            {
                s[i] = '1';

            }
            else if (s1[i] == '0' && s2[i] == '1' && carry==0)
            {
                s[i] = '1';
            }
            else if (s1[i] == '1' && s2[i] == '1' && carry==0)
            {
                carry = 1;

                s[i] = '0';
                
            }
            else if(s1[i] == '1' && carry==1)
            {
            	carry=1;
            	
            	if(s2[i] == '1')
            	{
            	      s[i] = '1';
            	}
            	else
            	{
            	      s[i] = '0';
            	}
            }
            else if(s1[i] == '0' && carry==1)
            {
            	carry=0;
            	
            	if(s2[i] == '1')
            	{
            	      s[i] = '0';
            	      carry=1;
            	}
            	else
            	{
            	      s[i] = '1';
            	      carry=0;
            	}
            } 
        }
        delete []s1;
        delete []s2;
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
                cout << "\nNot Equal.\n";

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
    delete []s1;
    return s;
}




    ~BinaryStore()
    {
    	//cout<<"\nDestructor called\n";
    	for(int i=0;i<olen;i++)
    	{
    	//cout<<"\nError\n";
    	delete []addres[i];
    	}
    	delete[] addres;
    	addres=nullptr;
    	for(int i=0;i<olen;i++)
    	{
    	delete []byte[i];
    	}
    	delete[] byte;
    	byte=nullptr;
    	/*
    	if(flag_control==true)
    	{
    	for(int i=0;i<2;i++)
    	{
    		
    		for(int j=0;j<total_index;j++)
    		{
    			delete [] additional_address[i][j];
    		
    		
    			//delete [] additional_address[i][j];
    		}
    			
    		
    		delete [] additional_address[i];
    	}
    	
    	delete []additional_address;
    	additional_address=nullptr;
    }
    else
    {
    	delete []additional_address;
    }
    */
    flag_control=false;
    total_index=0;
    current_index=0;
    
    };
};
BinaryStore::BinaryStore(int len=0)
{
    olen=len;
    flag_control=false;
    addres = new char* [len];
    byte = new char* [len];
    for (int i = 0; i < len; i++)
    {
        addres[i] = new char[4];
        byte[i] = new char[8];
    }
    additional_address= new char**[2];
    address_count = 0;
    byte_count = 0;
};

//BinaryStore ::

