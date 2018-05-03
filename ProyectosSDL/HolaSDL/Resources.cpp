#include <tuple>
#include "Resources.h"
#include "SDLApp.h"

std::vector<std::string> Resources::imageFiles_{ 
"..//images/SpriteSheets_Personajes/AlenaSpriteSheet.png", //Alena,
"..//images/Puzles/boton.png", //Boton
"..//images/Puzles/BotonSwapSheet.png", //BotonSwap
"..//images/Puzles/BotonUsarSheet.png", //BotonUsar
"..//images/ImgTest.png", //ImagenTest
"..//images/Inventario/InventarioAnimSheet.png", //Inventario
"..//images/Inventario/InvMarca.png", //InvMarca
"..//images/Inventario/InvMarcaS.png", //InvMarcaS
"..//images/Inventario/shortcut.png", //ShortCut
"..//images/Fondos/escena1caso1.png", // Escena1Caso1
"..//images/Objetos/Colisionables/cama.png", //Cama
"..//images/Objetos/Colisionables/mesa.png", //Mesa
"..//images/Objetos/Colisionables/cocina.png", //Cocina
"..//images/Objetos/Takeable/bolsaCoca.png", //BolsaCoca
"..//images/Objetos/Takeable/bolsaVacia.png", //BolsaVacia
"..//images/Objetos/Takeable/botellaVodka.png", //BotellaVodka
"..//images/Objetos/Takeable/cuaderno.png", //Cuaderno
"..//images/Objetos/Takeable/fotoNoviaMuerto.png", //FotoNoviaMuerto
"..//images/Objetos/Takeable/llaveHotel.png", //LlaveHotel
"..//images/Objetos/Takeable/llavePiso.png", //LlavePiso
"..//images/Objetos/Takeable/movilMuerto.png", //MovilMuerto
"..//images/Objetos/Takeable/ticketCompra.png", //TicketCompra
"..//images/Objetos/Colisionables/vater.png", //Vater
"..//images/Objetos/Colisionables/lavaboDucha.png", // LavaboDucha
"..//images/Fondos/escena0caso1.png", //Banio
"..//images/Fondos/escena2caso1.png", // Escena2Caso1
"..//images/Objetos/Colisionables/mesillapasillo.png", //MesillaPasillo
"..//images/Objetos/Colisionables/relojpasillo.png", //RelojPasillo
"..//images/Objetos/Doors/puertaCasaAlena.png", // PuertaCasaAlena
"..//images/Objetos/flechaTransicion.png", //FlechaTransicionSpriteSheet
"..//images/Puzles/llavePisoPuzzle.png", //llavePisoPuzzle
"..//images/Puzles/casillaPuzzleV.png", //CasillaPuzzleV
"..//images/Puzles/botonPuzzle.png" , //BotonPuzzle
"..//images/Puzles/PuzzleHud.png" , //PuzzleHud
"..//images/Puzles/botonReiniciar.png", //BotonReiniciar
"..//images/Puzles/casillaPuzzleBloq.png", //casillaPuzzleBloq
"..//images/Puzles/casillaPuzzleDestroy.png", //casillaPuzzleDest
"..//images/Fondos/escena4caso1.png", //Escena4Caso1
"..//images/Objetos/moto.png", //MotoAlena
"..//images/Fondos/escena3caso1.png", //Escena3Caso1
"..//images/Objetos/Colisionables/muebleentrada.png", //MesaRecepcion
"..//images/Objetos/Colisionables/macetaentrada.png", //PlantaRecepcion
"..//images/Objetos/Doors/puertaentrada.png", //PuertaPortal
"..//images/colisionableAux.png", //ColisionableAux
"..//images/Puzles/LuzApagada.png", //LuzApagada
"..//images/Puzles/LuzEncendida.png", //LuzEncendida
"..//images/Puzles/Barras.png", //Barras
"..//images/Puzles/BarraCarga.png", // Carga
"..//images/Puzles/ondas.png", //Onda
"..//images/Puzles/LucesHud.png", // HudLuces
"..//images/Puzles/TextoPixel.png", //TextoPixel
"..//images/Puzles/BarridoBotella.png", //BotellaAnimada
"..//images/SpriteSheets_Personajes/hidroqueno.png", //Hidroqueno
"..//images/Fondos/escena5caso1.png", //Escena5caso1
"..//images/Objetos/Takeable/llaveCoche.png", //LLaveCoche
"..//images/Objetos/Takeable/llaveMoto.png", //LlaveMoto
"..//images/Objetos/Takeable/rotulador.png", //Rotulador
"..//images/Objetos/ordenadorAlena.png", // OrdenadorAlena
"..//images/SpriteSheets_Personajes/vecinaAbuela.png", //VecinaAbuela
"..//images/SpriteSheets_Personajes/vecinoPerro.png", //VecinoPerro
"..//images/Objetos/Colisionables/bin.png", //Bin
"..//images/Objetos/Colisionables/desk.png", //Desk
"..//images/Objetos/Colisionables/cooler.png", //MaquinaAgua
"..//images/Fondos/escena6Caso1.png", // Escena6caso1
"..//images/SpriteSheets_Personajes/vecinaNinya.png", //VecinaNinya
"..//images/SpriteSheets_Personajes/companyero1.png", //Comp1
"..//images/SpriteSheets_Personajes/companyero2.png", //Comp2
"..//images/SpriteSheets_Personajes/companyero3.png", //Comp3
"..//images/SpriteSheets_Personajes/ninaCompanyera.png", //NinaComp
"..//images/Objetos/Colisionables/desk2.png", //Desk2
"..//images/Objetos/Colisionables/desk3.png", //Desk3
"..//images/Objetos/Takeable/bolsaCafe.png", //BolsaCafe
"..//images/Fondos/escena10caso1.png", // Escena10caso1
"..//images/Fondos/escena7caso1.png", //Escena7caso1
"..//images/Objetos/Colisionables/planta.png", //Planta
"..//images/Objetos/Colisionables/lockerNotsave.png", //TaquillaAbierta
"..//images/Objetos/Colisionables/lockersave.png", //TaquillaCerrada
"..//images/SpriteSheets_Personajes/JeffaSpriteSheet.png", //Jeffa
"..//images/SpriteSheets_Personajes/GalinaNoviaMuertoSheet.png", //Galina
"..//images/SpriteSheets_Personajes/senyoraDelBajo.png", //SenyoraDelBajo
"..//images/SpriteSheets_Personajes/policia1.png", //Policia1
"..//images/SpriteSheets_Personajes/policia2.png", //Policia2
"..//images/SpriteSheets_Personajes/policia3.png", //Policia3
"..//images/SpriteSheets_Personajes/policia4.png", //Policia4
"..//images/Fondos/escena8caso1.png", //Escena8caso1
"..//images/Objetos/Colisionables/perchero.png", //Perchero
"..//images/Objetos/Colisionables/deskD.png", //DeskD
"..//images/Fondos/escena12caso1.png", // Escena12caso1
"..//images/Objetos/Doors/puertaAzotea.png", //PuertaAzotea
"..//images/Expresiones/alenaExpresiones.png", // AlenaExpresiones
"..//images/Expresiones/anderExpresiones.png", //AnderExpresiones
"..//images/Expresiones/jeffaExpresiones.png", //JeffaExpresiones
"..//images/Fondos/escena16caso1.png", //Escena16caso1
"..//images/Objetos/muerto.png", //Muerto
"..//images/Fondos/escena13caso1.png", // Escena13Caso1
"..//images/Objetos/Colisionables/mesaCocina.png", //MesaCocina
"..//images/Objetos/Colisionables/encimera.png", //Encimera
"..//images/SpriteSheets_Personajes/periodista1.png", // Periodista1
"..//images/SpriteSheets_Personajes/periodista2.png", //Periodista2
"..//images/SpriteSheets_Personajes/periodista3.png", //Periodista3
"..//images/SpriteSheets_Personajes/periodista4.png", //Periodista4
"..//images/Fondos/escena11caso1.png", //Escena11caso1
"..//images/Objetos/Doors/puertaTrasera_edificio_Drzewo.png", // PuertaTrasera
"..//images/Objetos/Colisionables/Cubo de basura_edificio_Drzewo.png", //CuboBasura1
"..//images/Objetos/Colisionables/Basura_edificio_Drzewo.png", //BolsasBasura
"..//images/Objetos/Colisionables/escalera Incendios_edificio_Drzewo.png", //EscalerasMano
"..//images/Dialogos/GUIdialogosAlpha.png", //GUIDialogosAlpha
"..//images/SpriteSheets_Personajes/curioso1.png", //Curioso1
"..//images/SpriteSheets_Personajes/curioso2.png", //Curioso2
"..//images/SpriteSheets_Personajes/curioso3.png", //Curioso3
"..//images/SpriteSheets_Personajes/curioso4.png", //Curioso4
"..//images/Fondos/escena15caso1.png", // Escena15Caso1
"..//images/Fondos/escena18caso1.png", //Escena18Caso1
"..//images/Objetos/Colisionables/encimeraMuerto.png", //EncimeraMuerto
"..//images/Fondos/escena14caso1.png", //Escena14Caso1
"..//images/Objetos/Colisionables/estanteriaVieja.png", // EstanteriaVieja
"..//images/Objetos/Colisionables/mesillaVieja.png", //MesillaVieja
"..//images/Objetos/Colisionables/sofaVieja.png", //SofaVieja
"..//images/Objetos/Colisionables/mesaVieja.png", //MesaVieja
"..//images/Fondos/escena17caso1.png", // Escena17Caso1
"..//images/Objetos/Colisionables/mesaMuerto.png" , //MesaMuerto
"..//images/Objetos/Colisionables/mesillaMuerto.png", //MesillaMuerto
"..//images/Objetos/Colisionables/sofaMuerto.png", //SofaMuerto
"..//images/Objetos/Colisionables/plantaMuerto.png", //PlantaMuerto
"..//images/SpriteSheets_Personajes/ander.png", // Ander
"..//images/SpriteSheets_Personajes/FumadorNPC.png", // NPCFumador
"..//images/SpriteSheets_Personajes/mujerNinyoNPC.png", // NPCMujerNinyo
"..//images/Objetos/Colisionables/camaSpriteSheet.png", // spritesheet de la cama con el neon
"..//images/Objetos/ventanaOAnim.png", //ventana animada
"..//images/Fondos/transicion.png", //transicion
"..//images/Objetos/cigarrillosAnim.png", //cigarrillos animados con humo
"..//images/Fondos/escena9caso1.png", //Escena14Caso1
"..//images/Objetos/alcantarillaAnim.png", //animacion de la alcantarilla de la calle
"..//images/Objetos/neonAnim1.png", //animacion del neon de la calle
"..//images/Objetos/neonAnim2.png", //animacion del neon de la calle
"..//images/Objetos/ventanaAnim2.png", //animacion del descansillo de jeffa (ventana)
"..//images/Objetos/lampDeskD.png", //animacion de la lampara de jeffa
"..//images/Objetos/fregadero.png", //animacion del fregadero de la vieja
"..//images/Objetos/ventiladorTecho.png", //animacion ventilador
"..//images/Objetos/porro.png", //porro del muerto
"..//images/Objetos/Colisionables/radiador.png", //radiador de la vieja
"..//images/Objetos/Colisionables/mesaCocina2.png", //mesa del muerto(cocina)
"..//images/Objetos/dentaduraVieja.png", //animacion de la dentadura de la vieja
"..//images/Objetos/luzTecho.png", //animacion de las luces del salon del muerto
"..//images/Fondos/FondoMenu.png", //fondo del menu principal
"..//images/Fondos/logo.png", //logo del juego
"..//images/Fondos/logoAnim.png", //logo del juego animado
"..//images/Objetos/telefono.png",
"..//images/Expresiones/ExtrasOficina.png",//expresiones de extras en la oficina
"..//images/Objetos/COMENZAR.png",//boton Comenzar
"..//images/Objetos/CONTINUAR.png",//boton continuar
"..//images/Objetos/SALIR.png",//boton SALIR
"..//images/Objetos/MENU.png",//boton Menu
"..//images/Objetos/MUTE.png",//boton Mute
"..//images/Dialogos/transparente.png", //textura transparente
"..//images/Puzles/botonSalir.png", //salir del puzle del conecta 4
"..//images/Puzles/botonSalirLuces.png", //salir del puzle de las luces
"..//images/Puzles/returnLuces.png", //reiniciar puzle de las luces
"..//images/SpriteSheets_Personajes/senyoraDelBazar.png",//señora del bazar
"..//images/SpriteSheets_Personajes/senyorDelBazar.png",//señor del bazar
"..//images/SpriteSheets_Personajes/vecinoDelMuerto.png",//vecino yonki del muerto
"..//images/Objetos/Takeable/numeroDelCamello.png",//numero de telefono del camello
"..//images/SpriteSheets_Personajes/AmigaGalina.png", //amiga de la novia del muerto
"..//images/Fondos/escena20caso1.png", //entrada al Bazar
"..//images/Fondos/escena21caso1.png", //Bazar
"..//images/Fondos/escena22caso1.png", //casa de la novia del muerto
"..//images/Objetos/Colisionables/coche1.png", //coche1
"..//images/Objetos/Colisionables/coche2.png", //coche2 (util)
"..//images/Objetos/cartelbazarspritesheet.png", //cartel animado bazar
"..//images/Fondos/escena19caso1.png", //callejon que lleva al bazar
"..//images/Objetos/Colisionables/muertoAutopsia.png", //muerto en la morgue
"..//images/Fondos/AlenaMouse.png", 
"..//images/Fondos/AlenaArrows.png", 
"..//images/Fondos/key_i.png", 
"..//images/Fondos/key_p.png", 
"..//images/Fondos/ratonMouse.png", 
"..//images/Fondos/puertaViejaContrasenya.png", 
"..//images/Fondos/taquillaAlenaContrasenya.png", 
"..//images/Objetos/CONTROLES.png",
"..//images/SpriteSheets_Personajes/forense.png",
"..//images/SpriteSheets_Personajes/camello.png",
"..//images/SpriteSheets_Personajes/maks.png",
"..//images/SpriteSheets_Personajes/amigoMaks.png",
"..//images/SpriteSheets_Personajes/trabajadorPolbots1.png",
"..//images/SpriteSheets_Personajes/trabajadorPolbots2.png",
"..//images/Fondos/escena23caso1.png", //casa novia
"..//images/Objetos/Colisionables/sofaGalina.png",
"..//images/Objetos/Colisionables/pezGalina.png",
"..//images/Objetos/Colisionables/lamparaGalina.png",
"..//images/Objetos/Colisionables/mesaGalina.png",
"..//images/Fondos/escena24caso1.png",
"..//images/Objetos/Colisionables/armarioVecinoMuerto.png",
"..//images/Objetos/Colisionables/teleVecinoMuerto.png",
"..//images/Objetos/Colisionables/mesaVecinoMuerto.png",
"..//images/Fondos/escena31caso1.png", //sala de pruebas del forense
"..//images/Objetos/Colisionables/camillaForense.png",
"..//images/Objetos/Colisionables/mesaForense1.png",
"..//images/Objetos/Colisionables/mesaForense2.png",
"..//images/Objetos/Colisionables/mostradorbazar.png",
"..//images/Objetos/puertadeatrasmostradorspritesheet.png",
"..//images/Objetos/Doors/puertabazarinteriro.png",
"..//images/Objetos/Colisionables/estantebazar.png",
"..//images/Fondos/escena30caso1.png", //hall del forense
"..//images/Objetos/Colisionables/lamparaForense.png", //lampara del hall del forense
"..//images/Fondos/escena32caso1.png", //callejon de drogadictos
"..//images/Objetos/Colisionables/drogadicto.png",
"..//images/Fondos/escena29caso1.png",
};





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