#include "PlayState.h"
#include "GOstates.h"
#include <list>

PlayState::~PlayState() {
	vector<Scene*>::iterator aux;
	scenes[currentScene]->exitScene();
	std::ofstream i("..\\Scenes\\pj.json"); //archivo donde se va a guardar
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

PlayState::PlayState(SDLApp* app): GameState(app) {
	
	// crea la lista vacia
	list = new ObjectList(app);
	string name = "..\\Scenes\\pj.json";
	// Inicializa el personaje con los datos de archivo de la primera escena
	std::ifstream i(name);
	json j;
	i >> j;
	//SHORTCUT
	shortcut = new ShortCut(app, list, resources);
	stage.push_front(shortcut);

	/*PROVISIONAL*/
	//stage.push_front(new GOstates(app, 705, 265, 30, 30, app->getResources()->getImageTexture(Resources::FlechaTransicionSpriteSheet), new Puzzle1State(app, this), 1)); //MUY PROVISIONAL
	/*SUPERPROVISIONAL*/

	alena = new MainCharacter(app, j, list, &collision, shortcut, 6.0);
	stage.push_front(alena);

	i.close();

	// crea las escenas 1 y 2 desde archivo
	scenes.push_back(new Scene(0, app, alena));
	scenes.push_back(new Scene(1, app, alena));
	scenes.push_back(new Scene(2, app, alena));
}

void PlayState::swapScene(int nextScene)
{
	if (nextScene < (int)scenes.size() && nextScene >= 0) { // basicamente se asegura de que la escena a la que quiere cambiar existe
		scenes[currentScene]->exitScene();
		currentScene = nextScene;
		scenes[nextScene]->enterScene();
	}
	else cout << "Escena no encontrada, n�mero buscado: " << nextScene << " , escenas existentes hasta: " << scenes.size() - 1;
}
