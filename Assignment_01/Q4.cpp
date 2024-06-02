#include<iostream>
#include<time.h>
#include<ctime>

using namespace std;

void rules();//rules for playing game

void startSnakeGame(); // controller of the game

int** snakeBoardCreation(int ,int);//creates game board

void displayBoard(int **,int m,int n);//displays board

int playdice();//plays dice

bool checkSnakeHead(int**,int&,int); //checks for snakes head

bool checkLadderFoot(int **,int&,int);// checks for ladern foot

bool anomly(int , int);

void printPosition(int**,int**,int x, int y);//prints the position of snakes and ladders on the board

int main()
{
 
    startSnakeGame();

    return 0;
}
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