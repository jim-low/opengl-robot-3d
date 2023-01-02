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

void Hand::closeFinger() {
	if (fingerRot_X < 50 && positiveTransform) {
		fingerRot_X += fingerRot;
		if (fingerZpos > -0.09) {
			fingerZpos -= 0.001;
		}
	}
		
	if (fingerRot_X > 0 && !positiveTransform)
	{
		fingerRot_X -= fingerRot;
		if (fingerZpos < -0.03) {
			fingerZpos += 0.001;
		}
	}

	if (thumbRot_X < 90 && positiveTransform)
	{
		thumbRot_X += thumbRot;
	}
	if (thumbRot_X > 0 && !positiveTransform)
	{
		thumbRot_X -= thumbRot;
	}

	if (thumbRot_Y < 30 && positiveTransform && thumbRot_X > 60)
	{
		thumbRot_Y += thumbRot;
	}
	if (thumbRot_Y > 0 && !positiveTransform)
	{
		thumbRot_Y -= thumbRot;
	}

	if (thumbRot_Z < 45 && positiveTransform && thumbRot_X > 45)
	{
		thumbRot_Z += thumbRot;
	}
	if (thumbRot_Z > 0 && !positiveTransform)
	{
		thumbRot_Z -= thumbRot;
	}
}

float Hand::swordControl(bool isOpen, float swordLength) {
	if (isOpen) {
		swordLength -= 1;

	}

	if (!isOpen) {
		swordLength = 0;
	}

	return swordLength;
}

void Hand::drawSwordPart(bool isOpen, float swordLength) {
	
	glPushMatrix();
	
	// lower arm sword holder
	p1->setVector(-0.03, -0.1, 0.1);
	glColor3f(0.5, 0.5, 0.5);
	Shapes::drawCuboid(*p1, 0.06, 0.04, 0.25, GL_QUADS);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.06, 0.04, 0.25, GL_LINE_LOOP);

	// sword
	p1->setVector(-0.028, -0.098, 0.1);
	glColor3f(1, 1, 1);
	swordLength = swordControl(isOpen, swordLength);
	Shapes::drawCuboid(*p1, 0.056, 0.036, swordLength, GL_QUADS);

	glPopMatrix();
}

void Hand::drawPinkyFinger() {
	glPushMatrix();

	// joint 1
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.04f, -0.05f, -0.13f);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	// joint 2
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	//joint 3
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	glPopMatrix();
}

void Hand::drawRingFinger() {
	glPushMatrix();

	// joint 1
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.005f, -0.05f, -0.13f);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	// joint 2
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	//joint 3
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	glPopMatrix();
}

void Hand::drawMiddleFinger() {
	glPushMatrix();

	// joint 1
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.03f, -0.05f, -0.13f);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	// joint 2
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	//joint 3
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	glPopMatrix();
}

void Hand::drawIndexFinger() {
	glPushMatrix();

	// joint 1
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.065f, -0.05f, -0.13f);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	// joint 2
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	//joint 3
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, fingerZpos);
	glRotatef(fingerRot_X, 1, 0, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.09, GL_LINE_LOOP);

	glPopMatrix();
}

void Hand::drawThumb() {
	glPushMatrix();
	
	// joint 1
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.101, -0.0501, -0.05); 
	glRotatef(thumbRot_X, 1, 0, 0);
	glRotatef(thumbRot_Z * -1, 0, 0, 1);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.12, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.12, GL_LINE_LOOP);

	// joint 2
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, -0.12);
	glRotatef(thumbRot_Y * -1, 0, 1, 0);
	//fill
	p1->setVector(0, 0, 0);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.07, GL_QUADS);
	//outline
	p1->setVector(0, 0, 0);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCuboid(*p1, 0.03, 0.075, -0.07, GL_LINE_LOOP);

	glPopMatrix();
}

