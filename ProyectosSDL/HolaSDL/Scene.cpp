#include "Scene.h"
#include <fstream>
#include "MainCharacter.h"
#include "GOstates.h"
#include "LightsOut.h"
#include "GOConversational.h"

Scene::Scene()
{
	//Leer num scene
	//Idealmente lee de un archivo
}

Scene::Scene(int numEscena, SDLApp* app, MainCharacter* pj,bool load):app(app), SceneNum(numEscena), pj(pj) {
	string name;
	if (load)name = "..\\Scenes\\saves\\Scene";
	else name = "..\\Scenes\\Scene";
	name = name + to_string(numEscena) +".json";
	//name += ".json";
	//cout << name;

	std::ifstream i(name);
	
	if (i.is_open()) { // Para que no intente abrir archivos que no existen

		json j;
		i >> j;
		int n;
		string obj = "ItemInventario"; // nombre del array del objeto en el json

		// Cargado de items de inventario
		for (int i = 0; i < j[obj].size(); i++) {

			n = j[obj][i]["Texture"];

			bool permanente = false;
			if (!j[obj][i]["permanente"].is_null()) { permanente = j[obj][i]["permanente"]; }

			SceneItems.push_front(new ItemInventario(app, j[obj][i]["x"], j[obj][i]["y"], j[obj][i]["w"], j[obj][i]["h"],
				j[obj][i]["descripcion"], j[obj][i]["tag"],
				app->getResources()->getImageTexture(Resources::ImageId(n)), permanente));

			addAnimsFromJSON(SceneItems.back(), j[obj][i], n);

			if (!j[obj][i]["rotation"].is_null()) {
				SceneItems.back()->setRotation(j[obj][i]["rotation"]);
			}
		}

		obj = "GOState";
		//Cargado de Puzles
		for (int i = 0; i < j[obj].size(); i++) {

			n = j[obj][i]["Texture"];


			SceneStates.push_back(PuzzleCreator(j[obj][i]["type"], j[obj][i]));

			SceneItems.push_back(new GOstates(app, j[obj][i]["x"], j[obj][i]["y"],
				j[obj][i]["w"], j[obj][i]["h"],
				app->getResources()->getImageTexture(Resources::ImageId(n)),SceneStates.back(), j[obj][i]));

			addAnimsFromJSON(SceneItems.back(), j[obj][i], n);
			
			if (!j[obj][i]["rotation"].is_null()) {
				SceneItems.back()->setRotation(j[obj][i]["rotation"]);
			}
		}

		// Cargado de GOTransiciones
		obj = "GOTransiciones";
		for (int i = 0; i < j[obj].size(); i++) {

			n = j[obj][i]["Texture"];

			SceneItems.push_back(new GOTransiciones(app, j[obj][i]["x"], j[obj][i]["y"],
				j[obj][i]["w"], j[obj][i]["h"],
				app->getResources()->getImageTexture(Resources::ImageId(n)), j[obj][i]["scneNum"]));

			addAnimsFromJSON(SceneItems.back(), j[obj][i], n);

			if (!j[obj][i]["rotation"].is_null()) {
				SceneItems.back()->setRotation(j[obj][i]["rotation"]);
			}
		}

		// Cargado de GODoors
		obj = "GODoors";
		for (int i = 0; i < j[obj].size(); i++) {

			n = j[obj][i]["Texture"];
			double rotGOTrans = 0;
			if(!j[obj][i]["rotGOTr"].is_null())
				rotGOTrans = j[obj][i]["rotGOTr"];

			int id = -4;
			if (!j[obj][i]["UnlockId"].is_null())
				if (j[obj][i]["UnlockId"].is_number_integer()) {
					id = j[obj][i]["UnlockId"];
				}

			SceneItems.push_back(new GODoors(app, j[obj][i]["x"], j[obj][i]["y"], j[obj][i]["w"], j[obj][i]["h"],
			app->getResources()->getImageTexture(Resources::ImageId(n)), j[obj][i]["tag"], j[obj][i]["scneNum"], rotGOTrans, id));
			addAnimsFromJSON(SceneItems.back(), j[obj][i], n);

			
			if (!j[obj][i]["rotation"].is_null()) {
				SceneItems.back()->setRotation(j[obj][i]["rotation"]);
			}
		}

		// Cargado de Colisiones
		obj = "CollisionableObject";
		for (int i = 0; i < j[obj].size(); i++) {

			n = j[obj][i]["Texture"];

			SceneItems.push_back(new ColisionableObject(app, j[obj][i]["x"], j[obj][i]["y"],
				j[obj][i]["w"], j[obj][i]["h"],
				app->getResources()->getImageTexture(Resources::ImageId(n))));

			addAnimsFromJSON(SceneItems.back(), j[obj][i], n);

			if (!j[obj][i]["rotation"].is_null()) {
				SceneItems.back()->setRotation(j[obj][i]["rotation"]);
			}
		}


		//Cargado objetos conversaciones
		for (int i = 0; i < j["GOConversational"].size(); i++) {

			n = j["GOConversational"][i]["Texture"];

			SceneItems.push_front(new GOConversational(app, j["GOConversational"][i]["x"], j["GOConversational"][i]["y"], j["GOConversational"][i]["w"], j["GOConversational"][i]["h"],
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

		width = escenario->getWidth();
		height = escenario->getHeight();

		Vector2D pos;
		if (j["x"].is_null())
			pos.setX(0);
		else
			pos.setX(j["x"]);
		
		if (j["y"].is_null())
			pos.setY(0);
		else
			pos.setY(j["y"]);

		escenario->setPosition(pos);
		x = escenario->getPosition().getX();
		y = escenario->getPosition().getY();

		if (j["PlayerPos"].is_object()) {
			posIni.setX(j["PlayerPos"]["x"]);
			posIni.setY(j["PlayerPos"]["y"]);
		}

		//guardamos su tamaño dependiendo de lo que ponga en el json
		if (j["PlayerTam"].is_object()) {
			playerTam.setX(j["PlayerTam"]["w"]);
			playerTam.setY(j["PlayerTam"]["h"]);
		}//si en el json no se especificaba nada, se queda con un tamaño por defecto
		else playerTam.set({ pj->defaultW, pj->defaultH });

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

	list<GameState*>::iterator stateIt;
	for (stateIt = SceneStates.begin(); stateIt != SceneStates.end();) {
		if(!app->getStateMachine()->checkElement(*stateIt)) delete *stateIt; //si no está dentro de la pila en el momento de borrar todo, se borra. Si está, no se borra ya que ya ha sido borrado
		stateIt = SceneStates.erase(stateIt); //aux = aux++
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

	//establecemos el tamaño de la nueva escena en el jugador (para las colisiones y el mouse)
	pj->setSceneTam(width, height, x, y);

	//limpiamos las pilas de teclas para evitar errores entre cambios de escena
	pj->cleanKeys();

	//establecemos su posicion inicial
	pj->setPosIni();

	//establecemos su tamaño
	pj->setTam();

	//genera la matriz para el mouse
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
	pj->getMouseComponent()->send(&Mensaje(MouseStop));
	pj->getMouseComponent()->send(&Mensaje(CambioEscena));
	this->setPosIni(pj->getPosition()); //funciona *_*
}


void Scene::saveSceneToJson() {
	string name = "..\\Scenes\\saves\\Scene" + to_string(SceneNum);
	name += ".json";

	std::ofstream i(name); //archivo donde se va a guardar
	json j;
	for (GameObject* it : SceneItems) {
		it->saveToJson(j);	//manda a todos los objetos guardarse en dichos archivos
	}

	j["PlayerPos"]["x"] = posIni.getX();
	j["PlayerPos"]["y"] = posIni.getY();

	j["PlayerTam"]["w"] = playerTam.getX();
	j["PlayerTam"]["h"] = playerTam.getY();

	i << std::setw(3) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
}

GameState * Scene::PuzzleCreator(PuzzleTypes type, const json& j){
	GameState* nPuzzle = nullptr;

	switch (type)
	{
	case (Match3):
	{
		int aux = -4;
		if(!j["UnlockId"].is_null())
			aux = j["UnlockId"];

		nPuzzle = new Puzzle1State(app, app->getStateMachine()->currentState(), j["numberPuzzle"], j["numText"], aux);
		break;
	}
	case (Lights):
	{
		int aux = -4;
		if (!j["UnlockId"].is_null())
			aux = j["UnlockId"];
		
		nPuzzle = new LightsOut(app, j["numCas"], j["dificultad"], aux);
		break;
	}
	default:
		break;
	}
	return nPuzzle;
}

void Scene::addAnimsFromJSON(GameObject* obj, json& j, const int numText){

	if (!j["animation"].is_null()) {
		if (j["animation"]) {
			Entity* col = static_cast<Entity*>(SceneItems.back());
			col->setAnimated(true);
			col->delEveryRenderComponent();
			for (unsigned int k = 0; k < j["Anims"].size(); k++) {
				col->addAnim("Anim" + to_string(k), j["Anims"][k], j["loop"], -1, j["vel"]);
			}

			col->addRenderComponent(new AnimationRenderer(
				app->getResources()->getImageTexture(Resources::ImageId(numText)), col->getAnimations(),
				j["numFilsFrame"], j["numColsFrame"], j["widthFrame"], j["heightFrame"]));
		}

	}
}