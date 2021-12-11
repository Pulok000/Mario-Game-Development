#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<time.h>
float upD=700,upS=0;
bool stat=true;

float Rep2 = 0.0f;
float x = 0.0f;
float Rep = 0.0f;
GLfloat ll=0,gol=0,jumping=0;
int flag=1,flagm=0,game=5,flagj=0,flagjj=1;
int count1= 0;

void poly(int xl,int xr,int yu,int yd){
glBegin(GL_POLYGON);
glVertex2i(xl,yd);
glVertex2i(xl,yu);
glVertex2i(xr,yu);
glVertex2i(xr,yd);
glEnd();
}
//TREE--->pulok
void tree2()
{

glTranslatef(-500.0f, -430.0f, 0.0f);
glScalef(220.0, 300.0, 0.0);
glBegin(GL_POLYGON);
glColor3f(0.2267f,0.85f, 0.0f);
glVertex2f(0.0f,1.0f);
glVertex2f(-0.2f,0.8f);
glVertex2f(0.2f,0.8f);

 glEnd();
glBegin(GL_POLYGON);
glColor3f(0.2267f,0.85f, 0.0f);
glVertex2f(-0.15f,0.8f);
glVertex2f(-0.25f,0.7f);
glVertex2f(0.25f,0.7f);
glVertex2f(0.15f,0.8f);

 glEnd();

 glBegin(GL_POLYGON);
glColor3f(0.2267f,0.85f, 0.0f);
glVertex2f(-0.15f,0.7f);
glVertex2f(-0.25f,0.6f);
glVertex2f(0.25f,0.6f);
glVertex2f(0.15f,0.7f);

 glEnd();

 glBegin(GL_POLYGON);
glColor3f(0.2267f,0.85f, 0.0f);
glVertex2f(-0.15f,0.6f);
glVertex2f(-0.25f,0.5f);
glVertex2f(0.25f,0.5f);
glVertex2f(0.15f,0.6f);

 glEnd();

 glBegin(GL_POLYGON);
glColor3f(0.2267f,0.85f, 0.0f);
glVertex2f(-0.15f,0.5f);
glVertex2f(-0.25f,0.4f);
glVertex2f(0.25f,0.4f);
glVertex2f(0.15f,0.5f);

 glEnd();

 glBegin(GL_POLYGON);
glColor3f(0.61f, 0.20f, 0.0f);//Brown
glVertex2f(-0.05f,0.4f);
glVertex2f(0.05f,0.4f);
glVertex2f(0.05f,0.0f);
glVertex2f(-0.05f,0.0f);

 glEnd();

}
//Mountain --->pulok
void mountain()
{
glTranslatef(-500.0f, -400.0f, 0.0f);
glScalef(600.0, 500.0, 0.0);
glBegin(GL_POLYGON);
//glColor3f(1.0f, 0.0f, 0.0f);//Brown
glColor3f(1.0f,0.7326f,0.7326f);
glVertex2f(-0.6f,0.0f);
glVertex2f(0.0f,0.8f);
glVertex2f(0.6f,0.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);//Brown
glVertex2f(0.0f,0.8f);
glVertex2f(-0.15f,0.6f);
glVertex2f(-0.05f,0.55f);
glVertex2f(0.0f,0.6f);
glVertex2f(0.1f,0.55f);
glVertex2f(0.15f,0.6f);

 glEnd();

}

//LOSE --->pulok
void LoseSign()
{
glBegin(GL_LINES);//L
glColor3f(0.90f, 0.0f, 0.0f);
glVertex2f(-300.0f ,155.0f);
glVertex2f(-300.0f ,-100.0f);
glVertex2f(-325.0f ,-100.0f);
glVertex2f(-200.0f ,-100.0f);
glEnd();

glBegin(GL_LINE_STRIP);//O
glColor3f(0.90f, 0.0f, 0.0f);
glVertex2f(-150.0f ,155.0f);
glVertex2f(-150.0f ,-100.0f);
glVertex2f(-50.0f ,-100.0f);
glVertex2f(-50.0f ,155.0f);
glVertex2f(-150.0f ,155.0f);

glEnd();

glBegin(GL_LINE_STRIP);//S
glColor3f(0.90f, 0.0f, 0.0f);
glVertex2f(0.0f ,-100.0f);
glVertex2f(150.0f ,-100.0f);
glVertex2f(150.0f ,0.0f);
glVertex2f(30.0f ,0.0f);
glVertex2f(30.0f ,140.0f);
glVertex2f(150.0f ,140.0f);

glEnd();

glBegin(GL_LINES);//E
glColor3f(0.90f, 0.0f, 0.0f);
glVertex2f(220.0f ,-100.0f);
glVertex2f(220.0f ,155.0f);
glVertex2f(220.0f ,155.0f);
glVertex2f(340.0f ,155.0f);

 glVertex2f(220.0f ,30.0f);
glVertex2f(340.0f ,30.0f);

 glVertex2f(220.0f ,-100.0f);
glVertex2f(340.0f ,-100.0f);


glEnd();
}


