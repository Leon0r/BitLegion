#pragma once
#include "ClickeableGO.h"
#include "Conversacion.h"
class GOConversational :
	public ClickeableGO
{
public:
	GOConversational();
	~GOConversational();
	GOConversational(SDLApp* game, int x, int y, int w, int h, Texture* texture, string convoName) : ClickeableGO(game, x, y, w, h, texture) {
		convo = new Conversacion(app);
		convo->loadConversation(convoName);
	};
	virtual void saveToJson(json& j) {};
private:
	virtual void act();
	virtual void secondAct() {};
	bool inconversation = false;
	Conversacion* convo = nullptr;
};

