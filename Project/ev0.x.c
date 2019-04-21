#include<GL/glut.h>
#include<stdio.h>
void init()
            {
    glClearColor(0.1,0.1,0.1,0.0);
    //glViewport(800,0,1280,720);
    //glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0,1280,0,720); // x 0 to 128000 y 0 to 64000
    //glViewport(0,0,1280,720);   
                                }
void display(){
    glBegin(GL_QUADS);         //Main Rocket Body
        glColor3f(1.0,0.0,0.0);
        glVertex2i(900,200);
        glVertex2i(900,450);
        glVertex2i(1060,450);
        glVertex2i(1060,200);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
                               { //The Main Function CAll
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("@title HERE");
    init();
    glutDisplayFunc(display); // Paints the Display
    //glutTimerFunc(0, timer, 0);
    //glutFullScreen();
    glutMainLoop();
                    }
                  