#include "GOUnlockeable.h"
#include "PlayState.h"

void GOUnlockeable::act() {
	if (!opened) {
		if (dynamic_cast<MainCharacter*>(dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj())->getCurrentTag() == key) {
			opened = true;
			PlayState* aux = dynamic_cast<PlayState*>(app->getStateMachine()->currentState());
			if (aux != nullptr) {
				MainCharacter* pj = dynamic_cast<MainCharacter*>(aux->getMainPj());
				if (pj != nullptr) {
					pj->getList()->deleteItem(key);
				}
			}
			secondAct();
		}
		else
		{
			cout << "Cthun 2 broken" << endl;
		}
	}
	
}

