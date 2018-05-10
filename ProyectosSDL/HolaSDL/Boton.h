#pragma once
#include "checkML.h"
#include "Entity.h"
#include "GameState.h"
#include "ComponenteClickeable.h"
#include "FeedbackCursorInputComponent.h"

class Boton :
	public Entity, ComponenteClickeable
{
private:
	string nombre;
	int f = -1, c = -1;
	typedef void CallBackOnClickStateFC(GameState* actualState, int f, int c);
	CallBackOnClickStateFC* stateFC;
	GameState* actualState;
	function<void()> fun;

	FeedbackCursorInputComponent feed;

public:
	Boton() : fun(nullptr), stateFC(nullptr), actualState(nullptr), Entity(nullptr), nombre("") {}; //constructora vacia
	virtual ~Boton();

	Boton(SDLApp* app, CallBackOnClickStateFC* stateFC, GameState* actualState, string nombre, int fil, int col); //constructora2

	Boton(SDLApp* app, string nombre, function<void()> f);  //constructora que recibe cualquier funcion (de tipo void)

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	
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
};

