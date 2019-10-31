#include "stdafx.h"
#include <windows.h>
#include <commctrl.h>
#include <GL/GL.h>
#include "MainFrame.h"

#pragma comment (lib, "opengl32.lib")

//install-Package nupengl.core in Tools > Nuget package manager > console

LRESULT CALLBACK ProcessMessages(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInst;

int WINAPI WinMain(_In_ HINSTANCE mainInstance, _In_opt_ HINSTANCE previousInstance, _In_ LPSTR commandLine, _In_ int displayMode) {
	HWND mainFrame;
	MSG message;
	WNDCLASS windowClass;

	hInst = mainInstance;

	windowClass.style = 0;
	windowClass.lpfnWndProc = ProcessMessages;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = NULL;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
	windowClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	windowClass.lpszClassName = _T("classeF");

	if (!RegisterClass(&windowClass))
		return -1;

	mainFrame = CreateWindow(_T("classeF"), _T("Game Engine"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 576, NULL, NULL, mainInstance, NULL);

	if (!mainFrame)
		return -1;

	ShowWindow(mainFrame, displayMode);
	UpdateWindow(mainFrame);


	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

LRESULT CALLBACK ProcessMessages(HWND mainFrame, UINT message, WPARAM wParam, LPARAM lParam) {
	static HWND treeViewWindow;
	static HWND consoleViewWindow;
	static HWND mainWindow;
	int width;
	int height;


	RECT rect;
	GetWindowRect(mainFrame, &rect);

	width = rect.right - rect.left;
	height = rect.bottom - rect.top;


	int treeViewWidth = width / 5;
	int treeViewHeight = height;

	int consoleViewWidth = width - treeViewWidth;
	int consoleViewHeight = height / 4;
	int consoleViewX = treeViewWidth;
	int consoleViewY = height - consoleViewHeight;

	int mainViewX = treeViewWidth;
	int mainViewY = CW_USEDEFAULT;
	int mainViewWidth = width - treeViewWidth;
	int mainWiewHeight = height - consoleViewHeight;

	switch (message) {
	case WM_CREATE:
		treeViewWindow = CreateWindowEx(NULL, WC_TREEVIEW, TEXT("Tree View"), WS_CHILD | WS_BORDER | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, treeViewWidth, treeViewHeight, mainFrame, NULL, hInst, NULL);
		consoleViewWindow = CreateWindowEx(WS_EX_RIGHTSCROLLBAR, WC_STATIC, NULL, WS_CHILD | WS_BORDER | WS_VISIBLE, consoleViewX, consoleViewY, consoleViewWidth, consoleViewHeight, mainFrame, NULL, hInst, NULL);
		mainWindow = CreateWindowEx(NULL, WC_STATIC, TEXT("Main Frame"), WS_CHILD | WS_BORDER | WS_VISIBLE, mainViewX, mainViewY, mainViewWidth, mainWiewHeight, mainFrame, NULL, hInst, NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_FICHIER_QUITTER:
			PostMessage(mainFrame, WM_CLOSE, 0, 0);
		}
		break;
	case WM_SIZE:
		MoveWindow(treeViewWindow, 0, 0, treeViewWidth, treeViewHeight, true);
		MoveWindow(consoleViewWindow, consoleViewX, consoleViewY, consoleViewWidth, consoleViewHeight, true);
		MoveWindow(mainWindow, mainViewX, 0, mainViewWidth, mainWiewHeight, true);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(mainFrame, message, wParam, lParam);
	}

	return DefWindowProcW(mainFrame, message, wParam, lParam);
}
