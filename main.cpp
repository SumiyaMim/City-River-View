#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>

float b = 0, c = 0, cd = 0, s = 0;

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  //glOrtho(0, 100, 0, 100, 0, 100);
  gluOrtho2D(0,100,0,100); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

void circle(GLfloat rx, GLfloat ry,GLfloat cx,GLfloat cy){

 glBegin(GL_TRIANGLE_FAN);
 glVertex2f(cx,cy);

 for (int i=0;i<=100;i++){

 float angle = 2.0f * 3.1416f * i/100;
 float x= rx* cosf(angle);
 float y= ry* sinf(angle);

 glVertex2f((x+cx),(y+cy));

 }
}

void Draw()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(0,0);
   glVertex2f(0,100);
   glVertex2f(100,100);
   glVertex2f(100,0);
   glEnd();

   //water
   glColor3ub(25,88,104);
   glBegin(GL_POLYGON);
   glVertex2f(0,0);
   glVertex2f(100,0);
   glColor3ub(45,160,190);
   glVertex2f(100,25);
   glVertex2f(0,25);
   glEnd();

   //brown border
   glColor3f(0.2,0.1, 0);
   glBegin(GL_POLYGON);
   glVertex2f(0,25);
   glVertex2f(100,25);
   glVertex2f(100,30);
   glVertex2f(0,30);
   glEnd();

   //black border
   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(0,30);
   glVertex2f(100,30);
   glVertex2f(100,31);
   glVertex2f(0,31);
   glEnd();

   //boat
   if(b<=100)
    b = b+0.005;
   else
    b = 0;

   glutPostRedisplay();
   glColor3ub(139,69,19);
   glBegin(GL_POLYGON);
   glVertex2f(b+10,5);
   glVertex2f(b+30,5);
   glVertex2f(b+35,12);
   glVertex2f(b+5,12);
   glEnd();

   glutPostRedisplay();
   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(b+15,12);
   glVertex2f(b+15.8,12);
   glVertex2f(b+15.8,20);
   glVertex2f(b+15,20);
   glEnd();

   glutPostRedisplay();
   glColor3f(0.9,0.5,0.7);
   glBegin(GL_POLYGON);
   glVertex2f(b+9,13.5);
   glVertex2f(b+25,13.5);
   glVertex2f(b+15,29);
   glEnd();

   //road
   glColor3ub(128,128,128);
   glBegin(GL_POLYGON);
   glVertex2f(0,31);
   glVertex2f(100,31);
   glVertex2f(100,46);
   glVertex2f(0,46);
   glEnd();

   //road white lines
   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(10,38);
   glVertex2f(20,38);
   glVertex2f(20,39.5);
   glVertex2f(10,39.5);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(30,38);
   glVertex2f(40,38);
   glVertex2f(40,39.5);
   glVertex2f(30,39.5);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(50,38);
   glVertex2f(60,38);
   glVertex2f(60,39.5);
   glVertex2f(50,39.5);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(70,38);
   glVertex2f(80,38);
   glVertex2f(80,39.5);
   glVertex2f(70,39.5);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(90,38);
   glVertex2f(100,38);
   glVertex2f(100,39.5);
   glVertex2f(90,39.5);
   glEnd();

   //car
   if(c<=100)
    c = c+0.03;
   else
    c = 0;

   glutPostRedisplay();
   glColor3f(0.8,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+6,37);
   glVertex2f(c+25,37);
   glVertex2f(c+25,40);
   glVertex2f(c+6,40);
   glEnd();

   glutPostRedisplay();
   glColor3f(0.8,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+6,40);
   glVertex2f(c+25,40);
   glVertex2f(c+23,41);
   glVertex2f(c+8,41);
   glEnd();

   glutPostRedisplay();
   glColor3f(0.8,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+8,41);
   glVertex2f(c+23,41);
   glVertex2f(c+21,45);
   glVertex2f(c+10,45);
   glEnd();

   glutPostRedisplay();
   glColor3f(0,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+8.5,41);
   glVertex2f(c+10,41);
   glVertex2f(c+10,44);
   glEnd();

   glutPostRedisplay();
   glColor3f(0,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+10.5,41);
   glVertex2f(c+15,41);
   glVertex2f(c+15,44);
   glVertex2f(c+10.5,44);
   glEnd();

   glutPostRedisplay();
   glColor3f(0,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+16,41);
   glVertex2f(c+20.5,41);
   glVertex2f(c+20.5,44);
   glVertex2f(c+16,44);
   glEnd();

   glutPostRedisplay();
   glColor3f(0,0,0.1);
   glBegin(GL_POLYGON);
   glVertex2f(c+21,41);
   glVertex2f(c+22.5,41);
   glVertex2f(c+21,44);
   glEnd();

   //wheel
   glutPostRedisplay();
   glColor3f(0,0,0);
   circle(1,1.5,c+10,37);
   glEnd();

   glutPostRedisplay();
   glColor3f(1,1,1);
   circle(0.5,0.8,c+10,37);
   glEnd();

   glutPostRedisplay();
   glColor3f(0,0,0);
   circle(1,1.5,c+21,37);
   glEnd();


   glutPostRedisplay();
   glColor3f(1,1,1);
   circle(0.5,0.8,c+21,37);
   glEnd();

   //green border
   glColor3f(0.1,0.7,0.2);
   glBegin(GL_POLYGON);
   glVertex2f(0,46);
   glVertex2f(100,46);
   glVertex2f(100,52);
   glVertex2f(0,52);
   glEnd();

   //sky
   glColor3ub(116,185,234);
   glBegin(GL_POLYGON);
   glVertex2f(0,52);
   glVertex2f(100,52);
   glColor3ub(193,224,246);
   glVertex2f(100,100);
   glVertex2f(0,100);
   glEnd();

   //sun
   if(s<=28)
    s = s+0.006;
   else
    s = 28;

   glColor3f(1,1,0);
   circle(4,7,69,s+60);
   glEnd();

   //cloud
   if(cd<=100)
    cd = cd+0.001;
   else
    cd = 0;

   //cloud-1
   glutPostRedisplay();
   glColor3f(1,1,1);
   circle(2,2,cd+5,90.5);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+7,92);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+7,89.5);
   glEnd();

   glutPostRedisplay();
   circle(1.5,1.5,cd+9,92);
   glEnd();

   glutPostRedisplay();
   circle(1.5,1.5,cd+9,89.5);
   glEnd();

   glutPostRedisplay();
   circle(1.7,1.7,cd+10,91);
   glEnd();

   //cloud-2
   glutPostRedisplay();
   glColor3f(1,1,1);
   circle(3.5,3.5,cd+20,88);
   glEnd();

   glutPostRedisplay();
   circle(3.5,3.5,cd+23,89.5);
   glEnd();

   glutPostRedisplay();
   circle(3.5,3.5,cd+22.5,86);
   glEnd();

   glutPostRedisplay();
   circle(2.5,2.5,cd+26.5,89.5);
   glEnd();

   glutPostRedisplay();
   circle(2.5,2.5,cd+26,85.5);
   glEnd();

   glutPostRedisplay();
   circle(2.5,2.5,cd+28,87.5);
   glEnd();

   //cloud-3
   glutPostRedisplay();
   glColor3f(1,1,1);
   circle(3,3,cd+50,82);
   glEnd();

   glutPostRedisplay();
   circle(3,3,cd+53,84);
   glEnd();

   glutPostRedisplay();
   circle(3,3,cd+53,80.5);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+56,84);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+56,80.5);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+57.5,82);
   glEnd();

   //cloud-4
   glutPostRedisplay();
   glColor3f(1,1,1);
   circle(2,2,cd+84,86.5);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+86,88);
   glEnd();

   glutPostRedisplay();
   circle(2,2,cd+86,85.5);
   glEnd();

   glutPostRedisplay();
   circle(1.5,1.5,cd+88,88.2);
   glEnd();

   glutPostRedisplay();
   circle(1.5,1.5,cd+88,85.5);
   glEnd();

   glutPostRedisplay();
   circle(1.7,1.7,cd+89,87);
   glEnd();

   //building-1
   glColor3f(0.4,0.7,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(0,52);
   glVertex2f(2,52);
   glVertex2f(2,63);
   glVertex2f(0,63);
   glEnd();

   glColor3f(0.7,0.9,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(2,52);
   glVertex2f(3,52);
   glVertex2f(3,62);
   glVertex2f(2,63);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(0.5,59);
   glVertex2f(1.5,59);
   glVertex2f(1.5,61);
   glVertex2f(0.5,61);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(0.5,55);
   glVertex2f(1.5,55);
   glVertex2f(1.5,57);
   glVertex2f(0.5,57);
   glEnd();

   //building-2
   glColor3ub(56,92,107);
   glBegin(GL_POLYGON);
   glVertex2f(5,52);
   glVertex2f(14,52);
   glVertex2f(14,78);
   glVertex2f(5,78);
   glEnd();

   glColor3ub(128,171,189);
   glBegin(GL_POLYGON);
   glVertex2f(14,52);
   glVertex2f(17,52);
   glVertex2f(17,76);
   glVertex2f(14,78);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(6.5,72);
   glVertex2f(8.5,72);
   glVertex2f(8.5,75);
   glVertex2f(6.5,75);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(10.5,72);
   glVertex2f(12.5,72);
   glVertex2f(12.5,75);
   glVertex2f(10.5,75);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(6.5,67);
   glVertex2f(8.5,67);
   glVertex2f(8.5,70);
   glVertex2f(6.5,70);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(10.5,67);
   glVertex2f(12.5,67);
   glVertex2f(12.5,70);
   glVertex2f(10.5,70);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(6.5,65);
   glVertex2f(8.5,65);
   glVertex2f(8.5,62);
   glVertex2f(6.5,62);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(10.5,65);
   glVertex2f(12.5,65);
   glVertex2f(12.5,62);
   glVertex2f(10.5,62);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(6.5,57);
   glVertex2f(8.5,57);
   glVertex2f(8.5,60);
   glVertex2f(6.5,60);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(10.5,57);
   glVertex2f(12.5,57);
   glVertex2f(12.5,60);
   glVertex2f(10.5,60);
   glEnd();

   //building-3
   glColor3f(0.9,0.7,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(30,52);
   glVertex2f(45,52);
   glVertex2f(45,70);
   glVertex2f(30,70);
   glEnd();

   glColor3f(0.8,0.4,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(45,52);
   glVertex2f(47,52);
   glVertex2f(47,72);
   glVertex2f(45,70);
   glEnd();

   glColor3f(1,0.9,1);
   glBegin(GL_POLYGON);
   glVertex2f(30,70);
   glVertex2f(45,70);
   glVertex2f(47,72);
   glVertex2f(32,72);
   glEnd();

   glColor3f(0.2,0,0.3);
   glBegin(GL_POLYGON);
   glVertex2f(36,52);
   glVertex2f(39,52);
   glVertex2f(39,60);
   glVertex2f(36,60);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(32,63);
   glVertex2f(34,63);
   glVertex2f(34,67);
   glVertex2f(32,67);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(35,63);
   glVertex2f(37,63);
   glVertex2f(37,67);
   glVertex2f(35,67);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(38,63);
   glVertex2f(40,63);
   glVertex2f(40,67);
   glVertex2f(38,67);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(41,63);
   glVertex2f(43,63);
   glVertex2f(43,67);
   glVertex2f(41,67);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(32,56);
   glVertex2f(34,56);
   glVertex2f(34,60);
   glVertex2f(32,60);
   glEnd();

   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex2f(41,56);
   glVertex2f(43,56);
   glVertex2f(43,60);
   glVertex2f(41,60);
   glEnd();

   //building-4
   glColor3ub(234,155,92);
   glBegin(GL_POLYGON);
   glVertex2f(50,52);
   glVertex2f(62,52);
   glVertex2f(62,67);
   glVertex2f(50,67);
   glEnd();

   glColor3ub(240,185,143);
   glBegin(GL_POLYGON);
   glVertex2f(62,52);
   glVertex2f(64,52);
   glVertex2f(64,65);
   glVertex2f(62,67);
   glEnd();

   glColor3f(0.7,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(52,61);
   glVertex2f(55,61);
   glVertex2f(55,65);
   glVertex2f(52,65);
   glEnd();

   glColor3f(0.7,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(57,61);
   glVertex2f(60,61);
   glVertex2f(60,65);
   glVertex2f(57,65);
   glEnd();

   glColor3f(0.7,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(52,58.5);
   glVertex2f(55,58.5);
   glVertex2f(55,54.5);
   glVertex2f(52,54.5);
   glEnd();

   glColor3f(0.7,0,0);
   glBegin(GL_POLYGON);
   glVertex2f(57,58.5);
   glVertex2f(60,58.5);
   glVertex2f(60,54.5);
   glVertex2f(57,54.5);
   glEnd();

   //building-5
   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(65,52);
   glVertex2f(72,52);
   glVertex2f(72,70);
   glVertex2f(65,70);
   glEnd();

   glColor3f(0.8,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(72,52);
   glVertex2f(73,52);
   glVertex2f(73,69);
   glVertex2f(72,70);
   glEnd();

   glColor3f(0.1,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(66,66);
   glVertex2f(71,66);
   glVertex2f(71,68);
   glVertex2f(66,68);
   glEnd();

   glColor3f(0.1,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(66,63);
   glVertex2f(71,63);
   glVertex2f(71,65);
   glVertex2f(66,65);
   glEnd();

   glColor3f(0.1,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(66,60);
   glVertex2f(71,60);
   glVertex2f(71,62);
   glVertex2f(66,62);
   glEnd();

   glColor3f(0.1,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2f(66.5,52);
   glVertex2f(70.5,52);
   glVertex2f(70.5,58);
   glVertex2f(66.5,58);
   glEnd();

   //building-6
   glColor3f(0,0.3,0.3);
   glBegin(GL_POLYGON);
   glVertex2f(91.5,52);
   glVertex2f(97.5,52);
   glVertex2f(97.5,65);
   glVertex2f(91.5,65);
   glEnd();

   glColor3f(0.2,0.5,0.4);
   glBegin(GL_POLYGON);
   glVertex2f(97.5,52);
   glVertex2f(98.5,52);
   glVertex2f(98.5,64);
   glVertex2f(97.5,65);
   glEnd();

   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(92.5,61);
   glVertex2f(94,61);
   glVertex2f(94,63);
   glVertex2f(92.5,63);
   glEnd();

   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(95,61);
   glVertex2f(96.5,61);
   glVertex2f(96.5,63);
   glVertex2f(95,63);
   glEnd();

   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(92.5,57);
   glVertex2f(94,57);
   glVertex2f(94,59);
   glVertex2f(92.5,59);
   glEnd();

   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(95,57);
   glVertex2f(96.5,57);
   glVertex2f(96.5,59);
   glVertex2f(95,59);
   glEnd();

   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(92.5,53);
   glVertex2f(94,53);
   glVertex2f(94,55);
   glVertex2f(92.5,55);
   glEnd();

   glColor3f(0.6,0.9,0.8);
   glBegin(GL_POLYGON);
   glVertex2f(95,53);
   glVertex2f(96.5,53);
   glVertex2f(96.5,55);
   glVertex2f(95,55);
   glEnd();

   //tree-1
   glColor3f(0.4,0.3,0.2);
   glBegin(GL_POLYGON);
   glVertex2f(21,52);
   glVertex2f(22,52);
   glVertex2f(22,57);
   glVertex2f(21,57);
   glEnd();

   //green leaf
   glColor3ub(3,102,24);
   circle(1.8,1.8,19.5,57.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.2,1.2,21.5,56.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.8,1.8,23.5,57.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.8,1.8,21.5,61);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.8,1.8,21.5,59);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,20,59.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,23,59.5);
   glEnd();

   //tree-2
   glColor3f(0.4,0.3,0.2);
   glBegin(GL_POLYGON);
   glVertex2f(27.5,52);
   glVertex2f(28.1,52);
   glVertex2f(28.1,55);
   glVertex2f(27.5,55);
   glEnd();

   //green leaf
   glColor3ub(3,102,24);
   circle(1.2,1.2,27,55);
   glEnd();

   glColor3ub(3,102,24);
   circle(1,1,27.8,54.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.2,1.2,28.5,55);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.1,1.1,27.8,56.2);
   glEnd();

   //tree-3
   glColor3f(0.4,0.3,0.2);
   glBegin(GL_POLYGON);
   glVertex2f(78,52);
   glVertex2f(79.5,52);
   glVertex2f(79.5,64);
   glVertex2f(78,64);
   glEnd();

   //green leaf
   glColor3ub(3,102,24);
   circle(2.2,2.2,75.5,61);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.6,1.6,78,59.8);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.6,1.6,80,59.8);
   glEnd();

   glColor3ub(3,102,24);
   circle(2.2,2.2,82.1,61);
   glEnd();

   glColor3ub(3,102,24);
   circle(2.2,2.2,78.8,67.4);
   glEnd();

   glColor3ub(3,102,24);
   circle(2.4,2.4,78.8,63.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,75.8,63.8);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,76.8,66);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,81.7,63.8);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,80.7,66);
   glEnd();

   //tree-4
   glColor3f(0.4,0.3,0.2);
   glBegin(GL_POLYGON);
   glVertex2f(87,52);
   glVertex2f(88,52);
   glVertex2f(88,57);
   glVertex2f(87,57);
   glEnd();

   //green leaf
   glColor3ub(3,102,24);
   circle(1.8,1.8,85.5,57.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.2,1.2,87.5,56.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.8,1.8,89.5,57.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.8,1.8,87.5,61);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.8,1.8,87.5,59);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,86,59.5);
   glEnd();

   glColor3ub(3,102,24);
   circle(1.5,1.5,89,59.5);
   glEnd();

glutSwapBuffers();
}

int main(int argc,char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutCreateWindow("Final Project");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
