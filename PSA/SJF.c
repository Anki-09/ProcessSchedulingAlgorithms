#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
float black[]={0,0,0};
float white[]={1,1,1};
float yellow[]={1,1,0};
float GoldenRod[]={0.855, 0.647, 0.125};
float LimeGreen[]={0.196, 0.804, 0.196};
float MediumBlue[]={0.000, 0.000, 0.804};
float DarkGreen[]={0.000, 0.392, 0.000};
float OrangeRed[]={1.000, 0.271, 0.000};
float PeachPU[]={1.000, 0.855, 0.725};
float DarkOliveGreen[]={0.333, 0.420, 0.184};
float BurlyWood[]={0.871, 0.722, 0.529};
float p1x=2.5,p2x=2.5,p3x=2.5,p4x=2.5;
float d1x=2.5,d2x=2.5,d3x=2.5,d4x=2.5;
int count=0;
void init()
{
 glClearColor(1,0.89,0.7,1);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-2,2,-2,2,-2,2);
 glMatrixMode(GL_MODELVIEW);
}
void initLight()
{
 float ambient_Light[]={0.7,0.7,0.7,0.5};
 float diffuse_Light[]={0.5,0.5,0.5,1};
 float lightPos[]={2,2,-1,1};

 glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
 glLightfv(GL_LIGHT0,GL_AMBIENT,ambient_Light);
 glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse_Light);
}
void setMaterialColor(float *color)
{
 glMaterialfv(GL_FRONT,GL_AMBIENT,color);
 glMaterialfv(GL_FRONT,GL_SPECULAR,white);
 float mat_shine[]={40};
 glMaterialfv(GL_FRONT,GL_SHININESS,mat_shine);

}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glColor3f(1,0,0);
 glRasterPos3f(-0.2,0,0);
 char msg[]="SHORTEST JOB FIRST";
 for(int i=0;i<strlen(msg);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);

 glRasterPos3f(-0.2,-1.5,0);
 char msg1[]="PRESS 'l' OR 'L' TO CONTINUE......";
 for(int i=0;i<strlen(msg1);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg1[i]);
 glutSwapBuffers();
}
void mainPoster()
{
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.698, 0.133, 0.133);
 glRasterPos3f(-0.2,1.7,0);
 char msgp[]="PIZZA HOUSE";
 for(int i=0;i<strlen(msgp);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msgp[i]);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);

 glColor3f(0.855, 0.647, 0.125);
 glBegin(GL_QUADS);
 glVertex3f(-0.25,1.6,0);
 glVertex3f(-0.25,1.9,0);
 glVertex3f(0.35,1.9,0);
 glVertex3f(0.35,1.6,0);
 glEnd();
}
void customers(char no,float x,float y,float z)
{
//The Customers
 //face
 glColor3f(x,y,z);
 glPushMatrix();
 glTranslatef(-0.2,-0.5,0);
 glutSolidSphere(0.2,70,50);
 glPopMatrix();

 //body
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0,0,0);
 glRasterPos3f(-0.2,-0.9,0);
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,no);
 glColor3f(x,y,z);
 glRectf(-0.4,-0.7,0.01,-1.12);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}
