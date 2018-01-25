/*************** 
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 3
Due Date: 10/24/15
****************/

#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include"Header.h"

using namespace std;

heap::heap()
{
	int i;

	for(i=0; i<500; i++)
	{       
	        Minheap[i]= -1;
	}
}

int main(void)
{
	string user;
	int number;
	int i;
	heap Mheap;
	
	ofstream myfile;
	myfile.open("file.txt");


	while(cin>>user)
	{	
		if(user == "P")
		{
		        Mheap.printheap(myfile);
		}
		else if(user == "I")
		{
			Mheap.insert();
		}
		else if(user == "C")
		{
			Mheap.change();
		}		
		else if(user == "D")
		{
			Mheap.deleteitem();
		}	
	}
	myfile.close();		
	
	return 0;
}

void heap::insert()
{
	int i;
	cin>>number;

	for(i=0; i<500; i++)
	{
		if(Minheap[i] == -1)
		{
			Minheap[i]= number;
			break;
		}
	}
	sortheap();
}

void heap::sortheap()      //this function not working properly
{
	int temp;
	int i=0;
	for(i=0; i<500; i++)
	{
		if(Minheap[i]<Minheap[i/2] && Minheap[i] != -1)
			;

		else
		{
			temp= Minheap[i/2];
			Minheap[i/2]=Minheap[i];
			Minheap[i]=temp;
		}
	}
}

void heap::printheap(ofstream &myfile)
{
	int i;
	
	myfile<<"(";
	for(i=0;i<500;i++)
	{				 //printing sorted heap
		if(Minheap[i] != -1)
		{
			myfile<<Minheap[i];
			myfile<<",";	
		}
	}	
	myfile<<")";		
}

void heap::change()
{
	int i, num1, num2;

	cin>>num1>>num2;

	for(i=0;i<500;i++)
	{
		if(Minheap[i] == num1)
		{
			Minheap[i] = num2;
		}
	}
	sortheap();
}

void heap::deleteitem()
{
	int num;
	int i;
	cin>>num;
	
	for(i=0;i<500;i++)
	{
		if(Minheap[i] == num)
		Minheap[i] = -1;
	}
	
	sortheap();
}

