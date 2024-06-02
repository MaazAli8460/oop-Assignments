
#include<iostream>

using namespace std;

char*** ConvertToDynamic(char arr[], int x, int y, int z);
bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**&resultMat, int& colSize);
void DeleteArray(char***& arr, int x, int y, int z);

int main()
{
    int x=100,a=3,b=3,c=4,col=3;
    char arr[x]={"sbtaicztieahrnltagtsjvehfyf\0"};

    char ***ptr;

    ptr=ConvertToDynamic(arr,a,b,c);

    for(int i=0;i<a;i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int  k = 0; k < c; k++)
            {
                
                cout<< " "<<ptr[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    char * input=new char;
    input={"tag"};
    //input[]={'a','i','c','\0'};
    int **res;
    
    bool flag=  MatchString3DArray(ptr,a,b,c ,input,res,col);
    cout << "dkfmf" << flag << endl;
    for (int i = 0; i < 3; i++)
{
    for(int j=0;j<col;j++)
    cout<<res[i][j]<<"\t";

    cout<<endl;
    /* code */
}

    cout<<"\nThe flag="<<flag<<endl;
    return flag;
    return 0;
}
char*** ConvertToDynamic(char arr[], int x, int y, int z)
{
    char ***p=new char **[x];
    for(int i=0;i<x;i++)
    {
        p[i]=new char*[y];
        for(int j=0;j<y;j++)
        {
            p[i][j]= new char [z];
        }
    }
    int d=0;
    for(int i=0;i<x;i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int  k = 0; k < z; k++)
            {
                if (k!=z-1)
                p[i][j][k]=arr[d];

                else
                {
                p[i][j][k]='\0';
                break;
                }
                d++;
            }
            
        }
        
    }

    return p;
}
//bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**&resultMat, int& colSize)
// {
//     bool flag=false;
//     char *check=new char[colSize];
//     if(colSize==3)
//     {
//         for(int i=0;i<xSize;i++)
//         {
//             for (int j = 0; j < ySize; j++)
//             {
//                 for (int  k = 0; k < zSize; k++)
//                 {
//                     if(i<=xSize && j<=ySize && k<=2)
//                     {
//                         check[k]=mat[i][j][k];
//                     }
//                     if(k==3)
//                     {
//                         check[k]=='\0';
//                         int x=0;
//                         while(x<=3)
//                         {
//                             if(check[x]==input[x])
//                             {
//                                 flag=true;
//                                 x++;
//                                 continue;
//                             }
//                             else
//                             {
//                                 flag=false;
//                                 x++;
//                                 break;
//                             }
//                         }

//                         if(flag==true)
//                         {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
//                             resultMat[0][2]=i;
//                             resultMat[1][0]=j;
//                             resultMat[1][1]=j;
//                             resultMat[1][2]=j;
//                             resultMat[2][0]=0;
//                             resultMat[2][1]=1;
//                             resultMat[2][2]=2;

//                             break;
//                         }
//                     }
//                      if(flag==true)
//                     {
//                          break;
//                     }
//                 }
                
//             }
//             if(flag==true)
//             {
//                 break;
//             }
        
//         }
//     if(flag==true)
//         {
            
//             return flag;
//         }
// //for cols of same page
// check[0]='\0';
// check[1]='\0';
// check[2]='\0';
// check[3]='\0';
//         for(int i=0;i<xSize;i++)
//         {
//             for (int j = 0; j < zSize-1; j++)
//             {
//                 for (int  k = 0; k < ySize; k++)
//                 {
//                     if(i<=xSize && j<=zSize && k<=2)
//                     {
//                         check[k]=mat[i][k][j];
//                     }
//                     if(k==2)
//                     {
//                         check[k+1]=='\0';
                        
//                         int x=0;
//                         while(x<=2)
//                         {
//                             if(check[x]==input[x])
//                             {
//                                 flag=true;
//                                 x++;
//                                 continue;
//                             }
//                             else
//                             {
//                                 flag=false;
//                                 x++;
//                                 break;
//                             }
//                         }

//                         if(flag==true)
//                         {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
//                             resultMat[0][2]=i;
//                             resultMat[1][0]=0;
//                             resultMat[1][1]=1;
//                             resultMat[1][2]=2;
//                             resultMat[2][0]=k;
//                             resultMat[2][1]=k;
//                             resultMat[2][2]=k;

//                             break;
//                         }
//                     }
//                     if(flag==true)
//                     {
//                         break;
//                     }
//                 }
                
//             }
//             if(flag==true)
//             {
//                 break;
//             }
        
