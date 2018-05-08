#include "Interruptor.h"



Interruptor::Interruptor()
{
}


Interruptor::~Interruptor()
{
	luz_.delRenderComponent(&ausenciaDeLuz);
}

Interruptor::Interruptor(SDLApp* app, int x, int y, int w, int h, Texture* txt, string tag, int maxAlpha, int minAlpha, char id) : GOUnlockeable(app,x,y,w,h,txt,tag,id), maxAlpha_(maxAlpha), minAlpha_(minAlpha) {
	luz_ = Entity(app);
	ausenciaDeLuz = ImageRenderer(app->getResources()->getImageTexture(Resources::Transicion));
	luz_.addRenderComponent(&ausenciaDeLuz);
	app->getStateMachine()->currentState()->getStage()->push_back(&luz_);
}

void Interruptor::act() {
	if (on_) {
		luz_.getTexture()->changeAlpha(maxAlpha_);
	}
	else {
		luz_.getTexture()->changeAlpha(minAlpha_);
	}
}