void subtitles(char msgf[])
{
 glDisable(GL_DEPTH_TEST);
 //subtitle cloud created with spheres
 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.05,-0.5,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.15,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.35,-0.55,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.25,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.4,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.2,-0.57,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(0.8,-0.65,0);
 glutSolidSphere(0.025,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(0.9,-0.55,0);
 glutSolidSphere(0.035,12,6);
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(1.07,-0.43,0);
 char q1[]="I WANT ";
 for(int i=0;i<strlen(q1);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q1[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(1.3,-0.43,0);
 for(int i=0;i<strlen(msgf);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msgf[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(1.09,-0.54,0);
 char q2[]="VEG PIZZA";
 for(int i=0;i<strlen(q2);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q2[i]);
 glEnable(GL_DEPTH_TEST);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}
void subtitledisp()
{
 glPushMatrix();
 glTranslatef(0.75,0.3,0);
 glScalef(0.8,0.8,0);
 if(p4x<1.5)
 subtitles(" TWO");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(0.2,0.3,0);
 glScalef(0.8,0.8,0);
 if(p3x<1)
 subtitles(" ONE");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-0.35,0.3,0);
 glScalef(0.8,0.8,0);
 if(p2x<0.5)
 subtitles("FOUR");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-0.9,0.3,0);
 glScalef(0.8,0.8,0);
 if(p1x<0)
 subtitles("THREE");
 glPopMatrix();
}
void chair()
{
 //chair on which the counter-attendent sits
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.6,0,0);
 glPushMatrix();
 glTranslatef(-1.03,-0.49,0.05);
 glScalef(0.2,0.06,1);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0.8,0,0);
 glPushMatrix();
 glTranslatef(-1.09,-0.58,0.05);
 glRotatef(90,0,0,1);
 glScalef(0.2,0.04,1);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0.8,0,0);
 glPushMatrix();
 glTranslatef(-0.97,-0.58,0.05);
 glRotatef(90,0,0,1);
 glScalef(0.2,0.04,1);
 glutSolidCube(1);
 glPopMatrix();

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}

void staffWaiter()
{
 //waiter menu Board
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.333, 0.420, 0.184);
 glBegin(GL_QUADS);
 glVertex3f(-1.46,0.83,0);
 glVertex3f(-1.46,1.53,0);
 glVertex3f(-0.52,1.53,0);
 glVertex3f(-0.52,0.83,0);
 glEnd();

 //pizza chef_Waiter
