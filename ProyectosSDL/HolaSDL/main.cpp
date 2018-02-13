
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "SDLApp.h"
using namespace std;


int main(int argc, char* argv[]){
	SDLApp g(800, 600);
	g.run();
	system("pause");
	return 0;
}