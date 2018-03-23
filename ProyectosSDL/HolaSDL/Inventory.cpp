#include "Inventory.h"
#include "Boton.h"
#include "Font.h"
#include "MainCharacter.h"
#include "AnimationRenderer.h"

Inventory::Inventory(SDLApp* app, ObjectList* inventario, GameState* previousState, ShortCut* shortcut) : GameState(app), inventario(inventario), selected(nullptr), previousState(previousState), SC(shortcut) {
	matriz.resize(numCas*numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
		for (int j = 0; j < numCas; j++) {
			matriz[i*numCas+j] = Vector2D(relacion.first*(espaciado*j + 150), relacion.second*(espaciado*i + 125));
		}
	}

	f = new Font("..//images/fuente2.ttf", tamanyoFuente);
	
	//imagen del inventario
	inventarioHud->setHeight(app->getWindowHeight()*0.75);
	inventarioHud->setWidth(app->getWindowWidth()*0.75);
	inventarioHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventarioHud->getWidth()/2, 
		app->getWindowHeight() / 2 - inventarioHud->getHeight()/2)));
	imagen = new AnimationRenderer(app->getResources()->getImageTexture(Resources::Inventario), inventarioHud->getAnimations(), 4, 6, 600, 2700/6);
	inventarioHud->addRenderComponent(imagen);

	for (int i = 0; i < inventario->getLength(); i++) { // se colocan los objetos en sus posiciones correspondientes
		if (i < numCas){
			inventario->getItem(i)->setWidth(inventario->getItem(i)->getWidth()* SC->getCoef());
			inventario->getItem(i)->setHeight(inventario->getItem(i)->getHeight() * SC->getCoef());
		}
		inventario->getItem(i)->setPosition(Vector2D(matriz[i].getX() - inventario->getItem(i)->getWidth()/2, 
			matriz[i].getY() - inventario->getItem(i)->getHeight() / 2));
	}

	//marcador de objeto seleccionado
	imagenMarca = new ImageRenderer(app->getResources()->getImageTexture(Resources::InvMarca));
	marca->addRenderComponent(imagenMarca);
	marca->setHeight(espaciado*relacion.second);
	marca->setWidth(espaciado*relacion.first);
	//se pushea todo a la lista de objetos
	inventario->pushObjects(stage);

if (inventario->getLength() != 0) {//si hay algun objeto en la lista de objetos
		copia = new Entity(app);
		selected = inventario->getItem(0); //inicializamos el primero como seleccionado
		selectedTexture = new ImageRenderer(selected->getTexture(0));
		copia->addRenderComponent(selectedTexture);
		copia->setHeight(selected->getHeight() * relacion.first);//lo agranda
		copia->setWidth(selected->getWidth() * relacion.second);
		copia->setPosition(Vector2D((618*relacion.first)-copia->getWidth()/2, (150*relacion.second)-copia->getHeight()/2));
		stage.push_back(copia);	//lo pushea a la lista de objetos
		stage.push_back(marca); //se marca el primero de ellos
		marca->setPosition(inventario->getItem(0)->getPosition() +
			Vector2D(inventario->getItem(0)->getWidth() / 2, inventario->getItem(0)->getHeight() / 2)
			- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2));
		muestraDescripcion();
	}

	//--------------------Pruebas Botones ----------------------
	Boton* useButton = new Boton(app, usar, this, "use"); //nuevo Boton
	RenderComponent* im = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonUsar), useButton->getAnimations(), 4, 6, 140, 31); //se crea su image Renderer
	useButton->addRenderComponent(im);
	useButton->setPosition(Vector2D{ 548*relacion.first, 449*relacion.second }); //posiciones random de prueba
	useButton->setWidth(140*relacion.first);
	useButton->setHeight(31*relacion.second);
	stage.push_back(useButton); //se pushea

	Boton* swapButton = new Boton(app, swap, this, "swap"); //nuevo Boton
	RenderComponent* im2 = new AnimationRenderer(app->getResources()->getImageTexture(Resources::BotonSwap), swapButton->getAnimations(), 4, 6, 140, 31); //se crea su image Renderer
	swapButton->addRenderComponent(im2);
	swapButton->setPosition(Vector2D{ 548*relacion.first, 480*relacion.second }); //posiciones random de prueba
	swapButton->setWidth(140*relacion.first);
	swapButton->setHeight(31*relacion.second);
	stage.push_back(swapButton); //se pushea

	stage.push_back(inventarioHud);
	//-------------ConstructoraToGrandeLoko(hay q hacerla m�s peque�ita)------------------------
}

