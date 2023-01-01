#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")
#pragma once
class Shapes
{
public:
	static void drawCylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks, GLenum drawStyle);
	static void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum drawStyle);
	static void drawCuboid(Vector3 startPoint, float width, float height, float length, GLenum glBeginMode);
	static void drawCube(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, Vector3 p5, Vector3 p6, Vector3 p7, Vector3 p8, GLenum glBeginMode);
};

