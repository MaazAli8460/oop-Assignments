# include <iostream>

using namespace std;


bool FindSubString(char* Str, char* substr,int & start, int & end);


int main()
{
    char* str=new char;
    str={"affects"};
    char* sub=new char;
    sub={"sad"};
    int s,e;

    bool fl;
    fl=FindSubString(str,sub,s,e);
    return 0;
}
bool FindSubString(char* Str, char* substr,int & start, int & end)
{
    bool flag=false,f1=false;
    int x=0,count=0,temp=0;
    while(Str[x]!='\0')
    {
        temp++;
        x++;
    }
    x=0;
    //while(substr[x]!='\0')
    {
        
        for (int i = 0; Str[i] !='\0'; i++)
        {
            if(count==temp)
            {i--;}
            count++;
            if(substr[x]==Str[i] && substr[x]!='\0')
            {
                if(x==0)
                {
                start=i;
                }
                f1=true;
                x++;
                //continue;
                if(Str[i+1]=='\0' && f1==true && substr[x]==Str[0])
                {
                    end=i;
                    i=0;
                }
                //continue;
            }

            if(substr[x]=='\0'&& f1==true)
            {
                end=i;
                f1=false;
                flag=true;
                break;
            }
            else if(f1==false)
            {
                flag=false;
                end=-1;
                start=-1;

            }
            /* code */
        }

    }
    if(flag==false)
    {
        end=-1;
        start=-1;
    }
    cout<<"\nThis is flag:"<<flag<<endl;
    cout<<"\nThis is end:"<<end<<endl;
    cout<<"\nThis is start:"<<start<<endl;
    
    return flag;
}