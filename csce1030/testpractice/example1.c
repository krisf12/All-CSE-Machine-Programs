/* This is an en example that contains a lot, BUT NOT ALL of the
material covered in class. DO NOT assume that all the material 
covered by the test will be found here.
Good resourced for studying are
- Lab quizzes
- Lab assignments
- Homework assignments
- Assigned reading in the book
- Information posted on Moodle
- Your class notes. 
This example, however, is a good STARTING POINT to check on your 
understanding of SOME of the material. */

#include <stdio.h>

#define MAX 10 /* declaraion of a "constant"*/

int main(void)
{

	int i = 10;
	int num, option;
	float x, y, z;
	char a, b;
	double d;

	printf("======================================\n");
	printf("OUTPUT OF THE SWITCH STATEMENT:\n");

	/* This loop prints out a statement based on the
	user input */
	printf("Please enter an integer: ");
	scanf("%d", &option);
	switch(option)
	{
		case 0: 
			printf("This is reached only by 0 \n"); 
		case 1: 
			printf("This is reached by 0 and 1 \n");
			break;
		case 2:
			printf("This is reached only by 2\n");
			break;
		case 3:
			printf("This is reached only by 3\n");
			break;
		default:
			printf("This is reached by all numbers except 0-3\n");
			break;
	} /* end switch */

	printf("======================================\n");
	printf("OUTPUT OF THE WHILE LOOP\n"); 

	num =1;
	/* This loop will prompt the user for a number until 
	the entered number is even */
	while(num % 2 != 0)
	{
		printf("Please enter an even number: ");
		scanf("%d", &num);
	}/* end while */

	printf("======================================\n");
	printf("LET'S DO SOME MATH!\n");
	
	/* This segment will read some values from the command
	line and use them to compute mathematical expression */
	printf("Enter 2 floats and 1 double: ");
	scanf("%f %f %lf", &x, &y, &d);
	
	z = (x + y) / (x - y*y);
	d = d * d - d;

	printf("The result of (x+x) / (x-y*y) is %f\n", z);
	printf("The result of (d*d-d) is %lf \n",d);
	printf("The value of i is %d \n",i);
	printf("The value of i using ++i is %d \n", ++i);
	printf("The value of i using i++ is %d \n", i++);
	printf("Now the value of i is %d\n", i);

	printf("======================================\n");
	printf("FINALLY, LET'S WORK WITH CHARACTERES\n");
	/* Remember that there are 2 ways to read in a character */
	printf("Type 1 character: ");
	getchar(); /* Let us remove that new line character from the buffer.
		   It was entered along with your last input */
	scanf("%c", &a);
	getchar(); /* Recall that the "enter key" produces a new line,
		    which also is a character. We need to "get rid" 
		    of it. */
	printf("Type 1 character: ");
	b = getchar(); /* This character we want to actually store */
	getchar(); /* We do not want to store the new line */

	printf("We can print outcharacters using printf: \"%c\"  and \"%c\" \n",a,b);
	printf("Or we can use putchar(): \"");
	putchar(a);
	printf("\" and \"");
	putchar(b);
	printf("\" \n");
	
	printf("======================================\n");

	return 0;
}   
