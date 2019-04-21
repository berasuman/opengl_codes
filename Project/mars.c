#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void init(){
    glClearColor(0.0,0.0,0.0,0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0,1280,0,720);
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT);

        //for the mountains
        //for 1st ahade
        glColor3f(0.8,0.3,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(0,300);
            glVertex2d(0,330);
            glVertex2d(100,400);
            glVertex2d(380,310);
            glVertex2d(400,550);
            glVertex2d(730,300);
            glVertex2d(850,510);
            glVertex2d(1170,350);
            glVertex2d(1200,380);
            glVertex2d(1280,350);
            glVertex2d(1280,300);
        glEnd();
        glFlush();
        //for 2nd shade
        glColor3f(0.7,0.3,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(0,300);
            glVertex2d(0,330);
            glVertex2d(100,400);
            glVertex2d(120,360);
            glVertex2d(190,300);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(150,390);
            glVertex2d(400,550);
            glVertex2d(440,310);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(552,433);
            glVertex2d(850,510);
            glVertex2d(900,350);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(1125,372);
            glVertex2d(1200,380);
            glVertex2d(1250,310);
        glEnd();
        glFlush();
        //for the 3rd shade
        glColor3f(0.3,0.2,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(0,300);
            glVertex2d(0,330);
            glVertex2d(100,400);
            glVertex2d(92,360);
            glVertex2d(120,300);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(150,390);
            glVertex2d(300,482);
            glVertex2d(310,420);
            glVertex2d(440,310);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(552,433);
            glVertex2d(710,470);
            glVertex2d(900,350);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(1125,372);
            glVertex2d(1160,374);
            glVertex2d(1250,310);
        glEnd();
        glFlush();
        //for the lines
        /*glColor3f(0.1,0.1,0.0);
        glBegin(GL_LINES);
            glVertex2d(100,400);
            glVertex2d(92,360);
            glVertex2d(120,300);
        glEnd();
        glFlush();*/






        //for the ground
        glColor3f(0.9,0.3,0.0);
        glBegin(GL_QUADS);
            glVertex2d(0,300);
            glVertex2d(0,0);
            glVertex2d(1280,0);
            glVertex2d(1280,300);
        glEnd();
        glFlush();
        //for rocks on the ground
        glColor3f(0.7,0.3,0.0);
        glBegin(GL_POLYGON);
            glVertex2d(100,100);
            glVertex2d(200,150);
            glVertex2d(370,130);
            glVertex2d(600,170);
            glVertex2d(1000,100);
            glVertex2d(600,120);
            glVertex2d(370,100);
            glVertex2d(200,120);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(600,150);
            glVertex2d(800,180);
            glVertex2d(900,155);
            glVertex2d(1100,200);
            glVertex2d(1280,175);
            glVertex2d(1280,150);
        glEnd();
        glFlush();


















        //for the 1st tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600,200);
            glVertex2d(600,320);
            glVertex2d(700,320);
            glVertex2d(700,200);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595,320);
            glVertex2d(595,350);
            glVertex2d(705,350);
            glVertex2d(705,320);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(600,350);
            glVertex2d(600,470);
            glVertex2d(700,470);
            glVertex2d(700,350);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595,470);
            glVertex2d(595,500);
            glVertex2d(705,500);
            glVertex2d(705,470);
        glEnd();
        glFlush();
        //for the dome
        int i;
        int triangleAmount = 20;
        int x=650, y=500, radius=55;
        GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        //for the lines
        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595,470);
            glVertex2d(705,470);
            glVertex2d(595,320);
            glVertex2d(705,320);
            glVertex2d(595,350);
            glVertex2d(705,350);
            glVertex2d(600,350);
            glVertex2d(600,470);
            glVertex2d(615,350);
            glVertex2d(615,470);
            glVertex2d(630,350);
            glVertex2d(630,470);
            glVertex2d(647,350);
            glVertex2d(647,470);
            glVertex2d(665,350);
            glVertex2d(665,470);
            glVertex2d(687,350);
            glVertex2d(687,470);
            glVertex2d(700,350);
            glVertex2d(700,470);
            glVertex2d(600,350-150);
            glVertex2d(600,470-150);
            glVertex2d(615,350-150);
            glVertex2d(615,470-150);
            glVertex2d(630,350-150);
            glVertex2d(630,470-150);
            glVertex2d(647,350-150);
            glVertex2d(647,470-150);
            glVertex2d(665,350-150);
            glVertex2d(665,470-150);
            glVertex2d(687,350-150);
            glVertex2d(687,470-150);
            glVertex2d(700,350-150);
            glVertex2d(700,470-150);
        glEnd();
        glFlush();



         //for the 2nd tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600-200,200);
            glVertex2d(600-200,320);
            glVertex2d(700-200,320);
            glVertex2d(700-200,200);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595-200,320);
            glVertex2d(595-200,350);
            glVertex2d(705-200,350);
            glVertex2d(705-200,320);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(600-200,350);
            glVertex2d(600-200,470);
            glVertex2d(700-200,470);
            glVertex2d(700-200,350);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595-200,470);
            glVertex2d(595-200,500);
            glVertex2d(705-200,500);
            glVertex2d(705-200,470);
        glEnd();
        glFlush();
        //for the dome
        int i1;
        //triangleAmount = 20;
        int x1=650-200, y1=500, radius1=55;
        //GLfloat twicePi2() = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595-200,470);
            glVertex2d(705-200,470);
            glVertex2d(595-200,320);
            glVertex2d(705-200,320);
            glVertex2d(595-200,350);
            glVertex2d(705-200,350);
            glVertex2d(600-200,350);
            glVertex2d(600-200,470);
            glVertex2d(615-200,350);
            glVertex2d(615-200,470);
            glVertex2d(630-200,350);
            glVertex2d(630-200,470);
            glVertex2d(647-200,350);
            glVertex2d(647-200,470);
            glVertex2d(665-200,350);
            glVertex2d(665-200,470);
            glVertex2d(687-200,350);
            glVertex2d(687-200,470);
            glVertex2d(700-200,350);
            glVertex2d(700-200,470);
            glVertex2d(600-200,350-150);
            glVertex2d(600-200,470-150);
            glVertex2d(615-200,350-150);
            glVertex2d(615-200,470-150);
            glVertex2d(630-200,350-150);
            glVertex2d(630-200,470-150);
            glVertex2d(647-200,350-150);
            glVertex2d(647-200,470-150);
            glVertex2d(665-200,350-150);
            glVertex2d(665-200,470-150);
            glVertex2d(687-200,350-150);
            glVertex2d(687-200,470-150);
            glVertex2d(700-200,350-150);
            glVertex2d(700-200,470-150);
        glEnd();
        glFlush();


        //for the 3rd tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600+200,200);
            glVertex2d(600+200,320);
            glVertex2d(700+200,320);
            glVertex2d(700+200,200);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595+200,320);
            glVertex2d(595+200,350);
            glVertex2d(705+200,350);
            glVertex2d(705+200,320);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(600+200,350);
            glVertex2d(600+200,470);
            glVertex2d(700+200,470);
            glVertex2d(700+200,350);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595+200,470);
            glVertex2d(595+200,500);
            glVertex2d(705+200,500);
            glVertex2d(705+200,470);
        glEnd();
        glFlush();
        //for the dome
        int i2;
        //triangleAmount = 20;
        int x2=650+200, y2=500, radius2=55;
        //GLfloat twicePi2() = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2);
		for(i2 = 0; i2 <= triangleAmount;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(i2 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595+200,470);
            glVertex2d(705+200,470);
            glVertex2d(595+200,320);
            glVertex2d(705+200,320);
            glVertex2d(595+200,350);
            glVertex2d(705+200,350);
            glVertex2d(600+200,350);
            glVertex2d(600+200,470);
            glVertex2d(615+200,350);
            glVertex2d(615+200,470);
            glVertex2d(630+200,350);
            glVertex2d(630+200,470);
            glVertex2d(647+200,350);
            glVertex2d(647+200,470);
            glVertex2d(665+200,350);
            glVertex2d(665+200,470);
            glVertex2d(687+200,350);
            glVertex2d(687+200,470);
            glVertex2d(700+200,350);
            glVertex2d(700+200,470);
            glVertex2d(600+200,350-150);
            glVertex2d(600+200,470-150);
            glVertex2d(615+200,350-150);
            glVertex2d(615+200,470-150);
            glVertex2d(630+200,350-150);
            glVertex2d(630+200,470-150);
            glVertex2d(647+200,350-150);
            glVertex2d(647+200,470-150);
            glVertex2d(665+200,350-150);
            glVertex2d(665+200,470-150);
            glVertex2d(687+200,350-150);
            glVertex2d(687+200,470-150);
            glVertex2d(700+200,350-150);
            glVertex2d(700+200,470-150);
        glEnd();
        glFlush();


        //for the 4th tower type houses
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
            glVertex2d(600-400,200);
            glVertex2d(600-400,320);
            glVertex2d(700-400,320);
            glVertex2d(700-400,200);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595-400,320);
            glVertex2d(595-400,350);
            glVertex2d(705-400,350);
            glVertex2d(705-400,320);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(600-400,350);
            glVertex2d(600-400,470);
            glVertex2d(700-400,470);
            glVertex2d(700-400,350);
        glEnd();
        glFlush();
        glBegin(GL_POLYGON);
            glVertex2d(595-400,470);
            glVertex2d(595-400,500);
            glVertex2d(705-400,500);
            glVertex2d(705-400,470);
        glEnd();
        glFlush();
        //for the dome
        int i3;
        //int triangleAmount = 20;
        int x3=650-400, y3=500, radius3=55;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3);
		for(i3 = 0; i3 <= triangleAmount;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi / triangleAmount)),
			    y3 + (radius3 * sin(i3 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        //for the lines
        glColor3f(0.2,0.2,0.2);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2d(595-400,470);
            glVertex2d(705-400,470);
            glVertex2d(595-400,320);
            glVertex2d(705-400,320);
            glVertex2d(595-400,350);
            glVertex2d(705-400,350);
            glVertex2d(600-400,350);
            glVertex2d(600-400,470);
            glVertex2d(615-400,350);
            glVertex2d(615-400,470);
            glVertex2d(630-400,350);
            glVertex2d(630-400,470);
            glVertex2d(647-400,350);
            glVertex2d(647-400,470);
            glVertex2d(665-400,350);
            glVertex2d(665-400,470);
            glVertex2d(687-400,350);
            glVertex2d(687-400,470);
            glVertex2d(700-400,350);
            glVertex2d(700-400,470);
            glVertex2d(600-400,350-150);
            glVertex2d(600-400,470-150);
            glVertex2d(615-400,350-150);
            glVertex2d(615-400,470-150);
            glVertex2d(630-400,350-150);
            glVertex2d(630-400,470-150);
            glVertex2d(647-400,350-150);
            glVertex2d(647-400,470-150);
            glVertex2d(665-400,350-150);
            glVertex2d(665-400,470-150);
            glVertex2d(687-400,350-150);
            glVertex2d(687-400,470-150);
            glVertex2d(700-400,350-150);
            glVertex2d(700-400,470-150);
        glEnd();
        glFlush();




        //for the 1st dome type hoouses
        glColor3f(0.7,0.9,0.7);
        int i4;
        //int triangleAmount = 20;
        int x4=700, y4=180, radius4=200;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4);
		for(i4 = 0; i4 <= triangleAmount;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi / triangleAmount)),
			    y4 + (radius4 * sin(i4 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        //for the inner circle
        glColor3f(0.8,0.8,0.9);
        int i41;
        //int triangleAmount = 20;
        int x41=700, y41=180, radius41=170;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x41, y41);
		for(i41 = 0; i41 <= triangleAmount;i41++) {
			glVertex2f(
		            x41 + (radius41 * cos(i41 *  twicePi / triangleAmount)),
			    y41 + (radius41 * sin(i41 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        //for the line
        glColor3f(1.0,1.0,1.0);
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glVertex2d(700,180);
            glVertex2d(700,350);
        glEnd();
        glFlush();



        //for the 2nd dome type hoouses
        glColor3f(0.7,0.9,0.7);
        int i5;
        //int triangleAmount = 20;
        int x5=700+350, y5=180+20, radius5=180;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5);
		for(i5 = 0; i5 <= triangleAmount;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi / triangleAmount)),
			    y5 + (radius5 * sin(i5 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        //for the inner circle
        glColor3f(0.8,0.8,0.9);
        int i51;
        //int triangleAmount = 20;
        int x51=700+350, y51=180+20, radius51=150;
        //GLfloat twicePi = 1.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x51, y51);
		for(i51 = 0; i51 <= triangleAmount;i51++) {
			glVertex2f(
		            x51 + (radius51 * cos(i51 *  twicePi / triangleAmount)),
			    y51 + (radius51 * sin(i51 * twicePi / triangleAmount))
			);
		}
        glEnd();
        glFlush();
        //for the line
        glColor3f(1.0,1.0,1.0);
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glVertex2d(700+350,180+20);
            glVertex2d(700+350,350);
        glEnd();
        glFlush();








        //for the vehicle
        //for the main part
        glColor3f(0.7,0.5,0.1);
        glBegin(GL_POLYGON);
            glVertex2d(100*2-50,150*2-150);
            glVertex2d(100*2-50,200*2-150);
            glVertex2d(120*2-50,250*2-150);
            glVertex2d(220*2+50,250*2-150);
            glVertex2d(240*2+50,200*2-150);
            glVertex2d(240*2+50,150*2-150);
        glEnd();
        glFlush();
        //for the wheels
        glColor3f(0.1,0.1,0.1);
            int i7;
        int triangleAmount7 = 20;
        int x7=240, y7=150, radius7=50;
        GLfloat twicePi7 = 2.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7);
		for(i7 = 0; i7 <= triangleAmount;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount))
			);
		}
        glEnd();
        glFlush();

        int i8;
        int triangleAmount8 = 20;
        int x8=450, y8=150, radius8=50;
        GLfloat twicePi8 = 2.0f * 3.1416;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(i8 = 0; i8 <= triangleAmount;i8++) {
			glVertex2f(
		            x8+ (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
        glEnd();
        glFlush();

        //for the windows
        glColor3f(0.1,0.3,0.5);
        glBegin(GL_POLYGON);
            glVertex2d(430,200+50);
            glVertex2d(430,230+100);
            glVertex2d(490,230+100);
            glVertex2d(520,200+50);
        glEnd();
        glFlush();

        //for the middle part
        glColor3f(0.5,0.6,0.2);
        glBegin(GL_POLYGON);
            glVertex2d(250,330);
            glVertex2d(250,370);
            glVertex2d(400,370);
            glVertex2d(400,330);
        glEnd();
        glFlush();





}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("Moon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}