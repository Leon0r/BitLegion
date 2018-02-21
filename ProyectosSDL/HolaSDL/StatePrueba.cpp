#include "StatePrueba.h"

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {

	//creamos al personaje
	object = new Entity(app);
	object->setWidth(100);//ancho, alto, posicion y textura
	object->setHeight(100);
	object->setPosition(Vector2D(app->getWindowWidth()/2, app->getWindowHeight() / 2));
	Texture* texture2 = new Texture;
	texture2->loadFromImg(app->getRenderer(), "..//images/alena.png");

	//componentes
	RenderComponent* render2 = new ImageRenderer(texture2);
	object->addRenderComponent(render2);//componente de pintado para que aparezca en pantalla

										//añadimos el personaje a la lista de personajes
	stage.push_back(object);

	collision.push_back(object);

	//////////////////////////////////////
	//creamos al personaje
	alena = new Entity(app);
	alena->setWidth(39);//ancho, alto, posicion y textura
	alena->setHeight(143);
	alena->setPosition(Vector2D(0 - alena->getWidth(), app->getWindowHeight() / 2 - alena->getHeight()));
	Texture* texture = new Texture;
	texture->loadFromImg(app->getRenderer(), "..//images/alena.png");

	//componentes
	RenderComponent* render = new ImageRenderer(texture);
	alena->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	InputComponent* keyboard = new KeyboardComponent(5, SDLK_RIGHT, SDLK_LEFT, SDLK_UP, SDLK_DOWN);
	alena->addInputComponent(keyboard);//componente de input para manejar su direccion
	PhysicsComponent* movement = new MovementComponent(collision);
	alena->addPhysicsComponent(movement);//componente de movimiento para que pueda moverse

	//añadimos el personaje a la lista de personajes
	stage.push_back(alena);


	
}