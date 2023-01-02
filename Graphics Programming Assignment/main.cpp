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

// body part objects
Body* body = new Body();
Hand* hand = new Hand();
Legs* legs = new Legs();
Head* head = new Head();
Robot* robot = new Robot();
Gun* gun = new Gun();

// switch mode 1-head, 2-body, 3-hand, 4-leg
int mode = 4;

// projection
float objZ = 0.0f, objSpeed = 0.1f;		//	object translate in z-axis
float oNear = -10.0f, oFar = 10.0f;			//	ortho near & far
float ptx = 0.0f, pty = 0.0f, ptSpeed = 0.1f;	//	translation for projection
float prx = 0.0f, pry = 0.0f, prSpeed = 5;			//	rotation for projection
boolean isOrtho = true;

//lighting and material
float amb[] = { 0.6, 1.0, 0.6 }; //red ambient light source
float dif[] = { 0.6, 1.0, 0.6 }; //red diffuse light source
float posA[] = { 0.0, 0.4, 0.0 }; //ambient light from top 
float posD[] = { 0.0, 0.4, 0.0 }; //diffsue light from right 

float ambM[] = { 0.0, 1.0, 0.0 }; // red ambient material 
float difM[] = { 0.0, 1.0, 0.0 }; // red diffuse material
bool isLightOn = false;				//is light on?

