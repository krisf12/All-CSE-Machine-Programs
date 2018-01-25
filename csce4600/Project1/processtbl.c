//
//  processtbl.c
//  4600Project1
//
//  Created by Kristian Forestier and John Alvarez on 3/20/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procb.h"
#include "processtbl.h"

//Node that stores a process and the next process 
typedef struct ProcessNode ProcessNode;

struct ProcessNode{

	control_block *process;
	ProcessNode *next;
};

//Table that stores a linked list of process nodes and statistics
struct process_list{
	int numproc; //nodes in the linked list
	int totalCycles; //compute avg cycles
	int totalMemory; //compute avg memory
	ProcessNode *head; //LOWEST pid
	ProcessNode *tail; //HIGHEST pid
};

//Generate a number between 1,000 and 11,000
int getnumber_of_cycles() 
{	
	return(rand() % (11000 - 1000)) + 1000;
}

int getmemory_size()
{
	int high;
	int low;
	int mean;
	
	high = 100*1000;
	low = 1*1000;
	mean = 20*1000;
	
	//number under the mean
	if((rand() % (high - low)) > (mean - low)) 
		return(rand() % (mean - low)) + low;
	//number over the mean
	else 
		return(rand() % (high - mean)) + mean;
}

//Generates process and add to the table
int process_list_getNewProcess(process_list *t) 
{
	if(t==NULL) 
		return -1;
	
	// Create a new node
	ProcessNode *newNode = (ProcessNode *) calloc(1, sizeof(ProcessNode));
	if(!newNode) 
		return -1;
		
	if(t->head == NULL && t->tail == NULL) 
	{
		// Create new process
		control_block *newcontrol_block = new_control_block(1, getnumber_of_cycles(), getmemory_size());
		if(!newcontrol_block) return -1;
		
		// Set the values in the process node
		newNode->process = newcontrol_block;
		newNode->next = NULL;
				
		//Add the new node to the process table
		t->head = newNode;
		t->tail = newNode;
		t->totalCycles += control_block_getnumber_of_cycles(newcontrol_block);
		t->totalMemory += control_block_getmemory_size(newcontrol_block);
		
		//Return new process id
		return control_block_getPID(newcontrol_block);
	}

	//there is something in the process table
	else if(t->tail) 
	{
		// Create new process		
		control_block *newcontrol_block = new_control_block(control_block_getPID(t->tail->process)+1, getnumber_of_cycles(), getmemory_size());
		if (!newcontrol_block) return -1;
	
		// Set the values in the process node
		newNode->process = newcontrol_block;
		newNode->next = NULL;
		
		// Add the new node to the process table
		t->tail->next = newNode;
		t->tail = newNode;
		t->totalCycles += control_block_getnumber_of_cycles(newcontrol_block);
		t->totalMemory += control_block_getmemory_size(newcontrol_block);
		
		// Return the new process
		return control_block_getPID(newcontrol_block);
	}
	else 
	{
		// ERROR, this means there is a head and NO tail
		return -1;
	}
	
	return -1;
}

process_list *new_process_list(int numP) 
{
	process_list *my = (process_list *) calloc (1, sizeof(process_list));

	srand(time(NULL));
	
	int i;
	for(i=0; i<numP; i++)
	{
		if(process_list_getNewProcess(my))
			my->numproc++;
	}
	
	return my;
}

// Print process table number of processes, average cycles, and average memory
void process_list_printInfo(process_list *t)
{
	if(t==NULL) return;
	printf("number of processes= %d, average Memory= %d, averageCycles=%d\n", t->numproc, t->totalMemory/t->numproc, t->totalCycles/t->numproc);
}

// Print process table processes
void process_list_printProcesses(process_list *t) 
{
	if(t==NULL) return;
	ProcessNode *p;
	
	for(p=t->head; p != NULL; p=p->next) 
		control_block_print(p->process);
	
}

//Print process table statistics and processes
void process_list_print(process_list *t) 
{
	if(t==NULL) 
		return;		
	process_list_printInfo(t);
	process_list_printProcesses(t);
}

void process_list_printProcessesCF(process_list *t) 
{
	int i=1;
	int j=0;
	struct schedule_node nodes[50];
	
	if(t==NULL) 
		return;	
	ProcessNode *p;
	
	for(p=t->head; p != NULL; p=p->next) 
	{
        nodes[j].id=i;
        nodes[j].burst_t = control_block_print(p->process);
        i++;
        j++;
    }
    
    round_robin(nodes);
    fifo(nodes);
    sjf(nodes);
    fifo4core(nodes);
}

void process_list_printCF(process_list *t)
{
	if(t==NULL) 
		return;
	process_list_printProcessesCF(t);
}