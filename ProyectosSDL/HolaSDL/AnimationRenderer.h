#pragma once
#include "RenderComponent.h"
#include "Observer.h"
#include "SDLApp.h"

const double ANIM_RATE = 100;

class AnimationRenderer :
	public RenderComponent, public Observer
{
	struct animData {
		string label_; // nombre/etiqueta de la animacion
		vector<int> framesAnim_; // frames que forman la animacion
		bool loop_; // si es loopeada o no (por defecto true)
		double rate_; // velocidad de frames (por defecto ANIM_RATE)
		// constructora de animData
		animData(string label, vector<int> framesAnim, bool loop, double rate) : 
			label_(label), framesAnim_(framesAnim), loop_(loop), rate_(rate) {};
	};

public:

	AnimationRenderer(Texture* texture, int numFilsFrames, int numColsFrames, int frWidth, int frHeigth);

	virtual ~AnimationRenderer();
	virtual void render(GameObject* o, Uint32 time);
	virtual Texture* getTexture() const { return texture_; };
	virtual void setTexture(Texture* newText) { this->texture_ = newText; };

	// añade una animacion al vector
	virtual void addAnim(string label, vector<int> framesAnim, bool loop = true, double rate = ANIM_RATE) 
	{ animData newAnim(label, framesAnim, loop, rate); animations_.push_back(newAnim); }

	// inicia la animacion de entrada o pone la 0 en caso de no encontrarla
	virtual void playAnim(string label);
	virtual void playAnim(int anim) { (anim < animations_.size() && anim >= 0) ? (nextAnim_ = anim) : (nextAnim_ = currentAnim_); }// operador ternario (if)?(true):(false);
	
	virtual void receive(Messages msg);

protected:

	uint32_t timeNext; // Control del tiempo de repeticion del bucle
	uint32_t timeLastFrame = 0;

	Texture * texture_;// textura
	SDL_Rect sourceRect;

	int frWidth_, frHeigth_, numFrFils_, numFrCols_; // datos frames
	
	vector <animData> animations_; // animaciones existentes
	int currentAnim_, currentFrame_, nextAnim_; // posicion en el vector de la animacion activa
	int numFrames;

	virtual void calculateNextSourceRect();
	virtual void changeAnim();
	virtual int nextFrame();
};

