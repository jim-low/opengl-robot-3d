#include "Body.h"
#include "Vector3.h"

void Body::drawBody() {
	//  Upper
	glPushMatrix();
	glColor3f(1, 1, 1);
	Shapes::drawCuboid(Vector3(-0.27, 0.2, 0), 0.54, 0.2, 0.2, GL_QUADS);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	Shapes::drawCuboid(Vector3(-0.23, -0.1, 0), 0.46, 0.3, 0.2, GL_QUADS);
	glPopMatrix();
}

void Body::drawFrontBody() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	Shapes::drawCuboid(Vector3(-0.2, -0.1, 0), 0.02, 0.1, -0.02, GL_QUADS);
	Shapes::drawCuboid(Vector3(-0.25, 0, 0), 0.07, 0.02, -0.02, GL_QUADS);
	glPushMatrix();
	glTranslatef(0.05, 0.0, 0.0);
	Shapes::drawCuboid(Vector3(-0.2, -0.1, 0), 0.02, 0.15, -0.02, GL_QUADS);
	Shapes::drawCuboid(Vector3(-0.3, 0.05, 0), 0.12, 0.02, -0.02, GL_QUADS);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	Shapes::drawCuboid(Vector3(0.18, -0.1, 0), 0.02, 0.1, -0.02, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.18, 0, 0), 0.07, 0.02, -0.02, GL_QUADS);
	glPushMatrix();
	glTranslatef(-0.05, 0.0, 0.0);
	Shapes::drawCuboid(Vector3(0.18, -0.1, 0), 0.02, 0.15, -0.02, GL_QUADS);
	Shapes::drawCuboid(Vector3(0.18, 0.05, 0), 0.12, 0.02, -0.02, GL_QUADS);
	glPopMatrix();
	glPopMatrix();

	//front
	/*glPushMatrix();
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(Vector3(-0.2, 0.0, -0.1), 0.4, 0.2, 0.1, GL_QUADS);
	glPopMatrix();*/

	/*Vector3* p2 = new Vector3();
	glPushMatrix();
	glTranslatef(0.25, 0.35, 0.0);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p2, -0.1, -0.1, -0.01, GL_QUADS);
	glPopMatrix();
	Vector3* p3 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.25, 0.05, 0.0);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p3, 0.5, 0.2, -0.01, GL_QUADS);
	glPopMatrix();
	Vector3* p4 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.25, 0.05, 0.2);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p4, 0.5, 0.3, 0.01, GL_QUADS);
	glPopMatrix();
	Vector3* p5 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.20, 0.05, 0.0);
	glColor3f(0, 1, 1);
	Shapes::drawCuboid(*p5, 0.4, -0.2, -0.01, GL_QUADS);
	glPopMatrix();
	Vector3* p6 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.20, 0.05, 0.2);
	glColor3f(0, 1, 1);
	Shapes::drawCuboid(*p6, 0.4, -0.2, 0.01, GL_QUADS);
	glPopMatrix();
	Vector3* p7 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.25, 0.05, 0.2);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p7, -0.01, 0.3, -0.2, GL_QUADS);
	glPopMatrix();
	Vector3* p8 = new Vector3();
	glPushMatrix();
	glTranslatef(0.25, 0.05, 0.2);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p8, 0.01, 0.3, -0.2, GL_QUADS);
	glPopMatrix();
	Vector3* p9 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.25, 0.35, 0);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p9, 0.1, 0.01, 0.2, GL_QUADS);
	glPopMatrix();
	Vector3* p10 = new Vector3();
	glPushMatrix();
	glTranslatef(0.25, 0.35, 0);
	glColor3f(0, 0, 1);
	Shapes::drawCuboid(*p10, -0.1, 0.01, 0.2, GL_QUADS);
	glPopMatrix();*/
}

void Body::drawBackBody() {
	glPushMatrix();
	glTranslatef(0, 0.17, 0.2);
	Shapes::drawSphere(0.1, 30, 30, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	Shapes::drawCuboid(Vector3(-0.23, 0.05, 0.22), 0.46, 0.02, -0.02, GL_QUADS);
	glPushMatrix();
	glTranslatef(0, -0.05, 0.0);
	Shapes::drawCuboid(Vector3(-0.23, 0.05, 0.22), 0.46, 0.02, -0.02, GL_QUADS);
	glPopMatrix();
	glPopMatrix();
}

void Body::drawLeftBody() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	Shapes::drawCuboid(Vector3(-0.25, 0.05, 0.22), 0.02, 0.02, -0.23, GL_QUADS);
	glPushMatrix();
	glTranslatef(0, -0.05, 0.0);
	Shapes::drawCuboid(Vector3(-0.25, 0.05, 0.22), 0.02, 0.02, -0.23, GL_QUADS);
	glPopMatrix();
	glPopMatrix();
}

