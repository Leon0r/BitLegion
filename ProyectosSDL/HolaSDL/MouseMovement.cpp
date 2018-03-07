#include "MouseMovement.h"
#include "MainCharacter.h"

//actualizamos la logica del personaje
void MouseMovement::update(GameObject* o, Uint32 time) {
	MovementComponent::update(o, time);//update del movimniento normal
	stopMovement(o, destiny);//pero ademas si llega a la posicion destino se para
}

//miramos si ha llegado a la posicion destino
void MouseMovement::stopMovement(GameObject* o, Vector2D destiny) {
	SDL_Rect rectDestino = { destiny.getX() - o->getWidth() / 4, destiny.getY() - o->getWidth() /6, o->getWidth() / 2 , o->getWidth() / 2 };
	SDL_Point q = { o->getPosition().getX() + o->getWidth() / 4, o->getPosition().getY() + o->getHeight() };
	RenderComponent* r = new ImageRenderer(static_cast<MainCharacter*>(o)->getGame()->getResources()->getImageTexture(Resources::PuertaCutre));
	/*static_cast<MainCharacter*>(o)->kk->setPosition(Vector2D(rectDestino.x, rectDestino.y));
	static_cast<MainCharacter*>(o)->kk->setHeight(rectDestino.h);
	static_cast<MainCharacter*>(o)->kk->setWidth(rectDestino.w);
	static_cast<MainCharacter*>(o)->kk->addRenderComponent(r);
	RenderComponent* y = new ImageRenderer(static_cast<MainCharacter*>(o)->getGame()->getResources()->getImageTexture(Resources::Cama));
	static_cast<MainCharacter*>(o)->kk2->setPosition(Vector2D(q.x, q.y));
	static_cast<MainCharacter*>(o)->kk2->setHeight(20);
	static_cast<MainCharacter*>(o)->kk2->setWidth(20);
	static_cast<MainCharacter*>(o)->kk2->addRenderComponent(y);*/
	if (SDL_PointInRect(&q, &rectDestino)) {
		o->setVelocity(Vector2D(0, 0));
	}
}

//se establece la direccion que el objeto o debera seguir para llegar a destino
void MouseMovement::setDirection(GameObject* o, Vector2D destiny) {
	double modX = (o->getPosition().getX() - destiny.getX());
	double modY = (o->getPosition().getY() + o->getHeight() - destiny.getY());
	double hipo = sqrt(pow(modX, 2) + pow(modY, 2)); //pitagoras

	double sen = modY / hipo; //sacamos el seno y el coseno del triangulo
	double cosen = modX / hipo;

	o->setVelocity(Vector2D(-(cosen * vel), -(sen * vel)));  //establecemos la dirección y velocidad
}

//eventos de mouse
void MouseMovement::handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {
	//si se pulsa el raton registramos su posicion
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		p.x = event.button.x;
		p.y = event.button.y;
	}
	//si se suelta elegimos la direccion del jugador para llegar a esa posicion y actualizamos la posicion destino del componente mouseMov
	else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT) {
		setDirection(o, Vector2D(p.x, p.y));
		setDestiny(p.x, p.y);
	}
}
