#include "Robot.h"

void Robot::draw() {
	glPushMatrix();

	glTranslatef(robotMovement.x, robotMovement.y, robotMovement.z);
	glRotatef(robotDirection.y, 0, 1, 0);
	glRotatef(robotDirection.x, 1, 0, 0);
	
	glRotatef(robotDirection.z, 0, 0, 1);
	

	drawRobot();
	glPopMatrix();

	if (spin == 1) {
		hand->isSwordOpen_L = true;
		hand->isSwordOpen_R = true;
		if (hand->uArmRotAngle_R->x < 90) {
			hand->uArmRotAngle_R->x += 0.5;
			hand->uArmRotAngle_L->x -= 0.5;
		}
		if (hand->uArmRotAngle_R->x >= 90) {
			robotDirection.y += 5;
		}
		hand->closeFinger();
	}
	else if(spin == 2){
		hand->isSwordOpen_L = false;
		hand->isSwordOpen_R = false;
		if (hand->uArmRotAngle_R->x > 0) {
			hand->uArmRotAngle_R->x -= 0.5;
			hand->uArmRotAngle_L->x += 0.5;
		}
		hand->openFinger();

		if (hand->uArmRotAngle_R->x <= 0) {
			spin = 0;
		}
	}
}

void Robot::drawRobot() {
	glPushMatrix();
	glTranslatef(0, 0.2, 0);;

	//head
	glPushMatrix();
	glScalef(0.23, 0.23, 0.26);
	glTranslatef(0, 1.4, 0.1);
	glRotatef(180,0,1,0);
	head->draw();
	glPopMatrix();

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