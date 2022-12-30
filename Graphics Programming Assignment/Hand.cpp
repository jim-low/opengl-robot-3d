#include "Hand.h"
#include "Vector3.h"

/* Cube formula (GL_QUADS)
	1234
	5678
	1562
	4873
	1584
	2673
*/


void Hand::drawPalm() {
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

void Hand::drawLowerArm() {
	
	Shapes::drawSphere(0.1, 30, 30, GLU_LINE); // cylinder base arm

	//Lower arm
	glPushMatrix();

	glRotatef(lArmRot_X, 1, 0, 0);		//	rotate in x
	glRotatef(lArmRot_Y, 0, 1, 0);		//	rotate in y
	glRotatef(lArmRot_Z, 0, 0, 1);		//	rotate in z
	glTranslatef(0, 0, -0.5);			//	translate according cylinder arm height

	Shapes::drawCylinder(0.06, 0.1, 0.5, 30, 30, GLU_LINE); // cylinder base arm

	drawPalm();	//draw palm

	glPopMatrix();
}

void Hand::drawUpperArm() {

	Shapes::drawSphere(0.1, 30, 30, GLU_LINE); // cylinder base arm
	
	//Upper arm
	glPushMatrix();

	glRotatef(uArmRot_Y, 0, 1, 0);		//	rotate in y
	glRotatef(uArmRot_Z, 0, 0, 1);		//	rotate in z
	glRotatef(uArmRot_X, 1, 0, 0);		//	rotate in x
	glTranslatef(0, 0, -0.4);			//	translate according cylinder arm height

	Shapes::drawCylinder(0.1, 0.1, 0.4, 30, 30, GLU_LINE); // cylinder base arm
	
	drawLowerArm();	// draw lower arm
	glPopMatrix();
	
}


void Hand::draw()
{
	drawUpperArm();
	Shapes::drawSphere(0.1, 30, 30, GLU_LINE); // cylinder base arm
}
