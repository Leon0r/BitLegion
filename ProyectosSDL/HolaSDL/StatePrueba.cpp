#include "StatePrueba.h"

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {
	//creamos al personaje
	alena = new GameComponent(app);
	alena->setWidth(39);//ancho, alto, posicion y textura
	alena->setHeight(143);
	alena->setPosition(Vector2D(app->getWindowWidth() / 2 - alena->getWidth(), app->getWindowHeight() / 2 - alena->getHeight()));
	Texture* texture = new Texture;
	texture->loadFromImg(app->getRenderer(), "..//images/Alena.png");

	//componentes
	RenderComponent* render = new ImageRenderer(texture);
	alena->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	InputComponent* keyboard = new KeyboardComponent(5, SDLK_RIGHT, SDLK_LEFT, SDLK_UP, SDLK_DOWN);
	alena->addInputComponent(keyboard);//componente de input para manejar su direccion
	PhysicsComponent* movement = new MovementComponent();
	alena->addPhysicsComponent(movement);//componente de movimiento para que pueda moverse

	//añadimos el personaje a la lista de personajes
	stage.push_back(alena);
}