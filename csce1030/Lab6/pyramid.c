/*Kristian Forestier
/ 10/11/13
/ This program creates a pyramid using the first letter of my last name.
*/

#include<stdio.h>
#include<math.h>

int main(void)
{

int i;
int n;    /*these are the variables*/
int k;
int z;

printf("Enter your desired number of lines:");
scanf("%d",&n);                               /*user inputs the number of lines*/

 for(i=0; i<n; i++) /*beginning of first for loop*/
 {
   for(k=0; k<(n-i); k++)   /*first inner loop*/
   {
   printf(" ");
   }
  
   for(z=0; z<(2*i-1); z++) /*second inner loop*/
   {
   printf("F");
   }
   printf("\n");
 }                /*end of loop*/ 

return 0;
}
