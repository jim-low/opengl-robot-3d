#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#pragma once
class Legs
{
public:
	float ringRot = 0;
	Vector3 fireScale = Vector3(0.5,0.5,0.5);
	float fireScaling = 0.002;

	void draw();
	void drawQuads();
	void drawShin();
	void drawFoot();
	void drawFire();
};

