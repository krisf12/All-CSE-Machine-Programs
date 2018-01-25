/*
//  main.c
//  Homework 1
//
//  Created by Kristian Forestier on 9/14/13.
//  Email: kristianforestier@my.unt.edu
//  This program takes two 3D vectors and calculates multiple operations with them.
*/

#include <stdio.h>
#include <math.h>  /*this library is for the math equations*/

int main(void)
{
    printf("\n\n");
    printf("CSCE 1030.001 \nProgram #1 \nKristian Forestier \nkf0106 \nkristianforestier@my.unt.edu");
    printf("\n\n\n\n");

    float x1,x2,x3,y1,y2,y3,xvector,yvector,bothvectors1,bothvectors2,bothvectors3,innerproduct,cos0;
    /*the float refernces that will be used in the code*/

    printf("Enter six floating point numbers:\n\n");
    /*this is the first thing that will show up to prompt the user to provide input*/

        printf("First number x: ");
        scanf("%f",&x1);

        printf("Second number x: ");
        scanf("%f",&x2);

        printf("Third number x: ");  /*these will be the 6 coordinates that the user inputs*/
        scanf("%f",&x3);

        printf("Fourth number y: ");
        scanf("%f",&y1);

        printf("Fifth number y: ");
        scanf("%f",&y2);

        printf("Sixth number y: ");
        scanf("%f",&y3);

        printf("\n\n\n");
                                    /*the program echo's the two 3D coordinates here*/
    printf("The coordinates of your vectors are: x(%g,%g,%g) and y(%g,%g,%g).",x1,x2,x3,y1,y2,y3);
    printf("\n\n\n\n");

    xvector= sqrt((x1*x1)+(x2*x2)+(x3*x3)); /*the formula for the length of xvector*/
    yvector= sqrt((y1*y1)+(y2*y2)+(y3*y3)); /*the formula for the length of yvector*/

        printf("The xvector length is: %f.",xvector);
        printf("\n");
        printf("The yvector length is: %f.",yvector);

    bothvectors1= x1+y1;
    bothvectors2= x2+y2;  /*these are the three formulas for adding the vectors together*/
    bothvectors3= x3+y3;

        printf("\n\n");
        printf("The result of adding the two vectors is: (%g,%g,%g).",bothvectors1,bothvectors2,bothvectors3);
        printf("\n\n");

    innerproduct= ((x1*y1)+(x2*y2)+(x3*y3)); /*the formula for the inner product of the two vectors*/

        printf("The inner product of the two vectors is: %g.",innerproduct);
        printf("\n\n");

    cos0= (innerproduct/(xvector*yvector));
    /*the formula for the cosine of the angle between the two vectors*/

        printf("The cosine of the angle between the two vectors is: %g.",cos0);
        printf("\n");

    return 0;

}

