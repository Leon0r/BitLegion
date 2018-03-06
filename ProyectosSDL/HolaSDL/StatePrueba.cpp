#include "StatePrueba.h"

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {

	//ESCENARIO
	Entity* escenario = new Entity(app);
	escenario->setWidth(app->getWindowWidth());
	escenario->setHeight(app->getWindowHeight());
	RenderComponent* renderEscenario = new ImageRenderer(resources->getImageTexture(Resources::Escena1Caso1));
	escenario->addRenderComponent(renderEscenario);
	stage.push_back(escenario);

	//COLISIONABLES
	Entity* cama = new ColisionableObject(app, 0, 290, 393, 170, resources->getImageTexture(Resources::Cama));
	stage.push_back(cama);
	collision.push_back(cama);
	Entity* mesa = new ColisionableObject(app, 580, 432, 220, 230, resources->getImageTexture(Resources::Mesa));
	stage.push_back(mesa);
	collision.push_back(mesa);
	Entity* cocina = new ColisionableObject(app, 915, 125, 365, 280, resources->getImageTexture(Resources::Cocina));
	stage.push_back(cocina);
	collision.push_back(cocina);

	//PERSONAJE
	//Siempre 1º para que ocupe la 1º posicion en la lista
	list = new ObjectList(app);
	alena = new MainCharacter(app, 400, 300, 60, 215, resources->getImageTexture(Resources::Alena), list, collision, 6.0);
	stage.push_back(alena);

	//SHORTCUT
	shortcut = new ShortCut(app, list, resources);
	stage.push_back(shortcut);
}
