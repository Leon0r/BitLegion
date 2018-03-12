#include "AnimationRenderer.h"



AnimationRenderer::AnimationRenderer(Texture* texture, int numFilsFrames, int numColsFrames, 
	int frWidth, int frHeigth):
	texture_(texture), numFrCols_(numColsFrames), numFrFils_(numFilsFrames), frWidth_(frWidth), frHeigth_(frHeigth)
{
	numFrames = numColsFrames * numFilsFrames;
	timeNext = SDL_GetTicks();
	timeLastFrame = timeNext;
	nextAnim_ = currentAnim_;

	addAnim("Left", { 0,1,2,3,4,5,6,7 }, false);
	addAnim("Right", { 8,9,10,11,12,13,14,15 });
	addAnim("Stop", { 6 });
	playAnim(2);

	calculateNextSourceRect();
}

AnimationRenderer::~AnimationRenderer()
{
}

void AnimationRenderer::render(GameObject* o, Uint32 time)
{
	timeNext = SDL_GetTicks();

	if (timeNext - timeLastFrame >= animations_[currentAnim_].rate_) {

		calculateNextSourceRect();
		
		currentFrame_ = nextFrame();
		changeAnim();

		timeLastFrame = SDL_GetTicks();
	}

	SDL_Rect rect{ o->getPosition().getX(), o->getPosition().getY(),
		o->getWidth(), o->getHeight() };

	texture_->render(o->getGame()->getRenderer(), rect, &sourceRect);
}

void AnimationRenderer::playAnim(string label)
{
	int i = 0;
	while (i < animations_.size() && animations_[i].label_ != label) i++;
	
	if (i < animations_.size()) nextAnim_ = i;
}

void AnimationRenderer::changeAnim()
{
	if (nextAnim_ != currentAnim_) {
		currentAnim_ = nextAnim_;
		currentFrame_ = 0;
	}
}

int AnimationRenderer::nextFrame()
{
	int aux = currentFrame_ + 1;
	if (aux >= animations_[currentAnim_].framesAnim_.size())
		if(animations_[currentAnim_].loop_)
			aux = 0;
		else {
			playAnim(2);
		}
	return aux;
}

void AnimationRenderer::receive(Messages msg)
{
	switch (msg){
	case Ch_Left:
		playAnim(0);
		break;
	case Ch_Right:
		playAnim(1);
		break;
	case Stop:
		playAnim(2);
		break;
	default:
		break;
	}
}

void AnimationRenderer::calculateNextSourceRect()
{
	int y = (animations_[currentAnim_].framesAnim_[currentFrame_]) / numFrFils_;
	int x = (animations_[currentAnim_].framesAnim_[currentFrame_]) % numFrFils_;

	y *= frHeigth_;
	x *= frWidth_;

	sourceRect = { x, y, frWidth_, frHeigth_ };
}