glDisable(GL_DEPTH_TEST);
 glColor3f(0.961, 0.961, 0.961);
 glRasterPos3f(-1.4,1.4,0);
 char msg[]="MENU";
 for(int i=0;i<strlen(msg);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);
 glEnable(GL_DEPTH_TEST);

 //Waiter-face
 glColor3f(0.871, 0.722, 0.529);
 glRectf(-1.50,1.27,-1.59,1.57);
 glColor3f(0.871, 0.722, 0.529);
 glRectf(-1.62,1.4,-1.47,1.46);
 glDisable(GL_DEPTH_TEST);

 //Waiter-Eyes
 glColor3f(0,0,0);
 glRectf(-1.57,1.46,-1.58,1.478);
 glColor3f(0,0,0);
 glRectf(-1.51,1.46,-1.52,1.478);
 glEnable(GL_DEPTH_TEST);

 //Waiter-Face Lines
 glDisable(GL_DEPTH_TEST);
 glColor3f(0,0,0);
 glLineWidth(2);
 glBegin(GL_LINES);
 glVertex3f(-1.587,1.50,0);
 glVertex3f(-1.574,1.54,0);
 glVertex3f(-1.523,1.54,0);
 glVertex3f(-1.51,1.50,0);

 //Waiter-mouth
 glVertex3f(-1.53,1.30,0);
 glVertex3f(-1.55,1.30,0);
 glVertex3f(-1.523,1.54,0);
 glVertex3f(-1.51,1.50,0);
 glEnd();
 glEnable(GL_DEPTH_TEST);

 //Waiter-Neck-Area -Bow_Tie
 glColor3f(1.000, 0.000, 0.000);
 glPushMatrix();
 glTranslatef(-1.54,1.18,0);
 glutSolidSphere(0.03,70,50);
 glPopMatrix();

 //Waiter-Neck-Area-Neck
 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(-1.54,1.16,0);
 glRotatef(-90,0,0,1);
 glScalef(0.2,0.03,1);
 glutSolidCube(1);
 glPopMatrix();

 //Waiter-Black-hair
 glColor3f(0,0,0);
 glRectf(-1.50,1.30,-1.59,1.60);

 //Waiter-hat
 glColor3f(1,1,1);
 glRectf(-1.58,1.6,-1.51,1.7);

 glColor3f(1,0,0);
 glPushMatrix();
 glTranslatef(-1.52,1.72,0);
 glutSolidSphere(0.04,12,6);
 glPopMatrix();

 glColor3f(1,0,0);
 glPushMatrix();
 glTranslatef(-1.56,1.72,0);
 glutSolidSphere(0.04,12,6);
 glPopMatrix();

 //Body
 glColor3f(0.753, 0.753, 0.753);
 glRectf(-1.48,0.74,-1.61,1.15);

 //hands
 glDisable(GL_DEPTH_TEST);
 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(-1.62,0.85,0);
 glScalef(0.03,0.1,0);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(-1.47,0.85,0);
 glScalef(0.03,0.1,0);
 glutSolidCube(1);
 glPopMatrix();

 //pizza plate
 glColor3f(0.8,0,0);
 glPushMatrix();
 glTranslatef(-1.55,0.9,0.05);
 glScalef(0.3,0.1,1);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0,0,0);
 glRasterPos3f(-1.62,0.88,0.05);
 char msgq[]="PIZZA";
 for(int i=0;i<strlen(msgq);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msgq[i]);
 glEnable(GL_DEPTH_TEST);

 //Waiter Title Board
 glDisable(GL_DEPTH_TEST);
 glColor3f(0.000, 0.392, 0.000);
 glRectf(-1.48,0.6,-1.75,0.8);
 glEnable(GL_DEPTH_TEST);
 glColor3f(0.973, 0.973, 1.000);
 glRasterPos3f(-1.7,0.66,0);
 char msgw[]="WAITER";
 for(int i=0;i<strlen(msgw);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msgw[i]);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);

}
void staffManager(){
 //Pizza-House Manager
 //Manager-Poster
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0,0,0);
 glRasterPos3f(1.6,1.7,0);
 char msgm[]="MANAGER";
 for(int i=0;i<strlen(msgm);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msgm[i]);
 glColor3f(0.467, 0.533, 0.600);
 glRectf(1.58,1.67,1.89,1.84);

 //Manager-Face
 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(1.7,1.37,0);
 glutSolidSphere(0.2,200,200);
 glPopMatrix();

 //Manager-Hair
 glDisable(GL_DEPTH_TEST);
 glColor3f(0,0,0);
 glPushMatrix();
 glTranslatef(1.7,1.48,0);//Middle
 glutSolidSphere(0.1,14,8);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(1.6,1.46,0);//Left
 glutSolidSphere(0.1,10,5);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(1.79,1.48,0);//Right
 glutSolidSphere(0.09,14,8);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(1.67,1.49,0);//Middle Big
 glutSolidSphere(0.12,14,8);
 glPopMatrix();

 glEnable(GL_DEPTH_TEST);
 glDisable(GL_DEPTH_TEST);

 glBegin(GL_TRIANGLES);
 glColor3f(0,0,0);
 glVertex3f(1.54, 1.5, 0);
 glVertex3f(1.64, 1.5, 0);
 glVertex3f(1.57, 1.27, 0);
 glEnd();
 glEnable(GL_DEPTH_TEST);

 //Manager-Body
 glColor3f(0,0,0);
 glPushMatrix();
 glTranslatef(1.7,0.9,0);
 glutSolidSphere(0.3,6,12);
 glPopMatrix();

 //Manager-Tie Space
 glDisable(GL_DEPTH_TEST);
 glBegin(GL_TRIANGLES);
 glColor3f(1.000, 0.980, 0.980);
 glVertex3f(1.63, 1.17, 0);
 glVertex3f(1.77, 1.17, 0);
 glVertex3f(1.72, 0.9, 0);
 glEnd();
 glEnable(GL_DEPTH_TEST);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}
 void staffcounterAttendent()
 {
 //Counter-Attendent
 //Title Poster
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0,0,0);
 glRasterPos3f(-1.85,-1.4,0);
 char msgc[]="COUNTER ATTENDENT";
 for(int i=0;i<strlen(msgc);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msgc[i]);
 glColor3f(1.000, 0.271, 0.000);
 glRectf(-1.27,-1.3,-1.92,-1.47);

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_DEPTH_TEST);

 //Counter-Attendent-Face
 glColor3f(1,1,0);
 glPushMatrix();
 glTranslatef(-1.6,-0.4,0);
 glutSolidSphere(0.2,70,50);
 glPopMatrix();

 glColor3f(1,1,0);
 glRectf(-1.8,-0.6,-1.4,-1);

 //computer screen
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0,0,0);
 glPushMatrix();
 glTranslatef(-1.03,-0.1,0.05);
 glScalef(0.4,0.4,1);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0.5,0.5,0.5);
 glPushMatrix();
 glTranslatef(-1.03,-0.38,0.05);
 glScalef(0.2,0.15,1);
 glutSolidCube(1);
 glPopMatrix();

 glDisable(GL_DEPTH_TEST);
 glColor3f(1,1,1);
 glRasterPos3f(-1.1,-0.1,0);
 char msgj[]="SJEC";//Laptop Brand
 for(int i=0;i<strlen(msgj);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msgj[i]);
 glEnable(GL_DEPTH_TEST);

 glPushMatrix();
 glTranslatef(-0.55,-0.53,0);
 chair();
 glPopMatrix();

 //table on which the computer is kept
 glColor3f(0.6,0,0);
 glPushMatrix();
 glTranslatef(-1.03,-0.49,0.05);
 glScalef(0.7,0.06,1);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0.8,0,0);
 glPushMatrix();
 glTranslatef(-1.25,-0.72,0.05);
 glRotatef(90,0,0,1);
 glScalef(0.5,0.06,1);
 glutSolidCube(1);
 glPopMatrix();

 glColor3f(0.8,0,0);
 glPushMatrix();
 glTranslatef(-0.8,-0.72,0.05);
 glRotatef(90,0,0,1);
 glScalef(0.5,0.06,1);
 glutSolidCube(1);
 glPopMatrix();
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);

}

