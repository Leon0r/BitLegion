#ifndef SRC_SOUNDMANAGER_H_
#define SRC_SOUNDMANAGER_H_

#include "Resources.h"
#include "GameObject.h"
#include "Observer.h"
#include <queue>

/*
*
*/
class SoundManager : public Observer {
public:
	SoundManager() {}
	SoundManager(SDLApp* game);
	virtual ~SoundManager();
	virtual void receive(Mensaje* msg);
	virtual void update();
	void changeMute() { mute = !mute; }
private:
	struct PlayMessage {
		PlayMessage(Resources::SoundEffectId id, int num) : id_(id), num_(num) {};
		Resources::SoundEffectId id_; //id del sonido a reproducir
		int num_;
	};
	queue<PlaySoundE> eventQueue;
	SDLApp* app;
	SoundEffect* actualSoundEffect = nullptr;
	bool mute = false;
};

#endif /* SRC_SOUNDMANAGER_H_ */