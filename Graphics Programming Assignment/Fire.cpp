#include "Fire.h"

void Fire::draw()
{
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glRotatef(180, 1, 0, 0);
	glColor3f(0.0, 0.0, 1.0);
	Shapes::drawCube(
		Vector3(0.0, 0.0, 0.0),
		Vector3(0.05, 0.0, 0.0),
		Vector3(0.05, 0.0, 0.05),
		Vector3(0.0, 0.0, 0.05),
		Vector3(0.025, 0.1, 0.025),
		Vector3(0.025, 0.1, 0.025),
		Vector3(0.025, 0.1, 0.025),
		Vector3(0.025, 0.1, 0.025),
		GL_LINE_LOOP
	);
	glPopMatrix();
}