//         }
//         if(flag==true)
//             {
//                 return flag;
//             }
// //For diagonals of same page
// check[0]='\0';
// check[1]='\0';
// check[2]='\0';
// check[3]='\0';
// //int alpha=0;
//         for(int i=0;i<xSize;i++)
//         {
//             int alpha=0;
//             for (int j = 0; j < ySize; j++)
//             {
//                 for (int  k = 0; k < zSize; k++)
//                 {
//                     if(j==k)
//                     {
//                         check[alpha]=mat[i][j][k];
//                         alpha++;
//                     }
//                     if(k==3)
//                     {
//                         check[alpha]=='\0';
//                         cout<<check<<endl;
//                         int x=0;
//                         while(x<=3)
//                         {
//                             if(check[x]==input[x])
//                             {
//                                 flag=true;
//                                 x++;
//                                 continue;
//                             }
//                             else
//                             {
//                                 flag=false;
//                                 // check[0]='\0';
//                                 // check[1]='\0';
//                                 // check[2]='\0';
//                                 // check[3]='\0';
//                                 x++;
//                                 break;
//                             }
//                         }

//                         if(flag==true)
//                         {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
//                             resultMat[0][2]=i;
//                             resultMat[1][0]=0;
//                             resultMat[1][1]=1;
//                             resultMat[1][2]=2;
//                             resultMat[2][0]=0;
//                             resultMat[2][1]=1;
//                             resultMat[2][2]=2;

//                             break;
//                         }
//                     }
                    
//                     if(flag==true)
//                     {
//                         break;
//                     }
//                 }
//             }
//         }
//         //For same rows and cols different page
//     for(int i=0;i<zSize-1;i++)
//         {
//             for (int j = 0; j < ySize; j++)
//             {
//                 for (int  k = 0; k < xSize; k++)
//                 {
//                     if(i<=zSize-1 && j<=ySize && k<=2)
//                     {
//                         check[k]=mat[k][j][i];
//                     }
//                     if(k==2)
//                     {
//                         check[k+1]='\0';
//                         cout<<check<<endl;
//                         int x=0;
//                         while(x<=3)
//                         {
//                             if(check[x]==input[x])
//                             {
//                                 flag=true;
//                                 x++;
//                                 continue;
//                             }
//                             else
//                             {
//                                 flag=false;
//                                 x++;
//                                 break;
//                             }
//                         }

//                         if(flag==true)
//                         {
//                             resultMat[0][0]=0;
//                             resultMat[0][1]=1;
//                             resultMat[0][2]=2;
//                             resultMat[1][0]=j;
//                             resultMat[1][1]=j;
//                             resultMat[1][2]=j;
//                             resultMat[2][0]=i;
//                             resultMat[2][1]=i;
//                             resultMat[2][2]=i;

//                             break;
//                         }
//                     }
//                      if(flag==true)
//                     {
//                          break;
//                     }
//                 }
                
//             }
//             if(flag==true)
//             {
//                 break;
//             }
        
//     }
//     if(flag==true)
//     {
//         return flag;
//     }
// //for different page different cols different rows
// //write code

// //same page and diff rows diff cols

//     for(int i=0;i<xSize-1;i++)
//         {
//             if(i<=xSize)
//                     {
//                         check[0]=mat[i][2][0];
//                         check[1]=mat[i][1][1];
//                         check[2]=mat[i][0][2];
//                         check[3]='\0';
//                         cout<<check<<endl;
//                         int x=0;
//                         while(x<=3)
//                         {
//                             if(check[x]==input[x])
//                             {
//                                 flag=true;
//                                 x++;
//                                 continue;
//                             }
//                             else
//                             {
//                                 flag=false;
//                                 x++;
//                                 break;
//                             }
//                         }

//                         if(flag==true)
//                         {
//                             resultMat[0][0]=0;
//                             resultMat[0][1]=1;
//                             resultMat[0][2]=2;
//                             resultMat[1][0]=2;
//                             resultMat[1][1]=1;
//                             resultMat[1][2]=0;
//                             resultMat[2][0]=0;
//                             resultMat[2][1]=1;
//                             resultMat[2][2]=2;

//                             break;
//                         }
//             if(flag==true)
//             {
//                 break;
//             }
        
//         }
//     }
//         if(flag==true)
//         {
//             return flag;
//         }
//     }
//     else if(colSize==2)
//     {
//         //for same rows
//         for(int i=0;i<xSize;i++)
//         {
//             for(int j=0;j<ySize;j++)
//             {
//                 int x=0;
//                 for(int k=0;k<colSize;k++)
//                 {
//                     if(mat[i][j][k]==input[x])
//                     {
//                         x++;
//                         flag=true;
//                         continue;
//                     }
//                     else{
//                         flag=false;
//                     }
//                 }
//                 if(flag==true)
//             {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
                            
