#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include "process.h"
#define minMem 1000
#define maxMem 500000
#define avgMem 150000
#define minCyc 100
#define maxCyc 1000
#define numPro 50 //number of processes
#define numSwap 49 //number of context switch used

using namespace std;

void list::waitTimeFinder(int waitTimeFIFO[], int FIFO[], int waitTime){
	class node *ptr;
	ptr = head;
	int i=0;
	//int temp;
	for( ; ptr != NULL; ptr = ptr->next)
    {
		waitTime = FIFO[i] + waitTime;
 		waitTimeFIFO[i] = waitTime - ptr->arrivalTime - FIFO[i];
		i++;
	}
}

/**
 *Move all the data into array for easier calculation
 */
void list::dataTransfer(int FIFO[]){
	class node *ptr;
	ptr = head;
	int i = 0;
	for( ; ptr!= NULL; ptr = ptr->next){
		FIFO[i] = ptr->numCycles;
        //	cout << FIFO[i] << endl;
		i++;
	}
}

/**
 *function to find the average value of memory
 *Return value: the average
 */
int list::averageMem(int averageMem){
    class node *ptr;
    int avgResult;
    ptr = new(class node);
    ptr = head;
    for( ; ptr!=NULL; ptr=ptr->next){
        averageMem += ptr->memSize;
    }
	cout<<"The Total memory is "<<averageMem/1000<<endl;
    return avgResult = averageMem/numPro;
}

/**
 *function to find the average value of cycles
 *return value: the average
 */
int list::averageCycle(int averageCycle){
    class node *ptr;
    int avgResult;
    ptr = new(class node);
    ptr = head;
    for( ; ptr!=NULL; ptr=ptr->next){
        averageCycle += ptr->numCycles;
    }
    return avgResult = averageCycle/numPro;
}

/**
 *function to find random values for memory
 *the number must be between 1 and 100 with a mean 20
 *Since the difference between 1 and 20 is a lot smaller
 *than the difference between 21 to 100, it needs some work
 *When rand() returns a bigger number than 21, it should
 *save a number between 1 and 20. If rand() returns a smaller
 *number than 20, it should save a number greater than 21
 */
void list::randForMem(){
    class node *ptr;
    ptr = head;
    for( ; ptr!=NULL; ptr=ptr->next){
        //if random number between 1 and 100 is smaller than the mean
        //save the value generated between 21 and 100
        if((rand()%(maxMem - minMem + 1) + minMem) <= (avgMem-1))
            ptr->memSize = rand()%(maxMem - avgMem + 1)+(avgMem + 1);
        //otherwise save the number less than 20
        //This else statement will be more executed than if statement
        //so the average will become lower and become around 20
        else
            ptr->memSize = rand()%(avgMem - minMem + 1) + minMem;
    }
}

/**
 *function to create random data for processID and number of cycles
 */
void list::dataCreation(int i, int *tempArrivalTime){
	//first data!
	if(current == NULL){
		//process ID is simply the increment
		current = new(class node);
		current->processID = ++i;
		//number of cycles is randomly generated between 1000 and 11000
		current->numCycles = rand()%(maxCyc - minCyc + 1) + minCyc;
		current->arrivalTime = (*tempArrivalTime);
        
		//for non preemptive FIFO, the first process to run must be
		//the process that arrives at t=0.
        //		FIFO[0] = current->numCycles;
		head = current;
		return;
	}
    
	*tempArrivalTime = (*tempArrivalTime) + 50;
	class node *ptr;
	ptr = new(class node);
	//second data doesnt exist;
	if(current->next == NULL){
		current->next = ptr;
		ptr->processID = ++i;
		ptr->numCycles = rand()%(maxCyc - minCyc + 1) + minCyc;
		ptr->arrivalTime = (*tempArrivalTime);
		ptr->next = NULL;
	}
	//more than 2 data exist, then loop through till the last node
	else{
		while(current->next != NULL)
			current = current->next;
		current->next = ptr;
		ptr->processID = ++i;
		ptr->numCycles = rand()%(maxCyc - minCyc + 1) + minCyc;
		ptr->arrivalTime = (*tempArrivalTime);
		ptr->next = NULL;
	}
}

/**
 *function to print the result
 */
void list::printProcesses(int FIFO[], int waitTimeFIFO[]){
	class node *ptr;
	//in case, error check
	if(current == NULL){
		cout << "*** Empty Table ***\n";
		return;
	}
	//loop through the node printing each data they have
	ptr = head;
	int i=0, x = 0;
	for( ; ptr != NULL; ptr = ptr->next, ++x){
        cyclesdata[x]=ptr->numCycles;
        memorydata[x]=ptr->memSize;
		cout << "Process(" << x << ")\t|"
		<< ptr->processID << "\t|"
		<< ptr->numCycles << "\t|"
		<< ptr->memSize/1000 << "KB\t|"
		<< ptr->arrivalTime << "\t\n";
		i++;
	}
}

void list::allocate()
{
    char **a = (char**)malloc(50*sizeof(char*));
    cout<<endl<<endl;
    cout<<"Using malloc and free: "<<endl;
    for(int i= 0; i<50; i++ )
    {
        a[i]=(char *)malloc(memorydata[i]*sizeof(char));
		cout<<"Allocate process: "<<i+1<<endl;
    }
    for(int i=0; i<50;i++)
	{
		char *finishptr = a[i];
		free(finishptr);
	}		
	cout<<"Free all memory "<<endl;
}

