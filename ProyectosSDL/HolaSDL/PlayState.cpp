#include "PlayState.h"
#include "GOstates.h"
#include <list>


bool compareZ(GameObject* o1, GameObject* o2) {
	int obj1_, obj2_;
	obj1_ = obj2_ = 10;
	if (o1->getPosition().getY() > o1->getGame()->getWindowHeight() / 2) {
		obj1_ = o1->getPosition().getY();
	}

	if (o2->getPosition().getY() > o2->getGame()->getWindowHeight() / 2) {
		obj2_ = o2->getPosition().getY();
	}

	return (obj1_ > obj2_);
}

void PlayState::SetZBuffer()
{
	Zbuffer.clear();
	Zbuffer = stage;
	Zbuffer.pop_back();//Quitamos el fondo
	Zbuffer.sort(compareZ);
}

PlayState::PlayState(SDLApp* app, bool load) : GameState(app) {

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
}


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

void PlayState::handleEvent(SDL_Event & e) {
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
		stage.pop_front();
	}

}

void PlayState::render() {

	sortZbuffer();

	stage.back()->render(0);

	std::list<GameObject*>::const_reverse_iterator its;
	for (its = Zbuffer.rbegin(); its != Zbuffer.rend(); its++)
		(*its)->render(0);
}



void PlayState::sortZbuffer() {
	int alenaZActual = alena->getPosition().getY();

	bool flag = true;
	if (listhasChanged) {
		SetZBuffer();
	}
	vector<std::list<GameObject*>::iterator*> overlap;
	overlap = getOverlapping();
	std::list<GameObject*>::iterator alenaIt;// = consAlenaIt;//No begin dynamic alena
	for (alenaIt = Zbuffer.begin(); (*alenaIt) != alena; alenaIt++); //Encontramos la pos de alena parece un for pero es un while disfrazado (eficiencia yeyy)
	alenaZ = alenaZActual;
	Zbuffer.erase(alenaIt);
	//short
	if (!overlap.empty()) {
		SetZBuffer();
	}
	else {
		Zbuffer.push_front(alena);
	}
}

vector<std::list<GameObject*>::iterator*> PlayState::getOverlapping()
{
	vector<std::list<GameObject*>::iterator*> overlap;
	SDL_Rect AlenaRect, itmRect, hanzpReckt;
	//Rect Alena
	AlenaRect.x = alena->getPosition().getX();
	AlenaRect.y = alena->getPosition().getY() + alena->getHeight() + 10;
	AlenaRect.w = alena->getWidth();
	AlenaRect.h = alena->getHeight() / 6; 
	
	for(it = Zbuffer.begin(); it != Zbuffer.end();it++){//Comprobamos con que rects hay colision
		itmRect.x = (*it)->getPosition().getX();
		itmRect.y = (*it)->getPosition().getY();
		itmRect.w = (*it)->getWidth();
		itmRect.h = (*it)->getHeight();
		if (SDL_IntersectRect(&AlenaRect, &itmRect, &hanzpReckt)) {
			overlap.push_back(&it); //Los añadimos al vector
		}
	}
	return overlap;
}