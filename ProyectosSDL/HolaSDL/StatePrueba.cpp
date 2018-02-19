#include "StatePrueba.h"
#include "ClickeableGO.h"


StatePrueba::StatePrueba()
{
}

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {

	ClickeableGO* test = new ClickeableGO(app,400,300,400,300,"descripcion del item","tagEspecial");
	stage.push_back(test);

}

StatePrueba::~StatePrueba()
{
}
