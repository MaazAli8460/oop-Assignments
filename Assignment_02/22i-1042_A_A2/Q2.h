#include<iostream>
#include<cstring>
#include"string.h"
using namespace std;

class String {
char* data;
int len;
char ret;
int con;
// there is need of more data members, think about them...
public:
// provide definitions of following functions...
//String() // default constructor
String()
    {
        data = new char[1];
        data[0] = '\0';
        len = 0;
    };
//String(char* str); // constructor9 String(char *str); // initializes the
String(char *str)
    {
        len = 0;
        while (str[len] != '\0')
        {
            len++;
        }
        data = new char[len + 1];

        
        for (int i = 0; i < len; i++)
        {
            data[i] = str[i];
        }

        data[len]='\0';
        
    };
//string with constant cstring
//String(const String &); // copy constructor to initialize the string from
//existing string
String(const String &str)
    {
    	
        int x=str.len;

        x+=1;

        len=x;

        data=new char[len];
        char *data1 = str.data;
        for(int i=0;i<len;i++)
        {
        	data[i]=data1[i];

        }

    };
//String(int x); // initializes a string of pre-defined size
String(int x)
    {
        len = x;
        data = new char[len];
/*        for(int i=0;i<len;i++)
        {
        	data[i]='\0';
        }
*/
data="";
//	cout<<endl<<data<<endl;
    }
char* getdata()
{
    return data;
}
char getChar(int i) // returns the character at index [x] in a string
{
    ret=data[i];
    return ret;
}
bool isEmpty() // returns true if string is empty..
{
    bool flag=false;
    int i=0;
    
    
    if(data[i]=='\0')
    {
        flag=true;
        //break;
    }
    else
    {
        flag=false;
        //break;
    }
    
     return flag;   
    
}
String append_string(const String &str) // appends a String at the end ofthe String
{
    int x=len+str.len;
    char* cap= new char[x+1];
    int temp=0;
    for(int i=0;i<len;i++)
    {
    	cap[i]=data[i];
    	temp=i;
    }
    temp++;
    for(int i=0;i<str.len;i++)
    {
    	cap[temp]=str.data[i];
    	temp++;
    }
    cap[x]='\0';
    //cout<<endl<<cap<<endl;
    delete [] data;
    data = cap;
    cap=NULL;
        len=x;
        //cout<<len<<endl;
}
String append_string(const char &str) // appends a char at the end of theString
{
    int x=len+1;
    char* cap= new char[x];
    for(int i=0;i<len;i++)
    {
    	cap[i]=data[i];
    }
    cap[x-2]=str;
    cap[x-1]='\0';
    //cout<<endl<<cap<<endl;
    delete [] data;
    data = cap;
    cap=NULL;
    len=x;
    //cout<<len<<endl;

}
String append_string(char *&str) // appends a String at the end of theString
{
    int index=0;
    while (str[index] != '\0')
        {
            index++;
        }
    int x=index+len;
    char* cap= new char[x+1];
    int temp=0;
    for(int i=0;i<len;i++)
    {
    	cap[i]=data[i];
    	temp=i;
    }
    temp++;
    for(int i=0;i<index;i++)
    {
    	cap[temp]=str[i];
    	temp++;
    }
    cap[x]='\0';
    //cout<<endl<<cap<<endl;
    delete [] data;
    data = cap;
    cap=NULL;
        len=x;
        //cout<<len<<endl;
}
String append_string(string& str) // appends a String at the end of theString
{
    int index=0;
    while (str[index] != '\0')
        {
            index++;
        }
    int x=index+len;
    char* cap= new char[x+1];
    int temp=0;
    for(int i=0;i<len;i++)
    {
    	cap[i]=data[i];
    	temp=i;
    }
    temp++;
    for(int i=0;i<index;i++)
    {
    	cap[temp]=str[i];
    	temp++;
    }
    cap[x]='\0';
    //cout<<endl<<cap<<endl;
    delete [] data;
    data = cap;
    cap=NULL;
        len=x;
        //cout<<len<<endl;
}
String& assign_string(const String& str) // copies one String to another
{
    int x=str.len;
    char *c=new char[x+1];
    for(int i=0;i<x+1;i++)
    {
        c[i]=str.data[i];
    }
//    cout<<endl<<c;
    delete []data;
    data=c;
    c=NULL;

}
String& assign_string(char* str) // copies one c-string to another
{
        len = 0;
	
        while (str[len] != '\0')
        {
            len++;
        }
        data = new char[len + 1];

        
        for (int i = 0; i < len; i++)
        {
            data[i] = str[i];
        }

        data[len]='\0';
        
        //return b1;
}        
String& assign_string(const string& str) // copies one string to another
{
    int index=0;
    
    while(str[index]!='\0')
    {
    	index++;
    }
    len=index+1;
    data = new char[index+1];
    for (int i = 0; i < len; i++)
        {
            data[i] = str[i];
        }
    //return b1;

}
bool isEqual(const String& str)const //returns true if two Strings are equal
{
    bool flag=false;
    int ind=-1;

    if(len!=str.len)
    {
    	return false;
    }
    char *check=new char[(str.len)+1];
    char * c=str.data;

    for(int k=0;k<(str.len)+1;k++)
    {
    check[k]=*(c+k);
    }

    int x=0;
     for(int i=0;i<len;i++)
    {
    
    	if(check[0]==data[i]&& x==0)
    	{
    		ind=i;
    	}
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==str.len && flag==true)
            {
            	break;
            }
            continue;
        }
        else
        {
        	flag=false;
        	x=0;
        }
    }
    if(flag==false)
    {
    	ind=-1;
    }
    delete []check;
    check=NULL;
    return flag;
}
bool isEqual(const string& str)const //returns true if two strings are equal
{
    bool flag=false;
    int ind = -1;

    int index=0;
    while(str[index]!='\0')
    {
    	index++;
    }
    if(len!=index)
    {
    	return false;
    }
    char *check=new char[index+1];

    for(int k=0;k<index+1;k++)
    {
    check[k]=str[k];
    }

    int x=0;
     for(int i=0;i<len;i++)
    {
    
    	if(check[0]==data[i]&& x==0)
    	{
    		ind=i;
    	}
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==index && flag==true)
            {
            	break;
            }
            continue;
        }
        else
        {
        	flag=false;
        	x=0;
        }
    }
    if(flag==false)
    {
    	ind=-1;
    }
    delete []check;
    check=NULL;
    return flag;
}
bool isEqual(char *p)const //returns true if two strings are equal
{
    bool flag=false;
    int ind = -1;
    int index=0;
    while(p[index]!='\0')
    {
    	index++;
    }
    
    if(len!=index)
    {
    	return false;
    }    
    char *check=new char[index+1];


    for(int k=0;k<index+1;k++)
    {
    check[k]=p[k];
    }

    int x=0;
     for(int i=0;i<len;i++)
    {
    
    	if(check[0]==data[i]&& x==0)
    	{
    		ind=i;
    	}
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==index && flag==true)
            {
            	break;
            }
            continue;
        }
        else
        {
        	flag=false;
        	x=0;
        }
    }
    if(flag==false)
    {
    	ind=-1;
    }
    delete []check;
    check=NULL;
    return flag; 
}
String remove_string(const char & substr) //removes the substr from the String
{
    bool flag=false;
    int dataindex=-1;

    char *check=new char[2];
    check[0]=substr;
    check[1]='\0';
    
    int x=0;
     for(int i=0;i<len;i++)
    {
    
        if(check[0]==data[i]&& x==0)
        {
            dataindex=i;
        }
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==1 && flag==true)
            {
                break;
            }
            continue;
        }
        else
        {
            flag=false;
            x=0;
        }
    }
    int inputendindata=dataindex+1;
    if(flag)
    {
    	//cout<<"\nString found at:"<<dataindex<<" and ends at:"<<inputendindata<<endl;
    	char *p=new char[len-2];
    	int x1=0;
    	for(int i=0;i<len+1;i++)
    	{
    		if(i==dataindex)
    		{
    			continue;
    		}
    		else
    		{
    			p[x1]=data[i];
    			x1++;
    		}
    	}
    	delete []data;
    	data=p;
    	//cout<<endl<<data<<endl;
    	p=NULL;
    }
    else
    {
    	//cout<<"\nNot found.\n";
    }
}


