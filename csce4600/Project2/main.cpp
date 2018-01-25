#include <iostream>
#include <ctime>
#include <cstdlib>
#include "process.h"
#include<time.h>
#include <sys/time.h>
#define numPro 50 //number of processes
#define numSwap 49 //number of context switch used

float averageWT(int waitTimeFIFO[]);

int main(){
    system("clear");
	srand(time(NULL));
	int averageCycle=0;
	int averageMem=0;
	int tempArrivalTime = 0;
	int FIFO[numPro];
	int waitTimeFIFO[numPro];
	int waitTime = 0;
    timeval t1, t2, t3, t4, t5, t6, t7, t8;
    double time1, time2, time3,time4;
	//ask user how many processes they want created
	//make object
	list LIST;
    
	cout << "Process(#)\t|ID\t|Cycles\t|Memory\t|Arrival\t\n";
    
	//create k amount of processes where k is the number
	//the user selected at the beginning
	for(int i=0; i<numPro; i++){
		LIST.dataCreation(i, &tempArrivalTime);
	}
    
	LIST.randForMem();
    
	//move data into new array
	LIST.dataTransfer(FIFO);
	
	//calculate wait time and store the data into another new array
	LIST.waitTimeFinder(waitTimeFIFO, FIFO, waitTime);
	
	//print the result
	LIST.printProcesses(FIFO, waitTimeFIFO);
    
	//print the averages
	averageCycle = LIST.averageCycle(averageCycle);
	averageMem = LIST.averageMem(averageMem);
	cout << "Average Cycle: " << averageCycle << "\t\t"
	<< "Average Mem: " << averageMem/1000 << "KB\n";
    
    gettimeofday(&t1, NULL);
    LIST.allocate();
	gettimeofday(&t2, NULL);
	time1 = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    time1 += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	cout<<"Time for using malloc to allocate all process "<<time1<<endl;
 
    gettimeofday(&t3, NULL);
    LIST.allocate10(FIFO);
	gettimeofday(&t4, NULL);
	time2 = (t4.tv_sec - t3.tv_sec) * 1000.0;      // sec to ms
    time2 += (t4.tv_usec - t3.tv_usec) / 1000.0;   // us to ms
	cout<<"Time for using 10 MB block "<<time2<<endl;

    gettimeofday(&t5, NULL);
	LIST.allocate5(FIFO);
	gettimeofday(&t6, NULL);
	time3 = (t6.tv_sec - t5.tv_sec) * 1000.0;      // sec to ms
    time3 += (t6.tv_usec - t5.tv_usec) / 1000.0;   // us to ms
	cout<<"Time for using 5 MB block "<<time3<<endl;

	gettimeofday(&t7, NULL);
	LIST.allocate1(FIFO);
	gettimeofday(&t8, NULL);
	time4 = (t8.tv_sec - t7.tv_sec) * 1000.0;      // sec to ms
    time4 += (t8.tv_usec - t7.tv_usec) / 1000.0;   // us to ms
    cout<<endl;
	cout<<"Time for using 1 MB block "<<time4<<endl;
    
    cout<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Time for using malloc to allocate all process "<<time1<<endl;
	cout<<"Time for using 10 MB block "<<time2<<endl;
	cout<<"Time for using 5 MB block "<<time3<<endl;
	cout<<"Time for using 1 MB block "<<time4<<endl;
    
    return 0;
    
}
