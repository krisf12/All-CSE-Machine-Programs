#include "procb.h"
#include "processtbl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node that stores a process and the next process 
typedef struct ProcessNode ProcessNode;

struct ProcessNode{

	PCB *process;
	ProcessNode *next;
};

//Table that stores a linked list of process nodes and statistics
struct ProcessTable{
	int numP; //nodes in the linked list
	int totalCycles; //compute avg cycles
	int totalMemory; //compute avg memory
	ProcessNode *head; //LOWEST pid
	ProcessNode *tail; //HIGHEST pid
};

//Generate a number between 1,000 and 11,000
int generateNumCycles() 
{	
	return(rand() % (11000 - 1000)) + 1000;
}

int generateMemSize() 
{
	int upper;
	int lower;
	int mean;
	
	upper = 100*1000;
	lower = 1*1000;
	mean = 20*1000;
	
	//number under the mean
	if((rand() % (upper - lower)) > (mean - lower)) 
		return(rand() % (mean - lower)) + lower;
	//number over the mean
	else 
		return(rand() % (upper - mean)) + mean;
}

//Generates process and add to the table
int processTable_generateNewProcess(ProcessTable *t) 
{
	if(t==NULL) 

		return -1;
	
	// Create a new node
	ProcessNode *newNode = (ProcessNode *) calloc (1, sizeof(ProcessNode));
	if(!newNode) 
		return -1;
		
	if(t->head == NULL && t->tail == NULL) 
	{
		// Create new process
		PCB *newPCB = new_PCB(1, generateNumCycles(), generateMemSize());
		if(!newPCB) return -1;
		
		// Set the values in the process node
		newNode->process = newPCB;
		//newNode->prev = NULL;
		newNode->next = NULL;
				
		//Add the new node to the process table
		t->head = newNode;
		t->tail = newNode;
		t->totalCycles += pcb_getNumCycles(newPCB);
		t->totalMemory += pcb_getMemSize(newPCB);
		
		//Return new process id
		return pcb_getPID(newPCB);
	}

	//something in the process table
	else if(t->tail) 
	{
		// Create new process		
		PCB *newPCB = new_PCB(pcb_getPID(t->tail->process)+1, generateNumCycles(), generateMemSize());
		if (!newPCB) return -1;
	
		// Set the values in the process node
		newNode->process = newPCB;
		//newNode->prev = pt->tail;
		newNode->next = NULL;
		
		// Add the new node to the process table
		t->tail->next = newNode;
		t->tail = newNode;
		t->totalCycles += pcb_getNumCycles(newPCB);
		t->totalMemory += pcb_getMemSize(newPCB);
		
		// Return the new process
		return pcb_getPID(newPCB);
	}
	else 
	{
		// ERROR, this means there is a head and NO tail
		return -1;
	}
	
	return -1;
}

ProcessTable *new_ProcessTable(int numP) 
{
	ProcessTable *my = (ProcessTable *) calloc (1, sizeof(ProcessTable));

	srand(time(NULL));
	
	int i;
	for(i=0; i<numP; i++) 
	{
		if(processTable_generateNewProcess(my)) 
			my->numP++;
		
           	else 
			printf("Error for process %d\n", i);
	}
	
	return my;
}

// Print process table number of processes, average cycles, and average memory
void processTable_printStatistics(ProcessTable *t) 
{
	if(t==NULL) return;
	printf("number of processes= %d, average Memory= %d\n, averageCycles=%d", t->numP, t->totalMemory/t->numP, t->totalCycles/t->numP);
}

// Print process table processes
void processTable_printProcesses(ProcessTable *t) 
{
	if(t==NULL) return;
	ProcessNode *p;
	
	for(p=t->head; p != NULL; p=p->next) 
		pcb_print(p->process);
	
}

//Print process table statistics and processes
void processTable_print(ProcessTable *t) 
{
	if(t==NULL) 
		return;		
	processTable_printStatistics(t);
	processTable_printProcesses(t);
}

void processTable_printStatisticsCSV(ProcessTable *t) 
{
	if(t==NULL) 
		return;
	printf("%d, %d, %d\n", t->numP, t->totalCycles/t->numP, t->totalMemory/t->numP);
}

void processTable_printProcessesCSV(ProcessTable *t) 
{
	if(t==NULL) 
		return;	
	ProcessNode *p;
	
	for(p=t->head; p != NULL; p=p->next) 
		pcb_printCSV(p->process);
	
}

void processTable_printCSV (ProcessTable *t) 
{
	if(t==NULL) 
		return;
	processTable_printStatisticsCSV(t);
	processTable_printProcessesCSV(t);
}