void Hand::drawPalm(float palmRotAngle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glRotatef(palmRotAngle,0,0,1);
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
	p5->setVector(0.08, 0.025, -0.05);
	p6->setVector(-0.1, 0.025, -0.05);
	p7->setVector(-0.1, -0.05, -0.05);
	p8->setVector(0.08, -0.05, -0.05);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);

	// middle palm
	p7->setVector(-0.07, -0.05, -0.05);
	Shapes::drawCuboid(*p7, 0.15, 0.075, -0.05, GL_QUADS);

	//upper palm
	p1->setVector(0.07f, 0.025f, -0.13f);
	p2->setVector(-0.065f, 0.025f, -0.13f);
	p3->setVector(-0.065f, -0.05f, -0.13f);
	p4->setVector(0.07f, -0.05f, -0.13f);
	p5->setVector(0.08, 0.025, -0.1);
	p6->setVector(-0.07, 0.025, -0.1);
	p7->setVector(-0.07, -0.05, -0.1);
	p8->setVector(0.08, -0.05, -0.1);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);
	
	//design
	p1->setVector(-0.05, -0.05, -0.11);
	p2->setVector(0.055, -0.05, -0.11);
	p3->setVector(0.06, -0.05, -0.09);
	p4->setVector(-0.055, -0.05, -0.09);
	p5->setVector(-0.04, -0.06, -0.09);
	p6->setVector(0.045, -0.06, -0.09);
	p7->setVector(0.045, -0.06, -0.09);
	p8->setVector(-0.04, -0.06, -0.09);
	glColor3f(0.5, 0.5, 0.5);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_LINE_LOOP);

	p1->setVector(-0.055, -0.05, -0.09);
	p2->setVector(0.06, -0.05, -0.09);
	p3->setVector(0.06, -0.05, -0.04);
	p4->setVector(-0.055, -0.05, -0.04);
	p5->setVector(-0.04, -0.06, -0.09);
	p6->setVector(0.045, -0.06, -0.09);
	p7->setVector(0.045, -0.06, -0.04);
	p8->setVector(-0.04, -0.06, -0.04);
	glColor3f(0.5, 0.5, 0.5);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_LINE_LOOP);

	p1->setVector(-0.04, -0.06, -0.04);
	p2->setVector(0.045, -0.06, -0.04);
	p3->setVector(0.045, -0.06, -0.04);
	p4->setVector(-0.04, -0.06, -0.04);
	p5->setVector(-0.055, -0.05, -0.04);
	p6->setVector(0.06, -0.05, -0.04);
	p7->setVector(0.055, -0.05, -0.03);
	p8->setVector(-0.05, -0.05, -0.03);
	glColor3f(0.5, 0.5, 0.5);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);
	glColor3f(0, 0, 0);
	glLineWidth(2);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_LINE_LOOP);

	// Finger
	drawThumb();		// thumb
	drawIndexFinger();	// index
	drawMiddleFinger();	// middle
	drawRingFinger();	// ring
	drawPinkyFinger();	// pinky

	glPopMatrix();
	glPopMatrix();
}

void Hand::drawLowerArm(float lArmRotAngle, float palmRotAngle, bool isOpen, float swordLength) {
	glColor3f(0, 0, 0);
	Shapes::drawSphere(0.1, 30, 30, GLU_FILL); // joint

	//Lower arm
	glPushMatrix();

	glRotatef(lArmRotAngle, 0, 1, 0);		//	rotate lower arm
	
	glTranslatef(0, 0, -0.5);			//	translate according cylinder arm height
	glColor3f(0.5, 0.5, 0.5);
	Shapes::drawCylinder(0.06, 0.1, 0.5, 30, 30, GLU_FILL); // cylinder base arm
	glColor3f(0, 0, 0);
	Shapes::drawCylinder(0.061, 0.101, 0.5, 5, 5, GLU_LINE);

	//design
	glColor3f(0.5,0.5,0.5);
	Shapes::drawCylinder(0.07, 0.07, 0.05, 30, 30, GLU_FILL);
	glColor3f(0, 0, 0);
	Shapes::drawCylinder(0.071, 0.071, 0.05, 5, 5, GLU_LINE);

	p1->setVector(0.065, 0.07, 0.05);
	p2->setVector(0.065, -0.07, 0.05);
	p3->setVector(-0.065, -0.07, 0.05);
	p4->setVector(-0.065, 0.07, 0.05);
	Shapes::drawPlane(*p1, *p2, *p3, *p4, GL_QUADS);

	glPushMatrix();
	p1->setVector(0.065, 0.07, 0.05);
	p2->setVector(0.065, -0.07, 0.05);
	p3->setVector(0.1, -0.1, 0.4);
	p4->setVector(0.1, 0.1, 0.4);
	Shapes::drawPlane(*p1, *p2, *p3, *p4, GL_QUADS);
	glRotatef(90, 0, 0, 1);
	Shapes::drawPlane(*p1, *p2, *p3, *p4, GL_QUADS);
	glRotatef(90, 0, 0, 1);
	Shapes::drawPlane(*p1, *p2, *p3, *p4, GL_QUADS);
	glRotatef(90, 0, 0, 1);
	Shapes::drawPlane(*p1, *p2, *p3, *p4, GL_QUADS);
	glPopMatrix();
	
	drawSwordPart(isOpen, swordLength);
	drawPalm(palmRotAngle);	//draw palm

	glPopMatrix();
}

