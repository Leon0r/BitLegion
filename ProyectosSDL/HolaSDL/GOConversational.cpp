#include "GOConversational.h"



GOConversational::GOConversational()
{
}


GOConversational::~GOConversational()
{
}

void GOConversational::act() {
	if (!inconversation) {
		inconversation = true;
	}

}

void GOConversational::render(Uint32 time){
	Entity::render(time);
	if (inconversation)
		convo->render(time);


}
void GOConversational::handleInput(Uint32 time, const SDL_Event& event) {
	ClickeableGO::handleInput(time, event);
	if(inconversation)
		convo->handleInput(time, event);
}