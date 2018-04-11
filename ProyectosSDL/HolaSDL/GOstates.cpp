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

//BORRAR ESTO AL PASARTE EL PUZZLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//LISTA ESCENAS TIENE QUE SER CLASE PADRE PUZZLE
//QUITAR ESTE PUNTERO Y CAMBIARLO A PADREPUZZLE
//EL SERACHID() BAJARLO A PADREPUZZLE


//ADAPTAR EL LIGHTSOUT A LA NUEVA ESTRUCTURA

GOstates::~GOstates()
{
}

void GOstates::act() {
	app->getStateMachine()->currentState()->changeList();
	state_->searchId(); 
	this->getGame()->getStateMachine()->pushState(state_);
}

void GOstates::saveToJson(json & j){
	json aux; 
	Entity::saveToJson(aux);

	aux["type"] = jAux_["type"]; //tipo de puzzle
	aux["rotation"] = jAux_["rotation"];
	if (!jAux_["numberPuzzle"].is_null()) { aux["numberPuzzle"] = jAux_["numberPuzzle"]; } //atributos diferentes en cada puzzle... nos ahorramos excepciones raras con el isNull(); pero hay que ponerlos todos aqui ais...
	//(si se os ocurre otra forma avisad, que son las 2 de la ma�ana y ya no tiro)
	if (!jAux_["numCas"].is_null()) { aux["numCas"] = jAux_["numCas"]; }
	if (!jAux_["dificultad"].is_null()) { aux["dificultad"] = jAux_["dificultad"]; }
	if (!jAux_["numText"].is_null()) { aux["numText"] = jAux_["numText"]; }
	if (!jAux_["UnlockId"].is_null()) {	aux["UnlockId"] = jAux_["UnlockId"]; }

	j["GOState"].push_back(aux);
}