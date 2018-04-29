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

		PlayState* aux = dynamic_cast<PlayState*>(app->getStateMachine()->currentState()); 

		if (aux != nullptr) {
			inconversation = true;
			aux->setEnConversacion(true);
			convo->addObserver(app->getStateMachine()->currentState());
			this->addObserver(aux->getMainPj());
			this->send(&Mensaje(Stop));
			app->getStateMachine()->currentState()->getStage()->push_front(convo);
			app->getStateMachine()->currentState()->changeList();
		}
	}

}
