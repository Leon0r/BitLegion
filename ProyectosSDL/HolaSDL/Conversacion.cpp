#include "Conversacion.h"
#include "SDLApp.h"

Conversacion::Conversacion(SDLApp* game) :GameObject(game)
{
	f = new Font("..//images/fuente2.ttf", tamanyoFuente);
}


Conversacion::~Conversacion()
{
}

void Conversacion::escribir(){
	vector<string> escribir = dialogo[nodoActual]->getTexto();

	string texto;
	if (escribir.size() == 1)
		texto = escribir[0];
	else if (escribir.size() <= 4){
		texto = escribir[0];	// Escribe la primera opción en el primer espacio del bucle
		for (int i = 1; i < escribir.size(); i++){
			texto = texto + "\n" + escribir[i];		//Escribe el resto de opciones con saltos de linea
		}
	}
	else{
		texto = escribir[grupoOps * 3];
		for (int i = grupoOps+1; i < 2; i++){
			if (escribir.size() >= i)
				texto = texto + "\n" + escribir[i];		//Escribe el resto de opciones con saltos de linea
			else
				texto = texto + "\n";
		}
		texto = texto + "\n Más opciones";
	}


	Texture fuente(app->getRenderer(), escribir , *f, colorFuente); //fuente dinámica
	fuente.render(app->getRenderer(), { x, y, w, h });
	//MAGIA NEGRA PA QUE ESCRIBA
}

void Conversacion::handleInput(Uint32 time, const SDL_Event& event){
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
				nodoActual = dialogo[nodoActual]->getSiguiente();
			}
			else{
				

				//COMPROBAR OPCIONES Y COSAS DE ESAS LOL



			}




		}
	}
}
void Conversacion::update(Uint32 time){
	//ANIMACIONES GUAYS
}
void Conversacion::render(Uint32 time){
	escribir();
	//???????????? creo que solo eso
}