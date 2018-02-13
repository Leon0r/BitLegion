#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class Game {
public:

public:
	Game(std::string windowTitle_, int width, int height);
	virtual ~Game();

	SDL_Window* getWindow() const; // returns a pointer to the SDL window
	SDL_Renderer* getRenderer() const; // returns a pointer to the SDL renderer
	int getWindowWidth() const; // returns the window width
	int getWindowHeight() const; // returns the window height

	void run();//it calls handleInput, update, render, etc.
	void handleEvents();//input of all the gameObjects
	void update();//update all the gameObjects
	void render();//render all the gameObjects

private:
	void initSDL(); // initialize SDL (ttf, mixer, image, create window and renderer, etc)
	void closeSDL(); // close all SDL resources

protected:
	SDL_Window* window_; // the window
	SDL_Renderer* renderer_;  // the renderer

	string windowTitle_; // window title
	int width_; // window width
	int height_; // window height

};

#endif /* SDLGAME_H_ */
