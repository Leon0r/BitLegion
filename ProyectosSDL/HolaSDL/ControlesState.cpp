#include "ControlesState.h"
#include <fstream>
#include "ImageRenderer.h"

vector<Entity*> ControlesState::entities; 

ControlesState::ControlesState()
{
}


ControlesState::~ControlesState()
{
	stage.clear();
}

void ControlesState::readFromJson()
{
	if (entities.empty()) { //si la variable static está vacia...
		string name;
		name = "..\\Controles\\controles.json";

		std::ifstream i(name);

		if (i.is_open()) { // Para que no intente abrir archivos que no existen

			json j;
			i >> j;

			for (unsigned int i = 0; i < j["imagenes"].size(); i++) {
				entities.push_back(new Entity(app));

				Entity* aux = entities.back();

				if (!j["imagenes"][i]["w"].is_null())
					aux->setWidth(j["imagenes"][i]["w"]);
				else
					aux->setWidth(app->getWindowWidth());

				if (!j["imagenes"][i]["h"].is_null())
					aux->setHeight(j["imagenes"][i]["h"]);
				else
					aux->setHeight(app->getWindowHeight());

				if (!j["imagenes"][i]["y"].is_null() && !j["imagenes"][i]["x"].is_null())
					aux->setPosition(Vector2D(j["imagenes"][i]["x"], j["imagenes"][i]["y"]));

				bool animated = false;

				if (!j["imagenes"][i]["animated"].is_null()) {
					if (j["imagenes"][i]["animated"]) {
						animated = true;
						if (!j["imagenes"][i]["frames"].is_null() && !j["imagenes"][i]["loop"].is_null() && !j["imagenes"][i]["vel"].is_null())
							aux->addAnim("Loop", j["imagenes"][i]["frames"], j["imagenes"][i]["loop"], -1, j["imagenes"][i]["vel"]);
					}
				}

				if (animated) {
					if (!j["imagenes"][i]["numText"].is_null() && !j["imagenes"][i]["cols"].is_null() && !j["imagenes"][i]["fils"].is_null() && !j["imagenes"][i]["frameWidth"].is_null() && !j["imagenes"][i]["frameHeight"].is_null())
						aux->addRenderComponent(new AnimationRenderer(app->getResources()->getImageTexture(Resources::ImageId(j["imagenes"][i]["numText"])), aux->getAnimations(), j["imagenes"][i]["cols"], j["imagenes"][i]["fils"], j["imagenes"][i]["frameWidth"], j["imagenes"][i]["frameHeight"]));
				}
				else {
					if (!j["imagenes"][i]["numText"].is_null())
						aux->addRenderComponent(new ImageRenderer(app->getResources()->getImageTexture(Resources::ImageId(j["imagenes"][i]["numText"]))));
				}

				stage.push_back(aux);
			}
		}
	}
	else { //si no, simplemente pusheamos
		for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); it++) {
			stage.push_back(*it);
		}
	}
}
