#include "LightsOut.h"



LightsOut::LightsOut(SDLApp* app) : GameState::GameState(app), puzzleHasStarted(false)
{
	botonRender = (app->getResources()->getImageTexture(Resources::BotonPuzzle));//render del boton

	lights.resize(numCas);
	aux.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la lights de casillas
		lights[i].resize(numCas);
		aux[i].resize(numCas);
		for (int j = 0; j < numCas; j++) {
			lights[i][j] = new CasillaLight(app, i, j, 50, 50, nullptr, this);
			lights[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + 137), relacion.second*(espaciado*i + 112)));
			stage.push_back(lights[i][j]);
		}
	}
	this->apagaLuces(3);

	//--------Botones-----
	botonReset = new Boton(app, resetPuzzle, this, "reset");
	botonReset->setWidth(80);
	botonReset->setHeight(60);
	botonReset->setPosition(Vector2D(botonReset->getWidth(), relacion.second*(espaciado + espaciado + 25)));
	botonReset->addRenderComponent(&botonRender);
	stage.push_back(botonReset);
}


LightsOut::~LightsOut() //destructora
{
	for (int i = 0; i < numCas; i++) {
		for (int j = 0; j < numCas; j++) {
			delete lights[i][j]; lights[i][j] = nullptr;
		}
	}
	stage.clear();
}

bool LightsOut::win(){ //comprueba que todas las luces esten encendidas

	bool win = true;
	unsigned int i = 0;
	while (i < lights.size() && win) {
		unsigned int j = 0;
		while (j < lights[i].size() && win) {
			if (!lights[i][j]->isOn()) { win = false;}
			j++;
		}
		i++;
	}
	return win;
}

void LightsOut::receive(Mensaje* msg){
	if(msg->id_ == LuzInvertida) {
		pair<int, int> aux;
		aux = static_cast<MensajePosicionMatriz*>(msg)->pos_; //devuelve i, j de la matriz

		//invierte las adyacentes
		if (aux.first + 1 < lights.size()) { 
			lights[aux.first + 1][aux.second]->invertir(); 
		}
		if (aux.first - 1 >= 0) { 
			lights[aux.first - 1][aux.second]->invertir();
		}
		if (aux.second + 1 < lights[aux.first].size()) {
			lights[aux.first][aux.second + 1]->invertir();
		}
		if (aux.second - 1 >= 0) {
			lights[aux.first][aux.second - 1]->invertir();
		}
		if (win() && puzzleHasStarted) { //si gana y el puzzle ha empezado
			cout << "Disgüised Toast";
		}
	}
}

void LightsOut::apagaLuces(const unsigned int n){
	unsigned int i = 0;
	pair<pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int>> parAux; //par donde se guardan las dos ultimas posiciones invertidas
	parAux.first.first = parAux.first.second = parAux.second.first = parAux.second.second = numCas + 1; //no sé iniciar un par de pares snif

	while (i < n) {
		unsigned int x = rand() % numCas; //random entre 0 y numCas - 1
		unsigned int y = rand() % numCas;

		while(x == parAux.first.first || x == parAux.second.first) { x = rand() % numCas; } //mientras x sea igual al primer elemento de las dos posiciones, se hace random
		while (y == parAux.first.second || y == parAux.second.second) { y = rand() % numCas; } //igual en la y
		parAux.first.first = x;
		parAux.first.second = y;
		swap(parAux.first, parAux.second); //swap : (parActual, parViejo)--->(parViejo, parActual)

		lights[x][y]->act();
		i++;
	}
	updateAux();
	puzzleHasStarted = true; //puede ser que mientras hace el random de invertir, genere un puzzle resuelto. Si hace la comprobacion de win siempre, se saldra del estado y no queremos eso. Bool 
	//auxiliar para que solo compruebe cuando el random haya acabado y ya el usuario haga click en las casillas
}

void LightsOut::updateAux(){
	for (unsigned int i = 0; i < aux.size(); i++) {
		for (unsigned int j = 0; j < aux[i].size(); j++) {
			aux[i][j] = lights[i][j]->isOn();
		}
	}
}

void LightsOut::restartMatrix(){
	for (unsigned int i = 0; i < lights.size(); i++) {
		for (unsigned int j = 0; j < lights[i].size(); j++) {
			lights[i][j]->setOn(aux[i][j]); //cambia el bool y la textura a la inicial
		}
	}
}

void LightsOut::resetPuzzle(GameState * state){
	static_cast<LightsOut*>(state)->restartMatrix();
}
