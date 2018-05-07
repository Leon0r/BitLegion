#pragma once
#include "GOConversational.h"
class AutoConversational :
	public GOConversational
{
public:
	AutoConversational(SDLApp* game, int x, int y, int w, int h, Texture* texture, string convoName) : GOConversational(game, x, y, w, h, texture, convoName) {};
	AutoConversational();
	~AutoConversational();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void saveToJson(json& j) {
		json aux; Entity::saveToJson(aux);
		aux["convoName"] = convoName_; j["AutoGOConversational"].push_back(aux);
	};
};

