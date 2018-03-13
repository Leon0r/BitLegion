#pragma once
#include <string>
#include <vector>
using namespace std;

struct animData {
	string label_; // nombre/etiqueta de la animacion
	vector<int> framesAnim_; // frames que forman la animacion
	bool loop_; // si es loopeada o no (por defecto true)
	double rate_; // velocidad de frames (por defecto ANIM_RATE)
	
	// constructora de animData
	animData() { label_ = "Default"; loop_ = false; rate_ = 100; };
	animData(string label, vector<int> framesAnim, bool loop = true, double rate = 100.0) :
		label_(label), framesAnim_(framesAnim), loop_(loop), rate_(rate) {};
};