
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Game.h"
using namespace std;


int main(int argc, char* argv[]){
	Game g("hola", 800, 600);//init the game with a name and a resolution
	g.run();
	return 0;
}