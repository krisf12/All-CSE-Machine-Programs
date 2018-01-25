/*
//Kristian Forestier
//10/30/13
//Purpose: this is the main function which calls all of the functions
*/

#include"homework4.h" /*this includes the header file*/

int main(void)
{
	int a=0;
	double b=0;
		
	printf("\nCSCE1030\nHomework4\nKristian Forestier\nkf0106\nkristianforestier@my.unt.edu\n");
	readfile(count, length);   /*calls the original array function*/
	printf("\n");	

	percentage(count, percent); /*calls the function that calculates the array*/

	frequency(count); /*calles the function that calculates the frequency of each letter*/

}
