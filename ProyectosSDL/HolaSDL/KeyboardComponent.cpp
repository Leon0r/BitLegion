#include "KeyboardComponent.h"
#include "Inventory.h"

//miramos eventos de teclado
void KeyboardComponent::handleInput(GameObject* o, Uint32 time, const SDL_Event& event)
{
	Vector2D velocity = o->getVelocity();

	//si se ha pulsado una tecla se a�ade a la pila de teclas y se marca como pulsada
	if (event.type == SDL_KEYDOWN) {
		send(Messages(Moving));
		if (event.key.keysym.sym == right) {
			if (!r) Xaxis.push(right);
			r = true;
		}
	    else if (event.key.keysym.sym == left) {
			if (!l)Xaxis.push(left);
			l = true;
		}
		if (event.key.keysym.sym == up) {
			if (!u)Yaxis.push(up);
			u = true;
		}
		else if (event.key.keysym.sym == down) {
			if (!d)Yaxis.push(down);
			d = true;
		}
		if (event.key.keysym.sym == inventory) {
			r = l = u = d = false;
			while (!Xaxis.empty())Xaxis.pop();
			while (!Yaxis.empty())Yaxis.pop();
			dynamic_cast<PlayState*>(o->getGame()->getStateMachine()->currentState())->creaInventario();
		}
		if (event.key.keysym.sym == puzzle) {
			r = l = u = d = false;
			while (!Xaxis.empty())Xaxis.pop();
			while (!Yaxis.empty())Yaxis.pop();
			dynamic_cast<PlayState*>(o->getGame()->getStateMachine()->currentState())->creaPuzzle();
		}
	}
	//si se ha levantado una tecla se quita de la pila de teclas y se marca como no pulsada
	else if (event.type == SDL_KEYUP){
		if (event.key.keysym.sym == right) {
			r = false;
			if(!Xaxis.empty())Xaxis.pop();
			iddleRight = true;//has parado mirando hacia la derecha
		}
		else if (event.key.keysym.sym == left) {
			l = false;
			if (!Xaxis.empty())Xaxis.pop();
			iddleRight = false;//has parado mirando hacia la izquierda
		}
		if (event.key.keysym.sym == up) {
			u = false;
			if (!Yaxis.empty())Yaxis.pop();
		}
		else if (event.key.keysym.sym == down) {
			d = false;
			if (!Yaxis.empty())Yaxis.pop();
		}
	}
	//si no hay teclas en la pila la velocidad se para
	if (Xaxis.empty()) { 
		velocity.setX(0); 
	}
	else {//si hay teclas en la pila se mira cual es y se mueve en esa direccion
		if (Xaxis.top() == right && r) {
			velocity.setX(vel_);
			send(Ch_Right);//anim derecha
		}
		else if (Xaxis.top() == left && l) {
			velocity.setX(-vel_);
			send(Ch_Left);//anim izquierda
		}
	}   //lo mismo con las teclas del eje y
	if (Yaxis.empty())velocity.setY(0);
	else {
		if (Yaxis.top() == down && d) velocity.setY(vel_);
		else if(Yaxis.top() == up && u) velocity.setY(-vel_);
		if (!r && !l) {//si solo estan pulsadas las de arriba o abajo
			if (iddleRight)send(Ch_Right);
			else send(Ch_Left);//se activa la animacion correspondiente al lado hacia el que estuviera parado
		}
	}
	o->setVelocity(velocity);

	//si esta parado se establece la animacion correspondiente al lado hacia el que mira
	if (Xaxis.empty() && Yaxis.empty()) {
		if(iddleRight)send(StopRight);
		else send(StopLeft);
	}
}
