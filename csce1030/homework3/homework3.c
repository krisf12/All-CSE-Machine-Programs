/*Author: Kristian Forestier
//Date: 10/15/13
//Purpose: This program simulates the function of an ATM. It will loop unless the user incorrectly enters the pin or choses to quit.
*/

#include<stdio.h>

#define PIN 666

double account=100;
int ATM=1000;

int getwithdrawal(int withdraw);
double getdeposit(double deposit);
double printBalance(void);

int selection, enterpin, withdraw;
double deposit;


int main(void)
{
	
	printf("\n\t   CSCE 1030\n\t   Homework 3\n      Kristian Forestier\n\t    kf0106\n  kristianforestier@my.unt.edu");
	printf("\n\n");
	printf("\n\t===============\n\n");
	printf("This ATM has %d dollars in it\n", ATM);
	printf("Your balance is %g dollars\n\n", account);
	printf("Please enter your pin:\n");
	scanf("%d", &enterpin);

		while(enterpin == PIN)                                  					/*begin while loop for correct pin*/
  		{
			printf("\n\t===============\n\n");
			printf("\nHELLO! Please Select A Number:\n\n");
        		printf("1 Withdrawal\n2 Deposit\n3 Show Account Balance\n4 Exit\n\n", selection);
        		scanf("%d", &selection);
			printf("\n");
     
        		while(selection <1 || selection >4)                                                      /*while loop for when selection is incorrect*/
        			{
   				printf("ERROR, Try Again:\n\n");                                                 /*prints error and reprints menu*/
   				printf("1 Withdrawal\n2 Deposit\n3 Show Account Balance\n4 Exit\n\n", selection);
   				scanf("%d", &selection);
				printf("\n");
        			}

  				switch(selection)                                                                 /*switch statement for when selection is correct*/
				{	    
 				case 1:                                                                /*1*/
      	 				{
      	 				printf("Enter the ammount you would like to withdraw:\n");
     	 				scanf("%d", &withdraw);
					getwithdrawal(withdraw);
					}
					break;
      	 			case 2:                                                                /*2*/
      	 				{
      	 				printf("Enter the ammount you would like to deposit:\n");
      	 				scanf("%lf", &deposit);
					getdeposit(deposit);
					}
					break;                                                        
      	 			case 3:                                                                /*3*/
      	 				printBalance();
					break;
      	 			case 4:                                                                /*4*/
      	 				printf("Goodbye!\n\n");
	        			return 0;
				}
			}
  		
                                                         	                                       /*end while loop for correct pin*/
	if(enterpin != PIN)   
	{                                                                                              /*while loop for incorrect pin*/
  		printf("\nINCORRECT PIN\n\n");
		return 0;
	}
}                                                                       /*end main*/

double getdeposit(double deposit)
{
	account=(account+deposit);                                      /*equation for deposits*/ /*does not add to total ATM ammount*/
	printf("\nYour account balance is currently: %lf\n", account);
}

int getwithdrawal(int withdraw)
{
	if(withdraw <= account && withdraw <= ATM && withdraw%20==0)
	{
	ATM=(ATM-withdraw);                                             /*subtracts from ATM ammount*/  
                                                                
	account = (account-withdraw);                                   /*equation for withdrawals*/
	printf("\nYour account balance is currently: %lf\n", account);  /*prints updated account balance*/
	}
	else
		printf("\n    ****ERROR TRY AGAIN****\n");             /*error if they do not meet the requirements, which sends the user back to the menu*/
} 

double printBalance(void)
{
	printf("Your account balance is currently: %lf\n", account);   /*prints the updated user balance*/
}                                                                                    
