#include "Legs.h"

void Legs::draw() {
	drawBelt();

	drawQuads();

	// do some rotation
	drawShin();

	// some more rotation
	drawFoot();
}

void Legs::drawBelt()
{
}

void Legs::drawQuads()
{
	Shapes::drawCube(Vector3(0, 0, 0), 0.3, 0.3, 0.4);
}

void Legs::drawShin()
{
}

void Legs::drawFoot()
{

}
