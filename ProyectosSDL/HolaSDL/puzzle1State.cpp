#include "puzzle1State.h"


Puzzle1State::Puzzle1State(SDLApp * game, GameState * previousState) : GameState::GameState(game), previousState(previousState)
{
	matriz.resize(numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
		matriz[i].resize(numCas);
		for (int j = 0; j < numCas; j++) {
			if (j % 2 == 0 && i % 2 == 0)matriz[i][j] = new CasillaPuzzle1(game, std::to_string(i*numCas + j), game->getResources()->getImageTexture(Resources::llavePisoPuzzle), true);
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
			b->setWidth((espaciado/2)*relacion.first);
			b->setHeight((espaciado/2)*relacion.second);
			b->setPosition(Vector2D(espaciado/2, relacion.second*(espaciado*i + espaciado + 25)));
		}
		else {
			b = new Boton(game, usar, this, "boton1", -1, i - numCas);
			b->setWidth((espaciado / 2)*relacion.first);
			b->setHeight((espaciado / 2)*relacion.second);
			b->setPosition(Vector2D(relacion.first*(espaciado*(i-numCas) + 107) + espaciado/3, game->getWindowHeight()-b->getHeight() - espaciado/3));
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
}

void Puzzle1State::tresUnidos()
{
	vector<int> casSp;
	int cont = 0;
	if(currentFil >= 0){
		for (int i = 0; i < numCas-1; i++){
			//Si la casilla es especial
			if (matriz[currentFil][i]->active()) {
				casSp.push_back(i);//marcamos como especial para luego comprobar otra dir
				if( matriz[currentFil][i]->getTexture(0) == matriz[currentFil][i+1]->getTexture(0)) {
				cont++;//Aumentamos contador
				}
				else if (cont > 3){
					for (int j = cont; j = 0; j--) {
						matriz[currentFil][i - j]->setTexture(0, app->getResources()->getImageTexture(Resources::BolsaCoca));
					}
					cont = 0;
				}
				else cont = 0;
			}
		}
	if (cont >= 3) {
		for (int j = cont; j > 0; j--) {
			matriz[currentFil][numCas-1 - j]->setTexture(0, app->getResources()->getImageTexture(Resources::BolsaCoca));
		}
		cont = 0;
	}
	else cont = 0;


		
	}
	else {

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
		}
	}
}

void Puzzle1State::destroy()
{
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
