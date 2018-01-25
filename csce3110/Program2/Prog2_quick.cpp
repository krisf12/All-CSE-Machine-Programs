/***************
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 2
Due Date: 08/29/15
****************/

#include<cstdlib>
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct Data{

	string a;
	double b;
	int c;
	double d;

};

int med3(Data thestuff[], int, int);
void storing(Data thestuff[]);
void quicksort(Data thestuff[], int, int);
void swap(Data thestuff[], int, int);
int partition(Data thestuff[], int, int);

int main()
{
	Data thestuff[74000];
	int i;
	clock_t begin, end;
	double time;
	
	for(i=0; i<74000; i++)
	{
		getline(cin, thestuff[i].a, '|');
		cin>>thestuff[i].b; 
		getchar();
		cin>>thestuff[i].c; 
		getchar();
		cin>>thestuff[i].d;
	}
	
	begin = clock();
	quicksort(thestuff,0,73999);
	end = clock();

	time = (double)(end-begin)/CLOCKS_PER_SEC;
	cout<<"execution time "<<time<<endl;

	storing(thestuff);	

	return 0;
}

int med3(Data thestuff[], int low, int high) 
{
	int middle = (low+high)/2, upper = low, lower = high, temp;

	if ( thestuff[low].d > thestuff[middle].d )
		swap( thestuff[middle].d, thestuff[low].d );
	if ( thestuff[low].d > thestuff[high].d )
		swap( thestuff[low].d, thestuff[high].d );
	if ( thestuff[middle].d > thestuff[high].d )
		swap( thestuff[high].d, thestuff[middle].d );

	swap(thestuff[middle].d, thestuff[low].d);

	return partition(thestuff, low, high);
}

void quicksort(Data thestuff[],int low, int high)
{
  int pivotPosition;
  
	  if (low < high)
	  {
		  pivotPosition = med3(thestuff, low, high);
		  quicksort(thestuff, low, pivotPosition-1);
		  quicksort(thestuff, pivotPosition+1, high);
	  }
}

void swap(Data thestuff[], int low, int high )
{
  double temp;

  temp = thestuff[low].d;
  thestuff[low].d = thestuff[high].d;
  thestuff[high].d = temp;

}

int partition(Data thestuff[], int low, int high )
{
  int left, right;
  double pivot;

  left = low;
  right = high;
  pivot = thestuff[low].d;

  while ( left < right )
  {
    while ( thestuff[right].d > pivot )
      right--;

    while ( (left < right) && (thestuff[left].d <= pivot) )
      left++;

    if ( left < right )
     swap(thestuff[left].d, thestuff[right].d );
  }

  thestuff[low].d = thestuff[right].d;
  thestuff[right].d = pivot;

  return right;
}

void storing(Data thestuff[])
{
	ofstream out("pop_density_sorted.txt");
	streambuf *yo = cout.rdbuf();
	cout.rdbuf (out.rdbuf());
	cout.precision(15);	

	for(int i=0; i<74000; i++)
	{
		cout<< thestuff[i].a<<'|'<<thestuff[i].b<<'|'<<thestuff[i].c<<'|'<<thestuff[i].d<<endl;
	}

	cout.rdbuf(yo);

}
