//
//  chaos.c
//  testapp
//
//  Created by Kristian Forestier on 1/28/16.
//  Copyright (c) 2016 Kristian Forestier. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLdouble width, height;   /* window width and height */
int wd; /* GLUT window handle */
int ends[2][2];       /* array of 2D points */
GLfloat ctrlpts[4][2]={{0,0},{.75,.5},{.75,-.5}};

int i, n=6000, rndom;

/* Program initialization*/
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, -1.0);
    
    return;
}

/* Draw the window - this is where all the GL actions are */
void display(void)
{
    float p[3]= {0.0};
    
    /* clear the screen to white */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* draw a triangle */
    glColor3f(1.0, 1.0, 1.0);

    glPointSize(1.0);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);
    for(i=0;i<4;i++)
        glVertex3fv(&ctrlpts[i][0]);
    glEnd();
    glFlush();

    for(i=0; i<n; i++)
    {
        rndom= random()%3;
        
        if(rndom==0)
        {
            p[0]=p[0]/2;
            p[1]=(p[1]+0.4)/2;
        }
        
        else if(rndom==1)
        {
            p[0]=(p[0]-.6)/2;
            p[1]=(p[1]-.3)/2;
        }
        
        else if(rndom==2)
        {
            p[0]=(p[0]+.6)/2;
            p[1]=(p[1]-.3)/2;
        }
        
        glBegin(GL_POINTS);
            glVertex3fv(&p[0]);
        glEnd();
        glFlush();
    }
    
    
    return;
}

/* Called when window is resized, also when window is first created, before the first call to display(). */
void reshape(int w, int h)
{
    width = (GLdouble) w;
    height = (GLdouble) h;
    
    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    
    /* do an orthographic parallel projection with the coordinate system set to first quadrant, limited by screen/window size */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void kbd(unsigned char key, int x, int y)
{
    switch((char)key) {
        case 'q':
        case 27:    /* ESC */
            glutDestroyWindow(wd);
            exit(0);
        default:
            break;
    }
    
    return;
}

int main(int argc, char *argv[])
{
    /* perform initialization NOT OpenGL/GLUT dependent,
     as we haven't created a GLUT window yet */
    
    /* initialize GLUT, let it extract command-line GLUT options that you may provide - NOTE THE '&' BEFORE argc */
    glutInit(&argc, argv);
    
    /* specify the display to be single buffered and color as RGBA values */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    
    /* set the initial window size */
    glutInitWindowSize(800, 700);
    
    /* create the window and store the handle to it */
    glutCreateWindow("Experiment with line drawing" /* title */ );
    
    init();
    
    /* --- register callbacks with GLUT --- */
    
    /* register function to handle window resizes */
    glutReshapeFunc(reshape);
    
    /* register keyboard event processing function */
    glutKeyboardFunc(kbd);
    
    /* register function that draws in the window */
    glutDisplayFunc(display);
    
    /* start the GLUT main loop */
    glutMainLoop();
    
    exit(0);
}
