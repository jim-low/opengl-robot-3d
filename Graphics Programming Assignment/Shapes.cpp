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

void Shapes::drawSphereWithTexture(GLdouble radius, GLint slices, GLint stacks, GLenum drawStyle) {


	GLUquadricObj* gluObj = NULL;//create quadric obj pointer
	gluObj = gluNewQuadric();
	gluQuadricDrawStyle(gluObj, drawStyle);
	gluQuadricTexture(gluObj, true);

	gluSphere(gluObj, radius, slices, stacks);

	gluDeleteQuadric(gluObj);

}

void Shapes::drawCuboid(Vector3 startPoint, float width, float height, float length, GLenum glBeginMode) {
	// front face
	glBegin(glBeginMode);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z);
	glEnd();

	// left side face
	glBegin(glBeginMode);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z);
	glEnd();

	// right side of face
	glBegin(glBeginMode);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z);
	glEnd();

	// top side of face
	glBegin(glBeginMode);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z + length);
	glEnd();

	// bottom side of face
	glBegin(glBeginMode);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z + length);
	glEnd();

	// back side
	glBegin(glBeginMode);
	glVertex3f(startPoint.x, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y, startPoint.z + length);
	glVertex3f(startPoint.x + width, startPoint.y + height, startPoint.z + length);
	glVertex3f(startPoint.x, startPoint.y + height, startPoint.z + length);
	glEnd();
}


/*Notes !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	p1,p2,p3,p4 must be at same z axis plane which mean must have same z value
	p5,p6,p7,p8 must have same z value
	sequence of point in anticlockwise

	glBeginMode - GL_QUADS = filled 
				- GL_LINE_LOOP = outline
*/
void Shapes::drawCube(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, Vector3 p5, Vector3 p6, Vector3 p7, Vector3 p8, GLenum glBeginMode)
{
	//top surface
	glBegin(glBeginMode);
	glVertex3f(p1.x, p1.y, p1.z);		//	point 1
	glVertex3f(p2.x, p2.y, p2.z);		//	point 2
	glVertex3f(p3.x, p3.y, p3.z);		//	point 3
	glVertex3f(p4.x, p4.y, p4.z);		//	point 4
	glEnd();

	//bottom surface
	glBegin(glBeginMode);
	glVertex3f(p5.x, p5.y, p5.z);		//	point 5
	glVertex3f(p6.x, p6.y, p6.z);		//	point 6
	glVertex3f(p7.x, p7.y, p7.z);		//	point 7
	glVertex3f(p8.x, p8.y, p8.z);		//	point 8
	glEnd();
	//back surface
	glBegin(glBeginMode);
	glVertex3f(p1.x, p1.y, p1.z);		//	point 1
	glVertex3f(p5.x, p5.y, p5.z);		//	point 5
	glVertex3f(p6.x, p6.y, p6.z);		//	point 6
	glVertex3f(p2.x, p2.y, p2.z);		//	point 2
	glEnd();
	//front surface
	glBegin(glBeginMode);
	glVertex3f(p4.x, p4.y, p4.z);		//	point 4
	glVertex3f(p8.x, p8.y, p8.z);		//	point 8
	glVertex3f(p7.x, p7.y, p7.z);		//	point 7
	glVertex3f(p3.x, p3.y, p3.z);		//	point 3
	glEnd();
	//left surface
	glBegin(glBeginMode);
	glVertex3f(p1.x, p1.y, p1.z);		//	point 1
	glVertex3f(p5.x, p5.y, p5.z);		//	point 5
	glVertex3f(p8.x, p8.y, p8.z);		//	point 8
	glVertex3f(p4.x, p4.y, p4.z);		//	point 4
	glEnd();
	//right surface
	glBegin(glBeginMode);
	glVertex3f(p2.x, p2.y, p2.z);		//	point 2
	glVertex3f(p6.x, p6.y, p6.z);		//	point 6
	glVertex3f(p7.x, p7.y, p7.z);		//	point 7
	glVertex3f(p3.x, p3.y, p3.z);		//	point 3

	glEnd();
}

void Shapes::drawPlane(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, GLenum glBeginMode) {
	glBegin(glBeginMode);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(p3.x, p3.y, p3.z);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(p4.x, p4.y, p4.z);
	glEnd();
}

