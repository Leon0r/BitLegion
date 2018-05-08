#pragma once
#include "Resources.h"

// Archivo solo con el enum de mensajes posibles entre observer/observable
enum Messages {
	Ch_Left,
	Ch_Right,
	Ch_TakeObj,
	StopRight,
	StopLeft,
	Moving,
	MouseStop,
	MouseMoving,
	CambioEscena,
	LuzInvertida,
	WinPuzzle,
	ChangeScene,
	MensajeVacio,
	DialogoAcabado,
	Stop,
	SetZBufferPlayState,
	AbreInventario,
	Pausa,
	CambioEstado,
	PLAY_MUSIC,
	STOP_MUSIC,
	PAUSE_MUSIC,
	RESUME_MUSIC,
	PLAY_SOUNDEFFECT,
	STOP_ALL_SOUNDEFFECT
};

struct Mensaje{
	Mensaje(Messages id) : id_(id) {};
	Mensaje(): id_(MensajeVacio){};
	Messages id_;
};

struct MensajePosicionMatriz: Mensaje //mensaje que devuelve la posicion de la matriz (puzzles)
{
	MensajePosicionMatriz(Messages id, std::pair<const int, const int> pos) : Mensaje(id), pos_(pos) {}
	std::pair<const int, const int> pos_;
};

struct MensajeCambioEscenaDialogos : Mensaje 
{
	MensajeCambioEscenaDialogos(Messages id, int numScene) : Mensaje(id), numScene_(numScene) {}
	int numScene_;
};

struct PlayMusic : Mensaje {
	PlayMusic(Resources::MusicId idMusic) :
		Mensaje(PLAY_MUSIC), idMusic_(idMusic) {
	}
	Resources::MusicId idMusic_;
};

struct StopMusic : Mensaje {
	StopMusic(Resources::MusicId idMusic) :
		Mensaje(STOP_MUSIC), idMusic_(idMusic) {
	}
	Resources::MusicId idMusic_;
};

struct PauseMusic : Mensaje {
	PauseMusic(Resources::MusicId idMusic) :
		Mensaje(PAUSE_MUSIC), idMusic_(idMusic) {
	}
	Resources::MusicId idMusic_;
};

struct ResumeMusic : Mensaje {
	ResumeMusic(Resources::MusicId idMusic) :
		Mensaje(RESUME_MUSIC), idMusic_(idMusic) {
	}
	Resources::MusicId idMusic_;
};

struct PlaySoundE : Mensaje {
	PlaySoundE(Resources::SoundEffectId idSoundE, int numReps) :
		Mensaje(PLAY_SOUNDEFFECT), idSoundE_(idSoundE), numReps_(numReps) {
	}
	Resources::SoundEffectId idSoundE_;
	int numReps_;
};

