#pragma once
#include "checkML.h"
#include "GameObject.h"
#include "Font.h"
#include "Texture.h"
#include <list>
#include "Observable.h"
#include "Observer.h"

const int FRAME_RATE = 25; // A menor tiempo de espera entre frames, mayor la velocidad del bucle

class Entity;
class Cursor;
class GameState:
	public Observable, public Observer
{
private:
	static Cursor* cursor;

protected:
	bool listhasChanged = false;
	uint32_t startTime, frameTime; // Control del tiempo de repeticion del bucle

	list <GameObject*> stage; //lista de objetos del estados
	list<GameObject*>::iterator it;
	SDLApp* app; //puntero a SDLApp
	
	void handleCursor(SDL_Event &e);
	void renderCursor();
	//metodos para hacer mas sencillas las instrucciones de sonido
	void playMusic(Resources::MusicId id) {
		PlayMusic msg = { id };
		send(&msg);
	}
	void stopMusic(Resources::MusicId id) {
		StopMusic msg = { id };
		send(&msg);
	}
	void pauseMusic(Resources::MusicId id) {
		PauseMusic msg = { id };
		send(&msg);
	}
	void resumeMusic(Resources::MusicId id) {
		ResumeMusic msg = { id };
		send(&msg);
	}
	//este cuenta con el numero de repeticiones que quieres para el soundEffect, por defecto a 0
	void playSoundEffect(Resources::SoundEffectId id, int numReps = 0) {
		if (numReps != 0)numReps--;//esto es porque siempre se repite una vez mas de la que le pones (i dunno why)
		PlaySoundE msg = { id, numReps };
		send(&msg);
	}
	void stopAllSoundEffect() {
		Mensaje msg = { STOP_ALL_SOUNDEFFECT };
		send(&msg);
	}
public:
	virtual void render(); //manda a los objetos del estado render, el 0 es por el tiempo que no sé porq lo tenemos
	virtual void update(); //manda a los objetos del estado update
	virtual void handleEvent(SDL_Event &e);
	void addEntity(GameObject* entity){ stage.push_back(entity); }
	GameState();
	virtual ~GameState();
	GameState(SDLApp* app);
	void deleteElement(GameObject* o);
	list <GameObject*>* getStage() {return &stage;}
	void changeList() { listhasChanged = true; }
	virtual void receive(Mensaje* msg) {};
	virtual void SetZBuffer() {};

};

