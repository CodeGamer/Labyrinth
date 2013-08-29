#pragma once
#include "Window.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "RessourceManager.h"

#define WIN32_LEAN_AND_MEAN

class CGameCore{
public:

	void startGameLoop(int screenWidth, int screenHeight, LPCWSTR title, bool fullScreen, bool exclusiveMouse, float halfHorizontalViewAngle, float nearPlane, float farPlane, HWND windowHandle = NULL);
	void stopGameLoop(void);

public:
	CWindow* getMainWindow(void){
		return mainWindow;
	}

	HWND getHWND(void){
		return hWND;
	}

	ID3D10Device* getDevice(void){
		return device;
	}

	CGraphicManager* getGraphic(void){
		return graphicManager;
	}

	void setBackgroundColor(float r, float g, float b){
		direct3DInitializer->setBackgroundColor(r,g,b);
	}

	void setFullScreen(bool fullScreen){
		mainWindow->setFullScreen(fullScreen);
		direct3DInitializer->setFullScreen(fullScreen);
	}

private:
	
	void createObjects(int screenWidth, int screenHeight, LPCWSTR title, bool fullScreen, bool exclusiveMouse, float halfHorizontalViewAngle, float nearPlane, float farPlane);
	void deleteObjects(void);
private:
	CWindow* mainWindow;
	HWND hWND;
	
	CDirect3DInitializer* direct3DInitializer;
	ID3D10Device* device;
	CGraphicManager* graphicManager;
	CRessourceManager* ressourceManager;

	CInputManager* inputManager;

	
	bool gameLoopAktive;
protected:
	virtual void init(CRessourceManager* ressources) = 0;
	virtual void clear(void) = 0;
	virtual void update(CInputManager* input, DWORD passedTime) = 0;
	virtual void render(CGraphicManager* graphic) = 0;
};