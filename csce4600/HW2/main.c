#include "processtbl.h"

int main (void) 
{
	//make process table
	ProcessTable *pt1 = new_ProcessTable(50);

	processTable_printStatistics(pt1);
	processTable_printProcessesCSV(pt1);

	return 0;
}

