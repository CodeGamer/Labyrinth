#include <GameCore.h>

class Game: public CGameCore{
protected:
	void init(CRessourceManager* ressources);
	void clear(void);
	void update(CInputManager* input, DWORD passedTime);
	void render(CGraphicManager* graphic);
};