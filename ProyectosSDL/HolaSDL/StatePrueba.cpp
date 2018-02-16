#include "StatePrueba.h"
#include "ComponenteClickeable.h"
#include "TestGO.h"


StatePrueba::StatePrueba()
{
}

StatePrueba::StatePrueba(SDLApp* app): GameState(app) {
	ComponenteClickeable* prueba = new ComponenteClickeable();
	TestGO* test = new TestGO(app,400,300,400,300);
	stage.push_back(test);

}

StatePrueba::~StatePrueba()
{
}
