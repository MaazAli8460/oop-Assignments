#include<iostream>

using namespace std;



struct ZooCage
{
char *name;
int cageNumber;
ZooCage* link;
};

class ZooChain {
public:
ZooCage* start;
// Default constructor
ZooChain() { start = NULL; }

void add_Cage( char *name,int cageNumber)
{
    ZooCage* temp = new ZooCage;
	temp->name = name;
	temp-> cageNumber = cageNumber;
    temp->link = NULL;

    if(start==NULL)
    {
        start = new ZooCage;
        start->name = name;
        start->cageNumber = cageNumber;
        start->link = NULL;
    }
    else
    {
        ZooCage* temp2 = start;
        while(temp2->link!=NULL)
        {
            temp2 = temp2->link;
        }


        temp2->link = temp;
    }
}
 /*This member function will take the
name and cageNumber of Animal as input parameter. It creates the ZooCage
instance. If the new Zoocage instance is the first in the chain then the pointer
“start“ will point to it.Otherwise a new instance is attached at the end of the
existing chain.*/
void print_Chain()//It prints all the animals with their cage number in the chain.
{
    
    ZooCage *temp;
    temp  = start;
    if(start==NULL)
    {
    	cout<<"\nThe Zoochain is empty";
    	return;
    }
    while(temp !=NULL)
    {
        cout<<"\nAnimal name:"<<temp->name;
        cout<<"\tCage number:"<<temp->cageNumber;

        temp = temp->link;
    }
    cout<<endl;
    
    return;
}
void delete_Chain( int cageNumber) /* This member function will take the
cageNumber of Animal as input parameter. It deletes the mentioned cageNumber from
the chain of ZooCage instances.And rejoins the remaining chain.*/
{
    ZooCage *temp = start;
    ZooCage *temp1 = start;
   
   
             if(start->cageNumber == cageNumber)
            {
            ZooCage *temp2 = start;
            start = start->link;
            delete temp2;
            }

            else
            {
                while(temp1->cageNumber!= cageNumber && temp1->link !=NULL)
                {
                    temp1 = temp1->link;
                   
                }
            }
   
    temp->link = temp1->link;
    temp1 = NULL;
    delete temp1;

}

void Sort_Chain()// It sort all the elements in the chain based upon their cageNumber.
{
    ZooCage *temp = start;
   
    while(temp!=NULL)
    {
        ZooCage *temp1 = temp->link;
        while(temp1!=NULL)
        {
            if(temp->cageNumber > temp1->cageNumber)
            {
                int x=temp->cageNumber;
                char*c=temp->name;
                temp->cageNumber = temp1->cageNumber;
                temp->name = temp1->name;
                temp1->cageNumber = x;
                temp1->name = c;

            }
            // else
            // {
            //     continue;
            // }
            temp1=temp1->link;
        }
        temp = temp->link;
        
    }

}


void update_name_at_cageNumber(int cageNumber, char * name)
{
    ZooCage *temp = start;
    while(temp!=NULL)
    {
        if(temp->cageNumber == cageNumber)
        {
            temp->name = name;
            //break;
        }
        temp = temp->link;
    }
}

void remove_Duplicate()// It removes all the duplicates in the chain.
{
    //Sort_Chain();
    ZooCage *temp = start;
    ZooCage *temp2;
    while(temp!=NULL)
    {
        ZooCage *temp1 = temp->link;
        temp2=temp;
        while(temp1!=NULL)
        {
            if(temp->cageNumber == temp1->cageNumber)
            {
               // delete_Chain( temp->cageNumber);
                temp2->link=temp1->link;
                //delete temp1;
                //temp1=temp2->link;
            }
                temp2=temp2->link;
                temp1 = temp1->link;
           
        
        }
        temp = temp->link;
    }//Sort_Chain();
}

~ZooChain()
{
   ZooCage *temp = start;
   delete start;
// while(temp!=NULL)
// {
//     ZooCage *temp1=temp;
//     delete temp1;
// }
        
}
};
