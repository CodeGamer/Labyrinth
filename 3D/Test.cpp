#include "Test.h"

Test::Test(QMainWindow *parent)
{
	startGameLoop(800,600,L"Hallo",false,false,1.0f,1.0f,1000.0f,getHandle());
}

Test::~Test()
{

}

HWND Test::getHandle()
{
	return (HWND)winId();
}

void Test::init(CRessourceManager* ressources)
{

}

void Test::clear(void)
{

}

void Test::update(CInputManager* input, DWORD passedTime)
{

}

void Test::render(CGraphicManager* graphic)
{

}