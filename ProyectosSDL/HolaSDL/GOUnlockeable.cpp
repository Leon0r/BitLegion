#include "GOUnlockeable.h"
#include "PlayState.h"

void GOUnlockeable::act() {
	if (dynamic_cast<MainCharacter*>(dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj())->getCurrentTag() == key)
		secondAct();
	else
	{
		cout << "Cthun to broken" << endl;
	}
}

