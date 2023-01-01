#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#pragma once
class Hand
{
public:

	bool positiveTransform = true;
	float uArmRot_X = 0, uArmRot_Y = 0, uArmRot_Z = 0, uArmRot = 5;	// upper arm rotaion
	float lArmRot_X = 0, lArmRot_Y = 0, lArmRot_Z = 0, lArmRot = 5;	// lower arm rotaion

	void drawUpperArm();
	void drawLowerArm();
	void drawPalm();
	void drawThumb();
	void draw();
};