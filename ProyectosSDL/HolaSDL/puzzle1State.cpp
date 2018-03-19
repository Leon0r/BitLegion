#include "puzzle1State.h"

Puzzle1State::Puzzle1State(SDLApp * game, GameState * previousState) : GameState::GameState(game), previousState(previousState)
{
	matriz.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
		matriz[i].resize(numCas);
		for (int j = 0; j < numCas; j++) {
			if (j % 2 == 0 && i % 2 == 0 && i < 4) {
				numRestantes++;
				matriz[i][j] = new CasillaPuzzle1(game, std::to_string(i*numCas + j), game->getResources()->getImageTexture(Resources::llavePisoPuzzle), true);
			}
			else matriz[i][j] = new CasillaPuzzle1(game, std::to_string(i*numCas + j), game->getResources()->getImageTexture(Resources::CasillaPuzzleV));
			matriz[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + 137), relacion.second*(espaciado*i + 112)));
			stage.push_back(matriz[i][j]);
		}
	} 

	auxI = matriz[0][0]->getPosition().getX();
	auxD = auxI + relacion.first*espaciado;
	auxAB = matriz[numCas-1][numCas-1]->getPosition().getY();
	auxA = auxAB - relacion.second*espaciado;

	imagenMarca = new ImageRenderer(app->getResources()->getImageTexture(Resources::BotonPuzzle));
	for (int i = 0; i < numCas*2; i++) {
		Boton* b;
		if (i < numCas) {
			b = new Boton(game, usar, this, "boton1", i, -1);
			b->setWidth(80);
			b->setHeight(60);
			b->setPosition(Vector2D(b->getWidth(), relacion.second*(espaciado*i + espaciado + 25)));
		}
		else {
			b = new Boton(game, usar, this, "boton1", -1, i - numCas);
			b->setWidth(80);
			b->setHeight(60);
			b->setPosition(Vector2D(relacion.first*(espaciado*(i-numCas) + 111) + espaciado/3, game->getWindowHeight()-b->getHeight() - b->getHeight()/2));
		}
		b->addRenderComponent(imagenMarca);
		botones.push_back(b);
		stage.push_back(b);
	}

	//------------------------------------HUD-------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
}

void Puzzle1State::update()
{
	GameState::update();
	if (mover) mueveMatriz();
	if (numRestantes == 0) {
		app->getStateMachine()->popState();
	}
}

void Puzzle1State::tresUnidos()
{
	vector<int> casSp;
	int cont = 0;
	Texture* aux = nullptr;
	if(currentFil >= 0){
		for (int i = 0; i < numCas; i++){
			//Si la casilla es especial
			if (matriz[currentFil][i]->active()) {
				casSp.push_back(i);//marcamos como especial para luego comprobar otra dir
				if (aux == nullptr) aux = matriz[currentFil][i]->getTexture(0);//Textura aux a comprobar
				if( matriz[currentFil][i]->getTexture(0) == aux) {//Si tiene la textura correcta
					cont++;//Aumentamos contador
				}
				else {
					aux = matriz[currentFil][i]->getTexture(0);//Le damos el valor de la nueva casilla activap
					if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
						for (int j = cont; j > 0; j--) {
							matriz[currentFil][i - j]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
							matriz[currentFil][i - j]->setActive(false); numRestantes--;
						}
					}
					cont = 1;//La que acabamos de recibir
				}
			}
			else {
				if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
					for (int j = cont; j > 0; j--) {
						matriz[currentFil][i - j]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
						matriz[currentFil][i - j]->setActive(false); numRestantes--;
					}
				}
				cont = 0; aux = nullptr;
			}//Reseteo vars
		}
		if (cont >= 3) {
			for (int j = cont; j > 0; j--) {
				matriz[currentFil][numCas - j]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
				matriz[currentFil][numCas - j]->setActive(false); numRestantes--;
			}
			cont = 0;
			aux = nullptr;
		}
		else { cont = 0; aux = nullptr;}

		for (int i = 0; i < casSp.size(); i++)checkLine(casSp[i], false);
	}
	if(currentCol>-1){
		for (int i = 0; i < numCas; i++) {
			//Si la casilla es especial
			if (matriz[i][currentCol]->active()) {
				casSp.push_back(i);//marcamos como especial para luego comprobar otra dir
				if (aux == nullptr) aux = matriz[i][currentCol]->getTexture(0);//Textura aux a comprobar
				if (matriz[i][currentCol]->getTexture(0) == aux) {//Si tiene la textura correcta
					cont++;//Aumentamos contador
				}
				else {
					aux = matriz[i][currentCol]->getTexture(0);//Le damos el valor de la nueva casilla activap
					if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
						for (int j = cont; j > 0; j--) {
							matriz[i - j][currentCol]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
							matriz[i - j][currentCol]->setActive(false); numRestantes--;
						}
					}
					cont = 1;//La que acabamos de recibir
				}
			}
			else {
				if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
					for (int j = cont; j > 0; j--) {
						matriz[i - j][currentCol]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
						matriz[i - j][currentCol]->setActive(false); numRestantes--;
					}
				}
				cont = 0; aux = nullptr; 
			}//Reseteo vars
		}
		if (cont >= 3) {
			for (int j = cont; j > 0; j--) {
				matriz[numCas - j][currentCol]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
				matriz[numCas - j][currentCol]->setActive(false); numRestantes--;
			}
			cont = 0;
			aux = nullptr;
		}
		else { cont = 0; aux = nullptr; }
		for (int i = 0; i < casSp.size(); i++)checkLine(casSp[i], true);
	}
}

