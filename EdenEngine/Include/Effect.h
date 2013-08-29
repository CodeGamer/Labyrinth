#pragma once
#include "Technique.h"

class CEffect{
public:
	CEffect(LPCWSTR fileName, ID3D10Device* device);
	virtual ~CEffect(void);
public:
	ID3D10EffectVariable* getVariable(LPCSTR name){
		return effect->GetVariableByName(name);
	}
	ID3D10EffectVariable* getVariable(unsigned int index){
		return effect->GetVariableByIndex(index);
	}

	CTechnique* getTechnique(unsigned int index){
		return techniques[index];
	}
protected:
	ID3D10Effect* effect;
	CTechnique** techniques;
	unsigned int numTechniques;
protected:

};