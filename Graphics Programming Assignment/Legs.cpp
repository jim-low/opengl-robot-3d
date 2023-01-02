#include "Legs.h"

void Legs::draw() {

	float scaling = 0.8;
	glScalef(scaling, scaling, scaling);
	//glTranslatef(0, 0.9, 0); // just to move the model up so can see better
	drawQuads();
	drawShin();
}

void Legs::drawQuads()
{
	glPushMatrix();
	glRotatef(70, 1, 0, 0);
	glTranslatef(0, -0.01, 0);
	Shapes::drawCylinder(0.25, 0.25, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(75, 1, 0, 0);
	glTranslatef(0, -0.01, 0.1);
	Shapes::drawCylinder(0.25, 0.27, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(80, 1, 0, 0);
	glTranslatef(0, 0.005, 0.2);
	Shapes::drawCylinder(0.27, 0.27, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(85, 1, 0, 0);
	glTranslatef(0, 0.03, 0.3);
	Shapes::drawCylinder(0.27, 0.26, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.4);
	Shapes::drawCylinder(0.26, 0.25, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.5);
	Shapes::drawCylinder(0.25, 0.23, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.6);
	Shapes::drawCylinder(0.23, 0.21, 0.125, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.7);
	Shapes::drawCylinder(0.21, 0.18, 0.15, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.8);
	Shapes::drawCylinder(0.18, 0.15, 0.175, 30, 30, GLU_LINE);
	glPopMatrix();

	// joint for the knee (also acts as the knee)
	glPushMatrix();
	glTranslatef(0, -0.98, 0.05);
	Shapes::drawSphere(0.15, 30, 30, GLU_LINE);
	glPopMatrix();
}

void Legs::drawShin()
{
	glPushMatrix();
	glTranslatef(0, -1 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.15, 0.16, 0.12, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.12 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.16, 0.163, 0.12, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.24 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.163, 0.13, 0.12, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.36 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.13, 0.115, 0.12, 30, 30, GLU_LINE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.48 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.115, 0.1, 0.12, 30, 30, GLU_LINE);
	glPopMatrix();

	// joint for the ankle
	glPushMatrix();
	glTranslatef(0, -1.58 , 0.05);
	Shapes::drawSphere(0.1, 30, 30, GLU_LINE);
	glPopMatrix();
}
