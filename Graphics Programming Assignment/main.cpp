#include <Windows.h>
#include <gl/GL.h>
#include <cmath>
#include "Body.h"
#include "Hand.h"
#include "Legs.h"
#include "Head.h"

#define WINDOW_TITLE "BigASS Robot Simulator"

// body part objects
Body* body = new Body();
Hand* hand = new Hand();
Legs* legs = new Legs();
Head* head = new Head();

// switch mode 1-head, 2-body, 3- hand, 4-leg
int mode = 0;

// projection
bool isOrtho = false;					//	projection view type

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == 1) {

		}
		else if (wParam == 2) {					

		}
		else if (wParam == 3) {						
			if (wParam == VK_UP) {					// move obj up
				if (isOrtho) {
					if (objZ > oNear) {
						objZ -= objSpeed;
					}
				}
				else {
					if (objZ > pNear) {
						objZ -= objSpeed;
					}
				}
			}
			else if (wParam == VK_DOWN) {				// move obj down
				if (isOrtho) {
					if (objZ < hand->oFar) {
						objZ += objSpeed;
					}
				}
				else {
					if (objZ < pFar) {
						objZ += objSpeed;
					}
				}
			}
			else if (wParam == VK_SHIFT) {
				positiveTransform = !positiveTransform;
			}
			else if (wParam == VK_SPACE) {
				lArmRot_X = 0;
				lArmRot_Y = 0;
				lArmRot_Z = 0;
				uArmRot_X = 0;
				uArmRot_Y = 0;
				uArmRot_Z = 0;
			}
			else if (wParam == 'A') ptx -= ptSpeed;		//-------------------------
			else if (wParam == 'D') ptx += ptSpeed;		// projecttion translation
			else if (wParam == 'S') pty -= ptSpeed;		// (W,A,S,D)
			else if (wParam == 'W') pty += ptSpeed;		//-------------------------
			else if (wParam == 'I') prx -= prSpeed;		//-------------------------
			else if (wParam == 'K') prx += prSpeed;		// projection rotation
			else if (wParam == 'J') pry -= prSpeed;		// (I,J,K,L)
			else if (wParam == 'L') pry += prSpeed;		//-------------------------

			// lowerArm rotate X
			else if (wParam == 'Z') {
				if (lArmRot_X < 90 && positiveTransform)
					lArmRot_X += lArmRot;
				if (lArmRot_X > 0 && !positiveTransform)
					lArmRot_X -= lArmRot;
			}
			// lowerArm rotate Y
			else if (wParam == 'X') {
				if (lArmRot_Y < 90 && positiveTransform)
					lArmRot_Y += lArmRot;
				if (lArmRot_Y > 0 && !positiveTransform)
					lArmRot_Y -= lArmRot;
			}
			// lowerArm rotate Z
			else if (wParam == 'C') {
				if (lArmRot_Z < 90 && positiveTransform)
					lArmRot_Z += lArmRot;
				if (lArmRot_Z > 0 && !positiveTransform)
					lArmRot_Z -= lArmRot;
			}
			// upperArm rotate X
			else if (wParam == 'V') {
				if (uArmRot_X < 90 && positiveTransform)
					uArmRot_X += uArmRot;
				if (uArmRot_X > 0 && !positiveTransform)
					uArmRot_X -= uArmRot;
			}
			// upperArm rotate Y
			else if (wParam == 'B') {
				if (uArmRot_Y < 90 && positiveTransform)
					uArmRot_Y += uArmRot;
				if (uArmRot_Y > 0 && !positiveTransform)
					uArmRot_Y -= uArmRot;
			}
			// upperArm rotate Z
			else if (wParam == 'N') {
				if (uArmRot_Z < 90 && positiveTransform)
					uArmRot_Z += uArmRot;
				if (uArmRot_Z > 0 && !positiveTransform)
					uArmRot_Z -= uArmRot;
			}
		}
		else if (wParam == 4) {

		}
		else if (wParam == 'O') isOrtho = true;		// ortho projecttion (O)
		else if (wParam == 'P') isOrtho = false;	// perspective (P)
		
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

void display()
{
	body->draw();
	hand->draw();
	legs->draw();
	head->draw();
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

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, (1920 / 2) - 400, 30, 800, 600, NULL, NULL, wc.hInstance, NULL);

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
