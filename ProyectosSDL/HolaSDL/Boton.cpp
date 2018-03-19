#include "Boton.h"

Boton::~Boton()
{
}

void Boton::handleInput(Uint32 time, const SDL_Event& event) {
	//Cambio vvvvvvvvvvvvvvv Antes: This->handleEvent
	if (ComponenteClickeable::handleInput(this, event)) { //si es pulsado
		if (inApp != nullptr) { //si inApp != nullptr se ejecuta dicha funcion
			inApp(app);
		}
		else if (state != nullptr) { //si state != nullptr se ejecuta
			state(actualState);
		}
		else if (stateFC != nullptr) { //si state != nullptr se ejecuta
			stateFC(actualState, f, c);
		}
	}
	Entity::handleInput(time, event); //se llama al handleInput --> componentes adicionales que puedan tener
}
