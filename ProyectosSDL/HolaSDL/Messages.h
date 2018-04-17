#pragma once
// Archivo solo con el enum de mensajes posibles entre observer/observable
enum Messages {
	In_Menu,
	Game_Start,
	Game_End,
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
	Button_Press
};

struct Mensaje{
	Mensaje(Messages id) : id_(id) {}
	Messages id_;
};

struct MensajePosicionMatriz: Mensaje //mensaje que devuelve la posicion de la matriz (puzzles)
{
	MensajePosicionMatriz(Messages id, std::pair<const int, const int> pos) : Mensaje(id), pos_(pos) {}
	std::pair<const int, const int> pos_;
};
