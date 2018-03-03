#include "Scene.h"
#include <fstream>

Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}

Scene::Scene(int numEscena, SDLApp* app):app(app) {
	string name = "..\\Scenes\\Scene" + to_string(numEscena);
	name += ".json";

	std::ifstream i(name);
	json j;
	i >> j;
	int n;
	for (int i = 0; i < j["ItemInventario"].size(); i++) {

		n = j["ItemInventario"][i]["Texture"];

		SceneItems.push_back(new ItemInventario(app, j["ItemInventario"][i]["x"], j["ItemInventario"][i]["y"], j["ItemInventario"][i]["w"], j["ItemInventario"][i]["h"], 
							j["ItemInventario"][i]["descripcion"], j["ItemInventario"][i]["tag"], 
							app->getResources()->getImageTexture(Resources::ImageId(n))));
	}

	SceneItems.push_back(new GODoors(app, 300, 300, 300, 300, app->getResources()->getImageTexture(Resources::PuertaCutre), "key", 0));
	i.close();
	saveSceneToJson();
}

Scene::~Scene()
{
	/*list<GameObject*>::iterator aux;
	for (aux = SceneItems.begin(); aux != SceneItems.end(); aux++) { hay que diferenciar si es la escena activa o no, para no provocar errores de borrar dos veces la misma memoria
		aux = SceneItems.erase(aux);
	}*/
}

void Scene::enterScene() {
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
	SceneItems.pop_front(); //quitamos al jugador de la escena (es global). Se puede hacer as� o con un for que se salte el primero y copie los dem�s
}


void Scene::saveSceneToJson() {
	std::ofstream i("..\\Scenes\\Scene4.json");
	json j;
	for (GameObject* it : SceneItems) {
		it->saveToJson(j);	
	}
	i << std::setw(4) << j;
	i.close();
}