String remove_string(const String &substr) //removes the substr from the String
{
    char *input=substr.data;
    //cout<<endl<<input<<endl;
    bool flag=false;
    int dataindex,inputendindata;
    
    int count=0,l=0;
    while(input[l]!='\0')
    {
        count++;
        l++;
    }
    //cout<<"\nTotal length of input:"<<count<<endl;
    for (int i=0; i<len+1;i++)
    {
        for(int j=0; j<count;j++)
        {
            if (data[i+j]==input[j])
            {
              flag=true;
              inputendindata=i+j;
         //     if(jcount)
           //   {
             // 	break;
              //}
              continue;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if (flag==true)
        {
            dataindex=i;
            break;
        }
        //paraend=i;

    }
    if(flag)
    {
    	//cout<<"\nString found at:"<<dataindex<<" and ends at:"<<inputendindata;
    	char *p=new char[len-count];
    	int x=0;
    	for(int i=0;i<len+1;i++)
    	{
    		if(i>=dataindex &&i<=inputendindata)
    		{
    			continue;
    		}
    		else
    		{
    			p[x]=data[i];
    			x++;
    		}
    	}
    	delete []data;
    	data=p;
    	p=NULL;
    }
    else
    {
    	//cout<<"\nNot found.\n";
    }
    
}
String remove_string( string &substr) //removes the substr from theString
{
    //char *input=substr.data;
    //cout<<endl<<input<<endl;
    bool flag=false;
    int dataindex,inputendindata;
    
    int count=0,l=0;
    while(substr[l]!='\0')
    {
        count++;
        l++;
    }
    //cout<<"\nTotal length of input:"<<count<<endl;
    for (int i=0; i<len+1;i++)
    {
        for(int j=0; j<count;j++)
        {
            if (data[i+j]==substr[j])
            {
              flag=true;
              inputendindata=i+j;
         //     if(jcount)
           //   {
             // 	break;
              //}
              continue;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if (flag==true)
        {
            dataindex=i;
            break;
        }
        //paraend=i;

    }
    if(flag)
    {
    	//cout<<"\nString found at:"<<dataindex<<" and ends at:"<<inputendindata;
    	char *p=new char[len-count];
    	int x=0;
    	for(int i=0;i<len+1;i++)
    	{
    		if(i>=dataindex &&i<=inputendindata)
    		{
    			continue;
    		}
    		else
    		{
    			p[x]=data[i];
    			x++;
    		}
    	}
    	delete []data;
    	data=p;
    	p=NULL;
    }
    else
    {
    	//cout<<"\nNot found.\n";
    }	
}
String remove_string( char *& substr) //removes the substr from the String
{
	    bool flag=false;
    int dataindex,inputendindata;
    
    int count=0,l=0;
    while(substr[l]!='\0')
    {
        count++;
        l++;
    }
    //cout<<"\nTotal length of input:"<<count<<endl;
    for (int i=0; i<len+1;i++)
    {
        for(int j=0; j<count;j++)
        {
            if (data[i+j]==substr[j])
            {
              flag=true;
              inputendindata=i+j;
         //     if(jcount)
           //   {
             // 	break;
              //}
              continue;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if (flag==true)
        {
            dataindex=i;
            break;
        }
        //paraend=i;

    }
    if(flag)
    {
    	//cout<<"\nString found at:"<<dataindex<<" and ends at:"<<inputendindata;
    	char *p=new char[len-count];
    	int x=0;
    	for(int i=0;i<len+1;i++)
    	{
    		if(i>=dataindex &&i<=inputendindata)
    		{
    			continue;
    		}
    		else
    		{
    			p[x]=data[i];
    			x++;
    		}
    	}
    	delete []data;
    	data=p;
    	p=NULL;
    }
    else
    {
    	//cout<<"\nNot found.\n";
    }	
}

int index_at (char p) const // returns the index of the character beingsearched?
{

    int ind=-1;
    for(int i=0;i<len;i++)
    {
        if(data[i]==p)
        {
            ind=i;
            break;
        }

    }
    return ind;

}

int index_at (const String & str) const // returns the start index of the String being searched
{
    bool flag=false;
    int ind=-1;

    char *check=new char[(str.len)+1];
    char * c=str.data;

    for(int k=0;k<(str.len)+1;k++)
    {
    check[k]=*(c+k);
    }

    int x=0;
     for(int i=0;i<len;i++)
    {
    
    	if(check[0]==data[i]&& x==0)
    	{
    		ind=i;
    	}
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==str.len && flag==true)
            {
            	break;
            }
            continue;
        }
        else
        {
        	flag=false;
        	x=0;
        }
    }
    if(flag==false)
    {
    	ind=-1;
    }
    delete []check;
    check=NULL;
    return ind;
}



int index_at(const string& str) const // returns the start index of the string being searched
{
    bool flag=false;
    int ind = -1;

    int index=0;
    while(str[index]!='\0')
    {
    	index++;
    }
    
    char *check=new char[index+1];

    for(int k=0;k<index+1;k++)
    {
    check[k]=str[k];
    }

    int x=0;
     for(int i=0;i<len;i++)
    {
    
    	if(check[0]==data[i]&& x==0)
    	{
    		ind=i;
    	}
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==index && flag==true)
            {
            	break;
            }
            continue;
        }
        else
        {
        	flag=false;
        	x=0;
        }
    }
    if(flag==false)
    {
    	ind=-1;
    }
    delete []check;
    check=NULL;
    return ind;
}


int index_at (char *p) const // returns the start index of the c-string being searched
{

    bool flag=false;
    int ind = -1;
    int index=0;
    while(p[index]!='\0')
    {
    	index++;
    }
    
    char *check=new char[index+1];

    for(int k=0;k<index+1;k++)
    {
    check[k]=p[k];
    }

    int x=0;
     for(int i=0;i<len;i++)
    {
    
    	if(check[0]==data[i]&& x==0)
    	{
    		ind=i;
    	}
        if(check[x]== data[i])
        {
            //ind=i;
            x++;
            flag=true;
            if(x==index && flag==true)
            {
            	break;
            }
            continue;
        }
        else
        {
        	flag=false;
        	x=0;
        }
    }
    if(flag==false)
    {
    	ind=-1;
    }
    delete []check;
    check=NULL;
    return ind;
}
int length() // returns the length of string
{
	int i=0;con=0;
	while(data[i]!='\0')
	{
		con++;
		i++;
	}
	return con;
}

~String()
    {
        //delete[] data;
        //data=NULL;
    }
};
