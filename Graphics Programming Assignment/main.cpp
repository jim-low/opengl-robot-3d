#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <cmath>
#include "Body.h"
#include "Hand.h"
#include "Legs.h"
#include "Head.h"
#include "Robot.h"
#include "Gun.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")
#define WINDOW_TITLE "BigASS Robot Simulator"

// Robot obj
Robot* robot = new Robot();

// projection
float objZ = 0.0f, objSpeed = 0.1f;		//	object translate in z-axis
float oNear = -10.0f, oFar = 10.0f;			//	ortho near & far
float pNear = 1.0, pFar = 100.0; // perspective near & far
float ptx = 0.0f, pty = 0.0f, ptz, ptSpeed = 0.1f;	//	translation for projection
float prx = 0.0f, pry = 0.0f, prSpeed = 5;			//	rotation for projection
boolean isOrtho = true;

//lighting and material
float amb[] = { 1.0, 0.6, 0.6 }; //red ambient light source
float dif[] = { 0.0, 0.0, 1.0 }; //red diffuse light source
float posA[] = { 0.0, 0.4, 0.0 }; //ambient light from top 
float posD[] = { 0.0, 0.4, 0.0 }; //diffsue light from right 

float ambM[] = { 0.0, 1.0, 0.0 }; // red ambient material 
float difM[] = { 1.0, 0.0, 0.0 }; // red diffuse material
bool isLightOn = false;				//is light on?

int color = 0;

