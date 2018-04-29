#include "PasswordState.h"



PasswordState::PasswordState()
{
}


PasswordState::~PasswordState()
{
	if (f != nullptr) { delete f; f = nullptr; }

	if (fondo != nullptr) { fondo->delRenderComponent(&img); }
}

PasswordState::PasswordState(SDLApp * app, string password, int id, int txt): Puzzle(app, id), password_(password)
{
	f = new Font("..//images/Dialogos/Moonace-Regular.ttf", 50);
	resetPassword();

	if (txt != -1) {
		img = ImageRenderer(app->getResources()->getImageTexture(Resources::ImageId(txt)));
		fondo = new Entity(app);
		fondo->setWidth(app->getWindowWidth());
		fondo->setHeight(app->getWindowHeight());
		fondo->addRenderComponent(&img);
		this->stage.push_back(fondo);
	}

	function<void()> fun = [this]() mutable { reset(); };

	timerFail = new GOTimer(2000, fun);
	this->stage.push_back(timerFail);

	function<void()> fun2 = [this]() mutable { Puzzle::win(); };
	timeWin = new GOTimer(2000, fun2);
	this->stage.push_back(timeWin);
}

void PasswordState::handleEvent(SDL_Event & e)
{
	if (!checking) {
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z) {

				userPass_.at(i) = ((char)e.key.keysym.sym);
				i++;

				if (i >= password_.size()) {
					checkPassword();
				}
			}
		}
	}

	GameState::handleEvent(e);
}

void PasswordState::render()
{
	GameState::render();

	Texture text(app->getRenderer(), userPass_, *f, { 255, 255, 255, 1 }); //fuente dinamica
	text.render(app->getRenderer(), 410, 438); //se llama al render de la fuente Dinamica
}

bool PasswordState::checkPassword()
{
	if (userPass_ != password_ && !checking) {
		timerFail->startTimer();
		checking = true;
		i = 0;
		return false;
	}
	else if(!checking){
		timeWin->startTimer();
		checking = true;
		return true;
	}

}

void PasswordState::resetPassword()
{
	for (unsigned int j = 0; j < password_.size(); j++) {
		userPass_.push_back('_');
	}
}

void PasswordState::reset()
{
	userPass_.clear();
	resetPassword();
	checking = false;
}
