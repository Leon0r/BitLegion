#include "GOUnlockeable.h"
#include "PlayState.h"

void GOUnlockeable::act() {
	if (!opened) {
		if ( dynamic_cast<MainCharacter*>(dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj())->getCurrentTag() == key) {
			opened = true;
			secondAct();
		}
		else
		{
			cout << "Cthun 2 broken" << endl;
		}
	}
	
}

