# include <iostream>
using namespace std;

char* removeSentence(char* Para, char* input);

int main()

{
 
    char para[] = " maaz ali is in bs. he studies hard. he is nice. ";
    cout << para << endl;

    char input[] = " he is nice.";
    cout << input << endl;

    removeSentence(para, input);

    return 0;
}

char* removeSentence(char* Para, char* input)
{
    char temp =0;
    bool flag = false;
    int startpoint = 0, endpoint = 0, paralength = 0, inputlength=0;
    int count = 0, l = 0;
    while (Para[l] != '\0')
    {
        count++;
        l++;
    }

    cout << "\nTotal length of array:" << count << endl;

    for (int i = 0; Para[i] != '\0'; i++)
    {
        paralength++;
    }

    for (int j = 0; input[j] != '\0'; j++)
    {
        inputlength++;
    }

    for (int i = 0; i <= paralength; i++)
    {
        //int j = 0;
        for( int j = 0; j <= inputlength; j ++)
        {
            if (Para[i + j] != input[j]) 
            {
                break;
            }

            if (j == inputlength - 1)
            {
                startpoint = i;
            }
        }     
        
    }
 
    endpoint = startpoint + inputlength;

    int k = endpoint;
    
    for (int i = startpoint; i <= k; i++)
    {
            //int j=endpoint;
            Para[i] = Para[k];
            Para[k] = '\0';
            
            if (k <= count - 1)
            {
                k++;
            }   
    }

    for (int i = 0; i < count; i++)
    {
        cout << Para[i] << " ";
    }
    return Para;
}
