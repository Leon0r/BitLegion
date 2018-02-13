#pragma once
#include <vector>
#include <SDL.h>
using namespace std;

class GameStateMachine;
class SDLApp
{
private:
	GameStateMachine* maquinaEstados;
	//-------------------------------SDL----------------------------

	SDL_Window* window;
	
	SDL_Color color;
	SDL_Event event; //maneja eventos
	SDL_Renderer* renderer;
	int winWidth;
	int winHeight;

	bool exit = false;

public:
	SDLApp(int w, int h);
	~SDLApp() { this->closeSDL(); };
	GameStateMachine* getStateMachine(); //return de la maquina de estados
	void update(); //invoca el update del currentState
	void render(); //invoca el render del currentState
	void handleEvent();
	void run() { while (!this->exit) { handleEvent(); update(); render(); } }
	void closeSDL();
	void setExit(bool b) { exit = b; }
	SDL_Window* SDLApp::getWindow() const;
	SDL_Renderer* SDLApp::getRenderer() const;
	int SDLApp::getWindowWidth() const;
	int SDLApp::getWindowHeight() const;
};

