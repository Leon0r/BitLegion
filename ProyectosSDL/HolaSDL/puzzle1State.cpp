#include "puzzle1State.h"
#include <fstream>
#include "json.hpp"

Puzzle1State::Puzzle1State(SDLApp * game, GameState * previousState) : GameState::GameState(game), previousState(previousState)
{
	loadFromJson(1); //el 1 ese habrá que sacarlo de algún lado

	imagenCopia = new ImageRenderer(app->getResources()->getImageTexture(Resources::llavePisoPuzzle));
	copia->addRenderComponent(imagenCopia);
	copia->setWidth(imagenCopia->getTexture()->getHeight()*1.5*relacion.first);
	copia->setHeight(imagenCopia->getTexture()->getHeight()*1.7*relacion.second);
	copia->setPosition(Vector2D((103 * relacion.first) - copia->getWidth() / 2, (230 * relacion.second) - copia->getHeight() / 2));
	stage.push_back(copia);

	auxI = matriz[0][0]->getPosition().getX();
	auxD = auxI + relacion.first*espaciado;
	auxAB = matriz[numCas-1][numCas-1]->getPosition().getY();
	auxA = auxAB - relacion.second*espaciado;

	for (int i = 0; i < numCas*2; i++) {
		Boton* b;
		RenderComponent* bAnim = new ImageRenderer(app->getResources()->getImageTexture(Resources::BotonPuzzle));
		if (i < numCas) {
			b = new Boton(game, usar, this, "boton1", i, -1);
			b->setWidth(40);
			b->setHeight(60);
			b->setPosition(Vector2D(b->getWidth() + 223, relacion.second*((espaciado-4)*i + 51)));
		}
		else {
			b = new Boton(game, usar, this, "boton1", -1, i - numCas);
			b->setWidth(40);
			b->setHeight(60);
			b->setPosition(Vector2D(relacion.first*(espaciado*(i-numCas) + 100) + espaciado*2, game->getWindowHeight()-b->getHeight() - b->getHeight()/2));
		}
		//b->addAnim("pulsado", { 1 }, false, 1);
		//b->addAnim("Idle", { 0 }, false, 1);
		//RenderComponent* bAnim = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonReiniciar), resetButton->getAnimations(), 2, 1, 140, 140);
		botonesAnim.push_back(bAnim);
		b->addRenderComponent(botonesAnim[i]);
		botones.push_back(b);
		stage.push_back(b);
	}

	//------------------------------------HUD-------------------------------------------------------------
	resetButton = new Boton(app, resetFunction, this, "reset");
	//resetButton->addAnim("pulsado", { 1 }, false, 1);
	//resetButton->addAnim("Idle", { 0 }, false, 1);
	//reiniciar = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonReiniciar), resetButton->getAnimations(), 2, 1, 140, 140);
	reiniciar = new ImageRenderer(app->getResources()->getImageTexture(Resources::BotonReiniciar));
	resetButton->setPosition(Vector2D(43.5*relacion.first, 380*relacion.second)); //numeros majos
	resetButton->setHeight(reiniciar->getTexture()->getHeight() * 4 / 3);
	resetButton->setWidth(reiniciar->getTexture()->getWidth() * 4 / 3);
	resetButton->addRenderComponent(reiniciar);
	stage.push_back(resetButton);

	vector<int> j;
	j.resize(66);
	for (int i = 0; i < 66; i++)j[i] = 0;
	puzzleHud->addAnim("Idle", j, true, 50);
	puzzleHud->setHeight(app->getWindowHeight());
	puzzleHud->setWidth(app->getWindowWidth());
	puzzleHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - puzzleHud->getWidth() / 2,
		app->getWindowHeight() / 2 - puzzleHud->getHeight() / 2)));
	HUD = new AnimationRenderer(app->getResources()->getImageTexture(Resources::PuzzleHud), puzzleHud->getAnimations(), 9, 8, puzzleHud->getWidth()*0.75, puzzleHud->getHeight()*0.75);
	puzzleHud->addRenderComponent(HUD);
	stage.push_back(puzzleHud);
	//---------------------------------------------------------------------------------------------------
}

//---------------------------------------------------------------------------------------------------
void Puzzle1State::update()
{
	GameState::update();
	if (mover) mueveMatriz();
	if (numRestantes == 0) {
		app->getStateMachine()->popState();
	}
}

//---------------------------------------------------------------------------------------------------

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

//---------------------------------------------------------------------------------------------------

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

