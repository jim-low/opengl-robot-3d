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
	Vector3* uArmRotAngle_L = new Vector3();
	Vector3* uArmRotAngle_R = new Vector3();
	float uArmRot = 5;	// upper arm rotaion
	Vector3* lArmRotAngle_L = new Vector3();
	Vector3* lArmRotAngle_R = new Vector3();
	float lArmRot = 5;	// lower arm rotaion
	Vector3* palmRotAngle_L = new Vector3();
	Vector3* palmRotAngle_R = new Vector3();
	float palmRot = 5;	// palm rotaion
	float fingerRot_X = 0, fingerRot = 1;
	float fingerZpos = -0.05;
	Vector3* thumbRotAngle = new Vector3();
	float thumbRot = 1.5;
	float sword_L = 0, sword_R = 0;
	bool isSwordOpen_L = false, isSwordOpen_R = false;
	
	void drawSwordPart(float swordLength);
	void drawUpperArm(int hand_LR, Vector3 uArmRotAngle, Vector3 lArmRotAngle, Vector3 palmRotAngle, float swordLength);
	void drawLowerArm(int hand_LR, Vector3 lArmRotAngle, Vector3 palmRotAngle, float swordLength);
	void drawPalm(int hand_LR, Vector3 palmRotAngle);
	void drawThumb();
	void drawIndexFinger();
	void drawMiddleFinger();
	void drawRingFinger();
	void drawPinkyFinger();
	void draw();

	void closeFinger();
};

