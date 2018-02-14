#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <SDL.h>
#include "Vector2D.h"

class SDLApp;
class GameObject
{
public:
	GameObject();
	GameObject(SDLApp* game) :app(game) {}
	virtual ~GameObject();
	virtual void render() = 0;
	virtual void update() = 0;
	virtual bool handleEvent(SDL_Event& e) = 0;

	Vector2D getPosition() { 
		return position_; 
	}

	Vector2D getVelocity() {
		return velocity_;
	}

	void setVelocity(Vector2D velocity) {
		velocity_ = velocity;
	}

	double getWidth() {
		return width_;
	}

	double getHeight() {
		return height_;
	}

protected:
	SDLApp* app;   // pointer to the game

	bool active_;   // indicates if the object is active

	double width_;  // width
	double height_; // height

	Vector2D position_; // position
	Vector2D direction_; // angle in degrees (0) is considered facing left
	Vector2D velocity_; // direction

};
#endif /* GAMEOBJECT_H_ */

