#pragma once
#include <string>
#include <iostream>
#include <vector>

enum personajes{ Alena, Ander, Jeffa, Extras };
enum emociones{ normal, especial, sorpresa, enfado, triste, feliz };

using namespace std;

class NodoDialogo
{
public:
	NodoDialogo();
	virtual ~NodoDialogo();

	struct opciones{
		int nodoApuntado;
		string texto;
	};

	vector<string> getTexto();
	int getSiguiente(int opcion = -1);
	int getNumOpciones(){return numOpciones;}
	emociones getEmo(){return emo;}
	personajes getPj(){return pj;}

private:
	int numNodo;
	int nodoSig;
	vector<string> texto = { "" };
	int numOpciones;
	vector<opciones> respuestas;
	personajes pj;
	emociones emo;
};

