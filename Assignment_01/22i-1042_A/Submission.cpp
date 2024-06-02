#include <iostream>
using namespace std;

//Name:MAAZ ALI

//Roll-no:22i-1042

//ASSIGNMENT 01


char* removeSentence(char* Para, char* input)
{/*
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
        for( int j = 0; j < inputlength; j ++)
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
*/
}

bool FindSubString(char* Str, char* substr, int& start, int& end)
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

/*bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**& resultMat, int& colSize)
{

}*/
bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**&resultMat, int& colSize)
{
//     int d=0;
//     int count=0;
//     while(input[d]!='\0')
//     {
//     	count++;
//     	d++;
//     }
//     if(count==3)
//     {
//     	colSize=3;
//     	cout<<"\nThis is col size for count 3:"<<colSize;
//     }
//     else if(count==2)
//     {
//     	colSize=2;
//     	cout<<"\nThis is col size for count 2:"<<colSize;
//     }
//     //colSize=3;
//     resultMat=new int*[3];
//     for (int i = 0; i < 3; i++)
//     {
//         resultMat[i]=new int[colSize];
//     }
//     bool flag=false;
//     char *check=new char[colSize];
//     cout<<"\nbefore if(colSize==3)";
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
//          if(flag==true)
//             {
//             	cout<<"\nBefore return";
            	
//                 return flag;
//                 cout<<"\nAfter return";
//             }
//             cout<<"\noutside return";
// //for cols of same page
// check[0]='\0';
// check[1]='\0';
// check[2]='\0';
// check[3]='\0';
// 	if(flag==false)
// 	{
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
//        }
// //For diagonals of same page
// check[0]='\0';
// check[1]='\0';
// check[2]='\0';
// check[3]='\0';
// //int alpha=0;
// 	if(flag==false)
// 	{
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
//         }
//         //For same rows and cols different page
//         if(flag==false)
// 	{
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
//     }
// //for different page different cols different rows
// //write code

// //same page and diff rows diff cols
// if(flag==false)
// 	{
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



//     cout<<"\nThe flag at end of the loop="<<flag<<endl;

  //  return flag;
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

bool isperfectNumber(int n)
{
    static int sum=1;
    static int temp=n;

    if (n==1)
    return 1;

    if(temp%n==0 && n!=temp)
    sum+=n;

    isperfectNumber(n-1);

    if(sum==temp)
    return true;
    else
    return false;
}
int countVowels(char* str, int x);
int findVowels(char* str)
{
return countVowels(str, 0);
}

int countVowels(char* str, int x)
{
    if (*str == '\0')
    {
        return x;
    }

    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
    {
        x = x + 1;
    }

    return countVowels(str + 1, x);
}


int pascal(int row, int col) 
{
    if (col == 0 || col == row || row == 0) 
	{
        return 1;
    }
    
    return pascal(row - 1, col) + pascal(row - 1, col - 1);
}

void space(int str, int e);
void PrintPattern3(int start, int end);
void PrintPattern3(int start, int end) //This is the Recursive Function to Print the "X" Pattern
	{
		if (start==(start+end)/2) //To Take the middle staric we have used This Operation
		{
			cout<<'*'<<endl;
			return;
		}
		
		space(start, end);
		cout<<"*";
		cout<<endl;
		
		PrintPattern3(start+1, end-1);

		space(start, end);
		cout<<"*";
		cout<<endl;
	}
	
void PrintPattern1(int start, int end)
{
		if (start==(start+end)/2) //To Take the middle staric we have used This Operation
		{
			cout<<'*'<<endl;
			return;
		}
		
		space(start, end);
		cout<<"*";
		cout<<endl;
		
		PrintPattern3(start+1, end-1);

		space(start, end);
		cout<<"*";
		cout<<endl;
}

void space(int str, int e) //This is the recursive Function to Print the Pattern
{
	if (str==e)
	return;
	cout<<" ";
	space(++str,e);
}	

void space(int sp)
{
    if (sp == 0)
    {
        return;
    }
    else
    cout<<"  ";

    space(sp - 1);
}

void print(int num2)
{
    if (num2 == 0)
    {
        return;
    }
    else
    cout << "* ";
    print(num2 - 1);
}  


void lowerdiamond(int n, int num)
{

    if (n == 0)
    {
        return;
    }

    print(num - n + 1);
    
    space(2 * n - 2);
    
    print(num - n + 1);
    
    cout <<'\n';
  

    lowerdiamond(n - 1, num);

}

void upperdiamond(int n, int num)
{

    if (n == 0)
    {
        return;
    }
    print(n);
    
    space(2 * (num - n));
    
    print(n);
    
    cout << '\n';
  
    
    upperdiamond(n - 1, num);
}
  

void printHollowDiamond(int n){
    int num=n;

    upperdiamond(n, num);
    
    lowerdiamond(n - 1, num);
}
void PrintPattern2(int , int )
{

}
void rules();//rules for playing game

void startSnakeGame(); // controller of the game

int** snakeBoardCreation(int ,int);//creates game board

void displayBoard(int **,int m,int n);//displays board

int playdice();//plays dice

bool checkSnakeHead(int**,int&,int); //checks for snakes head

bool checkLadderFoot(int **,int&,int);// checks for ladern foot

bool anomly(int , int);

void printPosition(int**,int**,int x, int y);//prints the position of snakes and ladders on the board
void startSnakeGame()
{
    srand(time(0));

    int m,n;
    cout<<"\nEnter number of rows:";
    cin>>m;
    cout<<"\nEnter number of cols:";
    cin>>n;
    rules();//calling rules ftn
    //game board generator ftn
    int **gameboard;
    gameboard=snakeBoardCreation(m,n);

    //winning position is saved in variable to check later...
    int win_pos;
    if(m%2==0)
    {
            win_pos=gameboard[0][0];
    }
    else
    {
            win_pos=gameboard[0][n-1];
    }
    //Snake and lader generator
    int s=n-1;
    int **snake=new int *[s];
    for(int i=0;i<s;i++)
    {
       snake[i]=new int[2];
    }
    int l=n-1;
    int **lader=new int *[l];
    for(int i=0;i<l;i++)
    {
       lader[i]=new int[2];
    }
    
        
    for (int i = 0; i < s; i++) {
        
        int temp;
        temp=i;
        snake[i][0] = gameboard[i][rand() % (n - 1) + 1];
        while(temp<=i)
        temp=rand()%s+1;
        snake[i][1] = gameboard[temp][rand() % (n - 1) + 1];
    }
    for (int i = 0; i < l; i++) {
        int temp;
        temp=i;

        lader[i][0] = gameboard[i][rand() % (n - 1) + 1];
        
        while(temp<=i)
        temp=rand()%l+1;

        lader[i][1] = gameboard[temp][rand() % (n - 1) + 1];
    }

    int player1=0,player2=0;
    bool sh=false,lf=false;
    //start of actual game
    //Playas dice for first time
    int die1=0;
    char key1;
    int die2=0;
    char key2;
    bool fl1=false,fl2=false;
    do
    {
        key1='\0';
        key2='\0';
        cout<<"\nPlayer1";
        if(fl1==false)
        {
            if(playdice()==6 )
           {
                cout<<"\nCongrats! player1 can start the game now.";
                die1=6;
                fl1=true;
            }
            else
            {
                cout<<"\nSorry player1 need a 6 to start playing.";
                fl1=false;
            }

        }
        cout<<"\nEnter c to continue:";
        cin>>key1;
        //if not 6 then plays agian
        cout<<"\nPlayer2";
        if(fl2==false)
        {
            if(playdice()==6)
            {
                cout<<"\nCongrats! player2 can start the game now.";
                die2=6;
                fl2=true;
            }
            else
            {
                cout<<"\nSorry player2 need a 6 to start playing.";
                fl2=false;
            }
            
        }
        cout<<"\nEnter c to continue:";
        cin>>key2;
        if(die1==6)
        {
            displayBoard(gameboard,m,n);
            printPosition(snake,lader,s,l);
            player1+=playdice();
            cout<<"\nPlayer1 score :"<<player1;
            bool ps1=false,pl1=false;

            ps1=checkSnakeHead(snake,player1,s);
            pl1=checkLadderFoot(lader,player1,s);
            cout<<"\nPlayer1 score :"<<player1;
            if(anomly(player1,win_pos)) //check weather player 1 has won or not
            {
                cout<<"\nPlayer 1 has won.\nHard luck player 2.\n\tGAME OVER\n";
                break;
            }
            cout<<"\nEnter c to continue:";
            cin>>key1;

        }
        if(die2==6)
        {
            displayBoard(gameboard,m,n);
            printPosition(snake,lader,s,l);
            player2+=playdice();
            cout<<"\nPlayer2 score :"<<player2;
            bool ps2=false,pl2=false;

            ps2=checkSnakeHead(snake,player2,s);
            pl2=checkLadderFoot(lader,player2,s);
            cout<<"\nPlayer2 score :"<<player2;
            if(anomly(player2,win_pos)) //check weather player 2 has won or not
            {
                cout<<"\nPlayer 2 has won.\nHard luck player 1.\n\tGAME OVER\n";
                break;
            }
            cout<<"\nEnter c to continue:";
            cin>>key2;

        }

    } while ( key1=='c'|| key2=='c');

    //Its a good programing practice to delete the dynamic allocated memory
    //so here I am deleting the gameboard;

    for (int i = 0; i < m; i++)
    {
        delete [] gameboard[i];
    }
    delete [] gameboard;
    

}

int** snakeBoardCreation(int m ,int n)
{
    int **p=new int *[m];
    for(int i=0;i<m;i++)
    {
       p[i]=new int[n];
    }
    int num;
    num=m*n;
    if(m%2==0)
    {

        for(int i=0;i<m;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<n;j++)
                {
                    p[i][j]=num;
                    num--;
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    p[i][j]=num;
                    num--;
                }
            }
        }
    }
    else

    {
        for(int i=0;i<m;i++)
        {
            if(i%2==0)
            {
                for(int j=n-1;j>=0;j--)
                {
                    p[i][j]=num;
                    num--;
                } 
            }
            else
            {
               
                for(int j=0;j<n;j++)
                {
                    p[i][j]=num;
                    num--;
                }
            }
        }
    }

    return p;
}

