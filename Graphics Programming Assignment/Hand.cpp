#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Hand.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "OpenGL Window"


float objZ = 0.0f, objSpeed = 0.1f;		//	object translate in z-axis
float oNear = -10.0f, oFar = 10.0f;			//	ortho near & far
float pNear = 1.0f, pFar = 20.0f;				//	perspective near & far
float ptx = 0.0f, pty = 0.0f, ptSpeed = 0.1f;	//	translation for projection
float prx = 0.0f, pry = 0.0f, prSpeed = 5;			//	rotation for projection

bool positiveTransform = true;
float uArmRot_X = 0, uArmRot_Y = 0, uArmRot_Z = 0, uArmRot = 5;	// upper arm rotaion
float lArmRot_X = 0, lArmRot_Y = 0, lArmRot_Z = 0, lArmRot = 5;	// lower arm rotaion

/* Cube formula (GL_QUADS)
	1234
	5678
	1562
	4873
	1584
	2673
*/

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		

		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void drawCube(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, Vector3 p5, Vector3 p6, Vector3 p7, Vector3 p8) {
	glVertex3f(p1.x, p1.y, p1.z);		//	point 1
	glVertex3f(p2.x, p2.y, p2.z);		//	point 2
	glVertex3f(p3.x, p3.y, p3.z);		//	point 3
	glVertex3f(p4.x, p4.y, p4.z);		//	point 4

	glVertex3f(p5.x, p5.y, p5.z);		//	point 5
	glVertex3f(p6.x, p6.y, p6.z);		//	point 6
	glVertex3f(p7.x, p7.y, p7.z);		//	point 7
	glVertex3f(p8.x, p8.y, p8.z);		//	point 8

	glVertex3f(p1.x, p1.y, p1.z);		//	point 1
	glVertex3f(p5.x, p5.y, p5.z);		//	point 5
	glVertex3f(p6.x, p6.y, p6.z);		//	point 6
	glVertex3f(p2.x, p2.y, p2.z);		//	point 2

	glVertex3f(p4.x, p4.y, p4.z);		//	point 4
	glVertex3f(p8.x, p8.y, p8.z);		//	point 8
	glVertex3f(p7.x, p7.y, p7.z);		//	point 7
	glVertex3f(p3.x, p3.y, p3.z);		//	point 3

	glVertex3f(p1.x, p1.y, p1.z);		//	point 1
	glVertex3f(p5.x, p5.y, p5.z);		//	point 5
	glVertex3f(p8.x, p8.y, p8.z);		//	point 8
	glVertex3f(p4.x, p4.y, p4.z);		//	point 4

	glVertex3f(p2.x, p2.y, p2.z);		//	point 2
	glVertex3f(p6.x, p6.y, p6.z);		//	point 6
	glVertex3f(p7.x, p7.y, p7.z);		//	point 7
	glVertex3f(p3.x, p3.y, p3.z);		//	point 3
}

void drawSphere() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	GLUquadricObj* sphere = NULL;//create quadric obj pointer
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_LINE);

	//glColor3f(1, 1, 1);
	glRotatef(0.03, 1, 1, 1);
	gluSphere(sphere, 5, 30, 30);

	gluDeleteQuadric(sphere);

}

void projection() {
	glMatrixMode(GL_PROJECTION);	//refer to the projection matrix
	glLoadIdentity();				//reset the projections matrix

	glTranslatef(ptx, pty, 0);	//translate in x and y for projection
	glRotatef(pry, 0, 1, 0);		//rotate in y
	glRotatef(prx, 1, 0, 0);		//rotate in x
	if (isOrtho) {
		glOrtho(-10, 10, -10, 10, oNear, oFar);
	}
	else {
		gluPerspective(10, 1, -1, 1);
		glFrustum(-10, 10, -10, 10, pNear, pFar);
	}
}

