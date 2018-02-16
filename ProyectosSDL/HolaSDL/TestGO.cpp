#include "TestGO.h"
using namespace std;


TestGO::TestGO(SDLApp* game, int x, int y, int w, int h): GameObject(game)
{
	position_ = Vector2D(x, y);
	height_ = h;
	width_ = w;

}


TestGO::~TestGO()
{
}
void TestGO::handleInput(Uint32 time, const SDL_Event& event) {
	bool flag = ComponenteClickeable::handleInput(this, event);
}
