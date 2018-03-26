#include "LightsOut.h"



LightsOut::LightsOut(SDLApp* app) : GameState::GameState(app)
{
	lights.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la lights de casillas
		lights[i].resize(numCas);
		for (int j = 0; j < numCas; j++) {
			if (j % 2 == 0 && i % 2 == 0 && i < 4) { //esto se leerá de json o se hará random
				lights[i][j] = new CasillaLight(app, i, j, 50, 50, app->getResources()->getImageTexture(Resources::BotellaVodka), this);
			}
			else lights[i][j] = new CasillaLight(app, i, j, 50, 50, app->getResources()->getImageTexture(Resources::Cama), this);
			lights[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + 137), relacion.second*(espaciado*i + 112)));
			stage.push_back(lights[i][j]);
		}
	}
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

bool LightsOut::win() //comprueba que todas las luces esten encendidas
{
	bool win = true;
	unsigned int i = 0;
	while (i < lights.size() && win) {
		unsigned int j = 0;
		while (j < lights[i].size() && win) {
			if (!lights[i][j]->getEncendido()) { win = false;}
			j++;
		}
		i++;
	}
	return win;
}

void LightsOut::receive(Mensaje* msg)
{
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
		if (win()) { //si gana...
			cout << "Disgüised Toast";
		}
	}
}
