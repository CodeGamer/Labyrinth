#pragma once
#include "Pass.h"

class CTechnique{
public:
	CTechnique(ID3D10EffectTechnique* technique, ID3D10Device* device);
	virtual ~CTechnique(void);

	void drawIndexed(UINT startIndex, UINT numIndices);
	void draw(UINT startVertexIndex, UINT numVertices);
public:
	CPass* getPass(UINT index){
		return passes[index];
	}
	UINT getNumPasses(void){
		return numPasses;
	}
protected:

protected:
	CPass** passes;
	UINT numPasses;
	ID3D10Device* device;
};