#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#pragma once
class Head
{
public:
	Vector3* headRotAngle = new Vector3();
	float headRot = 0.5;

	void draw();
	void drawFrontPlane();
	void drawFrontTopPlane();
	void drawFrontBottomPlane();
	void drawBackHalf();
	void drawNeck();
	void drawAntenna1();
	void drawAntenna2();
};

