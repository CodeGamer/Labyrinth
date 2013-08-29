#include <d3d10.h>
#include <stdio.h>
#pragma once
class CTexture{
public:
	
	CTexture(ID3D10Device* device, unsigned int width, unsigned int height, DXGI_FORMAT format, unsigned int pixelSize, bool dynamic, void* pInitialData = NULL);

	CTexture(FILE* file, ID3D10Device* device, bool dynamic);

	CTexture(LPWSTR fileName, ID3D10Device* device, bool dynamic);

	virtual ~CTexture(void);

	unsigned int getWidth(void){
		return width;
	}
	unsigned int getHeight(void){
		return height;
	}

	unsigned int getPitch(void){
		return pitch;
	}


	ID3D10ShaderResourceView* getShaderResourceView(void){
		return shaderResourceView;
	}

	void setPixel(int x, int y, void* pPixel);
	void getPixel(int x, int y, void* pTarget);
	
	void setToTexture(CTexture* texture);

	void* getPData(void){
		return pData;
	}

	void fill(void* pFillColor);

	void updateTexture(void);
	void clearTexture(void);

	void saveToFile(LPCWSTR fileName);

	void saveToFile(FILE* file);
protected:
	void createTexture(void);
	void initFromFile(FILE* file, ID3D10Device* device, bool dynamic);
	void init(ID3D10Device* device, unsigned int width, unsigned int height, DXGI_FORMAT format, unsigned int pixelSize, bool dynamic, void* pInitialData);
protected:
unsigned int width,height;
unsigned int pixelSize, dataSize, pitch;
bool dynamic;
DXGI_FORMAT format;
ID3D10Device* device;
void* pData;

ID3D10Texture2D* texture;
ID3D10ShaderResourceView* shaderResourceView;
};