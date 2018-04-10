#include "SoundManager.h"
#include "Messages.h"

SoundManager::SoundManager(SDLApp* game) {
	// TODO Auto-generated constructor stub

}

SoundManager::~SoundManager() {
	// TODO Auto-generated destructor stub
}

void SoundManager::update(Uint32 time) {

	while (!eventQueue.empty()) {
		game_->getResources()->getSoundEffect(eventQueue.front().id_)->play(eventQueue.front().num_);
		eventQueue.pop();
	}
}

void SoundManager::receive(Mensaje* msg) {
	switch (msg->id_) {
	case FIGHTER_SHOOT:
	}
}