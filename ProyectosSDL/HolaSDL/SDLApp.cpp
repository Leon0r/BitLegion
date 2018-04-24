#include "SDLApp.h"
#include "PlayState.h"
#include "Inventory.h"
#include "LightsOut.h"
#include "MainMenuState.h"

SDLApp::SDLApp(int w, int h): winWidth(w), winHeight(h)
{
		srand(time(NULL)); //inicia la seed del random para que genere distintos numeros siempre que compilemos
		window = nullptr;
		renderer = nullptr;
		int winX, winY;
		winX = winY = SDL_WINDOWPOS_CENTERED;
		//Inicialización del sistema y renderer
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Moonace", winX, winY, winWidth, winHeight, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		TTF_Init();
		// SDL Mixer (Music, Sound, etc)
		Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

		initResources();
		soundManager = new SoundManager(this);
		maquinaEstados = new GameStateMachine();
		maquinaEstados->pushState(new MainMenuState(this, soundManager));
		//dynamic_cast<PlayState*>(maquinaEstados->currentState())->getScenes()[0]->enterScene();
}

void SDLApp::handleEvent() {
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT)
			exit = true;
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				exit = true;
			}
		}
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
	delete maquinaEstados; maquinaEstados = nullptr;
	delete resources; resources = nullptr;
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