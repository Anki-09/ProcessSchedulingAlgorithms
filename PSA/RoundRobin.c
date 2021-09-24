#include<windows.h>
#include<GL/glut.h>;
#include<string.h>
float blue[]={0,0,1};
float green[]={0,1,0};
float brown[]={0.8,0,0};
float red[]={1,0,0};
float queue[]={0.8,0.4,0};
float border[]={1,0.89,0.7};
float black[]={0,0,0};
float sky[]={0.54,0.92,1};
float white[]={1,1,1};
float grey[]={0.5,0.5,0.5};
float darkbrown[]={0.5,0,0};
float house2[]={1,0.5,0.7};
float house3[]={0.6,0,0};
float house4[]={1,0,0.6};
float screen[]={0.67,0.84,0.9};
float machine[]={0.8,0.4,0.2};
float mborder[]={0.9,0.4,0};
float sunT[]={0.99,0.72,0.07};
float sun[]={1,0.94,0.1};
float body[]={1,0.76,0.69};
float handbag[]={0.4,0,0};
void initLight()
{
    float ambient_Light[]={0.7,0.7,0.7,0.5};
    float diffuse_Light[]={0.5,0.5,0.5,1};
    float lightPos[]={-1.5,1,0,1};
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient_Light);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse_Light);
}
void setMaterialColor(float *color)
{
    glMaterialfv(GL_FRONT,GL_AMBIENT,color);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,white);
    float mat_shine[]={40};
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shine);
}
void init()
{
    glClearColor(1,0.89,0.7,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setMaterialColor(black);
    glRasterPos3f(-0.5,0,0);
    char msg[]="ROUND ROBIN";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
    glutSwapBuffers();
}
void processqueue()
{
    setMaterialColor(queue);
    glPushMatrix();
    glTranslatef(0.7,1.8,0);
    glScalef(2.3,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(queue);
    glPushMatrix();
    glTranslatef(-0.3,1.3,0);
    glRotatef(-90,0,0,1);
    glScalef(1,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(border);
    glPushMatrix();
    glTranslatef(0.7,1.3,-0.5);
    glRotatef(90,1,0,0);
    glScalef(2,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    glDisable(GL_DEPTH_TEST);
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(0.2,1.8,0);
    glVertex3f(0.2,0.8,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(0.7,1.8,0);
    glVertex3f(0.7,0.8,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(1.2,1.8,0);
    glVertex3f(1.2,0.8,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(1.7,1.8,0);
    glVertex3f(1.7,0.8,0);
    glEnd();
    glEnable(GL_DEPTH_TEST);
}
void road()
{
    //road
    glDisable(GL_DEPTH_TEST);
    setMaterialColor(grey);
    glBegin(GL_QUADS);
    glVertex3f(-0.8,0.2,0);
    glVertex3f(-0.28,0.8,0);
    glVertex3f(0.2,0.8,1);
    glVertex3f(-0.3,0.1,0);

    glVertex3f(-0.3,0.1,0);
    glVertex3f(-0.3,-0.5,0);
    glVertex3f(1.7,-0.5,0);
    glVertex3f(1.7,0.1,0);

    glVertex3f(1.7,0.1,0);
    glVertex3f(1.2,0.1,0);
    glVertex3f(1.2,0.8,0);
    glVertex3f(1.7,0.8,0);

    glVertex3f(0.9,-1.8,0);
    glVertex3f(0.2,-1.8,0);
    glVertex3f(0.2,-1.6,0);
    glVertex3f(0.8,-1.6,0);

    glVertex3f(0.5,-1.8,0);
    glVertex3f(0.1,-1.8,0);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.5,-0.5,0);
    glEnd();
    //road lines
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(10,0x00FF);
    setMaterialColor(white);
    glBegin(GL_LINES);
    glVertex3f(1.45,0.1,0);
    glVertex3f(1.45,0.8,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(1.45,-0.2,0);
    glVertex3f(0,-0.2,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.4,0.3,0);
    glVertex3f(0,0.8,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.3,-0.5,0);
    glVertex3f(0.3,-1.8,0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glEnable(GL_DEPTH_TEST);
    //work board
    glDisable(GL_DEPTH_TEST);
    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-0.8,0.8,0);
    glRotatef(-90,0,0,1);
    glScalef(1.2,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-0.8,1.2,0);
    glRotatef(-90,0,0,1);
    glScalef(0.4,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-0.3,0.75,0);
    glRotatef(-90,0,0,1);
    glScalef(1.3,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-0.55,1.2,0);
    glScalef(0.55,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(red);
    glRasterPos3f(-0.65,1.25,0);
    char msg[]="WORK";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);

    setMaterialColor(darkbrown);
    glBegin(GL_QUADS);
    glVertex3f(-0.8,1.4,0);
    glVertex3f(-0.8,1.2,0);
    glVertex3f(-0.3,1.2,0);
    glVertex3f(-0.3,1.4,0);
    glEnd();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-0.55,1.4,0);
    glScalef(0.55,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    //road direction
    setMaterialColor(red);
    glRasterPos3f(0.32,0.25,0);
    char msg1[]="QUEUE";
    for(int i=0;i<strlen(msg)+1;i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg1[i]);

    setMaterialColor(darkbrown);
    glBegin(GL_QUADS);
    glVertex3f(0.5,0.35,0);
    glVertex3f(0.5,0.2,0);
    glVertex3f(0.3,0.2,0);
    glVertex3f(0.3,0.35,0);

    glVertex3f(0.43,0.2,0);
    glVertex3f(0.43,0.1,0);
    glVertex3f(0.38,0.1,0);
    glVertex3f(0.38,0.2,0);
    glEnd();

    setMaterialColor(darkbrown);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5,0.38,0);
    glVertex3f(0.55,0.27,0);
    glVertex3f(0.5,0.17,0);
    glEnd();

    setMaterialColor(red);
    glRasterPos3f(-0.03,-0.72,0);
    float y=0.72;
    char msg2[]="HOME";
    for(int i=0;i<strlen(msg);i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg2[i]);
       y=y+0.09;
       glRasterPos3f(-0.03,-y,0);
    }
    setMaterialColor(darkbrown);
    glBegin(GL_QUADS);
    glVertex3f(0.1,-0.75,0);
    glVertex3f(0.1,-0.85,0);
    glVertex3f(0.02,-0.85,0);
    glVertex3f(0.02,-0.75,0);

    glVertex3f(-0.04,-0.63,0);
    glVertex3f(-0.04,-1,0);
    glVertex3f(0.02,-1,0);
    glVertex3f(0.02,-0.63,0);
    glEnd();

    setMaterialColor(darkbrown);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.04,-1,0);
    glVertex3f(-0.01,-1.1,0);
    glVertex3f(-0.06,-1,0);
    glEnd();
}
void house()
{
    setMaterialColor(darkbrown);
    glPushMatrix();
    glTranslatef(0.82,-1.48,0);
    glutSolidSphere(0.015,23,32);
    glPopMatrix();

    setMaterialColor(queue);
    glBegin(GL_QUADS);
    glVertex3f(0.9,-1.8,0);
    glVertex3f(0.9,-1.4,0);
    glVertex3f(0.8,-1.2,0);
    glVertex3f(0.8,-1.6,0);
    glEnd();

    setMaterialColor(house2);
    glBegin(GL_POLYGON);
    glVertex3f(0.75,-1.5,0);
    glVertex3f(0.75,-1.1,0);
    glVertex3f(0.9,-1,0);
    glVertex3f(0.95,-1.3,0);
    glVertex3f(0.95,-1.9,0);
    glEnd();

    setMaterialColor(house3);
    glBegin(GL_QUADS);
    glVertex3f(0.85,-1.4,0);
    glVertex3f(0.9,-0.98,0);
    glVertex3f(1.22,-0.98,0);
    glVertex3f(1.32,-1.35,0);
    glEnd();

    setMaterialColor(house4);
    glBegin(GL_QUADS);
    glVertex3f(0.95,-1.9,0);
    glVertex3f(0.95,-1.35,0);
    glVertex3f(1.3,-1.3,0);
    glVertex3f(1.3,-1.8,0);
    glEnd();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(0.82,-1.05,0);
    glRotatef(30,0,0,1);
    glScalef(0.2,0.05,0.7);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(0.93,-1.2,0);
    glRotatef(100,0,0,1);
    glScalef(0.4,0.03,0.7);
    glutSolidCube(1);
    glPopMatrix();
}
void work()
{
    //buttons
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.68,-0.055,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.1,0.1,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.58,0.02,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.1,0.1,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.58,-0.13,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.1,0.1,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.48,-0.055,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.1,0.1,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.47,0.095,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.13,0.09,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.37,0.03,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.15,0.09,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.47,-0.18,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.15,0.07,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.3,-0.06,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.2,0.07,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();
    //screen
    setMaterialColor(screen);
    glPushMatrix();
    glTranslatef(-1.65,0.12,0.05);
    glRotatef(35,0,0,1);
    glScalef(0.45,0.1,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

    //borders
    setMaterialColor(mborder);
    glPushMatrix();
    glTranslatef(-1.29,-0.14,0.05);
    glRotatef(33,0,0,1);
    glScalef(0.5,0.02,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(mborder);
    glPushMatrix();
    glTranslatef(-1.71,-0.15,0.05);
    glRotatef(-33,0,0,1);
    glScalef(0.5,0.02,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(mborder);
    glPushMatrix();
    glTranslatef(-1.5,-0.38,0.05);
    glRotatef(90,0,0,1);
    glScalef(0.22,0.02,1);
    glutSolidCube(1);
    glPopMatrix();

    //machine
    setMaterialColor(machine);
    glPushMatrix();
    glTranslatef(-1.5,-0.1,0);
    glRotatef(-90,0,1,1);
    glScalef(0.5,1,1);
    glutSolidCube(0.6);
    glPopMatrix();

    setMaterialColor(red);
    glRasterPos3f(-1.93,0.35,0);
    char msg[]="WORKING";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);
    glRasterPos3f(-1.92,0.25,0);
    char msg1[]="MACHINE";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg1[i]);

    //chair
    setMaterialColor(house3);
    glPushMatrix();
    glTranslatef(-1.03,-0.49,0.05);
    glScalef(0.2,0.06,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-1.09,-0.58,0.05);
    glRotatef(90,0,0,1);
    glScalef(0.2,0.04,1);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(brown);
    glPushMatrix();
    glTranslatef(-0.97,-0.58,0.05);
    glRotatef(90,0,0,1);
    glScalef(0.2,0.04,1);
    glutSolidCube(1);
    glPopMatrix();
}
void clock()
{
    setMaterialColor(red);
    glPushMatrix();
    glTranslatef(-1.45,-1.53,0);
    glutSolidTorus(0.01f,0.09f,40,32);
    glPopMatrix();

    setMaterialColor(white);
    glPushMatrix();
    glTranslatef(-1.45,-1.53,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    setMaterialColor(black);
    glDisable(GL_DEPTH_TEST);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(-1.45,-1.52,0);
    glVertex3f(-1.45,-1.46,0);
    glEnd();

    setMaterialColor(black);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(-1.45,-1.53,0);
    glVertex3f(-1.4,-1.57,0);
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.45,-1.53,0);
    glutSolidTorus(0.005f,0.01f,40,32);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

    setMaterialColor(black);
    glBegin(GL_QUADS);
    glVertex3f(-1.5,-1.6,0);
    glVertex3f(-1.4,-1.6,0);
    glVertex3f(-1.35,-1.7,0);
    glVertex3f(-1.55,-1.7,0);
    glEnd();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.55,-1.45,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.35,-1.45,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
}
float crowY=1.8;
int crowflag=0;
void crow()
{
    setMaterialColor(black);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(-1.8,crowY,0);
    glVertex3f(-1.75,1.75,0);
    glVertex3f(-1.75,1.75,0);
    glVertex3f(-1.7,crowY,0);
    glEnd();
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.75,1.75,0);
    glutSolidTorus(0.005f,0.01f,40,32);
    glPopMatrix();

}
void scenary()
{
    //crow
    crow();
    glPushMatrix();
    glTranslatef(1.1,0,0);
    crow();
    glPopMatrix();
    if(crowflag==0)
    {
        crowY-=0.001;
        if(crowY<1.7)
            crowflag=1;
    }
    if(crowflag==1)
    {
        crowY+=0.001;
        if(crowY>1.8)
            crowflag=0;
    }
    //sun
    setMaterialColor(sunT);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.08,1.77,0);
    glVertex3f(-1.02,1.8,0);
    glVertex3f(-1.02,1.73,0);

    glVertex3f(-1.02,1.73,0);
    glVertex3f(-0.97,1.72,0);
    glVertex3f(-1.02,1.68,0);

    glVertex3f(-1.02,1.68,0);
    glVertex3f(-0.99,1.63,0);
    glVertex3f(-1.06,1.64,0);

    glVertex3f(-1.05,1.64,0);
    glVertex3f(-1.045,1.58,0);
    glVertex3f(-1.1,1.62,0);

    glVertex3f(-1.1,1.62,0);
    glVertex3f(-1.15,1.58,0);
    glVertex3f(-1.15,1.63,0);

    glVertex3f(-1.15,1.63,0);
    glVertex3f(-1.2,1.63,0);
    glVertex3f(-1.18,1.68,0);

    glVertex3f(-1.18,1.68,0);
    glVertex3f(-1.23,1.72,0);
    glVertex3f(-1.14,1.75,0);

    glVertex3f(-1.17,1.75,0);
    glVertex3f(-1.17,1.81,0);
    glVertex3f(-1.11,1.78,0);

    glVertex3f(-1.12,1.78,0);
    glVertex3f(-1.08,1.83,0);
    glVertex3f(-1.06,1.77,0);
    glEnd();
    setMaterialColor(sun);
    glPushMatrix();
    glTranslatef(-1.1,1.7,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();
    //tree
    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.7,1.3,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.78,1.33,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.6,1.3,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.54,1.36,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.54,1.45,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.6,1.5,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.7,1.5,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.8,1.45,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    setMaterialColor(green);
    glTranslatef(-1.67,1.43,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    setMaterialColor(brown);
    glBegin(GL_QUADS);
    glVertex3f(-1.7,1,0);
    glVertex3f(-1.7,1.3,0);
    glVertex3f(-1.6,1.3,0);
    glVertex3f(-1.6,1,0);
    glEnd();
    //background
    setMaterialColor(sky);
    glBegin(GL_QUADS);
    glVertex3f(-2,1,0);
    glVertex3f(-2,2,0);
    glVertex3f(-0.3,2,0);
    glVertex3f(-0.3,1,0);
    glEnd();
    setMaterialColor(sky);
    glBegin(GL_QUADS);
    glVertex3f(1.7,1,0);
    glVertex3f(1.7,2,0);
    glVertex3f(2,2,0);
    glVertex3f(2,1,0);
    glEnd();
    setMaterialColor(sky);
    glBegin(GL_QUADS);
    glVertex3f(-0.3,1.8,0);
    glVertex3f(-0.3,2,0);
    glVertex3f(1.7,2,0);
    glVertex3f(1.7,1.8,0);
    glEnd();
}
void people(char name[],char number[])
{
    //head
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(-0.08,1.5,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();
    //ears
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(-0.16,1.5,0);
    glutSolidTorus(0.013f,0.015f,30,32);
    glPopMatrix();
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glutSolidTorus(0.013f,0.015f,30,32);
    glPopMatrix();
    //eyes,mouth
    glDisable(GL_DEPTH_TEST);
    setMaterialColor(black);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(-0.04,1.51,0);
    glVertex3f(-0.11,1.51,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.1,1.46,0);
    glVertex3f(-0.05,1.46,0);
    glEnd();
    glEnable(GL_DEPTH_TEST);
    //neck
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.11,1.43,0);
    glVertex3f(-0.05,1.43,0);
    glVertex3f(-0.05,1.39,0);
    glVertex3f(-0.11,1.39,0);
    glEnd();
    //shirt
    setMaterialColor(red);
    glBegin(GL_POLYGON);
    glVertex3f(-0.12,1.39,0);
    glVertex3f(-0.04,1.39,0);
    glVertex3f(0.01,1.35,0);
    glVertex3f(-0.02,1.28,0);
    glVertex3f(-0.04,1.38,0);
    glVertex3f(-0.04,1.14,0);
    glVertex3f(-0.12,1.14,0);
    glVertex3f(-0.12,1.31,0);
    glVertex3f(-0.14,1.28,0);
    glVertex3f(-0.17,1.35,0);
    glEnd();
    //pant
    setMaterialColor(brown);
    glBegin(GL_QUADS);
    glVertex3f(-0.12,1.14,0);
    glVertex3f(-0.07,1.14,0);
    glVertex3f(-0.08,0.93,0);
    glVertex3f(-0.12,0.93,0);

    glVertex3f(-0.08,1.14,0);
    glVertex3f(-0.04,1.14,0);
    glVertex3f(-0.04,0.93,0);
    glVertex3f(-0.073,0.93,0);
    glEnd();
    //legs
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.115,0.93,0);
    glVertex3f(-0.0855,0.93,0);
    glVertex3f(-0.0855,0.83,0);
    glVertex3f(-0.115,0.83,0);

    glVertex3f(-0.064,0.93,0);
    glVertex3f(-0.04,0.93,0);
    glVertex3f(-0.04,0.83,0);
    glVertex3f(-0.064,0.83,0);
    glEnd();
    //shoes
    setMaterialColor(black);
    glBegin(GL_QUADS);
    glVertex3f(-0.0855,0.83,0);
    glVertex3f(-0.13,0.83,0);
    glVertex3f(-0.13,0.8,0);
    glVertex3f(-0.0855,0.8,0);

    glVertex3f(-0.064,0.83,0);
    glVertex3f(-0.025,0.83,0);
    glVertex3f(-0.025,0.8,0);
    glVertex3f(-0.064,0.8,0);
    glEnd();
    //right hand
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.15,1.35,0);
    glVertex3f(-0.14,1.29,0);
    glVertex3f(-0.18,1.2,0);
    glVertex3f(-0.2,1.25,0);

    glVertex3f(-0.2,1.25,0);
    glVertex3f(-0.16,1.27,0);
    glVertex3f(-0.12,1.14,0);
    glVertex3f(-0.12,1.07,0);
    glEnd();
    //lefthand
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.02,1.29,0);
    glVertex3f(-0.01,1.36,0);
    glVertex3f(0.05,1.29,0);
    glVertex3f(0.02,1.25,0);

    glVertex3f(0.02,1.25,0);
    glVertex3f(0.05,1.29,0);
    glVertex3f(0.05,1.17,0);
    glVertex3f(0.02,1.17,0);
    glEnd();
    //handbag
    setMaterialColor(handbag);
    glBegin(GL_QUADS);
    glVertex3f(0.045,1.17,0);
    glVertex3f(0.025,1.17,0);
    glVertex3f(0.025,1.1,0);
    glVertex3f(0.045,1.1,0);

    glVertex3f(0,1.1,0);
    glVertex3f(0,0.9,0);
    glVertex3f(0.07,0.9,0);
    glVertex3f(0.07,1.1,0);
    glEnd();
    //hair
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-0.08,1.6,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.13,1.57,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.03,1.57,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();

    glDisable(GL_DEPTH_TEST);
    setMaterialColor(white);
    glRasterPos3f(-0.1,1.2,0);
    for(int i=0;i<strlen(name);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
    setMaterialColor(white);
    glRasterPos3f(0.01,0.97,0);
    for(int i=0;i<strlen(number);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,number[i]);
    glEnable(GL_DEPTH_TEST);
}

int time=0;
void timer(int time)
{
    setMaterialColor(black);
    glRasterPos3f(-1.12,-1.44,0);
    char msg1[4];
    sprintf(msg1,"%d",time);
    for(int i=0;i<strlen(msg1);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);
}
int count=1;
void wait()
{
    if(count==1 | count==300 | count==600 | count==900)
       time++;
    count+=1;
    if(count==901)
        count=-300;
}
void peopleside(char name[],char number[])
{
    glDisable(GL_DEPTH_TEST);
    //head
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(-0.8,0.35,0);
    glutSolidSphere(0.09,40,32);
    glPopMatrix();
    //eyes,mouth
    setMaterialColor(black);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(-0.75,0.37,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.75,0.315,0);
    glVertex3f(-0.72,0.315,0);
    glEnd();
    //hair
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-0.8,0.43,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.85,0.40,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.83,0.36,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.83,0.30,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.87,0.34,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    //neck
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.83,0.265,0);
    glVertex3f(-0.77,0.265,0);
    glVertex3f(-0.77,0.21,0);
    glVertex3f(-0.83,0.21,0);
    glEnd();
    //shirt
    setMaterialColor(red);
    glBegin(GL_QUADS);
    glVertex3f(-0.84,0.21,0);
    glVertex3f(-0.76,0.21,0);
    glVertex3f(-0.76,-0.03,0);
    glVertex3f(-0.84,-0.03,0);
    glEnd();
    //hands
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.82,0.19,0);
    glVertex3f(-0.78,0.19,0);
    glVertex3f(-0.78,0,0);
    glVertex3f(-0.82,0,0);
    glEnd();
    //pant
    setMaterialColor(brown);
    glBegin(GL_QUADS);
    glVertex3f(-0.83,-0.03,0);
    glVertex3f(-0.77,-0.03,0);
    glVertex3f(-0.77,-0.15,0);
    glVertex3f(-0.83,-0.15,0);
    glEnd();
    //legs
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-0.82,-0.15,0);
    glVertex3f(-0.78,-0.15,0);
    glVertex3f(-0.78,-0.25,0);
    glVertex3f(-0.82,-0.25,0);
    glEnd();
    //handbag
    setMaterialColor(handbag);
    glBegin(GL_QUADS);
    glVertex3f(-0.79,0,0);
    glVertex3f(-0.79,-0.05,0);
    glVertex3f(-0.81,-0.05,0);
    glVertex3f(-0.81,0,0);

    glVertex3f(-0.835,-0.21,0);
    glVertex3f(-0.835,-0.05,0);
    glVertex3f(-0.765,-0.05,0);
    glVertex3f(-0.765,-0.21,0);
    glEnd();
    //shoes
    setMaterialColor(black);
    glBegin(GL_QUADS);
    glVertex3f(-0.82,-0.25,0);
    glVertex3f(-0.82,-0.29,0);
    glVertex3f(-0.77,-0.29,0);
    glVertex3f(-0.77,-0.25,0);
    glEnd();
    setMaterialColor(white);
    glRasterPos3f(-0.821,-0.16,0);
    for(int i=0;i<strlen(number);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,number[i]);
    glEnable(GL_DEPTH_TEST);
}
int flag=0,stop=0;
float px=0,py=0,bx=0.5,cx=1,dx=1.5,mx=0,by=0,my=0,hx=0,hy=-1.5,cy=0,dy=0;
char Anumber[]="24";char Dnumber[]="08";
void gohome(char name[])
{
       if(hx<1)
       {
            glPushMatrix();
            glTranslatef(hx,0,0);
            peopleside(name,"00");
            glPopMatrix();
            hx+=0.002;
       }
        else
        {
            if(hy>-2.2)
            {
                glPushMatrix();
                glTranslatef(0.4,hy,0);
                glDisable(GL_DEPTH_TEST);
                people(name,"00");
                glEnable(GL_DEPTH_TEST);
                glPopMatrix();
                hy-=0.002;
            }
            else
            {
                if(hx<1.4)
                {
                    glPushMatrix();
                    glTranslatef(hx,-1.4,0);
                    peopleside(name,"00");
                    glPopMatrix();
                    hx+=0.002;
                }
                else
                    flag=1;
            }
        }
}
void backtoqueue(char name[],char number[])
{
         if(name=="A")
           strcpy(Anumber,number);
         else
            strcpy(Dnumber,number);
         if(mx<2.2)
         {
            glPushMatrix();
            glTranslatef(mx,0,0);
            peopleside(name,number);
            glPopMatrix();
            mx+=0.002;
         }
         else
         {
             if(my<1)
             {
               glPushMatrix();
               glTranslatef(0,my,0);
               personbehind(name,number);
               glPopMatrix();
               my+=0.002;
             }
             else
             {
                 if(name=="A")
                 {
                   if(px<=0)
                     px=1.5,py=0.00001;
                   if(px>0.5)
                     px-=0.001;
                 }
                 else
                 {
                     if(dx<=0)
                       dx=1.5,dy=0.00001;
                     if(dx>2)
                       dx-=0.001;
                 }
             }
         }
}
int pause=0;
void result()
{
    if(pause>2800)
    {
    glRasterPos3f(0.25,-0.1,0);
    char msg11[]="AVERAGE TURN AROUND TIME:   8+10+22+38 = 19.5";
    for(int i=0;i<strlen(msg11);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg11[i]);
    glRasterPos3f(1.14,-0.25,0);
    char msg12[]="4";
    for(int i=0;i<strlen(msg12);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg12[i]);
    setMaterialColor(brown);
    glBegin(GL_LINES);
    glVertex3f(1.02,-0.15,0);
    glVertex3f(1.27,-0.15,0);
    glEnd();
    }
    if(pause>3000)
    {
    glRasterPos3f(0.25,-0.6,0);
    char msg13[]="AVERAGE WAITING TIME:   4+8+14+14 = 10";
    for(int i=0;i<strlen(msg13);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg13[i]);
    glRasterPos3f(0.98,-0.76,0);
    char msg14[]="4";
    for(int i=0;i<strlen(msg14);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg14[i]);
    glBegin(GL_LINES);
    glVertex3f(0.88,-0.65,0);
    glVertex3f(1.11,-0.65,0);
    glEnd();
    }
}
void displaythree()
{
    glClearColor(0.56,0.93,0.56,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //queue1
    setMaterialColor(border);
    glPushMatrix();
    glTranslatef(-0.7,1.08,-0.5);
    glRotatef(90,1,0,0);
    glScalef(2.1,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    //lines
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-1.464,1.58,0);
    glVertex3f(-1.464,0.575,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-1.164,1.58,0);
    glVertex3f(-1.164,0.575,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-0.864,1.58,0);
    glVertex3f(-0.864,0.575,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-0.564,1.58,0);
    glVertex3f(-0.564,0.575,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-0.264,1.58,0);
    glVertex3f(-0.264,0.575,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(0.04,1.58,0);
    glVertex3f(0.04,0.575,0);
    glEnd();
    setMaterialColor(brown);
    glRasterPos3f(-1.4,1.65,0);
    char msg[]="ORDER IN WHICH WORKING MACHINE WAS USED";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);
    pause+=1;
    if(pause>50)
    {
    //people
    glPushMatrix();
    glTranslatef(-1.55,-0.15,0);
    people("A","24");
    glPopMatrix();
    }
    if(pause>100)
    {
    glPushMatrix();
    glTranslatef(-1.25,-0.15,0);
    people("B","04");
    glPopMatrix();
    }
    if(pause>150)
    {
    glPushMatrix();
    glTranslatef(-0.95,-0.15,0);
    people("C","02");
    glPopMatrix();
    }
    if(pause>200)
    {
    glPushMatrix();
    glTranslatef(-0.65,-0.15,0);
    people("D","08");
    glPopMatrix();
    }
    if(pause>250)
    {
    glPushMatrix();
    glTranslatef(-0.35,-0.15,0);
    people("A","20");
    glPopMatrix();
    }
    if(pause>300)
    {
    glPushMatrix();
    glTranslatef(-0.05,-0.15,0);
    people("D","04");
    glPopMatrix();
    }
    if(pause>350)
    {
    glPushMatrix();
    glTranslatef(0.25,-0.15,0);
    people("A","16");
    glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(2.6,2.7,0);
    clock();
    glPopMatrix();
    setMaterialColor(brown);
    glRasterPos3f(0.95,0.88,0);
    char msg1[]="TIME QUANTUM = 4";
    for(int i=0;i<strlen(msg1);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg1[i]);
    setMaterialColor(brown);
    glRasterPos3f(-1.8,0.5,0);
    char msg2[]="048";
    float x=1.8;
    for(int i=0;i<strlen(msg2);i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg2[i]);
       x=x-0.32;
       glRasterPos3f(-x,0.5,0);
    }
    setMaterialColor(brown);
    glRasterPos3f(-0.86,0.5,0);
    char msg3[]="1014182238";
    float xx=0.86;
    for(int i=0;i<strlen(msg3);i=i+2)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg3[i]);
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg3[i+1]);
       xx=xx-0.3;
       glRasterPos3f(-xx,0.5,0);
    }
    if(pause>700)
    {
    glPushMatrix();
    glTranslatef(-1.15,0.52,0);
    glutSolidTorus(0.01,0.06,32,32);
    glPopMatrix();

    setMaterialColor(brown);
    glRasterPos3f(-1.3,0.35,0);
    char msg4[]="B Completes";
    for(int i=0;i<strlen(msg4);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg4[i]);
    }
    if(pause>850)
    {
    glPushMatrix();
    glTranslatef(-0.84,0.52,0);
    glutSolidTorus(0.01,0.06,32,32);
    glPopMatrix();

    glRasterPos3f(-0.95,0.35,0);
    char msg5[]="C Completes";
    for(int i=0;i<strlen(msg5);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg5[i]);
    }
    if(pause>1050)
    {
    glPushMatrix();
    glTranslatef(0.07,0.52,0);
    glutSolidTorus(0.01,0.06,32,32);
    glPopMatrix();

    glRasterPos3f(-0.08,0.35,0);
    char msg6[]="D Completes";
    for(int i=0;i<strlen(msg6);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg6[i]);
    }
    if(pause>1200)
    {
    glPushMatrix();
    glTranslatef(0.37,0.52,0);
    glutSolidTorus(0.01,0.06,32,32);
    glPopMatrix();

    glRasterPos3f(0.3,0.35,0);
    char msg7[]="A Completes";
    for(int i=0;i<strlen(msg7);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg7[i]);
    }
    setMaterialColor(brown);
    glRasterPos3f(-0.9,-0.02,0);
    char msg8[]="WORK COMPLETION ORDER";
    for(int i=0;i<strlen(msg8);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg8[i]);
    //queue2
    setMaterialColor(border);
    glPushMatrix();
    glTranslatef(-0.55,-0.6,-0.5);
    glRotatef(90,1,0,0);
    glScalef(1.3,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    //lines
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-0.864,-0.1,0);
    glVertex3f(-0.864,-1.1,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-0.564,-0.1,0);
    glVertex3f(-0.564,-1.1,0);
    glEnd();
    setMaterialColor(queue);
    glBegin(GL_LINES);
    glVertex3f(-0.264,-0.1,0);
    glVertex3f(-0.264,-1.1,0);
    glEnd();
    if(pause>1400)
    {
    //people
    glPushMatrix();
    glTranslatef(-0.95,-1.8,0);
    people("B","04");
    glPopMatrix();
    }
    if(pause>1600)
    {
    glPushMatrix();
    glTranslatef(-0.65,-1.8,0);
    people("C","02");
    glPopMatrix();
    }
    if(pause>1800)
    {
    glPushMatrix();
    glTranslatef(-0.35,-1.8,0);
    people("D","08");
    glPopMatrix();
    }
    if(pause>2000)
    {
    glPushMatrix();
    glTranslatef(-0.05,-1.8,0);
    people("A","24");
    glPopMatrix();
    }
    if(pause>2300)
    {
    setMaterialColor(brown);
    glRasterPos3f(-1.7,-1.2,0);
    char msg9[]="TURN AROUND TIME:          B=8                 C=10                D=22               A=38";
    for(int i=0;i<strlen(msg9);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg9[i]);
    }
    if(pause>2600)
    {
    glRasterPos3f(-1.57,-1.4,0);
    char msg10[]="WAITING TIME:      B=8-4=4           C=10-2=8      D=22-8=14      A=38-24=14";
    for(int i=0;i<strlen(msg10);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg10[i]);
    }
    glPushMatrix();
    glTranslatef(0,-0.3,0);
    result();
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();
}
void displaytwoA()
{
    glClearColor(0.88,0.66,0.37,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setMaterialColor(red);
    glRasterPos3f(0.3,1.85,0);
    char msg[]="QUEUE";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
    road();
    //person4
    if(dx>=-0.9)
     {
      glPushMatrix();
      glTranslatef(dx,dy,0);
      people("D",Dnumber);
      glPopMatrix();
     }
     //person1
    if(px>=-0.9)
     {
      glPushMatrix();
      glTranslatef(px,py,0);
      people("A",Anumber);
      glPopMatrix();
     }
    processqueue();
    house();
    work();
    clock();
    setMaterialColor(black);
    timer(time);
    //timeboard
    setMaterialColor(white);
    glBegin(GL_QUADS);
    glVertex3f(-1.2,-1.5,0);
    glVertex3f(-1,-1.5,0);
    glVertex3f(-1,-1.3,0);
    glVertex3f(-1.2,-1.3,0);
    glEnd();
    setMaterialColor(black);
    glRasterPos3f(-1.18,-1.25,0);
    char msg3[]="TIME";
    for(int i=0;i<strlen(msg3);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);
    setMaterialColor(red);
    glRasterPos3f(-1.65,-1.85,0);
    char msg2[]="TIME QUANTUM = 4";
    for(int i=0;i<strlen(msg2);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg2[i]);
    if(stop==0)
       backtoqueue("A","16");
    if(dx>0)
        dx-=0.001;
     else
     {
         if(dy>=-1.3)
           dy-=0.002;
         if(dx>=-0.9)
          dx-=0.001;
         else
         {
             if(time<22)
             {
               peoplework("D",Dnumber);
               wait();
               stop=1;
             }
             else
             {
                 if(time<37)
                   gohome("D");
                 if(py>=-1.3)
                   py-=0.002;
                 if(px>=-0.9)
                   px-=0.001;
                else
                {
                    if(time<38)
                    {
                      peoplework("A","16");
                      wait();
                      if(time==37)
                        hx=0,hy=-1.5;
                      flag=0;
                    }
                    else
                    {
                        gohome("A");
                        if(flag==1)
                            glutDisplayFunc(displaythree);
                    }
                }
             }
         }
         if(px>0.001)
            px-=0.001;
     }
    scenary();
    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
    glutPostRedisplay();
}
void displaytwo()
{
    glClearColor(0.88,0.66,0.37,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setMaterialColor(red);
    glRasterPos3f(0.3,1.85,0);
    char msg[]="QUEUE";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
    road();
    //person4
    if(dx>=-0.9)
     {
      glPushMatrix();
      glTranslatef(dx,dy,0);
      people("D",Dnumber);
      glPopMatrix();
     }
    //person1
    if(px>=-0.9)
     {
      glPushMatrix();
      glTranslatef(px,py,0);
      people("A",Anumber);
      glPopMatrix();
     }
    processqueue();
    house();
    work();
    clock();
    setMaterialColor(black);
    timer(time);
    //timeboard
    setMaterialColor(white);
    glBegin(GL_QUADS);
    glVertex3f(-1.2,-1.5,0);
    glVertex3f(-1,-1.5,0);
    glVertex3f(-1,-1.3,0);
    glVertex3f(-1.2,-1.3,0);
    glEnd();
    setMaterialColor(black);
    glRasterPos3f(-1.18,-1.25,0);
    char msg3[]="TIME";
    for(int i=0;i<strlen(msg3);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);
    setMaterialColor(red);
    glRasterPos3f(-1.65,-1.85,0);
    char msg2[]="TIME QUANTUM = 4";
    for(int i=0;i<strlen(msg2);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg2[i]);
    //person3
    if(time<10)
    {
       peoplework("C","02");
       wait();
    }
    else
    {
       gohome("C");
       if(dy>=-1.3 && dy<=0)
          dy-=0.002;
       if(dx>=-0.9 && dx<=0)
          dx-=0.001;
       else
       {
           if(time<14)
           {
             peoplework("D",Dnumber);
             wait();
           }
           else
           {
             backtoqueue("D","04");
             if(py>=-1.3)
                 py-=0.002;
             if(px>=-0.9)
                 px-=0.001;
             else
             {
                if(time<18)
                {
                   peoplework("A","20");
                   wait();
                }
                else
                {
                   mx=0;my=0;hx=0,hy=-1.5;
                   glutDisplayFunc(displaytwoA);
                }
             }
           }
       }
       if(px>0)
          px-=0.001;
    }
    scenary();
    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
    glutPostRedisplay();
}
void displayone()
{
    glClearColor(0.88,0.66,0.37,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setMaterialColor(red);
    glRasterPos3f(0.3,1.85,0);
    char msg[]="QUEUE";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
    road();
    //person1
    if(bx>0 && cx>0.5 && dx>1)
    {
        bx-=0.001;
        cx-=0.001;
        dx-=0.001;
    }
     if(px>=-0.9)
     {
      glPushMatrix();
      glTranslatef(px,py,0);
      people("A",Anumber);
      glPopMatrix();
     }
    //person2
    if(bx>=-0.9)
    {
      glPushMatrix();
      glTranslatef(bx,by,0);
      people("B","04");
      glPopMatrix();
    }
    //person3
    glPushMatrix();
    glTranslatef(cx,cy,0);
    people("C","02");
    glPopMatrix();
    //person4
    glPushMatrix();
    glTranslatef(dx,0,0);
    people("D",Dnumber);
    glPopMatrix();

    processqueue();
    house();
    work();
    clock();
    if(py>=-1.3 && py<=0)
      py-=0.002;
    if(px>=-0.9 && px<=0)
      px-=0.001;
    else
    {
      if(time<4)
      {
       peoplework("A","24");
       wait();
      }
      else
      {
         backtoqueue("A","20");
         if(cx>0 && dx>0.5)
         {
           cx-=0.001;
           dx-=0.001;
        }
        if(by>=-1.3)
           by-=0.002;
        if(bx>=-0.9)
           bx-=0.001;
        else
        {
            if(time<8)
            {
               peoplework("B","04");
               wait();
            }
            else
            {
                gohome("B");
                if(flag==1)
                {
                    hx=0,hy=-1.5;mx=0;my=0;
                    glutDisplayFunc(displaytwo);
                }
                if(dx>0)
                   dx-=0.001;
                if(cy>=-1.3)
                  cy-=0.002;
                if(cx>=-0.9)
                  cx-=0.001;
            }
        }
      }
    }
    timer(time);
    //timeboard
    setMaterialColor(white);
    glBegin(GL_QUADS);
    glVertex3f(-1.2,-1.5,0);
    glVertex3f(-1,-1.5,0);
    glVertex3f(-1,-1.3,0);
    glVertex3f(-1.2,-1.3,0);
    glEnd();

    setMaterialColor(black);
    glRasterPos3f(-1.18,-1.25,0);
    char msg3[]="TIME";
    for(int i=0;i<strlen(msg3);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);

    setMaterialColor(red);
    glRasterPos3f(-1.65,-1.85,0);
    char msg2[]="TIME QUANTUM = 4";
    for(int i=0;i<strlen(msg2);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg2[i]);
    scenary();
    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
    glutPostRedisplay();
}
void peoplework(char msg[],char msg1[])
{
    glDisable(GL_DEPTH_TEST);
    //head
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(-1.03,0,0);
    glutSolidSphere(0.09,40,32);
    glPopMatrix();
    //eyes,mouth
    setMaterialColor(black);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(-1.07,0.03,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.115,-0.03,0);
    glVertex3f(-1.08,-0.03,0);
    glEnd();
    //hair
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-1.02,0.08,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.02,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,-0.04,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.97,0.05,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.97,-0.012,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    //neck
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-1.06,-0.08,0);
    glVertex3f(-1,-0.08,0);
    glVertex3f(-1,-0.13,0);
    glVertex3f(-1.06,-0.13,0);
    glEnd();
    //shirt
    setMaterialColor(red);
    glBegin(GL_QUADS);
    glVertex3f(-1.1,-0.13,0);
    glVertex3f(-1,-0.13,0);
    glVertex3f(-1,-0.4,0);
    glVertex3f(-1.1,-0.4,0);
    glEnd();
    //hands
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-1.1,-0.14,0);
    glVertex3f(-1.1,-0.18,0);
    glVertex3f(-1.17,-0.18,0);
    glVertex3f(-1.17,-0.14,0);

    glVertex3f(-1.1,-0.2,0);
    glVertex3f(-1.1,-0.24,0);
    glVertex3f(-1.2,-0.24,0);
    glVertex3f(-1.2,-0.2,0);
    glEnd();
    //pant
    setMaterialColor(brown);
    glBegin(GL_QUADS);
    glVertex3f(-1,-0.4,0);
    glVertex3f(-1,-0.47,0);
    glVertex3f(-1.15,-0.47,0);
    glVertex3f(-1.15,-0.4,0);

    glVertex3f(-1.12,-0.4,0);
    glVertex3f(-1.17,-0.4,0);
    glVertex3f(-1.17,-0.54,0);
    glVertex3f(-1.12,-0.54,0);
    glEnd();
    //legs
    setMaterialColor(body);
    glBegin(GL_QUADS);
    glVertex3f(-1.161,-0.54,0);
    glVertex3f(-1.125,-0.54,0);
    glVertex3f(-1.125,-0.64,0);
    glVertex3f(-1.161,-0.64,0);
    glEnd();
    //shoes
    setMaterialColor(black);
    glBegin(GL_QUADS);
    glVertex3f(-1.125,-0.64,0);
    glVertex3f(-1.125,-0.68,0);
    glVertex3f(-1.19,-0.68,0);
    glVertex3f(-1.19,-0.64,0);
    glEnd();
    //palm
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(-1.17,-0.16,0);
    glutSolidTorus(0.013f,0.015f,30,32);
    glPopMatrix();
    setMaterialColor(body);
    glPushMatrix();
    glTranslatef(-1.2,-0.22,0);
    glutSolidTorus(0.013f,0.015f,30,32);
    glPopMatrix();
    //handbag
    setMaterialColor(handbag);
    glBegin(GL_QUADS);
    glVertex3f(-1.2,-0.4,0);
    glVertex3f(-1.2,-0.58,0);
    glVertex3f(-1.27,-0.58,0);
    glVertex3f(-1.27,-0.4,0);

    glVertex3f(-1.245,-0.4,0);
    glVertex3f(-1.245,-0.34,0);
    glVertex3f(-1.225,-0.34,0);
    glVertex3f(-1.225,-0.4,0);
    glEnd();
    setMaterialColor(white);
    glRasterPos3f(-1.05,-0.3,0);
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
    setMaterialColor(white);
    glRasterPos3f(-1.26,-0.53,0);
    for(int i=0;i<strlen(msg1);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg1[i]);
    glEnable(GL_DEPTH_TEST);
}
void personbehind(char name[],char number[])
{
    glPushMatrix();
    glTranslatef(1.5,-1,0);
    glDisable(GL_DEPTH_TEST);
    people(name,number);
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    //behindhair
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(1.35,0.5,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.41,0.53,0);
    glutSolidSphere(0.06,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.49,0.5,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.39,0.45,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.45,0.45,0);
    glutSolidSphere(0.04,40,32);
    glPopMatrix();
}
void keys(unsigned char key,int x,int y)
{
    if(key=='1')
    {
        glutDisplayFunc(displayone);
        glutPostRedisplay();
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Process scheduling algorithms");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    initLight();
    glutMainLoop();
    return 0;
}

