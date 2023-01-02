#include "Head.h"

void Head::draw() {
	glPushMatrix();
	glRotatef(headRotAngle->x, 0, 1, 0);
	glRotatef(headRotAngle->y, 1, 0, 0);

	drawFrontPlane();
	drawFrontTopPlane();

	glPushMatrix();
	glScalef(0.85,1,0.9);
	drawFrontBottomPlane();
	glPopMatrix();

	drawBackHalf();
	drawNeck();
	drawAntenna1();
	drawAntenna2();

	glPopMatrix();
}

void Head::drawFrontPlane() {
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	//glBegin(GL_LINE_LOOP);
	//glMatrixMode(GL_MODELVIEW);

	glColor3f(0.7098, 0.8274, 0.9058);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glColor3f(0.70, 0.82, 0.8);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glEnd();
	glPopMatrix();
}
void Head::drawFrontTopPlane() {
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	//glBegin(GL_LINE_LOOP);
	//glMatrixMode(GL_MODELVIEW);

	glColor3f(1.0f, 1.0, 0);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.25f, 0.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0F, 1.0);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.25f, 0.0f);
	glVertex3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glColor3f(0.5, 0.5, 0.5);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.25f, 0.0f);
	glVertex3f(1.0f, 1.15f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glColor3f(0.5, 0.5, 0.5);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.25f, 0.0f);
	glVertex3f(-1.0f, 1.15f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glEnd();

	glPopMatrix();

}
void Head::drawFrontBottomPlane() {
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	//glBegin(GL_TRIANGLE_FAN);
	glBegin(GL_QUADS);
	//glMatrixMode(GL_MODELVIEW);

	glColor3f(0.0f, 0.0, 0);
	//F1 (bottom side)
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.3f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.3f);
	glVertex3f(0.0f, 0.0f, 1.0f);

	//F1 (bottom side)
	glVertex3f(1.3f, 0.0f, 0.0f);
	glVertex3f(1.3f, -0.2f, 0.0f);
	glVertex3f(0.0f, -0.2f, 1.3f);
	glVertex3f(0.0f, 0.0f, 1.3f);

	//F1 (bottom side)
	glVertex3f(1.3f, -0.2f, 0.0f);
	glVertex3f(0.0f, -0.2f, 1.3f);
	glVertex3f(0.0f, -0.2f, 1.0f);
	glVertex3f(1.0f, -0.2f, 0.0f);

	//F1 (bottom side)
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.3f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.3f);
	glVertex3f(0.0f, 0.0f, 1.0f);

	//F1 (bottom side)
	glVertex3f(-1.3f, 0.0f, 0.0f);
	glVertex3f(-1.3f, -0.2f, 0.0f);
	glVertex3f(0.0f, -0.2f, 1.3f);
	glVertex3f(0.0f, 0.0f, 1.3f);

	//F1 (bottom side)
	glVertex3f(-1.3f, -0.2f, 0.0f);
	glVertex3f(0.0f, -0.2f, 1.3f);
	glVertex3f(0.0f, -0.2f, 1.0f);
	glVertex3f(-1.0f, -0.2f, 0.0f);
	glEnd();
	glPopMatrix();
}
void Head::drawBackHalf() {
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	//glBegin(GL_TRIANGLE_FAN);
	glBegin(GL_TRIANGLE_FAN);
	//glMatrixMode(GL_MODELVIEW);

	glColor3f(0.0f, 0.0, 0.0f);
	//F1 (bottom side)
	glVertex3f(0.0f, 1.25f, 0.0f);
	glVertex3f(1.0f, 1.15f, 0.0f);
	glVertex3f(0.95f, 1.15f, -0.5f);
	glVertex3f(0.45f, 1.15f, -0.95f);
	glVertex3f(-0.45f, 1.15f, -0.95f);
	glVertex3f(-0.95f, 1.15f, -0.5f);
	glVertex3f(-1.0f, 1.15f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	//glMatrixMode(GL_MODELVIEW);

	glColor3f(0.0f, 0.0, 0);
	//F1 (bottom side)
	glVertex3f(1.0f, 1.15f, 0.0f);
	glVertex3f(1.0f, -0.2f, 0.0f);
	glVertex3f(0.95f, -0.2f, -0.5f);
	glVertex3f(0.95f, 1.15f, -0.5f);

	glVertex3f(0.95f, 1.15f, -0.5f);
	glVertex3f(0.95f, -0.2f, -0.5f);
	glVertex3f(0.45f, -0.2f, -0.95f);
	glVertex3f(0.45f, 1.15f, -0.95f);

	glVertex3f(0.45f, 1.15f, -0.95f);
	glVertex3f(0.45f, -0.2f, -0.95f);
	glVertex3f(-0.45f, -0.2f, -0.95f);
	glVertex3f(-0.45f, 1.15f, -0.95f);

	//F1 (bottom side)
	glVertex3f(-1.0f, 1.15f, 0.0f);
	glVertex3f(-1.0f, -0.2f, 0.0f);
	glVertex3f(-0.95f, -0.2f, -0.5f);
	glVertex3f(-0.95f, 1.15f, -0.5f);

	glVertex3f(-0.95f, 1.15f, -0.5f);
	glVertex3f(-0.95f, -0.2f, -0.5f);
	glVertex3f(-0.45f, -0.2f, -0.95f);
	glVertex3f(-0.45f, 1.15f, -0.95f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glMatrixMode(GL_MODELVIEW);

	//F1 (bottom side)
	glVertex3f(0.0f, -0.2f, 0.0f);
	glVertex3f(1.0f, -0.2f, 0.0f);
	glVertex3f(0.95f, -0.2f, -0.5f);
	glVertex3f(0.45f, -0.2f, -0.95f);
	glVertex3f(-0.45f, -0.2f, -0.95f);
	glVertex3f(-0.95f, -0.2f, -0.5f);
	glVertex3f(-1.0f, -0.2f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glMatrixMode(GL_MODELVIEW);

	//F1 (bottom side)
	glVertex3f(-1.0f, -0.2f, 0.0f);
	glVertex3f(0.0f, -0.2f, 1.0f);
	glVertex3f(1.0f, -0.2f, 0.0f);
	glEnd();
	glPopMatrix();
}
void Head::drawNeck() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0.0, -0.2, 0.0);
	glTranslatef(0.0, 0.0, -0.1);
	glRotatef(-90, 1.0, 0.0, 0.0);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 0.35, 0.35, 0.3, 50, 50);
	glColor3f(0, 0, 0);
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 0.351, 0.351, 0.3, 7, 5);
	gluDeleteQuadric(cylinder);
	glPopMatrix();
}
void Head::drawAntenna1() {
	glPushMatrix();
	glColor3f(1.0f, 1.0, 0);
	glTranslatef(0.0, 0.5, 0.0);
	glTranslatef(0.0, 0.0, -0.2);
	glTranslatef(-0.2, 0.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 0.05, 0.01, 0.4, 50, 50);
	gluDeleteQuadric(cylinder);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glTranslatef(0.0, 0.0, -0.2);
	glTranslatef(-0.2, 0.0, 0.0);
	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 0.05, 50, 50);
	gluDeleteQuadric(sphere);
	glEnd();
	glPopMatrix();
}
void Head::drawAntenna2() {
	glPushMatrix();
	glColor3f(1.0f, 1.0, 0);
	glTranslatef(0.0, 0.5, 0.0);
	glTranslatef(0.0, 0.0, -0.2);
	glTranslatef(0.2, 0.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, 0.05, 0.01, 0.4, 50, 50);
	gluDeleteQuadric(cylinder);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glTranslatef(0.0, 0.0, -0.2);
	glTranslatef(0.2, 0.0, 0.0);
	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 0.05, 50, 50);
	gluDeleteQuadric(sphere);
	glEnd();
	glPopMatrix();
}