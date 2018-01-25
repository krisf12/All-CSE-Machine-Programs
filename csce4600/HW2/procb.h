#ifndef PCB_H
#define PCB_H

//Structure that stores a single process
typedef struct PCB PCB;

//Creates a PCB structure
PCB *new_PCB(int pid, int numCycles, int memSize);

//Returns the PID of a PCB object
int pcb_getPID(PCB *p);

//Returns the number of cycles of a PCB object
int pcb_getNumCycles(PCB *p);

//Returns the memory footprint size of a PCB object
int pcb_getMemSize(PCB *p);


//Prints the values in a PCB object

void pcb_print(PCB *p);


//Prints the value in a PCB object in CSV format
void pcb_printCSV(PCB *p);

#endif
