#pragma once
#include <D3D10.h>
#include <D3DX10.h>

class CPass{
public:
	CPass(ID3D10EffectPass* pass, ID3D10Device* device);
	virtual ~CPass(void);

	void apply(void);
	void activateInputLayout(void);
protected:
	ID3D10EffectPass* pass;
	ID3D10InputLayout* inputLayout;
	ID3D10Device* device;
protected:
	void generateInputLayout(void);

};