//---------------------------------------------------------------------------------------------------

void Puzzle1State::deleteMatrix() {
	vector<vector<CasillaPuzzle1*>>::iterator it;
	for (it = matriz.begin(); it != matriz.end();) {
		vector<CasillaPuzzle1*>::iterator anotherIt;
		for (anotherIt = (*it).begin(); anotherIt != (*it).end();) {
			this->deleteElement(*anotherIt);
			anotherIt = (*it).erase(anotherIt); //si no hacemos esto, la lista "stage" acaba con 10k objetos, todos nullptr
		}
		it = matriz.erase(it);
	}
}

//---------------------------------------------------------------------------------------------------

void Puzzle1State::destroy()
{
	for (int i = 0; i < botones.size(); i++) {
		if (botones[i] != nullptr) { delete botones[i]; botones[i] = nullptr; }
		if (botonesAnim[i] != nullptr) { delete botonesAnim[i]; botonesAnim[i] = nullptr; }
	}

	deleteMatrix();

	if (resetButton != nullptr) { delete resetButton; resetButton = nullptr; }

	if (puzzleHud != nullptr) { delete puzzleHud; puzzleHud = nullptr; }

	if (copia != nullptr) { delete copia; copia = nullptr; }
}

//---------------------------------------------------------------------------------------------------

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

//---------------------------------------------------------------------------------------------------

void Puzzle1State::eligeTipoCasilla(int tipoCas, string name, CasillaPuzzle1*& cas) { //A partir del enum y el numero asociado a la casilla
	switch (tipoCas) {
		case CasillaVacia:
			cas = new CasillaPuzzle1(app, name, app->getResources()->getImageTexture(Resources::CasillaPuzzleV));
			break;
		case CasillaLlena:
			numRestantes++;
			cas = new CasillaPuzzle1(app, name, app->getResources()->getImageTexture(Resources::llavePisoPuzzle), true);
			break;
		default:
			cas = new CasillaPuzzle1(app, name, app->getResources()->getImageTexture(Resources::CasillaPuzzleV)); //por defecto es vacía
			break;
	}
}

//---------------------------------------------------------------------------------------------------

void Puzzle1State::loadFromJson(int numeroPuzzle){
	string name = "..\\Puzzles\\Puzzle" + to_string(numeroPuzzle);
	name += ".json";
	std::ifstream file(name);

	if (file.is_open()) { // Para que no pete si abre un archivo que no existe
		
		json json;
		file >> json;
		int index = 0;
		if (json["Casillas"].is_array()) {
			matriz.resize(numCas);  //numCas = j["numCas"]; es const asi que supondré que siempre es el mismo tamaño de matriz
			matrizOriginal.resize(numCas);
			for (unsigned int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
				matrizOriginal[i].resize(numCas);
				matriz[i].resize(numCas);
				for (unsigned int j = 0; j < numCas; j++) {
					matrizOriginal[i][j] = json["Casillas"][index]["Tipo"]; //se rellena la matriz original con su numero correspondiente
					eligeTipoCasilla(json["Casillas"][index]["Tipo"], std::to_string(i*numCas + j), matriz[i][j]);
					matriz[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + 240), relacion.second*((espaciado-5)*i + 53)));
					stage.push_back(matriz[i][j]);
					index++;
				}
			}
		}
		file.close();
	}
	else {
		cout << "No existe el archivo indicado" << name;
	}
}

//---------------------------------------------------------------------------------------------------

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

//---------------------------------------------------------------------------------------------------

void Puzzle1State::restart()
{
	this->deleteMatrix(); //primero borra todos los elementos de la matriz actual
	this->changeList(); //evita problemas de nullptr en el handle del state
	numRestantes = 0; //para que sea posible resolverlo. Si reinicia se setea a 0 y se suma en su lugar adecuado
	matriz.resize(numCas);
	for (unsigned int i = 0; i < matrizOriginal.size(); i++) {
		matriz[i].resize(numCas);
		for (unsigned int j = 0; j < matrizOriginal[i].size(); j++) {
			eligeTipoCasilla(matrizOriginal[i][j], std::to_string(i*numCas + j), matriz[i][j]); //depende del tipo anteriormente guardado, se crea una casilla u otra
			matriz[i][j]->setPosition(Vector2D(relacion.first*(espaciado*j + 240), relacion.second*((espaciado - 5)*i + 53))); //la coloca
			stage.push_front(matriz[i][j]); //la pushea
		}
	}
}

//---------------------------------------------------------------------------------------------------
