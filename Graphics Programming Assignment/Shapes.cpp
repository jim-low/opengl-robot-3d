#include "Shapes.h"

void Shapes::drawCylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks, GLenum drawStyle) {
	

	GLUquadricObj* gluObj = NULL;//create quadric obj pointer
	gluObj = gluNewQuadric();
	gluQuadricDrawStyle(gluObj, drawStyle);

	gluCylinder(gluObj, baseRadius, topRadius, height, slices, stacks);

	gluDeleteQuadric(gluObj);

}

void Shapes::drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum drawStyle) {
	

	GLUquadricObj* gluObj = NULL;//create quadric obj pointer
	gluObj = gluNewQuadric();
	gluQuadricDrawStyle(gluObj, drawStyle);

	gluSphere(gluObj, radius, slices, stacks);

	gluDeleteQuadric(gluObj);

}

void Shapes::drawCube(Vector3 startPoint, float width, float height, float length) {
	// front face
	glBegin(GL_LINE_LOOP);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z);
	glEnd();

	// left side face
	glBegin(GL_LINE_LOOP);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z);
	glEnd();

	// right side of face
	glBegin(GL_LINE_LOOP);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z);
	glEnd();
	
	// top side of face
	glBegin(GL_LINE_LOOP);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z + length);
	glEnd();

	// bottom side of face
	glBegin(GL_LINE_LOOP);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z + length);
	glEnd();

	// back side
	glBegin(GL_LINE_LOOP);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z + length);
	glEnd();
}
