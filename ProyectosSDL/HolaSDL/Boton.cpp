#include "Boton.h"
#include "AnimationRenderer.h"

Boton::~Boton()
{
	actualState = nullptr;
}

void Boton::handleInput(Uint32 time, const SDL_Event& event) {
	Entity::handleInput(time, event); //se llama al handleInput --> componentes adicionales que puedan tener

	if (ComponenteClickeable::handleInput(this, event)) { //si es pulsado

		if (stateFC != nullptr) { //si state != nullptr se ejecuta (valido para las matrices del puzzle match3 solo...)
			stateFC(actualState, f, c);
		}
		else fun(); //para todo lo demás, fun();
	}
}
