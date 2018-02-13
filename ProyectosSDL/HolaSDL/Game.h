#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"

class Game {
public:

public:
	Game(std::string windowTitle_, int width, int height);
	virtual ~Game();

	SDL_Window* getWindow() const; // returns a pointer to the SDL window
	SDL_Renderer* getRenderer() const; // returns a pointer to the SDL renderer
	int getWindowWidth() const; // returns the window width
	int getWindowHeight() const; // returns the window height

	// abstract methods to be implemented by subclasses
	void run();
	void update();
	void render();
	void handleEvents();

private:
	void initSDL(); // initialize SDL (ttf, mixer, image, create window and renderer, etc)
	void closeSDL(); // close all SDL resources

protected:
	SDL_Window* window_; // the window
	SDL_Renderer* renderer_;  // the renderer

	std::string windowTitle_; // window title
	int width_; // window width
	int height_; // window height

};

#endif /* SDLGAME_H_ */
