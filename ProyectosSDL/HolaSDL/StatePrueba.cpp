#include "StatePrueba.h"



StatePrueba::StatePrueba()
{
}

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {
	detective = new GameComponent(app);
	detective->setWidth(400);
	detective->setHeight(300);
	detective->setPosition(Vector2D(app->getWindowWidth() / 2 - detective->getWidth(), app->getWindowHeight() / 2 - detective->getHeight()));
	Texture* texture = new Texture;
	texture->loadFromImg(app->getRenderer(), "..//images/detectivesSprites.png");
	RenderComponent* render = new ImageRenderer(texture);
	detective->addRenderComponent(render);
	InputComponent* keyboard = new KeyboardComponent(SDLK_LEFT, SDLK_RIGHT);
	detective->addInputComponent(keyboard);
	stage.push_back(detective);
}

StatePrueba::~StatePrueba()
{
}
