#include "Robot.h"

void Robot::draw() {
	head->draw();

	//body
	glPushMatrix();

	glScalef(0.7, 0.8, 0.8);
	glTranslatef(0, -0.1, -0.1);
	body->draw();

	glPopMatrix();


	hand->draw();

	glPushMatrix();
	glScalef(1.5, 1, 1);
	legs->draw();
	glPopMatrix();
}