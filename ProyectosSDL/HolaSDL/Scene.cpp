#include "Scene.h"
#include <fstream>
#include "MainCharacter.h"

Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}

Scene::Scene(int numEscena, SDLApp* app, MainCharacter* pj):app(app), SceneNum(numEscena), pj(pj) {
	string name = "..\\Scenes\\Scene" + to_string(numEscena);
	name += ".json";

	std::ifstream i(name);
	
	if (i.is_open()) { // Para que no intente abrir archivos que no existen

		json j;
		i >> j;
		int n;

		// Cargado de items de inventario
		for (int i = 0; i < j["ItemInventario"].size(); i++) {

			n = j["ItemInventario"][i]["Texture"];

			SceneItems.push_front(new ItemInventario(app, j["ItemInventario"][i]["x"], j["ItemInventario"][i]["y"], j["ItemInventario"][i]["w"], j["ItemInventario"][i]["h"],
				j["ItemInventario"][i]["descripcion"], j["ItemInventario"][i]["tag"],
				app->getResources()->getImageTexture(Resources::ImageId(n))));
		}

		// Cargado de GODoors
		for (int i = 0; i < j["GODoors"].size(); i++) {

			n = j["GODoors"][i]["Texture"];

			SceneItems.push_back(new GODoors(app, j["GODoors"][i]["x"], j["GODoors"][i]["y"], j["GODoors"][i]["w"], j["GODoors"][i]["h"],
				app->getResources()->getImageTexture(Resources::ImageId(n)), j["GODoors"][i]["tag"], j["GODoors"][i]["scneNum"]));
		}

		// Cargado de GOTransiciones
		for (int i = 0; i < j["GOTransiciones"].size(); i++) {

			n = j["GOTransiciones"][i]["Texture"];

			SceneItems.push_back(new GOTransiciones(app, j["GOTransiciones"][i]["x"], j["GOTransiciones"][i]["y"],
				j["GOTransiciones"][i]["w"], j["GOTransiciones"][i]["h"],
				app->getResources()->getImageTexture(Resources::ImageId(n)), j["GOTransiciones"][i]["scneNum"]));
		}


		// Cargado de Colisiones
		for (int i = 0; i < j["CollisionableObject"].size(); i++) {

			n = j["CollisionableObject"][i]["Texture"];

			SceneItems.push_back(new ColisionableObject(app, j["CollisionableObject"][i]["x"], j["CollisionableObject"][i]["y"],
				j["CollisionableObject"][i]["w"], j["CollisionableObject"][i]["h"],
				app->getResources()->getImageTexture(Resources::ImageId(n))));
		}

		//ESCENARIO

		n = j["Texture"];

		Entity* escenario = new Entity(app);

		if (j["w"].is_null())
			escenario->setWidth(app->getWindowWidth());
		else escenario->setWidth(j["w"]);

		if (j["h"].is_null())
			escenario->setHeight(app->getWindowHeight());
		else escenario->setHeight(j["h"]);

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
			pj->setNewCollision(col);
		}
	}
	pj->collisionListWasModified();
}

void Scene::exitScene() { //al salir de la escena, todos los objetos de stage se vuelcan en la lista de la escena para que se queden guardados (menos el jugador)
	app->getStateMachine()->currentState()->changeList();
	SceneItems.clear();
	SceneItems = *(app->getStateMachine()->currentState()->getStage()); //la lista stage es igual a todos los objetos de la escena
	pj->clearCollisions(); //fuera colisiones
	SceneItems.pop_front(); //quitamos al jugador de la escena (es global). Se puede hacer as� o con un for que se salte el primero y copie los dem�s
	SceneItems.pop_front(); //quitamos al shortcut
	pj->setVelocity(Vector2D(0.0, 0.0));
	pj->getMouseComponent()->send(Messages(MouseStop));
}


void Scene::saveSceneToJson() {
	string name = "..\\Scenes\\saves\\Scene" + to_string(SceneNum);
	name += ".json";

	std::ofstream i(name); //archivo donde se va a guardar
	json j;
	for (GameObject* it : SceneItems) {
		it->saveToJson(j);	//manda a todos los objetos guardarse en dichos archivos
	}
	i << std::setw(3) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
}