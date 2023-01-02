#include "Robot.h"

void Robot::draw() {
	glPushMatrix();
	glTranslatef(robotMovement.x, robotMovement.y, robotMovement.z);
	glRotatef(robotDirection.y, 0, 1, 0);
	glRotatef(robotDirection.x, 1, 0, 0);
	
	glRotatef(robotDirection.z, 0, 0, 1);
	

	drawRobot();
	glPopMatrix();
}

void Robot::drawRobot() {
	glPushMatrix();
	glTranslatef(0, 0.2, 0);;

	//head
	head->draw();

	//body
	glPushMatrix();
	glScalef(0.7, 0.7, 1.35);
	glTranslatef(0, -0.1, -0.07);
	body->draw();
	glPopMatrix();

	//hand
	glPushMatrix();
	glScalef(1, 1, 1.5);
	glTranslatef(0, 0, 0.03);
	hand->draw();
	glPopMatrix();

	//leg
	glPushMatrix();
	glScalef(0.575, 0.4, 0.5);
	glTranslatef(0, 0, 0.02);
	legs->draw();
	glPopMatrix();

	glPopMatrix();
}