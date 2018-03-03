#include "PlayState.h"

PlayState::PlayState(SDLApp* app): GameState(app) {

	//COLISIONABLES
	//Entity* object = new ColisionableObject(app, 500, 500, 100, 100, resources->getImageTexture(Resources::InvMarca));
	//stage.push_back(object);
	//collision.push_back(object);

	//PERSONAJE
	//Siempre 1� para que ocupe la 1� posicion en la lista
	list = new ObjectList(app);
	alena = new MainCharacter(app, 400, 300, 39, 143, resources->getImageTexture(Resources::Alena), list, collision);
	stage.push_back(alena);


	scenes.push_back(new Scene(1, app));

	//scenes.push_back(new Scene(false, app, 0));
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
