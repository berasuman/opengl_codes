#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
#define ZOOM_IN 1
#define ZOOM_OUT -1

//using namespace std;

const int screenWidth = 500;
const int screenHeight = 500;
    float cx = 0.0, cy = 0.0;       //center of viewport (cx, cy)
    float h=1.2, w = 1.2;           //window size
    int NumFrames = 10;             //frames
    int frame = 0;
    int direction = ZOOM_IN;


//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myinit() {
    glClearColor (1.0, 1.0, 1.0, 1.0);          //set the background color to white 
    glColor3f (0.0, 0.0, 0.0);                  //set the foreground color to black
    glPointSize (3.0);                          //set the point size to 3 X 3 pixels
    glViewport (0.0, 0.0, 500.0, 500.0);        //set the viewport to be the entire window

    //set up a world window to screen transformation
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
//  glMatrixMode (GL_MODELVIEW);

}


//<<<<<<<<<<<<<<<<<<<<<<< hexswirl >>>>>>>>>>>>>>>>>>>>
void hexswirl() {
    double angle;                       //the angle of rotation
    double angleInc = 2*PI/6.0;         //the angle increment
    double inc = 5.0/50;                //the radius increment
    double radius = 5.0/50.0;           //the radius to be used


    //clear the background
    glClear (GL_COLOR_BUFFER_BIT);

    //draw the hexagon swirl
    for (int j = 0; j <= 50; j++) {
        //the angle of rotation depends on which hexagon is 
        //being drawn.
        angle = j* (PI/180.0);

        //draw one hexagon
        glBegin (GL_LINE_STRIP);
            for (int k=0; k <= 6; k++) {
                angle += angleInc;
                glVertex2d(radius * cos(angle), radius *sin(angle));

            }
        glEnd();

        //determine the radius of the next hexagon
        radius += inc;
    }
    //swap buffers for a smooth change from one
    //frame to another
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}


//<<<<<<<<<<<<<<<<<<<<<<< viewZoom >>>>>>>>>>>>>>>>>>>>
void viewZoom(int i) {


    if(direction == ZOOM_IN) {
        //change the width and height of the window each time
        w *= 0.9;
        h *= 0.9; 
    } 
    if(direction == ZOOM_OUT) {
        w /= 0.9;
        h /= 0.9;
        }   

    if(i%10 == 0) {
        direction = -direction;
    }
        //change the window and draw the hexagon swirl
        cx = screenWidth / w;
        cy = screenHeight / h;
        glViewport((screenWidth-cx)/2, (screenHeight-cy)/2, cx, cy);

        hexswirl();

        glutPostRedisplay();
        glutTimerFunc(200, viewZoom,i+1);

}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv) {
    glutInit(&argc, argv);  
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100,100);
    glutCreateWindow("hexanim");

    glutDisplayFunc(hexswirl);
    viewZoom(1);
    myinit();

    glutMainLoop();
    return 1;
}