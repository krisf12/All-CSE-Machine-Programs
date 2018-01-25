/*************** 
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 5
Due Date: 12/3/15
****************/

#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include"Header1.h"

using namespace std;

void recursion(int);

int main(void)
{
	int check = 0;

		recursion(check);

	return 0;
}


void recursion(int check)
{
	int edge1, edge2, edge3;
	Graph G(999);

	do      
	{       
	        if(edge1==1)
	        {       
	                check = false;
	        }
	        
	        cin>>edge1>>edge2>>edge3;
	        
	        if(edge3 == '\n')
	        {       
	                G.addEdge(edge1, edge2);
	        }
	        else if(edge3 != '\n')
	        {       
	                G.addEdge(edge1, edge2);
	                G.addEdge(edge1, edge3);
	        }
	        else if(check == 80)
		{
		        break;
		}
   
		G.BFS(1);
		check++;
	
	}while(check < 100);	

	while(check<110)
	{		
		recursion(check);
		if(check > 90)
			break;
	}
}
