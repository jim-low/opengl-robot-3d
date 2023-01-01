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

Vector3* p1 = new Vector3();
Vector3* p2 = new Vector3();
Vector3* p3 = new Vector3();
Vector3* p4 = new Vector3();
Vector3* p5 = new Vector3();
Vector3* p6 = new Vector3();
Vector3* p7 = new Vector3();
Vector3* p8 = new Vector3();

/*	8 point set up template
	p1->setVector(0, 0, 0);
	p2->setVector(0, 0, 0);
	p3->setVector(0, 0, 0);
	p4->setVector(0, 0, 0);				  
	p5->setVector(0, 0, 0);
	p6->setVector(0, 0, 0);
	p7->setVector(0, 0, 0);
	p8->setVector(0, 0, 0);
*/

void Hand::drawThumb() {
	glPointSize(5);	
	glBegin(GL_POINTS);

	glColor3f(0, 1, 0);
	glVertex3f(-0.1, 0.025, -0.08);

	glColor3f(0, 0, 1);
	glVertex3f(-0.1, -0.05, -0.08);

	glEnd();

	glColor3f(1, 0, 0);
	
	/*
	p1->setVector(-0.1, 0.025, -0.08);
	p2->setVector(-0.08, 0.025, -0.08);
	p3->setVector(0.08, -0.05);
	p4->setVector(-0.1, -0.05, -0.08);

	p5->setVector(0, 0, -0.16);
	p6->setVector(0, 0, -0.16);
	p7->setVector(0, 0, -0.16);
	p8->setVector(0, 0, -0.16);*/

	//Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8);
	Shapes::drawCuboid(*p1, 0.1, 0.3, 0.5, GL_QUADS);
}

void Hand::drawPalm() {
	glPushMatrix();
	glTranslatef(0,0,0.015);
	Shapes::drawSphere(0.06, 30, 30, GLU_LINE);

	//palm
	glPushMatrix();
	glTranslatef(0,0.01,-0.02);

	// lower palm	
	p1->setVector(0.05, 0.025, 0);
	p2->setVector(-0.05, 0.025, 0);
	p3->setVector(-0.05, -0.05, 0);
	p4->setVector(0.05, -0.05, 0);

	p5->setVector(0.08, 0.025, -0.08);
	p6->setVector(-0.1, 0.025, -0.08);
	p7->setVector(-0.1, -0.05, -0.08);
	p8->setVector(0.08, -0.05, -0.08);
	
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);

	//upper palm
	p1->setVector(0.05f, 0.025f, -0.13f);
	p2->setVector(-0.05f, 0.025f, -0.13f);
	p3->setVector(-0.05f, -0.05f, -0.13f);
	p4->setVector(0.05f, -0.05f, -0.13f);

	p5->setVector(0.08, 0.025, -0.08);
	p6->setVector(-0.1, 0.025, -0.08);
	p7->setVector(-0.1, -0.05, -0.08);
	p8->setVector(0.08, -0.05, -0.08);

	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_LINE_LOOP);
	
	// thumb
	drawThumb();
	

	glColor3f(1, 1, 1);
	glPopMatrix();
	glPopMatrix();
}

void Hand::drawLowerArm() {
	
	Shapes::drawSphere(0.1, 30, 30, GLU_LINE); // joint

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

	Shapes::drawSphere(0.1, 30, 30, GLU_LINE); // joint
	
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
	glScalef(2,2,2);
	drawPalm();
	//drawUpperArm();
}
