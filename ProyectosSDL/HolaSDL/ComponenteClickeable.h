#pragma once
#include <SDL.h>
#include "GameObject.h"

class ComponenteClickeable
<<<<<<< HEAD
=======
	//:public InputComponent
>>>>>>> Interacciones
{
public:
	ComponenteClickeable();
	~ComponenteClickeable();
<<<<<<< HEAD
	bool handleEvent(GameObject* o, const SDL_Event& event);
=======
	//void handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {};
	bool handleInput(GameObject* o, const SDL_Event& event);//Obtiene el rect del GO
	bool handleInput(SDL_Rect* rect, const SDL_Event& event);//recive un rectangulo destino

>>>>>>> Interacciones
private: 
	
};

