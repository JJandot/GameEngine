#include "stdafx.h"
#include <windows.h>
#include <commctrl.h>
#include <tchar.h>
#include "WindowsProject1.h"

LRESULT CALLBACK procedureFenetrePrincipale(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInst;

int WinMain(HINSTANCE cetteInstance, HINSTANCE precedenteInstance,
	LPSTR lignesDeCommande, int modeDAffichage)
{
	HWND fenetrePrincipale;
	MSG message;
	WNDCLASS classeFenetre;

	hInst = cetteInstance;

	classeFenetre.style = 0;
	classeFenetre.lpfnWndProc = procedureFenetrePrincipale;
	classeFenetre.cbClsExtra = 0;
	classeFenetre.cbWndExtra = 0;
	classeFenetre.hInstance = NULL;
	classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
	classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
	classeFenetre.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	classeFenetre.lpszClassName = _T("classeF");

	// On prévoit quand même le cas où ça échoue
	if (!RegisterClass(&classeFenetre)) return FALSE;

	fenetrePrincipale = CreateWindow(_T("classeF"), _T("Game Engine"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1024, 576,
		NULL, NULL, cetteInstance, NULL);
	if (!fenetrePrincipale) return FALSE;

	ShowWindow(fenetrePrincipale, modeDAffichage);
	UpdateWindow(fenetrePrincipale);


	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND treeViewWindow;
	static HWND consoleViewWindow;
	int width;
	int height;


	RECT rect;
	GetWindowRect(fenetrePrincipale, &rect);

	width = rect.right - rect.left;
	height = rect.bottom - rect.top;


	int treeViewWidth = width / 5;
	int treeViewHeight = height;

	int consoleViewWidth = width - treeViewWidth;
	int consoleViewHeight = height / 4;
	int consoleViewX = treeViewWidth;
	int consoleViewY = height - consoleViewHeight;

	switch (message)
	{
	case WM_CREATE:
		treeViewWindow = CreateWindowEx(NULL, WC_TREEVIEW, TEXT("Tree View"), WS_CHILD | WS_BORDER | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, treeViewWidth, treeViewHeight, fenetrePrincipale, NULL, hInst, NULL);
		consoleViewWindow = CreateWindowEx(WS_EX_RIGHTSCROLLBAR, WC_STATIC, NULL, WS_CHILD | WS_BORDER | WS_VISIBLE, consoleViewX, consoleViewY, consoleViewWidth, consoleViewHeight, fenetrePrincipale, NULL, hInst, NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
			case ID_FICHIER_QUITTER:
				PostMessage(fenetrePrincipale, WM_CLOSE, 0, 0);
		}
		break;
	case WM_SIZE:
		MoveWindow(treeViewWindow, 0, 0, treeViewWidth, treeViewHeight, true);
		MoveWindow(consoleViewWindow, consoleViewX, consoleViewY, consoleViewWidth, consoleViewHeight, true);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(fenetrePrincipale, message, wParam, lParam);
	}

	return DefWindowProcW(fenetrePrincipale, message, wParam, lParam);
}
