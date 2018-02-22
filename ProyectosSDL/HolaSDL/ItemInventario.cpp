#include "ItemInventario.h"



ItemInventario::ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture) : ClickeableGO(game,x, y,w,h, _desc,_tag,texture)
{
}


ItemInventario::~ItemInventario()
{
}

void ItemInventario::act() {
	cout << "Hanzo main" << endl;
	//Lo que tenga que hacer
}

