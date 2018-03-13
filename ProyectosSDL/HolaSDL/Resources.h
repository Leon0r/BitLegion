#ifndef RESOURCES_H_
#define RESOURCES_H_

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
		Baño
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
