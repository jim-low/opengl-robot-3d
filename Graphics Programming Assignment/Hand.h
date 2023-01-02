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
	int walkSwing = 1;
	float uArmRotAngle_L = 0, uArmRotAngle_R = 0, uArmRot = 5;	// upper arm rotaion
	float lArmRotAngle_L = 0, lArmRotAngle_R = 0, lArmRot = 5;	// lower arm rotaion
	float palmRotAngle_L = 0, palmRotAngle_R = 0, palmRot = 5;	// palm rotaion
	float fingerRot_X = 0, fingerRot = 1;
	float fingerZpos = -0.05;
	float thumbRot_X = 0, thumbRot_Y = 0, thumbRot_Z = 0, thumbRot = 1.5;
	float sword_L = 0, sword_R = 0;
	bool isSwordOpen_L = false, isSwordOpen_R = false;
	
	float swordControl(bool isOpen, float swordLength);
	void drawSwordPart(bool isOpen, float swordLength);
	void drawUpperArm(float uArmRotAngle, float lArmRotAngle, float palmRotAngle, bool isOpen, float swordLength);
	void drawLowerArm(float lArmRotAngle, float palmRotAngle, bool isOpen, float swordLength);
	void drawPalm(float palmRotAngle);
	void drawThumb();
	void drawIndexFinger();
	void drawMiddleFinger();
	void drawRingFinger();
	void drawPinkyFinger();
	void draw();

	void closeFinger();
};

