#include "NodoDialogo.h"


NodoDialogo::NodoDialogo()
{
}


NodoDialogo::~NodoDialogo()
{
}

int NodoDialogo::getSiguiente(int opcion){

	if (opcion = -1)
		return nodoSig;
	else
		return respuestas[opcion].nodoApuntado;
}


// Si no hay opciones devuelve un string con el texto a mostrar
// Las opciones se devuelven cada una en un string
vector<string> NodoDialogo::getTexto(){
	
	if (texto[0] != "")
		return texto;
	else{
		vector<string> salida;
		int n = 0;
		for each (opciones op in respuestas)
		{
			salida[n] = op.texto;
			n++;
		}
		return salida;
	}
}