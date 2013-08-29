#pragma once
#include <D3D10.h>

class CDirect3DInitializer{
public:
	CDirect3DInitializer(UINT width, UINT height, bool fullScreen, HWND hWND);
	virtual ~CDirect3DInitializer(void);

	void setBackgroundColor(float r, float g, float b);

	void beginSzene(void);
	void endSzene(void);

	void setFullScreen(bool fullScreen);

public:
	ID3D10Device* getDevice(void){
		return device;
	}
	
protected:
	void createDeviceAndSwapChain(UINT width, UINT height, bool fullScreen, HWND hWND);
	void createBackBuffer(void);
	void createDepthStencilBuffer(UINT width, UINT height);
	void createViewport(UINT width, UINT height);

	void findRefreshRate(UINT width, UINT height, DXGI_RATIONAL* target);
protected:
	ID3D10Device* device;
	IDXGISwapChain* swapChain;

	ID3D10RenderTargetView* backBufferView;

	ID3D10DepthStencilView* depthStencilView;

	D3D10_VIEWPORT viewPort;

	float backgroundColor[4];
	bool fullScreen;
};