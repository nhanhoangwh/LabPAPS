#pragma once
#include "IObserver.h"
// интерфейс, представл€ющий наблюдаемый объект 
class IObservable {
public:
	virtual void Attach(IObserver io) {};
	virtual void Detach(IObserver io) {};
	virtual void Notify() {}; //оповещает
};