void list::allocate10(int FIFO[])
{	
	cout<<"-------------------------------------"<<endl;
	char **a;
	int sizeleft=10000000;
    int i=0, q=0;
    int mems[50];
    int check[50];
    int freed[50];
    
    a = (char **)malloc(10000000*sizeof(char));
    
    for(int i=0; i<50; i++)
    {
        check[i]= -1;
        freed[i]= -2;
    }
    
    while(i<50)
    {
        int j;
        j=memorydata[i];
        mems[i]=memorydata[i];
        char b[j];
        
        if(mems[i]<=sizeleft && check[i]== -1 && freed[i] != 2)
        {
            my_malloc(a[i],b);
            sizeleft=sizeleft-mems[i];
            cout<<"process: "<< i<<" allocated "<<mems[i]/1000<<"KB"<<endl;
            cout<<"size left: "<<sizeleft/1000<<"KB"<<endl;
            check[i] = 0;
        }
        
        if(FIFO[q]<=0 && check[i]==0)
        {
            my_free(a[q]);
            check[i]=-1;
            freed[i]=2;
            sizeleft=sizeleft+mems[q];
            cout<<"Process: "<< q<<" is done"<<endl;
            cout<<"add: "<<mems[q]/1000<<"KB"<<endl;
            
            q++;
        }
        else
        {
            if(FIFO[q]<=0)
            {
                ;
            }
            else
                FIFO[q]= FIFO[q]-50;
        }
        
        if(mems[i]>sizeleft && FIFO[q]>0)
        {
            cout<<"Not enough mem for process, will wait for process to free"<<endl;
            i=0;
        }
        
        i++;
    }
    for(q=0;q<50;q++)
        my_free(a[q]);
    cout<<endl<<"All Processes Completed"<<endl;

}	
void list::allocate5(int FIFO[])
{
	cout<<"-------------------------------------"<<endl;
	char **a;
	int sizeleft=5000000;
    int i=0, q=0;
    int mems[50];
    int check[50];
    int freed[50];
    
    a = (char **)malloc(5000000*sizeof(char));
    
    for(int i=0; i<50; i++)
    {
        check[i]= -1;
        freed[i]= -2;
    }
    
    while(i<50)
    {
        int j;
        j=memorydata[i];
        mems[i]=memorydata[i];
        char b[j];
        
        if(mems[i]<=sizeleft && check[i]== -1 && freed[i] != 2)
        {
            my_malloc(a[i],b);
            sizeleft=sizeleft-mems[i];
            cout<<"process: "<< i<<" allocated "<<mems[i]/1000<<"KB"<<endl;
            cout<<"size left: "<<sizeleft/1000<<"KB"<<endl;
            check[i] = 0;
        }
        
        if(FIFO[q]<=0 && check[i]==0)
        {
            my_free(a[q]);
            check[i]=-1;
            freed[i]=2;
            sizeleft=sizeleft+mems[q];
            cout<<"Process: "<< q<<" is done"<<endl;
            cout<<"add: "<<mems[q]/1000<<"KB"<<endl;
     
            q++;
        }
        else
        {
            if(FIFO[q]<=0)
            {
                ;
            }
            else
                FIFO[q]= FIFO[q]-50;
        }
        
        if(mems[i]>sizeleft && FIFO[q]>0)
        {
            cout<<"Not enough mem for process, will wait for process to free"<<endl;
            i=0;
        }
        
        i++;
    }
    for(q=0;q<50;q++)
        my_free(a[q]);
    cout<<endl<<"All Processes Completed"<<endl;
}

void list::allocate1(int FIFO[]) // FIFO only needed for this one because the other processes dont need to free memory
{                                // Make sure to run this multiple times as sometimes it also does not need to free memory
	cout<<"-------------------------------------"<<endl;
	char **a;
	int sizeleft=1000000;
    int i=0, q=0;
    int mems[50];
    int check[50];
    int freed[50];
    
    a = (char **)malloc(1000000*sizeof(char));

    for(int i=0; i<50; i++)
    {
        check[i]= -1;
        freed[i]= -2;
    }
    
while(i<50)
{
    int j;
    j=memorydata[i];
    mems[i]=memorydata[i];
    char b[j];
    
    if(mems[i]<=sizeleft && check[i]== -1 && freed[i] != 2)
    {
        my_malloc(a[i],b);
        sizeleft=sizeleft-mems[i];
        cout<<"process: "<< i<<" allocated "<<mems[i]/1000<<"KB"<<endl;
        cout<<"size left: "<<sizeleft/1000<<"KB"<<endl;
        check[i] = 0;
    }
    
    if(FIFO[q]<=0 && check[i]==0)
    {
        my_free(a[q]);
        check[i]=-1;
        freed[i]=2;
        sizeleft=sizeleft+mems[q];
        cout<<"Process: "<< q<<" is done"<<endl;
        cout<<"add: "<<mems[q]/1000<<"KB"<<endl;

        q++;
    }
    else
    {
        if(FIFO[q]<=0)
        {
            ;
        }
        else
        FIFO[q]= FIFO[q]-50;
    }
    
    if(mems[i]>sizeleft && FIFO[q]>0)
    {
        cout<<"Not enough mem for process, will wait for process to free"<<endl;
        i=0;
    }
    
    i++;
}
    for(q=0;q<50;q++)
        my_free(a[q]);
    cout<<endl<<"All Processes Completed"<<endl;
}

void list::my_malloc(char *a, char*b )
{
	memmove(&a,&b, sizeof(b));
}
void list::my_free(char *a)
{
	a = NULL;
}