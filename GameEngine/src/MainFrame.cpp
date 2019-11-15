#include "stdafx.h"

#include "MainFrame.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

LRESULT CALLBACK ProcessMessages(HWND, UINT, WPARAM, LPARAM);


void UpdateSize(HWND frame) {
	RECT rect;
	GetWindowRect(frame, &rect);

	width = rect.right - rect.left;
	height = rect.bottom - rect.top;


	treeViewWidth = width / 5;
	treeViewHeight = height;

	consoleViewWidth = width - treeViewWidth;
	consoleViewHeight = height / 4;
	consoleViewX = treeViewWidth;
	consoleViewY = height - consoleViewHeight;

	mainViewX = treeViewWidth;
	mainViewY = CW_USEDEFAULT;
	mainViewWidth = width - treeViewWidth;
	mainViewHeight = height - consoleViewHeight;
}

int WINAPI WinMain(_In_ HINSTANCE mainInstance, _In_opt_ HINSTANCE previousInstance, _In_ LPSTR commandLine, _In_ int displayMode) {
	HWND mainFrame;
	MSG message;
	WNDCLASS windowClass;

	hInst = mainInstance;

	GameObject *go = sceneGraph.AddGameObject("../DataTest/cube.obj");

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

	UpdateSize(mainFrame);

	treeViewWindow = CreateWindowEx(NULL, WC_TREEVIEW, NULL, WS_CHILD | WS_BORDER | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, treeViewWidth, treeViewHeight, mainFrame, NULL, hInst, NULL);
	consoleViewWindow = CreateWindowEx(WS_EX_RIGHTSCROLLBAR, WC_STATIC, NULL, WS_CHILD | WS_BORDER | WS_VISIBLE, consoleViewX, consoleViewY, consoleViewWidth, consoleViewHeight, mainFrame, NULL, hInst, NULL);
	mainWindow = CreateWindowEx(NULL, WC_STATIC, NULL, WS_CHILD | WS_BORDER | WS_VISIBLE, mainViewX, mainViewY, mainViewWidth, mainViewHeight, mainFrame, NULL, hInst, NULL);


	if (!mainFrame)
		return -1;

	ShowWindow(mainFrame, displayMode);
	UpdateWindow(mainFrame);

	if (renderer.Attach(mainWindow)) {
		RECT rect;
		GetWindowRect(mainWindow, &rect);
		renderer.Init(rect, mainViewWidth, mainViewHeight);
	}
	else
		return -1;

	while (true) {
		while (PeekMessage(&message, NULL, 0, 0, PM_NOREMOVE)) {
			if (GetMessage(&message, NULL, 0, 0)) {
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
				return message.wParam;
		}
		renderer.Render();
	}
}

LRESULT CALLBACK ProcessMessages(HWND mainFrame, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_FICHIER_QUITTER:
			PostMessage(mainFrame, WM_CLOSE, 0, 0);
		}
		break;
	case WM_SIZE:
		UpdateSize(mainFrame);
		MoveWindow(treeViewWindow, 0, 0, treeViewWidth, treeViewHeight, true);
		MoveWindow(consoleViewWindow, consoleViewX, consoleViewY, consoleViewWidth, consoleViewHeight, true);
		MoveWindow(mainWindow, mainViewX, 0, mainViewWidth, mainViewHeight, true);
		break;
	case WM_EXITSIZEMOVE:
		RECT rect;
		GetWindowRect(mainWindow, &rect);
		renderer.Resize(rect, mainViewWidth, mainViewHeight);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(mainFrame, message, wParam, lParam);
	}

	return DefWindowProcW(mainFrame, message, wParam, lParam);
}
