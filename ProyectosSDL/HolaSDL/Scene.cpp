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


	i.close();
}

Scene::Scene(bool kk, SDLApp* app, int SceneNum): app(app) { //pruebas solo, Leo no me mates T_T T_T T_T T_T
	SceneNum = SceneNum;	
	if (kk) { 
		SceneItems.push_back(new ItemInventario(app, 368, 122, 64, 64, "descripcion", "tag", app->getResources()->getImageTexture(Resources::Alena)));
		SceneItems.push_back(new ItemInventario(app, 100, 544, 64, 64, "dsdwreeion", "Hanzo", app->getResources()->getImageTexture(Resources::LlaveCutre)));
		SceneItems.push_back(new ItemInventario(app, 668, 0, 64, 64, "dffffn", "ffftag", app->getResources()->getImageTexture(Resources::BotonSwap)));
		SceneItems.push_back(new GODoors(app, app->getWindowWidth() - 200, 500, 200, 300, app->getResources()->getImageTexture(Resources::PuertaCutre), "Hanzo", 1));
	}
	else {
		SceneItems.push_back(new ItemInventario(app, 666, 66, 66, 66, "wwwww", "ferrrag", app->getResources()->getImageTexture(Resources::Inventario)));
		SceneItems.push_back(new GOTransiciones(app, 10, 500, 200, 300, app->getResources()->getImageTexture(Resources::ImagenTest), 0));
	}
	saveSceneToJson();
}

Scene::~Scene()
{
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
	/*j["ItemInventario"][0]["x"] = 300;
	j["ItemInventario"][0]["Texture"] = Resources::LlaveCutre;
	j["ItemInventario"][1]["Texture"] = Resources::Alena;*/

	int s = 0;
	for (GameObject* it : SceneItems) {
			ItemInventario* aux = dynamic_cast<ItemInventario*>(it);
			if(aux != nullptr){
			Vector2D pos = it->getPosition();
			j["ItemInventario"][s]["x"] = pos.getX();
			j["ItemInventario"][s]["y"] = pos.getY();
			j["ItemInventario"][s]["w"] = it->getWidth();
			j["ItemInventario"][s]["h"] = it->getHeight();
			s++;
		}
	}
	i << std::setw(4) << j;
	i.close();
}