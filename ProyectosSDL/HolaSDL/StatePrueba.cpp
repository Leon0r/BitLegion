#include "StatePrueba.h"



StatePrueba::StatePrueba()
{
}

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {
	/*GameComponent* prueba = new GameComponent(app); 
	stage.push_back(prueba);
	RenderComponent* rnd = new CMPPRUEBA();
	prueba->addRenderComponent(rnd);*/
}

StatePrueba::~StatePrueba()
{
}
