#pragma once
#include "GameState.h"
#include "GOUnlockeable.h"

class Puzzle: public GameState
{
protected:
	vector<GOUnlockeable*> unlockeables;
public:
	Puzzle() {};
	Puzzle(SDLApp* app, int id = -4) : GameState(app), id(id) {};
	~Puzzle();

	int id;
	virtual void searchId() {
		if (id != -4) {
			GameState* _previousState = app->getStateMachine()->currentState(); //nos devuelve siempre el anterior antes de pushearlo
			list<GameObject*>::iterator aux;
			for (aux = _previousState->getStage()->begin(); aux != _previousState->getStage()->end(); aux++) {
				if ((*aux)->_id == id) unlockeables.push_back(static_cast<GOUnlockeable*>((*aux)));
			}
		}
	};

	virtual void unlockObjects() {
		vector<GOUnlockeable*>::iterator it;
		for (it = unlockeables.begin(); it != unlockeables.end(); it++) (*it)->secondAct();
	};

	virtual void win() {
		app->getStateMachine()->popState(false);
		unlockObjects();
		app->getStateMachine()->currentState()->SetZBuffer();
		send(&Mensaje(WinPuzzle));
	}
};