void Hand::drawUpperArm(float uArmRotAngle, float lArmRotAngle, float palmRotAngle, bool isOpen, float swordLength) {

	Shapes::drawSphere(0.1, 30, 30, GLU_LINE); // joint
	
	//Upper arm
	glPushMatrix();

	//rotate
	glRotatef(uArmRotAngle, 0, 1, 0);		//	rotate upper arm

	//design
	glColor3f(0, 0, 0);
	p1->setVector(0.1, 0.12, -0.1);
	p2->setVector(0.1, -0.15, -0.1);
	p3->setVector(-0.12, -0.15, -0.1);
	p4->setVector(-0.12, 0.12, -0.1);
	p5->setVector(0.1, 0.1, -0.15);
	p6->setVector(0.1, -0.1, -0.15);
	p7->setVector(-0.1, -0.1, -0.15);
	p8->setVector(-0.1, 0.1, -0.15);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);

	p1->setVector(0.1, 0.12, -0.1);
	p2->setVector(0.1, -0.15, -0.1);
	p3->setVector(-0.12, -0.15, -0.1);
	p4->setVector(-0.12, 0.12, -0.1);
	p5->setVector(0.1, 0.12, 0.08);
	p6->setVector(0.1, -0.15, 0.08);
	p7->setVector(-0.12, -0.15, 0.08);
	p8->setVector(-0.12, 0.12, 0.08);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);

	p1->setVector(0.1, 0.12, 0.08);
	p2->setVector(0.1, -0.15, 0.08);
	p3->setVector(-0.12, -0.15, 0.08);
	p4->setVector(-0.12, 0.12, 0.08);
	p5->setVector(0.1, 0.1, 0.12);
	p6->setVector(0.1, -0.1, 0.12);
	p7->setVector(-0.1, -0.1, 0.12);
	p8->setVector(-0.1, 0.1, 0.12);
	Shapes::drawCube(*p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, GL_QUADS);

	glTranslatef(0, 0, -0.4);			//	translate according cylinder arm height
	
	glColor3f(0.5, 0.5, 0.5);
	Shapes::drawCylinder(0.1, 0.1, 0.4, 30, 30, GLU_FILL); // cylinder base arm
	glColor3f(0, 0, 0);
	Shapes::drawCylinder(0.101, 0.101, 0.4, 6, 6, GLU_LINE);

	drawLowerArm(lArmRotAngle, palmRotAngle, isOpen, swordLength);	// draw lower arm
	glPopMatrix();
	
}


void Hand::draw()
{
	glScalef(0.5, 0.5, 0.5);
	
	//drawUpperArm(uArmRotAngle_L, lArmRotAngle_L, palmRotAngle_L, isSwordOpen_L, sword_L);

	/*glScalef(2, 2, 2);
	drawPalm();*/

	/*glScalef(0.5, 0.5, 0.5);
	drawUpperArm();*/

	glPushMatrix();
	glTranslatef(-0.5, 0.5, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	
	drawUpperArm(uArmRotAngle_L, lArmRotAngle_L, palmRotAngle_L, isSwordOpen_L, sword_L);

	glScalef(1, -1, 1);
	glTranslatef(0, -1, 0);
	drawUpperArm(uArmRotAngle_R, lArmRotAngle_R, palmRotAngle_R, isSwordOpen_R, sword_R);
	glPopMatrix();
}
