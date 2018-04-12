#include "PlayState.h"
#include "GOstates.h"
#include <list>

PlayState::~PlayState() {

	//Se destruye la conversacion si la hay, para que no de problemas
	if (enConversacion) {
		delete stage.front();
		stage.pop_front();
	}

	vector<Scene*>::iterator aux;
	scenes[currentScene]->exitScene();
	std::ofstream i("..\\Scenes\\saves\\pj.json"); //archivo donde se va a guardar
	json j;
	alena->saveToJson(j);
	i << std::setw(4) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
	delete alena;
	delete shortcut;

	stage.clear();
	for (aux = scenes.begin(); aux != scenes.end(); aux++) {
		(*aux)->saveSceneToJson();
		delete (*aux);
	}	
	delete list;
}

PlayState::PlayState(SDLApp* app, bool load): GameState(app) {
	
	// crea la lista vacia
	list = new ObjectList(app);
	string name;
	if (load) name = "..\\Scenes\\saves\\pj.json";
	else name = "..\\Scenes\\pj.json";
	// Inicializa el personaje con los datos de archivo de la primera escena
	std::ifstream i(name);
	json j;
	i >> j;
	//SHORTCUT
	shortcut = new ShortCut(app, list, resources);
	stage.push_front(shortcut);

	alena = new MainCharacter(app, j, list, &collision, shortcut, 6.0);
	stage.push_front(alena);

	i.close();

	name = "..\\Scenes\\numScenes.json"; //archivo que indica el numero de las escenas
	int numScenes = 0;
	std::ifstream k(name);
	if (k.is_open()) {
		json numSC;
		k >> numSC;
		numScenes = numSC["numScenes"];
		k.close();
	}
	else {
		cout << "Archivo no encontrado: " + name;
	}

	if (!load) {
		for (int cont = 0; cont < numScenes; cont++) {
			scenes.push_back(new Scene(cont, app, alena));
		}
	}
	else
	{
		for (int cont = 0; cont < numScenes; cont++) {
			scenes.push_back(new Scene(cont, app, alena, load));
		}
	}

	this->currentScene = alena->getCurrentScene();

	// crea las escenas desde archivo
	
}

void PlayState::swapScene(int nextScene)
{
	if (nextScene < (int)scenes.size() && nextScene >= 0) { // basicamente se asegura de que la escena a la que quiere cambiar existe
		scenes[currentScene]->exitScene();
		currentScene = nextScene;
		scenes[nextScene]->enterScene();
		alena->setCurrentScene(currentScene);
	}
	else cout << "Escena no encontrada, numero buscado: " << nextScene << " , escenas existentes hasta: " << scenes.size() - 1;
}

void PlayState::handleEvent(SDL_Event & e){
	if (e.type == SDL_KEYDOWN) { //jaaaaaaaaaaaaaaaacksss
		if (e.key.keysym.sym == SDLK_F1) {
			swapScene(currentScene + 1);
		}
		else if (e.key.keysym.sym == SDLK_F2) {
		
			swapScene(currentScene - 1);
		}
	}

	if (!enConversacion) {
		GameState::handleEvent(e);
	}
	else {
		stage.front()->handleInput(0, e);
	}

}
void PlayState::setEnConversacion(bool conv) { 

	enConversacion = conv; 
	if (!conv) {
		delete stage.front();
	}
		stage.pop_front();
}