#include "Game.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR info, int setting){
	Game game;

	/*HWND testWindowHaendel;
	game.startGameLoop(1024,768,L"Test",false,false,10.0f,1.0f,1000.0f,testWindowHaendel);*/

	game.startGameLoop(1024,768,L"Test",false,false,10.0f,1.0f,1000.0f);
	return 0;
}


void Game :: init(CRessourceManager* ressources){
	setBackgroundColor(1.0f,0,0);
}

void Game :: clear(void){

}

void Game :: update(CInputManager* input, DWORD passedTime){
	if(input->isKeyPressed(DIK_SPACE))
		setBackgroundColor(CMath::RandomFloat(0,1.0f),CMath::RandomFloat(0,1.0f),CMath::RandomFloat(0,1.0f));
}

void Game :: render(CGraphicManager* graphic){
	
}