GLuint texture = 0;  //texture name
BITMAP BMP;				//butmap structure
HBITMAP hBMP = NULL;	//bitmap handler

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		if (wParam == VK_UP) {					
			robot->robotDirection.x += 1;
		}
		else if (wParam == VK_DOWN) {				
			robot->robotDirection.x -= 1;
		}
		if (wParam == VK_LEFT) {
			robot->robotDirection.y += 1;
		}
		if (wParam == VK_RIGHT) {
			robot->robotDirection.y -= 1;
		}
		//else if (wParam == 'A') ptx -= ptSpeed;		//-------------------------
		//else if (wParam == 'D') ptx += ptSpeed;		// projecttion translation
		//else if (wParam == 'S') pty -= ptSpeed;		// (W,A,S,D)
		//else if (wParam == 'W') pty += ptSpeed;		//-------------------------
		else if (wParam == 'I') prx -= prSpeed;		//-------------------------
		else if (wParam == 'K') prx += prSpeed;		// projection rotation
		else if (wParam == 'J') pry -= prSpeed;		// (I,J,K,L)
		else if (wParam == 'L') pry += prSpeed;		//-------------------------

		if (wParam == 'O') {
			isOrtho = true;
		}
		else if (wParam == 'P') {
			isOrtho = false;
		}

		if (wParam == 'A') {
			if (!robot->spin) {
				robot->robotDirection.y = 90;
				robot->robotDirection.x = 350;
			}		
			robot->robotMovement.x -= robot->movementSpeed;
		}

		else if (wParam == 'D') {
			if (!robot->spin) {
				robot->robotDirection.y = -90;
				robot->robotDirection.x = -10;
			}
			robot->robotMovement.x += robot->movementSpeed;
		}

		else if (wParam == 'S') {
			if (!robot->spin) {
				robot->robotDirection.y = 180;
				robot->robotDirection.x = 0;
			}
			robot->robotMovement.z += robot->movementSpeed;
		}

		else if (wParam == 'W') {
			if (!robot->spin) {
				robot->robotDirection.y = 0;
				robot->robotDirection.x = 0;
			}
			robot->robotMovement.z -= robot->movementSpeed;
		}

		else if (wParam == VK_SHIFT) {
			robot->hand->positiveTransform = !robot->hand->positiveTransform;
		}

		else if (wParam == VK_SPACE) {
			robot->robotDirection = Vector3(0, 0, 0);
			robot->robotMovement = Vector3(0, 0, 0);
			robot->hand->positiveTransform = true;
			robot->hand->walkSwing = 1;
			robot->hand->lArmRotAngle_L->setVector(0, 0, 0);
			robot->hand->uArmRotAngle_L->setVector(0, 0, 0);
			robot->hand->palmRotAngle_L->setVector(0, 0, 0);
			robot->hand->lArmRotAngle_R->setVector(0, 0, 0);
			robot->hand->uArmRotAngle_R->setVector(0, 0, 0);
			robot->hand->palmRotAngle_R->setVector(0, 0, 0);
			robot->hand->fingerRot_X = 0;
			robot->hand->thumbRotAngle->setVector(0, 0, 0);
			robot->hand->sword_L = 0;
			robot->hand->sword_R = 0;
			robot->hand->isSwordOpen_L = false;
			robot->hand->isSwordOpen_R = false;
			robot->hand->isHoldingGun = false;
			isLightOn = false;
		}
		// uppwerArm rotatation
		else if (wParam == 'Z') {
			if (robot->hand->uArmRotAngle_L->y < 180 && robot->hand->positiveTransform)
				robot->hand->uArmRotAngle_L->y += robot->hand->uArmRot;
			if (robot->hand->uArmRotAngle_L->y > -30 && !robot->hand->positiveTransform)
				robot->hand->uArmRotAngle_L->y -= robot->hand->uArmRot;
		}
		else if (wParam == 'X') {
			if (robot->hand->uArmRotAngle_R->y < 190 && robot->hand->positiveTransform)
				robot->hand->uArmRotAngle_R->y += robot->hand->uArmRot;
			if (robot->hand->uArmRotAngle_R->y > -30 && !robot->hand->positiveTransform)
				robot->hand->uArmRotAngle_R->y -= robot->hand->uArmRot;
		}
		else if (wParam == 'C') {
			if (robot->hand->lArmRotAngle_L->y < 90 && robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_L->y += robot->hand->lArmRot;
			if (robot->hand->lArmRotAngle_L->y > 0 && !robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_L->y -= robot->hand->lArmRot;
		}
		else if (wParam == 'V') {
			if (robot->hand->lArmRotAngle_R->y < 90 && robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_R->y += robot->hand->lArmRot;
			if (robot->hand->lArmRotAngle_R->y > 0 && !robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_R->y -= robot->hand->lArmRot;
		}
		else if (wParam == 'B') {
			if (robot->hand->lArmRotAngle_L->z < 90 && robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_L->z += robot->hand->palmRot;
			if (robot->hand->lArmRotAngle_L->z > -90 && !robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_L->z -= robot->hand->palmRot;
		}
		else if (wParam == 'N') {
			if (robot->hand->lArmRotAngle_R->z < 90 && robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_R->z += robot->hand->palmRot;
			if (robot->hand->lArmRotAngle_R->z > -90 && !robot->hand->positiveTransform)
				robot->hand->lArmRotAngle_R->z -= robot->hand->palmRot;
		}
		else if (wParam == 'E') {
			robot->hand->uArmRotAngle_L->y = 0;
			robot->hand->uArmRotAngle_R->y = 0;
			robot->hand->lArmRotAngle_L->z = 0;
			robot->hand->lArmRotAngle_R->z = 0;
			if (robot->hand->uArmRotAngle_R->x < 90) {
				robot->hand->uArmRotAngle_R->x += robot->hand->uArmRot * robot->hand->walkSwing;
			}
			if (robot->hand->uArmRotAngle_L->x >-90) {
				robot->hand->uArmRotAngle_L->x -= robot->hand->uArmRot * robot->hand->walkSwing;
			}
			if (robot->hand->uArmRotAngle_R->x <= 0) {
				robot->hand->walkSwing = 1;
			}
			if (robot->hand->uArmRotAngle_R->x >= 60) {
				robot->hand->walkSwing = -1;
			}
			robot->robotMovement.y += robot->movementSpeed;
		}
		else if (wParam == 'Q') {
			if (!robot->spin) {
				robot->hand->uArmRotAngle_L->y = 180;
				robot->hand->uArmRotAngle_R->y = 180;
				robot->hand->lArmRotAngle_L->z = -90;
				robot->hand->lArmRotAngle_R->z = -90;
			}			
			robot->robotMovement.y -= robot->movementSpeed;
			robot->legs->fireScale = Vector3();
		}
		else if (wParam == 0x31) {
			robot->hand->isSwordOpen_L = !robot->hand->isSwordOpen_L;
		}
		else if (wParam == 0x32) {
			robot->hand->isSwordOpen_R = !robot->hand->isSwordOpen_R;
		}
		else if (wParam == 0x33) {
			robot->hand->isHoldingGun = !robot->hand->isHoldingGun;
			if (robot->hand->isHoldingGun)
				robot->hand->closeFinger();
			else
				robot->hand->openFinger();
		}

		// finger rotate X
		else if (wParam == 'M' && !robot->hand->isHoldingGun) {
			if (robot->hand->fingerRot_X < 50 && robot->hand->positiveTransform) {
				robot->hand->fingerRot_X += robot->hand->fingerRot;
				if (robot->hand->fingerZpos > -0.09) {
					robot->hand->fingerZpos -= 0.001;
				}
			}

			if (robot->hand->fingerRot_X > 0 && !robot->hand->positiveTransform)
			{
				robot->hand->fingerRot_X -= robot->hand->fingerRot;
				if (robot->hand->fingerZpos < -0.03) {
					robot->hand->fingerZpos += 0.001;
				}
			}

			if (robot->hand->thumbRotAngle->x < 90 && robot->hand->positiveTransform)
			{
				robot->hand->thumbRotAngle->x += robot->hand->thumbRot;
			}
			if (robot->hand->thumbRotAngle->x > 0 && !robot->hand->positiveTransform)
			{
				robot->hand->thumbRotAngle->x -= robot->hand->thumbRot;
			}

			if (robot->hand->thumbRotAngle->y < 30 && robot->hand->positiveTransform && robot->hand->thumbRotAngle->x > 60)
			{
				robot->hand->thumbRotAngle->y += robot->hand->thumbRot;
			}
			if (robot->hand->thumbRotAngle->y > 0 && !robot->hand->positiveTransform)
			{
				robot->hand->thumbRotAngle->y -= robot->hand->thumbRot;
			}

			if (robot->hand->thumbRotAngle->z < 45 && robot->hand->positiveTransform && robot->hand->thumbRotAngle->x > 45)
			{
				robot->hand->thumbRotAngle->z += robot->hand->thumbRot;
			}
			if (robot->hand->thumbRotAngle->z > 0 && !robot->hand->positiveTransform)
			{
				robot->hand->thumbRotAngle->z -= robot->hand->thumbRot;
			}
		}
		else if (wParam == 'R') {
			isLightOn = !isLightOn;
		}
		else if (wParam == 0x34)
		{
			glEnable(GL_LIGHT0);
			glDisable(GL_LIGHT1);
		}
		else if (wParam == 0x35)
		{
			glEnable(GL_LIGHT1);
			glDisable(GL_LIGHT0);
		}
		else if (wParam == 0x36)
		{
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHT1);
		}
		else if (wParam == 'T')
		{
			if(robot->head->headRotAngle->y > -20)
				robot->head->headRotAngle->y -= robot->head->headRot;
		}
		else if (wParam == 'G')
		{
			if (robot->head->headRotAngle->y < 10)
				robot->head->headRotAngle->y += robot->head->headRot;
		}
		else if (wParam == 'F')
		{
			if (robot->head->headRotAngle->x < 30)
				robot->head->headRotAngle->x += robot->head->headRot;
		}
		else if (wParam == 'H')
		{
			if (robot->head->headRotAngle->x > -30)
				robot->head->headRotAngle->x -= robot->head->headRot;
		}

		else if (wParam == 'Y')
		{
			robot->spin = 1;
		}
		else if (wParam == 'U')
		{
			robot->spin = 2;
		}
		else if (wParam == 0x30)
		{
			robot->hand->gun->triggerShoot = true;
		}
		else if (wParam == 0x37)
		{
			ptz += ptSpeed;
		}
		else if (wParam == 0x38)
		{
			ptz -= ptSpeed;
		}

		else if(wParam == VK_CONTROL) {
		color++;
			switch (color) {
			case 0:
				robot->color.setVector(0, 0, 0);
				break;
			case 1:
				robot->color.setVector(0, 0, 1);
				break;

			default:
				break;
			}
		}	

		color++;

		break;


	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 8;
	pfd.cDepthBits = 8;
	pfd.cStencilBits = 8;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	int n = ChoosePixelFormat(hdc, &pfd);

	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void projection() {
	glMatrixMode(GL_PROJECTION);	//refer to the projection matrix
	glLoadIdentity();				//reset the projections matrix

	if (isOrtho)
	{
		glOrtho(1.0, 1.0, 1.0, 1.0, oNear, oFar);
	}
	else
	{
		gluPerspective(20, 1, pNear, pFar);
		glFrustum(-10.0, 10.0, -10.0, 10.0, pNear, pFar);
	}

	glTranslatef(ptx, pty, ptz);	//translate in x and y for projection
	glRotatef(pry, 0, 1, 0);		//rotate in y
	glRotatef(prx, 1, 0, 0);		//rotate in x
}


void lighting()
{
	if (isLightOn) {
		glEnable(GL_LIGHTING);
	}
	else {
		glDisable(GL_LIGHTING);
	}


	//light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_POSITION, posA);
	glEnable(GL_LIGHT0);

	//light 1
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT1, GL_POSITION, posD);
	glEnable(GL_LIGHT1);
}

GLuint loadTexture(LPCSTR imgName) {

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), imgName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	DeleteObject(hBMP);
	return texture;
}

void background() {
	loadTexture("Sky1.bmp");
	glColor3f(1, 1, 1);
	Shapes::drawPlane(Vector3(-1.1, 1.1, 0.7), Vector3(1.1, 1.1, 0.7), Vector3(1.1, -1.1, 0.7), Vector3(-1.1, -1.1, 0.7), GL_QUADS);
	glDisable(GL_TEXTURE_2D);
	glDeleteTextures(1, &texture);
}

void display()
{
	projection();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.9, 0.9, 0.1, 0);

	background();

	lighting();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difM);	//diffuse material

	robot->draw();
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, (1920 / 2) - 400, 30, 800, 800, NULL, NULL, wc.hInstance, NULL);

	HDC hdc = GetDC(hWnd);

	initPixelFormat(hdc);

	HGLRC hglrc = wglCreateContext(hdc);

	if (!wglMakeCurrent(hdc, hglrc)) return false;

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);


	return true;
}
