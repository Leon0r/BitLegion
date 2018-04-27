#pragma once
// Archivo solo con el enum de mensajes posibles entre observer/observable
enum Messages {
	Ch_Left,
	Ch_Right,
	Ch_TakeObj,
	StopRight,
	StopLeft,
	Moving,
	MouseStop,
	MouseMoving,
	CambioEscena,
	LuzInvertida,
	WinPuzzle,
	ChangeScene,
	MensajeVacio,
	DialogoAcabado,
	Stop,
	SetZBufferPlayState,
	AbreInventario,
	Pausa
};

struct Mensaje{
	Mensaje(Messages id) : id_(id) {};
	Mensaje(): id_(MensajeVacio){};
	Messages id_;
};

struct MensajePosicionMatriz: Mensaje //mensaje que devuelve la posicion de la matriz (puzzles)
{
	MensajePosicionMatriz(Messages id, std::pair<const int, const int> pos) : Mensaje(id), pos_(pos) {}
	std::pair<const int, const int> pos_;
};

struct MensajeCambioEscenaDialogos : Mensaje 
{
	MensajeCambioEscenaDialogos(Messages id, int numScene) : Mensaje(id), numScene_(numScene) {}
	int numScene_;
};

