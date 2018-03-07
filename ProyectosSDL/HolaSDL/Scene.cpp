#include "Scene.h"
#include <fstream>
#include "MainCharacter.h"

Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}

Scene::Scene(int numEscena, SDLApp* app) :app(app), SceneNum(numEscena) {
	string name = "..\\Scenes\\Scene" + to_string(numEscena);
	name += ".json";

	std::ifstream i(name);

	if (i.is_open()) { // Para que no intente abrir archivos que no existen

		json j;
		i >> j;
		int n;

		if (j["ItemInventario"].is_array())
			// Cargado de items de inventario
			for (int i = 0; i < (int)j["ItemInventario"].size(); i++) {

				n = j["ItemInventario"][i]["Texture"];

				SceneItems.push_back(new ItemInventario(app, j["ItemInventario"][i]["x"], j["ItemInventario"][i]["y"], j["ItemInventario"][i]["w"], j["ItemInventario"][i]["h"],
					j["ItemInventario"][i]["descripcion"], j["ItemInventario"][i]["tag"],
					app->getResources()->getImageTexture(Resources::ImageId(n))));
			}

		if (j["GODoors"].is_array())
			// Cargado de GODoors
			for (int i = 0; i < (int)j["GODoors"].size(); i++) {

				n = j["GODoors"][i]["Texture"];

				SceneItems.push_back(new GODoors(app, j["GODoors"][i]["x"], j["GODoors"][i]["y"], j["GODoors"][i]["w"], j["GODoors"][i]["h"],
					app->getResources()->getImageTexture(Resources::ImageId(n)), j["GODoors"][i]["tag"], j["GODoors"][i]["scneNum"]));
			}

		if (j["GOTransiciones"].is_array())
			// Cargado de GOTransiciones
			for (int i = 0; i < (int)j["GOTransiciones"].size(); i++) {

				n = j["GOTransiciones"][i]["Texture"];

				SceneItems.push_back(new GOTransiciones(app, j["GOTransiciones"][i]["x"], j["GOTransiciones"][i]["y"],
					j["GOTransiciones"][i]["w"], j["GOTransiciones"][i]["h"],
					app->getResources()->getImageTexture(Resources::ImageId(n)), j["GOTransiciones"][i]["scneNum"]));
			}

		if (j["Collisions"].is_array())
			// Cargado de Colisiones
			for (int i = 0; i < (int)j["Collisions"].size(); i++) {

				n = j["Collisions"][i]["Texture"];

				SceneItems.push_back(new ColisionableObject(app, j["Collisions"][i]["x"], j["Collisions"][i]["y"],
					j["Collisions"][i]["w"], j["Collisions"][i]["h"],
					app->getResources()->getImageTexture(Resources::ImageId(n))));
			}

		//ESCENARIO

		n = j["Fondo"]["Texture"];

		Entity* escenario = new Entity(app);
		escenario->setWidth(app->getWindowWidth());
		escenario->setHeight(app->getWindowHeight());
		RenderComponent* renderEscenario = new ImageRenderer(app->getResources()->getImageTexture(Resources::ImageId(n)));
		escenario->addRenderComponent(renderEscenario);
		SceneItems.push_back(escenario);

		i.close();
	}
	else {
		cout << "No existe el archivo " << name;
	}
}

Scene::~Scene()
{
	list<GameObject*>::iterator aux;
	for (aux = SceneItems.begin(); aux != SceneItems.end();) {
		delete *aux;
		aux = SceneItems.erase(aux); //aux = aux++
	}
}

void Scene::enterScene() {
	CurrentState = app->getStateMachine()->currentState();
	//Iniciamos ite, saltamos primer ite(jugador) borrarmos el resto de items copiamos nuestra lista
	it = CurrentState->getStage()->begin();
	it++; it++;
	app->getStateMachine()->currentState()->changeList();

	while (it != CurrentState->getStage()->end()) {//Mientras no se acaben los items
		
		it = CurrentState->getStage()->erase(it);//borramos el item
	}
	CurrentState->getStage()->insert(CurrentState->getStage()->end(), SceneItems.begin(), SceneItems.end());
	for (GameObject* it : SceneItems) {
		ColisionableObject* col = dynamic_cast<ColisionableObject*>(it);
		if (col != nullptr) {
			dynamic_cast<MainCharacter*>(CurrentState->getStage()->front())->setNewCollision(col); //setea las nuevas colisiones de la escena
		}
	}
}

void Scene::exitScene() { //al salir de la escena, todos los objetos de stage se vuelcan en la lista de la escena para que se queden guardados (menos el jugador)
	app->getStateMachine()->currentState()->changeList();
	SceneItems.clear();
	SceneItems = *(app->getStateMachine()->currentState()->getStage()); //la lista stage es igual a todos los objetos de la escena
	dynamic_cast<MainCharacter*>(SceneItems.front())->clearCollisions(); //fuera colisiones
	SceneItems.pop_front(); //quitamos al jugador de la escena (es global). Se puede hacer as� o con un for que se salte el primero y copie los dem�s
	SceneItems.pop_front(); //quitamos al shortcut
}


void Scene::saveSceneToJson() {
	string name = "..\\Scenes\\saves\\Scene" + to_string(SceneNum);
	name += ".json";

	std::ofstream i(name); //archivo donde se va a guardar
	json j;
	list<GameObject*>::iterator it;
	for (it = SceneItems.begin(); it != SceneItems.end(); it++) {
		if (std::next(it) == SceneItems.end()) {
			(*it)->saveToJson(j["Fondo"]);
		}
		else {
			(*it)->saveToJson(j);
		}
	}
	/*for (GameObject* it : SceneItems) {
		it->saveToJson(j);	//manda a todos los objetos guardarse en dichos archivos
	}*/
	i << std::setw(3) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
}