void Board()
{
  //The pizza menu board beside the chef
 //line Down
 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(-1.0,0.8,0);
 glScalef(0.95,0.05,0);
 glutSolidCube(1);
 glPopMatrix();

 //line-Straight
 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(-0.52,1.17,0);
 glRotatef(-90,0,0,1);
 glScalef(0.8,0.03,1);
 glutSolidCube(1);
 glPopMatrix();

 //line-up
 glColor3f(0.871, 0.722, 0.529);
 glPushMatrix();
 glTranslatef(-1.0,1.55,0);
 glScalef(0.95,0.03,0);
 glutSolidCube(1);
 glPopMatrix();

}
void scene2Poster()
{
 glColor3f(0.863, 0.078, 0.235);
 glRasterPos3f(-0.2,1.2,0);
char msgl1[]="AFTER SORTING THEM";//line1
 for(int i=0;i<strlen(msgl1);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msgl1[i]);
 glColor3f(0.863, 0.078, 0.235);
 glRasterPos3f(-0.2,1.0,0);
char msgl2[]="IN SHORTEST JOB FIRST ORDER";//line2
 for(int i=0;i<strlen(msgl2);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msgl2[i]);
}

void scene2CA(char msgcounter[]){
 //These are the subtitles of counter-attendent for scene 2

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.1,-0.5,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.00,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.20,-0.55,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.00,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.20,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.09,-0.57,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.0,-0.65,0);
 glutSolidSphere(0.025,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-1.2,-0.55,0);
 glutSolidSphere(0.035,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(-0.9,-0.45,0);
 glutSolidSphere(0.15,12,6);
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glDisable(GL_DEPTH_TEST);
 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-1.25,-0.43,0);
 char q1[]="OKAY SIR, PLEASE";
 for(int i=0;i<strlen(q1);i++)
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,q1[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-1.5,-0.43,0);
 for(int i=0;i<strlen(msgcounter);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,msgcounter[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-1.25,-0.54,0);
 char q2[]="PAY RUPEES 100";
 for(int i=0;i<strlen(q2);i++)
 glutBitmapCharacter(GLUT_BITMAP_8_BY_13,q2[i]);
 glEnable(GL_DEPTH_TEST);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}
void scene2Body()
{ //This is the Count Number for Scene 2
 //First-Person
 glColor3f(0,0,0);
 glRasterPos3f(-0.2,-0.9,0);
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'4');
 glColor3f(0.000, 0.392, 0.000);
 glRectf(-0.4,-0.7,0.01,-1.12);

 //Second-Person
 glColor3f(0,0,0);
 glRasterPos3f(0.3,-0.9,0);
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'3');
 glColor3f(1.000, 0.271, 0.000);
 glRectf(0.10,-0.7,0.5,-1.12);

 //Third-Person
 glColor3f(0,0,0);
 glRasterPos3f(0.8,-0.9,0);
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'1');
 glColor3f(0.196, 0.804, 0.196);
 glRectf(0.6,-0.7,1.0,-1.12);

 //Fourth-Person
 glColor3f(0.961, 0.961, 0.961);
 glRasterPos3f(1.3,-0.9,0);
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'2');
 glColor3f(0.000, 0.000, 0.804);
 glRectf(1.1,-0.7,1.5,-1.12);
}

