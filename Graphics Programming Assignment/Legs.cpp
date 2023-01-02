#include "Legs.h"

void Legs::draw() {

	//glTranslatef(0, 0.9, 0); // just to move the model up so can see better
	ringRot+= 0.5;
	if (ringRot > 360) {
		ringRot == 0;
	}

	drawQuads();

	drawShin();

	fireScale.x += fireScaling;
	fireScale.y += fireScaling;
	fireScale.z += fireScaling;
	
	if (fireScale.x > 1) {
		fireScaling = -0.002;
	}
	if (fireScale.x < 0.5 || fireScale.x == 0) {
		fireScaling = 0.002;
	}

	drawFire();
	//drawFoot();
}

void Legs::drawQuads()
{
	glColor3f(0, 0, 0);
	glPushMatrix();
	glRotatef(70, 1, 0, 0);
	glTranslatef(0, -0.01, 0);
	Shapes::drawCylinder(0.25, 0.25, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	glRotatef(75, 1, 0, 0);
	glTranslatef(0, -0.01, 0.1);
	Shapes::drawCylinder(0.25, 0.27, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();

	
	glPushMatrix();
	glRotatef(80, 1, 0, 0);
	glTranslatef(0, 0.005, 0.2);
	Shapes::drawCylinder(0.27, 0.27, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();


	glPushMatrix();
	glRotatef(85, 1, 0, 0);
	glTranslatef(0, 0.03, 0.3);
	Shapes::drawCylinder(0.27, 0.26, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.4);
	Shapes::drawCylinder(0.26, 0.25, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();

	
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.5);
	Shapes::drawCylinder(0.25, 0.23, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();

	
	
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.6);
	Shapes::drawCylinder(0.23, 0.21, 0.125, 30, 30, GLU_FILL);
	glPopMatrix();

	
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.7);
	Shapes::drawCylinder(0.21, 0.18, 0.15, 30, 30, GLU_FILL);
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.06, 0.8);
	Shapes::drawCylinder(0.18, 0.15, 0.175, 30, 30, GLU_FILL);
	glColor3f(0, 0, 0);

	glPushMatrix();
	glRotatef(ringRot, 0, 0, 1);
	Shapes::drawCylinder(0.181, 0.151, 0.175, 10, 1, GLU_LINE);
	glPopMatrix();

	glPopMatrix();

	glColor3f(1, 1, 1);
	// joint for the knee (also acts as the knee)
	glPushMatrix();
	glTranslatef(0, -0.955, 0.05);
	Shapes::drawSphere(0.13, 30, 30, GLU_FILL);
	
	glPopMatrix();
}

void Legs::drawShin()
{
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(0, -0.98 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.15, 0.16, 0.12, 30, 30, GLU_FILL);
	glPopMatrix();

	glColor3f(1, 1, 1);
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(0, -1.1 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.16, 0.163, 0.12, 30, 30, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.22 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.163, 0.13, 0.12, 30, 30, GLU_FILL);
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0, -1.34 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.13, 0.115, 0.12, 30, 30, GLU_FILL);
	glColor3f(0, 0, 0);

	glPushMatrix();
	glRotatef(ringRot * -1, 0, 0, 1);
	Shapes::drawCylinder(0.131, 0.1151, 0.12, 10, 1, GLU_LINE);
	glPopMatrix();

	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(0, -1.46 , 0.05);
	glRotatef(90, 1, 0, 0);
	Shapes::drawCylinder(0.115, 0.1, 0.12, 30, 30, GLU_FILL);
	glPopMatrix();

	// joint for the ankle
	glPushMatrix();
	glTranslatef(0, -1.5 , 0.05);
	Shapes::drawSphere(0.1, 30, 30, GLU_FILL);
	
	glPopMatrix();
}

void Legs::drawFire() {
	glPushMatrix();
	glTranslatef(0, -1.6, 0.04);
	glRotatef(90,1,0,0);
	glColor3f(1, 0, 0);

	glPushMatrix();
	glScalef(fireScale.x, fireScale.y, fireScale.z);
	Shapes::drawSphere(0.12, 30, 30, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	glScalef(fireScale.x, fireScale.y, fireScale.z);
	Shapes::drawCylinder(0.121, 0, 0.5, 30, 30, GLU_FILL);
	glPopMatrix();

	glPopMatrix();
}

void Legs::drawFoot()
{
	glPushMatrix();
	Shapes::drawCube(
		Vector3(),
		Vector3(),
		Vector3(),
		Vector3(),
		Vector3(),
		Vector3(),
		Vector3(),
		Vector3(),
		GL_LINE_LOOP);
	glPopMatrix();
}
