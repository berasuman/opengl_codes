#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
#define wsx 1280 //Windows Size x-Axis
#define wsy 720 //Window Size y-Axis
#define PI 3.14
#define mar 3389// radius of the planets
#define er 6738
#define mor 1737
#define sur 12600
#define roc 800
#define xmax 43000
#define xmin -8200
#define ymax 26000
#define ymin -2800
//Space for Global Varibles
GLfloat angle=0.0f;   // rotational angle of the shapes
int refreshms=30;     // refresh interval in milliseconds
GLint i=0,j=0,k=0;
int rand_stars1x[110],rand_stars2x[110],rand_stars3x[110],rand_stars1y[110],rand_stars2y[110],rand_stars3y[110];
float radius = 100;
float twoPI = 2 * PI;
GLint px,py,cx,cy;
void stars();
//Initialize OpenGl Graphics. One time things
void init()
            {
    glClearColor(0.1,0.1,0.1,0.0);
    //glViewport(800,0,1280,720);
    //glColor3f(1.0,0.0,0.0);
    gluOrtho2D(-8200,43000,-2800,26000); // x 0 to 128000 y 0 to 64000
    //glViewport(0,0,1280,720);   
                                }
//Timer Function. Repeated Callbacks Occurs here
void timer(int value) 
                        {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshms, timer, 0); // next timer call milliseconds later
                                            }

void zoom(int x,int y){
    // literally it's not zoom its some sort of clipping but take it as zoom ok 
    //glViewport(-3800,-8500,38400,21600);
    //glViewport(-1200,-2500,12800,7200);    //10% zoom
    //glViewport(-2000,-4000,19200,10800);  // 15% zoom 
    glViewport(0,0,1280,720); // full view 0% zoom
    //glViewport(-5300-(x/2),-15500,51200,28800);  // 100% zoom our starting pos/
    //glViewport(-3950-(x/2),-15500,51200,28800);  // 100% zoom our starting pos
}
void stars()
{
	int h;
	glColor3f(1,1,0);
	for(h=0;h<100;h++)
	{
		glPointSize(1);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars1x[h],ymin+rand_stars1y[h]);
		glEnd();
	}
	for(h=0;h<100;h++)
	{
		glPointSize(1+rand()%2);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars2x[h],ymin+rand_stars2y[h]);
		glEnd();
	}
	for(h=0;h<100;h++)
	{
		glPointSize(2+rand()%2);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars3x[h],ymin+rand_stars3y[h]);
		glEnd();
	}
	glColor3f(1,0,0);
	for(h=100;h<105;h++)
	{
		glPointSize(1);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars1x[h],ymin+rand_stars1y[h]);
		glEnd();
	}
	for(h=100;h<105;h++)
	{
		glPointSize(1+rand()%2);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars2x[h],ymin+rand_stars2y[h]);
		glEnd();
	}
	for(h=100;h<105;h++)
	{
		glPointSize(2+rand()%2);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars3x[h],ymin+rand_stars3y[h]);
		glEnd();
	}
	glColor3f(1,0.5,0);
	for(h=105;h<110;h++)
	{
		glPointSize(1);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars1x[h],ymin+rand_stars1y[h]);
		glEnd();
	}
	for(h=105;h<110;h++)
	{
		glPointSize(1+rand()%2);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars2x[h],ymin+rand_stars2y[h]);
		glEnd();
	}
	for(h=105;h<110;h++)
	{
		glPointSize(2+rand()%2);
		glBegin(GL_POINTS);
		glVertex2i(xmin+rand_stars3x[h],ymin+rand_stars3y[h]);
		glEnd();
	}
}
//Ground on Earth
void ground(){
    glBegin(GL_POLYGON);// the earth circle
    glColor3f(0,0,1);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f((sin(t)*er),6000+(cos(t)*er));
    glEnd();
    //Objects on Earth
    glBegin(GL_QUADS);       //Ground on Earth & Moon  //quad or rectangnle is to be replaced with polygon 
        glColor3f(0.0,1.0,0.3);
        glVertex2i(-2000,0+sur);
        glVertex2i(-2000,150+sur);
        glVertex2i(2000,150+sur);
        glVertex2i(2000,0+sur);
    glEnd();
    // the Bunker on Earth.
    glBegin(GL_QUADS);//for the roof
        glColor3f(0.4,0.4,0.4);
        glVertex2d(-2000,300+sur);
        glVertex2d(-2000,280+sur);
        glVertex2d(-1700+10,280+sur);
        glVertex2d(-1700+10,300+sur);
    glEnd();

    glBegin(GL_QUADS);//for house
        glColor3f(0.2,0.2,0.2);
        glVertex2d(-1990,280+sur);
        glVertex2d(-1990,200-50+sur);
        glVertex2d(-1700,200-50+sur);
        glVertex2d(-1700,280+sur);
    glEnd();

    glBegin(GL_QUADS);//for the door
        glColor3f(0.6,0.6,0.6);
        glVertex2d(-1700,270+sur);
        glVertex2d(-1700,200+sur);
        glVertex2d(-1685,200+sur);
        glVertex2d(-1685,270+sur);
    glEnd();

    glBegin(GL_LINES);//for the door
        glColor3f(0.0,0.0,0.0);
        glVertex2d(-1698,250+sur);
        glVertex2d(-1687,250+sur);
        glVertex2d(-1682,230+sur);
        glVertex2d(-1687,230+sur);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);// the moon circle
    glColor3f(0.2,0.2,0.2);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f(11000+(sin(t)*mor),8000+(cos(t)*mor));
    glEnd();
    // glBegin(GL_POLYGON);
    //     glColor3f(1.0,1.0,1.0);
    //     glVertex2i(19200,200+15000);
    //     glVertex2i(19200,250+15000);
    //     glVertex2i(19500,250+15000);
    //     glVertex2i(19500,200+15000);
    // glEnd(); 
    //int m,n;
    glBegin(GL_TRIANGLE_FAN);// the mars Circle 
    glColor3f(0.8,0.0,0.0);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f(38000+(sin(t)*mar),15000+(cos(t)*mar));
    glEnd();
}

