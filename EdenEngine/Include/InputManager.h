#pragma once
#include <dinput.h>

class CInputManager{
public:
	CInputManager(HWND hWND,bool exclusiveMouse);
	virtual ~CInputManager(void);

	void update(void);

	bool isKeyPressed(int keyNr, bool initialyPressedOnly = false);

	bool isMousePressed(int keyNr,bool initialyPressedOnly = false);

public:

	float getMouseDX(void){
		return (float)mouseState.lX;
	}
	float getMouseDY(void){
		return (float)mouseState.lY;
	}
	float getDMouseWheel(void){
		return (float)mouseState.lZ;
	}
	
protected:
	void initializeDevices(HWND hWND,bool exclusiveMouse);
protected:
	IDirectInputDevice8* keyBoard;
	IDirectInputDevice8* mouse;
	IDirectInput8* input;
	bool keyStates[256];
	bool keyInitialyPressed[256];
	bool mouseButtonInitialyPressed[8];
	DIMOUSESTATE2 mouseState;
};