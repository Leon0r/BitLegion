#include "SDLApp.h"
#include "GameStateMachine.h"
#include "Inventory.h"
#include "ObjectList.h"

SDLApp::SDLApp(int w, int h): winWidth(w), winHeight(h)
{
		window = nullptr;
		renderer = nullptr;
		int winX, winY;
		winX = winY = SDL_WINDOWPOS_CENTERED;
		//Inicializaci�n del sistema y renderer
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("First test with SDL", winX, winY, winWidth, winHeight, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		maquinaEstados = new GameStateMachine();

		ObjectList* list = new ObjectList(this); //esto de prueba eh, hay q hacer deletes q no se borra 
		maquinaEstados->pushState(new Inventory(this, list));

}

void SDLApp::handleEvent() {
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT)
			exit = true;
		else
			maquinaEstados->currentState()->handleEvent(event); //invoca el handleEvent del currentState
	}
}

void SDLApp::update() {
	maquinaEstados->currentState()->update();
}

void SDLApp::render() {
	SDL_RenderClear(renderer); 
	maquinaEstados->currentState()->render(); 
	SDL_RenderPresent(renderer);
}

void SDLApp::closeSDL() {
	maquinaEstados->libera(); 
	SDL_DestroyRenderer(renderer); 
	renderer = nullptr; 
	SDL_DestroyWindow(window);
	window = nullptr; SDL_Quit();
}
//---------------------------Gets-------------------------
SDL_Window* SDLApp::getWindow() const {
	return window;
}

SDL_Renderer* SDLApp::getRenderer() const {
	return renderer;
}

int SDLApp::getWindowWidth() const {
	return winWidth;
}

int SDLApp::getWindowHeight() const {
	return winHeight;
}

GameStateMachine* SDLApp::getStateMachine() {
	return this->maquinaEstados;
}