//our Rocket
void rocket(int x){
    
    
    glBegin(GL_TRIANGLE_FAN); // Rocket Main Frame Head
    glColor3f(0.0,1.0,0.0);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(roc+980+(sin(t)*radius),x+600+sur+(cos(t)*radius));
    glEnd();

    glBegin(GL_QUADS);         //Main Rocket Body
        glColor3f(1.0,0.0,0.0);
        glVertex2i(roc+900,200+x+sur);
        glVertex2i(900+roc,450+x+sur);
        glVertex2i(1060+roc,450+x+sur);
        glVertex2i(1060+roc,200+x+sur);
    glEnd();
    glBegin(GL_QUADS);         //Main Rocket Body
        glColor3f(1.0,0.0,0.0);
        glVertex2i(roc+880,450+x+sur);
        glVertex2i(880+roc,600+x+sur);
        glVertex2i(1080+roc,600+x+sur);
        glVertex2i(1080+roc,450+x+sur);
    glEnd();
    int r=40;
    
    glBegin(GL_TRIANGLE_FAN); // left Small booster Head
    glColor3f(0.0,1.0,0.0);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(roc+860+(sin(t)*r),x+330+sur+(cos(t)*r));
    glEnd();

    glBegin(GL_QUADS);  //left Small Booster
        glColor3f(1.0,0.2,1.0);
        glVertex2i(900+roc,200+x+sur);
        glVertex2i(900+roc,330+x+sur);
        glVertex2i(820+roc,330+x+sur);
        glVertex2i(820+roc,200+x+sur);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); // right Small booster Head
    glColor3f(0.0,1.0,0.0);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(roc+1100+(sin(t)*r),x+330+sur+(cos(t)*r));
    glEnd();
    glBegin(GL_QUADS);  //right Small Booster
        glColor3f(1.0,0.0,1.0);
        glVertex2i(1060+roc,200+x+sur);
        glVertex2i(1060+roc,330+x+sur);
        glVertex2i(1140+roc,330+x+sur);
        glVertex2i(1140+roc,200+x+sur);
    glEnd();
    // glBegin(GL_QUADS);  //left Wing
    //     glColor3f(1.0,0.0,1.0);
    //     glVertex2i(900+roc,200+x+sur);
    //     glVertex2i(900+roc,300+x+sur);
    //     glVertex2i(825+roc,265+x+sur);
    //     glVertex2i(825+roc,200+x+sur);
    // glEnd();
    // glBegin(GL_QUADS);  //right Wing
    //     glColor3f(1.0,0.0,1.0);
    //     glVertex2i(1040+roc,200+x+sur);
    //     glVertex2i(1040+roc,300+x+sur);
    //     glVertex2i(1115+roc,265+x+sur);
    //     glVertex2i(1115+roc,200+x+sur);
    // glEnd();
    glBegin(GL_QUADS);  //bottom thrusters
        glColor3f(1.0,.0,0.5);
        glVertex2i(910+roc,200+x+sur);
        glVertex2i(880+roc,180+x+sur);
        glVertex2i(1060+roc,180+x+sur);
        glVertex2i(1030+roc,200+x+sur);
    glEnd();
    // glBegin(GL_POLYGON); // lights
    //     glColor3f(((rand()%(101))/100),((rand()%(101))/100),0.0);
    //     glVertex2i(200,200+x);
    //     glVertex2i(300,200+x);
    //     glVertex2i(200,300+x);
    //     glVertex2i(300,300+x);
    // glEnd();
    
            }