void Inventory::handleEvent(SDL_Event& event) {
	list<CasillaInventario*>::iterator it;
	for (it = inventario->getBegin(); it != inventario->getEnd(); it++) { //recorre la lista de objetos
		if ((*it)->pulsacion(event, (int)marca->getWidth(), (int)marca->getHeight())) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
			if (bswap) {
				bswap = false;
				marca->setTexture(0, app->getResources()->getImageTexture(Resources::InvMarca));
				inventario->swap((*it), selected);
			}
			selected = (*it);
			marca->setPosition((*it)->getPosition() + Vector2D((*it)->getWidth() / 2, (*it)->getHeight() / 2)
				- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear adem�s nuevos objetos para que se muestren por
			//pantalla (una imagen, la descripci�n, botones...)
			muestraDescripcion(); //se muestra 
		}
	}
	
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_i) {
			app->getStateMachine()->popState();
		}
	}
	else {
		GameState::handleEvent(event); //handleEvent del estado, el cual llama al handleInput de todos los GOs de la lista --> componentes normales
	}	
}

void Inventory::render() {
	if (previousState != nullptr) previousState->render();
	GameState::render(); //se llama a los componentes "Render" de todos los objetos de la lista del inventario
	if (selected != nullptr){
		Texture fuente(app->getRenderer(), selected->getDescription(), *f, colorFuente); //fuente din�mica
		fuente.render(app->getRenderer(), (int)(inventarioHud->getWidth() - inventarioHud->getWidth() / 16), (int)(inventarioHud->getHeight() / 1.5)); //se llama al render de la fuente Din�mica
	}
}

void Inventory::muestraDescripcion() {
	copia->setTexture(0, selected->getTexture(0));
}

void Inventory::swap(GameState* state){
	static_cast<Inventory*>(state)->bswap = true;
	static_cast<Inventory*>(state)->marca->setTexture(0, static_cast<Inventory*>(state)->app->getResources()->getImageTexture(Resources::InvMarcaS));
}

void Inventory::destroy() { //destrucci�n de la memoria din�mica que se crea en este estado
	int tam = inventario->getLength();
	if (tam > numCas) tam = numCas;
	if (tam != 0){
		for (int i = 0; i < tam; i++){
			inventario->getItem(i)->setWidth(inventario->getItem(i)->getWidth() / SC->getCoef());
			inventario->getItem(i)->setHeight(inventario->getItem(i)->getHeight() / SC->getCoef());
			inventario->getItem(i)->setPosition(Vector2D(SC->getMatriz()[i].getX() - inventario->getItem(i)->getWidth() / 2,
			SC->getMatriz()[i].getY() - inventario->getItem(i)->getHeight() / 2));
		}
	}

	delete f; f = nullptr;
	delete copia; copia = nullptr;
	delete inventarioHud; inventarioHud = nullptr;
	delete marca; marca = nullptr;
}

void Inventory::usar(GameState* state) {
	Inventory* inv = dynamic_cast<Inventory*>(state);
	if (inv != nullptr) { //comprobamos que sea el inventario por si acaso
		MainCharacter* aux = dynamic_cast<MainCharacter*>(inv->getPreviousState()->getStage()->front()); //si lo es, se obtiene el primer elemento de stage (el personaje)
		if (aux != nullptr && inv->selected != nullptr) {
			aux->setCurrenTag(inv->getLastClicked()->getTag()); //se cambia la current tag
			inv->app->getStateMachine()->popState(); //se popea el estado
			aux->getShortcut()->recorreEInicia(aux->getShortcut()->getCoef());
		}
	}
}