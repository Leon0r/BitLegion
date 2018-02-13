#include "Game.h"
#include <time.h>

using namespace std;

Game::Game(string windowTitle, int width, int height) :
windowTitle_(windowTitle), width_(width), height_(height) {
	initSDL();
}

Game::~Game() {
	closeSDL();
}

//initialize SDL (ttf, mixer, image, create window and renderer, etc)
//called in the constructor
void Game::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	// SDL Image
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

	// Create window .
	window_ = SDL_CreateWindow(windowTitle_.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN);

	// Create the renderer
	renderer_ = SDL_CreateRenderer(window_, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Clear screen (background color).
	SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);

	// initialize the seed of the random number generator;
	srand(static_cast<unsigned int>(time(NULL)));
}

//close all SDL resources
//called in the destructor
void Game::closeSDL() {

	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;

	SDL_DestroyWindow(window_);
	window_ = nullptr;

	IMG_Quit();

	SDL_Quit();
}

//it calls handleInput, update, render, etc.
void Game::run() {
	handleEvents();
	update();
	render();
	system("pause");
}

//input of all the gameObjects
void Game::handleEvents() {

}

//update all the gameObjects
void Game::update() {

}

//render all the gameObjects
void Game::render() {

}

SDL_Window* Game::getWindow() const {
	return window_;
}

SDL_Renderer* Game::getRenderer() const {
	return renderer_;
}

int Game::getWindowWidth() const {
	return width_;
}

int Game::getWindowHeight() const {
	return height_;
}

