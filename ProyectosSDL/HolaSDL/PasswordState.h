#pragma once
#include "Puzzle.h"
#include "GOTimer.h"

class PasswordState :
	public Puzzle
{
private:
	bool checking = false;
	const string password_; //contrasenya a averiguar
	string userPass_;
	bool checkPassword();
	void resetPassword();
	void reset();
	Font* f;
	unsigned int i = 0;
	ImageRenderer img;
	Entity* fondo = nullptr;
	GOTimer* timerFail;
	GOTimer* timeWin;

public:
	PasswordState();
	PasswordState(SDLApp* app, string password = "hanzomain", int id = -4, int txt = -1);
	virtual ~PasswordState();
	virtual void handleEvent(SDL_Event &e);
	virtual void render();

};

