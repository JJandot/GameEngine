#pragma once
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>

class Renderer {
private:
	float RotateX, RotateY, RotateZ;
	HDC hdc;
	HGLRC hrc;
	void InitGL(RECT rect, int width, int height);
	void SetGLProjection(RECT rect, int width, int height);
	void SetGLView(RECT rect, int width, int height);
	void DrawGLScene();
public:
	bool Attach(HWND frame);
	void Init(RECT rect, int width, int height);
	void Resize(RECT rect, int width, int height);
	void Render();
};