void Body::drawRightBody() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	Shapes::drawCuboid(Vector3(0.23, 0.05, 0.22), 0.02, 0.02, -0.23, GL_QUADS);
	glPushMatrix();
	glTranslatef(0, -0.05, 0.0);
	Shapes::drawCuboid(Vector3(0.23, 0.05, 0.22), 0.02, 0.02, -0.23, GL_QUADS);
	glPopMatrix();
	glPopMatrix();
}

void Body::drawArmor() {
	glPushMatrix();
	glTranslatef(0.0, 0.17, -0.05);
	glColor3f(0, 0, 0);
	Shapes::drawCylinder(0.1, 0.1, 0.2, 30, 30, GLU_FILL);
	glPushMatrix();
	glTranslatef(0, 0, 0.1);
	glColor3f(1, 1, 1);
	Shapes::drawSphere(0.099, 30, 30, GLU_FILL);
	glPopMatrix();
	glPopMatrix();
}

void Body::connectLeg() {
	glPushMatrix();
	glColor3f(1, 0, 0);
	Shapes::drawCuboid(Vector3(-0.23, -0.12, 0.0), 0.46, 0.02, 0.2, GL_QUADS);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 0);
	Shapes::drawCuboid(Vector3(-0.02, -0.17, 0.0), 0.04, 0.05, 0.2, GL_QUADS);
	glPopMatrix();
}

void Body::draw() {
	drawBody();
	drawFrontBody();
	drawLeftBody();
	drawRightBody();
	drawBackBody();
	drawArmor();
	connectLeg();
}

/*void Body::drawBody() {

	//  Upper
	Vector3* p3 = new Vector3();
	glPushMatrix();
	glTranslatef(-0.2, 0.2, 0);
	glColor3f(1, 0.9, 0.9);
	Shapes::drawCuboid(*p3, 0.4, 0.2, -0.09, GL_QUADS);
	glPopMatrix();

	// Lower
	// Front
	glBegin(GL_POLYGON);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(-0.2, 0.2, -0.09);
	glVertex3f(0.2, 0.2, -0.09);
	glVertex3f(0.15, -0.1, -0.09);
	glVertex3f(-0.15, -0.1, -0.09);
	glEnd();

	// Back
	glBegin(GL_POLYGON);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(-0.2, 0.2, 0);
	glVertex3f(0.2, 0.2, 0);
	glVertex3f(0.15, -0.1, 0);
	glVertex3f(-0.15, -0.1, 0);
	glEnd();
	
	// Left face
	glBegin(GL_POLYGON);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(-0.2, 0.2, -0.09);
	glVertex3f(-0.2, 0.2, 0);
	glVertex3f(-0.15, -0.1, 0);
	glVertex3f(-0.15, -0.1, -0.09);
	glEnd();

	// Right face
	glBegin(GL_POLYGON);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(0.2, 0.2, -0.09);
	glVertex3f(0.2, 0.2, 0);
	glVertex3f(0.15, -0.1, 0);
	glVertex3f(0.15, -0.1, -0.09);
	glEnd();

	// Top face
	glBegin(GL_POLYGON);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(-0.2, 0.2, -0.09);
	glVertex3f(-0.2, 0.2, 0);
	glVertex3f(0.2, 0.2, 0);
	glVertex3f(0.2, 0.2, -0.09);
	glEnd();

	// Bottom face
	glBegin(GL_POLYGON);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(-0.15, -0.1, -0.09);
	glVertex3f(-0.15, -0.1, 0);
	glVertex3f(0.15, -0.1, 0);
	glVertex3f(0.15, -0.1, -0.09);
	glEnd();

}*/

