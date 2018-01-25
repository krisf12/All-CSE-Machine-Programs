/***********************
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 2
Due Date: 09/19/15
************************/

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

void mergesort(Data thestuff[], Data tempR[], Data tempL[], int, int);
void merge(Data thestuff[], Data tempR[], Data tempL[], int, int, int);
void print(Data thestuff[]);
void storing(Data thestuff[]);

int main()
{
	Data thestuff[74000];
	Data tempL[74000];
	Data tempR[74000];	
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
	mergesort(thestuff, tempR, tempL , 0, 73999);
	end = clock();
	
	time = (double)(end-begin)/CLOCKS_PER_SEC;
	cout<<"execution time "<<time<<endl;
//	print(thestuff);
	storing(thestuff);	

	return 0;
}

void mergesort(Data thestuff[], Data tempR[], Data tempL[], int low, int high)
{	
	if(low<high)
	{
	        int  mid = (low+high)/2;
	        mergesort(thestuff, tempR, tempL, low, mid);
	        mergesort(thestuff,tempR, tempL,  mid+1, high);
	        merge(thestuff, tempR, tempL, low, mid, high);
	}
}

void merge(Data thestuff[], Data tempR[], Data tempL[], int low, int mid, int high)
{

        int i, j, k;
        int n1 = mid - low + 1;
        int n2 = high - mid;

	for(i = 0; i < n1; i++)
		tempL[i] = thestuff[low + i];

	for(j = 0; j < n2; j++)
		tempR[j] = thestuff[mid + 1 + j];

	i=0; j=0; k=low;

	while (i < n1 && j < n2)
	{
		if (tempL[i].d <= tempR[j].d)
		{
			thestuff[k] = tempL[i];
			i++;
		}
		else
		{
			thestuff[k] = tempR[j];
			j++;
		}
	k++;
	}

	while (i < n1)
	{
		thestuff[k] = tempL[i];
		i++;
		k++;
	}

	while (j < n2)
	{
        	thestuff[k] = tempR[j];
        	j++;
        	k++;
    	}	
}

void print(Data thestuff[])
{
	for(int i=0; i<74000; i++)
	{
		cout<< thestuff[i].a<<'|'<<thestuff[i].b<<'|'<<thestuff[i].c<<'|'<<thestuff[i].d<<endl;
	}
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
