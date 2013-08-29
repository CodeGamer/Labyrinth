#include "GraphicManager.h"
#include "InputManager.h"

class CUIManager{
public:
	CUIManager(ID3D10ShaderResourceView* cursorTexture,int screenWidth, int screenHeight);
	void update(CInputManager* input);
	void draw(CGraphicManager* graphic);

	float getCursorX(void){
		return cursorX;
	}

	float getCursorY(void){
		return cursorY;
	}

protected:
	float cursorX,cursorY;
	float screenWidth, screenHeight;
	
	//Nur Temporär, bis das Zeichenprogramm wieder funktioniert
	float cursorWidth, cursorHeight;

	ID3D10ShaderResourceView* cursorTexture;
protected:

};