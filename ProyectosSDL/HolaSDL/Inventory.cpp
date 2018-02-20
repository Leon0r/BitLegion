#include "Inventory.h"
#include "Boton.h"
#include "Font.h"
//#include "GameStateMachine.h"

Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario) {
	matriz.resize(numCas*numCas);
	for (int i = 0; i < numCas; i++) {//inicializacion de la matriz de casillas
		for (int j = 0; j < numCas; j++) {
			matriz[i*numCas+j] = Vector2D(espaciado*j + 150, espaciado*i + 125);
		}
	}
	//inicializacion de texturas (en el futuro se hara una lista)
	txt2 = new Texture();
	txt2->loadFromImg(app->getRenderer(), "..//images/Inventario.png");
	txt3 = new Texture();
	txt3->loadFromImg(app->getRenderer(), "..//images/InvMarca.png");
	txt4 = new Texture();
	txt4->loadFromImg(app->getRenderer(), "..//images/boton.png");
	txt5 = new Texture();
	txt5->loadFromImg(app->getRenderer(), "..//images/InvMarcaS.png");

	f = new Font("..//images/fuente2.ttf", tamanyoFuente);
	imagen = new ImageRenderer(txt2);

	//imagen del inventario
	inventarioHud->addRenderComponent(imagen);
	inventarioHud->setHeight(450);
	inventarioHud->setWidth(600);
	inventarioHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventarioHud->getWidth()/2, 
		app->getWindowHeight() / 2 - inventarioHud->getHeight()/2)));

	//marcador de objeto seleccionado
	imagen = new ImageRenderer(txt3);
	marca->addRenderComponent(imagen);
	marca->setHeight(87);
	marca->setWidth(87);
	//se pushea todo a la lista de objetos
	stage.push_back(inventarioHud);
	inventario->pushObjects(stage);

	if (inventario->getLength() != 0) {//si hay algun objeto en la lista de objetos
		stage.push_back(marca); //se marca el primero de ellos
		marca->setPosition(inventario->getItem(0)->getPosition() +
			Vector2D(inventario->getItem(0)->getWidth() / 2, inventario->getItem(0)->getHeight() / 2)
			- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2));
		muestraDescripcion(inventario->getItem(0));
	}

	//--------------------Pruebas Botones ----------------------
	Boton* useButton = new Boton(app, usar, this, "use"); //nuevo Boton
	ImageRenderer* im = new ImageRenderer(txt4); //se crea su image Renderer
	useButton->addRenderComponent(im);
	useButton->setPosition(Vector2D{ 547, 450 }); //posiciones random de prueba
	useButton->setWidth(txt4->getWidth());
	useButton->setHeight(txt4->getHeight());
	stage.push_back(useButton); //se pushea
	Boton* swapButton = new Boton(app, usar, this, "swap"); //nuevo Boton
	swapButton->addRenderComponent(im);
	swapButton->setPosition(Vector2D{ 547, 480 }); //posiciones random de prueba
	swapButton->setWidth(txt4->getWidth());
	swapButton->setHeight(txt4->getHeight());
	stage.push_back(swapButton); //se pushea
	//-------------ConstructoraToGrandeLoko------------------------
}

void Inventory::handleEvent(SDL_Event& event) {
	for (GameObject* it : stage) { //recorre la lista de objetos
		CasillaInventario* aux = dynamic_cast<CasillaInventario*>(it); //si aux == nullptr --> it no es de tipo CasillaInventario
		if (aux != nullptr) { //si aux != nullptr ---> it es de tipo CasillaInventario
			if (aux->pulsacion(event)) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
				marca->setPosition(aux->getPosition() + Vector2D(aux->getWidth() / 2, aux->getHeight() / 2)
					- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear adem�s nuevos objetos para que se muestren por
				//pantalla (una imagen, la descripci�n, botones...)
				muestraDescripcion(aux); //se muestra 
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
	Texture fuente(app->getRenderer(), copia->getDescription(), *f, colorFuente); //fuente din�mica
	fuente.render(app->getRenderer(), inventarioHud->getWidth() - inventarioHud->getWidth()/16, inventarioHud->getHeight()/1.5); //se llama al render de la fuente Din�mica
}

void Inventory::muestraDescripcion(CasillaInventario* aux) {
	*copia = *aux; //crea una copia del objeto a mostrar
	copia->setHeight(copia->getHeight()*2);//lo agranda
	copia->setWidth(copia->getWidth()*2);
	copia->setPosition(Vector2D(618 - copia->getWidth()/2, 149 - copia->getHeight()/2));
	stage.push_back(copia);	//lo pushea a la lista de objetos
}

void Inventory::destroy() { //destrucci�n de la memoria din�mica que se crea en este estado
	delete txt2; txt2 = nullptr;
	delete txt3; txt3 = nullptr;
	delete txt4; txt4 = nullptr;
	delete f; f = nullptr;
	delete copia; copia = nullptr;
	delete imagen; imagen = nullptr;
	delete inventarioHud; inventarioHud = nullptr;
	delete marca; marca = nullptr;
	//GameState::~GameState(); destruir�a tambien la lista de objectList --> da problemas, todo lo dem�s se destruye
}