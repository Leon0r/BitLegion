#include "Conversacion.h"
#include "SDLApp.h"

Conversacion::Conversacion(SDLApp* game) :GameObject(game)
{
	f = new Font("..//images/fuente2.ttf", tamanyoFuenteConv);
}


Conversacion::~Conversacion()
{
}

void Conversacion::escribir(){
	dialogo[nodoActual];
	vector<string> escribir = dialogo[nodoActual]->getTexto();

	int numLineas = escribir.size();

	if (dialogo[nodoActual]->getNumOpciones() > 3){

		for (int i = grupoOps * 3; i < grupoOps * 3 + 3; i++){
			if (i < dialogo[nodoActual]->getNumOpciones()){
				Texture fuente(app->getRenderer(), escribir[i], *f, colorFuenteConv); //fuente dinámica
				fuente.render(app->getRenderer(), { x, y + i%3 * h / 4 + 2, w, h / 4 });
			}
		}

		Texture fuente(app->getRenderer(), "Mas opciones                          ", *f, colorFuenteConv); //fuente dinámica
		fuente.render(app->getRenderer(), { x, y + 3 * h / 4 + 2, w, h / 4 });


	}



	else{
		grupoOps = 0;
		for (int i = 0; i < numLineas; i++){
			Texture fuente(app->getRenderer(), escribir[i], *f, colorFuenteConv); //fuente dinámica
			fuente.render(app->getRenderer(), { x, y + i * h / 4 + 2, w, h / 4 });
		}
	}
	
	//MAGIA NEGRA PA QUE ESCRIBA
}

void Conversacion::handleInput(Uint32 time, const SDL_Event& event){
	if (enconversacion){


		if (event.type == SDL_MOUSEBUTTONDOWN) {

			SDL_Point p;
			p.x = event.button.x;
			p.y = event.button.y;

			SDL_Rect r;
			r.x = x;
			r.y = y;
			r.h = h;
			r.w = w;

			//Si el evento es click de raton creamos un punto en la posicion del click, un rectangulo con la forma y posicion del boton
			//y comprobamos si el punto donde se ha clickado está dentro del rectangulo
			if (SDL_PointInRect(&p, &r)) {

				if (dialogo[nodoActual]->getNumOpciones() <= 0){
					if (nodoActual < dialogo.size() - 1)
						nodoActual = dialogo[nodoActual]->getSiguiente();
				}
				else{

					vector<opciones> respuestas = dialogo[nodoActual]->getOpciones();

					r.y = y;
					r.h = h / 4;
					if (SDL_PointInRect(&p, &r)){
						nodoActual = respuestas[grupoOps * 3].nodoApuntado;
					}
					else if (grupoOps * 3 + 1 < dialogo[nodoActual]->getNumOpciones()){
						r.y = y + h / 4;
						if (SDL_PointInRect(&p, &r)){
							nodoActual = respuestas[grupoOps * 3 + 1].nodoApuntado;
						}
						else if (grupoOps * 3 + 2 < dialogo[nodoActual]->getNumOpciones()){
							r.y = y + 2 * h / 4 + 2;
							if (SDL_PointInRect(&p, &r)){
								nodoActual = respuestas[grupoOps * 3 + 2].nodoApuntado;
							}

							//ULTIMA OPCION: Más opciones
						}
					}
				}

				if (nodoActual == -1)
					enconversacion = false;
				else if (dialogo[nodoActual]->getNumOpciones() > 3){
						r.y = y + 3 * h / 4 + 2;
						if (SDL_PointInRect(&p, &r)){
							//Si la ultima opcion es Más opciones, pasa al siguiente grupo o vuelve al primero
							if (grupoOps < dialogo[nodoActual]->getNumOpciones() / 3)
								grupoOps++;
							else
								grupoOps = 0;
						}

					}


			}
		}
	}
}
void Conversacion::update(Uint32 time){
	//ANIMACIONES GUAYS
}
void Conversacion::render(Uint32 time){
	if(enconversacion)
		escribir();
}

void Conversacion::ConversacionDePrueba(){


	vector<string> text = { "012345678901234567890123456789012345678901234567890123456789", "qwertyuiopasdfghjklñqwertyuiopasdfghjklñ", "qwertyuiopasdfghjklñ" };
	vector<opciones> ops;
	NodoDialogo* nodo1 = new NodoDialogo(0, 1, text, -1, ops, Alena, feliz);
	text = { "Odio mi vida" };
	NodoDialogo* nodo2 = new NodoDialogo(1, 2, text, -1, ops, Alena, triste);
	text = { "" };
	ops = { { 0, "Repite esto" }, { -1, "¿Que acabas de decir?" }, { 3, "Opciones de 3" }, { 0, "Opciones ricas jejejeje" }, { 1, "Di otra vez eso de que odias tu vida" } };
	NodoDialogo* nodo3 = new NodoDialogo(2, 3, text, 5, ops, Alena, especial);
	ops = { { 0, "1                                   " }, { -1, "2                                 " }, { 1, "3                               " } };
	NodoDialogo* nodo4 = new NodoDialogo(2, 3, text, 3, ops, Alena, especial);

	dialogo.push_back(nodo1);
	dialogo.push_back(nodo2);
	dialogo.push_back(nodo3);
	dialogo.push_back(nodo4);
	nodoActual = 0;
}