void treeSet()
{
float x;
while(x<5000)
{
glPushMatrix();
glTranslatef(-200.0f+x, 200.0f, 0.0f);
tree2();

glPopMatrix();
x+=100.0f;
}

}


void mario(){
glPushMatrix();
glTranslatef(0, jumping, 0);
glRotatef(gol, 0.0f, 0.0f, 1.0f);
glTranslatef(0, 13, 0);
glColor3f(1.0f, 0.0f, 0.0f);//hat
poly(-310,-280,-85,-95);
poly(-280,-265,-90,-95);
glColor3f(1.0f, 1.0f, 1.0f);//face
poly(-307,-276,-95,-125);
poly(-310,-265,-102,-115);
poly(-265,-260,-110,-115);
glColor3f(0.0f, 1.0f, 0.0f);//hair
poly(-310,-297,-95,-102);
poly(-305,-300,-102,-115);
poly(-300,-297,-109,-115);
poly(-315,-310,-102,-115);
poly(-310,-307,-115,-120);
poly(-286,-282,-95,-109);
poly(-282,-276,-109,-115);
poly(-286,-268,-115,-120);

int x=-292,y=-165;
glPushMatrix();
glTranslatef(x, y, 0);
glRotatef(ll, 0.0f, 0.0f, 1.0f);
glTranslatef(-x, -y, 0);
glColor3f(1.0f, 1.0f, 1.0f);//leg
poly((x-6),(x+6),(y),(y-40));glColor3f(1.0f, 0.0f, 0.0f);poly((x-6),(x+16),(y-40),(y-50));
glPopMatrix();
glPushMatrix();
glTranslatef(x, y, 0);
glRotatef(-ll, 0.0f, 0.0f, 1.0f);
glTranslatef(-x, -y, 0);
glColor3f(1.0f, 0.50f, 0.7f);//leg
poly((x-6),(x+6),(y),(y-40));glColor3f(1.0f, 0.0f, 0.0f);poly((x-6),(x+16),(y-40),(y-50));
glPopMatrix();

glColor3f(1.0f, 0.0f, 0.0f);//body
poly(-315,-269,-125,-130);
poly(-318,-266,-130,-170);
poly(-315,-269,-170,-175);
int xh=-292,yh=-155;
glPushMatrix();
glTranslatef(xh, yh, 0);
glRotatef(ll, 0.0f, 0.0f, 1.0f);
glTranslatef(-xh, -yh, 0);
glColor3f(1.0f, 1.0f, 1.0f);//hand
poly((xh),(xh+36),(yh),(yh+10));glColor3f(1.0f, 0.0f, 0.0f);poly((xh+36),(xh+46),(yh-2),(yh+12));
glPopMatrix();
glPopMatrix();

}

void func1(float x)// grass tiangle layer
{
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.80f, 0.0f);
glVertex2f(-500.0f + x,-200.0f);
glVertex2f(-450.0f + x, -200.0f);
glVertex2f(-480.0f + x, -280.0f);
glEnd();

}

void func2(float x)// 2 vertical square
{
glBegin(GL_POLYGON);
glColor3f(1.0f, 0.70f, 0.0f);
glVertex2f(-495.0f + x,-310.0f);
glVertex2f(-410.0f + x, -310.0f);
glVertex2f(-410.0f + x, -220.0f);
glVertex2f(-495.0f + x, -220.0f);
glEnd();

 glBegin(GL_POLYGON);
glColor3f(1.0f, 0.70f, 0.0f);
glVertex2f(-495.0f + x,-395.0f);
glVertex2f(-410.0f + x, -395.0f);
glVertex2f(-410.0f + x, -320.0f);
glVertex2f(-495.0f + x, -320.0f);
glEnd();

}


