#pragma once
#include <vector>
#include "Messages.h"
using namespace std;


class Observer
{
protected:
	vector<string> possibleEvents;

public:
	Observer();
	virtual~Observer();
	virtual void receive(Messages msg) = 0;
};

