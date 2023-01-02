#include "Gun.h"
#include "Vector3.h"

void Gun::draw() {
	glPushMatrix();
	glTranslatef(-0.15, 0.14, 0.05);
	glColor3f(0, 0, 0);
	Shapes::drawSphere(0.05, 30, 30, GLU_FILL);
	glPopMatrix();
	glColor3f(0.2, 0.2, 0.2);
	Shapes::drawCuboid(Vector3(-0.2, -0.2, 0), 0.1, 0.33, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(-0.1, -0.05, 0), 0.5, 0.18, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.0, -0.35, 0), 0.15, 0.3, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.03, -0.45, 0), 0.09, 0.1, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.2, -0.1, 0), 0.03, 0.05, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.28, -0.15, 0), 0.03, 0.1, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.15, -0.15, 0), 0.13, 0.03, 0.1, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.4, -0.03, 0), 0.05, 0.14, 0.1, GL_QUADS);

	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(Vector3(-0.2, -0.2, 0), 0.1, 0.33, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(-0.1, -0.05, 0), 0.5, 0.18, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(0.0, -0.35, 0), 0.15, 0.3, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(0.03, -0.45, 0), 0.09, 0.1, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(0.2, -0.1, 0), 0.03, 0.05, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(0.28, -0.15, 0), 0.03, 0.1, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(0.15, -0.15, 0), 0.13, 0.03, 0.1, GL_LINE_LOOP);
	Shapes::drawCuboid(Vector3(0.4, -0.03, 0), 0.05, 0.14, 0.1, GL_LINE_LOOP);
	glPushMatrix();
	glTranslatef(0.45, 0.04, 0.05);
	glRotatef(90, 0, 1, 0);
	glColor3f(0, 0, 0);
	Shapes::drawCylinder(0.04, 0.04, 0.15, 30, 30, GLU_FILL);
	glColor3f(0, 0, 0);
	Shapes::drawSphere(0.04, 30, 30, GLU_FILL);
	glPopMatrix();
}