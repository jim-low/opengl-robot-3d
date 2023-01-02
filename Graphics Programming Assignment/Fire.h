#pragma once
#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"

class Fire
{
public:
	float speed = 0.001f;
	float angle = 0;
	Vector3 velocity;

	void draw();
	void calculateTrajectory();
};