//plays dice
int playdice()
{
    int die=rand()%6 +1;
    cout<<"\nYou rolled:"<<die;
    
    return die;
}
bool checkSnakeHead(int **sh,int& point,int s) //checks for snakes head
{
    int j=0;
    bool snakehead=false;

    for(int i=0;i<s;i++)
    {
        if(sh[i][j]==point)
        {
            snakehead=true;
            point=sh[i][1];
            cout<<"\nOpps! Hard luck.\nYou have been bit by a snake.\n Moving down to:"<<point;
            break;
        }
        else{
            snakehead=false;

        }
    }
    return snakehead;
}

bool checkLadderFoot(int **lf,int& point, int l)// checks for ladder foot
{
    int j=1;
    bool laderfoot=false;

    for(int i=0;i<l;i++)
    {
        if(lf[i][j]==point)
        {
            laderfoot=true;
            point=lf[i][0];
            cout<<"\nYou got lucky.\nYou landed on the foot of a ladder.\n Moving up to:"<<point;
            break;
        }
        else
        {
            laderfoot=false;
        }
    }

    return laderfoot;
}
//displays board
void displayBoard(int**b,int m, int n)
{
    cout<<"\nThis is game board.\n";
    for (int i = 0 ; i < m ; i++ )
    {
        for (int j=0 ; j < n ; j++ ) 
        {
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}
void rules()
{
    cout<<"\n";
    cout<<"\n\t _____________________";
    cout<<"\n\t|WELCOME TO SNAKE GAME|";
    cout<<"\n\t|_____________________|";
    cout<<"\n\n";
    cout<<"\nRules of game.";
    cout<<"\n1.To start playing you need 6 on dice.\n2.If you land on snake head, you will come down to it's tail.";
    cout<<"\n3.If you land on the foot of the ladder you will move up to the head of ladder.\n4.First person to reach end wins.";
    cout<<"\n\tENJOY  :)";

}
//checks weather the player has won
bool anomly(int x , int win_pos)
{
    bool won=false;
    if(x>=win_pos)
    {
        won=true;
    }

    return won;
}

//prints the position of snakes and ladders on the board
void printPosition(int**snake1,int**ladder1,int x, int y)
{

    cout<<"\nHere you can get the info about the position of snake and ladder placement.";
    cout<<"\n-----------------------------------------------";

    for(int i=0;i<x;i++)
    {
        cout<<"\nSnake "<<i+1<<" head is at:"<<snake1[i][0];
        cout<<"\tSnake "<<i+1<<" tail is at:"<<snake1[i][1];

    }
    for(int i=0;i<y;i++)
    {
        cout<<"\nLadder "<<i+1<<" foot is at:"<<ladder1[i][1];
        cout<<"\tLadder "<<i+1<<" head is at:"<<ladder1[i][0];

    }

}
