#include <Math.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Shapes.h"
#include "Body.h"
#include "Hand.h"
#include "Legs.h"
#include "Head.h"
#include "Fire.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")
#pragma once
class Robot
{
public:
	Body* body = new Body();
	Hand* hand = new Hand();
	Legs* legs = new Legs();
	Head* head = new Head();
	Fire* fire = new Fire();

	void draw();
};

