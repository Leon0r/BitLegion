#pragma once
#include "ClickeableGO.h"
#include "Conversacion.h"
class GOConversational :
	public ClickeableGO
{
public:
	GOConversational();
	~GOConversational();
	GOConversational(SDLApp* game, int x, int y, int w, int h, Texture* texture, string convoName) : ClickeableGO(game, x, y, w, h, texture), convoName_(convoName) {
		convo = new Conversacion(app);
		convo->loadConversation(convoName);
	};
	virtual void saveToJson(json& j) {
		json aux; Entity::saveToJson(aux);
		aux["convoName"] = convoName_; j["GOConversational"].push_back(aux);
	};
protected:
	virtual void act();
	virtual void secondAct() {};
	bool inconversation = false;
	string convoName_;
	Conversacion* convo = nullptr;
};