void subtle()
{
 glDisable(GL_DEPTH_TEST);
 //subtitles
 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.05,-0.5,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.15,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.35,-0.55,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.25,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.4,-0.4,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(1.2,-0.57,0);
 glutSolidSphere(0.1,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(0.8,-0.65,0);
 glutSolidSphere(0.025,12,6);
 glPopMatrix();

 glColor3f(1.000, 0.855, 0.725);
 glPushMatrix();
 glTranslatef(0.9,-0.55,0);
 glutSolidSphere(0.035,12,6);
 glPopMatrix();
 glEnable(GL_DEPTH_TEST);
}

void S3person4()
{
 glPushMatrix();
 glTranslatef(-1.4,1,0);
 glScalef(0.8,0.8,0);
 subtle();
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-0.62,0.6,0);
 char q1[]="ONE VEG PIZZA";
 for(int i=0;i<strlen(q1);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q1[i]);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}

void S3counterattendent(){
 glPushMatrix();
 glTranslatef(-0.3,1.7,0);
 glScalef(0.8,0.8,0);
 subtle();
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(0.43,1.35,0);
 char q2[]="OKAY SIR PLEASE";
 for(int i=0;i<strlen(q2);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q2[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(0.53,1.25,0);
 char q3[]="PAY 200RS";
 for(int i=0;i<strlen(q3);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q3[i]);
 glEnable(GL_DEPTH_TEST);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}

void S3person3(){
 glPushMatrix();
 glTranslatef(0.8,1.9,0);
 glScalef(0.8,0.8,0);
 subtle();
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(1.67,1.55,0);
 char q4[]="TWO VEG";
 for(int i=0;i<strlen(q4);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q4[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(1.6,1.45,0);
 char q5[]="PIZZAS PLEASE";
 for(int i=0;i<strlen(q5);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q5[i]);
 glEnable(GL_DEPTH_TEST);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}

void S3person2(){
 glPushMatrix();
 glTranslatef(-0.6,-0.5,0);
 glScalef(1.3,1.3,0);
 glScalef(0.8,0.8,0);
 subtle();
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(0.5,-0.9,0);
 char q6[]="I DON'T LIKE THIS";
 for(int i=0;i<strlen(q6);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q6[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(0.5,-1,0);
 char q7[]="ARRANGEMENT SO";
 for(int i=0;i<strlen(q7);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q7[i]);
 glEnable(GL_DEPTH_TEST);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(0.5,-1.1,0);
 char q8[]="I'M LEAVING";
 for(int i=0;i<strlen(q8);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q8[i]);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}

void S3person1(){
 glPushMatrix();
 glTranslatef(-1.78,-1,0);
 glScalef(1.3,1.3,0);
 glScalef(0.8,0.8,0);
 subtle();
 glPopMatrix();

 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-0.6,-1.4,0);
 char q9[]="I CAME FIRST";
 for(int i=0;i<strlen(q9);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q9[i]);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-0.7,-1.5,0);
 char q10[]="BUT MY SERVICE";
 for(int i=0;i<strlen(q10);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q10[i]);
 glEnable(GL_DEPTH_TEST);

 glColor3f(0.824, 0.412, 0.118);
 glRasterPos3f(-0.6,-1.6,0);
 char q11[]="IS DELAYED";
 for(int i=0;i<strlen(q11);i++)//message-fill
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q11[i]);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}
void displayone()
{
 glLoadIdentity();
 glClearColor(1,0.89,1,1);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 setMaterialColor(GoldenRod);
 mainPoster();
 Board();

 if(p1x>0)
 p1x-=0.02;
 setMaterialColor(DarkGreen);
 glPushMatrix();
 glTranslatef(p1x,0,0);
 customers('1',0.000, 0.392, 0.000);
 glPopMatrix();

 if(p2x>0.5 && p1x<0)
 p2x-=0.02;
 setMaterialColor(OrangeRed);
 glPushMatrix();
 glTranslatef(p2x,0,0);
 customers('2',1.000, 0.271, 0.000);
 glPopMatrix();

 if(p3x>1 && p2x<0.5)
 p3x-=0.02;
 setMaterialColor(LimeGreen);
 glPushMatrix();
 glTranslatef(p3x,0,0);
 customers('4',0.196, 0.804, 0.196);
 glPopMatrix();

 if(p4x>1.5 && p3x<1)
 p4x-=0.02;
 setMaterialColor(MediumBlue);
 glPushMatrix();
 glTranslatef(p4x,0,0);
 customers('3',0.000, 0.000, 0.804);
 glPopMatrix();

 staffManager();
 setMaterialColor(DarkOliveGreen);
 staffWaiter();

 setMaterialColor(yellow);
 setMaterialColor(OrangeRed);
 staffcounterAttendent();
 chair();
 setMaterialColor(PeachPU);
 subtitledisp();
 glutSwapBuffers();
 glutPostRedisplay();
}
void displaytwo()
{
 glLoadIdentity();
 glClearColor(1,0.89,1,1);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 setMaterialColor(GoldenRod);
 mainPoster();
 scene2Poster();
 Board();

//Customers
 if(d1x>0)
 d1x-=0.02;
 setMaterialColor(LimeGreen);
 glPushMatrix();
 glTranslatef(d1x,0,0);
 customers('4',0.196, 0.804, 0.196);
 glPopMatrix();

 if(d2x>0.5 && d1x<0)
 d2x-=0.02;
 setMaterialColor(MediumBlue);
 glPushMatrix();
 glTranslatef(d2x,0,0);
 customers('3',0.000, 0.000, 0.804);
 glPopMatrix();

 if(d3x>1 && d2x<0.5)
 d3x-=0.02;
 setMaterialColor(DarkGreen);
 glPushMatrix();
 glTranslatef(d3x,0,0);
 customers('1',0.000, 0.392, 0.000);
 glPopMatrix();

 if(d4x>1.5 && d3x<1)
 d4x-=0.02;
 setMaterialColor(OrangeRed);
 glPushMatrix();
 glTranslatef(d4x,0,0);
 customers('2',1.000, 0.271, 0.000);
 glPopMatrix();

 //subtitle
 glPushMatrix();
 glTranslatef(0.75,0.3,0);
 glScalef(0.8,0.8,0);
 setMaterialColor(PeachPU);
 if(d4x<1.5)
 subtitles(" FOUR");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(0.2,0.3,0);
 glScalef(0.8,0.8,0);
 setMaterialColor(PeachPU);
 if(d3x<1)
 subtitles(" THREE");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-0.35,0.3,0);
 glScalef(0.8,0.8,0);
 setMaterialColor(PeachPU);
 if(d2x<0.5)
 subtitles("TWO");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-0.5,0.5,0);
 setMaterialColor(PeachPU);
 if(d1x<0)
 scene2CA("");
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-0.9,0.3,0);
 glScalef(0.8,0.8,0);
 setMaterialColor(PeachPU);
 if(d1x<0.3)

 subtitles("ONE");
 glPopMatrix();

 staffManager();
 setMaterialColor(DarkOliveGreen);
 staffWaiter();
 setMaterialColor(OrangeRed);
 staffcounterAttendent();
 chair();
 glutSwapBuffers();
 glutPostRedisplay();
}

