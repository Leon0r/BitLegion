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
	"..//images/vater.png", "..//images/lavaboDucha.png", "..//images/bano.png", "..//images/escena2caso1.png", 
	"..//images/mesillapasillo.png","..//images/relojpasillo.png", "..//images/puertaCasaAlena.png", "..//images/flechaTransicion.png",
	"..//images/flechaTransicionDer.png", "..//images/flechaTransicionIzq.png", "..//images/llavePisoPuzzle.png", "..//images/casillaPuzzleV.png", 
	"..//images/botonPuzzle.png" , "..//images/PuzzleHud.png" , "..//images/botonReiniciar.png", "..//images/casillaPuzzleBloq.png", "..//images/casillaPuzzleDestroy.png",
	"..//images/escena4caso1.png", "..//images/moto.png", "..//images/escena3caso1.png", "..//images/muebleentrada.png", "..//images/macetaentrada.png", "..//images/puertaentrada.png",
	"..//images/colisionableAux.png" , "..//images/LuzApagada.png", "..//images/LuzEncendida.png", "..//images/Barras.png", "..//images/BarraCarga.png", "..//images/ondas.png",
	"..//images/LucesHud.png", "..//images/TextoPixel.png", "..//images/BarridoBotella.png", "..//images/hidroqueno.png", "..//images/escena5caso1.png",
	"..//images/llaveCoche.png", "..//images/llaveMoto.png", "..//images/rotulador.png", "..//images/ordenadorAlena.png", "..//images/vecinaAbuela.png", "..//images/vecinoPerro.png",
	"..//images/bin.png", "..//images/desk.png", "..//images/cooler.png", "..//images/escena6Caso1.png", "..//images/vecinaNinya.png", "..//images/companyero1.png", 
	"..//images/companyero2.png", "..//images/companyero3.png", "..//images/ninaCompanyera.png", "..//images/desk2.png", "..//images/desk3.png", "..//images/bolsaCafe.png",
	"..//images/plaza.png", "..//images/escena7caso1.png", "..//images/planta.png", "..//images/lockerNotsave.png",  "..//images/lockersave.png" };


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



/*
<<<<<<< HEAD
"..//images/botonPuzzle.png" , "..//images/PuzzleHud.png" , "..//images/botonReiniciar.png", "..//images/casillaPuzzleBloq.png", "..//images/casillaPuzzleDestroy.png",
"..//images/escena4caso1.png", "..//images/moto.png", "..//images/escena3caso1.png", "..//images/muebleentrada.png", "..//images/macetaentrada.png", "..//images/puertaentrada.png",
"..//images/colisionableAux.png" };
=======
"..//images/botonPuzzle.png", "..//images/LuzApagada.png", "..//images/LuzEncendida.png", "..//images/Barras.png", "..//images/BarraCarga.png", "..//images/ondas.png",
"..//images/LucesHud.png", "..//images/TextoPixel.png", "..//images/BarridoBotella.png"  };
>>>>>>> Puzzle-2+-basura
*/