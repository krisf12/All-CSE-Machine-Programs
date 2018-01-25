/*
// Kristian Forestier
//
// Project 1
//
// This program reads from a file and implements dijksras algorithm for finding the shortest path between vertices and then writes that data to another file.
//
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;
#define INFINITY 9999

int main(void)
{

ifstream file3("graph"); 	//read from the file that contains the data
int size, j, i, k, q;
int count=0 , min=0 , nextn=0 , firstn=0; 	//variables for incrementing

        streambuf * cinbuf = cin.rdbuf();	//used for cin from file
        cin.rdbuf(file3.rdbuf());
        cin>>size;				//store first number of file as the size

	int data[size][size];			//create a 2d array of size "size"

        for(i = 0; i < size; i++)
        {
                for(j = 0; j < size; j++)		
                {
                        if ( !(file3 >> data[i][j]) )	//transfer data to array
                        {
                                cout <<"Error: No File"<<endl;
                                break;
                        }
                }
          if ( !file3 ) break;	//error checking
        }
	cin.rdbuf(cinbuf);	//restore cin

 	file3.close();		//close file

int weight[size][size], dist[size];	//array for weights 
int prev[size], seen[size], d[size];	//arrays for visited and previous

for(i = 0; i < size; i++)		//for loop to run N times and visit every vertex
{       
         for(j = 0; j < size; j++)	
         {       
                 if (data[i][j] == 0) 
                         weight[i][j] = INFINITY;	//set diagonal equal to infinity (which is really 999)
                 else    
                         weight[i][j] = data[i][j];	//move data over to same new 2d array
         }
}

clock_t begin, end;
float time;

begin = clock();	//used for calculating runtime in seconds

  for(firstn = 0; firstn < size; firstn++)
  {
	for(i = 0; i < size; i++)
    	{
		dist[i] = weight[firstn][i];	//save data of first column
		prev[i] = firstn;		//store as previous
		seen[i] = 0;			//mark as visited
	}

	dist[firstn] = 0;		//set distance to first node as 0
	seen[firstn] = 1;	//set visited 
	count = 1;		//set count equal to 1

	while(count < size-1)		
    	{
		min = INFINITY;		//set the minimum equal to infinity

		for(i = 0; i < size; i++)
        	{
			if(dist[i] < min && !seen[i])	//check if weight is less than the min and hasnt been visited
            		{
				min =dist[i];	//set new min value if true
				nextn = i;	
			}
		}

		seen[nextn] = 1;	//mark as visited

		for(i = 0; i < size; i++)
        	{
			if(!seen[i])			//check if visited
				if(min + weight[nextn][i] <dist[i])	//check if the addition of two positions is less than that weight
                		{
					dist[i] = min + weight[nextn][i];	//set equal to new value
					prev[i] = nextn;		//set to next
				}
		}
		count++;	//increment the counter
	}
      k = 0; q = 0;	//init k and q

	for(i = 0; i < size; i++)
    	{
		if(i != firstn)
        	{
			d[q] = dist[i];	//store data into array d
			q++;	//increment position
			j = i;	//set j equal to i position
			k++;	//increment k

			do
            		{
				j = prev[j];
				k++;
                
			}while(j != firstn);
            
			k++;
		}
	}

	j = 0;	//init j

	for(i = 0; i < size; i++)
    	{
		if(firstn == i)
			data[firstn][i] = 0;	//resets the matrix diagonal to 0
		else
        	{
			data[firstn][i] = d[j];	//sets all other positions to their respectful values
			j++;			//increment position
		}
	}
  }

end = clock();	//calculate end runtime

time = (float)(end - begin) / CLOCKS_PER_SEC;	//calculate running time in seconds
cout<<endl<<"Execution time: " << time << endl;	//output to command line

ofstream writefile2("dijkstra_shortest_path");	//create file called dijkstra_shortest_path to store new matrix
        
writefile2<<"Matrix that stores the cost of shortest path between every pair of the vertices:"<<endl;	//output to file
        for(i = 0; i < size; i++)
        {
                for(j = 0; j < size; j++)
                {
                        writefile2<<data[i][j]<<" ";	//store data with new shortest paths to the file
                }
                writefile2<<endl;
        }
        writefile2.close(); 	//close the file

ofstream writefile3;	//open a new file
writefile3.open("DijkstraData.txt",ios::app);
writefile3<<"execution time: "<<time<<" Nodes in graph: "<<size;	//store the execution times and size and append
writefile3<<endl;
writefile3.close();	//close the file

return 0;
}
