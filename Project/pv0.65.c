#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h> 
#include<time.h>
//#define wsx 1280 //Windows Size x-Axis
//#define wsy 720 //Window Size y-Axis
#define PI 3.14
#define mar 3389// radius of the planets
#define er 6378
#define mor 1737
#define ery 12100     // Earth Ground Raiser y- Axis .no need to move x as centre of earth is (0,0) 
#define mrx 37400       // Mars Ground Raiser x-Axis
#define mry 18300       // Mars Ground Raiser y-Axis A sort of Shifter
#define roc 800
#define xmax 43000
#define xmin -8200
#define ymax 26000
#define ymin -2800
//Space for Global Varibles
GLfloat angle=0.0f;   // rotational angle of the shapes
int refreshms=30;     // refresh interval in milliseconds
GLdouble gtrack=0;
GLint i=0,j=0,k=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,tx=0,ty=0,c0=0;
GLint m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0;
float radius = 90;
GLint stopx=0,stopy=0,stopcx=-5500,stopcy=-14950;
GLfloat emer=0,eme=0,dg=0;
int rand_stars1x[110],rand_stars2x[110],rand_stars3x[110],rand_stars1y[110],rand_stars2y[110],rand_stars3y[110];
float twoPI = 2 * PI;
GLint px,py,cx,cy;
GLfloat dd=0,de=0;
void zoom();
void rand_generate_for_stars();
void house();
GLfloat vportx=51200,vporty=28800,xi=-129,yi=-393,it0=0;
GLfloat vpx=1280,vpy=720,it1=0;
GLfloat rocx=0,rocy=0;//rocket co-ordinates
GLfloat acc=0;//rocket acceleration
GLfloat Rcx=16000,Rcy=0,thetaR=0;//rocket circular path variables
// The Most Imp Function Our Camera :)
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
    //glClearColor(0.1,0.1,0.1,0.0);
    glClearColor(0.1,0.1,0.1,0.0);
    //glViewport(800,0,1280,720);
    //glColor3f(1.0,0.0,0.0);
    gluOrtho2D(-8200,43000,-2800,26000); // x 0 to 128000 y 0 to 64000
    //glViewport(0,0,1280,720);   
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
        //glEnable(GL_BLEND);glBlendFunc (0,0);
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
    glColor3f(0.0,0.3,1.0);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f((sin(t)*er),6000+(cos(t)*er));
    glEnd();
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
    //b=0;
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
    // glBegin(GL_LINES);//for the door
    //     glColor3f(0.0,0.0,0.0);
    //     glVertex2d(-1698,250+ery);
    //     glVertex2d(-1687,250+ery);
    //     glVertex2d(-1682,230+ery);
    //     glVertex2d(-1687,230+ery);
    // glEnd();
    // trees
    // glBegin(GL_POLYGON); 
    //     glColor3i(0.5,0.5,1.0);     //for the dead tree
    //     glVertex2d(785,230+ery);   //a  fixed
    //     glVertex2d(785,150+ery);   //b
    //     glVertex2d(815,150+ery);   //g
    //     glVertex2d(815,230+ery);   //h
    //     glVertex2d(830,250+ery);    
    //     glVertex2d(810,230+ery);
    //     glVertex2d(800,245+ery);
    //     glVertex2d(790,230+ery);   //d
    //     glVertex2d(760,250+ery);   //c
    // glEnd();
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
    glEnd();  // glPointSize(4);
    // glBegin(GL_POINT);
    //     glColor3i(1.0,1.5,1.0);
    //     glVertex2d(760+250,520-270+ery);
    // glEnd();
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
void groundmars(){
        //for the mountains
        //for 1st ahade
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

        //for the lines
        /*glColor3f(0.1,0.1,0.0);
        glBegin(GL_LINES);
            glVertex2d(100,400);
            glVertex2d(92,360);
            glVertex2d(120,300);
        glEnd();
*/

        //for the ground
        glColor3f(0.9,0.3,0.0);
        glBegin(GL_QUADS);
            glVertex2d(0+mrx,300+mry);
            glVertex2d(0+mrx,0+mry);
            glVertex2d(1280+mrx,0+mry);
            glVertex2d(1280+mrx,300+mry);
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
        //triangleAmount = 20;
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
        //GLfloat twicePi2() = 1.0f * 3.1416;

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
        //int triangleAmount = 20;
        int x3=650-400, y3=500, radius3=55;
        //GLfloat twicePi = 1.0f * 3.1416;

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
        //int triangleAmount = 20;
        int x51=700+350, y51=180+20, radius51=150;
        //GLfloat twicePi = 1.0f * 3.1416;

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
    glBegin(GL_QUADS);         //Main Rocket Body
        glColor3f(1.0,1.0,1.0);
        glVertex2i(roc+y-700+900,200+x+ery);
        glVertex2i(900-700+y+roc,450+x+ery);
        glVertex2i(1060-700+y+roc,450+x+ery);
        glVertex2i(1060-700+y+roc,200+x+ery);
    glEnd();
    glBegin(GL_QUADS);         //Main Rocket Body
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
     glBegin(GL_LINES);         //Stickman Figure with 5 degrees of freedom  Top-down is being followed
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
		glVertex2f(-2000+x+(30*cos(t*twoPI/triamount)),
			355+ery+(30*sin(t*twoPI/triamount)));
	}
	glEnd();

}
//The Main Display Functiom
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);     //Enabling the Color
    //glColor3f(1.0,0.0,0.0);          //Color RGB Red Green Blue
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    //glLoadIdentity();               // Reset the model-view matrix
    //Space for Static Polygons eg. ground
    // glEnable(GL_BLEND);
    // //glBlendFunc(0.7,0.3);
    // if(tx>-1700){
    //     d+=0.1;e+=0.1;glBlendFunc(0.6-d,0.2+d);
    //     glDisable(0.6-d,0.3+d);
    // }
    glPushMatrix();
    zoom();
    glPopMatrix();
    glPushMatrix();
    stars();
    glPopMatrix();
    glPushMatrix();
    ground();
    groundmars();
    glPopMatrix();
    //Space For Moving Objects
    glPushMatrix();
    rocket(rocx,rocy);
    glPopMatrix();
    if(gtrack>=0&&gtrack<15.3)
    {
    	glPushMatrix();
    	stickman(i,j);
    	glPopMatrix();
    }
    glPushMatrix();
    house();
    glPopMatrix(); 
    //glDisable(GL_BLEND);
    //The most imp place, Control Var here
    glutSwapBuffers();
    tx=-2000+i;
    //i=200;
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
    gtrack+=0.01;
}
void zoom()
{
    // literally it's not zoom its some sort of clipping but take it as zoom ok 
    //glViewport(-480,-680,2560,1440);    //10% zoom
    //glViewport(-2400,-3400,12800,7200);
    //glViewport(-3600,-5100,19200,10800);
    // if(track<-1800)
    //glViewport(-5500,-14950,51200,28800); // our starting pos FINAL starts at the bunker 
    //glViewport(-29000,-21100,51200,28800);  // the mars surface
    //glViewport(-100,-100,640,360);
    //glViewport(0,0,1280,720);
    
    
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
	if(gtrack>=25.4)
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
//Main Function
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("@title HERE");
    init();//	Initialization of the Animation
	rand_generate_for_stars();
    glutDisplayFunc(display); // Paints the Display
    glutTimerFunc(0, timer, 0);
    //glutFullScreen(); 
    glutMainLoop();
}
