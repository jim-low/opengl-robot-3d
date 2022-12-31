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

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")
#define WINDOW_TITLE "BigASS Robot Simulator"

// body part objects
Body* body = new Body();
Hand* hand = new Hand();
Legs* legs = new Legs();
Head* head = new Head();

// switch mode 1-head, 2-body, 3-hand, 4-leg
int mode = 4;

// projection
float objZ = 0.0f, objSpeed = 0.1f;		//	object translate in z-axis
float oNear = -10.0f, oFar = 10.0f;			//	ortho near & far
float ptx = 0.0f, pty = 0.0f, ptSpeed = 0.1f;	//	translation for projection
float prx = 0.0f, pry = 0.0f, prSpeed = 5;			//	rotation for projection

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
		
		switch (mode) {
			case 1:
				
				break;
			case 2:
				break;
			case 3:
				if (wParam == VK_SHIFT) {
					hand->positiveTransform = !hand->positiveTransform;
				}
				else if (wParam == VK_SPACE) {
					hand->lArmRot_X = 0;
					hand->lArmRot_Y = 0;
					hand->lArmRot_Z = 0;
					hand->uArmRot_X = 0;
					hand->uArmRot_Y = 0;
					hand->uArmRot_Z = 0;
				}
				// lowerArm rotate X
				else if (wParam == 'Z') {
					if (hand->lArmRot_X < 90 && hand->positiveTransform)
						hand->lArmRot_X += hand->lArmRot;
					if (hand->lArmRot_X > 0 && !hand->positiveTransform)
						hand->lArmRot_X -= hand->lArmRot;
				}
				// lowerArm rotate Y
				else if (wParam == 'X') {
					if (hand->lArmRot_Y < 90 && hand->positiveTransform)
						hand->lArmRot_Y += hand->lArmRot;
					if (hand->lArmRot_Y > 0 && !hand->positiveTransform)
						hand->lArmRot_Y -= hand->lArmRot;
				}
				// lowerArm rotate Z
				else if (wParam == 'C') {
					if (hand->lArmRot_Z < 90 && hand->positiveTransform)
						hand->lArmRot_Z += hand->lArmRot;
					if (hand->lArmRot_Z > 0 && !hand->positiveTransform)
						hand->lArmRot_Z -= hand->lArmRot;
				}
				// upperArm rotate X
				else if (wParam == 'V') {
					if (hand->uArmRot_X < 90 && hand->positiveTransform)
						hand->uArmRot_X += hand->uArmRot;
					if (hand->uArmRot_X > 0 && !hand->positiveTransform)
						hand->uArmRot_X -= hand->uArmRot;
				}
				// upperArm rotate Y
				else if (wParam == 'B') {
					if (hand->uArmRot_Y < 90 && hand->positiveTransform)
						hand->uArmRot_Y += hand->uArmRot;
					if (hand->uArmRot_Y > 0 && !hand->positiveTransform)
						hand->uArmRot_Y -= hand->uArmRot;
				}
				// upperArm rotate Z
				else if (wParam == 'N') {
					if (hand->uArmRot_Z < 90 && hand->positiveTransform)
						hand->uArmRot_Z += hand->uArmRot;
					if (hand->uArmRot_Z > 0 && !hand->positiveTransform)
						hand->uArmRot_Z -= hand->uArmRot;
				}
				break;
			case 4:
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
