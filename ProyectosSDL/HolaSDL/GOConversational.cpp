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

void GOConversational::render(Uint32 time){
	Entity::render(time);
}
void GOConversational::handleInput(Uint32 time, const SDL_Event& event) {
	ClickeableGO::handleInput(time, event);
	/*
	if(inconversation)
		convo->handleInput(time, event);
		*/
}