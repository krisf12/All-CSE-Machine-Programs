//
//  procb.h
//  4600Project1
//
//  Created by Kristian Forestier and John Alvarez on 3/20/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

//Structure that stores a single process
typedef struct control_block control_block;

//typedef struct schedule_node schedule_node;

//Creates a control_block structure
control_block *new_control_block(int pid, int number_of_cycles, int memory_size);

//Returns the PID of a control_block object
int control_block_getPID(control_block *p);

//Returns the number of cycles of a control_block object
int control_block_getnumber_of_cycles(control_block *p);

//Returns the memory footprint size of a control_block object
int control_block_getmemory_size(control_block *p);

//Prints the values in a control_block object

int control_block_print(control_block *p);

//Prints the value in a control_block object in CF format
void control_block_printCF(control_block *p);