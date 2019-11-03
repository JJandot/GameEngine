#include "Renderer.h"

void Renderer::SetGLProjection(RECT rect, int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (float)rect.right / (float)rect.bottom, 1.0, 200.0);
}

void Renderer::SetGLView(RECT rect, int width, int height) {
	SetGLProjection(rect, width, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Renderer::InitGL(RECT rect, int width, int height) {

	SetGLView(rect, width, height);

	glCullFace(GL_BACK);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);


	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	GLfloat light_position[] = { 200.0, 200.0, 200.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat mat_ambient[] = { 0.1f, 0.5f, 1.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 1.0f, 1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
}

bool Renderer::Attach(HWND frame) {
	static PIXELFORMATDESCRIPTOR pfd;

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 16;
	pfd.cRedBits = 0;
	pfd.cRedShift = 0;
	pfd.cGreenBits = 0;
	pfd.cGreenShift = 0;
	pfd.cBlueBits = 0;
	pfd.cBlueShift = 0;
	pfd.cAlphaBits = 0;
	pfd.cAlphaShift = 0;
	pfd.cAccumBits = 0;
	pfd.cAccumRedBits = 0;
	pfd.cAccumGreenBits = 0;
	pfd.cAccumBlueBits = 0;
	pfd.cAccumAlphaBits = 0;
	pfd.cDepthBits = 16;
	pfd.cStencilBits = 0;
	pfd.cAuxBuffers = 0;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.bReserved = 0;
	pfd.dwLayerMask = 0;
	pfd.dwVisibleMask = 0;
	pfd.dwDamageMask = 0;

	hdc = GetDC(frame);

	int PixelFormat = ChoosePixelFormat(hdc, &pfd);

	if (!PixelFormat) {
		MessageBox(0, L"Can't Find A Suitable PixelFormat.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (!SetPixelFormat(hdc, PixelFormat, &pfd)) {
		MessageBox(0, L"Can't Set The PixelFormat.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	hrc = wglCreateContext(hdc);

	if (!hrc) {
		MessageBox(0, L"Can't Create A GL Rendering Context.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (!wglMakeCurrent(hdc, hrc)) {
		MessageBox(0, L"Can't activate GLRC.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	return true;
}

void Renderer::Init(RECT rect, int width, int height) {
	InitGL(rect, width, height);
}

void Renderer::Resize(RECT rect, int width, int height) {
	SetGLProjection(rect, width, height);
}

void Renderer::Render() {
	DrawGLScene();
	glFinish();
	SwapBuffers(hdc);
}

void Renderer::DrawGLScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	GLfloat light_position[] = { 200.0, 200.0, 200.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);



	glPushMatrix();



	glTranslatef(0.0, 0.0, -5.0);



	glRotatef(RotateX, 1, 0, 0);

	glRotatef(RotateY, 0, 1, 0);

	glRotatef(RotateZ, 0, 0, 1);



	glBegin(GL_QUADS);

	//Front Face



	glNormal3f(0.0, 0.0, 1.0);

	glVertex3f(-1.0f, -1.0f, 1.0f);

	glVertex3f(1.0f, -1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, 1.0f);



	// Back Face



	glNormal3f(0.0, 0.0, -1.0);

	glVertex3f(-1.0f, -1.0f, -1.0f);

	glVertex3f(-1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);



	// Top Face



	glNormal3f(0.0, 1.0, 0.0);

	glVertex3f(-1.0f, 1.0f, -1.0f);

	glVertex3f(-1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);



	// Bottom Face



	glNormal3f(0.0, -1.0, 0.0);

	glVertex3f(-1.0f, -1.0f, -1.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);

	glVertex3f(1.0f, -1.0f, 1.0f);

	glVertex3f(-1.0f, -1.0f, 1.0f);



	// Right face



	glNormal3f(1.0, 0.0, 0.0);

	glVertex3f(1.0f, -1.0f, -1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, -1.0f, 1.0f);



	// Left Face



	glNormal3f(-1.0, 0.0, 0.0);

	glVertex3f(-1.0f, -1.0f, -1.0f);

	glVertex3f(-1.0f, -1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, -1.0f);

	glEnd();



	glPopMatrix();



	RotateX += 0.1;

	RotateY += -0.2;

	RotateZ += 0.3;
}