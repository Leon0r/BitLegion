#include "Inventory.h"
#include "Boton.h"
#include "Font.h"

Inventory::Inventory(SDLApp* app, ObjectList* inventario) : GameState(app), inventario(inventario) {
	int numElem = 18;
	matriz.resize(numCas*numCas);
	for (int i = 0; i < numCas; i++) {
		for (int j = 0; j < numCas; j++) {
			matriz[i*numCas+j] = Vector2D(espaciado*j + 150, espaciado*i + 125);
		}
	}
	txt = new Texture();
	txt->loadFromImg(app->getRenderer(), "..//images/Alena.png");
	txt2 = new Texture();
	txt2->loadFromImg(app->getRenderer(), "..//images/Inventario.png");
	txt3 = new Texture();
	txt3->loadFromImg(app->getRenderer(), "..//images/InvMarca.png");
	txt4 = new Texture();
	txt4->loadFromImg(app->getRenderer(), "..//images/boton.png");
	f = new Font("..//images/fuente2.ttf", tamanyoFuente);
	imagen = new ImageRenderer(txt2);
	inventarioHud->addRenderComponent(imagen);
	inventarioHud->setHeight(450);
	inventarioHud->setWidth(600);
	inventarioHud->setPosition(Vector2D(Vector2D(app->getWindowWidth() / 2 - inventarioHud->getWidth()/2, 
		app->getWindowHeight() / 2 - inventarioHud->getHeight()/2)));

	imagen = new ImageRenderer(txt3);
	marca->addRenderComponent(imagen);
	marca->setHeight(87);
	marca->setWidth(87);

	for (int i = 0; i < numElem; i++) {
		if(i < numElem/3) inventario->addItem(txt, "a", "kk" + to_string(i));
		else if (i < numElem*2/3) inventario->addItem(txt3, "b", "ak2" + to_string(i));
		else inventario->addItem(txt2, "c", "kk3" + to_string(i));
		inventario->getItem(i)->setPosition(Vector2D(matriz[i] + inventario->getItem(i)->getPosition()));
	}
	//inventario->deleteItem("b0");
	stage.push_back(inventarioHud);
	inventario->pushObjects(stage);
	if (inventario->getLength() != 0) {
		stage.push_back(marca);
		marca->setPosition(inventario->getItem(0)->getPosition() +
			Vector2D(inventario->getItem(0)->getWidth() / 2, inventario->getItem(0)->getHeight() / 2)
			- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2));
		muestraDescripcion(inventario->getItem(0));
	}

	//--------------------Pruebas Botones ----------------------
	Boton* newButton = new Boton(app, usar, this); //nuevo Boton
	ImageRenderer* im = new ImageRenderer(txt4); //se crea su image Renderer
	newButton->addRenderComponent(im);
	newButton->setPosition(Vector2D{ 400, 400 }); //posiciones random de prueba
	newButton->setWidth(50);
	newButton->setHeight(50);
	stage.push_back(newButton); //se pushea
	//-------------ConstructoraToGrandeLoko------------------------
}

void Inventory::handleEvent(SDL_Event& event) {
	for (GameObject* it : stage) { //recorre la lista de objetos
		CasillaInventario* aux = dynamic_cast<CasillaInventario*>(it); //si aux == nullptr --> it no es de tipo CasillaInventario
		if (aux != nullptr) { //si aux != nullptr ---> it es de tipo CasillaInventario
			if (aux->pulsacion(event)) { //se puede ejecutar el metodo que comprueba si ha sido clickado o no
				marca->setPosition(aux->getPosition() + Vector2D(aux->getWidth() / 2, aux->getHeight() / 2)
					- Vector2D(marca->getWidth() / 2, marca->getHeight() / 2)); // desde aqui, con aux, se puede acceder a la textura, descripcion, tag... de it y crear además nuevos objetos para que se muestren por
				//pantalla (una imagen, la descripción, botones...)
				muestraDescripcion(aux);
			}
		}
	}
	
	GameState::handleEvent(event); //handleEvent del estado, el cual llama al handleInput de todos los GOs de la lista --> componentes normales
}

void Inventory::render() {
	GameState::render(); //se llama a los componentes "Render" de todos los objetos de la lista del inventario
	Texture fuente(app->getRenderer(), copia->getDescription(), *f, colorFuente); //fuente dinámica
	fuente.render(app->getRenderer(), inventarioHud->getWidth() - inventarioHud->getWidth()/16, inventarioHud->getHeight()/1.5); //se llama al render de la fuente Dinámica
}

void Inventory::muestraDescripcion(CasillaInventario* aux) {
	*copia = *aux;
	copia->setHeight(copia->getHeight()*2);
	copia->setWidth(copia->getWidth()*2);
	copia->setPosition(Vector2D(618 - copia->getWidth()/2, 149 - copia->getHeight()/2));
	stage.push_back(copia);	
}

void Inventory::destroy() { //destrucción de la memoria dinámica que se crea en este estado
	delete txt; txt = nullptr;
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