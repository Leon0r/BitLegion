#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "checkML.h"
#include "Texture.h"
#include "Music.h"
#include "SoundEffect.h"
#include <vector>
#include <tuple>

class SDLApp;
class Resources {
public:
	// in this part we define the enums for the resources, and the
	// corresponding data to be used to create them. The enums are simple
	// used to make access readable ...

	// Images -- each image file is loaded as an instance of Texture
	//
	enum ImageId {
		Alena,
		BitLegionLogo,
		Boton,
		BotonSwap,
		BotonUsar,
		ImagenTest,
		Inventario,
		InvMarca,
		InvMarcaS,
		ShortCut,
		Escena1Caso1,
		Cama,
		Mesa,
		Cocina,
		PuertaCutre,
		LlaveCutre,
		BolsaCoca,
		BolsaVacia,
		BotellaVodka,
		Cuaderno,
		FotoNoviaMuerto,
		LlaveHotel,
		LlavePiso,
		MovilMuerto,
		TicketCompra,
		Vater,
		LavaboDucha,
		Banio,
		Escena2Caso1,
		MesillaPasillo,
		RelojPasillo,
		PuertaCasaAlena,
		FlechaTransicionSpriteSheet,
		FlechaTransicionDer,
		FlechaTransicionIzq,
		llavePisoPuzzle,
		CasillaPuzzleV,
		BotonPuzzle,  
		PuzzleHud,
		BotonReiniciar,
		casillaPuzzleBloq,
		casillaPuzzleDest,
		Escena4Caso1,
		MotoAlena,
		Escena3Caso1,//44
		MesaRecepcion,
		PlantaRecepcion,
		PuertaPortal,
		ColisionableAux,
		//BotonPuzzle,
		LuzApagada,
		LuzEncendida,
		Barras,
		Carga,
		Onda,
		HudLuces,
		TextoPixel,
		BotellaAnimada,
		Hidroqueno,
		Escena5caso1,
		LLaveCoche,
		LlaveMoto,
		Rotulador,
		OrdenadorAlena,
		VecinaAbuela,
		VecinoPerro,
		Bin,
		Desk,
		MaquinaAgua,
		Escena6caso1,
		VecinaNiña,
		Comp1,
		Comp2,
		Comp3,
		NinaComp,
		Desk2,
		Desk3,
		BolsaCafe,
		Plaza,
		Escena7caso1,
		Planta,
		TaquillaAbierta,
		TaquillaCerrada, 
		Jeffa,
		Galina,
		SeñoraDelBajo,
		Policia1,
		Policia2, 
		Policia3,
		Policia4,
		Escena8caso1,
		Perchero,
		DeskD
	};


	// Music -- each file is loaded as an instance of Music
	//
	enum MusicId {
		Beat, 
	};


	// Sound Effects -- each file is loaded as an instance of SoundEffect
	//
	enum SoundEffectId {
		Wall_Hit, 
	};

private:
	static std::vector<std::string> imageFiles_; // initialized in .cpp
	static std::vector<std::string> musicFiles_; // initialized in .cpp
	static std::vector<std::string> soundEffectFiles_; // initialized in .cpp

public:
	Resources(SDLApp* game);
	virtual ~Resources();

	Texture* getImageTexture(ImageId i) const;

	int getPosTexture(Texture* text) const;


	Music* getMusic(MusicId i) const;
	SoundEffect* getSoundEffect(SoundEffectId i) const;

private:
	void setImageTextures(std::vector<std::string> textures);
	void setMusic(std::vector<std::string> music);
	void setSoundEffects(std::vector<std::string> soundEffects);


	void closeMusic();
	void closeSoundEffects();
	void closeImageTextures();

	SDLApp* game_;

	int numOfImageTextures_;
	Texture** imageTextures_;

	int numOfMusic_;
	Music** music_;

	int numOfSoundEffects_;
	SoundEffect** soundEffects_;

};

#endif /* RESOURCES_H_ */
