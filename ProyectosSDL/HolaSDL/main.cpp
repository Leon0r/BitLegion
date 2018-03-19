
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "SDLApp.h"
using namespace std;


int main(int argc, char* argv[]){
	SDLApp g(1280, 720);
	g.run();
	g.closeSDL();
	return 0;
}