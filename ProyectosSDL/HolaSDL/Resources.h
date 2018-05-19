#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "checkML.h"
#include "Texture.h"
#include <vector>
#include <tuple>
#include "Music.h"
#include "SoundEffect.h"

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
		VentanaAnimada,
		Transicion,
		CigarrillosAnim,
		Escena9Caso1,
		AlcantarillaAnim,
		NeonAnim1,
		NeonAnim2,
		ventanaAnim2,
		lampAnim,
		fregaderoAnim,
		ventiladorAnim,
		porroAnim,
		radiador,
		mesaMuerto,
		dentaduraAnim,
		luzTechoAnim,
		FondoMenu,
		Logo,
		LogoAnim,
		Telefono,
		ExpresionesExtrasOficina,
		BotonComenzar,
		BotonLoad,
		BotonExit,
		BotonMenu,
		BotonMute,
		Transparente,
		BotonSalir,
		BotonSalirLuces,
		ReturnLuces,
		SenyoraBazar,
		SenyorBazar,
		VecinoDelMuerto,
		NumeroCamello,
		AmigaDeGalina,
		EntradaBazar,
		Bazar,
		Escena22Caso1,
		Coche1Decorado,
		Coche2Decorado,
		CartelBazar,
		Escena19Caso1,
		MuertoAutopsia,
		ControlesRaton,
		ControlesKeyArrows,
		ControlesKeyI,
		ControlesKeyP,
		MovimientoClick,
		PuertaViejaContra,
		TaquillaAlenaContra,
		ControlesButton,
		Forense,
		Camello,
		Maks,
		AmigoDeMaks,
		TrabajadorPolbots1,
		TrabajadorPolbots2,
		Escena23Caso1,
		SofaGalina,
		Pecera,
		Lampara,
		MesaGalina,
		Escena24Caso1,
		Armario,
		Television,
		MesaVecinoMuerto,
		Escena33Caso1,
		CamillaForense,
		MesaForense1,
		MesaForense2,
		MostradorBazar,
		PuertaAtras,
		PuertaBazar,
		EstanteBazar,
		Escena32Caso1,
		LamparaForense,
		Escena34Caso1,
		Drogadicto,
		Escena29Caso1,
		CuadroLuces,
		Antidoto,
		BolsaCocaLogoLuna,
		CartaLogoLuna,
		CuadernoDroga,
		Escena9Caso1Inv,
		HombrePortal,
		SalirPassWord,
		SalirControles,
		Escena31Caso1,
		Cursor,
		VecinosExpresiones,
		TaquillaOpening,
		ControlesMouseInteractuar,
		CocheGuay,
		Escena37Caso1,
		Escena38Caso1,
		Escena39Caso1,
		Escena40Caso1,
		Escena41Caso1,
		Mujer5piso,
		PuertaPisos,
		Escena36Caso1,
		NeonAnim3,
		NeonAnim4,
		TelefonilloAnim,
		RadiografiaAnim,
		Escena35Caso1,
		Escena42Caso1,
		BuzonCamello,
		InterruptorCamello,
		LucesCamello,
		SofaCamello,
		MesaCamello,
		LuzPolbots,
		NeonSports,
		VentanaGalina,
		CasillaPuzleCarta,
		Luz,
		Escena30Caso1,
		Taburete1,
		Taburete2,
		TocaDiscos,
		BarraBar,
		CartelExit,
		PlantaBar,
		VentanaCafe,
		HidroquenosExpresiones,
		GalinaNoviaMuertoExpresiones,
		SenyoraBajoExpresiones,
		SenyoraBazarExpresiones,
		CreditosBoton,
		Creditos,
		LogoSDL,
		LogoBitLegion,
		VecinoMuertoExpresiones,
		MaksExpresiones,
		ForenseExpresiones,
		LogosAnim,
		AmigoMaksExpresiones,
		Mujer5Expresiones,
		CamelloExpresiones,
		SeñorBazarExpresiones,
		AmigaGalinaExpresiones
	};

	// Music -- each file is loaded as an instance of Music
	//
	enum MusicId {
		MainTheme,
		MainThemePro
	};


	// Sound Effects -- each file is loaded as an instance of SoundEffect
	//
	enum SoundEffectId {
		Door,
		pickItem,
		invStartUp,
		BotonSonido,
		Neon,
		TVnoSignal,
		Click,
		WrongPuzle,
		CorrectPuzle,
		Paso
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

	void closeImageTextures();
	void closeMusic();
	void closeSoundEffects();

	SDLApp* game_;

	int numOfImageTextures_;
	Texture** imageTextures_;

	int numOfMusic_;
	Music** music_;

	int numOfSoundEffects_;
	SoundEffect** soundEffects_;
};

#endif /* RESOURCES_H_ */
