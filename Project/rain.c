#include<GL/glut.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
int xmin=0,xmax=1280,ymin=0,ymax=720;
void init();
void snowfall(int x);
void fire(int x);
void ellipse(int xc,int yc,int Rx,int Ry,int x,float col1,float col2,float col3);
void circle(int xc,int yc, int R, int x,float col1,float col2,float col3);
void line(int x1,int y1,int x2,int y2,int x,float col1,float col2,float col3);
void display();
void asteroid(int x);
int refreshms=30;
GLint k=0;
int rand7[64][36],rand20[64][36];
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//asteroid(k);
	ellipse(300,300,150,100,k,1,1,0);
	//glPopMatrix;
	//glPushMatrix();
	//snowfall(k);
	//glPopMatrix();
	//glPushMatrix();
	//fire(1);
	glPopMatrix();  
	glutSwapBuffers();
	k+=6;
}
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1280.0,0.0,720.0);
}
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshms,timer,0);
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
void asteroid(int x)
{
	circle(300,300,100,x,0.2,0.2,0.2);
	for(int i=200;i<=400;i+=rand()%3)
		line((fabs(300-i))/0.3-140+rand()%70,i,300-rand()%50,i,x,1,1,0);
}
void fire(int x)
{
	//srand(time(0));
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	int l=95+rand()%10;
	glVertex2i(100,l);
	glVertex2i(150,200);
	glVertex2i(250,200);
	glVertex2i(300,l);
	glEnd();
}
void snowfall(int x)
{
	int p4,p1,p2,p3;
	glColor3f(1.0,1.0,1.0);
	p1=0;
	p4=0;
	for(p3=0;p3<ymax;p3+=20)
	{
		p1=0;
		for(p2=0;p2<xmax;p2+=20)
		{
			glPointSize(rand7[p1][p4]);
			glBegin(GL_POINTS);
			glVertex2i(p2+rand20[p1][p4],p3-x);
			glEnd();
			p1++;
		}
		p4++;
	}
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(5,5);
	glutInitWindowSize(1280,720);
	glutCreateWindow("SNOWFALL");
	init( );
	srand(time(0));
	int i1,i2;
	for(i2=0;i2<ymax/20;i2++)
	{
		for(i1=0;i1<xmax/20;i1++)
		{
			rand7[i1][i2]=rand()%7;
			rand20[i1][i2]=rand()%20;
		}
	}
	glutDisplayFunc(display);
	glutTimerFunc(0,timer,0);
	glutMainLoop( );
}
