#include <stdio.h>
#include <math.h>

int main(void)
{
   float x1, x2, x3;
   float y1, y2, y3; 
   float innerProduct, lengthOfX;

   printf("Please enter the coordinates of the first vector X.\nPlease press \"return\" after you are done.  ");
   scanf("%f%f%f",&x1,&x2,&x3);

   printf("Please enter the coordinates of the second vector Y.\nPlease press \"return\" after you are done.  ");
   scanf("%f%f%f",&y1,&y2,&y3);

/* Step 1 of the homework: print out the two vectors */
   printf("X= [%6.3f, %6.3f, %6.3f]\n",x1,x2,x3);
   printf("Y= [%6.3f, %6.3f, %6.3f]\n",y1,y2,y3);


/* Step 2 of the homework: print out the length of the vectors
   (here we'll print out one only) */
   lengthOfX= sqrt((x1*x1)+(x2*x2)+(x3*x3));
   printf("The length of Vector X is: %6.3f\n",lengthOfX);

/* Step 2 of the homework: print out the result of adding the two vectors */
   printf("X+Y= [%6.3f, %6.3f, %6.3f]\n",(x1+y1),(x2+y2),(x3+y3));

return 0;
}
