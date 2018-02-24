#include <tuple>
#include "Resources.h"
#include "SDLApp.h"

std::vector<std::string> Resources::imageFiles_ { "images/Alena.png",
		"images/bit legion_logo.png", "images/boton.png", "images/botonSwap.png",
		"images/botonUsar.png", "images/ImgTest.png", "images/Inventario.png",
		"images/InvMarca.png", "images/InvMarcaS.png" };

#include <iostream>

Resources::Resources(SDLApp* game) :
		game_(game), numOfImageTextures_(0), imageTextures_(nullptr) {

	setImageTextures(imageFiles_);
}

Resources::~Resources() {
	closeImageTextures();
}

void Resources::setImageTextures(std::vector<std::string> textures) {
	closeImageTextures();
	numOfImageTextures_ = textures.size();
	imageTextures_ = new Texture*[numOfImageTextures_];
	for (int i = 0; i < numOfImageTextures_; i++) {
		imageTextures_[i] = new Texture(game_->getRenderer(), textures[i]);
	}
}

void Resources::closeImageTextures() {
	for (int i = 0; i < numOfImageTextures_; i++) {
		if (imageTextures_[i] != nullptr) {
			delete imageTextures_[i];
		}
	}
	delete[] imageTextures_;
	numOfImageTextures_ = 0;

}

Texture* Resources::getImageTexture(ImageId i) const {
	if (i < numOfImageTextures_)
		return imageTextures_[i];
	else
		return nullptr;
}