void WinSign()
{
glBegin(GL_LINE_STRIP);//W
glColor3f(0.30f, 0.0f, 0.70f);
glVertex2f(-200.0f ,155.0f);
glVertex2f(-150.0f ,-100.0f);
glVertex2f(-100.0f ,155.0f);
glVertex2f(-50.0f ,-100.0f);
glVertex2f(0.0f ,155.0f);

glEnd();

glBegin(GL_LINE_STRIP);//I
glColor3f(0.30f, 0.0f, 0.70f);
glVertex2f(50.0f ,155.0f);
glVertex2f(50.0f ,-100.0f);

glEnd();

glBegin(GL_LINE_STRIP);//N
glColor3f(0.30f, 0.0f, 0.70f);
glVertex2f(110.0f ,-100.0f);
glVertex2f(110.0f ,155.0f);
glVertex2f(210.0f ,-100.0f);
glVertex2f(210.0f ,155.0f);

glEnd();

}

void FinishLine()
{
glTranslatef(650.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(0.80f, 0.20f, 0.20f);
glVertex2f(400.0f ,-200.0f);
glVertex2f(410.0f ,-200.0f);
glVertex2f(410.0f ,200.0f);
glVertex2f(400.0f ,200.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.20f, 0.80f, 0.20f);
glVertex2f(410.0f ,180.0f);
glVertex2f(410.0f ,120.0f);
glVertex2f(490.0f ,150.0f);

glEnd();

}

void Repeater(float position)
{
glTranslatef(position,0.0f, 0.0f);
glBegin(GL_QUADS); // main quad
glColor3f(1.0f, 0.5f, 0.0f);
glVertex2f(-500.0f, -400.0f);
glVertex2f( -200.0f, -400.0f);
glVertex2f( -200.0f, -200.0f);
glVertex2f(-500.0f, -200.0f);
glEnd();

 func2(0.0f);
func2(100.0f);
func2(200.05f);

 glBegin(GL_POLYGON);// grass surface layer
glColor3f(0.0f, 0.80f, 0.0f);
glVertex2f(-500.0f ,-230.0f);
glVertex2f( -200.0f, -230.0f);
glVertex2f( -200.0f, -200.0f);
glVertex2f( -500.0f, -200.0f);
glEnd();

 func1(0.0f);
func1(40.0f);
func1(90.0f);
func1(130.0f);
func1(180.0f);
func1(210.0f);
func1(250.0f);
}

void Rock(float x)
{
glBegin(GL_POLYGON);// big rock
glColor3f(0.8f, 0.8f, 0.8f);
glVertex2f(100.0f+x ,-200.0f);
glVertex2f(210.0f+x, -200.0f);
glVertex2f(210.0f+x, -80.0f);
glVertex2f(180.0f+x , -80.0f);
glVertex2f(120.0f+x, -150.0f);
glEnd();

 glBegin(GL_POLYGON);//shade
glColor3f(0.6f, 0.6f, 0.6f);
glVertex2f(170.0f+x ,-200.0f);
glVertex2f(210.0f+x, -200.0f);
glVertex2f(210.0f+x, -80.0f);
glVertex2f(200.0f+x , -100.0f);
glVertex2f(180.0f+x, -150.0f);
glEnd();

 glBegin(GL_POLYGON);//small rock
glColor3f(0.8f, 0.8f, 0.8f);
glVertex2f(200.0f+x ,-200.0f);
glVertex2f(230.0f+x, -200.0f);
glVertex2f(230.0f+x, -180.0f);
glVertex2f(220.0f+x, -170.0f);
glVertex2f(200.0f+x , -180.0f);
glEnd();

}



void delay(unsigned int ms)
{
clock_t goal= ms + clock();
while(goal>clock());
stat=!stat;
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
int i;
int triangleAmount = 20; //# of triangles used to draw circle

 //GLfloat radius = 0.8f; //radius
GLfloat twicePi = 2.0f * 3.1416;

 glBegin(GL_TRIANGLE_FAN);
glVertex2f(x, y); // center of circle
for(i = 0; i <= triangleAmount;i++) {
glVertex2f(
x + (radius * cos(i * twicePi / triangleAmount)),
y + (radius * sin(i * twicePi / triangleAmount))
);
}
glEnd();
}
void cloud(){
glTranslatef(50.0f, 0.0f, 0.0f);
glColor3ub(255, 255, 255);
drawFilledCircle(600,270,40);
drawFilledCircle(640,270,30);
drawFilledCircle(570,290,30);
drawFilledCircle(570,250,30);
drawFilledCircle(550,270,30);
drawFilledCircle(520,260,40);

drawFilledCircle(1200,270,40);
drawFilledCircle(1240,270,30);
drawFilledCircle(1170,290,30);
drawFilledCircle(1170,250,30);
drawFilledCircle(1150,270,30);
drawFilledCircle(1120,260,40);
}
void display()
{
glClearColor(0.0f, 0.4f, 0.7f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT);

glPushMatrix();

glTranslatef(0,upS,0);

glColor3ub(237, 226, 9);

drawFilledCircle(-100,300,30);

glPopMatrix();

glPushMatrix();

glTranslatef(0,upD,0);

glColor3ub(255, 255, 255);

drawFilledCircle(100,300,40);

glPopMatrix();

glPushMatrix();
glTranslatef(500.0f, 200.0f, 0.0f);
mountain();
glPopMatrix();
glPushMatrix();
glTranslatef(100.0f, 200.0f, 0.0f);
mountain();
glPopMatrix();

glPushMatrix();

glPushMatrix();
glTranslatef(Rep,0.0f, 0.0f);
treeSet();
glPopMatrix();

mario();
//glScalef(0.50, 0.50, 0.0);
//glTranslatef(-500.0f, -400.0f, 0.0f);
glTranslatef(Rep,0.0f, 0.0f);
glPushMatrix();
if(count1==4)
{
FinishLine();
}
glPopMatrix();
Rock(600);
Repeater(0.0f);
for(int i=0; i<10;i++)
{
Repeater(300.0f);

}
glPopMatrix();

glPushMatrix();
glTranslatef(Rep2, 0.0f, 0.0);
cloud();

glPopMatrix();

if(count1==5)
{

 WinSign();

}
if(game==1)
{
LoseSign();
}


glFlush();

}
int flag2=0;
void update(int value)
{
if(count1<5)
{

if(game==0){
if(upS==0&&upD==200)
{
delay(2000);
}
else if(upS==-800&&upD==0)
{
delay(3000);
}
if(upS>-800&&flag2==0&&stat)
{
if(upS==-799)
{
flag2=1;
}
upS--;
}
if(upD>0&&flag2==1&&stat)
{
if(upD==1)
{
flag2=2;
}
upD--;
}
if(upD<200&&flag2==2&&!stat)
{
if(upD==199)
{
flag2=3;
}
upD++;
}
if(upS<0&&flag2==3&&!stat)
{
if(upS==-1)
{
flag2=0;
}
upS++;
}

 //
// for mario movement
if(ll==30){flag=-1;}
else if(ll==-30){flag=1;}
if (flag==-1){ll=ll-5;}
else if (flag==1){ll=ll+5;}

if(flagj==1){
if(jumping==160){flagjj=-1;}
else if(jumping==0){flagjj=1;}
if (flagjj==-1){jumping=jumping-10;
if(jumping==0){flagj=0;}
}
else if (flagjj==1){jumping=jumping+20;}
}
// for ground movement
if(Rep <-1300.0f)
Rep = 0.0f;
if(Rep == 0.0f)
{
count1++;
}

Rep -= 20;
if(Rep==-980&&flagj==0){game=1;}
if(Rep>=-1100&&Rep<=-1080&&jumping<120&&flagj==1){game=1;}

if(Rep2 <-1800.0f)
Rep2=0.0f;
Rep2 -= 10;

glutPostRedisplay();

}
}
glutTimerFunc(30, update, 0); //speed
}

void init(void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-500.0, 500.0, -400.0, 400.0, -1.0, 1.0);
}
void handleKeypress(unsigned char key, int x, int y)
{
switch (key)
{
case 'w':
flagj=1;
//tranx=130.0;
//trany=130.0;
//speed = 0.0f;
break;

 case 'x':
game = 0;
break;

 case 'z':
game = 5;
break;

 }
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitWindowSize(640, 560);
glutInitWindowPosition(0, 0);
glutCreateWindow("Mario");
init();
glLineWidth(50);
glutDisplayFunc(display);
glutTimerFunc(10, update, 0);
glutKeyboardFunc(handleKeypress);
glutMainLoop();
return 0;
}
