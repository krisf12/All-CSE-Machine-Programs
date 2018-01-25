//
//  processtbl.h
//  4600Project1
//
//  Created by Kristian Forestier and John Alvarez on 3/20/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

//structure that stores a linked list of processes and maintains statistics.
typedef struct process_list process_list;

//Creates a process table with an initial number of processes.
process_list *new_process_list(int numproc);

//adds a new process to the process table.
//returns the process id if it was successfully added or returns NULL if there was any error.
int process_list_generateNewProcess(process_list *pointer);

//stores the id and burst times for manipulation with scheduling algorithms
typedef struct schedule_node schedule_node;

//prints the process table statistics and the processes in the process table.
//prints in labeled format or CF format
//print and printCF print both the statistics and processes
void process_list_printInfo(process_list *pointer);
void process_list_print(process_list *pointer);
void process_list_printCF(process_list *pointer);
void process_list_printProcesses(process_list *pointer);
void process_list_printProcessesCF(process_list *pointer);

struct schedule_node{
    
    int id;
    int burst_t;
};

void round_robin(schedule_node *nodes);
void fifo(schedule_node *nodes);
void sjf(schedule_node *nodes);
void fifo4core(schedule_node *nodes);