void drawPalm() {
	GLUquadricObj* gluObj = NULL;//create quadric obj pointer
	gluObj = gluNewQuadric();
	gluQuadricDrawStyle(gluObj, GLU_LINE);

	gluSphere(gluObj, 0.06, 30, 30);

	//palm
	glPushMatrix();
	glBegin(GL_QUADS);


	// upper palm
	glColor3f(1, 0, 0);
	glVertex3f(0.05, 0.05, 0);			//	point 1
	glVertex3f(-0.05, 0.05, 0);			//	point 2
	glVertex3f(-0.05, -0.05, 0);		//	point 3
	glVertex3f(0.05, -0.05, 0);			//	point 4

	glVertex3f(0.08, 0.05, -0.08);		//	point 5
	glVertex3f(-0.1, 0.05, -0.08);		//	point 6
	glVertex3f(-0.1, -0.05, -0.08);		//	point 7
	glVertex3f(0.08, -0.05, -0.08);		//	point 8

	glVertex3f(0.05, 0.05, 0);			//	point 1
	glVertex3f(0.08, 0.05, -0.08);		//	point 5
	glVertex3f(-0.1, 0.05, -0.08);		//	point 6
	glVertex3f(-0.05, 0.05, 0);			//	point 2

	glVertex3f(0.05, -0.05, 0);			//	point 4
	glVertex3f(0.08, -0.05, -0.08);		//	point 8
	glVertex3f(-0.1, -0.05, -0.08);		//	point 7
	glVertex3f(-0.05, -0.05, 0);		//	point 3

	glVertex3f(0.05, 0.05, 0);			//	point 1
	glVertex3f(0.08, 0.05, -0.08);		//	point 5
	glVertex3f(0.08, -0.05, -0.08);		//	point 8
	glVertex3f(0.05, -0.05, 0);			//	point 4

	glVertex3f(-0.05, 0.05, 0);			//	point 2
	glVertex3f(-0.1, 0.05, -0.08);		//	point 6
	glVertex3f(-0.1, -0.05, -0.08);		//	point 7
	glVertex3f(-0.05, -0.05, 0);		//	point 3

	//lower palm
	glVertex3f(0.05, 0.05, -0.13);		//	point 1
	glVertex3f(-0.05, 0.05, -0.13);		//	point 2
	glVertex3f(-0.05, -0.05, -0.13);	//	point 3
	glVertex3f(0.05, -0.05, -0.13);		//	point 4

	glVertex3f(0.07, 0.04, -0.08);		//	point 5
	glVertex3f(-0.09, 0.04, -0.08);		//	point 6
	glVertex3f(-0.09, -0.04, -0.08);		//	point 7
	glVertex3f(0.07, -0.04, -0.08);		//	point 8

	glVertex3f(0.05, 0.05, -0.13);		//	point 1
	glVertex3f(0.08, 0.05, -0.08);		//	point 5
	glVertex3f(-0.1, 0.05, -0.08);		//	point 6
	glVertex3f(-0.05, 0.05, -0.13);		//	point 2

	glVertex3f(0.05, -0.05, -0.13);		//	point 4
	glVertex3f(0.08, -0.05, -0.08);		//	point 8
	glVertex3f(-0.1, -0.05, -0.08);		//	point 7
	glVertex3f(-0.05, -0.05, -0.13);	//	point 3

	glVertex3f(0.05, 0.05, -0.13);		//	point 1
	glVertex3f(0.08, 0.05, -0.08);		//	point 5
	glVertex3f(0.08, -0.05, -0.08);		//	point 8
	glVertex3f(0.05, -0.05, -0.13);		//	point 4

	glVertex3f(-0.05, 0.05, -0.13);		//	point 2
	glVertex3f(-0.1, 0.05, -0.08);		//	point 6
	glVertex3f(-0.1, -0.05, -0.08);		//	point 7
	glVertex3f(-0.05, -0.05, -0.13);	//	point 3

	glColor3f(1, 1, 1);
	glEnd();
	glPopMatrix();

	gluDeleteQuadric(gluObj);
}

void drawLowerArm() {
	GLUquadricObj* gluObj = NULL;//create quadric obj pointer
	gluObj = gluNewQuadric();
	gluQuadricDrawStyle(gluObj, GLU_LINE);

	gluSphere(gluObj, 0.1, 30, 30);

	//Lower arm
	glPushMatrix();
	glRotatef(lArmRot_X, 1, 0, 0);		//	rotate in x
	glRotatef(lArmRot_Y, 0, 1, 0);		//	rotate in y
	glRotatef(lArmRot_Z, 0, 0, 1);		//	rotate in z
	glTranslatef(0, 0, -0.5);			//	translate according cylinder arm height

	gluCylinder(gluObj, 0.06, 0.1, 0.5, 30, 30);	// cylinder base arm

	drawPalm();	//draw palm

	glPopMatrix();

	gluDeleteQuadric(gluObj);
}

void drawUpperArm() {
	GLUquadricObj* gluObj = NULL;//create quadric obj pointer
	gluObj = gluNewQuadric();
	gluQuadricDrawStyle(gluObj, GLU_LINE);

	gluSphere(gluObj, 0.1, 30, 30);

	//Upper arm
	glPushMatrix();

	glRotatef(uArmRot_Y, 0, 1, 0);		//	rotate in y
	glRotatef(uArmRot_Z, 0, 0, 1);		//	rotate in z
	glRotatef(uArmRot_X, 1, 0, 0);		//	rotate in x
	glTranslatef(0, 0, -0.4);			//	translate according cylinder arm height


	gluCylinder(gluObj, 0.1, 0.1, 0.4, 30, 30);	// cylinder base arm

	drawLowerArm();	// draw lower arm

	glPopMatrix();

	gluDeleteQuadric(gluObj);


}

void display()
{
	/*projection();*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, objZ);			//zoom in and out
	glRotatef(pry, 0, 1, 0);		//rotate in y
	glRotatef(prx, 1, 0, 0);		//rotate in x

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);


	switch (isOrtho) {
	case 0:
		glPushMatrix();
		glScalef(6, 6, 6);
		drawPalm();


		glPopMatrix();
		break;
	case 1:
		glPushMatrix();
		drawUpperArm();
		glPopMatrix();
		break;
	}




}
//--------------------------------------------------------------------