//void Body::drawFrontArmor() {
//
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.2, 0.4, -0.1);
//	glVertex3f(-0.1, 0.4, -0.1);
//	glVertex3f(-0.05, 0.3, -0.1);
//	glVertex3f(-0.05, 0.15, -0.1);
//	glVertex3f(-0.15, 0.2, -0.1);
//	glVertex3f(-0.2, 0.2, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.05, 0.3, -0.1);
//	glVertex3f(0.05, 0.3, -0.1);
//	glVertex3f(0.05, 0.15, -0.1);
//	glVertex3f(-0.05, 0.15, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.05, 0.3, -0.1);
//	glVertex3f(0.1, 0.4, -0.1);
//	glVertex3f(0.2, 0.4, -0.1);
//	glVertex3f(0.2, 0.2, -0.1);
//	glVertex3f(0.15, 0.2, -0.1);
//	glVertex3f(0.05, 0.15, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.18, 0.1, -0.1);
//	glVertex3f(-0.15, 0.1, -0.1);
//	glVertex3f(-0.15, 0.06, -0.1);
//	glVertex3f(-0.171, 0.06, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.15, 0.1, -0.1);
//	glVertex3f(-0.05, 0.0, -0.1);
//	glVertex3f(-0.09, 0.0, -0.1);
//	glVertex3f(-0.15, 0.06, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.09, 0.0, -0.1);
//	glVertex3f(-0.05, 0.0, -0.1);
//	glVertex3f(-0.05, -0.1, -0.1);
//	glVertex3f(-0.09, -0.1, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.169, 0.04, -0.1);
//	glVertex3f(-0.15, 0.04, -0.1);
//	glVertex3f(-0.15, 0.0, -0.1);
//	glVertex3f(-0.16, 0.0, -0.1);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.15, 0.04, -0.1);
//	glVertex3f(-0.11, 0.0, -0.1);
//	glVertex3f(-0.15, 0.0, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.15, 0.0, -0.1);
//	glVertex3f(-0.11, 0.0, -0.1);
//	glVertex3f(-0.11, -0.1, -0.1);
//	glVertex3f(-0.15, -0.1, -0.1);
//	glEnd();
//	
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.18, 0.1, -0.1);
//	glVertex3f(0.15, 0.1, -0.1);
//	glVertex3f(0.15, 0.06, -0.1);
//	glVertex3f(0.171, 0.06, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.15, 0.1, -0.1);
//	glVertex3f(0.05, 0.0, -0.1);
//	glVertex3f(0.09, 0.0, -0.1);
//	glVertex3f(0.15, 0.06, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.09, 0.0, -0.1);
//	glVertex3f(0.05, 0.0, -0.1);
//	glVertex3f(0.05, -0.1, -0.1);
//	glVertex3f(0.09, -0.1, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.169, 0.04, -0.1);
//	glVertex3f(0.15, 0.04, -0.1);
//	glVertex3f(0.15, 0.0, -0.1);
//	glVertex3f(0.16, 0.0, -0.1);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.15, 0.04, -0.1);
//	glVertex3f(0.11, 0.0, -0.1);
//	glVertex3f(0.15, 0.0, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.15, 0.0, -0.1);
//	glVertex3f(0.11, 0.0, -0.1);
//	glVertex3f(0.11, -0.1, -0.1);
//	glVertex3f(0.15, -0.1, -0.1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.05, 0.3, -0.1);
//	glVertex3f(0.1, 0.4, -0.1);
//	glVertex3f(0.2, 0.4, -0.1);
//	glVertex3f(0.2, 0.2, -0.1);
//	glVertex3f(0.15, 0.2, -0.1);
//	glVertex3f(0.05, 0.15, -0.1);
//	glVertex3f(0.05, 0.15, -0.1);
//	glEnd();
//
//	////front
//	//Vector3* p1 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.25, 0.35, 0.0);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p1, 0.1, -0.1, -0.01, GL_QUADS);
//	//glPopMatrix();
//
//	//Vector3* p2 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(0.25, 0.35, 0.0);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p2, -0.1, -0.1, -0.01, GL_QUADS);
//	//glPopMatrix();
//
//
//
//	//Vector3* p3 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.25, 0.05, 0.0);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p3, 0.5, 0.2, -0.01, GL_QUADS);
//	//glPopMatrix();
//
//	//Vector3* p4 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.25, 0.05, 0.2);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p4, 0.5, 0.3, 0.01, GL_QUADS);
//	//glPopMatrix();
//
//
//
//
//	//Vector3* p5 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.20, 0.05, 0.0);
//	//glColor3f(0, 1, 1);
//	//Shapes::drawCuboid(*p5, 0.4, -0.2, -0.01, GL_QUADS);
//	//glPopMatrix();
//
//
//	//Vector3* p6 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.20, 0.05, 0.2);
//	//glColor3f(0, 1, 1);
//	//Shapes::drawCuboid(*p6, 0.4, -0.2, 0.01, GL_QUADS);
//	//glPopMatrix();
//
//
//
//
//	//Vector3* p7 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.25, 0.05, 0.2);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p7, -0.01, 0.3, -0.2, GL_QUADS);
//	//glPopMatrix();
//
//	//Vector3* p8 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(0.25, 0.05, 0.2);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p8, 0.01, 0.3, -0.2, GL_QUADS);
//	//glPopMatrix();
//
//
//	//Vector3* p9 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(-0.25, 0.35, 0);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p9, 0.1, 0.01, 0.2, GL_QUADS);
//	//glPopMatrix();
//
//	//Vector3* p10 = new Vector3();
//	//glPushMatrix();
//	//glTranslatef(0.25, 0.35, 0);
//	//glColor3f(0, 0, 1);
//	//Shapes::drawCuboid(*p10, -0.1, 0.01, 0.2, GL_QUADS);
//	//glPopMatrix();
//}

