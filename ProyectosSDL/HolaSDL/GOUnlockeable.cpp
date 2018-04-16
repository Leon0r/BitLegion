#include "GOUnlockeable.h"
#include "PlayState.h"

void GOUnlockeable::act() {
	if (!opened) {
		if (dynamic_cast<MainCharacter*>(dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj())->getCurrentTag() == key) {
			opened = true;
			PlayState* aux = static_cast<PlayState*>(app->getStateMachine()->currentState());
			if (aux != nullptr) {
				MainCharacter* pj = static_cast<MainCharacter*>(aux->getMainPj());
				if (pj != nullptr) {
					pj->getList()->deleteItem(key);
					pj->setCurrenTag("");
					pj->marcaOut();
					if (pj->getList()->getLength() > 4) {
						pj->getList()->getItem(4)->setWidth(pj->getList()->getItem(4)->getWidth() / pj->getShortcut()->getCoef());
						pj->getList()->getItem(4)->setHeight(pj->getList()->getItem(4)->getHeight() / pj->getShortcut()->getCoef());
					}
					pj->getShortcut()->recorreEInicia();
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

