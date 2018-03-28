#include "Boton.h"
#include "AnimationRenderer.h"

Boton::~Boton()
{
	actualState = nullptr;
}

void Boton::handleInput(Uint32 time, const SDL_Event& event) {
	//Cambio vvvvvvvvvvvvvvv Antes: This->handleEvent
	if (ComponenteClickeable::handleInput(this, event)) { //si es pulsado
		if(this->animations.size() > 0 && render_ != nullptr) static_cast<AnimationRenderer*>(render_)->playAnim(1);
		else static_cast<AnimationRenderer*>(render_)->playAnim(0);
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

	else if (this->animations.size() > 0 && render_ != nullptr) static_cast<AnimationRenderer*>(render_)->playAnim(0);

	Entity::handleInput(time, event); //se llama al handleInput --> componentes adicionales que puedan tener
}