void Puzzle1State::mueveMatriz()
{
	if (currentFil >= 0) {
		if (auxD > auxI) {
			for (int i = 0; i < numCas; i++) {
				matriz[currentFil][i]->setVelocity(Vector2D(5, 0));
				matriz[currentFil][i]->setPosition(matriz[currentFil][i]->getPosition() + matriz[currentFil][i]->getVelocity());
				if (matriz[currentFil][i]->getPosition().getX() > topD) 
					matriz[currentFil][i]->setPosition(Vector2D(topI, matriz[currentFil][i]->getPosition().getY()));
			}
			auxI = matriz[currentFil][0]->getPosition().getX();
		}
		else {
			reestableFC(currentFil, -1);
			mover = false;
			auxI = matriz[0][0]->getPosition().getX();
			auxD = auxI + relacion.first*espaciado;
			tresUnidos();
		}
	}
	else {
		if (auxA < auxAB) {
			for (int i = 0; i < numCas; i++) {
				matriz[i][currentCol]->setVelocity(Vector2D(0, -5));
				matriz[i][currentCol]->setPosition(matriz[i][currentCol]->getPosition() + matriz[i][currentCol]->getVelocity());
				if (matriz[i][currentCol]->getPosition().getY() < topA) matriz[i][currentCol]->setPosition(Vector2D(matriz[i][currentCol]->getPosition().getX(), topAB));
			}
			auxAB = matriz[4][currentCol]->getPosition().getY();
		}
		else {
			reestableFC(-1, currentCol);
			mover = false;
			auxAB = matriz[numCas - 1][numCas - 1]->getPosition().getY();
			auxA = auxAB - relacion.second*espaciado;
			tresUnidos();
		}
	}
}

void Puzzle1State::destroy()
{
	for (int i = 0; i < botones.size(); i++) {
		delete botones[i]; botones[i] = nullptr;
	}
	for (int i = 0; i < numCas; i++) {
		for (int j = 0; j < numCas; j++) {
			delete matriz[i][j]; matriz[i][j] = nullptr;
		}
	}

	delete imagenMarca; imagenMarca = nullptr;

	//GameState::~GameState(); da problemas
}

void Puzzle1State::usar(GameState* state, int fil, int col)
{
	Puzzle1State* puzz = dynamic_cast<Puzzle1State*>(state);
	if (puzz != nullptr && !puzz->mover) { //comprobamos que sea el inventario por si acaso
		if (fil != -1) {
			puzz->currentFil = fil;
			puzz->currentCol = -1;
		}
		else if (col != -1) {
			puzz->currentCol = col;
			puzz->currentFil = -1;
		}
		puzz->mover = true;
	}
}

void Puzzle1State::checkLine(int line, bool Vert)
{
	int cont = 0;
	Texture* aux = nullptr;
	if (Vert) {//Vertical
		for (int i = 0; i < numCas; i++) {
			//Si la casilla es especial
			if (matriz[line][i]->active()) {
				if (aux == nullptr) aux = matriz[line][i]->getTexture(0);//Textura aux a comprobar
				if (matriz[line][i]->getTexture(0) == aux) {//Si tiene la textura correcta
					cont++;//Aumentamos contador
				}
				else {
					aux = matriz[line][i]->getTexture(0);//Le damos el valor de la nueva casilla activap
					if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
						for (int j = cont; j > 0; j--) {
							matriz[line][i - j]->setActive(false); numRestantes--;
							matriz[line][i - j]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
						}
					}
					cont = 1;//La que acabamos de recibir
				}
			}
			else {
				if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
					for (int j = cont; j > 0; j--) {
						matriz[line][i - j]->setActive(false); numRestantes--;
						matriz[line][i - j]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
					}
				}
				cont = 0; aux = nullptr;
			}//Reseteo vars
		}
		if (cont >= 3) {
			for (int j = cont; j > 0; j--) {
				matriz[line][numCas - j]->setActive(false); numRestantes--;
				matriz[line][numCas - j]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
			}
			cont = 0;
			aux = nullptr;
		}
		else { cont = 0; aux = nullptr; }
	}
	else {
		for (int i = 0; i < numCas; i++) {
			//Si la casilla es especial
			if (matriz[i][line]->active()) {
				if (aux == nullptr) aux = matriz[i][line]->getTexture(0);//Textura aux a comprobar
				if (matriz[i][line]->getTexture(0) == aux) {//Si tiene la textura correcta
					cont++;//Aumentamos contador
				}
				else {
					aux = matriz[i][line]->getTexture(0);//Le damos el valor de la nueva casilla activap
					if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
						for (int j = cont; j > 0; j--) {
							matriz[line][i - j]->setActive(false); numRestantes--;
							matriz[i - j][line]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
						}
					}
					cont = 1;//La que acabamos de recibir
				}
			}
			else {
				if (cont >= 3) {//Vemos si habia mas de 3 acumuladas
					for (int j = cont; j > 0; j--) {
						matriz[line][i - j]->setActive(false); numRestantes--;
						matriz[i - j][line]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
					}
				}
				cont = 0; aux = nullptr;
			}//Reseteo vars
		}
		if (cont >= 3) {
			for (int j = cont; j > 0; j--) {
				matriz[line][numCas - j]->setActive(false); numRestantes--;
				matriz[numCas - j][line]->setTexture(0, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
			}
			cont = 0;
			aux = nullptr;
		}
		else { cont = 0; aux = nullptr; }
	}
}
