#include "Scene.h"
#include "SDLApp.h"
#include "ItemInventario.h"
#include "Resources.h"


Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}

Scene::Scene(bool kk, SDLApp* app, int SceneNum) { //pruebas solo, Leo no me mates T_T
	app = app;
	SceneNum = SceneNum;
	if (kk) { 
		SceneItems.push_back(new ItemInventario(app, 368, 0, 64, 64, "descripcion", "tag", app->getResources()->getImageTexture(Resources::ImagenTest)));
		SceneItems.push_back(new ItemInventario(app, 100, 0, 64, 64, "dsdwreeion", "teweg", app->getResources()->getImageTexture(Resources::ImagenTest)));
		SceneItems.push_back(new ItemInventario(app, 668, 0, 64, 64, "dffffn", "ffftag", app->getResources()->getImageTexture(Resources::ImagenTest)));
	}
	else {
		SceneItems.push_back(new ItemInventario(app, 668, 0, 64, 64, "wwwww", "ferrrag", app->getResources()->getImageTexture(Resources::ImagenTest)));
	}
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

void Scene::exitScene() { //al salir de la escena, todos los objetos de stage se vuelcan en la lista de la escena para que se queden guardados (menos el jugador)
	SceneItems.clear();
	SceneItems = *(app->getStateMachine()->currentState()->getStage()); //la lista stage es igual a todos los objetos de la escena
	SceneItems.pop_front(); //quitamos al jugador de la escena (es global). Se puede hacer así o con un for que se salte el primero y copie los demás
}