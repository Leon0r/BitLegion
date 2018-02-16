#include "Texture.h"

Texture::Texture() :
		texture_(nullptr), width_(0), height_(0) {
}

Texture::~Texture() {
	close();
}

int Texture::getWidth() {
	return width_;
}

int Texture::getHeight() {
	return height_;
}

void Texture::close() {
	if (texture_ != nullptr) {
		SDL_DestroyTexture(texture_); // delete current texture
		texture_ = nullptr;
		width_ = 0;
		height_ = 0;
	}
}

bool Texture::loadFromImg(SDL_Renderer* renderer, string fileName) {
	SDL_Surface* surface = IMG_Load(fileName.c_str());
	if (surface != nullptr) {
		close(); // destroy current texture
		texture_ = SDL_CreateTextureFromSurface(renderer, surface);
		if (texture_ != nullptr) {
			width_ = surface->w;
			height_ = surface->h;
		}
		SDL_FreeSurface(surface);
	}
	return texture_ != nullptr;
}

void Texture::render(SDL_Renderer* renderer, int x, int y) const {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = width_;
	dest.h = height_;
	render(renderer, dest);
}

void Texture::render(SDL_Renderer* renderer, const SDL_Rect& dest,
		SDL_Rect* clip) const {
	if (texture_) {
		SDL_Rect default_clip = { 0, 0, width_, height_ };
		if (clip == nullptr) {
			clip = &default_clip;
		}
		SDL_RenderCopy(renderer, texture_, clip, &dest);
	}
}

void Texture::render(SDL_Renderer* renderer, const SDL_Rect& dest, double angle,
		SDL_Rect* clip) const {
	if (texture_) {
		SDL_Rect default_clip = { 0, 0, width_, height_ };
		if (clip == nullptr) {
			clip = &default_clip;
		}
		SDL_RenderCopyEx(renderer, texture_, clip, &dest, angle, nullptr,
				SDL_FLIP_NONE);
	}
}
