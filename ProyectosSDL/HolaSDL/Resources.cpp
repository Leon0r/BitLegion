#include <tuple>
#include "Resources.h"
#include "SDLApp.h"

std::vector<std::string> Resources::imageFiles_ { "..//images/AlenaSpriteSheet.png",  //"..//images/Alena.png",
		"..//images/bit legion_logo.png", "..//images/boton.png", "..//images/BotonSwapSheet.png",
		"..//images/BotonUsarSheet.png", "..//images/ImgTest.png", "..//images/InventarioAnimSheet.png",
		"..//images/InvMarca.png", "..//images/InvMarcaS.png", "..//images/shortcut.png",
	"..//images/escena1caso1.png", "..//images/cama.png", "..//images/mesa.png", "..//images/cocina.png", 
	"..//images/puertaCutre.png", "..//images/llaveCutre.png", "..//images/bolsaCoca.png", "..//images/bolsaVacia.png",
	"..//images/botellaVodka.png", "..//images/cuaderno.png", "..//images/fotoNoviaMuerto.png",
	"..//images/llaveHotel.png", "..//images/llavePiso.png", "..//images/movilMuerto.png", "..//images/ticketCompra.png",
	"..//images/vater.png" };

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

int Resources::getPosTexture(Texture* text) const {
	int i = 0;
	bool found = false;
	while (i < numOfImageTextures_ && !found) { //encuentra el numero de la textura correspondiente (nos vale para guardar y cargar escenas)
		if (text == imageTextures_[i]) {
			found = true;
		}
		else {
			i++;
		}
	}
	return i;
}