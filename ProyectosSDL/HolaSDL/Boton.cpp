#include "Boton.h"
#include "AnimationRenderer.h"

Boton::~Boton()
{
	this->delInputComponent(&ov);
	actualState = nullptr;
}

void Boton::handleInput(Uint32 time, const SDL_Event& event) {
	Entity::handleInput(time, event); //se llama al handleInput --> componentes adicionales que puedan tener

	if (ComponenteClickeable::handleInput(this, event)) { //si es pulsado
		/*if(this->animations.size() > 1 && render_ != nullptr) static_cast<AnimationRenderer*>(render_)->playAnim(1);
		else if (this->animations.size() > 0)static_cast<AnimationRenderer*>(render_)->playAnim(0);*/

		if (stateFC != nullptr) { //si state != nullptr se ejecuta (valido para las matrices del puzzle match3 solo...)
			stateFC(actualState, f, c);
		}
		else fun(); //para todo lo demás, fun();
	}

	else if (this->animations.size() > 0 && render_ != nullptr) static_cast<AnimationRenderer*>(render_)->playAnim(0);
}
