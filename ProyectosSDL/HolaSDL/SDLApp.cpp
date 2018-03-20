#include "SDLApp.h"
#include "PlayState.h"
#include "Inventory.h"
#include "puzzle1State.h"

SDLApp::SDLApp(int w, int h): winWidth(w), winHeight(h)
{
		window = nullptr;
		renderer = nullptr;
		int winX, winY;
		winX = winY = SDL_WINDOWPOS_CENTERED;
		//Inicializaci�n del sistema y renderer
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Moonace", winX, winY, winWidth, winHeight, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		TTF_Init();
		initResources();
		maquinaEstados = new GameStateMachine();
		GameState* aux = new Puzzle1State(this, nullptr);
		maquinaEstados->pushState(aux);
		//dynamic_cast<PlayState*>(maquinaEstados->currentState())->getScenes()[0]->enterScene();
}

void SDLApp::handleEvent() {
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
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
