// project.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "project.h"
#include <queue>
#include "DDALine.h"
#include "ParametricLine.h"
#include "MidpointLine.h"
#include "PointClip.h"
#include "LineClip.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
Drawing *draw;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void fillBackground(HWND hWnd, COLORREF c);
void save(HWND hWnd);
void load(HWND hWnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int x;
	static int y;
	static bool l = false;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case ID_FILE_SAVE:
				save(hWnd);
				break;
			case ID_FILE_LOAD:
				load(hWnd);
				break;
			case ID_FILL_BACKGROUND:
				fillBackground(hWnd, RGB(200, 0, 0));
				break;
			case ID_CLIPPING_LINE:
				if (draw != NULL) {
					delete(draw);
				}
				draw = new LineClip();
				break;
			case ID_CLIPPING_POINT:
				if (draw != NULL) {
					delete(draw);
				}
				draw = new PointClip();
				break;
            case ID_LINE_DDA:
				if (draw != NULL) {
					delete(draw);
				}
				draw = new DDALine();
                break;
			case ID_LINE_PARAMETRIC:
				if (draw != NULL) {
					delete(draw);
				}
				draw = new ParametricLine();
				break;
			case ID_LINE_MIDPOINT:
				if (draw != NULL) {
					delete(draw);
				}
				draw = new MidpointLine();
				break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_LBUTTONDOWN:
		{
			if(draw != NULL)
				draw->addInput(Vector2d(LOWORD(lParam), HIWORD(lParam)));
		}
		break;
    case WM_PAINT:
        {
			HDC hdc = GetDC(hWnd);
			if (draw != NULL) {
				if (draw->validInput()) {
					draw->draw(hdc, RGB(100, 100, 100));
					
				}
				
			}
				
			ReleaseDC(hWnd, hdc);
		}
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void fillBackground(HWND hWnd, COLORREF c)
{
	RECT rect;
	GetWindowRect(hWnd, &rect);
	HDC hdc = GetDC(hWnd);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			SetPixel(hdc, i, j, c);
		}
	}
	ReleaseDC(hWnd, hdc);


}

void save(HWND hWnd) {
	RECT rect;
	GetWindowRect(hWnd, &rect);
	HDC hdc = GetDC(hWnd);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	ofstream file("draw.image");
	file.write((char*)&width,sizeof(int));
	file.write((char*)&height, sizeof(int));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			COLORREF color = GetPixel(hdc, i, j);
			file.write((char*)&color, sizeof(COLORREF));
		}
	}
	file.close();
}

void load(HWND hWnd) {
	HDC hdc = GetDC(hWnd);
	ifstream file("draw.image");
	int width;
	int height;
	file.read((char*)&width, sizeof(int));
	file.read((char*)&height, sizeof(int));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			COLORREF color;
			file.read((char*)&color, sizeof(COLORREF));
			SetPixel(hdc, i, j,color);
		}
	}
	file.close();
}