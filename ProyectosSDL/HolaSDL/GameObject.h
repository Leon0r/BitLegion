#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Vector2D.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

protected:
	//SDLGame* game_; // pointer to the game

	bool active_;   // indicates if the object is active

	double width_;  // width
	double height_; // height

	Vector2D position_; // position
	Vector2D direction_; // angle in degrees (0) is considered facing left
	Vector2D velocity_; // direction

};
#endif /* GAMEOBJECT_H_ */

