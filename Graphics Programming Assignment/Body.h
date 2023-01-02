#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#pragma once
class Body
{
	// function name;
public:

	void drawBody();
	void connectLeg();
	void drawFrontBody();
	void drawBackBody();
	void drawLeftBody();
	void drawRightBody();
	void drawArmor();
	void draw();
};

