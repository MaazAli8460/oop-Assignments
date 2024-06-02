/*
 * ZooChain.cpp
 *
 *  Created on: Mar 21, 2023
 *      Author: maaz
 */

#include "ZooChain.h"
#include <cstddef>
#include<iostream>
using namespace std;



ZooChain::ZooChain()
{ start = NULL; };

void ZooChain::add_Cage( char *name,int cageNumber)
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

void ZooChain::print_Chain()//It prints all the animals with their cage number in the chain.
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



void ZooChain::delete_Chain( int cageNumber) /* This member function will take the
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




void ZooChain::Sort_Chain()// It sort all the elements in the chain based upon their cageNumber.
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

            temp1=temp1->link;
        }
        temp = temp->link;

    }

}




void ZooChain::update_name_at_cageNumber(int cageNumber, char * name)
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

void ZooChain::remove_Duplicate()// It removes all the duplicates in the chain.
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


ZooChain::~ZooChain()
{
   ZooCage *temp = start;
   delete start;
   //error if uncommented last lines. gives error: free(): double free detected in tcache 2 Aborted (core dumped)

 //while(temp!=NULL)
 //{
  //   ZooCage *temp1=temp;
 //    delete temp1;
 //    temp=temp->link;
 //}

};
