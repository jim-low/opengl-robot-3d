#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#pragma once
class Gun
{
public:
	float bullet[10];
	bool isShot[10];
	int bulletIndex = 0;
	bool triggerShoot = false;

	void draw();
	void drawGun();
	void drawBullet();
	void shoot();
};