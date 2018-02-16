#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

using namespace std;

class Texture {
public:
	Texture();
	Texture(SDL_Renderer* renderer, std::string fileName);
	virtual ~Texture();

	int getWidth();
	int getHeight();
	bool loadFromImg(SDL_Renderer* renderer, std::string fileName);
	void render(SDL_Renderer* renderer, int x, int y) const;
	void render(SDL_Renderer* renderer, SDL_Rect const& dest, SDL_Rect* clip =
			nullptr) const;
	void render(SDL_Renderer* renderer, SDL_Rect const& dest, double angle,
			SDL_Rect* clip = nullptr) const;
	void close();

private:

	SDL_Texture *texture_;
	int width_;
	int height_;
};

#endif /* TEXTURE_H_ */
