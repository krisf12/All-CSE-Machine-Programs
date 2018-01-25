//
//  procb.c
//  4600Project1
//
//  Created by Kristian Forestier and John Alvarez on 3/20/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "procb.h"

//stores a single process
struct control_block{
	int pid;                // Unique process id
	int number_of_cycles;   // number of CPU cycles required to complete the process
	int memory_size;        // Size of memory footprint
};

control_block *new_control_block(int pid, int number_of_cycles, int memory_size)
{
	control_block *my = (control_block *) calloc(1, sizeof(control_block));
	my->pid = pid;
	my->number_of_cycles = number_of_cycles;
	my->memory_size = memory_size;	
	return my;
}

//returns the pid of a control_block object
int control_block_getPID(control_block *c) 
{
	if(c==NULL)
        return -1;
    
	return c->pid; 
}

//returns the number of cycles of a control_block object
int control_block_getnumber_of_cycles(control_block *c)
{
	if(c==NULL)
        return 0;
    
	return c->number_of_cycles;
}

//returns the memory footprint size of a control_block object
int control_block_getmemory_size (control_block *c) 
{ 
	if(c==NULL)
        return 0;
    
	return c->memory_size; 
}

//prints out control_block structure and returns number of cycles
int control_block_print(control_block *c) 
{
	printf("pid= %d, number of cycles= %d, memory size= %d KB\n", c->pid, c->number_of_cycles, c->memory_size);
        return c->number_of_cycles;
}

//Print out control_block structure in CF format
void control_block_printCF(control_block *c) 
{
	printf("%d, %d, %d\n", c->pid, c->number_of_cycles, c->memory_size);
}
