#include "SoundManager.h"
#include "Messages.h"

SoundManager::SoundManager(SDLApp* game) {
	// TODO Auto-generated constructor stub
	app = game;
}

SoundManager::~SoundManager() {
	// TODO Auto-generated destructor stub
}

void SoundManager::update(Uint32 time) {

	while (!eventQueue.empty()) {
		app->getResources()->getSoundEffect(eventQueue.front().id_)->play(eventQueue.front().num_);
		eventQueue.pop();
	}
}

void SoundManager::receive(Mensaje* msg) {
	switch (msg->id_) {
	case In_Menu:
		
		break;
	case Game_Start:

		break;
	case Button_Press:

		break;
	}
}