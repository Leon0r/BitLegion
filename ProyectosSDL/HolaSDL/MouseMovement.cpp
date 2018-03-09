#include "MouseMovement.h"
#include "MainCharacter.h"
#include "AStar.h"

//actualizamos la logica del personaje
void MouseMovement::update(GameObject* o, Uint32 time) {
	MovementComponent::update(o, time);//update del movimniento normal
	stopMovement(o, destiny);//pero ademas si llega a la posicion destino se para
}

//miramos si ha llegado a la posicion destino
void MouseMovement::stopMovement(GameObject* o, Vector2D destiny) {
	/*RenderComponent* r = new ImageRenderer(static_cast<MainCharacter*>(o)->getGame()->getResources()->getImageTexture(Resources::PuertaCutre));
	static_cast<MainCharacter*>(o)->kk->setPosition(Vector2D(rectDestino.x, rectDestino.y));
	static_cast<MainCharacter*>(o)->kk->setHeight(rectDestino.h);
	static_cast<MainCharacter*>(o)->kk->setWidth(rectDestino.w);
	static_cast<MainCharacter*>(o)->kk->addRenderComponent(r);
	RenderComponent* y = new ImageRenderer(static_cast<MainCharacter*>(o)->getGame()->getResources()->getImageTexture(Resources::Cama));
	static_cast<MainCharacter*>(o)->kk2->setPosition(Vector2D(q.x, q.y));
	static_cast<MainCharacter*>(o)->kk2->setHeight(20);
	static_cast<MainCharacter*>(o)->kk2->setWidth(20);
	static_cast<MainCharacter*>(o)->kk2->addRenderComponent(y);*/
	if (playerInDestiny(o, destiny)) {
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
	int grid2[9][10] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	AStar* nek = new AStar(this);
	nek->defineCosas(o);
	//si se pulsa el raton registramos su posicion
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		p.x = event.button.x;
		p.y = event.button.y;
	}
	//si se suelta elegimos la direccion del jugador para llegar a esa posicion y actualizamos la posicion destino del componente mouseMov
	else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT) {
		setDestiny(p.x, p.y);
		if (!playerInDestiny(o, destiny)) { 
			nek->aStarSearch(grid2, pair<double, double>(o->getPosition().getX() / auxX, o->getPosition().getY() / auxY), pair<double, double>(p.x / auxX, p.y / auxY)); 
			/*while (!stackerino.empty()) {
				Vector2D desAux (stackerino.top().first, stackerino.top().second);
				stackerino.pop();
				setDestiny(desAux.getX(), desAux.getY());
				setDirection(o, destiny);
				while (!playerInDestiny(o, destiny)) {
					update(o, 0);
				}
			}*/ //da mala espina el bucle si
		} //setDirection(o, Vector2D(p.x, p.y));
		//while(pilanovacia) { while(!playerInDestiny) {setDirection()} stack.pop; setdestiny(stack.top);}
	}
}

bool MouseMovement::playerInDestiny(GameObject* o, Vector2D destiny) {
	SDL_Rect rectDestino = { destiny.getX() - o->getWidth() / 4, destiny.getY() - o->getWidth() / 6, o->getWidth() / 2 , o->getWidth() / 2 };
	SDL_Point q = { o->getPosition().getX() + o->getWidth() / 4, o->getPosition().getY() + o->getHeight() };
	return (SDL_PointInRect(&q, &rectDestino));
}
