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
#define sur 12100
#define roc 800
#define xmax 43000
#define xmin -8200
#define ymax 26000
#define ymin -2800
//Space for Global Varibles
GLfloat angle=0.0f;   // rotational angle of the shapes
int refreshms=30;     // refresh interval in milliseconds
GLint i=0,j=0,k=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,tx=0,ty=0;
GLint m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0;
float radius = 40;
GLint stopx=0,stopy=0,stopcx=-5500,stopcy=-14950;
GLfloat emer=0,eme=0,dg=0;
int rand_stars1x[110],rand_stars2x[110],rand_stars3x[110],rand_stars1y[110],rand_stars2y[110],rand_stars3y[110];
float twoPI = 2 * PI;
GLint px,py,cx,cy;
GLfloat dd=0,de=0;
void zoom(int x,int y,int track);

// The Most Imp Function Our Camera :)

//Utlity Functions Begins
//Timer Function. Repeated Callbacks Occurs here
void timer(int value) 
{
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshms, timer, 0); // next timer call milliseconds later
}
void ellipse(int xc,int yc,int Rx,int Ry,int x,float col1,float col2,float col3)
{
	glBegin(GL_POLYGON);
	glColor3f(col1,col2,col3);
	for(float t=0;t<=6.29;t+=0.001)
		glVertex2i(xc+(cos(t)*Rx)+x,yc+(sin(t)*Ry));
	glEnd();
}
void circle(int xc,int yc,int R,int x,float col1,float col2,float col3)
{
	glBegin(GL_POLYGON);
	glColor3f(col1,col2,col3);
	for(float t=0;t<=6.29;t+=0.001)
		glVertex2i(xc+(cos(t)*R)+x,yc+(sin(t)*R));
	glEnd();
}
void line(int x1,int y1,int x2,int y2,int x,float col1,float col2,float col3)
{
	glBegin(GL_LINES);
	glColor3f(col1,col2,col3);
	glVertex2i(x1+x,y1);
	glVertex2i(x2+x,y2);
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
//Planets and Grounds Functions
void ground(){
    //circle of Earth
    glBegin(GL_POLYGON);// the earth circle
    glColor3f(0.0,0.4,0.0);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f((sin(t)*er),6000+(cos(t)*er));
    glEnd();
    //Objects on Earth
    glBegin(GL_QUADS);       //Ground on Earth & Moon 
        glColor3f(0.0,1.0,0.3);
        glVertex2i(-2000,0+sur);
        glVertex2i(-2000,150+sur);
        glVertex2i(2000,150+sur);
        glVertex2i(2000,0+sur);
    glEnd();
    // the Bunker on Earth.
    glBegin(GL_QUADS);//for the roof
        glColor3f(0.4,0.4,0.4);
        glVertex2i(-2000,430+sur);
        glVertex2i(-2000,400+sur);
        glVertex2i(-1700+20,400+sur);
        glVertex2i(-1700+20,430+sur);
    glEnd();

    glBegin(GL_QUADS);//for house
        //glEnable(GL_BLEND);glBlendFunc (0,0);
        glColor4f(0.2,0.2,0.2,0.8);
        glVertex2i(-1990,400+sur);
        glVertex2i(-1990,150+sur);
        glVertex2i(-1700,150+sur);
        glVertex2i(-1700,400+sur);
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
        glVertex2i(-1700,390+sur);
        glVertex2i(-1700,150+sur);
        glVertex2i(-1685+a,150+sur);
        glVertex2i(-1685+a,390+sur);
    glEnd();

    glBegin(GL_LINES);//for the door knob
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

//Rocket Function
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
        glColor3f(1.0,0.0,0.5);
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
// void stick(int x,int y){
//     glLineWidth(5.0);
//     glBegin(GL_LINES);         //Stickman Figure with 5 degrees of freedom  Top-down is being followed
//         glColor3f(0.0,0.0,0.0);

//         glVertex2i(-2000+i,230+sur);        //torso
//         glVertex2i(-2000+j,330+sur);

//         glVertex2i(-2000+i,310+sur);        //Obvious left hand
//         glVertex2i(-2050+j+i,230+sur);

//         glVertex2i(-2000+i,310+sur);        //right hand
//         glVertex2i(-1950-j+i,230+sur);

//         glVertex2i(-2000+i,230+sur);        //Assumed left leg
//         glVertex2i(-2050+j+i,150+sur);

//         glVertex2i(-2000+i,230+sur);        //right leg
//         glVertex2i(-1950-j+i,150+sur);

//     glEnd();
// }
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
    zoom(i,j,tx);
    glPopMatrix();
    glPushMatrix();
    stars();
    glPopMatrix();
    glPushMatrix();
    ground();

    glPopMatrix();  
    //Space For Moving Objects
    glPushMatrix();  // ground push

    rocket(k);
    glPopMatrix(); 

    glPushMatrix();  // rocket push
    // the stickman direct code for the tracker control var. me(chaos7) is tying the figure 
    //with the torso
    //stick(i,j);
    glLineWidth(5.0);
    glBegin(GL_LINES);         //Stickman Figure with 5 degrees of freedom  Top-down is being followed
        if(tx>-1700){
            //glEnable(GL_BLEND);
            glColor3f(0.0,0.0,0.0);
        }
        else{
        
        glColor3f(0.2,0.2,0.2);
        //glColor3f(0.0,0.0,0.0);
        }
        glVertex2i(-2000+i,230+sur);        //torso
        glVertex2i(-2000+i,330+sur);

        glVertex2i(-2000+i,310+sur);        //Obvious left hand
        glVertex2i(-2050+j+i,230+sur);

         glVertex2i(-2000+i,310+sur);        //right hand
         glVertex2i(-1950-j+i,230+sur);

        glVertex2i(-2000+i,230+sur);        //Assumed left leg
        glVertex2i(-2050+j+i,150+sur);

         glVertex2i(-2000+i,230+sur);        //right leg
         glVertex2i(-1950-j+i,150+sur);

    glEnd();
    glBegin(GL_POLYGON);// the earth circle
    glColor3f(0.,0.0,0.0);
    // for (float t = 0; t <= 20; t += 0.001)
    //     glVertex2f(-2000+i+(sin(t)*40),(cos(t)*40)+sur+350);
    // glEnd();
    int triamount=20;
	for(t=0;t<= triamount;t++){
		glVertex2f(-2000+i+(30*cos(t*twoPI/triamount)),
			355+sur+(30*sin(t*twoPI/triamount)));
	}
	glEnd();
    glPopMatrix();
    //glDisable(GL_BLEND);
    //The most imp place, Control Var here
    glutSwapBuffers();
    tx=-2000+i;
    //i=200;
    i+=2;
        j+=2.5;
        if(j==100)
            j=0;
    
}
void zoom(int x,int y,int track)
{
    // literally it's not zoom its some sort of clipping but take it as zoom ok 
    //glViewport(-480,-680,2560,1440);    //10% zoom
    //glViewport(-240,-340,1280,720); // full view 0% zoom
    //glViewport(-720,-1020,3840,2160); 
    //glViewport(-960,-1360,5120,2880);
    glViewport(-2400,-3400,12800,7200);
    glViewport(-3600,-5100,19200,10800);
    // if(track<-1800)
    //glViewport(-5500,-14950,51200,28800);
    //glViewport(-2750,-7475,25600,14400);
    //glViewport(0,0,640,360);
    // if(track>-2000){
    //     dg+=3.2;
    //     emer+=1.8;
    //     glViewport(0,0,320+dg,emer+180);
    // }
    //glViewport(-100,-100,640,360);
    //glViewport(0,0,1280,720);
    // if(track>=-1800){
    //     c+=2;
    //  glViewport(-4000-(c/2),-14950,51200,28800);}
    // }
        // emer+=711;
        // eme+=400;
        // dg+=1;
        // stopx=51200-emer;
        // stopy=28800-eme;
        // // stopcx=-5500;
        // stopcy=-14950;//+(dg*3);
        // if((stopx>1280 || stopy>720) || stopcx<=0&&stopcy<=0){
        // glViewport(stopcx+=dg,stopcy+=2.0*dg,stopx,stopy);
        // printf("stopcx :%d stopcy:%d stopx %d stopy %d\n", stopcx,stopcy,stopx,stopy);
        // }
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
    glutDisplayFunc(display); // Paints the Display
    glutTimerFunc(0, timer, 0);
    //glutFullScreen(); 
    glutMainLoop();
}