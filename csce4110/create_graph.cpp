/*
// Kristian Forestier
//
// Project 1
//
// This program genarates a square adjacency matrix of random size with random weighted edges.
//
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main()
{
         ofstream file1("graph");	//create a file and call it graph
         int N, j, i;
 
                 if(file1.is_open())	//check if the file is open
                 {
                         srand(time(NULL));	//initialize time seed
                         N= rand() % 951 + 50;   //50 to 1000 vertices size stored in N  
                         int graph[N][N];	//create a 2d array of size N
 
                         cout<<"Number of vertices in graph: "<<N<<endl<<endl;	//output to command line
 
                         for(j=0;j<N;j++)		//doubly nested for loops to store data in array
                         {
                                 for(i=0;i<N;i++)
                                 {
                                         if(j==i)			//check for diagonal positions
                                                 graph[j][i] = 0;	//set equal to zero
                                         else
                                                 graph[j][i] = rand() % 51 + 1; //assign a random weight between 1 and 50 to the edges
                                 }
                         }
                         file1 << N << endl;		//output size to first line of file
                         for(j=0;j<N;j++)
                         {       
                                 for(i=0;i<N;i++)
                                 {       
                                         file1<< graph[j][i]<< " ";	//output weights followed by a space
                                 }
                                 file1<<endl;		//new line after each row
                         }
                 file1.close();		//close file
                 }
 
}
