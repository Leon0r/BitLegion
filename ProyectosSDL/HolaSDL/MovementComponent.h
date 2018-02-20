#pragma once
#include "PhysicsComponent.h"

//componente de movimiento, es un componente de fisicas
class MovementComponent : public PhysicsComponent {
public:
	MovementComponent() {}
	~MovementComponent() {}

	//actualizamos la logica del personaje
	virtual void update(GameObject* o, Uint32 time);

	//controla que el personaje no salga de la pantalla
	void windowBounces(GameObject* o, double& x, double& y, Vector2D& velocity);
};