void displaythree()
{
 count++;
 glLoadIdentity();
 glClearColor(1,0.89,1,1);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 setMaterialColor(GoldenRod);
 mainPoster();
 Board();

 //customers
 glPushMatrix();
 setMaterialColor(PeachPU);
 if(count>100)
 S3person4();
 glTranslatef(-0.8,0.9,0);
 setMaterialColor(LimeGreen);
 customers('4',0.196, 0.804, 0.196);
 glPopMatrix();

 glPushMatrix();
 setMaterialColor(PeachPU);
 if(count>200)
 S3person3();
 glTranslatef(1.83,1.68,0);
 setMaterialColor(MediumBlue);
 customers('3',0.000, 0.000, 0.804);
 glPopMatrix();

 glPushMatrix();
 setMaterialColor(PeachPU);
 if(count>400)
 S3person1();
 glTranslatef(-1.05,-0.86,0);
 setMaterialColor(DarkGreen);
 customers('1',0.000, 0.392, 0.000);
 glPopMatrix();

 glPushMatrix();
 setMaterialColor(PeachPU);
 if(count>500)
 S3person2();
 glTranslatef(0.26,-0.86,0);
 setMaterialColor(OrangeRed);
 customers('2',1.000, 0.271, 0.000);
 glPopMatrix();

 staffWaiter();
 glPushMatrix();
 glTranslatef(-2.0,-1.77,0);
 glScalef(0.8,0.8,0);
 staffManager();
 glPopMatrix();

 glPushMatrix();
 setMaterialColor(PeachPU);
 if(count>300)
 S3counterattendent();
 glTranslatef(2.1,1.3,0);
 setMaterialColor(OrangeRed);
 staffcounterAttendent();
 glPopMatrix();
 glutSwapBuffers();
 glutPostRedisplay();
}

