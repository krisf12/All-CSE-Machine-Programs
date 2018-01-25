#ifndef PROCESS
#define PROCESS
#include<iostream>
using namespace std;

class node{
public:
	node *next;
	int processID;
	int numCycles;
	int memSize;
	int arrivalTime;
	node(){
		processID = 0;
		numCycles = 0;
		memSize = 0;
	}
};

class list{
	node *head;
	node *current;
public:
	void dataCreation(int i, int *tempArrivalTime);
	void printProcesses(int FIFO[], int waitTimeFIFO[]);
	void waitTimeFinder(int waitTimeFIFO[], int FIFO[], int waitTime);
	int averageCycle(int averageCycle);
	int averageMem(int averageMem);
	void randForMem();
    void dataTransfer(int FIFO[]);
    int memorydata[50];
    int cyclesdata[50];
    
    void allocate();
	void allocate10(int FIFO[]);
	void allocate5(int FIFO[]);
	void allocate1(int FIFO[]);
    
    void my_malloc(char*a, char*b);
	void my_free(char *a);
    
	list(){
		current = NULL;
		head = NULL;
	}
	//become friends with class node to access their data
	friend class node;
};

#endif
