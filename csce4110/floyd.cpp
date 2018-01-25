/*
// Kristian Forestier
//
// Project 1
//
// This program reads from a file and implements floyds algorithm for finding the shortest path between vertices and then writes that data to another file
//
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(void)
{

ifstream file("graph");	//read from the file that was created titled graph		//if test file being used is different change file name to graph
int N, j, k, i;

	streambuf * cinbuf = cin.rdbuf();	//used for changing cin to read from the file
	cin.rdbuf(file.rdbuf());
	cin>>N;				//store first number in file as size

int D[N][N];	//create 2d array of size N

	for(j = 0; j < N; j++)			//doubly nested for loops to read from file
	{
		for(i = 0; i < N; i++)
		{
         		if ( !(file >> D[j][i]) ) //check for errors
         		{
             			cout <<"Error: No File"<<endl;
             			break;
         		}
   		}
 	  if ( !file ) break;	//error check
	} 
file.close();  //close file

clock_t begin, end;
float time;

begin = clock();			//used for calculating runtime in seconds
	for (k = 0; k < N; k++) 
	{
		for (i = 0; i < N; i++) 	//triply nested for loop for checking vertex weights and comparing them
		{
			for (j = 0; j < N; j++) 
			{	
				if (D[i][k] + D[k][j] < D[i][j])	//check if the addition of position ik and jk is less than ij
				{
        	    			D[i][j] = D[i][k] + D[k][j];	//if its true then set that position equal to the addition of the other two
				} 
			} 
		} 
	}
end = clock();	//calculate endtime

	ofstream writefile("floyd_shortest_path");	//create a file called floyd_shortest_path
	writefile<<"Matrix that stores the cost of shortest path between every pair of the vertices:"<<endl;	//output to file
	for (i = 0; i < N; i++) 
	{
	      	for (j = 0; j < N; j++) 		
		{		
			writefile<<D[i][j]<<" ";	//output new matrix to file with shortest paths
		}
		writefile<<endl;
	}
	writefile.close();	//close file

	time = (float)(end-begin)/CLOCKS_PER_SEC;	//calculate runtime in seconds
	cout<<endl<<"execution time: "<<time<<endl;	//output to command line

	ofstream writefile2;
	writefile2.open("FloydData.txt",ios::app);
	writefile2<<"execution time: "<<time<<" Nodes in graph: "<<N;	//output to a new file named Floyd data and append
	writefile2<<endl;
	writefile2.close();	//close file

	return 0;
}
