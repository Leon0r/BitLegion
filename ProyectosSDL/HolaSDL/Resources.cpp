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
	"..//images/plaza.png", "..//images/escena7caso1.png", "..//images/planta.png", "..//images/lockerNotsave.png",  "..//images/lockersave.png",  "..//images//JeffaSpriteSheet.png",
	"..//images//GalinaNoviaMuertoSheet.png", "..//images//señoraDelBajo.png", "..//images//policia1.png", "..//images//policia2.png", "..//images//policia3.png", 
	"..//images//policia4.png", "..//images//escena8caso1.png", "..//images//perchero.png","..//images//deskD.png" };

std::vector<std::string> Resources::musicFiles_{ "..//music/initTest.mp3",
/*"sound/cheer.wav", "sound/boooo.wav"*/ };

std::vector<std::string> Resources::soundEffectFiles_{ "..//SoundFX/door.mp3",
/*"sound/paddle_hit.wav"*/ };


#include <iostream>

Resources::Resources(SDLApp* game) :
		game_(game), numOfImageTextures_(0), imageTextures_(nullptr) {

	setImageTextures(imageFiles_);
	setMusic(musicFiles_);
	//setSoundEffects(soundEffectFiles_);
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


void Resources::setMusic(std::vector<std::string> music) {
	closeMusic();
	numOfMusic_ = music.size();
	music_ = new Music*[numOfMusic_];
	for (int i = 0; i < numOfMusic_; i++) {
		music_[i] = new Music(music[i]);
	}
}

void Resources::setSoundEffects(std::vector<std::string> soundEffects) {
	closeSoundEffects();
	numOfSoundEffects_ = soundEffects.size();
	soundEffects_ = new SoundEffect*[numOfSoundEffects_];
	for (int i = 0; i < numOfSoundEffects_; i++) {
		soundEffects_[i] = new SoundEffect(soundEffects[i]);
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

Music* Resources::getMusic(MusicId i) const {
	if (i < numOfMusic_)
		return music_[i];
	else
		return nullptr;
}

SoundEffect* Resources::getSoundEffect(SoundEffectId i) const {
	if (i < numOfSoundEffects_)
		return soundEffects_[i];
	else
		return nullptr;
}

void Resources::closeMusic() {
	for (int i = 0; i < numOfMusic_; i++) {
		if (music_[i] != nullptr) {
			delete music_[i];
		}
	}
	delete[] music_;
	numOfMusic_ = 0;
}

void Resources::closeSoundEffects() {
	for (int i = 0; i < numOfSoundEffects_; i++) {
		if (soundEffects_[i] != nullptr) {
			delete soundEffects_[i];
		}
	}
	delete[] soundEffects_;
	numOfSoundEffects_ = 0;
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