void welcome()
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glColor3f(0,0,0);
 //setMaterialColor(black);
 glRasterPos3f(-0.6,1.5,0);
 char msg1[]="PROCESS SCHEDULING ALGORITHMS";
 for(int i=0;i<strlen(msg1);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);

 glRasterPos3f(-1.5,1,0);
 char msg2[]="SUBMITTED BY:";
 for(int i=0;i<strlen(msg2);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg2[i]);

 glRasterPos3f(-1.5,0.8,0);
 char msg3[]="ANISHA DSOUZA :4SO18CS010 -> FIRST COME FIRST SERVE";
 for(int i=0;i<strlen(msg3);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);

 glRasterPos3f(-1.5,0.6,0);
 char msg4[]="ANKITHA :4SO18CS011 -> ROUND ROBIN";
 for(int i=0;i<strlen(msg4);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg4[i]);

 glRasterPos3f(-1.5,0.4,0);
 char msg5[]="DEEKSHIT LAWRENCE DSOUZA :4SO18CS031 -> SHORTEST JOB FIRST";
 for(int i=0;i<strlen(msg5);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg5[i]);

 glRasterPos3f(0.5,-0.2,0);
 char msg6[]="SUBMITTED TO:";
 for(int i=0;i<strlen(msg6);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg6[i]);

 glRasterPos3f(0.5,-0.4,0);
 char msg7[]="MS. NISHA ROCHE";
 for(int i=0;i<strlen(msg7);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg7[i]);

 glRasterPos3f(0.5,-0.6,0);
 char msg8[]="ASSISTANT PROFESSOR, CSE DEPT";
 for(int i=0;i<strlen(msg8);i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg8[i]);

 glRasterPos3f(-0.5,-1.5,0);
 char msg9[]="PRESS 'w' OR 'W' TO CONTINUE......";
 for(int i=0;i<strlen(msg9);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg9[i]);
 glutSwapBuffers();
}

void keys(unsigned char key,int x,int y)
{
 if(key=='w' || key=='W')//First scene
 {
 glutDisplayFunc(display);
 glutPostRedisplay();
 }
 if(key=='l' || key=='L')//First scene
 {
 glutDisplayFunc(displayone);
 glutPostRedisplay();
 }
 if(key=='m' || key =='M')//Second Scene
 {
 glutDisplayFunc(displaytwo);
 glutPostRedisplay();
 }
 if(key=='n' || key=='N')//Third Scene
 {
 glutDisplayFunc(displaythree);
 glutPostRedisplay();
 }
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
 glutInitWindowSize(600,600);
 glutCreateWindow("Process scheduling algorithms");
 welcome();
 init();
 glutDisplayFunc(welcome);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 glEnable(GL_NORMALIZE);
 initLight();
 glutKeyboardFunc(keys);
 glEnable(GL_DEPTH_TEST);
 glutMainLoop();
 return 0;
}

