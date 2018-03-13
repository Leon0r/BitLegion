#include "PlayState.h"
#include <list>

PlayState::~PlayState() {
	vector<Scene*>::iterator aux;
	//scenes[0]->exitScene();
	std::ofstream i("..\\Scenes\\pj.json"); //archivo donde se va a guardar
	json j;
	alena->saveToJson(j);
	i << std::setw(4) << j; //pretty identación para leer mejor el archivo
	i.close(); //cierra el flujo
	delete alena;
	stage.clear();
	for (aux = scenes.begin(); aux != scenes.end(); aux++) {
		(*aux)->saveSceneToJson();
		delete (*aux);
	}	
	delete list;
}

PlayState::PlayState(SDLApp* app): GameState(app) {
	
	/*//COLISIONABLES
	Entity* cama = new ColisionableObject(app, 0, 290, 393, 170, resources->getImageTexture(Resources::Cama));
	stage.push_back(cama);
	collision.push_back(cama);
	Entity* mesa = new ColisionableObject(app, 580, 432, 220, 230, resources->getImageTexture(Resources::Mesa));
	stage.push_back(mesa);
	collision.push_back(mesa);
	Entity* cocina = new ColisionableObject(app, 915, 125, 365, 280, resources->getImageTexture(Resources::Cocina));
	stage.push_back(cocina);
	collision.push_back(cocina);

	Entity* hola = new ItemInventario(app, 200, 200, 25, 25, "jeje", "key", resources->getImageTexture(Resources::LlaveCutre));
	stage.push_back(hola);
	Entity* kk = new GODoors(app, 400, 400, 300, 400, app->getResources()->getImageTexture(Resources::PuertaCutre), "key", 1);
	stage.push_back(kk);*/

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

	alena = new MainCharacter(app, j, list, &collision, 6.0);
	stage.push_front(alena);

	i.close();

	// crea las escenas 1 y 2 desde archivo
	scenes.push_back(new Scene(0, app, alena));
	scenes.push_back(new Scene(1, app, alena));
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


/*void PlayState::handleEvent(SDL_Event &e) { debug de prueba
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_0) {
			swapScene(1);
		}
	}
	GameState::handleEvent(e);
}*/