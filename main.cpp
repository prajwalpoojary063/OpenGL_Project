#include <GL/glut.h>
#include<math.h>
#include<String.h>
#include<stdlib.h>


float p,q,r,s,m1,m2,m3,m4,m5,m6,c,i,a,d1,d2,d3,d4;  //global variables
int idle_v=0,ax,bx,cx,nax,nbx,mx=-200,ncx,final,chain_x=-400,zx,tx,t_text=-100;
void *fonts[]={
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_12,
GLUT_BITMAP_HELVETICA_10,
GLUT_BITMAP_HELVETICA_18,
};

void chain();
void human(float x,float y,float z,float a[]);


void initOpenGl(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,700,0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

void output(char *w,int j)							//function to display Text
{
        int k;
        for(k=0;k<strlen(w);k++)
            glutBitmapCharacter(fonts[j],w[k]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void key_a(char *w){								//Next KEY display function
	glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(100.0,450.0,0.0);
	output(w,2);
    glPopMatrix();
    glBegin(GL_POLYGON);		//black cover
	glColor3f(0.8,1,1);
	glVertex2i(50+ax-nax,440);
	glVertex2i(280,440);
	glVertex2i(280,480);
	glVertex2i(50+ax-nax,480);
	glEnd();
}
void key_b(char *w){								//Next KEY display function
	glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(100.0,380.0,0.0);
	output(w,2);
    glPopMatrix();
    glBegin(GL_POLYGON);		//black cover
	glColor3f(0.8,1,1);
	glVertex2i(50+bx-nbx,370);
	glVertex2i(280,370);
	glVertex2i(280,395);
	glVertex2i(50+bx-nbx,395);
	glEnd();
}
void key_c(char *w){								//Next KEY display function
	glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(100.0,450.0,0.0);
	output(w,2);
    glPopMatrix();
    glBegin(GL_POLYGON);		//black cover
	glColor3f(0.8,1,1);
	glVertex2i(50+cx-ncx,440);
	glVertex2i(280,440);
	glVertex2i(280,480);
	glVertex2i(50+cx-ncx,480);
	glEnd();
}
void message1(char *w){
	glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(mx,250,0.0);
	output(w,2);
    glPopMatrix();
}
void message2(char *w){
	while(q>220){
		glColor3f(0.0,0.0,0.0);			//text background
		glBegin(GL_POLYGON);
		glVertex2i(25,255);
		glVertex2i(285,255);
		glVertex2i(285,275);
		glVertex2i(25,275);
		glEnd();
		glColor3f(1.0,1.0,1.0);				//text 
	    glPushMatrix();
	    glRasterPos3f(mx,260,0.0);
		output(w,5);
	    glPopMatrix();
		break;
	}
    
    while(m5>50){					//chain
		chain();
		break;
	}
	glColor3f(0.6,0.7,0.6);    //chain blink scene
	glBegin(GL_POLYGON);
	glVertex2i(120+chain_x,220);
	glVertex2i(250+chain_x,220);
	glVertex2i(250+chain_x,240);
	glVertex2i(120+chain_x,240);
	glEnd();
	 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void intro(){														//***Intro slide***
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);	//white background
	glVertex2i(0,0);
	glVertex2i(700,0);
	glVertex2i(700,500);
	glVertex2i(0,500);
	glEnd();
	
	glBegin(GL_POLYGON);		//black background
	glColor3f(1.0,1.0,1.0);
	glVertex2i(5,5);
	glVertex2i(695,5);
	glVertex2i(695,495);
	glVertex2i(5,495);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);			//white background
	glVertex2i(10,10);
	glVertex2i(690,10);
	glVertex2i(690,490);
	glVertex2i(10,490);
	glEnd();
	
	
	
	//INTRO background DESIGNS
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex2i(10,100);
	glVertex2i(310,100);
	glVertex2i(310,105);
	glVertex2i(10,105);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(341,10);
	glVertex2i(346,10);
	glVertex2f(690,295.5);
	glVertex2i(690,300);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex2i(300,100);
	glVertex2i(450,100);
	glVertex2i(690,300);
	glVertex2i(690,400);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(300,100);
	glVertex2i(330,100);
	glVertex2i(690,370);
	glVertex2i(690,400);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(390,380);
	glVertex2i(560,490);
	glVertex2i(540,490);
	glVertex2i(400,400);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex2i(400,380);
	glVertex2i(570,490);
	glVertex2i(550,490);
	glVertex2i(410,400);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(140,380);
	glVertex2i(370,490);
	glVertex2i(340,490);
	glVertex2i(150,400);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.7,1.0);
	glVertex2i(150,380);
	glVertex2i(370,490);
	glVertex2i(350,490);
	glVertex2i(160,400);
	glEnd();
	
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(600,400,0);
	glutSolidSphere(50,50,200);
	glPopMatrix();
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(600,400,0);
	glutSolidSphere(45,45,200);
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2i(580,355);
	glVertex2i(620,445);
	glVertex2i(616,447);
	glVertex2i(576,357);
	glEnd();

	//STATEMENTS
	glColor3f(0.0,1.0,0.0);   
	glPushMatrix();
    glRasterPos3f(575.0,405.0,0.0);
	output("CORONA",2);
    glPopMatrix();
    glPushMatrix();
    glRasterPos3f(580.0,385.0,0.0);
	output("VIRUS",2);
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(575.9,405.0,0.0);
	output("CORONA",2);
    glPopMatrix();
    glPushMatrix();
    glRasterPos3f(580.9,385.0,0.0);
	output("VIRUS",2);
    glPopMatrix();
	
	glBegin(GL_POLYGON);		//HEADING BACKGROUND
	glColor3f(1.0,1.0,1.0);
	glVertex2i(60,340);
	glVertex2i(490,340);
	glVertex2i(490,380);
	glVertex2i(60,380);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex2i(70,335);
	glVertex2i(500,335);
	glVertex2i(500,355);
	glVertex2i(70,355);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.7,1.0);
	glVertex2i(70,355);
	glVertex2i(500,355);
	glVertex2i(500,375);
	glVertex2i(70,375);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);   
    glPushMatrix();
    glRasterPos3f(100.0,360.0,0.0);
	output("MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING",2);
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(140.0,340.0,0.0);
	output("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",5);
    glPopMatrix();
    
    glColor3f(0.8,0.4,0.4);
    glPushMatrix();
    glRasterPos3f(180,300.0,0.0);
	output("CG MINI PROJECT ON ",5);
    glPopMatrix();
    
    glColor3f(0.0,1.0,0.0);
    glPushMatrix();
    glRasterPos3f(59,280.0,0.0);
	output("\"USE OF SOCIAL DISTANCING IN PREVENTING CORONA VIRUS\"",2);
    glPopMatrix();
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(58.5,280.0,0.0);
	output("\"USE OF SOCIAL DISTANCING IN PREVENTING CORONA VIRUS\"",2);
    glPopMatrix();
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(58.0,280.0,0.0);
	output("\"USE OF SOCIAL DISTANCING IN PREVENTING CORONA VIRUS\"",2);
    glPopMatrix();
    
    glColor3f(0.8,0.4,0.4);
    glPushMatrix();
    glRasterPos3f(170.0,240.0,0.0);
	output("UNDER THE GUIDANCE OF ",5);
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(175.0,220.0,0.0);
	output("MS.AISHWARYA M BHAT",5);
    glPopMatrix();
    
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(189.0,200.0,0.0);
	output("MS.SUNITHA N V",5);
    glPopMatrix();
    
    
    glColor3f(0.8,0.4,0.4);
    glPushMatrix();
    glRasterPos3f(480.0,100.0,0.0);
	output("TEAM MEMBERS :",5);
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(500.0,70.0,0.0);
	output("PRAJWAL POOJARY 4MT18CS063",5);
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(500.0,50.0,0.0);
	output("SUMAN                        4MT18CS104",5);
    glPopMatrix();
    
    glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2i(80,40);
	glVertex2i(220,40);
	glVertex2i(220,70);
	glVertex2i(80,70);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex2i(90,40);
	glVertex2i(210,40);
	glVertex2i(210,70);
	glVertex2i(90,70);
	glEnd();
	
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(100.0,50.0,0.0);
	output("PRESS  S  TO START ",5);
    glPopMatrix();
    
    
    glFlush();
    glutSwapBuffers();
}
void instruct(){
	
	float hc[]={0.2,0.4,0.1};
	float ic[]={0.9,0.0,0.0};
	
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2i(100,100);
	glVertex2i(600,100);
	glVertex2i(600,390);
	glVertex2i(100,390);
	glEnd();
	
	human(250,350,0,hc);
	human(250,220,0,ic);
	
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
    glRasterPos3f(300.0,370.0,0.0);
	output("\"INSTRUCTIONS\"",2);
    glPopMatrix();
    glPushMatrix();
    glRasterPos3f(380.0,300.0,0.0);
	output("HEALTHY PERSON",5);
    glPopMatrix();
    glPushMatrix();
    glRasterPos3f(380.0,170.0,0.0);
	output("INFECTED PERSON",5);
    glPopMatrix();
    
    glColor3f(1.0,1.0,0.0);
    glPushMatrix();
    glRasterPos3f(550.0,70.0,0.0);
	output("Press N for NEXT ",2);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void end(){
	
	glClearColor(0.0,0,0,0);
	
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex2i(70,20);
	glVertex2i(630,20);
	glVertex2i(630,480);
	glVertex2i(70,480);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2i(80,30);
	glVertex2i(620,30);
	glVertex2i(620,470);
	glVertex2i(80,470);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2i(90,40);
	glVertex2i(610,40);
	glVertex2i(610,460);
	glVertex2i(90,460);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2i(100,50);
	glVertex2i(600,50);
	glVertex2i(600,450);
	glVertex2i(100,450);
	glEnd();
	
	glColor3f(0,0,0);
	int x=340;
	int y=200;
	int i;
	float twicePi = 2.0 *3.14;
	int triangleAmount = 30;
	float radius=100;
	for(i = 0; i <=triangleAmount;i++) { 
		glPointSize(3);	
		glBegin(GL_POINTS);
		glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		glEnd();
	}
	
	float hc[]={0.2,0.4,0.1};
	float ic[]={0.9,0.0,0.0};
	human(230,280,0,hc);
	human(450,280,0,hc);
	human(340,180,0,ic);
	
	glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glRasterPos3f(230.0,380.0,0.0);
	output("\"ONLY I AND U CAN BREAK THE CHAIN\"",2);
    glPopMatrix();
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(230.5,380.0,0.0);
	output("\"ONLY I AND U CAN BREAK THE CHAIN\"",2);
    glPopMatrix();
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(280.0,360.0,0.0);
	output("SO BE SOCIALLY RESPONSIBLE",5);
    glPopMatrix();
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(280.5,360.0,0.0);
	output("SO BE SOCIALLY RESPONSIBLE",5);
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(480.5,100.0,0.0);
	output("Press Z for next",2);
    glPopMatrix();
	glBegin(GL_POLYGON);      //cover
	glColor3f(1.0,1.0,1.0);
	glVertex2i(400+zx,90);
	glVertex2i(570,90);
	glVertex2i(570,120);
	glVertex2i(400+zx,120);
	glEnd();
	
	glPushMatrix();
	glTranslatef(tx,0,0);
	glBegin(GL_POLYGON);      //cover
	glColor3f(0.0,0.0,0.0);
	glVertex2i(-350,0);
	glVertex2i(0,0);
	glVertex2i(0,500);
	glVertex2i(-350,500);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-tx,0,0);
	glBegin(GL_POLYGON);      //cover
	glColor3f(0.0,0.0,0.0);
	glVertex2i(700,0);
	glVertex2i(1050,0);
	glVertex2i(1050,500);
	glVertex2i(700,500);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(tx,0,0);
	glBegin(GL_POLYGON);      //cover
	glColor3f(1.0,0.6,0.0);
	glVertex2i(-115,220);
	glVertex2i(0,220);
	glVertex2i(0,280);
	glVertex2i(-115,280);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-tx,0,0);
	glBegin(GL_POLYGON);      //cover
	glColor3f(1.0,0.6,0.0);
	glVertex2i(700,220);
	glVertex2i(800,220);
	glVertex2i(800,280);
	glVertex2i(700,280);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
    glRasterPos3f(t_text,245.0,0.0);
	output("\"THANK YOU\"",2);
    glPopMatrix();
	glFlush();
    glutSwapBuffers();
}

