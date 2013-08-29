#pragma once
#include <Windows.h>

class CWindowPaintListener{
public:
	virtual void paint(HDC hDC) = 0;
};

class CWindowKeyListener{
public:
	virtual void keyChanged(unsigned int keyCode, bool pressed) = 0;
	virtual void characterTyped(wchar_t character) = 0;
};

class CWindowMouseListener{
public:
	virtual void mouseButtonChanged(unsigned int buttonNr, int x, int y, bool pressed) = 0;
	virtual void mouseMoved(int x, int y) = 0;
};

class CWindow{
public:
	CWindow(int x, int y, int width, int height, LPCWSTR title,bool fullScreen, DWORD style);

	virtual~CWindow(void);

	LRESULT sendMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	static void UpdateWindows(void);

	void destroyWindow(void);

	void repaint(void);

	void setPosition(int x, int y);

	void setDimensions(int width, int height);

	void setTitle(LPCWSTR title);

	void setFullScreen(bool fullScreen);
public:

bool isAlive(void){
	return alive;
}

bool isMaximized(void){
	return maximized;
}

HWND getHWND(void){
	return hWND;
}

int getX(void){
	return x;
}

int getY(void){
	return y;
}

int getWidth(void){
	return width;
}

int getHeight(void){
	return height;
}

void setPaintListener(CWindowPaintListener* paintListener){
	this->paintListener = paintListener;
}

void setKeyListener(CWindowKeyListener* keyListener){
	this->keyListener = keyListener;
}


void setMouseListener(CWindowMouseListener* mouseListener){
	this->mouseListener = mouseListener;
}

protected:
	
	void registerWindowsClass(HINSTANCE instance);

	bool handlePaintListeners(UINT message, WPARAM wParam, LPARAM lParam);
	bool handleKeyListeners(UINT message, WPARAM wParam, LPARAM lParam);
	bool handleMouseListeners(UINT message, WPARAM wParam, LPARAM lParam);
protected:
	int x,y;
	int width, height;
	LPCWSTR className;
	HWND hWND;
	bool alive;
	bool controlPressed;
	bool fullScreen;
	bool maximized;
protected:
	CWindowPaintListener* paintListener;

	CWindowKeyListener* keyListener;
	
	CWindowMouseListener* mouseListener;
};