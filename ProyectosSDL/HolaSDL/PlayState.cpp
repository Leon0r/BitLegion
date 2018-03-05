#include "PlayState.h"

PlayState::~PlayState() {
	vector<Scene*>::iterator aux;
	scenes[currentScene]->exitScene();
	std::ofstream i("..\\Scenes\\pj.json"); //archivo donde se va a guardar
	json j;
	alena->saveToJson(j);
	i << std::setw(4) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
	stage.clear();
	for (aux = scenes.begin(); aux != scenes.end(); aux++) {
		(*aux)->saveSceneToJson();
		delete (*aux);
	}	
	delete list;
	delete alena;
}

PlayState::PlayState(SDLApp* app): GameState(app) {

	// crea la lista vacia
	list = new ObjectList(app);

	string name = "..\\Scenes\\pj.json";

	// Inicializa el personaje con los datos de archivo de la primera escena
	std::ifstream i(name);
	json j;
	i >> j;

	alena = new MainCharacter(app, j, list, collision);
	stage.push_back(alena);

	i.close();

	// crea las escenas 1 y 2 desde archivo
	scenes.push_back(new Scene(0, app));
	scenes.push_back(new Scene(1, app));
}

void PlayState::swapScene(int nextScene)
{
	if (nextScene < scenes.size() && nextScene >= 0) { // basicamente se asegura de que la escena a la que quiere cambiar existe
		scenes[currentScene]->exitScene();
		currentScene = nextScene;
		scenes[nextScene]->enterScene();
	}
	else cout << "Escena no encontrada, n�mero buscado: " << nextScene << " , escenas existentes hasta: " << scenes.size() - 1;
}
