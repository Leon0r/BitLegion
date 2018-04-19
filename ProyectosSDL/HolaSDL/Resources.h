#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "checkML.h"
#include "Texture.h"
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
		llavePisoPuzzle,
		CasillaPuzzleV,
		BotonPuzzle,
		PuzzleHud,
		BotonReiniciar,
		casillaPuzzleBloq,
		casillaPuzzleDest,
		Escena4Caso1,
		MotoAlena,
		Escena3Caso1,
		MesaRecepcion,
		PlantaRecepcion,
		PuertaPortal,
		ColisionableAux,
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
		VecinaNinya,
		Comp1,
		Comp2,
		Comp3,
		NinaComp,
		Desk2,
		Desk3,
		BolsaCafe,
		Escena10caso1,
		Escena7caso1,
		Planta,
		TaquillaAbierta,
		TaquillaCerrada,
		Jeffa,
		Galina,
		SenyoraDelBajo,
		Policia1,
		Policia2,
		Policia3,
		Policia4,
		Escena8caso1,
		Perchero,
		DeskD,
		Escena12caso1,
		PuertaAzotea,
		AlenaExpresiones,
		AnderExpresiones,
		JeffaExpresiones,
		Escena16caso1,
		Muerto,
		Escena13Caso1,
		MesaCocina,
		Encimera,
		Periodista1,
		Periodista2,
		Periodista3,
		Periodista4,
		Escena11caso1,
		PuertaTrasera,
		CuboBasura1,
		BolsasBasura,
		EscalerasMano,
		GUIDialogosAlpha,
		Curioso1,
		Curioso2,
		Curioso3,
		Curioso4,
		Escena15Caso1,
		Escena18Caso1,
		EncimeraMuerto,
		Escena14Caso1,
		EstanteriaVieja,
		MesillaVieja,
		SofaVieja,
		MesaVieja,
		Escena17Caso1,
		MesaMuerto,
		MesillaMuerto,
		SofaMuerto,
		PlantaMuerto,
		Ander,
		NPCFumador,
		NPCMujerNinyo,
		CamaSpriteSheet,
		VentanaAnimada
	};
private:
	static std::vector<std::string> imageFiles_; // initialized in .cpp

public:
	Resources(SDLApp* game);
	virtual ~Resources();

	Texture* getImageTexture(ImageId i) const;

	int getPosTexture(Texture* text) const;

private:
	void setImageTextures(std::vector<std::string> textures);

	void closeImageTextures();

	SDLApp* game_;

	int numOfImageTextures_;
	Texture** imageTextures_;
};

#endif /* RESOURCES_H_ */
