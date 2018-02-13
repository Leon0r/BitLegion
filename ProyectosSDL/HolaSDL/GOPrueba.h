#pragma once
#include "GameObject.h"
#include <iostream>
class GOPrueba: public GameObject
{
public:
	char kk;
	GOPrueba(char kk) : GameObject(), kk(kk) {};
	virtual void update() { std::cout << kk; };
	virtual void render() {};
	virtual bool handleEvent(SDL_Event& e) { return false; };

	~GOPrueba();
};