GLuint texture = 0;  //texture name
BITMAP BMP;				//butmap structure
HBITMAP hBMP = NULL;	//bitmap handler
GLuint textureArray[10];

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		if (wParam == VK_UP) {					// move obj up
			if (objZ > oNear) {
				objZ -= objSpeed;
			}
		}
		else if (wParam == VK_DOWN) {				// move obj down
			if (objZ < oFar) {
				objZ += objSpeed;
			}
		}
		else if (wParam == 'A') ptx -= ptSpeed;		//-------------------------
		else if (wParam == 'D') ptx += ptSpeed;		// projecttion translation
		else if (wParam == 'S') pty -= ptSpeed;		// (W,A,S,D)
		else if (wParam == 'W') pty += ptSpeed;		//-------------------------
		else if (wParam == 'I') prx -= prSpeed;		//-------------------------
		else if (wParam == 'K') prx += prSpeed;		// projection rotation
		else if (wParam == 'J') pry -= prSpeed;		// (I,J,K,L)
		else if (wParam == 'L') pry += prSpeed;		//-------------------------
		else if (wParam == 0x31) mode = 1;			// head (wing kian)
		else if (wParam == 0x32) mode = 2;			// body (yu heng)
		else if (wParam == 0x33) mode = 3;			// hand (zi heng)
		else if (wParam == 0x34) mode = 4;			// legs (jim)
		else if (wParam == 0x35) mode = 5;			// complete robot
		else if (wParam == 0x36) mode = 6;
		
		switch (mode) {
			case 1:
				
				break;
			case 2:
				if (wParam == 'L')			//L 
				{
					isLightOn = !isLightOn;
				}
				break;
			case 3:
				if (wParam == VK_SHIFT) {
					hand->positiveTransform = !hand->positiveTransform;
				}
				else if (wParam == VK_SPACE) {
					hand->lArmRotAngle_L = 0;
					hand->uArmRotAngle_L = 0;
					hand->palmRotAngle_L = 0;
					hand->lArmRotAngle_R = 0;
					hand->uArmRotAngle_R = 0;
					hand->palmRotAngle_R = 0;
				}
				// uppwerArm rotatation
				else if (wParam == 'Z') {
					if (hand->uArmRotAngle_L->y < 180 && hand->positiveTransform)
						hand->uArmRotAngle_L->y += hand->uArmRot;
					if (hand->uArmRotAngle_L->y > -30 && !hand->positiveTransform)
						hand->uArmRotAngle_L->y -= hand->uArmRot;
				}
				else if (wParam == 'X') {
					if (hand->uArmRotAngle_R->y < 190 && hand->positiveTransform)
						hand->uArmRotAngle_R->y += hand->uArmRot;
					if (hand->uArmRotAngle_R->y > -30 && !hand->positiveTransform)
						hand->uArmRotAngle_R->y -= hand->uArmRot;
				}
				else if (wParam == 'C') {
					if (hand->lArmRotAngle_L->y < 90 && hand->positiveTransform)
						hand->lArmRotAngle_L->y += hand->lArmRot;
					if (hand->lArmRotAngle_L->y > 0 && !hand->positiveTransform)
						hand->lArmRotAngle_L->y -= hand->lArmRot;
				}
				else if (wParam == 'V') {
					if (hand->lArmRotAngle_R->y < 90 && hand->positiveTransform)
						hand->lArmRotAngle_R->y += hand->lArmRot;
					if (hand->lArmRotAngle_R->y > 0 && !hand->positiveTransform)
						hand->lArmRotAngle_R->y -= hand->lArmRot;
				}
				else if (wParam == 'B') {
					if (hand->lArmRotAngle_L->z < 90 && hand->positiveTransform)
						hand->lArmRotAngle_L->z += hand->palmRot;
					if (hand->lArmRotAngle_L->z > 0 && !hand->positiveTransform)
						hand->lArmRotAngle_L->z -= hand->palmRot;
				}
				else if (wParam == 'N') {
					if (hand->lArmRotAngle_R->z < 90 && hand->positiveTransform)
						hand->lArmRotAngle_R->z += hand->palmRot;
					if (hand->lArmRotAngle_R->z > 0 && !hand->positiveTransform)
						hand->lArmRotAngle_R->z -= hand->palmRot;
				}
				else if (wParam == 'Q') {			
					hand->uArmRotAngle_R->y += hand->uArmRot * hand->walkSwing;
					hand->uArmRotAngle_L->y -= hand->uArmRot * hand->walkSwing;
					if (hand->uArmRotAngle_R->y == -45) {
						hand->walkSwing = 1;
					}
					if (hand->uArmRotAngle_R->y == 45) {
						hand->walkSwing = -1;
					}			
				}
				else if (wParam == 'O') {				
					hand->isSwordOpen_L = !hand->isSwordOpen_L;
				}
				else if (wParam == 'P') {
					hand->isSwordOpen_R = !hand->isSwordOpen_R;
				}

				// finger rotate X
				else if (wParam == 'M') {
					hand->closeFinger();
				}
				break;
			case 4:
				break;
			case 5:
				if (wParam == VK_SHIFT) {
					robot->hand->positiveTransform = !robot->hand->positiveTransform;
				}
				else if (wParam == VK_SPACE) {
					robot->hand->lArmRotAngle_L = 0;
					robot->hand->uArmRotAngle_L = 0;
					robot->hand->palmRotAngle_L = 0;
					robot->hand->lArmRotAngle_R = 0;
					robot->hand->uArmRotAngle_R = 0;
					robot->hand->palmRotAngle_R = 0;
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
					if (robot->hand->lArmRotAngle_L->z > 0 && !robot->hand->positiveTransform)
						robot->hand->lArmRotAngle_L->z -= robot->hand->palmRot;
				}
				else if (wParam == 'N') {
					if (robot->hand->lArmRotAngle_R->z < 90 && robot->hand->positiveTransform)
						robot->hand->lArmRotAngle_R->z += robot->hand->palmRot;
					if (robot->hand->lArmRotAngle_R->z > 0 && !robot->hand->positiveTransform)
						robot->hand->lArmRotAngle_R->z -= robot->hand->palmRot;
				}
				else if (wParam == 'Q') {
					robot->hand->uArmRotAngle_R->y += robot->hand->uArmRot * robot->hand->walkSwing;
					robot->hand->uArmRotAngle_L->y -= robot->hand->uArmRot * robot->hand->walkSwing;
					if (robot->hand->uArmRotAngle_R->y == -45) {
						robot->hand->walkSwing = 1;
					}
					if (robot->hand->uArmRotAngle_R->y == 45) {
						robot->hand->walkSwing = -1;
					}
				}
				else if (wParam == 'O') {
					robot->hand->isSwordOpen_L = !robot->hand->isSwordOpen_L;
				}
				else if (wParam == 'P') {
					robot->hand->isSwordOpen_R = !robot->hand->isSwordOpen_R;
				}

				// finger rotate X
				else if (wParam == 'M') {
					robot->hand->closeFinger();
				}
				break;
			case 6:
				break;
			default:
				break;
		}
		break;
	default:
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

	glTranslatef(ptx, pty, 0);	//translate in x and y for projection
	glRotatef(pry, 0, 1, 0);		//rotate in y
	glRotatef(prx, 1, 0, 0);		//rotate in x
}

void lighting() {

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

GLuint loadtexture(LPCSTR filename) {
	GLuint texture = 0;

	//step 3
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL),
		filename, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
		LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP); //create object in memory to make handler refer to this object

	//step 4
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth,
		BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	DeleteObject(hBMP);

	return texture;
}

void display()
{
	//projection();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, objZ);		//zoom in and out
	glRotatef(pry, 0, 1, 0);		//rotate in y
	glRotatef(prx, 1, 0, 0);		//rotate in x

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.9, 0.9, 0.1, 0);
	lighting();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difM);	//diffuse material


	switch (mode) {
	case 1:
		head->draw();
		break;
	case 2:
		body->draw();
		break;
	case 3:		
		hand->draw();		
		break;
	case 4:
		legs->draw();
		break;
	case 5:
		robot->draw();
		break;
	case 6:
		gun->draw();
		break;
	default:
		break;
	}
	
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
