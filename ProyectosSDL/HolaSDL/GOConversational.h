#pragma once
#include "ClickeableGO.h"
#include "Conversacion.h"
class GOConversational :
	public ClickeableGO, public Observer
{
public:
	GOConversational();
	~GOConversational();
	GOConversational(SDLApp* game, int x, int y, int w, int h, Texture* texture, string convoName, bool repeat = true) : ClickeableGO(game, x, y, w, h, texture), convoName_(convoName), repeat_(repeat) {
		convo = new Conversacion(app);
		convo->loadConversation(convoName);
	};
	virtual void saveToJson(json& j) {
		json aux; Entity::saveToJson(aux);
		aux["convoName"] = convoName_; aux["repeat"] = repeat_; j["GOConversational"].push_back(aux);
	};

	virtual void receive(Mensaje* msg);
protected:
	virtual void act();
	virtual void secondAct() {};
	bool inconversation = false;
	string convoName_;
	Conversacion* convo = nullptr;
	bool repeat_;
	bool firstTime_ = true;
};

