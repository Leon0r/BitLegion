#include "GOUnlockeable.h"
#include "MainCharacter.h"
#include "PlayState.h"



GOUnlockeable::GOUnlockeable(SDLApp* game, int x, int y, int w, int h, Texture* texture, string tag): ClickeableGO(game, x, y, w, h, texture),key(tag)
{
}


GOUnlockeable::~GOUnlockeable()
{
}

void GOUnlockeable::act() {
	if (dynamic_cast<MainCharacter*>(dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj())->getCurrentTag() == key)
		secondAct();
	else
	{
		cout << "Cthun to broken" << endl;
	}
}
