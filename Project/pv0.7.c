#include <GL/glut.h>     //Headers
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#define PI 3.14
#define mar 3389// Planets Radius  Mars 
#define er 6378     //Earth
#define mor 1737    //Moon
#define ery 12100     // Earth Ground Raiser y- Axis .no need to move x as centre of earth is (0,0) 
#define mrx 37400       // Mars Ground Raiser x-Axis
#define mry 18300       // Mars Ground Raiser y-Axis A sort of Shifter
#define roc 800
#define xmax 43000      //Self Descriptions
#define xmin -8200
#define ymax 26000
#define ymin -2800
//Space for Global Variables
GLfloat angle=0.0f;   // rotational angle of moon
int refreshms=30;     // refresh interval in milliseconds
GLdouble gtrack=-10;     //The Global Track Variable Very Imp
GLint i=0,j=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,tx=0,c0=0;
GLint n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0;// pqrmn unused 
int rand_stars1x[110],rand_stars2x[110],rand_stars3x[110],rand_stars1y[110],rand_stars2y[110],rand_stars3y[110];
GLfloat vportx=51200,vporty=28800,xi=-129,yi=-393,it0=0;
GLfloat vpx=1280,vpy=720,it1=0;
GLfloat rocx=0,rocy=0;//rocket co-ordinates
GLfloat acc=0;//rocket acceleration
GLfloat Rcx=16000,Rcy=0,thetaR=0;//rocket circular path variables
GLfloat m=0,t1=0,t2=0,t3=0;
//Functions Prototype
void zoom();
void rand_generate_for_stars();
void house();
void story();
//Function Definition Begins
//Utlity Functions Begins
//Timer Function. Repeated Callbacks Occurs here
void timer(int value) 
{
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshms, timer, 0); // next timer call milliseconds later
}
void ellipse(int xc,int yc,int Rx,int Ry,int x,int y,float col1,float col2,float col3)
{
	glBegin(GL_POLYGON);
	glColor3f(col1,col2,col3);
	for(float t=0;t<=6.29;t+=0.001)
		glVertex2i(xc+(cos(t)*Rx)+x,yc+(sin(t)*Ry)+y);
	glEnd();
}
void circle(int xc,int yc,int R,int x,int y,float col1,float col2,float col3)
{
	glBegin(GL_POLYGON);
	glColor3f(col1,col2,col3);
	for(float t=0;t<=6.29;t+=0.001)
		glVertex2i(xc+(cos(t)*R)+x,yc+(sin(t)*R)+y);
	glEnd();
}
void line(int x1,int y1,int x2,int y2,int x,int y,float col1,float col2,float col3)
{
	glBegin(GL_LINES);
	glColor3f(col1,col2,col3);
	glVertex2i(x1+x,y1+y);
	glVertex2i(x2+x,y2+y);
	glEnd();
}
//Utility Functions Ends.
//OPEN GL Funcrion Begins here
//Initialize OpenGl Graphics. One time things
void init()
{
    glClearColor(0.1,0.1,0.1,0.0);
    gluOrtho2D(-8200,43000,-2800,26000); // x 0 to 512000 y 0 to 28800
}
//Function For Stars in the Solar System
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
void house()
{
   glBegin(GL_QUADS);//for house
        glColor4f(0.2,0.2,0.2,0.8);
        glVertex2i(-1990,400+ery);
        glVertex2i(-1990,150+ery);
        glVertex2i(-1700,150+ery);
        glVertex2i(-1700,400+ery);
    glEnd();
}
//Planets and Grounds Functions
void ground(){
    //circle of Earth
    glBegin(GL_POLYGON);// the earth circle
    if(gtrack>0  && gtrack<=28.8){
    glColor3f(0.0,0.3,1.0);  
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f((sin(t)*er),6000+(cos(t)*er));
    glEnd();
    }
    //Objects on Earth
    glBegin(GL_QUADS);       //Ground on Earth & Moon 
        glColor3f(0.0,1.0,0.3);
        glVertex2i(-2000,0+ery);
        glVertex2i(-2000,150+ery);
        glVertex2i(2000,150+ery);
        glVertex2i(2000,0+ery);
    glEnd();
    // the Bunker on Earth.
    glBegin(GL_QUADS);//for the roof
        glColor3f(0.4,0.4,0.4);
        glVertex2i(-2000,430+ery);
        glVertex2i(-2000,400+ery);
        glVertex2i(-1700+20,400+ery);
        glVertex2i(-1700+20,430+ery);
    glEnd();
    //Door Control Variable
    if(tx>-1800)
        if(a<200 && b==0)
        a+=5;
    if(t>-1000){
    if(a>=200 || b==1){
        a-=7;
        b=1;
        if(a==25)
            b=3;
        }
    }
    glBegin(GL_QUADS);//for the door
        glColor3f(0.6,0.6,0.6);
        glVertex2i(-1700,390+ery);
        glVertex2i(-1700,150+ery);
        glVertex2i(-1685+a,150+ery);
        glVertex2i(-1685+a,390+ery);
    glEnd();

    glBegin(GL_POLYGON); 
        glColor3f(0.36,0.25,0.20);     //for the dead tree bark
        glVertex2d(785-700,390+ery);   //b 
        glVertex2d(785-700,150+ery);   //a  fixed point
        glVertex2d(875-700,150+ery);   //h   over
        glVertex2d(875-700,390+ery);   //g
        glVertex2d(920-700,450+ery);   //both axis scaled is to be done 
        glVertex2d(860-700,390+ery);
        glVertex2d(830-700,435+ery);
        glVertex2d(800-700,390+ery);   //d  over
        glVertex2d(710-700,450+ery);   //c
    glEnd();
    //angle+=45;
    glPopMatrix();
    angle+=0.2;glPushMatrix();
    //glTranslated(-100,-200,0);
    glRotated(angle,0.0,0.0,0.1);
    glBegin(GL_TRIANGLE_FAN);// the moon circle
    glColor3f(0.2,0.2,0.2);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f(11000+(sin(t)*mor),11000+(cos(t)*mor));
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);// the mars Circle 
    glColor3f(0.8,0.0,0.0);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f(38000+(sin(t)*mar),15000+(cos(t)*mar));
    glEnd();
}
void groundmars(){
        //the mountains
        //for 1st Shade
        glColor3f(0.8,0.3,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(0+mrx,300+mry);
            glVertex2d(0+mrx,330+mry);
            glVertex2d(100+mrx,400+mry);
            glVertex2d(380+mrx,310+mry);
            glVertex2d(400+mrx,550+mry);
            glVertex2d(730+mrx,300+mry);
            glVertex2d(850+mrx,510+mry);
            glVertex2d(1170+mrx,350+mry);
            glVertex2d(1200+mrx,380+mry);
            glVertex2d(1280+mrx,350+mry);
            glVertex2d(1280+mrx,300+mry);
        glEnd();

        //for 2nd shade
        glColor3f(0.7,0.3,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(0+mrx,300+mry);
            glVertex2d(0+mrx,330+mry);
            glVertex2d(100+mrx,400+mry);
            glVertex2d(120+mrx,360+mry);
            glVertex2d(190+mrx,300+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(150+mrx,390+mry);
            glVertex2d(400+mrx,550+mry);
            glVertex2d(440+mrx,310+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(552+mrx,433+mry);
            glVertex2d(850+mrx,510+mry);
            glVertex2d(900+mrx,350+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(1125+mrx,372+mry);
            glVertex2d(1200+mrx,380+mry);
            glVertex2d(1250+mrx,310+mry);
        glEnd();

        //for the 3rd shade
        glColor3f(0.3,0.2,0.0);
        glBegin(GL_POLYGON);
              glVertex2d(0+mrx,300+mry);
              glVertex2d(0+mrx,330+mry);
            glVertex2d(100+mrx,400+mry);
             glVertex2d(92+mrx,360+mry);
            glVertex2d(120+mrx,300+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(150+mrx,390+mry);
            glVertex2d(300+mrx,482+mry);
            glVertex2d(310+mrx,420+mry);
            glVertex2d(440+mrx,310+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(552+mrx,433+mry);
            glVertex2d(710+mrx,470+mry);
            glVertex2d(900+mrx,350+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(1125+mrx,372+mry);
            glVertex2d(1160+mrx,374+mry);
            glVertex2d(1250+mrx,310+mry);
        glEnd();

        //for the ground
        glColor3f(0.9,0.3,0.0);  // main modifications here
        glBegin(GL_QUADS);
            glVertex2d(-800+mrx,300+mry);
            glVertex2d(-800+mrx,0+mry);
            glVertex2d(1500+mrx,0+mry);
            glVertex2d(1500+mrx,300+mry);
        glEnd();

        //for rocks on the ground
        glColor3f(0.7,0.3,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(100+mrx,100+mry);
            glVertex2d(200+mrx,150+mry);
            glVertex2d(370+mrx,130+mry);
            glVertex2d(600+mrx,170+mry);
            glVertex2d(1000+mrx,100+mry);
            glVertex2d(600+mrx,120+mry);
            glVertex2d(370+mrx,100+mry);
            glVertex2d(200+mrx,120+mry);
        glEnd();

        glBegin(GL_POLYGON);
             glVertex2d(600+mrx,150+mry);
             glVertex2d(800+mrx,180+mry);
             glVertex2d(900+mrx,155+mry);
            glVertex2d(1100+mrx,200+mry);
            glVertex2d(1280+mrx,175+mry);
            glVertex2d(1280+mrx,150+mry);
        glEnd();

        //for the 1st tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600+mrx,200+mry);
            glVertex2d(600+mrx,320+mry);
            glVertex2d(700+mrx,320+mry);
            glVertex2d(700+mrx,200+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595+mrx,320+mry);
            glVertex2d(595+mrx,350+mry);
            glVertex2d(705+mrx,350+mry);
            glVertex2d(705+mrx,320+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(600+mrx,350+mry);
            glVertex2d(600+mrx,470+mry);
            glVertex2d(700+mrx,470+mry);
            glVertex2d(700+mrx,350+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595+mrx,470+mry);
            glVertex2d(595+mrx,500+mry);
            glVertex2d(705+mrx,500+mry);
            glVertex2d(705+mrx,470+mry);
        glEnd();

        //for the dome
        int i;
        int triangleAmount = 20;
        int x=650, y=500, radius=55;
        GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x+mrx, y+mry);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mrx+x + (radius * cos(i *  twicePi / triangleAmount)),
			    mry+y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        //for the lines
        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595+mrx,470+mry);
            glVertex2d(705+mrx,470+mry);
            glVertex2d(595+mrx,320+mry);
            glVertex2d(705+mrx,320+mry);
            glVertex2d(595+mrx,350+mry);
            glVertex2d(705+mrx,350+mry);
            glVertex2d(600+mrx,350+mry);
            glVertex2d(600+mrx,470+mry);
            glVertex2d(615+mrx,350+mry);
            glVertex2d(615+mrx,470+mry);
            glVertex2d(630+mrx,350+mry);
            glVertex2d(630+mrx,470+mry);
            glVertex2d(647+mrx,350+mry);
            glVertex2d(647+mrx,470+mry);
            glVertex2d(665+mrx,350+mry);
            glVertex2d(665+mrx,470+mry);
            glVertex2d(687+mrx,350+mry);
            glVertex2d(687+mrx,470+mry);
            glVertex2d(700+mrx,350+mry);
            glVertex2d(700+mrx,470+mry);
            glVertex2d(600+mrx,350-150+mry);
            glVertex2d(600+mrx,470-150+mry);
            glVertex2d(615+mrx,350-150+mry);
            glVertex2d(615+mrx,470-150+mry);
            glVertex2d(630+mrx,350-150+mry);
            glVertex2d(630+mrx,470-150+mry);
            glVertex2d(647+mrx,350-150+mry);
            glVertex2d(647+mrx,470-150+mry);
            glVertex2d(665+mrx,350-150+mry);
            glVertex2d(665+mrx,470-150+mry);
            glVertex2d(687+mrx,350-150+mry);
            glVertex2d(687+mrx,470-150+mry);
            glVertex2d(700+mrx,350-150+mry);
            glVertex2d(700+mrx,470-150+mry);
        glEnd();

         //for the 2nd tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600-200+mrx,200+mry);
            glVertex2d(600-200+mrx,320+mry);
            glVertex2d(700-200+mrx,320+mry);
            glVertex2d(700-200+mrx,200+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595-200+mrx,320+mry);
            glVertex2d(595-200+mrx,350+mry);
            glVertex2d(705-200+mrx,350+mry);
            glVertex2d(705-200+mrx,320+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(600-200+mrx,350+mry);
            glVertex2d(600-200+mrx,470+mry);
            glVertex2d(700-200+mrx,470+mry);
            glVertex2d(700-200+mrx,350+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595-200+mrx,470+mry);
            glVertex2d(595-200+mrx,500+mry);
            glVertex2d(705-200+mrx,500+mry);
            glVertex2d(705-200+mrx,470+mry);
        glEnd();

        //for the dome
        int i1;
        int x1=650-200, y1=500, radius1=55;
        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1+mrx, y1+mry);
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            mrx+x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    mry+y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
        glEnd();

        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595-200+mrx,470+mry);
            glVertex2d(705-200+mrx,470+mry);
            glVertex2d(595-200+mrx,320+mry);
            glVertex2d(705-200+mrx,320+mry);
            glVertex2d(595-200+mrx,350+mry);
            glVertex2d(705-200+mrx,350+mry);
            glVertex2d(600-200+mrx,350+mry);
            glVertex2d(600-200+mrx,470+mry);
            glVertex2d(615-200+mrx,350+mry);
            glVertex2d(615-200+mrx,470+mry);
            glVertex2d(630-200+mrx,350+mry);
            glVertex2d(630-200+mrx,470+mry);
            glVertex2d(647-200+mrx,350+mry);
            glVertex2d(647-200+mrx,470+mry);
            glVertex2d(665-200+mrx,350+mry);
            glVertex2d(665-200+mrx,470+mry);
            glVertex2d(687-200+mrx,350+mry);
            glVertex2d(687-200+mrx,470+mry);
            glVertex2d(700-200+mrx,350+mry);
            glVertex2d(700-200+mrx,470+mry);
            glVertex2d(600-200+mrx,350-150+mry);
            glVertex2d(600-200+mrx,470-150+mry);
            glVertex2d(615-200+mrx,350-150+mry);
            glVertex2d(615-200+mrx,470-150+mry);
            glVertex2d(630-200+mrx,350-150+mry);
            glVertex2d(630-200+mrx,470-150+mry);
            glVertex2d(647-200+mrx,350-150+mry);
            glVertex2d(647-200+mrx,470-150+mry);
            glVertex2d(665-200+mrx,350-150+mry);
            glVertex2d(665-200+mrx,470-150+mry);
            glVertex2d(687-200+mrx,350-150+mry);
            glVertex2d(687-200+mrx,470-150+mry);
            glVertex2d(700-200+mrx,350-150+mry);
            glVertex2d(700-200+mrx,470-150+mry);
        glEnd();

        //for the 3rd tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600+200+mrx,200+mry);
            glVertex2d(600+200+mrx,320+mry);
            glVertex2d(700+200+mrx,320+mry);
            glVertex2d(700+200+mrx,200+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595+200+mrx,320+mry);
            glVertex2d(595+200+mrx,350+mry);
            glVertex2d(705+200+mrx,350+mry);
            glVertex2d(705+200+mrx,320+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(600+200+mrx,350+mry);
            glVertex2d(600+200+mrx,470+mry);
            glVertex2d(700+200+mrx,470+mry);
            glVertex2d(700+200+mrx,350+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595+200+mrx,470+mry);
            glVertex2d(595+200+mrx,500+mry);
            glVertex2d(705+200+mrx,500+mry);
            glVertex2d(705+200+mrx,470+mry);
        glEnd();

        //for the dome
        int i2;
        //triangleAmount = 20;
        int x2=650+200, y2=500, radius2=55;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2+mrx, y2+mry);
		for(i2 = 0; i2 <= triangleAmount;i2++) {
			glVertex2f(
		            mrx+x2 + (radius2 * cos(i2 *  twicePi / triangleAmount)),
			    mry+y2 + (radius2 * sin(i2 * twicePi / triangleAmount))
			);
		}
        glEnd();

        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595+200+mrx,470+mry);
            glVertex2d(705+200+mrx,470+mry);
            glVertex2d(595+200+mrx,320+mry);
            glVertex2d(705+200+mrx,320+mry);
            glVertex2d(595+200+mrx,350+mry);
            glVertex2d(705+200+mrx,350+mry);
            glVertex2d(600+200+mrx,350+mry);
            glVertex2d(600+200+mrx,470+mry);
            glVertex2d(615+200+mrx,350+mry);
            glVertex2d(615+200+mrx,470+mry);
            glVertex2d(630+200+mrx,350+mry);
            glVertex2d(630+200+mrx,470+mry);
            glVertex2d(647+200+mrx,350+mry);
            glVertex2d(647+200+mrx,470+mry);
            glVertex2d(665+200+mrx,350+mry);
            glVertex2d(665+200+mrx,470+mry);
            glVertex2d(687+200+mrx,350+mry);
            glVertex2d(687+200+mrx,470+mry);
            glVertex2d(700+200+mrx,350+mry);
            glVertex2d(700+200+mrx,470+mry);
            glVertex2d(600+200+mrx,350-150+mry);
            glVertex2d(600+200+mrx,470-150+mry);
            glVertex2d(615+200+mrx,350-150+mry);
            glVertex2d(615+200+mrx,470-150+mry);
            glVertex2d(630+200+mrx,350-150+mry);
            glVertex2d(630+200+mrx,470-150+mry);
            glVertex2d(647+200+mrx,350-150+mry);
            glVertex2d(647+200+mrx,470-150+mry);
            glVertex2d(665+200+mrx,350-150+mry);
            glVertex2d(665+200+mrx,470-150+mry);
            glVertex2d(687+200+mrx,350-150+mry);
            glVertex2d(687+200+mrx,470-150+mry);
            glVertex2d(700+200+mrx,350-150+mry);
            glVertex2d(700+200+mrx,470-150+mry);
        glEnd();

        //for the 4th tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600-400+mrx,200+mry);
            glVertex2d(600-400+mrx,320+mry);
            glVertex2d(700-400+mrx,320+mry);
            glVertex2d(700-400+mrx,200+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595-400+mrx,320+mry);
            glVertex2d(595-400+mrx,350+mry);
            glVertex2d(705-400+mrx,350+mry);
            glVertex2d(705-400+mrx,320+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(600-400+mrx,350+mry);
            glVertex2d(600-400+mrx,470+mry);
            glVertex2d(700-400+mrx,470+mry);
            glVertex2d(700-400+mrx,350+mry);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2d(595-400+mrx,470+mry);
            glVertex2d(595-400+mrx,500+mry);
            glVertex2d(705-400+mrx,500+mry);
            glVertex2d(705-400+mrx,470+mry);
        glEnd();

        //for the dome
        int i3;
        int x3=650-400, y3=500, radius3=55;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3+mrx, y3+mry);
		for(i3 = 0; i3 <= triangleAmount;i3++) {
			glVertex2f(
		            mrx+x3 + (radius3 * cos(i3 *  twicePi / triangleAmount)),
			    mry+y3 + (radius3 * sin(i3 * twicePi / triangleAmount))
			);
		}
        glEnd();

        //for the lines
        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595-400+mrx,470+mry);
            glVertex2d(705-400+mrx,470+mry);
            glVertex2d(595-400+mrx,320+mry);
            glVertex2d(705-400+mrx,320+mry);
            glVertex2d(595-400+mrx,350+mry);
            glVertex2d(705-400+mrx,350+mry);
            glVertex2d(600-400+mrx,350+mry);
            glVertex2d(600-400+mrx,470+mry);
            glVertex2d(615-400+mrx,350+mry);
            glVertex2d(615-400+mrx,470+mry);
            glVertex2d(630-400+mrx,350+mry);
            glVertex2d(630-400+mrx,470+mry);
            glVertex2d(647-400+mrx,350+mry);
            glVertex2d(647-400+mrx,470+mry);
            glVertex2d(665-400+mrx,350+mry);
            glVertex2d(665-400+mrx,470+mry);
            glVertex2d(687-400+mrx,350+mry);
            glVertex2d(687-400+mrx,470+mry);
            glVertex2d(700-400+mrx,350+mry);
            glVertex2d(700-400+mrx,470+mry);
            glVertex2d(600-400+mrx,350-150+mry);
            glVertex2d(600-400+mrx,470-150+mry);
            glVertex2d(615-400+mrx,350-150+mry);
            glVertex2d(615-400+mrx,470-150+mry);
            glVertex2d(630-400+mrx,350-150+mry);
            glVertex2d(630-400+mrx,470-150+mry);
            glVertex2d(647-400+mrx,350-150+mry);
            glVertex2d(647-400+mrx,470-150+mry);
            glVertex2d(665-400+mrx,350-150+mry);
            glVertex2d(665-400+mrx,470-150+mry);
            glVertex2d(687-400+mrx,350-150+mry);
            glVertex2d(687-400+mrx,470-150+mry);
            glVertex2d(700-400+mrx,350-150+mry);
            glVertex2d(700-400+mrx,470-150+mry);
        glEnd();

        //for the 1st dome type hoouses
        glColor3f(0.7,0.9,0.7);
        int i4;
        //int triangleAmount = 20;
        int x4=700, y4=180, radius4=200;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4+mrx, y4+mry);
		for(i4 = 0; i4 <= triangleAmount;i4++) {
			glVertex2f(
		            mrx+x4 + (radius4 * cos(i4 *  twicePi / triangleAmount)),
			    mry+y4 + (radius4 * sin(i4 * twicePi / triangleAmount))
			);
		}
        glEnd();

        //for the inner circle
        glColor3f(0.8,0.8,0.9);
        int i41;
        //int triangleAmount = 20;
        int x41=700, y41=180, radius41=170;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x41+mrx, y41+mry);
		for(i41 = 0; i41 <= triangleAmount;i41++) {
			glVertex2f(
		            mrx+x41 + (radius41 * cos(i41 *  twicePi / triangleAmount)),
			    mry+y41 + (radius41 * sin(i41 * twicePi / triangleAmount))
			);
		}
        glEnd();

        //for the line
        glColor3f(1.0,1.0,1.0);
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glVertex2d(700+mrx,180+mry);
            glVertex2d(700+mrx,350+mry);
        glEnd();

        //for the 2nd dome type hoouses
        glColor3f(0.7,0.9,0.7);
        int i5;
        //int triangleAmount = 20;
        int x5=700+350, y5=180+20, radius5=180;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5+mrx, y5+mry);
		for(i5 = 0; i5 <= triangleAmount;i5++) {
			glVertex2f(
		            mrx+x5 + (radius5 * cos(i5 *  twicePi / triangleAmount)),
			    mry+y5 + (radius5 * sin(i5 * twicePi / triangleAmount))
			);
		}
        glEnd();

        //for the inner circle
        glColor3f(0.8,0.8,0.9);
        int i51;
        int x51=700+350, y51=180+20, radius51=150;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x51+mrx, y51+mry);
		for(i51 = 0; i51 <= triangleAmount;i51++) {
			glVertex2f(
		            mrx+x51 + (radius51 * cos(i51 *  twicePi / triangleAmount)),
			    mry+y51 + (radius51 * sin(i51 * twicePi / triangleAmount))
			);
		}
        glEnd();

        //for the line
        glColor3f(1.0,1.0,1.0);
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glVertex2d(700+350+mrx,180+20+mry);
            glVertex2d(700+350+mrx,350+mry);
        glEnd();

        //for the vehicle
        //for the main part
        glColor3f(0.7,0.5,0.1);
        glBegin(GL_POLYGON);
            glVertex2d(100*2-50+mrx,150*2-150+mry);
            glVertex2d(100*2-50+mrx,200*2-150+mry);
            glVertex2d(120*2-50+mrx,250*2-150+mry);
            glVertex2d(220*2+50+mrx,250*2-150+mry);
            glVertex2d(240*2+50+mrx,200*2-150+mry);
            glVertex2d(240*2+50+mrx,150*2-150+mry);
        glEnd();

        //for the wheels
        glColor3f(0.1,0.1,0.1);
            int i7;
        int triangleAmount7 = 20;
        int x7=240, y7=150, radius7=50;
        GLfloat twicePi7 = 2.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7+mrx, y7+mry);
		for(i7 = 0; i7 <= triangleAmount;i7++) {
			glVertex2f(
		            mrx+x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount)),
			    mry+y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount))
			);
		}
        glEnd();

        int i8;
        int triangleAmount8 = 20;
        int x8=450, y8=150, radius8=50;
        GLfloat twicePi8 = 2.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8+mrx, y8+mry);
		for(i8 = 0; i8 <= triangleAmount;i8++) {
			glVertex2f(
		            mrx+x8+ (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    mry+y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
        glEnd();

        //for the windows
        glColor3f(0.1,0.3,0.5);
        glBegin(GL_POLYGON);
            glVertex2d(430+mrx,200+500+mry);
            glVertex2d(430+mrx,230+100+mry);
            glVertex2d(490+mrx,230+100+mry);
            glVertex2d(520+mrx,200+500+mry);
        glEnd();

        //for the middle part
        glColor3f(0.5,0.6,0.2);
        glBegin(GL_POLYGON);
            glVertex2d(250+mrx,330+mry);
            glVertex2d(250+mrx,370+mry);
            glVertex2d(400+mrx,370+mry);
            glVertex2d(400+mrx,330+mry);
        glEnd();

}
//Rocket Function
void rocket(int y,int x)// one more parameter to be added 
{
    glBegin(GL_TRIANGLE_FAN); // Rocket Main Frame Head
    glColor3f(0.4,0.4,0.4);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(roc+y+980-700+(sin(t)*100),x+600+ery+(cos(t)*100));
    glEnd();
    glBegin(GL_QUADS);         //Main Rocket Body Upper Part
        glColor3f(1.0,1.0,1.0);
        glVertex2i(roc+y-700+900,200+x+ery);
        glVertex2i(900-700+y+roc,450+x+ery);
        glVertex2i(1060-700+y+roc,450+x+ery);
        glVertex2i(1060-700+y+roc,200+x+ery);
    glEnd();
    glBegin(GL_QUADS);         //Main Rocket Body Lower Part
        glColor3f(1.0,1.0,1.0);
        glVertex2i(roc-700+y+880,450+x+ery);
        glVertex2i(880-700+y+roc,600+x+ery);
        glVertex2i(1080-700+y+roc,600+x+ery);
        glVertex2i(1080-700+y+roc,450+x+ery);
    glEnd();
    int rboost=40; // radius of boosters
    glBegin(GL_TRIANGLE_FAN); // left Small booster Head
    glColor3f(0.3,0.3,0.3);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(roc-700+y+860+(sin(t)*rboost),x+350+ery+(cos(t)*rboost));
    glEnd();
    glBegin(GL_QUADS);  //left Small Booster
        glColor3f(1.0,0.1,1.0);
        glVertex2i(900-700+y+roc,220+x+ery);
        glVertex2i(900-700+y+roc,350+x+ery);
        glVertex2i(820-700+y+roc,350+x+ery);
        glVertex2i(820-700+y+roc,220+x+ery);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); // right Small booster Head
    glColor3f(0.3,0.3,0.3);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(roc-700+y+1100+(sin(t)*rboost),x+350+ery+(cos(t)*rboost));
    glEnd();
    glBegin(GL_QUADS);  //right Small Booster
        glColor3f(1.0,0.1,1.0);
        glVertex2i(1060-700+y+roc,220+x+ery);
        glVertex2i(1060-700+y+roc,350+x+ery);
        glVertex2i(1140-700+y+roc,350+x+ery);
        glVertex2i(1140-700+y+roc,220+x+ery);
    glEnd();
    // glBegin(GL_QUADS);  //left Wing    // I am thinking not to waste them
    //     glColor3f(1.0,0.0,1.0);
    //     glVertex2i(900+roc,200+x+ery);
    //     glVertex2i(900+roc,300+x+ery);
    //     glVertex2i(825+roc,265+x+ery);
    //     glVertex2i(825+roc,200+x+ery);
    // glEnd();
    // glBegin(GL_QUADS);  //right Wing
    //     glColor3f(1.0,0.0,1.0);
    //     glVertex2i(1040+roc,200+x+ery);
    //     glVertex2i(1040+roc,300+x+ery);
    //     glVertex2i(1115+roc,265+x+ery);
    //     glVertex2i(1115+roc,200+x+ery);
    // glEnd();
    glBegin(GL_QUADS);  //bottom thrusters
        glColor3f(1.0,0.0,0.5);
        glVertex2i(910-700+y+roc,200+x+ery);
        glVertex2i(900-700+y+roc,170+x+ery);
        glVertex2i(1060-700+y+roc,170+x+ery);
        glVertex2i(1050-700+y+roc,200+x+ery);
    glEnd();
    // glBegin(GL_POLYGON); // lights
    //     glColor3f(((rand()%(101))/100),((rand()%(101))/100),0.0);
    //     glVertex2i(200,200+x);
    //     glVertex2i(300,200+x);
    //     glVertex2i(200,300+x);
    //     glVertex2i(300,300+x);
    // glEnd();
    if(gtrack>17&&gtrack<=29.5)//fire
    {
    glBegin(GL_LINES);
    	for(int i=900-700+roc;i<=1060-700+roc;i+=rand()%10)
    		line(i,170+ery,i,170+ery-300+rand()%70,y,x,1,1,0);
    }
}
//The Stickman with 5 degrees of freedom
void stickman(int x,int y)
{
     glLineWidth(5.0);
     //glScaled(0.2,0.2,0.0);
     glBegin(GL_LINES);         //Top-down Aproach is being followed
         glColor3f(0.0,0.0,0.0);
         glVertex2i(-2000+x,230+ery);        //torso
         glVertex2i(-2000+x,330+ery);
         glVertex2i(-2000+x,310+ery);        //Obvious left hand
         glVertex2i(-2050+y+x,230+ery);
         glVertex2i(-2000+x,310+ery);        //right hand
         glVertex2i(-1950-y+x,230+ery);
         glVertex2i(-2000+x,230+ery);        //Assumed left leg
         glVertex2i(-2050+y+x,150+ery);
         glVertex2i(-2000+x,230+ery);        //right leg
         glVertex2i(-1950-y+x,150+ery);
     glEnd();
         glBegin(GL_POLYGON);// head replace with ellipse
    glColor3f(0,0,0);
    int triamount=20;
	for(t=0;t<= triamount;t++){
		glVertex2f(-2000+x+(30*cos(t*6.28/triamount)),
			355+ery+(30*sin(t*6.28/triamount)));
	}
	glEnd();

}
//The Main Display Functiom
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);     //Enabling the Color
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    //glLoadIdentity();               // Reset the model-view matrix
    //glEnable(GL_BLEND);
    if(gtrack>=-0.5 && gtrack<2){
        glEnable(GL_BLEND);
        glBlendFunc(0.6,0.2);
        //glDisable(GL_BLEND);
    }
    if(gtrack>2.00 && gtrack<2.01)
        glDisable(GL_BLEND);
    //printf("%f",gtrack);
    glPushMatrix();
    zoom();
    glPopMatrix();

    glPushMatrix();
    story();
    glPopMatrix();
    
    glPushMatrix();
    stars();
    glPopMatrix();

    glPushMatrix();
    ground();
    glPopMatrix();

    glPushMatrix();
    groundmars();
    glPopMatrix();

    glPushMatrix();
    rocket(rocx,rocy);
    glPopMatrix();

    //Initial Control Variable
    if(gtrack>=0&&gtrack<15.3)
    {
    	glPushMatrix();
    	stickman(i,j);
    	glPopMatrix();
    }
    glPushMatrix();
    house();
    glPopMatrix(); 

    //The most imp place, Control Var here
    glutSwapBuffers();
    tx=-2000+i;
    if(gtrack>=0&&gtrack<15.2){
    i+=2;
        j+=2.5;
        if(j==100)
            j=0;
    }
    if(gtrack>17&&gtrack<20)
    	rocy+=0.3;
    if(gtrack>=20&&gtrack<20.6)
    {
    	rocy=90+acc*acc*acc;
    	acc+=0.2;
    }
    if(gtrack>=22&&gtrack<23)
    {
    	rocy=90+acc*acc*acc;
    	acc+=0.2;
    }
    if(gtrack>=23&&gtrack<=25)
    {
    	rocx=37000;
    	rocy=13300;
    }
    if(gtrack>25&&gtrack<=26.35)
    	rocy-=40;
    if(gtrack>27&&gtrack<=28.8)
    	rocy-=10;
    /*if(gtrack>=23 && gtrack<23.3)
    {
    	int RC=6000;
    	rocx=-RC*cos(thetaR)+RC;
    	rocy=90+acc*acc*acc+RC*sin(thetaR);
    	thetaR+=0.03;
    }
    if(gtrack>=23.3 && gtrack<24)
    	rocx=rocx+200;*/
    gtrack+=0.01;  // Our Global Track Updates Here
}
void zoom()
{
    //zooming is implemted via viewport. Basically Clips the Window
    //glViewport(-5500,-14950,51200,28800); // our starting pos FINAL starts at the bunker 
    //glViewport(-29000,-21100,51200,28800);  // the mars surface
    //glViewport(0,0,1280,720);      //For Full World View
    if(gtrack<0){
        glViewport(-3850,-1100,25600,14400); //Our Story Mode
        //glViewport(0,0,1280,720);
    }
    
    if(gtrack>=0 && gtrack<=2)
    	glViewport(-4000,-14950,51200,28800);
    if(gtrack>2 && gtrack<13.5)
    {
        c+=2;
    	glViewport(-4000-(c/2),-14950,51200,28800);
    }
    if(gtrack>17 && gtrack<20.1)
    	glViewport(-4000-(c/2)-5+rand()%10,-14950-5+rand()%10,51200-5+rand()%10,28800-5+rand()%10);
    if(gtrack>=20.1 && gtrack<20.5)
    {
    	c0+=19;
    	glViewport(-4000-(c/2),-14950-c0,51200,28800);
    }
    if(gtrack>=20.5 && gtrack<24)
    {
    	if(vportx>1280&&vporty>720)
		{
			float xR=(xi+it0*0.69)*(40/pow(1.02,it0));
			float yR=(yi+it0*2.11)*(40/pow(1.02,it0));
			glViewport(xR,yR,vportx,vporty);
			vportx/=(1.02);
			vporty/=(1.02);
			it0++;
		}
	}
	if(gtrack>=25.4 && gtrack<=34)// taking a buffer of 0.2 
	{
		if(vpx<=51200&&vpy<=28800)
		{
			float xR=(-it1*3.9)*pow(1.02,it1);
			float yR=(-it1*2.83)*pow(1.02,it1);
			glViewport(xR,yR,vpx,vpy);
			vpx*=(1.02);
			vpy*=(1.02);
			it1++;
		}
	}
    if(gtrack>34){
        glViewport(-3850,-1100,25600,14400);
    }

}
void rand_generate_for_stars()
{
	int i1,i2;
	srand(time(0));
	for(i1=0;i1<110;i1++)
	{
		rand_stars1x[i1]=rand()%51200;
		rand_stars2x[i1]=rand()%51200;
		rand_stars3x[i1]=rand()%51200;
	}
	for(i1=0;i1<110;i1++)
	{
		rand_stars1y[i1]=rand()%28800;
		rand_stars2y[i1]=rand()%28800;
		rand_stars3y[i1]=rand()%28800;
	}
}
void story()
{
	if(gtrack>-10 && gtrack<-8.5){
        char c1[]="A Simple 2D Animation";
	    glPushMatrix();
            glColor3f(((rand()%(101))/100),(1.0-((rand()%(101))/100)),0.0);
	    //   glTranslatef(0,0,0);
	    //   glScalef(0.0f,0.0f,0);
        int l=strlen(c1);
  	    for (int i=0;i<l;i++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN , c1[i]);
	    glPopMatrix();
    }
    if(gtrack>-9 && gtrack<-7.5){
        char c2[]="Using OpenGL in C";
        glPushMatrix();
        //glColor(3f)
        glTranslatef(90,-240,0);
	    glScalef(1.0f,1.0f,0);
        if(gtrack>-8.5)
            glColor3f(((rand()%(110))/10),0.0,0.0);
        int l=strlen(c2);
  	    for (int i=0;i<l;i++)
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c2[i]);
	    glPopMatrix();
    }
    if(gtrack>-7.5 && gtrack<-6.5){
        char c3[]="In a Frictional Timeline";
        char c5[]=".";
        glPushMatrix();
	    glScalef(0.6f,0.6f,0);
        glColor3f(((rand()%(110))/10),0.0,0.0);
        int l1=strlen(c3);
  	    if(n<=l1){
            n+=1.0;
            for (int i=0;i<n;i++)
                glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c3[i]);
            for (int k=0;k<1;k++)
                glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c5[i]);
        glPopMatrix();
    }}
    if(gtrack>-7.0 && gtrack<-6.5){
	    char c4[]="A Man Decides to Go Mars";
        char c5[]=".";
        int l2=strlen(c4);
        glPushMatrix();
        glScalef(0.6f,0.6f,0);
        glColor3f(((rand()%(110))/10),0.0,0.0);
        glTranslatef(0,-200,0);
        if(p<=l2){
            p+=1.0;
                for (int i=0;i<p;i++)
                    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c4[i]);
                for(int k=0;k<1;k++)
                    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c5[i]);
            }
        glPopMatrix();
    }
    if(gtrack>-6.5 && gtrack<-3.5){
        char c3[]="In a Frictional Timeline";
        int l1=strlen(c3);
        glPushMatrix();
        glScalef(0.6f,0.6f,0);
        glColor3f(((rand()%(110))/10),0.0,0.0);
        for (int i=0;i<l1;i++)
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c3[i]);
        glPopMatrix();
    }
    if(gtrack>-6.5 && gtrack<-3.5){
        char c4[]="A Man Decides to Go Mars";
        char c5[]=".";
        int l2=strlen(c4);
        glPushMatrix();
        glScalef(0.6f,0.6f,0);
        glTranslatef(0,-200,0);glColor3f(((rand()%(110))/10),0.0,0.0);
        for (int i=0;i<l2;i++)
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c4[i]);
        for(int k=0;k<1;k++)
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , c5[i]);
        glPopMatrix();
    }


    if(gtrack>34 && gtrack<37){
        m+=0.005;
        char c7[]="The End";
        glPushMatrix();
        glColor3f(0.0+m,0.0+m,0.0+m);    
        glTranslatef(-280,-80,0);
	    glScalef(4.0f,4.0f,0);
        //printf("%f",)
        int l=strlen(c7);
  	    for (int i=0;i<l;i++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN , c7[i]);
        glPopMatrix();
    }
    if(gtrack>37 ){
        
        if(gtrack>37){
            char c18[]="HIMANGSHU KAKATI";
            glPushMatrix();
            glColor3f(((rand()%(101))/100),(1.0-((rand()%(101))/100)),0.0);
            if(gtrack>37 && gtrack <43){
                glTranslatef(0,(37-gtrack)*100,0);t1=(37-gtrack)*100;
            }
            else
                glTranslatef(0,t1,0);
            glScalef(1.5f,1.5f,0);
            int l=strlen(c18);
  	        for (int i=0;i<l;i++)
                glutStrokeCharacter(GLUT_STROKE_ROMAN , c18[i]);
            glPopMatrix();
        }
        if(gtrack>40){
            char c16[]="BHASKAR BORO";
            glPushMatrix();
            glColor3f(((rand()%(101))/100),(1.0-((rand()%(101))/100)),0.0);
            if(gtrack>40 && gtrack <43){
                glTranslatef(0,(40-gtrack)*100,0);t2=(40-gtrack)*100;
            }
            else
                glTranslatef(0,t2,0);
            glScalef(1.5f,1.5f,0);
            int l=strlen(c16);
  	        for (int i=0;i<l;i++)
                glutStrokeCharacter(GLUT_STROKE_ROMAN , c16[i]);
            glPopMatrix();
        } 
        if(gtrack>43){
            char c19[]="SUMAN BERA";
            glPushMatrix();
            glColor3f(((rand()%(101))/100),(1.0-((rand()%(101))/100)),0.0);
            if(gtrack>43 && gtrack <44){
                glTranslatef(0,(43-gtrack)*100,0);t3=(43-gtrack)*100;
            }
            else
                glTranslatef(0,t3,0);
            
            glScalef(1.5f,1.5f,0);
            int l=strlen(c19);
  	        for (int i=0;i<l;i++)
                glutStrokeCharacter(GLUT_STROKE_ROMAN , c19[i]);
            glPopMatrix();
        }
    }
}
//Main Function
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("A Man Goes To Mars");
    init();//	Initialization of the Animation
	rand_generate_for_stars();
    glutDisplayFunc(display); // Paints the Display
    glutTimerFunc(0, timer, 0);
    glutFullScreen(); // Uncomment for Full Screen
    glutMainLoop();
}
