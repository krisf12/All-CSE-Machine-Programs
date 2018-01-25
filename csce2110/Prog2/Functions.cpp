#include<cstdlib>
#include<iostream>
#include "Hash.h"

using namespace std;


void menu()  //user menu
{
cout<<endl;
cout<<"Type one the following commands:"<<endl;
cout<<"add"<<endl; cout<<"delete"<<endl; cout<<"search"<<endl; cout<<"show"<<endl; cout<<"quit"<<endl<<endl;
cout<<"set> ";
}

void add(int num, int key, Hash *h) //add function
{
	int i, j;

	for(i=0;i<7;i++) //for loop with 7 positions for the buckets
	{
		for(j=0;j<h[i].count;j++)
		{
			if(num==h[i].data[j]) //checking if input is already in the hash table
			{
				cout<<"Warning: duplicate input: "<< num <<endl;
				return;
			}
		}
	}

	h[key].data[h[key].count] = num; //adds in the number using the key
	h[key].count++; //counts
}

void del(int num, int key, Hash *h)
{
	int i,j,k;
	
	for(k=0; k<7; k++)
	{
		for(i=0;i<h[k].count; i++)
		{
			if(num==h[k].data[i]) //checks if number is even in the hash table
			{
				for(j=0;j<h[k].count-i;j++) //moving elements to compensate
				{
					h[k].data[i] = h[k].data[i+1]; //moving elements
				}
			h[k].count--;
			return; //exits the function
			}
		}
	}
	cout<< "ERROR: Value not found"<<endl; //if the function never happened then the value isnt there
}

void search(int num, int key, Hash *h)
{
	int i, j;

	 for(i=0;i<7;i++)
	 {       
	         for(j=0;j<h[i].count;j++)
	         {       
	                 if(num==h[i].data[j]) //checks if the number is in the hash table
	                 {       
	                         cout<<"True"<<endl; //found the number
				 return;
	                 }	
	         }
	 }
 cout<<"False"<<endl; //didnt find the number
}

void show(Hash *h)
{
	int i;
		if(h[0].count==0 && h[1].count==0 && h[2].count==0 && h[3].count==0 && h[4].count==0 && h[5].count==0 && h[6].count==0)
		{
			cout<<"()-()-()-()-()-()-()"<<endl;
		}
		else
		{
			cout<<"(";
			if(h[0].count!=0) //checks if there is a number in this bucket
			{
				for(i=0; i<h[0].count; i++)
				{
					if(i>0)
						cout<<",";
						cout<<h[0].data[i]; //prints the bucket
				}
				cout<<")-("; //formatting
                        }
			if(h[1].count!=0) //checks this bucket
			{
				for(i=0; i<h[1].count; i++)
				{
					if(i>0)
						cout<<",";
						cout<<h[1].data[i];
				}
				cout<<")-(";
			}
                        if(h[2].count!=0) //checks this bucket
                        {
                                for(i=0; i<h[2].count; i++)
                                {
                                        if(i>0)
                                                cout<<",";
                                                cout<<h[2].data[i];
                                }
				cout<<")-(";
                        }
                         if(h[3].count!=0)
                        {
                                for(i=0; i<h[3].count; i++)
                                {
                                        if(i>0)
                                                cout<<",";
                                                cout<<h[3].data[i];
                                }
				cout<<")-(";
                        }
                        if(h[4].count!=0)
                        {
                                for(i=0; i<h[4].count; i++)
                                {
                                        if(i>0)       
                                                cout<<",";
                                                cout<<h[4].data[i];
                                }
				cout<<")-(";
                        }
                        if(h[5].count!=0)
                        {
                                for(i=0; i<h[5].count; i++)
                                {
                                        if(i>0)
                                                cout<<",";
                                                cout<<h[5].data[i];
                                }       
                                cout<<")-(";
                        }       
                        if(h[6].count!=0)
                        {
                                for(i=0; i<h[6].count; i++)
                                {
                                        if(i>0)
                                                cout<<",";
                                                cout<<h[6].data[i];
                                }       
                                cout<<")";
                        }       
	}
}

