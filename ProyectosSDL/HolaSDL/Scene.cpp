#include "Scene.h"



Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}


Scene::~Scene()
{
}

void Scene::loadScene() {
	//Iniciamos ite, saltamos primer ite(jugador) borrarmos el resto de items copiamos nuestra lista
	it = CurrentState->getStage()->begin();
	it++;
	while (it != CurrentState->getStage()->end()) {//Mientras no se acaben los items
		CurrentState->getStage()->erase(it);//borramos el item
		it++;//Pasamos al siguiente
	}
	CurrentState->getStage()->insert(CurrentState->getStage()->begin(), SceneItems.begin(), SceneItems.end());
}

void Scene::exitScene() {
	//Cambia la lista actual por 
}