//                             resultMat[1][0]=j;
//                             resultMat[1][1]=j;
                            
//                             resultMat[2][0]=0;
//                             resultMat[2][1]=1;
                            
//                 break;
//             }
//             }
//             if(flag==true)
//             {
//                 break;
//             }
//         }
//         if(flag==true)
//         {
//             return flag;
//         }
//         //for same cols
//         for(int i=0;i<xSize;i++)
//         {
//             for(int j=0;j<zSize;j++)
//             {
//                 int x=0;
//                 for(int k=0;k<colSize;k++)
//                 {
//                     if(mat[i][k][j]==input[x])
//                     {
//                         x++;
//                         flag=true;
//                         continue;
//                     }
//                     else{
//                         flag=false;
//                     }
//                 }
//                 if(flag==true)
//             {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
                            
//                             resultMat[1][0]=0;
//                             resultMat[1][1]=1;
                            
//                             resultMat[2][0]=j;
//                             resultMat[2][1]=j;
//                 break;
//             }
//             }
//             if(flag==true)
//             {
//                 break;
//             }
//         }
//         if(flag==true)
//         {
//             return flag;
//         }
//         //for same diagonals
//         for(int i=0;i<xSize;i++)
//         {
//             int x=0;
//             for(int j=0;j<ySize;j++)
//             {
                
//                 for(int k=0;k<colSize;k++)
//                 {
//                     if(mat[i][j][k]==input[x] && j==k)
//                     {
//                         x++;
//                         flag=true;
//                         continue;
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 if(flag==true)
//             {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
                            
//                             resultMat[1][0]=j;
//                             resultMat[1][1]=j;
                            
//                             resultMat[2][0]=j;
//                             resultMat[2][1]=j;
//                 break;
//             }
//             }
//             if(flag==true)
//             {
//                 break;
//             }
//         }
//         if(flag==true)
//         {
//             return flag;
//         }
//         for(int i=0;i<xSize;i++)
//         {
//             int x=0;
//             for(int j=0;j<colSize;j++)
//             {
                
//                 for(int k=zSize-1;k>0;k--)
//                 {
//                     if(mat[i][j][k]==input[x] &&(k<=1))
//                     {
//                         x++;
//                         flag=true;
//                         continue;
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 if(flag==true)
//             {
//                             resultMat[0][0]=i;
//                             resultMat[0][1]=i;
                            
//                             resultMat[1][0]=0;
//                             resultMat[1][1]=1;
                            
//                             resultMat[2][0]=2;
//                             resultMat[2][1]=1;
//                 break;
//             }
//             }
//             if(flag==true)
//             {
//                 break;
//             }
//         }
//                 if(flag==true)
//         {
//             return flag;
//         }
//     }

// for (int i = 0; i < 3; i++)
// {
//     for(int j=0;j<colSize;j++)
//     cout<<resultMat[i][j]<<"\t";

//     cout<<endl;
//     /* code */
// }


//     cout<<"\nThe flag at end of the loop="<<flag<<endl;

