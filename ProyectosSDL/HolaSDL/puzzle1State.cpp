#include "puzzle1State.h"


Puzzle1State::Puzzle1State(SDLApp * game, GameState * previousState) : GameState::GameState(game), previousState(previousState)
{
	matriz.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
		matriz[i].resize(numCas);
		for (int j = 0; j < numCas; j++) {
			matriz[i][j] = new CasillaPuzzle1(game, std::to_string(i*numCas + j), game->getResources()->getImageTexture(Resources::LlavePiso));
			matriz[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + 137), relacion.second*(espaciado*i + 112)));
			stage.push_back(matriz[i][j]);
		}
		auxI = matriz[0][0]->getPosition().getX();
		auxD = auxI + relacion.first*espaciado;
	}
	puzzleHud->setHeight(app->getWindowHeight()*0.75);
	puzzleHud->setWidth(app->getWindowWidth()*0.75);
	puzzleHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - puzzleHud->getWidth() / 2,
		app->getWindowHeight() / 2 - puzzleHud->getHeight() / 2)));
	puzzleHud->addAnim("Idle", { 23 }, false, 0);
	imagen = new AnimationRenderer(app->getResources()->getImageTexture(Resources::Inventario), puzzleHud->getAnimations(), 4, 6, 600, 2700 / 6);
	puzzleHud->addRenderComponent(imagen);

	imagenMarca = new ImageRenderer(app->getResources()->getImageTexture(Resources::InvMarca));
	marca->addRenderComponent(imagenMarca);
	marca->setPosition(Vector2D(0, 100));
	marca->setHeight(espaciado*relacion.second);
	marca->setWidth(espaciado*relacion.first);

	stage.push_back(marca);
	stage.push_back(puzzleHud);
}

void Puzzle1State::destroy()
{
}

void Puzzle1State::usar(GameState* state, int fil, int col)
{
	Puzzle1State* puzz = dynamic_cast<Puzzle1State*>(state);
	if (puzz != nullptr) { //comprobamos que sea el inventario por si acaso
		if (fil = -1) {

		}
		else if (col = -1) {

		}
	}
}
