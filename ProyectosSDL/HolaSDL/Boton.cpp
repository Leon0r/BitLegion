#include "Boton.h"

Boton::~Boton()
{
}

void Boton::handleInput(Uint32 time, const SDL_Event& event) {

	if (this->handleEvent(this, event)) { //si es pulsado
		if (inApp != nullptr) { //si inApp != nullptr se ejecuta dicha funcion
			inApp(app);
		}
		else if (state != nullptr) { //si state != nullptr se ejecuta
			state(actualState);
		}
	}
	GameComponent::handleInput(time, event); //se llama al handleInput --> componentes adicionales que puedan tener
}
