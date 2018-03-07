#include "MouseDirection.h"
#include "MainCharacter.h"

void MouseDirection::setDirection(GameObject* o, Vector2D destiny) {
	//pair <double, double> posJugador(o->getPosition().getX(), o->getPosition().getY()); //el vector2D no tiene operador "==" o "!="
	//pair <double, double> posD(destiny.getX() + vel, destiny.getY() + vel);
	//pair <double, double> posI(destiny.getX() - vel, destiny.getY() - vel);
	
		double modX = (o->getPosition().getX() - destiny.getX());
		double modY = (o->getPosition().getY() + o->getHeight() - destiny.getY());
		double hipo = sqrt(pow(modX, 2) + pow(modY, 2)); //pitagoras

		double sen = modY / hipo; //sacamos el seno y el coseno del triangulo
		double cosen = modX / hipo;

		o->setVelocity(Vector2D(-(cosen * vel), -(sen * vel)));  //establecemos la dirección y velocidad
}


void MouseDirection::handleInput(GameObject* o, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONDOWN  && event.button.button == SDL_BUTTON_RIGHT) {
		p.x = event.button.x;
		p.y = event.button.y;
		setDirection(o, Vector2D(p.x, p.y));
	}
	stopMovement(o, Vector2D(p.x, p.y));

}


void MouseDirection::stopMovement(GameObject* o, Vector2D destiny) {
	SDL_Rect rectDestino = { destiny.getX() - o->getWidth()*2, destiny.getY() - o->getHeight(), o->getWidth() * 4, o->getHeight() * 2 };
	SDL_Point p = { o->getPosition().getX() + o->getWidth(), o->getPosition().getY() + o->getHeight()};
	RenderComponent* r = new ImageRenderer(static_cast<MainCharacter*>(o)->getGame()->getResources()->getImageTexture(Resources::PuertaCutre));
	static_cast<MainCharacter*>(o)->kk->setPosition(Vector2D(rectDestino.x, rectDestino.y));
	static_cast<MainCharacter*>(o)->kk->setHeight(rectDestino.h);
	static_cast<MainCharacter*>(o)->kk->setWidth(rectDestino.w);
	static_cast<MainCharacter*>(o)->kk->addRenderComponent(r);
	RenderComponent* y = new ImageRenderer(static_cast<MainCharacter*>(o)->getGame()->getResources()->getImageTexture(Resources::Cama));
	static_cast<MainCharacter*>(o)->kk2->setPosition(Vector2D(p.x, p.y));
	static_cast<MainCharacter*>(o)->kk2->setHeight(20);
	static_cast<MainCharacter*>(o)->kk2->setWidth(20);
	static_cast<MainCharacter*>(o)->kk2->addRenderComponent(y);
	if (SDL_PointInRect(&p, &rectDestino)) {
		o->setVelocity(Vector2D(0, 0));
	}
}
