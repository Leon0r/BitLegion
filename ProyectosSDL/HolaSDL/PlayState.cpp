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
	
	//ESCENARIO
	Entity* escenario = new Entity(app);
	escenario->setWidth(app->getWindowWidth());
	escenario->setHeight(app->getWindowHeight());
	RenderComponent* renderEscenario = new ImageRenderer(resources->getImageTexture(Resources::Escena1Caso1));
	escenario->addRenderComponent(renderEscenario);
	stage.push_back(escenario);

	//COLISIONABLES
	Entity* cama = new ColisionableObject(app, 0, 290, 393, 170, resources->getImageTexture(Resources::Cama));
	stage.push_back(cama);
	collision.push_back(cama);
	Entity* mesa = new ColisionableObject(app, 580, 432, 220, 230, resources->getImageTexture(Resources::Mesa));
	stage.push_back(mesa);
	collision.push_back(mesa);
	Entity* cocina = new ColisionableObject(app, 915, 125, 365, 280, resources->getImageTexture(Resources::Cocina));
	stage.push_back(cocina);
	collision.push_back(cocina);

	Entity* hola = new ItemInventario(app, 200, 200, 25, 25, "jeje", "h", resources->getImageTexture(Resources::LlaveCutre));
	stage.push_back(hola);

	// crea la lista vacia
	list = new ObjectList(app);

	string name = "..\\Scenes\\pj.json";

	// Inicializa el personaje con los datos de archivo de la primera escena
	std::ifstream i(name);
	json j;
	i >> j;

	alena = new MainCharacter(app, j, list, collision, 6.0);
	stage.push_back(alena);

	i.close();

	//SHORTCUT
	shortcut = new ShortCut(app, list, resources);
	stage.push_back(shortcut);

	// crea las escenas 1 y 2 desde archivo
	//scenes.push_back(new Scene(0, app));
	//scenes.push_back(new Scene(1, app));
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
