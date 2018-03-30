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
	hudAux->delRenderComponent(&hudRend);
	for (unsigned int i = 0; i < numCas; i++) {
		for (unsigned int j = 0; j < numCas; j++) {
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
			cout << "Disg�ised Toast";
		}
	}
}

void LightsOut::render(){
	fadeOut();
	GameState::render();
}

void LightsOut::handleEvent(SDL_Event & e){
	if (faded) GameState::handleEvent(e); //podria hacerlo activando los gameObjects, pero como el active no lo usamos para nada, no quiero tocar la estructura por un efecto "fancy"
}

void LightsOut::apagaLuces(const unsigned int n){
	unsigned int i = 0;
	pair<pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int>> parAux; //par donde se guardan las dos ultimas posiciones invertidas
	parAux.first.first = parAux.first.second = parAux.second.first = parAux.second.second = numCas + 1; //no s� iniciar un par de pares snif

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
	decorado.resize(5);

	hudRend = (app->getResources()->getImageTexture(Resources::HudLuces)); //hud del inventario

	decorado[0] = Entity(app); //barras y su animacion
	decorado[0].addAnim("IdleRight", { 0, 1, 2, 3, 4, 5, 6, 7 }, true, -1, 175);
	decorado[0].setHeight(150); decorado[0].setWidth(200); decorado[0].setPosition(Vector2D(0 + decorado[0].getWidth()/2 + 10, 270)); //numeros majos
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::Barras), decorado[0].getAnimations(), 2, 4, 226, 164));
	decorado[0].addRenderComponent(anim[0]);
	stage.push_back(&decorado[0]);

	decorado[1] = Entity(app); //barra de carga y su animacion
	decorado[1].addAnim("IdleRight", { 0, 1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }, true, -1, 150);
	decorado[1].setHeight(480); decorado[1].setWidth(480); decorado[1].setPosition(Vector2D(app->getWindowWidth()/1.5 - decorado[1].getWidth()/60, 130));
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::Carga), decorado[1].getAnimations(), 4, 5, 480, 480));
	decorado[1].addRenderComponent(anim[1]);
	stage.push_back(&decorado[1]);

	decorado[2] = Entity(app); //ondas y su animacion
	decorado[2].addAnim("IdleRight", { 0, 1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11, 12, 13, 14, 15, 16 }, true, -1, 75);
	decorado[2].setHeight(300); decorado[2].setWidth(280); decorado[2].setPosition(Vector2D(0 + decorado[2].getWidth()/4, app->getWindowHeight()/1.8));
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::Onda), decorado[2].getAnimations(), 4, 5, 272, 272));
	decorado[2].addRenderComponent(anim[2]);
	stage.push_back(&decorado[2]);

	decorado[3] = Entity(app); //texto y su animacion
	decorado[3].addAnim("IdleRight", { 0, 1}, true, -1, 750);
	decorado[3].setHeight(300); decorado[3].setWidth(280); decorado[3].setPosition(Vector2D(0 + decorado[3].getWidth() / 4, 0));
	anim.push_back(new AnimationRenderer(app->getResources()->getImageTexture(Resources::TextoPixel), decorado[3].getAnimations(), 1, 2, 240, 240));
	decorado[3].addRenderComponent(anim[3]);
	stage.push_back(&decorado[3]);

	decorado[4] = Entity(app); //hud
	decorado[4].setWidth(app->getWindowWidth()); decorado[4].setHeight(app->getWindowHeight()); decorado[4].setPosition(Vector2D(0, 0));
	decorado[4].addRenderComponent(&hudRend);
	hudAux = &decorado[4];
	stage.push_back(&decorado[4]);
}

void LightsOut::fadeOut(){ 
	if (alpha > alphaMin) {
		alpha -= 2;
		for (int i = 0; i < decorado.size(); i++) {
			decorado[i].getTexture()->changeAlpha(alpha);
		}
		if (alpha <= alphaMin) faded = true;
	}
}