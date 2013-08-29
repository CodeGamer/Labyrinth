#include "LinkedList.h"
#include <d3dx10.h>
#pragma once
class CRessourceManager{
public:
	CRessourceManager(ID3D10Device* device);
	virtual ~CRessourceManager(void);
	ID3D10ShaderResourceView* loadTexture(LPCWSTR fileName);
	ID3D10ShaderResourceView* loadTextureIfNecessary(LPCWSTR fileName);
protected:
	struct TEXTURE_DATA{
		LPCWSTR fileName;
		ID3D10ShaderResourceView* texture;
	};
protected:
	CLinkedList<TEXTURE_DATA>* textureList;
	ID3D10Device* device;
};