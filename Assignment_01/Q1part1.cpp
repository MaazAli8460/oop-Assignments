# include <iostream>

using namespace std;

char* removeSentence(char* Para, char* input);

int main()

{
    int x=1000;
    char *para =new char [x];
    char *input= new char[x];
    para={"maaz ali is my name.i am a good man lol.this assignment."};
    input={"i am a good man lol."};
    cout<<endl<<removeSentence(para,input);

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
            break;
        }
        paraend=i;

    }

    
    cout<<"\nPara index="<<paraindex<<"\nPara index endpoint="<<endpoint<<"\nPara end="<<paraend;
    cout<<endl<<flag<<endl;

    int j=endpoint;
    for(int i=paraindex;i<endpoint; i++)
    {
        if(j<=paraend)
        {
        //int j=endpoint;
        Para[i] = Para[j];
        Para[j]='\0';
        j++;
        }
    }
    cout<<Para;

    return Para;
}

