//
//  SchedulingFunctions.c
//  4600Project1
//
//  Created by Kristian Forestier and John Alvarez on 3/20/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "procb.h"
#include "processtbl.h"

void round_robin(struct schedule_node nodes[50])
{
    int i,z,n=50,remaining_process=50, time, check=0, qs=50;
    int total_wait=0,rt[50], a_time[50];
    //make the arrival times

for(z=0;z<50;z++)
{
    if(z==0)
		a_time[z]=0;
        
    else
        a_time[z]=a_time[z-1]+50;
    
    //keep track of burst times
    rt[z]=nodes[z].burst_t;
}

printf("\n");
printf("ROUND ROBIN\n");
    
for(time=0,i=0;remaining_process>0;)
{
    if(rt[i]<=qs && rt[i]>0 )
    {
        time+=rt[i];
        rt[i]=0;
        check=1;
    }
    else if(rt[i]>0)
    {
        rt[i]-=qs;
        time+=qs;
        time+=10; // for context switch
    }
	
    if(rt[i]==0 && check == 1)
    {
        remaining_process--;
        time+=10; // for context switch
        printf("pid= %d wait time= %d arrival time = %d\n",i+1,time-a_time[i]-nodes[i].burst_t,a_time[i]);
        total_wait+=time-a_time[i]-nodes[i].burst_t;
        check=0;
    }
    
    if(i==n-1)
		i=0;
    
    else if(a_time[i+1]<=time)
        i++;
    
    else
        i=0;
}
    //last unneeded context switch
    total_wait-=10;
    printf("average wait time = %f\n\n",total_wait*1.0/n);

}

void fifo(struct schedule_node nodes[50])
{
    int i,j,num_proc=50, wait_t[50]= {0}, ave_wait=0;
    
    // start at one because arival time of first process = 0
    for(i=1;i<num_proc;i++)
    {
        for(j=0;j<i;j++)
        {
            wait_t[i]+=nodes[j].burst_t;
            wait_t[i]+=10; //context switch penalty
        }
    }
    
    printf("FIRST IN FIRST OUT\n");
    
	for(i=0;i<num_proc;i++)
	{
		ave_wait+=wait_t[i];
		printf("pid= %d number of cycles= %d wait time= %d \n",i+1,nodes[i].burst_t,wait_t[i]);
	}
	
	// to calculate ave wait
    ave_wait-=10;
	printf("average wait time= %f\n\n",ave_wait*1.0/50);
}

void sjf(struct schedule_node nodes[50])
{
	int num_proc=50, processes[50]={0}, wait_t[50]={0}, total_t=0,ave_wait=0;
	int position,tmp,i,j;
	int buff_bt[50]={0};
	
	//initalize processes 1-50
	for(i=0;i<50;i++)
        processes[i]=i+1;
    
	for(i=0;i<num_proc;i++)
		buff_bt[i]=nodes[i].burst_t;
	
    for(i=0,position=0;i<num_proc;i++)
	{
		for(j=i+1;j<num_proc;j++)
			if(buff_bt[j]<buff_bt[position])
			{
				position=j;
				total_t+=10;//for context switch
			}
        
		tmp=buff_bt[i];
		buff_bt[i]=buff_bt[position];
		buff_bt[position]=tmp;
		tmp=processes[i];
		processes[i]=processes[position];
		processes[position]=tmp;
	}
	
	for(i=1;i<num_proc;i++)
	{
		for(j=0;j<i;j++)
			wait_t[i]+=buff_bt[j];
        
		total_t+=wait_t[i];
	}
    
	total_t+=490;	//context switch
	ave_wait=total_t/num_proc;
	
    printf("SHORTEST JOB FIRST\n");
    
	for(i=0;i<num_proc;i++)
		printf("pid= %d, number of cycles= %d, wait time= %d\n",processes[i],buff_bt[i],wait_t[i]);
	
        printf("average wait time= %f\n",ave_wait*1.0);
}

void fifo4core(struct schedule_node nodes[50])
{
    int i,j,num_proc=50, wait_t[50]= {0}, ave_wait=0;
    
    // start at 4 because wait time of first 4 process = 0
    for(i=4;i<14;i++)
    {
        for(j=0;j<i;j++)
        {
            wait_t[i]+=nodes[j].burst_t;
            wait_t[i]+=10; //context switch penalty
        }
        wait_t[i]/=4;
    }

    for(i=14;i<26;i++)
    {
        for(j=0;j<i;j++)
        {
            wait_t[i]+=nodes[j].burst_t;
            wait_t[i]+=10; //context switch penalty
        }
        wait_t[i]/=4;
    }

    for(i=26;i<39;i++)
    {
        for(j=0;j<i;j++)
        {
            wait_t[i]+=nodes[j].burst_t;
            wait_t[i]+=10; //context switch penalty
        }
        wait_t[i]/=4;
    }
    
    for(i=39;i<50;i++)
    {
        for(j=0;j<i;j++)
        {
            wait_t[i]+=nodes[j].burst_t;
            wait_t[i]+=10; //context switch penalty
        }
        wait_t[i]/=4;
    }
    
    printf("\nFIRST IN FIRST OUT (4 cores)\n");
    
	for(i=0;i<num_proc;i++)
	{
		ave_wait+=wait_t[i];
		printf("pid= %d number of cycles= %d wait time= %d \n",i+1,nodes[i].burst_t,wait_t[i]);
	}
	
	// to calculate ave wait
    ave_wait-=10;
	printf("average wait time= %f\n\n",ave_wait*1.0/50);
    
}
