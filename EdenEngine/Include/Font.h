#include "GraphicManager.h"
#include <stdio.h>
#pragma once
class CFont{
public:
	CFont(CGraphicManager* graphic, LPCWSTR fileName);

	CFont(CGraphicManager* graphic, FILE* file);

	virtual ~CFont();

	CTexture* getImage(char character);

	void drawText(float x, float y, LPCWSTR text, float scaleX = 1.0f, float scaleY = 1.0f);

	float computeTextWidth(LPCWSTR text);
public:
	float getTextHeight(){
		return textHeight;
	}

protected:
	void loadFromFile(FILE* file);
protected:
	CTexture** textures;
	float textHeight;
	CGraphicManager* graphic;

};