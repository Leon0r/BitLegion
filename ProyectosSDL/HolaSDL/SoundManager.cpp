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
	case PLAY_MUSIC: {
		PlayMusic* m = static_cast<PlayMusic*>(msg);
		app->getResources()->getMusic(m->idMusic_)->play();
		break;
	}
	case STOP_MUSIC: {
		StopMusic* m = static_cast<StopMusic*>(msg);
		app->getResources()->getMusic(m->idMusic_)->stop();
		break;
	}
	case PAUSE_MUSIC: {
		PauseMusic* m = static_cast<PauseMusic*>(msg);
		app->getResources()->getMusic(m->idMusic_)->pause();
		break;
	}
	case RESUME_MUSIC: {
		ResumeMusic* m = static_cast<ResumeMusic*>(msg);
		app->getResources()->getMusic(m->idMusic_)->resume();
		break;
	}
	}
}