#include "Inventory.h"
#include "Boton.h"
#include "Font.h"
//#include "GameStateMachine.h"


Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario), selected(nullptr) {
	matriz.resize(numCas*numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
		for (int j = 0; j < numCas; j++) {
			matriz[i*numCas+j] = Vector2D(espaciado*j + 150, espaciado*i + 125);
		}
	}
	//inicializacion de texturas (en el futuro se hara una lista)
	txt1 = new Texture();
	txt1->loadFromImg(app->getRenderer(), "..//images/botonUsar.png");
	txt2 = new Texture();
	txt2->loadFromImg(app->getRenderer(), "..//images/Inventario.png");
	txt3 = new Texture();
	txt3->loadFromImg(app->getRenderer(), "..//images/InvMarca.png");
	txt4 = new Texture();
	txt4->loadFromImg(app->getRenderer(), "..//images/botonSwap.png");
	txt5 = new Texture();
	txt5->loadFromImg(app->getRenderer(), "..//images/InvMarcaS.png");

	f = new Font("..//images/fuente2.ttf", tamanyoFuente);
	imagen = new ImageRenderer(txt2);

	//imagen del inventario
	inventarioHud->addRenderComponent(imagen);
	inventarioHud->setHeight(app->getWindowHeight()*0.75);
	inventarioHud->setWidth(app->getWindowWidth()*0.75);
	inventarioHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventarioHud->getWidth()/2, 
		app->getWindowHeight() / 2 - inventarioHud->getHeight()/2)));

	for (int i = 0; i < inventario->getLength(); i++) { // se colocan los objetos en sus posiciones correspondientes
		inventario->getItem(i)->setPosition(Vector2D(matriz[i] + inventario->getItem(i)->getPosition()));
	}

	//marcador de objeto seleccionado
	imagenMarca = new ImageRenderer(txt3);
	marca->addRenderComponent(imagenMarca);
	marca->setHeight(87);
	marca->setWidth(87);
	//se pushea todo a la lista de objetos
	stage.push_back(inventarioHud);
	inventario->pushObjects(stage);

	if (inventario->getLength() != 0) {//si hay algun objeto en la lista de objetos
		copia = new Entity(app);
		selected = inventario->getItem(0); //inicializamos el primero como seleccionado
		selectedTexture = new ImageRenderer(selected->getTexture(0));
		copia->addRenderComponent(selectedTexture);
		copia->setHeight(selected->getHeight() * 2);//lo agranda
		copia->setWidth(selected->getWidth() * 2);
		copia->setPosition(Vector2D(618 - copia->getWidth() / 2, 149 - copia->getHeight() / 2));
		stage.push_back(copia);	//lo pushea a la lista de objetos
		stage.push_back(marca); //se marca el primero de ellos
		marca->setPosition(inventario->getItem(0)->getPosition() +
			Vector2D(inventario->getItem(0)->getWidth() / 2, inventario->getItem(0)->getHeight() / 2)
			- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2));
		muestraDescripcion();
	}

	//--------------------Pruebas Botones ----------------------
	Boton* useButton = new Boton(app, usar, this, "use"); //nuevo Boton
	ImageRenderer* im = new ImageRenderer(txt1); //se crea su image Renderer
	useButton->addRenderComponent(im);
	useButton->setPosition(Vector2D{ 547, 450 }); //posiciones random de prueba
	useButton->setWidth(txt4->getWidth());
	useButton->setHeight(txt4->getHeight());
	stage.push_back(useButton); //se pushea
	ImageRenderer* im2 = new ImageRenderer(txt4); //se crea su image Renderer
	Boton* swapButton = new Boton(app, swap, this, "swap"); //nuevo Boton
	swapButton->addRenderComponent(im2);
	swapButton->setPosition(Vector2D{ 547, 480 }); //posiciones random de prueba
	swapButton->setWidth(txt4->getWidth());
	swapButton->setHeight(txt4->getHeight());
	stage.push_back(swapButton); //se pushea
	//-------------ConstructoraToGrandeLoko------------------------
}

void Inventory::handleEvent(SDL_Event& event) {
	list<GameObject*>::iterator it;
	for (it = stage.begin(); it != stage.end(); it++) { //recorre la lista de objetos
		CasillaInventario* aux = dynamic_cast<CasillaInventario*>(*it); //si aux == nullptr --> it no es de tipo CasillaInventario
		if (aux != nullptr) { //si aux != nullptr ---> it es de tipo CasillaInventario
			if (aux->pulsacion(event, marca->getHeight())) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
				if (bswap) {
					bswap = false;
					marca->setTexture(0, txt3);
					inventario->swap(aux, selected);
				}
				selected = aux;
				marca->setPosition(aux->getPosition() + Vector2D(aux->getWidth() / 2, aux->getHeight() / 2)
					- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear además nuevos objetos para que se muestren por
				//pantalla (una imagen, la descripción, botones...)
				muestraDescripcion(); //se muestra 
			}
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
	GameState::render(); //se llama a los componentes "Render" de todos los objetos de la lista del inventario
	if (selected != nullptr){
		Texture fuente(app->getRenderer(), selected->getDescription(), *f, colorFuente); //fuente dinámica
		fuente.render(app->getRenderer(), inventarioHud->getWidth() - inventarioHud->getWidth() / 16, inventarioHud->getHeight() / 1.5); //se llama al render de la fuente Dinámica
	}
}

void Inventory::muestraDescripcion() {
	copia->setTexture(0, selected->getTexture(0));
}

void Inventory::swap(GameState* state){
	/*static_cast<Inventory*>(state)->inventario->swap(static_cast<Inventory*>(state)->inventario->getItem(0),
		static_cast<Inventory*>(state)->inventario->getItem(1));*/
	static_cast<Inventory*>(state)->bswap = true;
	static_cast<Inventory*>(state)->marca->setTexture(0, static_cast<Inventory*>(state)->txt5);

}

void Inventory::destroy() { //destrucción de la memoria dinámica que se crea en este estado
	for (int i = 0; i < inventario->getLength(); i++) {// se recolocan los objetos en su posicion inicial para que al volver a sercreados se coloquen bien
		inventario->getItem(i)->setPosition(Vector2D(inventario->getItem(i)->getPosition() - matriz[i]));
	}
	delete txt2; txt2 = nullptr;
	delete txt3; txt3 = nullptr;
	delete txt4; txt4 = nullptr;
	delete f; f = nullptr;
	delete copia; copia = nullptr;
	delete imagen; imagen = nullptr;
	delete inventarioHud; inventarioHud = nullptr;
	delete marca; marca = nullptr;
	//GameState::~GameState(); destruiría tambien la lista de objectList --> da problemas, todo lo demás se destruye
}