//The Stickman with 5 degrees of freedom
void stick(int x,int y){
    glLineWidth(5.0);
    glBegin(GL_LINES);         //Stickman Figure with 5 degrees of freedom  Top-down is being followed
        glColor3f(0.0,0.0,0.0);

        glVertex2i(-2000+x,230+sur);        //torso
        glVertex2i(-2000+x,330+sur);

        glVertex2i(-2000+x,310+sur);        //Obvious left hand
        glVertex2i(-2050+y+x,230+sur);

        glVertex2i(-2000+x,310+sur);        //right hand
        glVertex2i(-1950-y+x,230+sur);

        glVertex2i(-2000+x,230+sur);        //Assumed left leg
        glVertex2i(-2050+y+x,150+sur);

        glVertex2i(-2000+x,230+sur);        //right leg
        glVertex2i(-1950-y+x,150+sur);

    glEnd();
            }
// void zoom(int x,int y){
//     glViewport(-0,-140,2560,1440);

// } 
//The Main Display Functiom
void display()
              {
    glClear(GL_COLOR_BUFFER_BIT);     //Enabling the Color
    //glColor3f(1.0,0.0,0.0);          //Color RGB Red Green Blue
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    //glLoadIdentity();               // Reset the model-view matrix
    //Space for Static Polygons eg. ground
    glPushMatrix();
    stars();
    glPopMatrix();
    glPushMatrix();
    zoom(i,j);
    glPopMatrix();
    glPushMatrix();
    ground();

    glPopMatrix();  
    //Space For Moving Objects
    glPushMatrix();  // ground push

    rocket(k);
    glPopMatrix(); 

    glPushMatrix();  // rocket push
    stick(i,j);
    glPopMatrix();

    glPushMatrix();
    // stick push

    // zoom(i,j);
    // glPopMatrix();
    // glPushMatrix(); // zoom push
    
    // glBegin(GL_POLYGON);
    //     glColor3f(1.0,0.0,0.5);
    //     glVertex2i(1920,200);
    //     glVertex2i(1920,250);
    //     glVertex2i(1950,250);
    //     glVertex2i(1950,200);
    // glEnd(); 
    // glPushMatrix(); // last polygon push
    glPopMatrix();
    //glPopMatrix();       //for head of the man
    // int i;
	// int triangleAmount = 20;
	// int x=200, y=410, radius=40;
	// GLfloat twicePi = 2.0f * 3.1416;

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x, y);
	// 	for(i = 0; i <= triangleAmount;i++) {
	// 		glVertex2f(
	// 	            x + (radius * cos(i *  twicePi / triangleAmount)),
	// 		    y + (radius * sin(i * twicePi / triangleAmount))
	// 		);
	// 	}
	// glEnd();
	// glFlush();

	//for eyes of the man
	// int j;
	// int triangleAmount2 = 20;
	// int x2=185, y2=410, radius2=5;
	// GLfloat twicePi2 = 2.0f * 3.1416;
	// glColor3f(1.0,1.0,1.0);

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x2, y2);
	// 	for(j = 0; j <= triangleAmount2;j++) {
	// 		glVertex2f(
	// 	            x2 + (radius2 * cos(j *  twicePi2 / triangleAmount2)),
	// 		    y2 + (radius2 * sin(j * twicePi2 / triangleAmount2))
	// 		);
	// 	}
	// glEnd();
	// glFlush();

	// int i3;
	// int triangleAmount3 = 20;
	// int x3=215, y3=410, radius3=5;
	// GLfloat twicePi3 = 2.0f * 3.1416;
	// glColor3f(1.0,1.0,1.0);

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x3, y3);
	// 	for(i3 = 0; i3 <= triangleAmount3;i3++) {
	// 		glVertex2f(
	// 	            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
	// 		    y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
	// 		);
	// 	}
	// glEnd();
    // int i4;
	// int triangleAmount4 = 20;
	// int x4=200, y4=390, radius4=10;
	// GLfloat twicePi4 = 1.0f * 3.1416;
	// glColor3f(1.0,1.0,1.0);

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x4, y4);
	// 	for(i4 = 0; i4 <= triangleAmount4;i4++) {
	// 		glVertex2f(
	// 	            x4 - (radius3 * cos(i4 *  twicePi4 / triangleAmount4)),
	// 		    y4 - (radius4 * sin(i4 * twicePi4 / triangleAmount4))
	// 		);
	// 	}
	// glEnd();


    //The most imp place, Control Var here
    glutSwapBuffers();
    
        i+=2;
        if(i>1900)
            k+=2;
    j+=2.5;
    if(j==100)
        j=0;

                            }
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1280,720);
	glutCreateWindow("@title_HERE");
	init();
	int i1,i2;
	srand(time(0));
	for(i1=0;i1<110;i1++)
	{
		rand_stars1x[i1]=rand()%55500;
		rand_stars2x[i1]=rand()%55500;
		rand_stars3x[i1]=rand()%55500;
	}
	for(i1=0;i1<110;i1++)
	{
		rand_stars1y[i1]=rand()%28800;
		rand_stars2y[i1]=rand()%28800;
		rand_stars3y[i1]=rand()%28800;
	}
	glutDisplayFunc(display);
	glutTimerFunc(0,timer,0);
    glutFullScreen();
	glutMainLoop();
}
