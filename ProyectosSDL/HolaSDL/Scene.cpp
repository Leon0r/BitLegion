#include "Scene.h"
#include "SDLApp.h"
#include "ItemInventario.h"
#include "Resources.h"
#include "GOTransiciones.h"


Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}

Scene::Scene(bool kk, SDLApp* app, int SceneNum): app(app) { //pruebas solo, Leo no me mates T_T T_T T_T T_T
	SceneNum = SceneNum;	
	if (kk) { 
		SceneItems.push_back(new ItemInventario(app, 368, 122, 64, 64, "descripcion", "tag", app->getResources()->getImageTexture(Resources::Alena)));
		SceneItems.push_back(new ItemInventario(app, 100, 544, 64, 64, "dsdwreeion", "teweg", app->getResources()->getImageTexture(Resources::ImagenTest)));
		SceneItems.push_back(new ItemInventario(app, 668, 0, 64, 64, "dffffn", "ffftag", app->getResources()->getImageTexture(Resources::BotonSwap)));
		SceneItems.push_back(new GOTransiciones(app, app->getWindowWidth()-70, 500, 100, 100, app->getResources()->getImageTexture(Resources::ImagenTest), 1));
	}
	else {
		SceneItems.push_back(new ItemInventario(app, 666, 66, 66, 66, "wwwww", "ferrrag", app->getResources()->getImageTexture(Resources::Inventario)));
		SceneItems.push_back(new GOTransiciones(app, 10, 500, 100, 100, app->getResources()->getImageTexture(Resources::ImagenTest), 0));
	}
}

Scene::~Scene()
{
}

void Scene::loadScene() {
	CurrentState = app->getStateMachine()->currentState();
	//Iniciamos ite, saltamos primer ite(jugador) borrarmos el resto de items copiamos nuestra lista
	it = CurrentState->getStage()->begin();
	it++;
	app->getStateMachine()->currentState()->changeList();
	while (it != CurrentState->getStage()->end()) {//Mientras no se acaben los items
		
		it = CurrentState->getStage()->erase(it);//borramos el item
	}
	CurrentState->getStage()->insert(CurrentState->getStage()->end(), SceneItems.begin(), SceneItems.end());
}

void Scene::exitScene() { //al salir de la escena, todos los objetos de stage se vuelcan en la lista de la escena para que se queden guardados (menos el jugador)
	app->getStateMachine()->currentState()->changeList();
	SceneItems.clear();
	SceneItems = *(app->getStateMachine()->currentState()->getStage()); //la lista stage es igual a todos los objetos de la escena
	SceneItems.pop_front(); //quitamos al jugador de la escena (es global). Se puede hacer así o con un for que se salte el primero y copie los demás
}