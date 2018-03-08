#pragma once
#include "Observer.h"

class Observable
{
protected:
	static const int MAX_OBSERVERS = 5;
	vector<Observer*> observers_;
	int numOfObservers_=0;

public:

	Observable();
	~Observable();
	void addObserver(Observer* o) { observers_[numOfObservers_] = o; numOfObservers_++; }
	void removeObserver(Observer* o);
	void send(Observer::Messages msg);
};

