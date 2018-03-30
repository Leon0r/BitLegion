#include "LightsOut.h"



LightsOut::LightsOut(SDLApp* app) : GameState::GameState(app), puzzleHasStarted(false)
{
	botonRender = (app->getResources()->getImageTexture(Resources::BotonPuzzle));//render del boton
	
	this->creaDecoracion(); //crea los objetos del HUD

	lights.resize(numCas);
	aux.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la lights de casillas
		lights[i].resize(numCas);
		aux[i].resize(numCas);
		for (int j = 0; j < numCas; j++) {
			lights[i][j] = new CasillaLight(app, i, j, tamCas/numCas, tamCas/numCas, nullptr, this);
			lights[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + posX), relacion.second*(espaciado*i + 182)));
			stage.push_front(lights[i][j]);
		}
	}
	this->apagaLuces(1);

	//--------Botones-----
	botonReset = new Boton(app, resetPuzzle, this, "reset");
	botonReset->setWidth(80);
	botonReset->setHeight(60);
	botonReset->setPosition(Vector2D(app->getWindowWidth() / 1.35, app->getWindowHeight()/2 + botonReset->getHeight()*1.8));
	botonReset->addRenderComponent(&botonRender);
	stage.push_front(botonReset);
}


LightsOut::~LightsOut() //destructora
{
	for (unsigned int i = 0; i < numCas; i++) {
		for (unsigned int j = 0; j < numCas; j++) {
			delete lights[i][j]; lights[i][j] = nullptr;
		}
	}
	hud.delRenderComponent(&hudRend);
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

void LightsOut::creaDecoracion(){ //hay que hacer el vector de entitieeees
	hudRend = (app->getResources()->getImageTexture(Resources::HudLuces)); //hud del inventario

	barras = Entity(app); //barras y su animacion
	barras.addAnim("IdleRight", { 0, 1, 2, 3, 4, 5, 6, 7 }, true, -1, 200);
	barras.setHeight(150); barras.setWidth(200); barras.setPosition(Vector2D(0 + barras.getWidth()/2 + 10, 270)); //numeros majos
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::Barras), barras.getAnimations(), 2, 4, 226, 164));
	barras.addRenderComponent(anim[0]);
	stage.push_back(&barras);

	carga = Entity(app); //barra de carga y su animacion
	carga.addAnim("IdleRight", { 0, 1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }, true, -1, 150);
	carga.setHeight(480); carga.setWidth(480); carga.setPosition(Vector2D(app->getWindowWidth()/1.5 - carga.getWidth()/60, 130));
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::Carga), carga.getAnimations(), 4, 5, 480, 480));
	carga.addRenderComponent(anim[1]);
	stage.push_back(&carga);

	onda = Entity(app); //onda y su animacion
	onda.addAnim("IdleRight", { 0, 1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11, 12 }, true, -1, 100);
	onda.setHeight(300); onda.setWidth(280); onda.setPosition(Vector2D(0 + onda.getWidth()/4, app->getWindowHeight()/1.8));
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::Onda), onda.getAnimations(), 4, 4, 272, 272));
	onda.addRenderComponent(anim[2]);
	stage.push_back(&onda);

	text = Entity(app); //texto y su animacion
	text.addAnim("IdleRight", { 0, 1}, true, -1, 750);
	text.setHeight(300); text.setWidth(280); text.setPosition(Vector2D(0 + text.getWidth() / 4, 0));
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::TextoPixel), text.getAnimations(), 1, 2, 240, 240));
	text.addRenderComponent(anim[3]);
	stage.push_back(&text);

	hud = Entity(app); //hud
	hud.setWidth(app->getWindowWidth()); hud.setHeight(app->getWindowHeight()); hud.setPosition(Vector2D(0, 0));
	hud.addRenderComponent(&hudRend);
	stage.push_back(&hud);
}
