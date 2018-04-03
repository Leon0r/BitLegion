#include "ClickeableGO.h"
#include "PlayState.h"
//Clase de Testeo


ClickeableGO::ClickeableGO(SDLApp* game, int x, int y, int w, int h, Texture* texture): Entity(game)
{
	render = new ImageRenderer(texture);
	this->addRenderComponent(render);//componente de pintado para que aparezca en pantalla
	position_ = Vector2D(x, y);
	height_ = h;
	width_ = w;
}

ClickeableGO::~ClickeableGO()
{
}

void ClickeableGO::handleInput(Uint32 time, const SDL_Event& event) {
	if (ComponenteClickeable::handleInput(this, event)) {
		// vvvv Habra que cambiarlo cuando se suba el personaje la clase escena en general vvvv
		if (inRange((int)dynamic_cast<PlayState*>(this->getGame()->getStateMachine()->currentState())->getMainPj()->getPosition().getX())) {
			act();//Redefinico en cada clase
			cout << "Pulsado" << endl;
		}
		else
			cout << "not in range" << endl;
	}
}
