//
//  main.cpp
//  Prog2
//
//  Created by Kristian Forestier on 2/16/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static GLfloat spin = 90.0; //starts the pendulum in a vertical position
static float r=1.0, l=8.0;  //setting the variables r and l to their respective values
int factor=2.0; //the speed at which it rotates

enum{
    
    MENU_CCW,
    MENU_CW,
    MENU_STOP,
    MENU_QUIT,
    MENU_SPEEDUP,
    MENU_SLOWDOWN
    
};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    glRotatef(spin, 0.0, 0.0, 1.0); //rotates all objects within the matrix
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);       //the width of the line to be drawn

    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-l,0);
    glEnd();
    
    glPointSize(5.0); //creates a point of size 5
    glBegin(GL_POINTS);
    glVertex2f(0.0,0.0); //creates it at the origin
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2d(r*sin(1/6.0*2*M_PI)-l, r*cos(1/6.0*2*M_PI)); //Draws a 6 sided polygon
    glVertex2d(r*sin(2/6.0*2*M_PI)-l, r*cos(2/6.0*2*M_PI)); //r and l are used to reshape and reposition
    glVertex2d(r*sin(3/6.0*2*M_PI)-l, r*cos(3/6.0*2*M_PI));
    glVertex2d(r*sin(4/6.0*2*M_PI)-l, r*cos(4/6.0*2*M_PI));
    glVertex2d(r*sin(5/6.0*2*M_PI)-l, r*cos(5/6.0*2*M_PI));
    glVertex2d(r*sin(6/6.0*2*M_PI)-l, r*cos(6/6.0*2*M_PI));
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplayccw()
{
    spin = spin + factor; //causes spin to increase by 2 in the positive direction
    //if (spin > 360.0)
      //  spin = spin - 360.0;
    glutPostRedisplay();
}

void spinDisplaycw()
{
    spin = spin - factor; //causes spin to increase by 2 in the negative direction
//    if (spin < 360.0)
  //      spin = spin + 360.0;
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glShadeModel(GL_FLAT);
}

void reshape(int w, int h) //used when re-sizing the viewport
{
    if(w<h)
        glViewport((h-w)/2, 0, w, w);
    else
        glViewport(0, (w-h)/2, h, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-l*1.3, l*1.3, -l*1.3, l*1.3);  //the size of the two dimensional view volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void menu(int key)
{
    switch (key){
        case MENU_CCW:                      //calls the ccw menu function created in the kbd function
            glutIdleFunc(spinDisplayccw);
            break;
            
        case MENU_STOP:             //stops rotating if the spacebar is pressed
            glutIdleFunc(NULL);
            break;
            
        case MENU_CW:
            glutIdleFunc(spinDisplaycw);
            break;
            
        case MENU_SPEEDUP:      //increases the speed by increasing the variable "factor" by 1
            factor++;
            break;
        
        case MENU_SLOWDOWN:     //decreases the speed by decreasing the variable "factor" by 1
           if(factor>0)         //checks if factor is greater than zero so it doesn't change direction
                factor--;
            break;
            
        case 'q':           //quits if the letter q is pressed or
        case 27:            //quits if the esc button is pressed
        case MENU_QUIT:
            exit(0);
            
        default:
            break;
    }
    
}

void kbd(unsigned char key, int x, int y)
{
    switch (key) {
        case '+':
            menu(MENU_CCW);
            break;
            
        case 32:
            menu(MENU_STOP);
            glutIdleFunc(NULL);
            break;
            
        case '-':
            menu(MENU_CW);
            break;
            
        case 1:
            menu(MENU_SPEEDUP);
            break;
            
        case 2:
            menu(MENU_SLOWDOWN);
            break;
            
        case 'q':
        case 27:
            menu(MENU_QUIT);
            
        default:
            break;
    }
}

void mouse(int button, int state, int x, int y) //this is used for the mouse click originally in this program
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplaycw);    //starts the rotation when mouse is clicked
            break;
        case GLUT_MIDDLE_BUTTON:
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) //no longer used since right click now bring up menu
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

//Request double buffer display mode.
//Register mouse input callback functions
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (300, 300);
    glutInitWindowPosition (400, 100);
    glutCreateWindow(argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(kbd);
    
    glutCreateMenu(menu);
    glutAddMenuEntry("Clockwise Rotation", MENU_CW);
    glutAddMenuEntry("Counter Clockwise Rotation", MENU_CCW);      //these are all used when displaying the menu
    glutAddMenuEntry("Stop Rotation", MENU_STOP);
    glutAddMenuEntry("Go Faster", MENU_SPEEDUP);
    glutAddMenuEntry("Go Slower", MENU_SLOWDOWN);
    glutAddMenuEntry("Quit", MENU_QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutMainLoop();
    
    
    return 0;   /* ANSI C requires main to return int. */
}
