#pragma once

#include "Ressources/Resource.h"
#include <windows.h>
#include <commctrl.h>
#include "RenderEngine/Renderer.h"

HINSTANCE hInst;

static HWND treeViewWindow;
static HWND consoleViewWindow;
static HWND mainWindow;
int width;
int height;
int treeViewWidth;
int treeViewHeight;

int consoleViewWidth;
int consoleViewHeight;
int consoleViewX;
int consoleViewY;

int mainViewX;
int mainViewY;
int mainViewWidth;
int mainViewHeight;


Renderer renderer;