void chain()
{
	glBegin(GL_POLYGON);      //chain1
	glColor3f(0.0,0.0,0.0);
	glVertex2i(142,230);
	glVertex2i(157,230);
	glVertex2i(157,240);
	glVertex2i(142,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);			//sphere1
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(144,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere2
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(144,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere3
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(155,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere4
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(155,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glBegin(GL_POLYGON);      //inside chain1
	glColor3f(1.0,1.0,1.0);
	glVertex2i(144,232);
	glVertex2i(155,232);
	glVertex2i(155,238);
	glVertex2i(144,238);
	glEnd();
	
	glBegin(GL_POLYGON);      //chain//
	glColor3f(0.0,0.0,0.0);
	glVertex2i(146,234);
	glVertex2i(138,234);
	glVertex2i(138,236);
	glVertex2i(146,236);
	glEnd(); 
	
	glBegin(GL_POLYGON);      //chain2
	glColor3f(0.0,0.0,0.0);
	glVertex2i(160,230);
	glVertex2i(175,230);
	glVertex2i(175,240);
	glVertex2i(160,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);			//sphere1
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(162,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere2
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(162,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere3
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(173,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere4
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(173,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glBegin(GL_POLYGON);      //inside chain2
	glColor3f(1.0,1.0,1.0);
	glVertex2i(162,232);
	glVertex2i(173,232);
	glVertex2i(173,238);
	glVertex2i(162,238);
	glEnd();
	
	glBegin(GL_POLYGON);      //chain//
	glColor3f(0.0,0.0,0.0);
	glVertex2i(151,234);
	glVertex2i(166,234);
	glVertex2i(166,236);
	glVertex2i(151,236);
	glEnd(); 
		
	
	glBegin(GL_POLYGON);      //chain3
	glColor3f(0.0,0.0,0.0);
	glVertex2i(178,230);
	glVertex2i(187,230);
	glVertex2i(187,240);
	glVertex2i(178,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);			//sphere1
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(180,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere2
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(180,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	
	glBegin(GL_POLYGON);      //inside chain3
	glColor3f(1.0,1.0,1.0);
	glVertex2i(180,232);
	glVertex2i(187,232);
	glVertex2i(187,238);
	glVertex2i(180,238);
	glEnd();
	
	glBegin(GL_POLYGON);      //chain//
	glColor3f(0.0,0.0,0.0);
	glVertex2i(170,234);
	glVertex2i(183,234);
	glVertex2i(183,236);
	glVertex2i(170,236);
	glEnd(); 
	
	glBegin(GL_POLYGON);      //broken chain1
	glColor3f(0.0,0.0,0.0);
	glVertex2i(189,231);
	glVertex2i(189,231);
	glVertex2i(192,233);
	glVertex2i(189,233);
	glEnd();
	
	glBegin(GL_POLYGON);      //broken chain2
	glColor3f(0.0,0.0,0.0);
	glVertex2i(192,236);
	glVertex2i(195,236);
	glVertex2i(195,238);
	glVertex2i(195,238);
	glEnd();
	
	glBegin(GL_POLYGON);      //broken chain2
	glColor3f(0.0,0.0,0.0);
	glVertex2i(191,229);
	glVertex2i(194,233);
	glVertex2i(194,233);
	glVertex2i(194,229);
	glEnd();
	
	glBegin(GL_POLYGON);      //chain4
	glColor3f(0.0,0.0,0.0);
	glVertex2i(200,230);
	glVertex2i(209,230);
	glVertex2i(209,240);
	glVertex2i(200,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);			//sphere1
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(207,233,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere2
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(207,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glBegin(GL_POLYGON);      //inside chain4
	glColor3f(1.0,1.0,1.0);
	glVertex2i(200,232);
	glVertex2i(206,232);
	glVertex2i(206,238);
	glVertex2i(200,238);
	glEnd();
	
	
	glBegin(GL_POLYGON);      //chain4
	glColor3f(0.0,0.0,0.0);
	glVertex2i(212,230);
	glVertex2i(227,230);
	glVertex2i(227,240);
	glVertex2i(212,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);			//sphere1
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(214,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere2
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(214,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere3
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(225,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere4
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(225,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glBegin(GL_POLYGON);      //inside chain4
	glColor3f(1.0,1.0,1.0);
	glVertex2i(214,232);
	glVertex2i(225,232);
	glVertex2i(225,238);
	glVertex2i(214,238);
	glEnd();
	
	glBegin(GL_POLYGON);      //chain//
	glColor3f(0.0,0.0,0.0);
	glVertex2i(204,234);
	glVertex2i(216,234);
	glVertex2i(216,236);
	glVertex2i(204,236);
	glEnd();  
	

	
	glBegin(GL_POLYGON);      //chain5
	glColor3f(0.0,0.0,0.0);
	glVertex2i(230,230);
	glVertex2i(245,230);
	glVertex2i(245,240);
	glVertex2i(230,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);			//sphere1
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(232,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere2
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(232,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere3
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(243,237,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);			//sphere4
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(243,232,0);
	glutSolidSphere(2.7,100,200);
	glPopMatrix();
	
	glBegin(GL_POLYGON);      //inside chain6
	glColor3f(1.0,1.0,1.0);
	glVertex2i(232,232);
	glVertex2i(243,232);
	glVertex2i(243,238);
	glVertex2i(232,238);
	glEnd();
	
	glBegin(GL_POLYGON);      //chain//
	glColor3f(0.0,0.0,0.0);
	glVertex2i(222,234);
	glVertex2i(235,234);
	glVertex2i(235,236);
	glVertex2i(222,236);
	glEnd(); 
	
	glBegin(GL_POLYGON);      //chain//
	glColor3f(0.0,0.0,0.0);
	glVertex2i(241,234);
	glVertex2i(249,234);
	glVertex2i(249,236);
	glVertex2i(241,236);
	glEnd();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void human(float x,float y,float z,float a[]){						//**HUMAN function
	
	glColor3f(a[0],a[1],a[2]);
	glPushMatrix();					//human head
	glTranslatef(x,y,0);
	glutSolidSphere(9.5,50.0,50.0);
	glPopMatrix();
	
	glBegin(GL_POLYGON);			//mask
	glColor3f(1,1,1);
	glVertex2f(x-4,y-6);
	glVertex2f(x,y-8);
	glVertex2f(x+4,y-6);
	glVertex2f(x+4,y);
	glVertex2f(x,y+2);
	glVertex2f(x-4,y);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(x-9,y+1);
	glVertex2f(x-3,y-3);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(x+3,y-3);
	glVertex2f(x+9,y+1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
	glVertex2f(x-3,y-1);
	glVertex2f(x+3,y-1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
	glVertex2f(x-3,y-3);
	glVertex2f(x+3,y-3);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
	glVertex2f(x-3,y-4);
	glVertex2f(x+3,y-4);
	glEnd();
	
	
	glColor3f(a[0],a[1],a[2]);
	glBegin(GL_POLYGON);			//body
	glVertex2f(x-10-z,y-61);
	glVertex2f(x+10+z,y-61);
	glVertex2f(x+10,y-11);
	glVertex2f(x-10,y-11);
	glEnd();
	
	glBegin(GL_POLYGON);			//leftleg
	glVertex2f(x-10,y-111);
	glVertex2f(x-1,y-111);
	glVertex2f(x-1,y-61);
	glVertex2f(x-10,y-61);
	glEnd();
	glPushMatrix();					
	glTranslatef(x-5.5,y-111,0);
	glutSolidSphere(4,50.0,50.0);
	glPopMatrix();
	
	glBegin(GL_POLYGON);		//right leg
	glVertex2f(x+1,y-111);
	glVertex2f(x+10,y-111);
	glVertex2f(x+10,y-61);
	glVertex2f(x+1,y-61);
	glEnd();
	glPushMatrix();					
	glTranslatef(x+5.5,y-111,0);
	glutSolidSphere(4,50.0,50.0);
	glPopMatrix();
	
	glBegin(GL_POLYGON);
	glVertex2f(x+11+z,y-61);		//lefthand
	glVertex2f(x+17+z,y-61);
	glVertex2f(x+17,y-16);
	glVertex2f(x+11,y-16);
	glEnd();
	glPushMatrix();					
	glTranslatef(x+14+z,y-61,0);
	glutSolidSphere(3,50.0,50.0);
	glPopMatrix();
	
	glBegin(GL_POLYGON);		//right hand
	glVertex2f(x-17-z,y-61);
	glVertex2f(x-11-z,y-61);
	glVertex2f(x-11,y-16);
	glVertex2f(x-17,y-16);
	glEnd();
	glPushMatrix();					
	glTranslatef(x-14-z,y-61,0);
	glutSolidSphere(3,50.0,50.0);
	glPopMatrix();
	
	glBegin(GL_POLYGON);		//joint
	glVertex2f(x-12,y-16);
	glVertex2f(x-10,y-16);
	glVertex2f(x-10,y-11);
	glVertex2f(x-12,y-11);
	glEnd();
	
	glPushMatrix();					//joint
	glTranslatef(x-13,y-15,0);
	glutSolidSphere(4,50.0,50.0);
	glPopMatrix();
	
	glBegin(GL_POLYGON);		//joint
	glVertex2f(x+10,y-16);
	glVertex2f(x+12,y-16);
	glVertex2f(x+12,y-11);
	glVertex2f(x+10,y-11);
	glEnd();
	
	glPushMatrix();					//joint
	glTranslatef(x+13,y-15,0);
	glutSolidSphere(4,50.0,50.0);
	glPopMatrix();
	
}
void box(int x,int y,int n,int m){		//bustand top white polygon
	glBegin(GL_POLYGON);   
	glColor3f(0.5,0.7,0.7);
	glVertex2i(x,y);
	glVertex2i(x+n,y);
	glVertex2i(x+n,y+m);
	glVertex2i(x,y+m);
	glEnd();
}
void pole(int x,int y,int n,int m){		//function for polygons
	glBegin(GL_POLYGON); 
	glColor3f(0.3,0.3,0.4);  
	glVertex2i(x,y);
	glVertex2i(x+n,y);
	glVertex2i(x+n,y+m);
	glVertex2i(x,y+m);
	glEnd();
}
void road(){
	float x1,x2,x3,x4,x,y;
	
	glBegin(GL_POLYGON);      //Road
	glColor3f(0.0,0.0,0.0);
	glVertex2i(0,0);
	glVertex2i(700,0);
	glVertex2i(700,75);
	glVertex2i(0,75);
	glEnd();
	
	glBegin(GL_POLYGON);      //foot path
	glColor3f(0.4,0.6,0.5);
	glVertex2i(0,75);
	glVertex2i(700,75);
	glVertex2i(700,115);
	glVertex2i(0,115);
	glEnd();
	
	x1=50;x2=100;x3=103.5;x4=53.5;
	while(x3<710){
		glBegin(GL_POLYGON);      // white marks
		glColor3f(1.0,1.0,1.0);
		glVertex2i(x1,45);
		glVertex2i(x2,45);
		glVertex2f(x3,50.0);
		glVertex2f(x4,50.0);
		glEnd();
		x1+=100;x2+=100;x3+=100;x4+=100;
	}
}

void board(){
	int x,i,y,j;
	float th;
	pole(647,100,3,200); 	//sign pole
	glBegin(GL_POLYGON);      // sign board
	glColor3f(0.1,0.2,0.6);
	glVertex2i(628,300);
	glVertex2i(668,300);
	glVertex2f(668.0,350.0);
	glVertex2f(628.0,350.0);
	glEnd();
	glBegin(GL_POLYGON);      // Bus sign
	glColor3f(1.0,1.0,1.0);
	glVertex2i(635,310);
	glVertex2i(661,310);
	glVertex2f(661.0,340.0);
	glVertex2f(635.0,340.0);
	glEnd();
	glBegin(GL_POLYGON);      //Bus wind shield
	glColor3f(0.3,0.3,0.4);
	glVertex2i(636,318);
	glVertex2i(660,318);
	glVertex2f(660.0,338.0);
	glVertex2f(636.0,338.0);
	glEnd();
	x=640;y=314;			
	j=0;
	while(j<2){				
		glBegin(GL_POLYGON);		//headlights
   		glColor3f(0,0,0);
   		for(int i=0;i<360;i++)
   		{
       		th=i*(3.1416/180);
       		glVertex2f(x+2*cos(th),y+2*sin(th));
  		}
		glEnd();
		j++;
		x=656;
	}
	glBegin(GL_POLYGON);      //Bus wheels
	glColor3f(1.0,1.0,1.0);
	glVertex2i(637,306);
	glVertex2i(640,306);
	glVertex2f(640.0,310.0);
	glVertex2f(637.0,310.0);
	glEnd();
	glBegin(GL_POLYGON);      
	glColor3f(1.0,1.0,1.0);
	glVertex2i(656,306);
	glVertex2i(659,306);
	glVertex2f(659.0,310.0);
	glVertex2f(656.0,310.0);
	glEnd();	
	glBegin(GL_POLYGON);      // Bus top
	glColor3f(1.0,1.0,1.0);
	glVertex2i(640,340);
	glVertex2i(656,340);
	glVertex2f(656.0,343.0);
	glVertex2f(640.0,343.0);
	glEnd();
	
	
}

void busstand(){
	int j,x1,x2,i;
	int number = 20; 
    float radius = 0.4; 
    float twopi = 2.0*3.14159;
	glBegin(GL_POLYGON);   	//background glass
	glColor3f(0.1,0.8,0.8);
	glVertex2i(303,120);
	glVertex2i(550,120);
	glVertex2i(550,270);
	glVertex2i(303,270);
	glEnd();
	
								//glass shades
	j=0;x1=393;x2=483;
	while(j<2){
	glBegin(GL_POLYGON);   	
	glColor3f(0.9,1.0,1.0);
	glVertex2i(x1,120);
	glVertex2i(x1+20,120);
	glVertex2i(x2+20,270);
	glVertex2i(x2,270);
	glEnd();
	x1+=40;x2+=40;
	j++;
	}
	glBegin(GL_TRIANGLES);   	
	glColor3f(0.9,1.0,1.0);
	glVertex2i(303,220);
	glVertex2i(330,270);
	glVertex2i(303,270);
	glEnd();
	glBegin(GL_POLYGON);   	
	glColor3f(0.9,1.0,1.0);
	glVertex2i(303,180);
	glVertex2i(333,180);
	glVertex2i(380,270);
	glVertex2i(350,270);
	glEnd();
	glBegin(GL_TRIANGLES);   	
	glColor3f(0.9,1.0,1.0);
	glVertex2i(303,120);
	glVertex2i(333,180);
	glVertex2i(303,180);
	glEnd();
	
	pole(550,100,3,200);	//main pole1
	pole(300,100,3,200);	//main pole 2
	
	pole(303,270,247,5);	//horizontal poles
	pole(303,140,247,5);
	pole(303,120,247,3);
	
	pole(270,300,315,35);	//top
	glBegin(GL_POLYGON);   
	glColor3f(1.0,1.0,1.0);
	glVertex2i(275,305);
	glVertex2i(580,305);
	glVertex2i(580,330);
	glVertex2i(275,330);
	glEnd();
	pole(290,335,3,50);		//top
	box(293,335,55,50);
	pole(345,335,3,50);
	box(348,335,40,50);
	pole(385,335,3,50);
	box(388,335,40,50);
	pole(425,335,3,50);
	box(428,335,40,50);
	pole(465,335,3,50);
	box(468,335,40,50);
	pole(505,335,3,50);
	box(508,335,55,50);
	pole(560,335,3,50);
	
	j=0;
	x1=330;
	while(j<5){
		glColor3f(1,0.9,0);
		glPushMatrix();					//seat
		glTranslatef(x1,150,0);
		glutSolidSphere(20,1000.0,50.0);
		glPopMatrix();
		i=0;
		while(i<10){
			glColor3f(0,0,0);
			glBegin(GL_LINES);
			glVertex2f(x1-15,157-i-12);
			glVertex2f(x1+15,157-i-12);
			glEnd();
			i+=2;
		}
		x1+=47;
		j++;
	}
}
void background(){
	glBegin(GL_POLYGON);      //garden
	glColor3f(0.0,0.8,0.0);
	glVertex2i(0,115);
	glVertex2i(700,115);
	glVertex2i(700,150);
	glVertex2i(0,150);
	glEnd();
	
	glBegin(GL_POLYGON);      //bricks
	glColor3f(0.4,0.3,0.3);
	glVertex2i(0,150);
	glVertex2i(700,150);
	glVertex2i(700,162);
	glVertex2i(0,162);
	glEnd();
	
	glBegin(GL_POLYGON);      //compound
	glColor3f(0.6,0.7,0.6);
	glVertex2i(0,162);
	glVertex2i(700,162);
	glVertex2i(700,240);
	glVertex2i(0,240);
	glEnd();
	
	glBegin(GL_POLYGON);      //tree stem
	glColor3f(0.7,0.3,0.0);
	glVertex2i(675,260);
	glVertex2i(700,260);
	glVertex2i(700,300);
	glVertex2i(675,300);
	glEnd();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(668,265,0);
	glutSolidSphere(20,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(700,300,0);
	glutSolidSphere(20,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(666,310,0);
	glutSolidSphere(30,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(648,275,0);
	glutSolidSphere(30,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(640,315,0);
	glutSolidSphere(30,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(660,350,0);
	glutSolidSphere(30,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(688,385,0);
	glutSolidSphere(30,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(688,360,0);
	glutSolidSphere(45,100,200);
	glPopMatrix();

	glBegin(GL_POLYGON);      //bricks
	glColor3f(0.5,0.5,0.4);
	glVertex2i(0,240);
	glVertex2i(700,240);
	glVertex2i(700,260);
	glVertex2i(0,260);
	glEnd();
	
	glBegin(GL_POLYGON);      //building2
	glColor3f(0.7,0.3,0.0);
	glVertex2i(43,260);
	glVertex2i(100,260);
	glVertex2i(100,390);
	glVertex2i(43,390);
	glEnd();
	
	glBegin(GL_POLYGON);      //building2 upper
	glColor3f(0.7,0.2,0.1);
	glVertex2i(45,390);
	glVertex2i(98,390);
	glVertex2i(98,400);
	glVertex2i(45,400);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass1
	glColor3f(0.2,1.0,0.8);
	glVertex2i(47,295);
	glVertex2i(68,295);
	glVertex2i(68,270);
	glVertex2i(47,270);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass2
	glColor3f(0.2,1.0,0.8);
	glVertex2i(74,295);
	glVertex2i(95,295);
	glVertex2i(95,270);
	glVertex2i(74,270);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass3
	glColor3f(0.2,1.0,0.8);
	glVertex2i(47,330);
	glVertex2i(68,330);
	glVertex2i(68,305);
	glVertex2i(47,305);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass4
	glColor3f(0.2,1.0,0.8);
	glVertex2i(74,330);
	glVertex2i(95,330);
	glVertex2i(95,305);
	glVertex2i(74,305);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass5
	glColor3f(0.2,1.0,0.8);
	glVertex2i(47,365);
	glVertex2i(68,365);
	glVertex2i(68,340);
	glVertex2i(47,340);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass6
	glColor3f(0.2,1.0,0.8);
	glVertex2i(74,365);
	glVertex2i(95,365);
	glVertex2i(95,340);
	glVertex2i(74,340);
	glEnd();
	
	glBegin(GL_POLYGON);      //stand bricks1
	glColor3f(0.5,0.5,0.5);
	glVertex2i(80,150);
	glVertex2i(110,150);
	glVertex2i(110,280);
	glVertex2i(80,280);
	glEnd();
	
	glBegin(GL_POLYGON);      //stand bricks4
	glColor3f(0.5,0.5,0.5);
	glVertex2i(580,150);
	glVertex2i(610,150);
	glVertex2i(610,280);
	glVertex2i(580,280);
	glEnd();
	
	glBegin(GL_POLYGON);      //building1
	glColor3f(0.7,0.2,0.1);
	glVertex2i(0,260);
	glVertex2i(40,260);
	glVertex2i(40,350);
	glVertex2i(0,350);
	glEnd();
	
	glBegin(GL_POLYGON);      //building1 upper
	glColor3f(0.7,0.1,0.0);
	glVertex2i(0,350);
	glVertex2i(35,350);
	glVertex2i(35,360);
	glVertex2i(0,360);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass1
	glColor3f(0.2,1.0,0.8);
	glVertex2i(5,270);
	glVertex2i(30,270);
	glVertex2i(30,290);
	glVertex2i(5,290);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass2
	glColor3f(0.2,1.0,0.8);
	glVertex2i(5,310);
	glVertex2i(30,310);
	glVertex2i(30,330);
	glVertex2i(5,330);
	glEnd();
	
	
	
	glBegin(GL_POLYGON);      //house
	glColor3f(0.8,0.4,0.0);
	glVertex2i(145,260);
	glVertex2i(340,260);
	glVertex2i(340,350);
	glVertex2i(145,350);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);			//glass
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(245,300,0);
	glutSolidSphere(20,100,200);
	glPopMatrix();
	
	glColor3f(0.3,0.9,1.0);			//glass
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(249,300,0);
	glutSolidSphere(17,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(140,316,0);
	glutSolidSphere(25,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(170,350,0);
	glutSolidSphere(40,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(170,320,0);
	glutSolidSphere(15,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(200,345,0);
	glutSolidSphere(25,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(220,375,0);
	glutSolidSphere(35,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(260,369,0);
	glutSolidSphere(21,100,200);
	glPopMatrix();
	
	glColor3f(0.4,0.7,0.1);			//tree
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(288,359,0);
	glutSolidSphere(15,100,200);
	glPopMatrix();
	
	glBegin(GL_POLYGON);      //house hut
	glColor3f(0.5,0.2,0.1);
	glVertex2i(123,280);
	glVertex2i(247,360);
	glVertex2i(272,360);
	glVertex2i(148,280);
	glEnd();
	
	glBegin(GL_POLYGON);      //house hut
	glColor3f(0.5,0.2,0.1);
	glVertex2i(342,280);
	glVertex2i(242,360);
	glVertex2i(267,360);
	glVertex2i(367,280);
	glEnd();
	
	glBegin(GL_POLYGON);      //stand bricks2
	glColor3f(0.5,0.5,0.5);
	glVertex2i(250,150);
	glVertex2i(280,150);
	glVertex2i(280,280);
	glVertex2i(250,280);
	glEnd();
	
	glBegin(GL_POLYGON);      //building3
	glColor3f(0.6,0.3,0.0);
	glVertex2i(400,260);
	glVertex2i(500,260);
	glVertex2i(500,430);
	glVertex2i(400,430);
	glEnd();
	
	glBegin(GL_POLYGON);      //building3 upper
	glColor3f(0.7,0.1,0.0);
	glVertex2i(405,430);
	glVertex2i(495,430);
	glVertex2i(495,440);
	glVertex2i(405,440);
	glEnd();
	
	glBegin(GL_POLYGON);      //stand bricks3
	glColor3f(0.5,0.5,0.5);
	glVertex2i(400,150);
	glVertex2i(430,150);
	glVertex2i(430,280);
	glVertex2i(400,280);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass1
	glColor3f(0.2,1.0,0.8);
	glVertex2i(410,288);
	glVertex2i(450,288);
	glVertex2i(450,400);
	glVertex2i(410,400);
	glEnd();
	
	glBegin(GL_POLYGON);      //glass2
	glColor3f(0.2,1.0,0.8);
	glVertex2i(455,288);
	glVertex2i(490,288);
	glVertex2i(490,400);
	glVertex2i(455,400);
	glEnd();
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void key_timer1(int e){			//next key timer function
	if(ax<=200 && p==600){
		ax++;
		glutPostRedisplay();
		glutTimerFunc(10,key_timer1,0);
	}
	else if(bx<=200 && m2==20){
		bx++;
		glutPostRedisplay();
		glutTimerFunc(10,key_timer1,0);
	}
	else if(cx<=200 &&final==1){
		cx++;
		glutPostRedisplay();
		glutTimerFunc(10,key_timer1,0);
	}
	else{
		glutTimerFunc(0,key_timer1,0);
	}
}
void key_timer2(int e){			//next key timer function
		if(nax<=200){
			nax++;
			glutPostRedisplay();
			glutTimerFunc(10,key_timer2,0);
		}
		else{
			glutTimerFunc(0,key_timer2,0);
		}
}
void key_timer3(int e){			//next key timer function
		if(ncx<=200){
			ncx++;
			glutPostRedisplay();
			glutTimerFunc(10,key_timer3,0);
		}
		else{
			glutTimerFunc(0,key_timer3,0);
		}
}
void key_timer4(int e){
	if(zx<=200){
			zx++;
			glutPostRedisplay();
			glutTimerFunc(20,key_timer4,0);
		}
		else{
			glutTimerFunc(0,key_timer4,0);
		}
}
void message_timer(int e){
	if(mx<=30){
		mx++;
		glutPostRedisplay();
		glutTimerFunc(10,message_timer,0);
	}
	else{
		glutTimerFunc(0,message_timer,0);
	}
}
void message_timer2(int e){
	if(tx<=350){
		tx++;
		glutPostRedisplay();
		glutTimerFunc(10,message_timer2,0);
	}
	else{
		t_text=300;
		glutPostRedisplay();
	}
}
void chain_timer(int e){
	if(chain_x==-400){
			chain_x=0;
			glutPostRedisplay();
			glutTimerFunc(200,chain_timer,0);
	}
	else{
		chain_x=-400;
		glutPostRedisplay();
		glutTimerFunc(200,chain_timer,0);
    }
}

void timer1(int e){						// timer function for human entry from left
	if(p<600){
		p=p+10;
		glutPostRedisplay();
		glutTimerFunc(100,timer1,1);	
	}	
}

void timer2(int e){						//timer function for human entry from right
	r=r-10;
	s=s-10;
	if(s>-610){
		glutPostRedisplay();
		glutTimerFunc(100,timer2,0);	
	}
}

void timer3(int e){						//includes all the operations

	if(q<228){							//infected person
		q=q+10;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	else if(a==1 && d1<20){				//social distancing
		d1=d1+10;
		d2=d2+30;
		d3=d3+40;
		d4=d4+50;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	
	else if(m6<108){					//infecting human6 
		m6=m6+10;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	else if(m5<60){						//infecting human5 
		m5=m5+10;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	else if(a>0){						//terminating further infection
		final=1;
		return;
	}
	else if(m4<20){						//infecting human4
		m4=m4+10;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	
	else if(m3<20){						//infecting human3
		m3=m3+10;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	
	else if(m2<20){						//infecting human2 
		m2=m2+10;
		glutPostRedisplay();
		glutTimerFunc(400,timer3,0);
	}
	else{
		a++;	//variable for terminating further infection
	}
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void movement(){
	float hc[]={0.2,0.4,0.1};
	int i;
	float ic[]={0.9,0.0,0.0};
	float ne1[3],ne2[3],ne3[3],ne4[3],ne5[3],ne6[3];
	
	if(m2>10){							//human1
		for(i=0;i<3;i++)
			ne1[i]=ic[i];
	}
	else {
		for(i=0;i<3;i++)
			ne1[i]=hc[i];
	}
	glPushMatrix();
	glTranslatef(-600+p-d3,0,0);
	human(90,210,0,ne1);
	glPopMatrix(); 
	
	if(m3>10){							//human2
		for(i=0;i<3;i++)
			ne2[i]=ic[i];
	}
	else {
		for(i=0;i<3;i++)
			ne2[i]=hc[i];
	}
	glPushMatrix();
	glTranslatef(610+s-d2,0,0);
	human(135,210,10,ne2);
	glPopMatrix(); 
	
	if(m4>10){							//human3
		for(i=0;i<3;i++)
			ne3[i]=ic[i];
	}
	else {
		for(i=0;i<3;i++)
			ne3[i]=hc[i];
	}
	glPushMatrix();
	glTranslatef(-600+p-d1,0,0);
	human(180,210,0,ne3);
	glPopMatrix(); 
	
	if(m5>50){							//human4
		for(i=0;i<3;i++)
			ne4[i]=ic[i];
	}
	else {
		for(i=0;i<3;i++)
			ne4[i]=hc[i];
	}
	glPushMatrix();
	glTranslatef(610+s,0,0);
	human(225,210,10,ne4);
	glPopMatrix(); 
	
	if(m6>108){							//human5
		for(i=0;i<3;i++)
			ne5[i]=ic[i];
	}
	else {
		for(i=0;i<3;i++)
			ne5[i]=hc[i];
	}
	glPushMatrix();
	glTranslatef(610+s-m5,0,0);
	human(330,210,0,ne5);
	glPopMatrix(); 
	

	if(q>220){							//human6
		for(i=0;i<3;i++)
			ne6[i]=ic[i];
	}
	else {
		for(i=0;i<3;i++)
			ne6[i]=hc[i];
	}
	
	glPushMatrix();
	glTranslatef(-600+p-m6,0,0);
	human(472,210,0,ne6);
	glPopMatrix(); 
	
	glPushMatrix();						//infected person
	glTranslatef(228-q,0,0);
	human(505,210,0,ic);
	glPopMatrix();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void slide1(){							
	road();
	board();
	busstand();	
}
void slide2(){
	movement();	
}
void slide3(){
	p=600;q=0;r=0;s=-610;m1=0;m2=0;m3=0;m4=0;m5=0;m6=0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display(){
	glClearColor(0.8,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	slide1();
	slide2();
	key_a("PRESS A FOR NEXT");
	key_b("PRESS B FOR NEXT");
	message1("HERE THERE IS NO SOCIAL DISTANCING!!!");
	glFlush();
	glutSwapBuffers();	
}
void display2(){
	glClear(GL_COLOR_BUFFER_BIT);
	background();
	road();
	board();
	busstand();	
	movement();
	key_c("PRESS C FOR NEXT");
	message2("HERE THEY HAVE MAINTAINED SOCIAL DISTANCING!!!");
	glFlush();
	glutSwapBuffers();
}
void display1(){
	glClear(GL_COLOR_BUFFER_BIT);
	intro();
	glFlush();
	glutSwapBuffers();
}
void display3(){
	glClear(GL_COLOR_BUFFER_BIT);
	end();
	glFlush();
	glutSwapBuffers();
}
void instruction(){
	glClear(GL_COLOR_BUFFER_BIT);
	instruct();
	glFlush();
	glutSwapBuffers();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void keyPressed (unsigned char key, int x, int y) { 

	switch(key){
		case 's':glutDisplayFunc(instruction);
				break;
		case 'n':timer1(0);
				timer2(0);
				key_timer1(0);
				glutDisplayFunc(display);
				break;
				glutDisplayFunc(instruction);
				break;
		case 'a':timer3(0);
				key_timer2(0);
				key_timer1(0);
				message_timer(0);
				 break;
		case 'b':slide3();
				 timer3(0);
				 key_timer1(0);
				 mx=-300;
				 message_timer(0);
				 chain_timer(0);
				 glutDisplayFunc(display2);
				 break;
		case 'c':key_timer4(0);
				glutDisplayFunc(display3);
				break;
		case 'z':message_timer2(0);
				break;
	}
	glutPostRedisplay();
}  
void idle(){
	if(!idle_v)
		return;
	display();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("USE OF SOCIAL DISTANCING IN PREVENTING CORONA VIRUS)");
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	initOpenGl();
	glutKeyboardFunc(keyPressed);
    glutDisplayFunc(display1);
    //glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}


