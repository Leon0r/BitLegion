#include "GOConversational.h"
#include "PlayState.h"



GOConversational::GOConversational()
{
}


GOConversational::~GOConversational()
{
	delete convo;
}

void GOConversational::act() {
	if (!inconversation) {
		PlayState* aux = dynamic_cast<PlayState*>(app->getStateMachine()->currentState()); //este dynamic lo veo super necesario en los dialogos automaticos... da problemnas con las transiciones
		if (aux != nullptr) {
			inconversation = true;
			static_cast<PlayState*>(app->getStateMachine()->currentState())->setEnConversacion(true);
			convo->addObserver(app->getStateMachine()->currentState());
			this->addObserver(static_cast<PlayState*>(app->getStateMachine()->currentState())->getMainPj());
			this->send(&Mensaje(Stop));
			app->getStateMachine()->currentState()->getStage()->push_front(convo);
			app->getStateMachine()->currentState()->changeList();
		}
	}

}
