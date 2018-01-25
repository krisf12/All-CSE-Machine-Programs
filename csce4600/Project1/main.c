//
//  main.c
//  4600Project1
//
//  Created by Kristian Forestier and John Alvarez on 3/20/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

#include "processtbl.h"
#include <stdio.h>

int main (void) 
{
	//makes the process table
	process_list *pointer1 = new_process_list(50);
    
    //prints the data that was created
    printf("PROCESSES GENERATED\n");
	process_list_printInfo(pointer1);
    
    //prints the data that was created
	process_list_printProcessesCF(pointer1);
    
	return 0;
}