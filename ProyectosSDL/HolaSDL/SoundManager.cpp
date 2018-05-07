#include "SoundManager.h"
#include "Messages.h"
#include "SDLApp.h"

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
	case Suena:
		app->getResources()->getMusic(Resources::MainTheme)->play(30);
		break;
	}
}