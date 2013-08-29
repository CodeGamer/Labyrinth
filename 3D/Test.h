#pragma once

#include <QMainWindow>
#include "ui_Test.h"
#include <GameCore.h>

class Test : public QMainWindow, public Ui::Test, public CGameCore
{
	Q_OBJECT
	
	public:
		Test(QMainWindow *parent = 0);
		~Test();

		HWND getHandle();

		void init(CRessourceManager* ressources);
		void clear(void);
		void update(CInputManager* input, DWORD passedTime);
		void render(CGraphicManager* graphic);
	private:
};