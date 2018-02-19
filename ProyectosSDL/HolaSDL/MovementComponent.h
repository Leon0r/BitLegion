#pragma once
#include "PhysicsComponent.h"
#include <list>

using namespace std;

//componente de movimiento, es un componente de fisicas
class MovementComponent : public PhysicsComponent {

protected:
	list<GameObject*> collisions;
	list<GameObject*>::iterator it;

public:
	MovementComponent(list<GameObject*> colisiones): collisions(colisiones) {}
	~MovementComponent() {}

	//actualizamos la logica del personaje
	virtual void update(GameObject* o, Uint32 time);

	//controla que el personaje no salga de la pantalla
	bool windowBounces(GameObject* o, double& x, double& y, Vector2D& velocity);

	bool collideObjects(GameObject* o, Vector2D& velocity);
};

