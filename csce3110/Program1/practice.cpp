/***************
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 1
Due Date: 08/29/15
****************/

#include<cstdlib>
#include<iostream>
#include<iomanip>

using namespace std;

void input();
void outputs();
int array[10][10];

void input()
{       	
         for(int i=0;i<10;i++)
         {
		for(int j=0;j<10;j++)
		{
			cin>>array[i][j];
        	}
	 }	  	
}

void outputs()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<setw(3)<<array[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
}


int main(void)
{
	input();
	outputs();
}
