#pragma once
#include "InputComponent.h"

class Entity;
class FeedbackCursorInputComponent :
	public InputComponent
{
private:
	Entity* cursor;
	bool isMe = false;
public:
	FeedbackCursorInputComponent();
	FeedbackCursorInputComponent(Entity* cursor): cursor(cursor) {}
	virtual ~FeedbackCursorInputComponent();
	virtual void FeedbackCursorInputComponent::handleInput(GameObject * o, Uint32 time, const SDL_Event & event);
};

