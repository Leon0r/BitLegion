#include "ControlesState.h"



ControlesState::ControlesState()
{
}


ControlesState::~ControlesState()
{
}

void ControlesState::create()
{
	movTeclas = Entity(app);
	movRaton = Entity(app);

	animTeclas = AnimationRenderer(app->getResources()->getImageTexture(Resources::ControlesKeyArrows), movTeclas.getAnimations(), 5, 6, 200, 144);
	animRaton = AnimationRenderer(app->getResources()->getImageTexture(Resources::ControlesClick), movRaton.getAnimations(), 6, 4, 150, 235);
}