//     return flag;
// }
bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**&resultMat, int& colSize)
{
    int d=0;
    int count=0;
    while(input[d]!='\0')
    {
    	count++;
    	d++;
    }
    if(count==3)
    {
    	colSize=3;
    	cout<<"\nThis is col size for count 3:"<<colSize;
    }
    else if(count==2)
    {
    	colSize=2;
    	cout<<"\nThis is col size for count 2:"<<colSize;
    }
    //colSize=3;
    resultMat=new int*[3];
    for (int i = 0; i < 3; i++)
    {
        resultMat[i]=new int[colSize];
    }
    bool flag=false;
    char *check=new char[colSize];
    cout<<"\nbefore if(colSize==3)";
    if(colSize==3)
    {
        for(int i=0;i<xSize;i++)
        {
            for (int j = 0; j < ySize; j++)
            {
                for (int  k = 0; k < zSize; k++)
                {
                    if(i<=xSize && j<=ySize && k<=2)
                    {
                        check[k]=mat[i][j][k];
                    }
                    if(k==3)
                    {
                        check[k]=='\0';
                        int x=0;
                        while(x<=3)
                        {
                            if(check[x]==input[x])
                            {
                                flag=true;
                                x++;
                                continue;
                            }
                            else
                            {
                                flag=false;
                                x++;
                                break;
                            }
                        }

                        if(flag==true)
                        {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            resultMat[0][2]=i;
                            resultMat[1][0]=j;
                            resultMat[1][1]=j;
                            resultMat[1][2]=j;
                            resultMat[2][0]=0;
                            resultMat[2][1]=1;
                            resultMat[2][2]=2;

                            break;
                        }
                    }
                     if(flag==true)
                    {
                         break;
                    }
                }
                
            }
            if(flag==true)
            {
                break;
            }
        
        }
         if(flag==true)
            {
            	cout<<"\nBefore return";
            	
                return flag;
                cout<<"\nAfter return";
            }
            cout<<"\noutside return";
//for cols of same page
check[0]='\0';
check[1]='\0';
check[2]='\0';
check[3]='\0';
	if(flag==false)
	{
        for(int i=0;i<xSize;i++)
        {
            for (int j = 0; j < zSize-1; j++)
            {
                for (int  k = 0; k < ySize; k++)
                {
                    if(i<=xSize && j<=zSize && k<=2)
                    {
                        check[k]=mat[i][k][j];
                    }
                    if(k==2)
                    {
                        check[k+1]=='\0';
                        
                        int x=0;
                        while(x<=2)
                        {
                            if(check[x]==input[x])
                            {
                                flag=true;
                                x++;
                                continue;
                            }
                            else
                            {
                                flag=false;
                                x++;
                                break;
                            }
                        }

                        if(flag==true)
                        {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            resultMat[0][2]=i;
                            resultMat[1][0]=0;
                            resultMat[1][1]=1;
                            resultMat[1][2]=2;
                            resultMat[2][0]=k;
                            resultMat[2][1]=k;
                            resultMat[2][2]=k;

                            break;
                        }
                    }
                    if(flag==true)
                    {
                        break;
                    }
                }
                
            }
            if(flag==true)
            {
                break;
            }
        
        }
        if(flag==true)
            {
                return flag;
            }
       }
//For diagonals of same page
check[0]='\0';
check[1]='\0';
check[2]='\0';
check[3]='\0';
//int alpha=0;
	if(flag==false)
	{
        for(int i=0;i<xSize;i++)
        {
            int alpha=0;
            for (int j = 0; j < ySize; j++)
            {
                for (int  k = 0; k < zSize; k++)
                {
                    if(j==k)
                    {
                        check[alpha]=mat[i][j][k];
                        alpha++;
                    }
                    if(k==3)
                    {
                        check[alpha]=='\0';
                        cout<<check<<endl;
                        int x=0;
                        while(x<=3)
                        {
                            if(check[x]==input[x])
                            {
                                flag=true;
                                x++;
                                continue;
                            }
                            else
                            {
                                flag=false;
                                // check[0]='\0';
                                // check[1]='\0';
                                // check[2]='\0';
                                // check[3]='\0';
                                x++;
                                break;
                            }
                        }

                        if(flag==true)
                        {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            resultMat[0][2]=i;
                            resultMat[1][0]=0;
                            resultMat[1][1]=1;
                            resultMat[1][2]=2;
                            resultMat[2][0]=0;
                            resultMat[2][1]=1;
                            resultMat[2][2]=2;

                            break;
                        }
                    }
                    
                    if(flag==true)
                    {
                        break;
                    }
                }
            }
        }
        }
        //For same rows and cols different page
        if(flag==false)
	{
    for(int i=0;i<zSize-1;i++)
        {
            for (int j = 0; j < ySize; j++)
            {
                for (int  k = 0; k < xSize; k++)
                {
                    if(i<=zSize-1 && j<=ySize && k<=2)
                    {
                        check[k]=mat[k][j][i];
                    }
                    if(k==2)
                    {
                        check[k+1]='\0';
                        cout<<check<<endl;
                        int x=0;
                        while(x<=3)
                        {
                            if(check[x]==input[x])
                            {
                                flag=true;
                                x++;
                                continue;
                            }
                            else
                            {
                                flag=false;
                                x++;
                                break;
                            }
                        }

                        if(flag==true)
                        {
                            resultMat[0][0]=0;
                            resultMat[0][1]=1;
                            resultMat[0][2]=2;
                            resultMat[1][0]=j;
                            resultMat[1][1]=j;
                            resultMat[1][2]=j;
                            resultMat[2][0]=i;
                            resultMat[2][1]=i;
                            resultMat[2][2]=i;

                            break;
                        }
                    }
                     if(flag==true)
                    {
                         break;
                    }
                }
                
            }
            if(flag==true)
            {
                break;
            }
        
    }
    if(flag==true)
    {
        return flag;
    }
    }
//for different page different cols different rows
//write code

//same page and diff rows diff cols
if(flag==false)
	{
    for(int i=0;i<xSize-1;i++)
        {
            if(i<=xSize)
                    {
                        check[0]=mat[i][2][0];
                        check[1]=mat[i][1][1];
                        check[2]=mat[i][0][2];
                        check[3]='\0';
                        cout<<check<<endl;
                        int x=0;
                        while(x<=3)
                        {
                            if(check[x]==input[x])
                            {
                                flag=true;
                                x++;
                                continue;
                            }
                            else
                            {
                                flag=false;
                                x++;
                                break;
                            }
                        }

                        if(flag==true)
                        {
                            resultMat[0][0]=0;
                            resultMat[0][1]=1;
                            resultMat[0][2]=2;
                            resultMat[1][0]=2;
                            resultMat[1][1]=1;
                            resultMat[1][2]=0;
                            resultMat[2][0]=0;
                            resultMat[2][1]=1;
                            resultMat[2][2]=2;

                            break;
                        }
            if(flag==true)
            {
                break;
            }
        
        }
    }
        if(flag==true)
        {
            return flag;
        }
        }
    }
    else if(colSize==2)
    {
        //for same rows
        for(int i=0;i<xSize;i++)
        {
            for(int j=0;j<ySize;j++)
            {
                int x=0;
                for(int k=0;k<colSize;k++)
                {
                    if(mat[i][j][k]==input[x])
                    {
                        x++;
                        flag=true;
                        continue;
                    }
                    else{
                        flag=false;
                    }
                }
                if(flag==true)
            {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            
                            resultMat[1][0]=j;
                            resultMat[1][1]=j;
                            
                            resultMat[2][0]=0;
                            resultMat[2][1]=1;
                            
                break;
            }
            }
            if(flag==true)
            {
                break;
            }
        }
        if(flag==true)
        {
            return flag;
        }
        //for same cols
        for(int i=0;i<xSize;i++)
        {
            for(int j=0;j<zSize;j++)
            {
                int x=0;
                for(int k=0;k<colSize;k++)
                {
                    if(mat[i][k][j]==input[x])
                    {
                        x++;
                        flag=true;
                        continue;
                    }
                    else{
                        flag=false;
                    }
                }
                if(flag==true)
            {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            
                            resultMat[1][0]=0;
                            resultMat[1][1]=1;
                            
                            resultMat[2][0]=j;
                            resultMat[2][1]=j;
                break;
            }
            }
            if(flag==true)
            {
                break;
            }
        }
        if(flag==true)
        {
            return flag;
        }
        //for same diagonals
        for(int i=0;i<xSize;i++)
        {
            int x=0;
            for(int j=0;j<ySize;j++)
            {
                
                for(int k=0;k<colSize;k++)
                {
                    if(mat[i][j][k]==input[x] && j==k)
                    {
                        x++;
                        flag=true;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(flag==true)
            {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            
                            resultMat[1][0]=j;
                            resultMat[1][1]=j;
                            
                            resultMat[2][0]=j;
                            resultMat[2][1]=j;
                break;
            }
            }
            if(flag==true)
            {
                break;
            }
        }
        if(flag==true)
        {
            return flag;
        }
        for(int i=0;i<xSize;i++)
        {
            int x=0;
            for(int j=0;j<colSize;j++)
            {
                
                for(int k=zSize-1;k>0;k--)
                {
                    if(mat[i][j][k]==input[x] &&(k<=1))
                    {
                        x++;
                        flag=true;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(flag==true)
            {
                            resultMat[0][0]=i;
                            resultMat[0][1]=i;
                            
                            resultMat[1][0]=0;
                            resultMat[1][1]=1;
                            
                            resultMat[2][0]=2;
                            resultMat[2][1]=1;
                break;
            }
            }
            if(flag==true)
            {
                break;
            }
        }
                if(flag==true)
        {
            return flag;
        }
    }



    cout<<"\nThe flag at end of the loop="<<flag<<endl;

    return flag;
}
void DeleteArray(char***& arr, int x, int y, int z)
{
    for (int i = 0; i < x; i++)
    {
        for(int j=0;j<y;j++)
        {
            delete [] arr[j][z];
        }
        /* code */
    }
    delete []arr;
    arr=nullptr;
    
}

// if (k <= 2 && j <= 2) {
//                     char diagonalString[4] = "";
//                     int n = 0;
//                     while (i+n <= 2 && j+n <= 2 && n < 3) {
//                         diagonalString[n] = matrix[i+n][j+n][k];
//                         n++;
//                     }
//                     if (matchString(diagonalString, searchString, n) && n >= 2 && n <= 3) {
//                         // found a match
//                         cout << "in the same column but different planes Match found at position [" << i << "][" << j << "][" << k << "]" << endl;
//                     }
//                 }