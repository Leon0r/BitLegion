#include "PasswordState.h"



PasswordState::PasswordState()
{
}


PasswordState::~PasswordState()
{
	if (f != nullptr) { delete f; f = nullptr; }
}

PasswordState::PasswordState(SDLApp * app, string password, int id): Puzzle(app, id), password_(password)
{
	f = new Font("..//images/Dialogos/Moonace-Regular.ttf", 35);
	resetPassword();
}

void PasswordState::handleEvent(SDL_Event & e)
{
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z) {
			
			userPass_.at(i) = ((char)e.key.keysym.sym);
			i++;

			if(i >= password_.size()){
				win();
			}		
		}
	}

	GameState::handleEvent(e);
}

void PasswordState::render()
{
	GameState::render();

	Texture text(app->getRenderer(), userPass_, *f, { 255, 255, 255, 1 }); //fuente dinamica
	text.render(app->getRenderer(), 400, 400); //se llama al render de la fuente Dinamica
}

bool PasswordState::checkPassword()
{
	if (userPass_ != password_) {
		userPass_.clear();
		resetPassword();
		i = 0;
		return false;
	}
	else {
		return true;
	}

}

void PasswordState::win()
{
	if (checkPassword()) {
		Puzzle::win();
	}
}

void PasswordState::resetPassword()
{
	for (unsigned int j = 0; j < password_.size(); j++) {
		userPass_.push_back('-');
	}
}
