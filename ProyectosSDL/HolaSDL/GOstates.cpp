#include "GOstates.h"
#include "PlayState.h"
#include "MainCharacter.h"


GOstates::GOstates(SDLApp* game, int x, int y, int w, int h, Texture* texture, GameState* state, json j) : ClickeableGO(game, x, y, w, h, texture), state_(state), jAux_(j)
{
	this->delRenderComponent(render);
	addAnim("RightArrow", { 0,1,2,3 });
	addAnim("LeftArrow", { 4,5,6,7 });
	addAnim("DownArrow", { 8,9,10,11 });
	addAnim("UpArrow", { 12,13,14,15 });
	if (render != nullptr) {
		delete render;
		render = nullptr;
	}
	render = new AnimationRenderer(texture, animations, 4, 4, 60, 60);
	static_cast<AnimationRenderer*>(render)->playAnim(rotation_);
	this->addRenderComponent(render);
}


GOstates::~GOstates()
{
}

void GOstates::act() {
	app->getStateMachine()->currentState()->changeList();
	this->getGame()->getStateMachine()->pushState(state_);
}

void GOstates::saveToJson(json & j){
	json aux; 
	Entity::saveToJson(aux);

	aux["type"] = jAux_["type"]; //tipo de puzzle
	aux["rotation"] = jAux_["rotation"];
	if (!jAux_["numberPuzzle"].is_null()) { aux["numberPuzzle"] = jAux_["numberPuzzle"]; } //atributos diferentes en cada puzzle... nos ahorramos excepciones raras con el isNull();
	if (!jAux_["numCas"].is_null()) { aux["numCas"] = jAux_["numCas"]; }
	if (!jAux_["dificultad"].is_null()) { aux["dificultad"] = jAux_["dificultad"]; }

	j["GOState"].push_back(aux);
}