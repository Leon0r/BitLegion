#pragma once
#include <vector>
using namespace std;


class Observer
{
protected:
	vector<string> possibleEvents;

public:
	enum Messages {
		Ch_Left,
		Ch_Right,
		Ch_TakeObj, 
		Stop
	};

	Observer();
	virtual~Observer();
	virtual void receive(Messages msg) = 0;
};

