#include "procb.h"
#include <stdlib.h>
#include <stdio.h>

//stores a single process
struct PCB{
	int pid; // Unique process id 
	int numCycles; // number of CPU cycles required to complete the process
	int memSize; // Size of memory footprint
};

PCB *new_PCB(int pid, int numCycles, int memSize) {
	PCB *my = (PCB *) calloc (1, sizeof(PCB));
	my->pid = pid;
	my->numCycles = numCycles;
	my->memSize = memSize;	
	return my;
}
//Returns the pid of a PCB object
int pcb_getPID(PCB *c) 
{
	if(c==NULL) return -1; 
	return c->pid; 
}

//Returns the number of cycles of a PCB object
int pcb_getNumCycles(PCB *c) 
{	
	if(c==NULL) return 0;
	return c->numCycles; 
}

//Returns the memory footprint size of a PCB object
int pcb_getMemSize (PCB *c) 
{ 
	if(c==NULL) return 0;
	return c->memSize; 
}

//Print out PCB structure
void pcb_print(PCB *c) 
{
	printf("pid=%d, number of cycles=%d, memory size(KB)=%d\n", c->pid, c->numCycles, c->memSize);
}

//Print out PCB structure in CSV format
void pcb_printCSV(PCB *c) 
{
	printf("%d, %d, %d\n", c->pid, c->numCycles, c->memSize);
}
