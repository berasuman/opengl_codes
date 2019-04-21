#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void display(){

    //for the christmas tree
   // glRotatef(45,0,0,0.1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.6,0.0);
    glRotatef(2,0,0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(500,650);
        glVertex2d(450,600);
        glVertex2d(550,600);
    glEnd();
    // glFlush();
    // glBegin(GL_TRIANGLES);
    //     glVertex2d(500,650);
    //     glVertex2d(430,550);
    //     glVertex2d(570,550);
    // glEnd();
    // glFlush();
    // glBegin(GL_TRIANGLES);
    //     glVertex2d(500,650);
    //     glVertex2d(410,500);
    //     glVertex2d(590,500);
    // glEnd();
    // glFlush();
    // glBegin(GL_TRIANGLES);
    //     glVertex2d(500,650);
    //     glVertex2d(390,450);
    //     glVertex2d(610,450);
    // glEnd();
    // glFlush();
    // glColor3f(0.8,0.5,0.1);
    // glBegin(GL_QUADS);
    //     glVertex2d(465+50,450);
    //     glVertex2d(435+50,450);
    //     glVertex2d(435+50,420);
    //     glVertex2d(465+50,420);
    // glEnd();
    // glFlush();

    // //for the dead tree
    // glBegin(GL_POLYGON);
    //     glVertex2d(785,500);
    //     glVertex2d(785,420);
    //     glVertex2d(815,420);
    //     glVertex2d(815,500);
    //     glVertex2d(830,520);
    //     glVertex2d(810,500);
    //     glVertex2d(800,515);
    //     glVertex2d(790,500);
    //     glVertex2d(760,520);
    // glEnd();
    // glFlush();

    // //for the bunker
    // glColor3f(0.4,0.4,0.4);
    // glBegin(GL_QUADS);//for the roof
    //     glVertex2d(500,300);
    //     glVertex2d(500,280);
    //     glVertex2d(700+10,280);
    //     glVertex2d(700+10,300);
    // glEnd();
    // glFlush();
    // glColor3f(0.2,0.2,0.2);//for house
    // glBegin(GL_QUADS);
    //     glVertex2d(510,280);
    //     glVertex2d(510,200-10);
    //     glVertex2d(690+10,200-10);
    //     glVertex2d(690+10,280);
    // glEnd();
    // glFlush();
    // glColor3f(0.6,0.6,0.6);
    // glBegin(GL_QUADS);//for the door
    //     glVertex2d(700,270);
    //     glVertex2d(700,200);
    //     glVertex2d(715,200);
    //     glVertex2d(715,270);
    // glEnd();
    // glFlush();
    // glColor3f(0.0,0.0,0.0);
    // glBegin(GL_LINES);//for the door
    //     glVertex2d(702,250);
    //     glVertex2d(713,250);
    //     glVertex2d(702,230);
    //     glVertex2d(713,230);
    // glEnd();
    // glFlush();
    glutSwapBuffers();
}

void init(){
    glClearColor(0.0,0.0,0.0,0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0,1280,0,720);
}


int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("@testrotate");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}