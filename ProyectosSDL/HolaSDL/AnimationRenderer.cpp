#include "AnimationRenderer.h"



AnimationRenderer::AnimationRenderer(Texture* texture, int numFilsFrames, int numColsFrames, int frWidth, int frHeigth):
	texture_(texture), numFrCols_(numColsFrames), numFrFils_(numFilsFrames), frWidth_(frWidth), frHeigth_(frHeigth)
{
	numFrames = numColsFrames * numFilsFrames;
	startTime = SDL_GetTicks();
	timeAcum = startTime;
	nextAnim_ = currentAnim_;

	addAnim("Left", { 0,1,2,3,4,5,6,7 });
	addAnim("Right", { 8,9,10,11,12,13,14,15 });
	addAnim("Stop", { 6 });
	playAnim(0);
}

AnimationRenderer::~AnimationRenderer()
{
}

void AnimationRenderer::render(GameObject* o, Uint32 time)
{
	startTime = SDL_GetTicks();

	if (timeAcum - startTime < ANIM_RATE) {
		timeAcum += startTime;
	}
	else {
		
		int y = (animations_[currentAnim_].framesAnim_[currentFrame_]) / numFrFils_;
		int x = (animations_[currentAnim_].framesAnim_[currentFrame_]) % numFrFils_;

		SDL_Rect sourceRect{ x, y, frWidth_, frHeigth_ };

		SDL_Rect rect{ o->getPosition().getX(), o->getPosition().getY(),
			o->getWidth(), o->getHeight() };

		texture_->render(o->getGame()->getRenderer(), rect, &sourceRect);
		currentFrame_ = nextFrame();
		changeAnim();

		timeAcum = SDL_GetTicks();
	}
}

void AnimationRenderer::playAnim(string label)
{
	int i = 0;
	while (i < animations_.size() && animations_[i].label_ != label) i++;
	
	if (i < animations_.size()) nextAnim_ = i;
}

int AnimationRenderer::nextFrame()
{
	int aux = currentFrame_ + 1;
	if (aux >= animations_[currentAnim_].framesAnim_.size())
		aux = 0;
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
