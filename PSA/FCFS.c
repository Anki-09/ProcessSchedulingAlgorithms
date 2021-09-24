#include<GL/glut.h>;
#include<string.h>
float manx=0,many=0,b1x=0,b1y=0,b2x=0.4,b2y=0,b3x=0.8,b3y=0,b4x=1.2,b4y=0,mx=-0.55,my=0.2;
int flag=0,flag1=0,flag2=0,flag3=0,star=0;
float red[]={1,0,0};
float brown[]={0.8,0.4,0};
float black[]={0,0,0};
float blue[]={0,0,1};
float b1col[]={0,1,1};
float b2col[]={1,1,0};
float white[]={1,1,1};
float grey[]={0.80,0.76,0.80};
float trx[]={0.560784,0.560784,0.737255};
float sky[]={0.54,0.92,1};
float hills[]={0.576471,0.858824,0.439216};
float hillsb[]={0.184314,0.309804,0.184314};
float sun[]={0.99,0.72,0.07};
float suns[]={1,0.94,0.1};
float green[]={0,1,0};
float rocks[]={0.75,0.75,0.75};
float cactus[]={0.32,0.49,0.46};
float root[]={0.8,0,0};
float skin[]={1,0.76,0.69};
float tie[]={0.5,0.76,1};
float subtitle[]={0.5,0.5,1};
float dgrey[]={0.5,0.5,0.5};
float mountb[]={0.36,0.25,0.20};
float slideb[]={1,0.5,0};
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
void welcome()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setMaterialColor(black);
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setMaterialColor(black);
    glRasterPos3f(-0.5,0.5,0);
    char msg1[]="FIRST COME FIRST SERVE";
    for(int i=0;i<strlen(msg1);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);

    glRasterPos3f(-0.5,-1.5,0);
    char msg2[]="PRESS 'x' OR 'X' TO CONTINUE......";
    for(int i=0;i<strlen(msg2);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg2[i]);
    glutSwapBuffers();
}
void slide()
{
    //mountain fill color
    setMaterialColor(brown);
    glBegin(GL_QUADS);
    glVertex3f(-2,0.28,0);
    glVertex3f(-0.27,0.28,0);
    glVertex3f(0.1,-1.13,0);
    glVertex3f(-2,-1.13,0);
    glEnd();

    //slider lines
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(6,0x00FF);
    setMaterialColor(black);
    glBegin(GL_LINES);
    glVertex3f(-0.25,1,0);
    glVertex3f(0.2,-0.8,0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    //slider fill color
    setMaterialColor(red);
    glBegin(GL_QUADS);
    glVertex3f(-0.25,0.29,0);
    glVertex3f(-0.25,1.53,0);
    glVertex3f(0.37,-0.76,0);
    glVertex3f(0.12,-1.1,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.13,-1.08,0);
    glVertex3f(0.37,-0.76,0);
    glVertex3f(0.59,-0.76,0);
    glVertex3f(0.6,-1.08,0);
    glEnd();
}
void blocks(char msg,float x,float y)
{
    setMaterialColor(black);
    glRasterPos3f(x,y,0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg);

    //block
    glBegin(GL_QUADS);
    setMaterialColor(b1col);
    glVertex3f(-1.8,0.5,0); //anti
    glVertex3f(-1.6,0.5,0);
    glVertex3f(-1.6,0.9,0);
    glVertex3f(-1.8,0.9,0);

    setMaterialColor(dgrey);
    glVertex3f(-1.8,0.5,0); //anti
    glVertex3f(-1.8,0.9,0);
    glVertex3f(-1.85,0.8,0);
    glVertex3f(-1.85,0.4,0);

    setMaterialColor(b2col);
    glVertex3f(-1.65,0.4,0);    //anti
    glVertex3f(-1.6,0.5,0);
    glVertex3f(-1.8,0.5,0);
    glVertex3f(-1.85,0.4,0);
    glEnd();

    glDisable(GL_DEPTH_TEST);
    //circles inside block
    setMaterialColor(blue);
    glPushMatrix();
    glTranslatef(-1.75,0.55,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75,0.85,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.65,0.55,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.65,0.85,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}
float theta=0;
void truck()
{
    setMaterialColor(blue);
    glPushMatrix();
    glTranslatef(0.65,-0.93,0);
    glRotatef(90,0,0,1);
    glScalef(0.4,0.03,0.7);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(grey);
    glBegin(GL_QUADS);
    glVertex3f(0.65,-1.12,0);
    glVertex3f(0.65,-0.73,0);
    glVertex3f(1,-0.68,0);
    glVertex3f(1,-1.12,0);
    glEnd();

    setMaterialColor(blue);
    glPushMatrix();
    glTranslatef(1.1,-0.5,0);
    glScalef(0.2,0.03,0.7);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(grey);
    glPushMatrix();
    glTranslatef(0.99,-0.61,0);
    glRotatef(80,0,0,1);
    glScalef(0.2,0.03,0.7);
    glutSolidCube(1);
    glPopMatrix();
    glDisable(GL_DEPTH_TEST);

    setMaterialColor(black);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.7,-0.82,0);
    glVertex3f(0.7,-0.78,0);
    glVertex3f(0.95,-0.75,0);
    glVertex3f(0.95,-0.78,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(0.72,-0.82,0);
    glVertex3f(0.74,-0.81,0);
    glVertex3f(0.74,-0.97,0);
    glVertex3f(0.72,-0.97,0);
    glVertex3f(0.72,-0.82,0);

    glVertex3f(0.78,-0.81,0);
    glVertex3f(0.8,-0.81,0);
    glVertex3f(0.8,-0.97,0);
    glVertex3f(0.78,-0.97,0);
    glVertex3f(0.78,-0.81,0);

    glVertex3f(0.84,-0.8,0);
    glVertex3f(0.86,-0.8,0);
    glVertex3f(0.86,-0.97,0);
    glVertex3f(0.84,-0.97,0);
    glVertex3f(0.84,-0.8,0);

    glVertex3f(0.9,-0.79,0);
    glVertex3f(0.92,-0.79,0);
    glVertex3f(0.92,-0.97,0);
    glVertex3f(0.9,-0.97,0);
    glVertex3f(0.9,-0.79,0);
    glEnd();

    setMaterialColor(trx);
    glBegin(GL_QUADS);
    glVertex3f(1.03,-1.14,0);
    glVertex3f(1.03,-0.68,0);
    glVertex3f(1.22,-0.68,0);
    glVertex3f(1.22,-1.14,0);

    glVertex3f(1.03,-0.68,0);
    glVertex3f(1.05,-0.6,0);
    glVertex3f(1.21,-0.6,0);
    glVertex3f(1.22,-0.68,0);

    glVertex3f(1.22,-0.76,0);
    glVertex3f(1.22,-1.14,0);
    glVertex3f(1.3,-1.14,0);
    glVertex3f(1.3,-0.76,0);
    glEnd();

    setMaterialColor(black);
    glBegin(GL_LINES);
    glVertex3f(1.07,-0.65,0);
    glVertex3f(1.07,-1.05,0);

    glVertex3f(1.17,-0.65,0);
    glVertex3f(1.17,-1.05,0);

    glVertex3f(1.07,-1.05,0);
    glVertex3f(1.17,-1.05,0);

    glVertex3f(1.07,-0.65,0);
    glVertex3f(1.17,-0.65,0);

    glVertex3f(1.09,-0.69,0);
    glVertex3f(1.09,-0.78,0);

    glVertex3f(1.15,-0.69,0);
    glVertex3f(1.15,-0.78,0);

    glVertex3f(1.09,-0.69,0);
    glVertex3f(1.15,-0.69,0);

    glVertex3f(1.09,-0.78,0);
    glVertex3f(1.15,-0.78,0);

    glVertex3f(1.22,-0.65,0);
    glVertex3f(1.2,-0.69,0);

    glVertex3f(1.22,-0.73,0);
    glVertex3f(1.2,-0.77,0);

    glVertex3f(1.2,-0.69,0);
    glVertex3f(1.2,-0.77,0);

    glVertex3f(1.225,-0.77,0);
    glVertex3f(1.225,-0.84,0);

    glVertex3f(1.225,-0.84,0);
    glVertex3f(1.3,-0.84,0);

    glVertex3f(1,-0.78,0);
    glVertex3f(1.03,-0.78,0);

    glVertex3f(1,-0.78,0);
    glVertex3f(1.03,-0.78,0);

    glVertex3f(1,-0.8,0);
    glVertex3f(1.03,-0.8,0);

    glVertex3f(1,-0.76,0);
    glVertex3f(1.03,-0.76,0);

    glVertex3f(1,-0.74,0);
    glVertex3f(1.03,-0.74,0);

    glVertex3f(1,-0.72,0);
    glVertex3f(1.03,-0.72,0);

    glVertex3f(1,-0.7,0);
    glVertex3f(1.03,-0.7,0);

    glVertex3f(1,-0.68,0);
    glVertex3f(1.03,-0.68,0);

    glVertex3f(0.995,-0.66,0);
    glVertex3f(1.04,-0.66,0);

    glVertex3f(0.995,-0.64,0);
    glVertex3f(1.04,-0.64,0);

    glVertex3f(1,-1.1,0);
    glVertex3f(1.03,-1.1,0);
    glEnd();

    setMaterialColor(blue);
    glPushMatrix();
    glTranslatef(0.8,-1.13,0);
    glScalef(0.2,0.03,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.68,-1.16,0);
    glRotatef(60,0,0,1);
    glScalef(0.1,0.02,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.66,-1.25,0);
    glRotatef(90,0,0,1);
    glScalef(0.1,0.02,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.92,-1.18,0);
    glRotatef(-70,0,0,1);
    glScalef(0.15,0.02,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.015,-1.25,0);
    glScalef(0.15,0.02,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1,-1.2,0);
    glRotatef(-90,0,0,1);
    glScalef(0.13,0.02,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.16,-1.15,0);
    glScalef(0.145,0.02,0.7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.235,-1.2,0);
    glRotatef(-90,0,0,1);
    glScalef(0.13,0.01,0.7);
    glutSolidCube(1);
    glPopMatrix();

    setMaterialColor(black);
    glBegin(GL_LINES);
    glVertex3f(1.3,-1.1,0);
    glVertex3f(1.32,-1.1,0);

    glVertex3f(1.24,-1.2,0);
    glVertex3f(1.32,-1.2,0);

    glVertex3f(1.32,-1.1,0);
    glVertex3f(1.32,-1.2,0);

    glVertex3f(0.98,-1.25,0);
    glVertex3f(0.98,-1.15,0);

    glVertex3f(1.05,-1.25,0);
    glVertex3f(1.05,-1.15,0);

    glVertex3f(0.98,-1.15,0);
    glVertex3f(1.05,-1.15,0);

    glVertex3f(1.01,-1.25,0);
    glVertex3f(1.01,-1.15,0);

    glVertex3f(1.02,-1.25,0);
    glVertex3f(1.02,-1.15,0);
    glEnd();

    //wheel
    theta+=0.5;
    glPushMatrix();
    glTranslatef(0.73,-1.22,0);
    if(b4x>2.3)
        glRotatef(theta,0,0,1);
    glutSolidSphere(0.06,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85,-1.22,0);
    if(b4x>2.3)
        glRotatef(theta,0,0,1);
    glutSolidSphere(0.06,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.17,-1.22,0);
    if(b4x>2.3)
        glRotatef(theta,0,0,1);
    glutSolidSphere(0.06,12,6);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}
float truckx=-0.2,trucky=0.3;
int flag4=0,flag8=0,flag12=0,flag16=0,cnt=0;
void truckdisp()
{
    if(b4x>2.3 && b4x<3.8)
        truckx+=0.003;
    if(b4x>3.8 && truckx<-0.12)
        flag4=1;
    if(b4x>3.8 && flag4==0)
        truckx-=0.003;

    if(b3x>2.3 && b3x<3.8)
        truckx+=0.003;
    if(b3x>3.8 && truckx<-0.12)
        flag8=1;
    if(b3x>3.8 && flag8==0)
        truckx-=0.003;

    if(b2x>2.3 && b2x<3.8)
        truckx+=0.003;
    if(b2x>3.8 && truckx<-0.12)
        flag12=1;
    if(b2x>3.8 && flag12==0)
        truckx-=0.003;

    if(b1x>2.3 && b1x<3.8)
        truckx+=0.003;
    if(b1x>3.8 && truckx<-0.12)
        flag16=1;
    if(b1x>=3.8 && flag16==0)
        truckx-=0.003;
    glPushMatrix();
    glTranslatef(truckx,trucky,0);
    glScalef(1.4,1.3,0);
    truck();
    glPopMatrix();
}
int count=0,count1=0,count2=0,count3=0,flag5=0,flag6=0,flag7=0,flag9=0,flag10=0,flag11=0,flag13=0,flag14=0,flag15=0;
void blockdisplay()
{
    truckdisp();
    glLoadIdentity();
    setMaterialColor(black);
    glRasterPos3f(-1.2,1.2,0);
    char msg[]="BLOCKS";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);

    if(b1x>2.3)
        flag15=1;
    if(b1y<-1.5)
    {
        flag14=1;
        if(flag15==0)
        {
            b1x+=0.003;
            count3++;
        }
    }
    if(b1x>1.6 && flag14==0)
    {
        flag13=1;
        b1x+=0.0007;
        b1y-=0.003;
        count3++;
    }
    if(manx<-1.2 && flag13==0)
    {
        b1x+=0.003;
        count3++;
    }
    //block1
    glPushMatrix();
    glTranslatef(b1x,b1y,0);
    if(b1x>1.6)
    {
        glTranslatef(mx,my,0);
        glScalef(0.7,0.7,0);
    }
    if(b1x>2.3 && count3==1150)
    {
        glTranslatef(0.6,0.3,0);
        b1x+=0.003;
    }
    blocks('6',-1.7,0.7);
    glPopMatrix();

    if(b2x>2.3)
        flag11=1;
    if(b2y<-1.5)
    {
        flag10=1;
        if(flag11==0)
        {
            b2x+=0.003;
            count2++;
        }
    }
    if(b2x>1.6 && flag10==0)
    {
        flag9=1;
        b2x+=0.0007;
        b2y-=0.003;
        count2++;
    }
    if(manx<-0.8 && flag9==0)
    {
        b2x+=0.003;
        count2++;
    }
    //block2
    glPushMatrix();
    glTranslatef(b2x,b2y,0);
    if(b2x>1.6)
    {
        glTranslatef(mx,my,0);
        glScalef(0.7,0.7,0);
    }
    if(b2x>2.3 && count2==1017)
    {
        glTranslatef(0.6,0.3,0);
        b2x+=0.003;
    }
    blocks('3',-1.7,0.7);
    glPopMatrix();

    if(b3x>2.3)
        flag7=1;
    if(b3y<-1.5)
    {
        flag6=1;
        if(flag7==0)
        {
            b3x+=0.003;
            count1++;
        }
    }
    if(b3x>1.6 && flag6==0)
    {
        flag5=1;
        b3x+=0.0007;
        b3y-=0.003;
        count1++;
    }
    if(manx<-0.4 && flag5==0)
    {
        b3x+=0.003;
        count1++;
    }
    //block3
    glPushMatrix();
    glTranslatef(b3x,b3y,0);
    if(b3x>1.6)
    {
        glTranslatef(mx,my,0);
        glScalef(0.7,0.7,0);
    }
    if(b3x>2.3 && count1==884)
    {
        glTranslatef(0.6,0.3,0);
        b3x+=0.003;
    }
    blocks('8',-1.7,0.7);
    glPopMatrix();

    if(b4x>2.3)
        flag3=1;
    if(b4y<-1.5)
    {
        flag2=1;
        if(flag3==0)
        {
            b4x+=0.003;
            count++;
        }
    }
    if(b4x>1.6 && flag2==0)
    {
        flag1=1;
        b4x+=0.0007;
        b4y-=0.003;
        count++;
    }
    if(many<-0.5 && flag1==0)
    {
        b4x+=0.003;
        count++;
    }
    //block4
    glPushMatrix();
    glTranslatef(b4x,b4y,0);
    if(b4x>1.6)
    {
        glTranslatef(mx,my,0);
        glScalef(0.7,0.7,0);
    }
    if(b4x>2.3 && count==750)
    {
        glTranslatef(0.5,0.3,0);
        b4x+=0.003;
    }
    blocks('5',-1.7,0.7);
    glPopMatrix();
    glutPostRedisplay();
}
void hillsandsun()
{
    //sky
    glBegin(GL_QUADS);
    setMaterialColor(sky);
    glVertex3f(-0.25,1.64,0); //clockwise
    glVertex3f(-0.25,2,0);
    glVertex3f(-0.055,2,0);
    glVertex3f(-0.19,1.41,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.165,1.168,0);
    glVertex3f(-0.045,2,0);
    glVertex3f(0.445,2,0);

    glVertex3f(0.665,1.168,0);
    glVertex3f(0.455,2,0);
    glVertex3f(0.945,2,0);

    glVertex3f(1.165,1.168,0);
    glVertex3f(0.955,2,0);
    glVertex3f(1.445,2,0);

    glVertex3f(1.665,1.168,0);
    glVertex3f(1.458,2,0);
    glVertex3f(1.945,2,0);

    glVertex3f(2,1.83,0);
    glVertex3f(1.955,2,0);
    glVertex3f(2,2,0);
    glEnd();

    //baseline
    glBegin(GL_LINES);
    setMaterialColor(black);
    glVertex3f(-0.2,1,0);
    glVertex3f(2,1,0);
    glEnd();

    //hills
    glBegin(GL_QUADS);
    setMaterialColor(hills);
    glVertex3f(-0.2,1,0); //clockwise
    glVertex3f(-0.25,1.1,0);
    glVertex3f(-0.05,2,0);
    glVertex3f(0.2,1,0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    setMaterialColor(hillsb);
    glVertex3f(-0.25,1.1,0);
    glVertex3f(-0.05,2,0);
    glVertex3f(0.2,1,0);
    glEnd();

    glBegin(GL_QUADS);
    setMaterialColor(hills);
    glVertex3f(0.2,1,0); //clockwise
    glVertex3f(0.15,1.1,0);
    glVertex3f(0.45,2,0);
    glVertex3f(0.7,1,0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    setMaterialColor(hillsb);
    glVertex3f(0.15,1.1,0);
    glVertex3f(0.45,2,0);
    glVertex3f(0.7,1,0);
    glEnd();

    glBegin(GL_QUADS);
    setMaterialColor(hills);
    glVertex3f(0.7,1,0); //clockwise
    glVertex3f(0.65,1.1,0);
    glVertex3f(0.95,2,0);
    glVertex3f(1.2,1,0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    setMaterialColor(hillsb);
    glVertex3f(0.65,1.1,0);
    glVertex3f(0.95,2,0);
    glVertex3f(1.2,1,0);
    glEnd();

    glBegin(GL_QUADS);
    setMaterialColor(hills);
    glVertex3f(1.2,1,0); //clockwise
    glVertex3f(1.15,1.1,0);
    glVertex3f(1.45,2,0);
    glVertex3f(1.7,1,0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    setMaterialColor(hillsb);
    glVertex3f(1.15,1.1,0);
    glVertex3f(1.45,2,0);
    glVertex3f(1.7,1,0);
    glEnd();

    glBegin(GL_QUADS);
    setMaterialColor(hills);
    glVertex3f(1.7,1,0); //clockwise
    glVertex3f(1.65,1.1,0);
    glVertex3f(1.95,2,0);
    glVertex3f(2.2,1,0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    setMaterialColor(hillsb);
    glVertex3f(1.65,1.1,0);
    glVertex3f(1.95,2,0);
    glVertex3f(2.2,1,0);
    glEnd();

    glDisable(GL_DEPTH_TEST);
    //sun
    setMaterialColor(sun);
    glBegin(GL_TRIANGLES);
    glVertex3f(1.16,1.77,0);
    glVertex3f(1.1,1.8,0);
    glVertex3f(1.1,1.73,0);

    glVertex3f(1.1,1.73,0);
    glVertex3f(1.05,1.72,0);
    glVertex3f(1.1,1.68,0);

    glVertex3f(1.1,1.68,0);
    glVertex3f(1.07,1.63,0);
    glVertex3f(1.14,1.64,0);

    glVertex3f(1.13,1.64,0);
    glVertex3f(1.125,1.58,0);
    glVertex3f(1.18,1.62,0);

    glVertex3f(1.18,1.62,0);
    glVertex3f(1.23,1.58,0);
    glVertex3f(1.23,1.63,0);

    glVertex3f(1.23,1.63,0);
    glVertex3f(1.28,1.63,0);
    glVertex3f(1.26,1.68,0);

    glVertex3f(1.26,1.68,0);
    glVertex3f(1.31,1.72,0);
    glVertex3f(1.22,1.75,0);

    glVertex3f(1.25,1.75,0);
    glVertex3f(1.25,1.81,0);
    glVertex3f(1.19,1.78,0);

    glVertex3f(1.20,1.78,0);
    glVertex3f(1.16,1.83,0);
    glVertex3f(1.14,1.77,0);
    glEnd();

    setMaterialColor(suns);
    glPushMatrix();
    glTranslatef(1.18,1.7,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}
float crowy=1.65,crowyy=1.8;
int crowflag=0;
void crow()
{
    glDisable(GL_DEPTH_TEST);
    //crow
    setMaterialColor(black);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0.75,crowyy,0);
    glVertex3f(0.7,1.75,0);
    glVertex3f(0.7,1.75,0);
    glVertex3f(0.65,crowyy,0);
    glEnd();

    glPushMatrix();
    glTranslatef(0.7,1.75,0);
    glutSolidTorus(0.005f,0.01f,40,32);
    glPopMatrix();
    if(crowflag==0)
    {
        crowyy-=0.001;
        if(crowyy<1.75)
            crowflag=1;
    }
    if(crowflag==1)
    {
        crowyy+=0.001;
        if(crowyy>1.85)
            crowflag=0;
    }
    glEnable(GL_DEPTH_TEST);
}
void rocksnplants()
{
    glDisable(GL_DEPTH_TEST);
    //greenery
    setMaterialColor(green);
    glBegin(GL_QUADS);
    glVertex3f(-2,0.3,0); //clockwise
    glVertex3f(-2,2,0);
    glVertex3f(-0.28,2,0);
    glVertex3f(-0.28,0.3,0);
    glEnd();

    //rocks
    setMaterialColor(rocks);
    glPushMatrix();
    glTranslatef(-1.13,1.75,0);
    glutSolidSphere(0.05,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.05,1.75,0);
    glutSolidSphere(0.05,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.09,1.8,0);
    glutSolidSphere(0.05,12,6);
    glPopMatrix();

    //baseline
    glBegin(GL_LINES);
    setMaterialColor(black);
    glVertex3f(-0.98,1.7,0);
    glVertex3f(-1.2,1.7,0);
    glEnd();

    //cactus
    glBegin(GL_QUADS);
    setMaterialColor(cactus);
    glVertex3f(-1.77,1.36,0); //clockwise
    glVertex3f(-1.78,1.5,0);
    glVertex3f(-1.71,1.5,0);
    glVertex3f(-1.73,1.36,0);

    glVertex3f(-1.7,1.36,0); //clockwise
    glVertex3f(-1.72,1.55,0);
    glVertex3f(-1.67,1.5,0);
    glVertex3f(-1.65,1.36,0);

    glVertex3f(-1.67,1.36,0); //clockwise
    glVertex3f(-1.68,1.5,0);
    glVertex3f(-1.64,1.54,0);
    glVertex3f(-1.65,1.36,0);
    glEnd();

    //baseline
    glBegin(GL_LINES);
    setMaterialColor(black);
    glVertex3f(-1.6,1.35,0);
    glVertex3f(-1.8,1.35,0);
    glEnd();

    glEnable(GL_DEPTH_TEST);
}
void house()
{
    //house
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(1.42,0.2,0);
    glutSolidSphere(0.01,12,6);
    glPopMatrix();

    glColor3f(1,0.4,0.3);
    glBegin(GL_QUADS);
    glVertex3f(1.4,0.01,0);
    glVertex3f(1.4,0.3,0);
    glVertex3f(1.45,0.3,0);
    glVertex3f(1.45,0.01,0);
    glEnd();

    glColor3f(1,0.5,1);
    glBegin(GL_POLYGON);
    glVertex3f(1.35,0.01,0);
    glVertex3f(1.35,0.3,0);
    glVertex3f(1.45,0.5,0);
    glVertex3f(1.5,0.3,0);
    glVertex3f(1.5,0.01,0);
    glEnd();

    glColor3f(0.6,0,1);
    glBegin(GL_QUADS);
    glVertex3f(1.5,0.3,0);
    glVertex3f(1.45,0.5,0);
    glVertex3f(1.74,0.5,0);
    glVertex3f(1.79,0.3,0);
    glEnd();

    glColor3f(1,0,0.6);
    glBegin(GL_QUADS);
    glVertex3f(1.5,0.01,0);
    glVertex3f(1.5,0.3,0);
    glVertex3f(1.79,0.3,0);
    glVertex3f(1.79,0.01,0);
    glEnd();

    glColor3f(0.8,0,0);
    glPushMatrix();
    glTranslatef(1.39,0.4,0);
    glRotatef(60,0,0,1);
    glScalef(0.223,0.03,0.7);
    glutSolidCube(1);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glDisable(GL_DEPTH_TEST);
    //border
    setMaterialColor(black);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex3f(1.5,0.01,0);
    glVertex3f(1.5,0.3,0);
    glVertex3f(1.79,0.3,0);
    glVertex3f(1.79,0.01,0);

    glVertex3f(1.35,0.01,0);
    glVertex3f(1.35,0.3,0);
    glVertex3f(1.45,0.5,0);
    glVertex3f(1.5,0.3,0);
    glVertex3f(1.5,0.01,0);

    glVertex3f(1.4,0.01,0);
    glVertex3f(1.4,0.3,0);
    glVertex3f(1.45,0.3,0);
    glVertex3f(1.45,0.01,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(1.5,0.3,0);
    glVertex3f(1.45,0.5,0);
    glVertex3f(1.74,0.5,0);
    glVertex3f(1.79,0.3,0);
    glEnd();

    //pole
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glBegin(GL_QUADS);
    glColor3f(0.52,0.37,0.26);
    glVertex3f(1.8,0.01,0); //clockwise
    glVertex3f(1.8,0.5,0);
    glVertex3f(1.9,0.5,0);
    glVertex3f(1.9,0.01,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(1.8,0.5,0); //clockwise
    glVertex3f(1.85,0.6,0);
    glVertex3f(1.9,0.5,0);
    glEnd();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    setMaterialColor(black);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex3f(1.8,0.01,0); //clockwise
    glVertex3f(1.8,0.5,0);
    glVertex3f(1.9,0.5,0);
    glVertex3f(1.9,0.01,0);
    glEnd();

    //baseline
    glLineWidth(2);
    glBegin(GL_LINES);
    setMaterialColor(black);
    glVertex3f(1,0,0);
    glVertex3f(2,0,0);

    glVertex3f(1.92,0.5,0);
    glVertex3f(1.78,0.5,0);

    glVertex3f(1.85,0.6,0);
    glVertex3f(1.85,0.65,0);

    glVertex3f(1.88,0.54,0);
    glVertex3f(1.82,0.54,0);

    glVertex3f(1.8,0.5,0); //clockwise
    glVertex3f(1.85,0.6,0);
    glVertex3f(1.85,0.6,0);
    glVertex3f(1.9,0.5,0);
    glEnd();

    glEnable(GL_DEPTH_TEST);
}
void man()
{
    glDisable(GL_DEPTH_TEST);
    //man
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glColor3f(1,1,1); //phants
    glBegin(GL_QUADS);
    glVertex3f(-0.6,1.2,0);
    glVertex3f(-0.6,1.35,0);
    glVertex3f(-0.5,1.35,0);
    glVertex3f(-0.5,1.2,0);
    glEnd();

    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex3f(-0.55,1.21,0);
    glVertex3f(-0.55,1.3,0);
    glEnd();

    //shoes
    glBegin(GL_QUADS);
    glVertex3f(-0.55,1.2,0); //anticlockwise
    glVertex3f(-0.6,1.2,0);
    glVertex3f(-0.65,1.1,0);
    glVertex3f(-0.55,1.15,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.55,1.2,0); //anticlockwise
    glVertex3f(-0.5,1.2,0);
    glVertex3f(-0.45,1.1,0);
    glVertex3f(-0.55,1.15,0);
    glEnd();

    //body
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(-0.62,1.35,0);
    glVertex3f(-0.62,1.52,0);
    glVertex3f(-0.48,1.52,0);
    glVertex3f(-0.48,1.35,0);

    //hands
    glVertex3f(-0.62,1.52,0);
    glVertex3f(-0.69,1.47,0);
    glVertex3f(-0.67,1.45,0);
    glVertex3f(-0.62,1.47,0);

    glVertex3f(-0.48,1.52,0);
    glVertex3f(-0.41,1.47,0);
    glVertex3f(-0.43,1.45,0);
    glVertex3f(-0.48,1.47,0);
    glEnd();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    setMaterialColor(skin);
    glPushMatrix();
    glTranslatef(-0.69,1.45,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.41,1.45,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    //tie
    setMaterialColor(tie);
    glPushMatrix();
    glTranslatef(-0.55,1.47,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glVertex3f(-0.56,1.45,0);
    glVertex3f(-0.58,1.43,0);
    glVertex3f(-0.55,1.38,0);
    glVertex3f(-0.52,1.43,0);
    glVertex3f(-0.54,1.45,0);
    glEnd();

    //head
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glColor3f(1,0.76,0.69);
    glBegin(GL_QUADS);
    glVertex3f(-0.6,1.52,0);
    glVertex3f(-0.6,1.62,0);
    glVertex3f(-0.5,1.64,0);
    glVertex3f(-0.5,1.52,0);
    glEnd();

    setMaterialColor(skin);
    glPushMatrix();
    glTranslatef(-0.55,1.52,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //eyes
    setMaterialColor(white);
    glPushMatrix();
    glTranslatef(-0.53,1.59,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.57,1.59,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-0.53,1.59,0);
    glutSolidSphere(0.005,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.57,1.59,0);
    glutSolidSphere(0.005,12,6);
    glPopMatrix();

    //mouth
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(-0.57,1.53,0);
    glVertex3f(-0.53,1.53,0);
    glEnd();

    //ears
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    setMaterialColor(skin);
    glPushMatrix();
    glTranslatef(-0.6,1.57,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,1.57,0);
    glutSolidSphere(0.02,12,6);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //hair
    setMaterialColor(black);
    glPushMatrix();
    glTranslatef(-0.57,1.66,0);
    glutSolidSphere(0.04,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.53,1.66,0);
    glutSolidSphere(0.03,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.55,1.66,0);
    glutSolidSphere(0.03,12,6);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}
void tree()
{
     //tree
    setMaterialColor(green);
    glPushMatrix();
    glTranslatef(-1.7,1.3,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.78,1.33,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.3,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.54,1.36,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.54,1.45,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6,1.5,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.7,1.5,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.8,1.45,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.67,1.43,0);
    glutSolidSphere(0.08,40,32);
    glPopMatrix();

    setMaterialColor(root);
    glBegin(GL_QUADS);
    glVertex3f(-1.7,1,0);
    glVertex3f(-1.7,1.3,0);
    glVertex3f(-1.6,1.3,0);
    glVertex3f(-1.6,1,0);
    glEnd();
}
void treedisp()
{
    glPushMatrix();
    glTranslatef(2.6,-0.9,0);
    glScalef(0.9,0.9,0);
    tree();
    glPopMatrix();
}
void grass()
{
    //baseline
    glLineWidth(2);
    setMaterialColor(black);
    glBegin(GL_LINES);
    glVertex3f(-1.7,-1.7,0);
    glVertex3f(-1.9,-1.7,0);
    glEnd();

    setMaterialColor(green);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.72,-1.7,0);
    glVertex3f(-1.74,-1.5,0);
    glVertex3f(-1.75,-1.7,0);

    glVertex3f(-1.74,-1.7,0);
    glVertex3f(-1.76,-1.52,0);
    glVertex3f(-1.77,-1.7,0);

    glVertex3f(-1.79,-1.7,0);
    glVertex3f(-1.81,-1.48,0);
    glVertex3f(-1.84,-1.7,0);

    glVertex3f(-1.83,-1.7,0);
    glVertex3f(-1.87,-1.52,0);
    glVertex3f(-1.89,-1.7,0);

    glVertex3f(-1.76,-1.7,0);
    glVertex3f(-1.79,-1.5,0);
    glVertex3f(-1.8,-1.7,0);
    glEnd();
}
void grassdisp()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7,0.3,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7,0.1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.4,1.5,0);
    grass();
    glPopMatrix();
}
void scene3()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glColor3f(1,1,1);
    glRasterPos3f(-1.09,0.6,0);
    char msg[]="WAITING";
    for(int i=0;i<strlen(msg);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);

    glRasterPos3f(-1.09,0.5,0);
    char msg1[]="TIME:";
    for(int i=0;i<strlen(msg1);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg1[i]);

    glRasterPos3f(-0.75,0.6,0);
    char num1[]="16";
    for(int i=0;i<strlen(num1);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,num1[i]);

    glRasterPos3f(-0.35,0.6,0);
    char num2[]="13";
    for(int i=0;i<strlen(num2);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,num2[i]);

    glRasterPos3f(0.05,0.6,0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'5');

    glRasterPos3f(0.45,0.6,0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
void subtitles()
{
    glDisable(GL_DEPTH_TEST);
    //subtitles
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glColor3f(0.5,0.5,1);
    glPushMatrix();
    glTranslatef(1.05,-0.5,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.15,-0.4,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.35,-0.55,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25,-0.4,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4,-0.4,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.57,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.05,-0.3,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.3,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1,-0.15,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.3,-0.3,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.27,-0.15,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.45,-0.25,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4,-0.129,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,-0.129,0);
    glutSolidSphere(0.1,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,-0.6,0);
    glutSolidSphere(0.025,12,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9,-0.5,0);
    glutSolidSphere(0.035,12,6);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

    glColor3f(0,0,0);
    glRasterPos3f(1.05,-0.15,0);
    char q1[]="Though the third block";
    for(int i=0;i<strlen(q1);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q1[i]);

    glRasterPos3f(1.03,-0.26,0);
    char q2[]="would have been slided ";
    for(int i=0;i<strlen(q2);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q2[i]);

    glRasterPos3f(1.01,-0.36,0);
    char q3[]="within 3 mins. I had";
    for(int i=0;i<strlen(q3);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q3[i]);

    glRasterPos3f(1.06,-0.45,0);
    char q4[]="to wait for 13 mins ";
    for(int i=0;i<strlen(q4);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q4[i]);

    glRasterPos3f(1.12,-0.56,0);
    char q5[]="to slide it. ";
    for(int i=0;i<strlen(q5);i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,q5[i]);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
float trux=-4.5,mnx=3.2;
void displaytwo()
{
    glLoadIdentity();
    star+=1;
    glClearColor(0.96,0.87,0.70,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    setMaterialColor(black);
    glBegin(GL_QUADS);
    glVertex3f(-1.1,1.7,0); //anti
    glVertex3f(0.9,1.7,0);
    glVertex3f(0.9,0.4,0);
    glVertex3f(-1.1,0.4,0);
    glEnd();

    if(star>4300)
        scene3();

    //man
    glPushMatrix();
    glTranslatef(mnx,-3.2,0);
    glScalef(1.5,1.5,0);
    if(mnx>1.5 && trux>-2.8)
        mnx-=0.001;
    man();
    glPopMatrix();
    if(mnx<1.55)
        subtitles();

    //truck
    glPushMatrix();
    glTranslatef(trux,0.3,0);
    glScalef(1.8,1.5,0);
    if(trux<-2.8)
        trux+=0.001;
    truck();
    glPopMatrix();

    //block1
    glPushMatrix();
    glTranslatef(1,0.4,0);
    if(star>3500)
        blocks('6',-1.7,0.7);
    glPopMatrix();

    //block2
    glPushMatrix();
    glTranslatef(1.4,0.4,0);
        if(star>3700)
            blocks('3',-1.7,0.7);
    glPopMatrix();

    //block3
    glPushMatrix();
    glTranslatef(1.8,0.4,0);
    if(star>3900)
        blocks('8',-1.7,0.7);
    glPopMatrix();

    //block4
    glPushMatrix();
    glTranslatef(2.2,0.4,0);
    if(star>4100)
        blocks('5',-1.7,0.7);
    glPopMatrix();

    glutSwapBuffers();
    glEnable(GL_DEPTH_TEST);
    glutPostRedisplay();
}
void displayone()
{
    glClearColor(0.96,0.87,0.70,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    rocksnplants();
    house();

    if(many<-0.5)
    {
        flag=1;
        if(flag4==1 && manx>-0.4)
            manx-=0.003;
        else if(flag8==1 && manx>-0.8)
            manx-=0.003;
        else if(flag12==1 && manx>-1.2)
            manx-=0.003;
    }
    if(flag==0)
        many-=0.003;
    glPushMatrix();
    glTranslatef(manx,many,0);
    man();
    glPopMatrix();

    glDisable(GL_DEPTH_TEST);
    //mountain border
    setMaterialColor(mountb);
    glPushMatrix();
    glTranslatef(-1.5,0.3,0);
    glScalef(2.5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.265,1.25,0);
    glRotatef(-90,0,0,1);
    glScalef(1.9,0.03,1);
    glutSolidCube(1);
    glPopMatrix();

    //slider border
    setMaterialColor(slideb);
    glPushMatrix();
    glTranslatef(-0.08,-0.4,0);
    glRotatef(-75,0,0,1);
    glScalef(1.5,0.03,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.055,0.45,0);
    glRotatef(-75,0,0,1);
    glScalef(2.5,0.03,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.35,-1.1,0);
    glScalef(0.5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48,-0.75,0);
    glScalef(0.23,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

    blockdisplay();
    slide();
    hillsandsun();

    crow();
    glPushMatrix();
    glTranslatef(-0.05,-0.2,0);
    crow();
    glPopMatrix();

    treedisp();
    grassdisp();

    if(flag16==1)
    {
         glutDisplayFunc(displaytwo);
         glutPostRedisplay();
    }
    glutSwapBuffers();
    glutPostRedisplay();
}
void keys(unsigned char key,int x,int y)
{
    if(key=='w' || key=='W')
    {
          glutDisplayFunc(display);
          glutPostRedisplay();
    }
    if(key=='x' || key=='X')
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
    glutDisplayFunc(welcome);
    glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	initLight();
    glutMainLoop();
    return 0;
}
