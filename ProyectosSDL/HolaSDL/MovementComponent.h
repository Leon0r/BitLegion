#pragma once
#include "PhysicsComponent.h"
#include <list>

using namespace std;

//componente de movimiento, es un componente de fisicas
class MovementComponent : public PhysicsComponent {

protected:
	list<GameObject*>* collisions;
	list<GameObject*>::iterator it;
	int sceneWidth = 0, sceneHeight = 0, scenePosX = 0, scenePosY = 0;
public:
	MovementComponent() {}
	MovementComponent(list<GameObject*>* colisiones): collisions(colisiones) {}
	~MovementComponent() {}

	//actualizamos la logica del personaje
	virtual void update(GameObject* o, Uint32 time);

	//controla que el personaje no salga de la pantalla
	void windowBounces(GameObject* o, double& x, double& y, Vector2D& velocity);

	void collideObjects(GameObject* o, double& x, double& y, Vector2D& velocity);

	//maincharacter le da el tama�o de la nueva escena cada vez que esta cambia
	void setSceneTam(double w, double h, double x, double y) {
		sceneWidth = w;
		sceneHeight = h;
		scenePosX = x;
		scenePosY = y;
	}
};

