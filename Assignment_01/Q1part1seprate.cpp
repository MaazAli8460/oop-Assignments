#include <iostream>

using namespace std;


char* removeSentence(char* Para, char* input);

int main()

{
    int x=1000;
    char *para =new char [x];
    char *input= new char[x];
    para={"maaz ali is my name.i am a good man lol.how are you.\0"};
    input={"i am a good man lol.\0"};
    removeSentence(para,input);

    return 0;
}

char* removeSentence(char* Para, char* input)
{
    char temp;
    bool flag=false;
    int paraindex,endpoint,paraend;
    int count=0,l=0;
    while(Para[l]!='\0')
    {
        count++;
        l++;
    }
    cout<<"\nTotal length of array:"<<count;
    for (int i=0; Para[i]!='\0';i++)
    {
        for(int j=0; input[j]!='\0';j++)
        {
            if (Para[i+j]==input[j])
            {
              flag=true;
              endpoint=i+j;
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
            paraindex=i;
        }
        paraend=i;

    }

    
    cout<<"\nPara index="<<paraindex<<"\nPara index endpoint="<<endpoint<<"\nPara end="<<paraend;
    cout<<endl<<flag<<endl;

    char * para1=new char[paraend];

    int pp;

    pp=endpoint-paraindex;

    for(int i=0;i<paraend;i++)
    {
        for(int j=0;input[j]!='\0';j++)
        {
            if(Para[i+j]==input[j])
            {
                continue;
            }
            else
            {
                para1[i]=Para[i];
            }

        }
    }

   // cout<<para1;
    cout<<endl<<Para;
    Para=para1;
    cout<<endl<<Para;
    return Para;
}
