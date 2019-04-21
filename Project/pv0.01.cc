#include<stdio.h> 
#include<GL/glut.h> 
#include <unistd.h>
//#include<math.h> 
int x, y; 
float i, j; 
void myInit (void) 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
     
    glPointSize(-5.0);  
    // Set width of point to one unit 
    //glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity(); 
      
    // Set window size in X- and Y- direction 
    gluOrtho2D(-20,1260, -20, 700); 
}
void display (void) 
{ 
    //glClear(GL_COLOR_BUFFER_BIT);
    // glBegin(GL_LINES);
    //     glVertex2i(150,350);//body
    //     glVertex2i(150,250);
    //     //sleep(1);
    //     glVertex2i(150,350);//left hand
    //     glVertex2i(120,330);
    //     glVertex2i(150,350);//right hand
    //     glVertex2i(180,380);
    //     glVertex2i(150,250);//left leg
    //     glVertex2i(100,0);
    //     glVertex2i(150,250);//right leg
    //     glVertex2i(250,0);
    // glEnd();
    //glFlush();
   
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        
        glBegin(GL_POINTS);
            //glLineSize(5);
            glVertex2i(150,350);//bdydy
            glVertex2i(150,250);
            glVertex2i(150,350);//left hand
            glVertex2i(120,330);
            glVertex2i(150,350);//right hand
            glVertex2i(180,380);
            glVertex2i(150,250);//lefteg
            glVertex2i(100,0);
            glVertex2i(150,250);//righteg
            glVertex2i(250,0);
            glEnd();
            glFlush();
            //glFlush();
    //}
    
    //         glVertex2i(20+(j/1000),30-(j/1000));
    // for (j = 0; j < 5000000; j += 1) 
    // { 
    //     glClear(GL_COLOR_BUFFER_BIT);
    //     // glEnable(GL_LINE_STIPPLE); 
    //     // glLineStipple(1,0x0101);
    //     glBegin(GL_POINTS); 

    //     // }  
         //glEnd(); 
         //glFlush(); 
    // } 
} 
int main (int argc,char **argv) 
{ 
    glutInit(&argc, argv); 
      
    // Display mode which is of RGB (Red Green Blue) type 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(1280,720); 
    glutInitWindowPosition(0, 0); 
    glutCreateWindow("@2D"); 
    myInit(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 