//void Body::drawBackArmor() {
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.2, 0.4, 0.01);
//	glVertex3f(-0.1, 0.4, 0.01);
//	glVertex3f(-0.1, 0.2, 0.01);
//	glVertex3f(-0.2, 0.2, 0.01);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.1, 0.3, 0.01);
//	glVertex3f(0.0, 0.2, 0.01);
//	glVertex3f(-0.1, 0.2, 0.01);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.0, 0.35, 0.01);
//	glVertex3f(0.05, 0.3, 0.01);
//	glVertex3f(0.05, 0.25, 0.01);
//	glVertex3f(0.0, 0.2, 0.01);
//	glVertex3f(-0.05, 0.25, 0.01);
//	glVertex3f(-0.05, 0.3, 0.01);
//	glEnd();
//
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.1, 0.3, 0.01);
//	glVertex3f(0.0, 0.2, 0.01);
//	glVertex3f(0.1, 0.2, 0.01);
//	glEnd();
//
//
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.2, 0.4, 0.01);
//	glVertex3f(0.1, 0.4, 0.01);
//	glVertex3f(0.1, 0.2, 0.01);
//	glVertex3f(0.2, 0.2, 0.01);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.2, 0.2, 0.01);
//	glVertex3f(-0.1, 0.2, 0.01);
//	glVertex3f(-0.1, 0.1, 0.01);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.1, 0.2, 0.01);
//	glVertex3f(0.1, 0.2, 0.01);
//	glVertex3f(0.1, 0.1, 0.01);
//	glVertex3f(-0.1, 0.1, 0.01);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.1, 0.2, 0.01);
//	glVertex3f(0.2, 0.2, 0.01);
//	glVertex3f(0.1, 0.1, 0.01);
//	glEnd();
//
//
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.18, 0.1, 0.01);
//	glVertex3f(0.18, 0.1, 0.01);
//	glVertex3f(0.171, 0.06, 0.01);
//	glVertex3f(-0.171, 0.06, 0.01);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.169, 0.04, 0.01);
//	glVertex3f(0.169, 0.04, 0.01);
//	glVertex3f(0.16, 0.0, 0.01);
//	glVertex3f(-0.16, 0.0, 0.01);
//	glEnd();
//}

//void Body::drawLeftArmor() {
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.201, 0.4, -0.1);
//	glVertex3f(-0.201, 0.4, 0.01);
//	glVertex3f(-0.201, 0.2, 0.01);
//	glVertex3f(-0.201, 0.2, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.18, 0.1, -0.1);
//	glVertex3f(-0.18, 0.1, 0.01);
//	glVertex3f(-0.171, 0.06, 0.01);
//	glVertex3f(-0.171, 0.06, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.169, 0.04, -0.1);
//	glVertex3f(-0.169, 0.04, 0.01);
//	glVertex3f(-0.16, 0.0, 0.01);
//	glVertex3f(-0.16, 0.0, -0.1);
//	glEnd();
//}

//void Body::drawRightArmor() {
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.201, 0.4, -0.1);
//	glVertex3f(0.201, 0.4, 0.01);
//	glVertex3f(0.201, 0.2, 0.01);
//	glVertex3f(0.201, 0.2, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0,1, 0);
//	glVertex3f(0.18, 0.1, -0.1);
//	glVertex3f(0.18, 0.1, 0.01);
//	glVertex3f(0.171, 0.06, 0.01);
//	glVertex3f(0.171, 0.06, -0.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.169, 0.04, -0.1);
//	glVertex3f(0.169, 0.04, 0.01);
//	glVertex3f(0.16, 0.0, 0.01);
//	glVertex3f(0.16, 0.0, -0.1);
//	glEnd();
//}



//void Body::draw() {
//	drawFrontArmor();
//	drawBackArmor();
//	drawLeftArmor();
//	drawRightArmor();
//	drawBody();
//	connectLeg(); 
//	
//}