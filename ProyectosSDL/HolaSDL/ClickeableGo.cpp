#include "ClickeableGO.h"
#include "StatePrueba.h"
//Clase de Testeo


ClickeableGO::ClickeableGO(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture): Entity(game)
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
		if (inRange(dynamic_cast<StatePrueba*>(this->getGame()->getStateMachine()->currentState())->getMainPj()->getPosition().getX())) {
			act();//Redefinico en cada clase
			cout << "Pulsado" << endl;
		}
		else
			cout << "not in range" << endl;
	}
	//dynamic_cast<StatePrueba*>(this->getGame()->getStateMachine()->currentState())->getMainPj()->getPosition().getX()
	///this->getGame()->getStateMachine()->currentState()->stage.front()->getDirection().getX()
}
