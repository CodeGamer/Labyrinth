#include "Texture.h"

class CRenderTargetTexture{
public:
CRenderTargetTexture(ID3D10Device* device, UINT width, UINT height);
virtual ~CRenderTargetTexture(void);


CTexture* createAcessableRenderTargetCopy(bool dynamic);

void startRenderToTexture(float backgroundR, float backgroundG, float backgroundB, float backgroundA);

void stopRenderToTexture(void);

public:



ID3D10ShaderResourceView* getShaderResourceView(void){
	return resourceView;
}

ID3D10DepthStencilView* getDepthStencilView(void){
	return depthStencilView;
}

UINT getWidth(void){
	return viewPort.Width;
}

UINT getHeight(void){
	return viewPort.Height;
}


protected:
D3D10_VIEWPORT viewPort;
ID3D10ShaderResourceView* resourceView;
ID3D10RenderTargetView* renderTargetView;
ID3D10DepthStencilView* depthStencilView;
ID3D10Device* device;

ID3D10RenderTargetView* oldBackBufferView;
ID3D10DepthStencilView* oldDepthStencilView;
D3D10_VIEWPORT oldViewPort;
protected:
	void createRenderTarget(void);
	void createDepthStencilBuffer(void);
};