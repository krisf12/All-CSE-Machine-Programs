//Kristian Forestier
// 4/18/14
// Lab11
// 

#include<iostream>
#include<cstdlib>
using namespace std;

void printMatrix(int **, int, int);
void sumElements(int **, int, int);
void upperHalf(int **, int, int);
void middle(int **, int, int);
void column(int **, int, int);

int main(void)
{

int x, y, i, j;
int **m;
int option;   //this is for the menu to call a function

cin>>x;  //this is the rows input
cin>>y; //this is the columns input

m= new int*[x]; //allocates memory for the matrix

for(int i=0; i<x; i++)

	m[i]=new int[y]; //allocates memory for the columns

	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			cin>>m[i][j];  //inputs the numbers into the correct position of the matrix
	

cout<<endl<<endl;
cout<<"1: print the matrix"<<endl;
cout<<"2: sum all of the elements"<<endl;     //this is the menu
cout<<"3: show the upper half"<<endl;
cout<<"4: show the middle row"<<endl;
cout<<"5: show the middle column"<<endl;
cout<<endl;

cin>>option;  //asks the user for their choice

if(option==1)
printMatrix(m, x, y);
else if(option==2)
sumElements(m,x,y);
else if(option==3)    //these are the function calls
upperHalf(m,x,y);
else if(option==4)
middle(m,x,y);
else if(option==5)
column(m,x,y);

return 0;         //end of main
}


void printMatrix(int **m, int x, int y)  //this function prints the entire matrix formatted correctly
{
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
		{
			cout<<"\t"<<m[i][j];
			if(j==y-1)
			cout<<endl;
		}

}


void sumElements(int **m, int x, int y)  //this function finds the sum of all the elements
{
int sum=0; //initialize sum to zero
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			sum+=m[i][j]; //add em up
cout<<endl<<"the sum is "<<sum<<endl;  //print the sum
}


void upperHalf(int **m, int x, int y) //this function prints the upper half of the matrix
{
	if(x!=y)
	cout<<"ERROR Try Again"<<endl;  // this checks if it is a square matrix

	else 
	{
		for(int i=0; i<x; i++)
		{
			for(int j=0; j<y; j++)
			{
				if(j>=i)
				cout<<"\t"<<m[i][j]; 
				
				else cout<<"\t";

				if(j==y-1)
					cout<<endl;
			}	
		}
	}

}


void middle(int **m, int x, int y) //this function prints the middle row of the matrix
{
	int mid=x/2;

	if(x%2 != 1)  //this checks if it does not have an odd number of rows
	{
	cout<<"ERROR"<<endl;
	}
	
	else
	{	
		for(int i=0; i<x; i++)
                        for(int j=0; j<y; j++)  
                        {
                                if(i==mid)
                                cout<<"\t"<<m[i][j]; //print the middle row

                                else cout<<"\t";

                                if(j==y-1)
                                        cout<<endl;
			}

	}
}


void column(int **m, int x, int y)  //this function prints the middle column of the matrix 
{
int mid=y/2;  //finds the middle


        if(y%2 != 1)  //checks if it does not have an off number of columns
        {
        cout<<"ERROR"<<endl;
        }

        else
        {
                for(int i=0; i<x; i++)
                        for(int j=0; j<y; j++)
                        {
                                if(j==mid)
                                cout<<"\t"<<m[i][j]; //print the middle column

                                else cout<<"\t";

                                if(j==y-1)
                                        cout<<endl;
                        }

        }
}
