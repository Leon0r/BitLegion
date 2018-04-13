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
	f = new Font("..//images/fuente2.ttf", 35);
}

void PasswordState::handleEvent(SDL_Event & e)
{
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z) {
			userPass_.push_back((char)e.key.keysym.sym);
			cout << checkPassword() << endl;
			win();
			//cout << userPass_ << endl;		
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
	if (userPass_.size() == password_.size()) {
		if (userPass_ != password_) {
			userPass_.clear();
			return false;
		}
		else {
			return true;
		}

	}
	else {
		return false;
	}
}

void PasswordState::win()
{
	if (checkPassword()) {
		Puzzle::win();
	}
}
