#pragma once
#include "ClickeableGO.h"
#include "Conversacion.h"
class GOConversational :
	public ClickeableGO
{
public:
	GOConversational();
	~GOConversational();
	GOConversational(SDLApp* game, int x, int y, int w, int h, Texture* texture) : ClickeableGO(game, x, y, w, h, texture) {
		convo = new Conversacion(app);
		convo->ConversacionDePrueba();
	};
private:
	virtual void render(Uint32 time);
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void act();
	virtual void secondAct() {};
	virtual void saveToJson(json& j) {};
	bool inconversation = false;
	Conversacion* convo = nullptr;
};

