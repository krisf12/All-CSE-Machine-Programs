/*
 * Structure that stores a linked list of processes and maintains 
 * statistics.
 */
typedef struct ProcessTable ProcessTable;

/*
 * Creates a process table with an initial number of processes.
 */
ProcessTable *new_ProcessTable(int numP);

/*
 * Adds a new process to the process table.
 * Returns the process id if it was successfully added, returns NULL if 
 * there was any error.
 */
int processTable_generateNewProcess(ProcessTable *pt);

/*
 * Print the process table statistics and the processes in the process table.
 * Print in labeled format or CSV format
 * print and printCSV print both the PT statistics and processes
 */
void processTable_print(ProcessTable *pt);
void processTable_printCSV(ProcessTable *pt);
void processTable_printStatistics(ProcessTable *pt);
void processTable_printStatisticsCSV(ProcessTable *pt);
void processTable_printProcesses(ProcessTable *pt);
void processTable_printProcessesCSV(ProcessTable *pt);

