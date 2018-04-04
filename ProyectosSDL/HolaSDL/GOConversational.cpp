#include "GOConversational.h"
#include "PlayState.h"



GOConversational::GOConversational()
{
}


GOConversational::~GOConversational()
{
}

void GOConversational::act() {
	if (!inconversation) {
		inconversation = true;
		static_cast<PlayState*>(app->getStateMachine()->currentState())->setEnConversacion(true);
		app->getStateMachine()->currentState()->getStage()->push_front(convo);
	}

}
