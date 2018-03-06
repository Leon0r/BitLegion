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

string NodoDialogo::getTexto(){
	if (texto != "")
		return texto;
	else{
		string salida;
		for each (opciones op in respuestas)
		{
			salida = salida + "\n" + op.texto;
		}
		return salida;
	}
}